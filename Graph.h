#ifndef GRAPH_H
#define GRAPH_H

#include "Project4a.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

class Graph{
    private:
        
    public:
        Graph();
        
        vector<User> graph;
        
        int userExistsAt(string username);
        
        void addUser(User username);
        
};
#endif // GRAPH_H