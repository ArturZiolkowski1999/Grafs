#pragma once

#include <iostream>
#include <memory>
#include <chrono>

class Benchmark
{
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start_point;
        float duration; // [us]

    public:
        Benchmark(){
            this->start_point = std::chrono::high_resolution_clock::now();
            this->duration = 0;
        }

        ~Benchmark(){
            Stop();
        }

        float Stop(){
            auto end_point = std::chrono::high_resolution_clock::now();

            auto start = std::chrono::time_point_cast<std::chrono::microseconds>(this->start_point).time_since_epoch().count();
            auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point).time_since_epoch().count();
            this->duration = (end - start);
            return this->duration;
        }
        
        float get_duration(){
            return this->duration;
        }

        void Start(){
            this->start_point = std::chrono::high_resolution_clock::now();
        }
    
};
