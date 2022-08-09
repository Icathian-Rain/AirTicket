#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <functional>

#include <sys/socket.h> // socket 头文件
#include <netinet/in.h> // sockaddr_in结构体
#include <arpa/inet.h>  // inet_addr函数
#include <unistd.h>     // close函数
#include <time.h>       // time函数

#include "ThreadPool.h" // 线程池

namespace httplib //定义命名空间
{
    // 请求类
    class HttpRequest
    {
    private:
        int client_sock;                                      // 客户端socket
        std::string raw_request;                              // 原始请求数据
        std::string method;                                   // 请求方法
        std::string path;                                     // 请求路径
        std::string version;                                  // 请求版本
        std::unordered_map<std::string, std::string> headers; // 请求头
        std::unordered_map<std::string, std::string> params;  // 请求参数
        std::string body;                                     // 请求体

    public:
        HttpRequest(int client_sock, std::string raw_request)
        {
            // 初始化
            this->client_sock = client_sock;
            this->raw_request = raw_request;
            // 解析请求数据
            // 按行分割
            std::vector<std::string> lines;
            std::string line;
            std::stringstream ss(raw_request);
            while (getline(ss, line))
            {
                lines.push_back(line);
            }
            // 解析第一行
            std::string first_line = lines[0];
            // 按空格分割
            std::vector<std::string> first_line_vec;
            std::stringstream first_line_ss(first_line);
            while (getline(first_line_ss, line, ' '))
            {
                first_line_vec.push_back(line);
            }
            // 解析请求方法，路径和版本
            method = first_line_vec[0];
            path = first_line_vec[1];
            // 解析路径中的参数
            if (path.find('?') != std::string::npos)
            {
                // 按 ? 分割, ? 前为路径，? 后为参数
                std::string param_str = path.substr(path.find('?') + 1); // 参数段
                path = path.substr(0, path.find('?'));                   // 路径段
                // 参数段按 & 分割
                std::vector<std::string> param_vec;
                std::stringstream param_ss(param_str);
                // 获取参数行
                while (getline(param_ss, line, '&'))
                {
                    param_vec.push_back(line);
                }
                for (int i = 0; i < param_vec.size(); i++)
                {
                    std::string param_line = param_vec[i];
                    // 按 = 分割
                    if (param_line.find('=') != std::string::npos)
                    {
                        std::string param_key = param_line.substr(0, param_line.find('='));
                        std::string param_value = param_line.substr(param_line.find('=') + 1);
                        params[param_key] = param_value;
                    }
                    else
                    {
                        std::cout << "params error" << std::endl;
                    }
                }
            }
            version = first_line_vec[2];
            // 解析请求头
            for (int i = 1; i < lines.size() - 1; i++)
            {
                std::string header_line = lines[i];
                if (header_line == "\r")
                {
                    break;
                }
                if (header_line.find(':') != std::string::npos)
                {
                    std::string header_line_key = header_line.substr(0, header_line.find(':'));
                    std::string header_line_value = header_line.substr(header_line.find(':') + 1, header_line.size() - header_line.find(':') - 2);
                    headers[header_line_key] = header_line_value;
                }
                else
                {
                    std::cout << header_line << std::endl;
                    std::cout << "headers ERROR" << std::endl;
                }
            }
            // 解析请求体
            body = raw_request.substr(raw_request.find("\r\n\r\n") + 4);
        }
        // 对外接口
        std::string get_method()
        {
            return method;
        }

        std::string get_path()
        {
            return path;
        }

        std::string get_version()
        {
            return version;
        }

        std::string get_header(std::string header)
        {
            return headers[header];
        }
        std::string get_param(std::string param)
        {
            return params[param];
        }

        std::string get_body()
        {
            return body;
        }

        std::string get_raw_request()
        {
            return raw_request;
        }
    };

    class HttpResponse //响应类
    {
    private:
        int client_sock;                                      // 客户端socket
        std::string raw_response;                             // 原始响应数据
        std::string version;                                  // 响应版本
        int status_code;                                      // 响应状态码
        std::string status_message;                           // 响应状态信息
        std::unordered_map<std::string, std::string> headers; // 响应头
        std::string body;                                     // 响应体
    public:
        HttpResponse(int client_sock)
        {
            // 初始化
            this->client_sock = client_sock;
            // 响应数据初始化
            this->set_version("HTTP/1.1");
            this->set_status_code(200);
            this->set_status_message("OK");
            this->set_header("Content-Type", "text/html");
            this->set_header("Connection", "close");
        }
        // 对外接口
        void set_version(std::string version)
        {
            this->version = version;
        }
        void set_status_code(int status_code)
        {
            this->status_code = status_code;
        }
        void set_status_message(std::string status_message)
        {
            this->status_message = status_message;
        }
        void set_header(std::string header, std::string value)
        {
            headers[header] = value;
        }
        void set_body(std::string body, std::string content_type)
        {
            // 设置响应体
            this->body = body;
            this->set_header("Content-Type", content_type);
            this->set_header("Content-Length", std::to_string(body.size()));
        }
        std::string get_body()
        {
            return body;
        }
        // 获取原始响应数据
        std::string get_raw_response()
        {
            raw_response = "";
            raw_response += version + " " + std::to_string(status_code) + " " + status_message + "\r\n";
            for (auto it = headers.begin(); it != headers.end(); it++)
            {
                raw_response += it->first + ": " + it->second + "\r\n";
            }
            raw_response += "\r\n";
            raw_response += body;
            return raw_response;
        }
    };

