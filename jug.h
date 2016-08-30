/**
 * Course: CS 14 Summer 2016
 *
 * First Name:      Isaac
 * Last Name:       Lino
 * Username:        ilino
 * email address:   ilino001@ucr.edu
 *
 *
 * Assignment:      assn5
 * Filename :       jug.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */
#ifndef __JUG_H
#define __JUG_H

#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

class Jug {
    
    
public:
    
    
    int Ca=5;
    int Cb=3;
    int N=4;
    int fA;
    int fB;
    int eA;
    int eB;
    int pAB;
    int pBA;
    
   
    Jug(int,int,int,int,int,int,int,int,int);

    ~Jug();
    
    
  
    int jugA;
    int jugB;
    
    bool operator < (const Jug& that) const
    {
        if (jugA != that.jugA)
        {
            return jugA < that.jugA;
        }
        return jugB < that.jugB;
    }
   
    
    int Solve();
    static void BreadthFisrtSearch(Jug start, stack <pair <Jug, int> >& path);
    
    
    
protected:
    
private:
    
};



#endif
