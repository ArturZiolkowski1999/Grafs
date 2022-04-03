#pragma once

#include <iostream>

class Edge {
public:
    unsigned int vertex;
    unsigned int weight;
    Edge *next;

    Edge(){
        this->vertex = 0;
        this->weight = 0;
        this->next = nullptr;
    };

    Edge(unsigned int vertex, unsigned int weight){
        this->vertex = vertex;
        this->weight = weight;
        this->next = nullptr;
    };
};

class Linkedlist {
private:
    Edge *head;
public:
    Linkedlist(){this->head = nullptr; };
    void push(unsigned int vertex, unsigned int weight);
    friend std::ostream &operator<<(std::ostream &ost, Linkedlist &list);
};

void Linkedlist::push(unsigned int vertex, unsigned int weight){
    Edge *newEdge = new Edge(vertex, weight);
    
    if (this->head == nullptr){
        this->head = newEdge;
        return;
    }

    //go to the last node
    Edge* tmp = head;
    while(tmp->next != nullptr){
        tmp = tmp->next;
    }
    // insert node to the end
    tmp->next = newEdge;
}

std::ostream &operator<<(std::ostream &ost, Linkedlist &list) {
    Edge * tmp = list.head;
    if (list.head == nullptr){
        ost << "empty list";
        return ost;
    }

    while(tmp != nullptr){
        ost << "v:" << tmp->vertex << " w:" << tmp->weight << " ";
        tmp = tmp->next;
    }
    return ost;
}
