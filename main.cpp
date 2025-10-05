#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#include "Graph.h"

int main(int argc, const char* argv[]) {
    if (argc != 2)
    {
        std::cout << "./project4 inputFile" << std::endl;
        return EXIT_FAILURE;
    }
    string inputFileName = argv[1];
    
    Graph network;
    ifstream inFS;
    
    inFS.open(inputFileName);
    
    if(!inFS) {
        return -1;
    }
    
    while(!inFS.eof()) {
        string tempName;            //Main account
        string tempFollower;        //Follower of main account
        
        inFS >> tempName;
        inFS >> tempFollower;
        
        //Turns the usernames to fully lowercase
        std::transform(tempName.begin(), tempName.end(), tempName.begin(),
        [](unsigned char c){ return std::tolower(c); });
        std::transform(tempFollower.begin(), tempFollower.end(), tempFollower.begin(), 
        [](unsigned char c){ return std::tolower(c); });
        
        //If the account does not exist create new user in graph
        if(network.userExistsAt(tempName) == -1 && tempName != "") {
            network.addUser(tempName);
        }
        
        if(network.userExistsAt(tempFollower) == -1 && tempFollower != "") {
            network.addUser(tempFollower);
        }
        
        //Adds follower to a user
        if(tempName != "") {
            network.graph.at(network.userExistsAt(tempName)).addFollower(tempFollower);
        }
        if(tempFollower != "") {
            network.graph.at(network.userExistsAt(tempFollower)).addFollowing(tempName);
        }
    }
    
    //Adds followings to each user and calculates the in degree
    for(unsigned int i=0; i<network.graph.size(); i++) {
        network.graph.at(i).calcInDegree();
    }
    
    
    //Find root node by determining the max in degree 
    int max = network.graph.at(0).getInDegree();
    int maxIndex = 0;
    for(unsigned int i=0; i<network.graph.size(); i++) {
        if(max < network.graph.at(i).getInDegree()) {
            max = network.graph.at(i).getInDegree();
            maxIndex = i;
        }
        else if(max == network.graph.at(i).getInDegree() && network.graph.at(maxIndex).getName() > network.graph.at(i).getName()) {
            max = network.graph.at(i).getInDegree();
            maxIndex = i;
        }
    }
    
    //Print the root and other formalities
    cout << "The root user is " << network.graph.at(maxIndex).getName() << ", with in-degree centrality of " << network.graph.at(maxIndex).getInDegree() << "." << endl;
    cout << "There are " << network.graph.size() << " users in the social network." << endl;
    
    //Determine all users of depth of 1 from root node
    vector<string> users(0);
    for(unsigned int i=0; i<network.graph.at(maxIndex).followers.size(); i++) {
        string tempUser;
        tempUser = network.graph.at(maxIndex).followers.at(i);
        
        users.push_back(tempUser);
    }
    
    //Print out the depth 1 nodes and print their followers (depth 2) in order
    sort(users.begin(), users.end());
    cout << network.graph.at(maxIndex).getName() << " (0)" << endl;
    for(auto i : users) {
        cout << i << " (1)" << endl;
        auto key = network.userExistsAt(i);
            if(key != -1){
                sort(network.graph.at(key).followers.begin(), network.graph.at(key).followers.end());
                    for(auto j: network.graph.at(key).followers) {
                        cout << j << " (2)" << endl;
                    }
            }
    }
    
    return 0;   
}