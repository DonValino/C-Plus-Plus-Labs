//
//  DequeFull.hpp
//  Lab9b
//
//  Created by Jake Valino on 13/12/2015.
//  Copyright © 2015 Jake Valino. All rights reserved.
//

#ifndef DequeFull_hpp
#define DequeFull_hpp
#include <string>
#include <stdio.h>

using namespace std;
class DequeFull{
private:
    string message;
public:
    DequeFull(){ //the constructor
        message = "Exception: Array is Full. Size is now dynamically increased\n";
    } //in-lined
    
    const string what() const {
        return message;
    } //in-lined
};
#endif /* DequeFull_hpp */
