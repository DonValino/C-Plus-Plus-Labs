//
//  TemplateLab.cpp
//  Lab2
//
//  Created by Jake Valino on 30/01/2017.
//  Copyright © 2017 Jake Valino. All rights reserved.
//

#include "TemplateLab.hpp"
#include <iostream>
#include <string>

using namespace std;

// Constructor
TemplateLab::TemplateLab()
{
    
}



template <typename ElTyp> ElTyp TemplateLab::swapData(ElTyp x, ElTyp y)
{
    x = y;
    return x;
}