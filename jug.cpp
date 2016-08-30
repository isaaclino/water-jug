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
 * Filename :       jug.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */
#include <iostream>
#include <fstream>
#include <cstdlib>

#include <list>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <map>

#include <sstream>

#include "jug.h"

using namespace std;



Jug::Jug(int Ca, int Cb, int N, int fA, int fB, int eA, int eB, int pAB, int pBA)
{

    Ca  = 5;    // capacity of jug A
    Cb  = 3;    // capacity of jug B
    N   = 4;    // goal
    fA  = 1;    // cost to fill A
    fB  = 1;    // cost to fill B
    eA  = 1;    // cost to empty A
    eB  = 1;    // cost to empty B
    pAB = 1;    // cost to pour A to B
    pBA = 1;    // cost to pour B to A

}

Jug::~Jug() {}




void
Jug::BreadthFisrtSearch(Jug start, stack <pair <Jug, int> >& path)
{
    int Ca  = 5;    // capacity of jug A
    int Cb  = 3;    // capacity of jug B
    int N   = 4;    // goal
    int fA  = 1;    // cost to fill A
    int fB  = 1;    // cost to fill B
    int eA  = 1;    // cost to empty A
    int eB  = 1;    // cost to empty B
    int pAB = 1;    // cost to pour A to B
    int pBA = 1;    // cost to pour B to A
    
    
    queue <Jug> q;
    
 //   Jug goal = (Jug) {5,3,4,1,1,1,1,1,1};
    
    Jug goal = (Jug) {Ca, Cb, N, fA, fB, eA, eB, pAB, pBA };
    // Mapping from a Jug to its parent Jug and rule no. that
    // led to this Jug
    
    map <Jug, pair <Jug, int> > parent;
    
    
    q.push(start);
    parent[start] = make_pair(start, 0);


    cout << "q " << &q << endl;
    cout << "start " << &start << endl;
    cout << "path " << &path << endl;
    
    while (!q.empty())
    {
        Jug top = q.front();
        q.pop();
        
        // Check for goal N on jug A and Jug B
        if (top.jugA == N || top.jugB == N)
        {
            goal = top;
            break;
        }
        
        // Pour B to A
        // or until B is empty
        if (top.jugB > 0)
        {
            
            int minimum = top.jugA + top.jugB;
            int maximum = top.jugA + top.jugB - Ca;
            
            
            //Jug child = (Jug) {min(minimum, Ca), max(0, maximum)};
            Jug child = (Jug) {min(minimum, Ca), max(0, maximum), N, fA, fB, eA, eB, pAB, pBA};
            if (parent.find(child) == parent.end())
            {
                q.push(child);
                parent[child] = make_pair(top, 1);
            }
        }
        
        // Pour A to B
        // or until A is empty
        if (top.jugA > 0)
        {
            
            
            int minimum = top.jugA + top.jugB;
            int maximum = top.jugA + top.jugB - Cb;
            
            
            //Jug child = (Jug) {max(0, maximum), min(minimum, Cb)};
            Jug child = (Jug) {max(0, maximum), min(minimum, Cb), N, fA, fB, eA, eB, pAB, pBA};
            if (parent.find(child) == parent.end())
            {
                q.push(child);
                parent[child] = make_pair(top, 2);
            }
        }

        
        // (0, jugB) if jugA > 0
        // Empty B
        if (top.jugA > 0)
        {
            //Jug child = (Jug) {0, top.jugB};
            
            Jug child = (Jug) {0, top.jugB, N, fA, fB, eA, eB, pAB, pBA};
            if (parent.find(child) == parent.end())
            {
                q.push(child);
                parent[child] = make_pair(top, 3);
            }
        }
        
        // (jugB, 0) if jugB > 0
        // Empty B
        if (top.jugB > 0)
        {
            //Jug child = (Jug) {top.jugA, 0};
            Jug child = (Jug) {top.jugA, 0, N, fA, fB, eA, eB, pAB, pBA};
            if (parent.find(child) == parent.end())
            {
                q.push(child);
                parent[child] = make_pair(top, 4);
            }
        }

        
        // (Ca, JugB) if JugA < Ca
        // Fill A
        if (top.jugA < Ca)
        {
            //Jug child = (Jug) {Ca, top.jugB};
            
            Jug child = (Jug) {Ca, top.jugB, N, fA, fB, eA, eB, pAB, pBA};
            // Consider this Jug for visiting only if it has not been visited before
            if (parent.find(child) == parent.end())
            {
                q.push(child);
                parent[child] = make_pair(top, 5);
            }
        }
        
        
        // (Ca, JugB) if JugB < Cb
        // Fill B
        if (top.jugB < Cb)
        {
            //Jug child = (Jug) {top.jugA, Cb};
            
            Jug child = (Jug) {top.jugA, Cb, N, fA, fB, eA, eB, pAB, pBA};
            if (parent.find(child) == parent.end())
            {
                q.push(child);
                parent[child] = make_pair(top, 6);
            }
        }
    }
    
    //soution does not exist
    if (goal.jugA == -1 || goal.jugB == -1)
    {
        return;
        
    }
    
    
    
    path.push(make_pair(goal, 0));
    
    
    while (parent[path.top().first].second != 0)
    {
        path.push(parent[path.top().first]);
    }
    

    
}




int
Jug::Solve()
{
    stack <pair <Jug, int> > path;
   
    BreadthFisrtSearch((Jug) {5,3,4,1,1,1,1,1,1}, path);
    
    
    unsigned long suceess_moves =0;
    if (path.empty())
    {
        cout << "\nInvalid input.\n";
        return -1;
    }
    
    else
    {
        suceess_moves = path.size()-1;
        cout << endl;
        
        while (!path.empty())
        {
            Jug top = path.top().first;
            int rule = path.top().second;
            path.pop();
            
            
            switch (rule)
            {
                case 0:
                {
                    cout << "Jug A has " << top.jugA << " and Jug B has " << top.jugB << endl;
                    break;
                }
                case 1:
                {
                    cout << "Pour Jug B with " << top.jugB << " into Jug A with " << top.jugA << endl;
                    break;
                }
                case 2:
                {
                    cout << "Pour Jug A with " << top.jugA << " into Jug B with " << top.jugB << endl;
                    break;
                }
                case 3:
                {
                    cout << "Empty Jug A "<< top.jugA << endl;
                    break;
                }
                case 4:
                {
                    cout << "Empty Jug B " << top.jugB << endl;
                    break;
                }
                case 5:
                {
                    cout << "Filling Jug A... Currently has "<< top.jugA << endl;
                    break;
                }
                case 6:
                {
                    cout << "Filling Jug B... Currently has "<< top.jugB << endl;
                    break;
                }
            }
        }
        cout << "\nSuccess in " << suceess_moves << " moves"<<endl;
    }

    
    
    return 0;
}
