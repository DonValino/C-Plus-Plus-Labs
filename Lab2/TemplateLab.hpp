//
//  TemplateLab.hpp
//  Lab2
//
//  Created by Jake Valino on 30/01/2017.
//  Copyright © 2017 Jake Valino. All rights reserved.
//

#ifndef TemplateLab_hpp
#define TemplateLab_hpp
#include <iostream>
#include <string>

using namespace std;
#include <stdio.h>
class TemplateLab
{
public:
    TemplateLab();

template <typename ElTyp> ElTyp swapData(ElTyp x, ElTyp y);
};

#endif /* TemplateLab_hpp */
