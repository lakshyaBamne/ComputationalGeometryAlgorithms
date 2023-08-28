#include<iostream>
#include<vector>

#include "SlowConvexHull.h"

using namespace std;

int main(){
    // reading input and logging
    SlowConvexHull sch;
    sch.read_input();

    // Make the convex hull
    sch.make_hull();
    sch.show_output();    

    // Write output to file 'hull.txt'
}