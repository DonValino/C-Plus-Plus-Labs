//
//  main.cpp
//  Lab9b
//
//  Created by Jake Valino on 10/12/2015.
//  Copyright © 2015 Jake Valino. All rights reserved.
//

#include <iostream>
#include <string>
#include "Deque.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
   /* Rough Work
    Deque d;
    d.insertBack(1);
    d.insertBack(2);
    d.insertBack(3);
    d.insertBack(4);
    d.insertBack(5);
    d.insertBack(6);
    d.insertBack(7);
    d.insertBack(8);
    d.insertBack(9);
    d.insertBack(10);
    
    d.insertBack(11);
    d.insertBack(12);
    d.insertBack(13);
    d.insertBack(14);
    d.insertBack(15);
    d.insertBack(16);
    d.insertBack(17);
    d.insertBack(18);
    d.insertBack(19);
    d.insertBack(20);
    d.insertBack(21);
    d.insertBack(22);
    
    d.insertFront(69);
    d.insertFront(70);
    d.insertFront(71);
    d.insertFront(72);
    d.insertFront(73);
    d.insertFront(74);
    d.insertFront(75);
    d.insertFront(76);
    d.insertFront(77);
    d.insertFront(78);
    d.insertFront(79);
    d.insertFront(80);
    d.insertFront(81);
    d.insertFront(82);
    d.insertFront(83);
    d.insertFront(84);
    d.insertFront(85);
    d.insertFront(86);
    d.insertFront(87);
    d.insertFront(88);
    d.insertFront(89);
    d.insertFront(90);
    
    d.insertBack(66);
    d.insertBack(67);
    d.insertBack(68);
    int out = 68;
    d.removeBack(out);
     out = 67;
    d.removeBack(out);
    out = 66;
    d.removeBack(out);
    
    out = 90;
    d.removeFront(out);
    out = 89;
    d.removeFront(out);
    



    
    d.display();*/
    
    Deque d;
    d.insertBack(1);
    d.insertBack(2);
    d.insertBack(3);
    d.insertBack(4);
    d.insertBack(5);
    d.insertBack(6);
    d.insertBack(7);
    d.insertBack(8);
    d.insertBack(9);
    d.insertBack(10);
    d.insertBack(11);
    
    int out = d.getv()[d.getHead()];
    cout << "Out is: " << out << endl;
    d.removeFront(out);
    d.display();
    cout << endl;
    
    out = d.getv()[d.getHead()];
    cout << "Out is: " << out << endl;
    d.removeFront(out);
    d.display();
    cout << endl;
    
    out = d.getv()[d.getHead()];
    cout << "Out is: " << out << endl;
    d.removeFront(out);
    d.display();
    cout << endl;
    
    out = d.getv()[d.getHead()];
    cout << "Out is: " << out << endl;
    d.removeFront(out);
    d.display();
    cout << endl;
    
    out = d.getv()[d.getHead()];
    cout << "Out is: " << out << endl;
    d.removeFront(out);
    d.display();
    cout << endl;
    
    out = d.getv()[d.getHead()];
    cout << "Out is: " << out << endl;
    d.removeFront(out);
    d.display();
    cout << endl;
    
    out = d.getv()[d.getHead()];
    cout << "Out is: " << out << endl;
    d.removeFront(out);
    d.display();
    cout << endl;
    
    out = d.getv()[d.getHead()];
    cout << "Out is: " << out << endl;
    d.removeFront(out);
    d.display();
    cout << endl;
    
    out = d.getv()[d.getHead()];
    cout << "Out is: " << out << endl;
    d.removeFront(out);
    d.display();
    cout << endl;
    
    out = d.getv()[d.getHead()];
    cout << "Out is: " << out << endl;
    d.removeFront(out);
    d.display();
    cout << endl;
    
    
    /*Using exception handling has some advantages over other Error-Handling functions to find fatal errors/exceptions
     For instance, exceptions allows you to create a throw list which contains all the possible exceptions which may occur in your program. Then if an exception that was not predefined in your throwlist is catched, the unexpected method is called to handle the exception that has occured. With exception, you can also throw multiple exceptions instead of just looking out for a possible one. You can also catch multiple exceptions. Finally with exceptions, you can create your own predefined exception handler which may handle a specific exception that may have occured that is not defined in the standard library*/
    
    
    return 0;
}
