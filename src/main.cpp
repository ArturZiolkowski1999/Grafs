#include <iostream>
#include "Graph.h"
#include "Timer.h"
#include "List.h"

int main() {
    Graph<5> graph(100);
    std::cout << graph << std::endl;
    graph.print_adjacency_list();
    graph.dijkstra_algorithm(1);
}
