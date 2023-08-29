#include<iostream>
#include<vector>
#include<string>
#include<time.h>

#include "SlowConvexHull.h"

using namespace std;

int main(){
    // random number generation
    srand(time(0));

    // reading input and logging
    SlowConvexHull sch;

    sch.generate_random_data(0, 100, 50);
    sch.read_input();

    // Make the convex hull
    sch.make_hull();
    sch.show_output();    

    // Write output to file 'hull.txt'
    sch.write_output("hull.txt");
}