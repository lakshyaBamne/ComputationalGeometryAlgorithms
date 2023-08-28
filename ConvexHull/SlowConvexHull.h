/*
    ! Slow Convex Hull (Brute Force)

    -> Brute force approach that just implements the Geometric Structure of the problem
    -> given a directed ray passing through two points, it is an edge in the Convex Hull
    -> iff all the remaining points of the set are on the right/left of the edge or exactly on it

    ! Time Complexity - O(n^3)
*/
#pragma once

#include<utility>
#include<vector>

using namespace std;

class SlowConvexHull{
private:
    vector< pair<int,int> > data; // Input set of points
    vector< pair<int,int> > hull; // Resulting Convex Hull

public:
    // functions to output input and output values to standard output for logging and debugging
    void show_input();
    void show_output();

    // Function to read input from a text file containing
    // one point in one line with comma separated coordinates
    void read_input();

    // Function to create a convex hull for the given data points
    void make_hull();

    // Function to create the vector of points which represent the hull in Counter clockwise direction
    // when given the set of edges in the convex hull
    void get_hull(vector< vector<pair<int,int>> > hull_edges);

    // Function to write output into a file named hull.txt
    void write_output();
};

