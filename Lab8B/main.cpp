//
//  main.cpp
//  Lab8B
//
//  Created by Jake Valino on 07/12/2015.
//  Copyright © 2015 Jake Valino. All rights reserved.
//

#include <iostream>
#include <string>
#include <iostream>
#include "PFArrayD.hpp"

using namespace std;
enum players
{
    Fred,
    Paul,
    Jim,
    Allen,
    playerCount
};

int& scores(players challenger)
{
    static int scoreCard[playerCount];
    cout << "Sex" << scoreCard[playerCount] << endl;
    return scoreCard[challenger];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scores(Fred) = 5;
    scores(Paul) = 10;
    
    cout << scores(Fred) << " " << endl;
    cout << scores(Paul) << " " << endl;
    return 0;
}
