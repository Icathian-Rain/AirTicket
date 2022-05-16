cmake_minimum_required(VERSION 3.22)
project(Travel_Recommend_system)

set(CMAKE_CXX_STANDARD 14)

add_executable(Travel_Recommend_system main.cpp Flight.cpp Flight.h Time.cpp Time.h FlightRequest.cpp FlightRequest.h PriceRule.cpp PriceRule.h RemainingSeat.cpp RemainingSeat.h Recommend_sys.cpp Recommend_sys.h FlightAns.cpp FlightAns.h Net.cpp Net.h FlightSet.cpp FlightSet.h SameDayFlight.cpp SameDayFlight.h)
