/**
 * First Name:      Isaac
 * Last Name:       Lino
 *
 * Filename :       main.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there
 * code from any outside resources such as another individual,
 * a website, or publishings. 
 *
 * All rights reserved by Isaac Lino
 * If you want to use this file, you have to give me credit for it!
 *
 */

include <iomanip>
#include <queue>
#include <stack>
#include <map>

#include "jug.h"

using namespace std;

int main()  {
    
    // create stack using map that stores path information
    stack <pair <Jug, int> > path;
        
   
    Jug die_hard(5,3,4,1,1,1,1,1,1);
    
    die_hard.BreadthFisrtSearch((Jug) {5,3,4,1,1,1,1,1,1}, path);
   
    die_hard.Solve();
    
    return 0;
}
