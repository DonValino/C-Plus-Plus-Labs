//
//  main.cpp
//  JacketLinkedList
//
//  Created by Jake Valino on 19/11/2015.
//  Copyright © 2015 Jake Valino. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
#include "JacketList.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    JacketList j;
    j.addEnd("Addidas", 12);
    j.addFront("Nike", 11);
    j.alterNodeAtSpecificLocation("Nike");
    j.addEnd("Lacoste", 13);
    j.deleteNodeAtSpecificLocation("Lacoste");
    j.deleteMostRecent();
    j.display();
    cout << endl;
    cout << endl;
    cout << endl;
    JacketList j1(j);
    j1.display();
    cout << endl;
    cout << endl;
    cout << endl;
    JacketList j2;
    j2.addEnd("Vermoda", 1);
    j2 = j1;
    j2.display();
    cout << endl;
    cout << endl;
    cout << endl;
    
    JacketNode jN("Nike",12);
    JacketNode jN1("Nike",13);
    jN = jN + jN1;
    jN.display();
    
    cout << endl;
    cout << endl;
    cout << endl;
    
    JacketList j9;
    j9.addEnd("Penny",10);
    Jacket jack = j9.findNodeAtSpecificLocation("Penny");
    cin >> jack;
    jack.display();
    
    return 0;
}
