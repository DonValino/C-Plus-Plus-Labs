//
//  DequeEmpty.hpp
//  Lab9b
//
//  Created by Jake Valino on 13/12/2015.
//  Copyright © 2015 Jake Valino. All rights reserved.
//

#ifndef DequeEmpty_hpp
#define DequeEmpty_hpp

#include <stdio.h>
#include <string>
#include <stdio.h>

using namespace std;
class DequeEmpty{
private:
    string message;

public:
    DequeEmpty(){ //the constructor
        message = "Exception: Array is empty.\n";
    } //in-lined
    
    const string what() const {
        return message;
    } //in-lined
};
#endif /* DequeEmpty_hpp */
