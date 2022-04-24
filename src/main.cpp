#include <iostream>
#include <tuple>
#include <array>
#include "Graph.h"
#include "Timer.h"
#include "List.h"
#include "Timer.h"

template <unsigned int vertices>
std::tuple<float,float> test_dikistra_both_repr(Graph<vertices> graph, unsigned int iterations){
    float result_list = 0;
    float result_matrix = 0;
    Benchmark timer_list;
    Benchmark timer_matrix;

    for(unsigned int i = 0; i < iterations; ++i){

        timer_list.Start();
        graph.dijkstra_algorithm_list_repr(1);
        result_list += timer_list.Stop();

        timer_matrix.Start();
        graph.dijkstra_algorithm_matrix_repr(1);
        result_matrix += timer_matrix.Stop();
    }

    result_list /= iterations;
    result_matrix /= iterations;

    return std::make_tuple(result_list, result_matrix);
}

int main() {

    // 50 elements graph
    for (unsigned int density = 25; density <= 100; density+=25){
            Graph<50> graph50(density);
            auto results = test_dikistra_both_repr<50>(graph50, 100);
            std::cout << "List representation, 50 elements "<<"density " <<density << ", time: " << std::get<0>(results) << std::endl;
            std::cout << "Matrix representation, 50 elements "<<"density " <<density << ", time: " << std::get<1>(results) << std::endl;
            std::cout << std::endl;
    }

    // 100 elements graph
    for (unsigned int density = 25; density <= 100; density+=25){
            Graph<100> graph100(density);
            auto results = test_dikistra_both_repr<100>(graph100, 100);
            std::cout << "List representation, 100 elements "<<"density " <<density << ", time: " << std::get<0>(results) << std::endl;
            std::cout << "Matrix representation, 100 elements "<<"density " <<density << ", time: " << std::get<1>(results) << std::endl;
            std::cout << std::endl;
    }

    // 150 elements graph
    for (unsigned int density = 25; density <= 100; density+=25){
            Graph<150> graph150(density);
            auto results = test_dikistra_both_repr<150>(graph150, 100);
            std::cout << "List representation, 150 elements "<<"density " <<density << ", time: " << std::get<0>(results) << std::endl;
            std::cout << "Matrix representation, 150 elements "<<"density " <<density << ", time: " << std::get<1>(results) << std::endl;
            std::cout << std::endl;
    }

    // 200 elements graph
    for (unsigned int density = 25; density <= 100; density+=25){
            Graph<200> graph200(density);
            auto results = test_dikistra_both_repr<200>(graph200, 100);
            std::cout << "List representation, 200 elements "<<"density " <<density << ", time: " << std::get<0>(results) << std::endl;
            std::cout << "Matrix representation, 200 elements "<<"density " <<density << ", time: " << std::get<1>(results) << std::endl;
            std::cout << std::endl;
    }

    // 250 elements graph
    for (unsigned int density = 25; density <= 100; density+=25){
            Graph<250> graph250(density);
            auto results = test_dikistra_both_repr<250>(graph250, 100);
            std::cout << "List representation, 250 elements "<<"density " <<density << ", time: " << std::get<0>(results) << std::endl;
            std::cout << "Matrix representation, 250 elements "<<"density " <<density << ", time: " << std::get<1>(results) << std::endl;
            std::cout << std::endl;
    }
    
}
