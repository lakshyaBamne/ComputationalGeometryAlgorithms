#include<iostream>
#include<vector>
#include<string>
#include<time.h>
#include<iomanip>
#include<ios>

#include "SlowConvexHull.h"

using namespace std;

int main(){
    time_t t_start, t_end;

    // random number generation
    srand(time(0));

    // reading input and logging
    SlowConvexHull sch;

    time(&t_start);

    sch.generate_random_data(-100, 100, 100);
    sch.read_input();

    // Make the convex hull
    sch.make_hull();
    sch.show_output();    

    // Write output to file 'hull.txt'
    sch.write_output("hull.txt");

    time(&t_end);

    // calculate time taken for execution
    double time_taken = double(t_end - t_start);

    cout << "Time taken during execution : " << fixed << time_taken << setprecision(10) << "seconds" << endl;
}