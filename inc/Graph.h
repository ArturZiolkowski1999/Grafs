#pragma once

#include <iostream>
#include <array>
#include <stdlib.h> // rand
#include <bits/stdc++.h> // INT_MAX
#include <time.h>  // time
#include <stdexcept> // invalid_argument

#include "PriorityQueue.h"
#include "List.h"

template <unsigned int vertices>
class Graph {
private:
    std::array<Linkedlist, vertices> adjacency_list_matrix;
    std::array<int, vertices * vertices> edge_weight_matrix;
    unsigned int density;
    void create_adjacency_list();
    unsigned int min_distance(std::array<unsigned int, vertices> &distance, std::array<bool, vertices> &Tset);
public:
    Graph(unsigned int density = 0);
    std::array<unsigned int, vertices> dijkstra_algorithm_matrix_repr(unsigned int vertex);
    std::array<unsigned int, vertices> dijkstra_algorithm_list_repr(unsigned int vertex);
    void reshuffle(unsigned int density = 0);

    void print_adjacency_list();
    template<unsigned int vertices1>
    friend std::ostream &operator<<(std::ostream &ost, Graph<vertices1> &graph);
};

template<unsigned int vertices>
Graph<vertices>::Graph(unsigned int density) {
    this->density = density;
    this->reshuffle(density);
    this->create_adjacency_list();
}

template<unsigned int vertices>
std::ostream &operator<<(std::ostream &ost, Graph<vertices> &graph) {

    int empty_edges = ((100 - int(graph.density)) * (vertices * vertices - vertices))/ 100;
    ost << "Graph vertices: " << vertices << " Graph density: " << graph.density;
    ost << " Graph empty edges: " << empty_edges << std::endl;
    for (int i = 0; i < vertices; ++i){
        for (int j = 0; j < vertices; ++j){
            if (graph.edge_weight_matrix[i*vertices+j] == INT_MAX){
                ost << "*" << " ";
            }else{
                ost << graph.edge_weight_matrix[i*vertices+j] << " ";
            }
        }
        ost << std::endl;
    }
    return ost;
}

template<unsigned int vertices>
void Graph<vertices>::reshuffle(unsigned int density) {
    // chceck if density is between 0 an 100
    if (density > 100 || density < 0)
        throw std::invalid_argument("Unexpected density value");
    // initialize rand
    std::srand(time(NULL));
    // fill edges with not empty value
    for (int index = 0; index < vertices*vertices; ++index){
        if(index/vertices != index%vertices){
            this->edge_weight_matrix[index] = std::rand() % 999 + 1;
        }else {
            this->edge_weight_matrix[index] = 0;
        }
    }

    int empty_edges = ((100 - int(density)) * (vertices * vertices - vertices))/ 100;
    unsigned int random_index;
    unsigned int next_index;
    // fill matrix with proper amount od empty edges on quasi random positions
    while(empty_edges != 0){
        random_index = std::rand() % (vertices * vertices);
        // leave diagonal edges with value 0 and leave empty edges
        if (this->edge_weight_matrix[random_index] != INT_MAX && this->edge_weight_matrix[random_index] != 0){
            this->edge_weight_matrix[random_index] = INT_MAX;
            empty_edges--;
        }else if(this->edge_weight_matrix[random_index] == INT_MAX){
            // looking for next place that is not empty, and empty that.
            // This should help speed the code
            next_index = (random_index + 1) % (vertices * vertices);
            while(next_index != random_index){
                // leave diagonal edges with value 0
                if(this->edge_weight_matrix[next_index] != INT_MAX && this->edge_weight_matrix[next_index] != 0){
                    this->edge_weight_matrix[next_index] = INT_MAX;
                    empty_edges--;
                    next_index = random_index;
                }else{
                    next_index = (next_index + 1) % (vertices * vertices);
                }    
            }
        } 
    } 
}

