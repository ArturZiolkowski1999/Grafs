#pragma once

#include <iostream>

class PriorityQueueNode {
public:
    unsigned int vertex;
    unsigned int weight;

    PriorityQueueNode(){
        this->vertex = 0;
        this->weight = 0;
    };

    PriorityQueueNode(unsigned int vertex, unsigned int weight){
        this->vertex = vertex;
        this->weight = weight;
    };

    static void swap_nodes(PriorityQueueNode** a, PriorityQueueNode **b){
        PriorityQueueNode* t = *a;
        *a = *b;
        *b = t;
    }
};

class PriorityQueue {
public:
    PriorityQueueNode **array;
    unsigned int size;
    unsigned int capacity;

    unsigned int *pos;

    PriorityQueue(unsigned int capacity);

    void heapify(unsigned int index);
    bool is_empty();
    PriorityQueueNode* extract_min();
    void decrease_key(unsigned int vertex, unsigned int weight);
    bool is_in_queue(unsigned int v);
    void print_solution(unsigned int dist[], int n);
};

PriorityQueue::PriorityQueue(unsigned int capacity){
    this->size = 0;
    this->capacity = capacity;
    this->pos = (unsigned int *)malloc(capacity * sizeof(unsigned int));
    this->array = (PriorityQueueNode**)malloc(capacity * sizeof(PriorityQueueNode*));
}

void PriorityQueue::heapify(unsigned int index){
    unsigned int smallest, left, right;
    smallest = index;
    left = 2 * index + 1;
    right = 2 * index + 2;

    if(left < this->size && this->array[left]->weight < this->array[smallest]->weight){
        smallest = left;
    }

    if(right < this->size && this->array[right]->weight < this->array[smallest]->weight){
        smallest = right;
    }

    if(smallest != index){
        PriorityQueueNode* smallestNode = this->array[smallest];
        PriorityQueueNode* indexNode = this->array[index];

        this->pos[smallestNode->vertex] = index;
        this->pos[indexNode->vertex] = smallest;

        PriorityQueueNode::swap_nodes(&this->array[smallest], &this->array[index]);

        this->heapify(smallest);
    }
}

bool PriorityQueue::is_empty(){
    return this->size == 0;
}

PriorityQueueNode* PriorityQueue::extract_min(){
    if(this->is_empty()) return NULL;

    PriorityQueueNode* root = this->array[0];
    PriorityQueueNode* last_node = this->array[this->size - 1];
    this->array[0] = last_node;

    this->pos[root->vertex] = this->size-1;
    this->pos[last_node->vertex] = 0;

    -- this->size;
    this->heapify(0);

    return root;
}

void PriorityQueue::decrease_key(unsigned int vertex, unsigned int weight){
    unsigned int i = this->pos[vertex];
    this->array[i]->weight = weight;

    while (i && this->array[i]->weight < this->array[(i-1)/2]->weight){
        this->pos[this->array[i]->vertex] = (i-1)/2;
        this->pos[this->array[(i-1)/2]->vertex] = i;

        PriorityQueueNode::swap_nodes(&this->array[i], &this->array[(i-1)/2]);

        i = (i - 1) / 2;
    }
}

bool PriorityQueue::is_in_queue(unsigned int v){
    if(this->pos[v] < this->size) return true;
    return false;
}

void PriorityQueue::print_solution(unsigned int distance[], int n){
    for(int k = 0; k < n; ++k){
        std::cout <<"Distance from vertex " << k << " Is:" << distance[k] <<std::endl;
    }

}
