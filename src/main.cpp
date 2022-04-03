#include <iostream>
#include "Graph.h"
#include "Timer.h"
#include "List.h"

int main() {
    Graph<9> graph(50);
    std::cout << graph << std::endl;
    graph.print_adjacency_list();
}