template<unsigned int vertices>
void Graph<vertices>::create_adjacency_list() {
    for(int row = 0; row < vertices; ++row){
        for(int column = 0; column < vertices; ++column){
            if(this->edge_weight_matrix[row*vertices+column] != INT_MAX 
                && this->edge_weight_matrix[row*vertices+column] != 0){
                this->adjacency_list_matrix[row].push(column, this->edge_weight_matrix[row*vertices+column]);
            }
        }
    }
}

template<unsigned int vertices>
void Graph<vertices>::print_adjacency_list() {
    for(int row = 0; row < vertices; ++row){
        std::cout << "vertices:" << row << "-> ";
        std::cout << this->adjacency_list_matrix[row] << std::endl;
    }
}

template<unsigned int vertices>
std::array<unsigned int, vertices> Graph<vertices>::dijkstra_algorithm_matrix_repr(unsigned int vertex){
    std::array<unsigned int, vertices> distance;
    std::array<bool, vertices> Tset;

    for(int v = 0; v < vertices; ++v){
        distance[v] = INT_MAX;
        Tset[v] = false;
    }

    distance[vertex] = 0;

    for(int i = 0; i < vertices; ++i){
        unsigned int nearest = this->min_distance(distance, Tset);
        Tset[nearest] = true;
        for(int j = 0; j < vertices; ++j){
            if(!Tset[j] && this->edge_weight_matrix[vertices*nearest+j] && distance[nearest] != INT_MAX
                && distance[nearest] + this->edge_weight_matrix[vertices*nearest+j] < distance[j]){
                    distance[j] = distance[nearest] + this->edge_weight_matrix[vertices*nearest+j];
                }
        }
    }


    //Display should not be there, but im lazy
    // Uncoment for printing reasult
    // std::cout << "Vertex :" << vertex << std::endl;
    // for(int k = 0; k < vertices; ++k){
    //     std::cout <<"Distance from vertex " << k << " Is:" << distance[k] <<std::endl;
    // }

    return distance;
}

template<unsigned int vertices>
unsigned int Graph<vertices>::min_distance(std::array<unsigned int, vertices> &distance, std::array<bool, vertices> &Tset){
    unsigned int minimum = INT_MAX,ind;

    for(int i = 0; i<vertices; ++i){
        if(Tset[i] == false & distance[i] <= minimum){
            minimum = distance[i];
            ind = i;
        }
    }
    return ind;
}

template<unsigned int vertices>
std::array<unsigned int, vertices> Graph<vertices>::dijkstra_algorithm_list_repr(unsigned int vertex){
    
    unsigned int distance[vertices];

    PriorityQueue* min_heap = new PriorityQueue(vertices);

    for(int v = 0; v < vertices; ++v){
        distance[v] = INT_MAX;
        min_heap->array[v] = new PriorityQueueNode(v, distance[v]);

        min_heap->pos[v] = v;
    }

    min_heap->array[vertex] = new PriorityQueueNode(vertex, distance[vertex]);
    min_heap->pos[vertex] = vertex;
    distance[vertex] = 0;
    min_heap->decrease_key(vertex, distance[vertex]);

    min_heap->size = vertices;

    while(!min_heap->is_empty()){
        PriorityQueueNode* min_heap_node = min_heap->extract_min();

        unsigned int u = min_heap_node->vertex;

        Edge * pCrawl = this->adjacency_list_matrix[u].head;

        while(pCrawl != NULL){
            unsigned int v = pCrawl->vertex;

            if(min_heap->is_in_queue(v) && distance[u] != INT_MAX 
                && pCrawl->weight + distance[u] < distance[v]){
                    distance[v] = distance[u] + pCrawl->weight;

                    min_heap->decrease_key(v, distance[v]);
                }
                pCrawl = pCrawl->next;
        }
    }
    // Uncoment for printing reasult //
    // min_heap->print_solution(distance, vertices);

    // gowno kod alert !!!
    std::array<unsigned int, vertices> result;
    for (int i = 0; i < vertices; ++i){
        result[i]= distance[i];
    }
    // koniec alertu

    return result;
}
