#include "Project4a.h"

User::User() {
    this->name = "null";
}

User::User(string name) {
    this->name = name;
}

void User::addFollower(string follower) {
    followers.push_back(follower);
}

void User::addFollowing(string following) {
    followings.push_back(following);
}


bool User::operator<(const User& rhs) const {
    if(this->getName() < rhs.getName()) {
        return true;
    }
    else if(this->getInDegree() > rhs.getInDegree() && this->getName() == rhs.getName()) {
        return true;
    }
    else {
        return false;
    }
}