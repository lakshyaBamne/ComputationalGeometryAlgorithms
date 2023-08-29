#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<limits>
#include<set>

#include "Utility.h"
#include "SlowConvexHull.h"

using namespace std;

namespace UTL = Utility;

/*
    Function implementations
*/

void SlowConvexHull::show_input(){
    cout << "--------------------------INPUT SET----------------------------" << endl;
    for(auto i : data){
        cout << "<" << i.first << "," << i.second << ">" << endl;
    }
}

void SlowConvexHull::show_output(){
    cout << "--------------------------OUTPUT SET---------------------------" << endl;
    for(auto i : hull){
        cout << "<" << i.first << "," << i.second << ">" << endl;
    }
}

void SlowConvexHull::read_input(){
    string filename;
    // cout << "-----------------------INPUT-------------------------" << endl;
    // cout << "Input file name (TXT): " << endl;
    // cin >> filename;

    filename = "data.txt";

    // open the given file
    ifstream fin;
    fin.open(filename);

    string line;

    while( getline(fin, line) ){
        stringstream ss(line);
        string val;

        vector<int> x;

        while( !ss.eof() ){
            getline(ss, val, ',');
            x.push_back(stoi(val));
        }

        data.push_back({x[0],x[1]});
    }

    // close the file after use
    fin.close();
}

void SlowConvexHull::make_hull(){
    vector< vector< pair<int,int> > > hull_edges;

    // Scan through all triplets of points and find out the triplets with Clockwise orientations
    vector< pair<int,int> > rays = UTL::generate_rays(data.size());

    for(auto i : rays){
        int count=0;
        for(int k=0 ; k<data.size() ; k++){
            if( k!=i.first && k!=i.second ){
                if( UTL::find_orientation( data[i.first], data[i.second], data[k] ) >= 0 ){
                    count++;
                }
            }
        }

        if( count == data.size()-2 ){
            hull_edges.push_back({ data[i.first], data[i.second] });
        }
    }

    // LOG
    cout << "Hull Edges" << endl;
    for(auto i : hull_edges){
        cout << "<" << i[0].first << "," << i[0].second << "> -> <" << i[1].first << "," << i[1].second << ">" << endl;
    }

    // store output in the hull vector
    get_hull(hull_edges);
    
}

void SlowConvexHull::get_hull( vector< vector<pair<int,int>> > hull_edges ){    
    // first extract the unique edges
    // if there are multiple edges starting from a source add the minimum length ray

    set< vector< pair<int,int> > > unique_edges;

    for(auto i : hull_edges){
        vector< pair<int,int> > min_edge = i;
        
        for(auto j : hull_edges){
            if( j[0]==i[0] && j!=i ){
                if( UTL::distance( j[0] , j[1] ) < UTL::distance( min_edge[0], min_edge[1] ) ){
                    // found new shortest edge going from the same source
                    min_edge = j;
                }
            }
        }

        unique_edges.insert( { min_edge } );
    }

    vector< vector< pair<int,int> > > edges;

    for(auto i : unique_edges){
        edges.push_back( i );
    }

    cout << "Unique Hull Edges" << endl;
    for(auto i : edges){
        cout << "<" << i[0].first << "," << i[0].second << "> -> <" << i[1].first << "," << i[1].second << ">" << endl;
    }

    // Now convert the Unique hull edges to a vector
    hull.push_back( edges[0][0] );

    while( hull.size() < edges.size() ){
        for(auto i : edges){
            if( i[0] == hull.back() ){
                hull.push_back( i[1] );
            }
        }
    }

    hull.push_back(hull[0]);

}

void SlowConvexHull::write_output(string filename){
    ofstream fout;

    fout.open( filename , ios::app );

    for(auto i : hull){
        fout << i.first << "," << i.second << endl;
    }

    fout.close();
}   


void SlowConvexHull::generate_random_data(int ll, int up, int n){
    
    ofstream fout;

    fout.open( "data.txt" , ios::app );

    for(int i=0 ; i<n ; i++){
        int x = rand() % (up-ll+1) + ll;
        int y = rand() % (up-ll+1) + ll;

        fout << x << "," << y << endl;
    }

    fout.close();

}
