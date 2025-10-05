#include "Graph.h"

Graph::Graph() {
}
int Graph::userExistsAt(string username) {
    
    if(graph.size() > 0) {
        for(unsigned int i=0; i<graph.size(); i++) {
            if(graph.at(i).getName() == username) {
                return i;
            }
        }
    }
    
    return -1;
}

void Graph::addUser(User username) {
    graph.push_back(username);
}