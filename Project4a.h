#ifndef Project4a_h
#define Project4a_h

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class User{
    
    private:
        string name;
        int inDegree;
        
    public:
        vector<string> followers;
        vector<string> followings;
        
        User();
        User(string name);
        
        void setName(string name) {this->name = name; };
        void setInDegree(int in) {inDegree = in; };

        void addFollower(string follower);
        void addFollowing(string following);
        
        string getName() const { return name; };
        int getInDegree() const { return inDegree; };

        void calcInDegree() { inDegree = followers.size(); };
        
        
        
        bool operator<(const User& rhs) const;
};

#endif // User 