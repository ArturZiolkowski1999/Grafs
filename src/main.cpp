#include <iostream>
#include "Graph.h"
#include "Timer.h"
#include "List.h"

int main() {
    Graph<5> graph(100);
    std::cout << graph << std::endl;
    // graph.print_adjacency_list();
    // std::cout << std::endl;
    graph.dijkstra_algorithm_list_repr(1);
    graph.dijkstra_algorithm_matrix_repr(1);
}