    class HttpServer
    {
    private:
        int port;                                                                                          // 监听端口
        int server_socket;                                                                                 // 服务器socket
        struct sockaddr_in server_addr;                                                                    // 服务器地址
        bool is_running;                                                                                   // 服务器是否运行
        std::unordered_map<std::string, std::function<void(HttpRequest &, HttpResponse &)>> get_handlers;  // get请求处理函数映射
        std::unordered_map<std::string, std::function<void(HttpRequest &, HttpResponse &)>> post_handlers; // post请求处理函数映射
        ThreadPool *pool;                                                                                   // 线程池
        std::vector< std::future<bool> > results;                                                           // 线程池结果
    public:
        HttpServer(const char *addr, int port)
        {
            // 初始化
            this->port = port;
            this->server_socket = socket(AF_INET, SOCK_STREAM, 0);
            if (server_socket == -1)
            {
                std::cout << "socket error" << std::endl;
                return;
            }
            memset(&this->server_addr, 0, sizeof(this->server_addr));
            this->server_addr.sin_family = AF_INET;              // ipv4
            this->server_addr.sin_port = htons(port);            // 端口号
            this->server_addr.sin_addr.s_addr = inet_addr(addr); // ip地址
            int reuse = 1;
            // 重复使用端口号
            if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0)
            {
                std::cout << "setsockopt error" << std::endl;
            }

            // 绑定socket
            if (bind(server_socket, (struct sockaddr *)&this->server_addr, sizeof(this->server_addr)) == -1)
            {
                std::cout << "bind error" << std::endl;
                return;
            }
            // 监听socket
            if (listen(server_socket, 128) == -1)
            {
                std::cout << "listen error" << std::endl;
                return;
            }
            this->pool = new ThreadPool(2);
        }
        void run()
        {
            is_running = true;
            while (is_running)
            {
                // 接收客户端请求
                int client_socket;              // 客户端socket
                struct sockaddr_in client_addr; // 客户端地址
                socklen_t client_addr_len = sizeof(client_addr);
                // 等待客户连接
                client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
                if (client_socket == -1)
                {
                    std::cout << "accept error" << std::endl;
                    return;
                }
                std::cout << "accept success" << std::endl;
                // 响应客户端请求
                // handle_http_request(client_socket);
                results.emplace_back(pool->enqueue(&HttpServer::handle_http_request, this, client_socket));
                std::cout << "enqueue success" << std::endl;
            }
        }
        void stop()
        {
            is_running = false;
            close(server_socket);
        }
        bool handle_http_request(int client_sock)
        {
            // clock_t start = clock();
            char buf[1024];                                   // 缓冲区
            memset(buf, 0, sizeof(buf));                      // 清空缓冲区
            int ret = recv(client_sock, buf, sizeof(buf), 0); // 接收客户端请求
            if (ret == -1)
            {
                std::cout << "recv error" << std::endl;
                return false;
            }
            else if (ret == 0)
            {
                std::cout << "client close" << std::endl;
                return false;
            }
            // printf("recv takes %f s\n", (double)(clock() - start) / CLOCKS_PER_SEC);
            // 初始化响应与请求
            auto req = HttpRequest(client_sock, buf);
            // printf("req takes %f s\n", (double)(clock() - start) / CLOCKS_PER_SEC);
            auto res = HttpResponse(client_sock);
            // 处理请求
            // get请求
            if (req.get_method() == "GET")
            {
                if (get_handlers.find(req.get_path()) != get_handlers.end())
                {
                    // 调用get请求处理函数
                    get_handlers[req.get_path()](req, res);
                }
                else
                {
                    // 返回404错误
                    res.set_status_code(404);
                    res.set_status_message("Not Found");
                    res.set_body("<h1>Not Found</h1>", "text/html");
                }
            }
            else if (req.get_method() == "POST")
            {
                if (post_handlers.find(req.get_path()) != post_handlers.end())
                {
                    // 调用post请求处理函数
                    post_handlers[req.get_path()](req, res);
                }
                else
                {
                    // 返回404错误
                    res.set_status_code(404);
                    res.set_status_message("Not Found");
                    res.set_body("<h1>Not Found</h1>", "text/html");
                }
            }
            else
            {
                // 返回405错误
                res.set_status_code(405);
                res.set_status_message("Method Not Allowed");
                res.set_body("<h1>Method Not Allowed</h1>", "text/html");
            }
            // printf("res takes %f s\n", (double)(clock() - start) / CLOCKS_PER_SEC);
            send(client_sock, res.get_raw_response().c_str(), res.get_raw_response().size(), 0);
            // 关闭客户端socket
            // printf("send takes %f s\n", (double)(clock() - start) / CLOCKS_PER_SEC);
            close(client_sock);
            return true;
        }
        void Get(std::string path, std::function<void(HttpRequest &, HttpResponse &)> callback)
        {
            get_handlers[path] = callback;
        }
        void Post(std::string path, std::function<void(HttpRequest &, HttpResponse &)> callback)
        {
            post_handlers[path] = callback;
        }
    };
}