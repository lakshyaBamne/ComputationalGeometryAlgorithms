/*
    Utility File containing useful functions used while 
    working with Computational Geometry algorithms
*/
#pragma once

#include<vector>
#include<utility>
#include<cmath>

using namespace std;

namespace Utility{ 
    // Function to find the orientation of points A,B,C
    // -> Clockwise = 1
    // -> Counter Clockwise = -1
    // -? Collinear = 0
    int find_orientation(pair<int,int>& A, pair<int,int>& B, pair<int,int>& C);

    // Function to generate unique ordered triplets with unique values
    vector< pair<int,int> > generate_rays(int size);

    // Function to find the distance between two points
    int distance(pair<int,int>& p1, pair<int,int>& p2);
}

int Utility::find_orientation(pair<int,int>& A, pair<int,int>& B, pair<int,int>& C){
    int value = ( B.first-A.first )*( C.second-A.second ) - ( B.second-A.second )*( C.first-A.first );

    if( value == 0 ){
        return 0;
    }
    else if( value < 0 ){
        return -1;
    }
    else{
        return 1;
    }
}

vector< pair<int,int> > Utility::generate_rays(int size){
    vector< pair<int,int> > rays;

    for(int i=0 ; i<size ; i++){
        for(int j=0 ; j<size ; j++){
            if( i != j ){
                rays.push_back( {i,j} );
            }
        }
    }

    return rays;
}

int Utility::distance(pair<int,int>& p1, pair<int,int>& p2){
    return (p2.first-p1.first)*(p2.first-p1.first) + (p2.second-p1.second)*(p2.second-p1.second);
}
