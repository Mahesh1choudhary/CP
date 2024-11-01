#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

// LINK -> https://cp-algorithms.com/geometry/convex-hull.html


// METHOD 1 -> GRAHAM SCAN ALGORITHM
/*
find bottom-most point(if two points with same y, then choose one with lowest x) let it be P0, sort all other points by polar angle (with respect to bottom-most point) in clockwise order.
If two or more points have same polar angle, then tie is broken by distance from point P0, increasing order
Iterate through each point one by one, if current point and previous two points are make clockwise turn, then add this point and continue, otherwise remove previous point and continue

special case -> if we need to include collinear points
Then after sorting, get the points that have biggest polar distance from P0 and are collinear( this should be at the end of sorted vector)
Reverse the points in this line
THIS STEP SHOULDN'T BE INCLUDED IN NON COLLINEAR VERSION OF ALGORITHM, OTHERWISE WE WOULDN'T GET THE SMALLEST CONVEX HULL.

*/

struct point{
    double x,y;
};

// return 1->if clockwise, -1-> if anticlockwise, 0 -> if collinear
// we use cross product to check orientation-> a, b, c are in order, then two lines are l1=b-a and l2=c-b, cross pruct gives l1x*l2y - l2x*l1y
int orientation(point a, point b, point c){
    double l1x=b.x-a.x, l1y=b.y-a.y, l2x=c.x-b.x,  l2y=c.y-b.y;
    double v= l1x*l2y - l2x*l1y;
    if(v<0) return -1; // clockwise
    if(v>0) return +1; // anticlockwise
    return 0;   // collinear
}

// order should be a then b and then c
bool collinear(point a, point b, point c){
    return orientation(a,b,c)==0;
}

// check if three point a, b,c in order are clockwise
bool cw(point a, point b, point c, bool include_collinear){
    int orient=orientation(a,b,c);
    return orient<0 || (include_collinear && orient==0);
}

void convex_hull(vector<point> &point_vec, bool include_collinear =false){
    point p0 = *min_element(point_vec.begin(), point_vec.end(), [](point a, point b){
        return make_pair(a.y,a.x) < make_pair(b.y,b.x);
    });

    sort(point_vec.begin(), point_vec.end(), [&p0](const point& a, const point& b){
        int orient= orientation(p0,a,b);
        if(orient==0){
            return (p0.x-a.x)*(p0.x-a.x)+(p0.y-a.y)*(p0.y-a.y) < (p0.x-b.x)*(p0.x-b.x)+(p0.y-b.y)*(p0.y-b.y);
        }
        return orient<0;
    });

    if(include_collinear){
        int i=(int)point_vec.size()-1;
        while(i>=0 && collinear(p0,point_vec[i],point_vec.back())) i--;
        reverse(point_vec.begin()+i+1, point_vec.end());
    }

    vector<point> st;
    for(int i=0; i<(int)point_vec.size(); i++){
        while(st.size()>1 && !cw(st[st.size()-2], st.back(), point_vec[i], include_collinear) ){
            st.pop_back();
        }
        st.push_back(point_vec[i]);
    }
    point_vec=st;

}








// METHOD 2 ->  MONOTONE CHAIN ALGORITHM
/*
First find leftmost and rightmost points A and B. If multiple such points exist, choose lowest on leftmost y coordinate and highest on rightmost.
Construct upper convex hull (above line AB) and lower convex hull (below line AB) and combine them to get the answer. Points A and B belong to both sets

To get upper set, sort points by x-coordinate. For each point check if either the current point is the last point(i.e. B) or orientation between the line between A and current point and line between current point and B is clockwise
then point will belong to upper set

*/



struct point{
    double x,y;
};

int orientation(point a, point b, point c){
    double l1x=b.x-a.x, l1y=b.y-a.y, l2x=c.x-b.x,  l2y=c.y-b.y;
    double v= l1x*l2y - l2x*l1y;
    if(v<0) return -1; // clockwise
    if(v>0) return +1; // anticlockwise
    return 0;   // collinear
}

// order should be a then b and then c
bool collinear(point a, point b, point c){
    return orientation(a,b,c)==0;
}

// check if three point a, b,c in order are clockwise
bool cw(point a, point b, point c, bool include_collinear){
    int orient=orientation(a,b,c);
    return orient<0 || (include_collinear && orient==0);
}

// check if three point a, b,c in order are clockwise
bool ccw(point a, point b, point c, bool include_collinear){
    int orient=orientation(a,b,c);
    return orient>0 || (include_collinear && orient==0);
}

void convex_hull(vector<point> point_vec, bool include_collinear=false){
    if(point_vec.size()==1) return;

    sort(point_vec.begin(), point_vec.end(), [](point a, point b){
        return make_pair(a.x,a.y)<make_pair(b.x,b.y);
    });
    
    point p1=point_vec[0], p2=point_vec.back(); // A and B- leftmost and rightmost points
    vector<point> up, down;
    up.push_back(p1);
    down.push_back(p2);
    
    for(int i=1;i<(int)point_vec.size();i++){
        if(i==point_vec.size()-1 || cw(p1,point_vec[i],p2,include_collinear)){
            while(up.size()>=2 && !cw(up[up.size()-2], up[up.size()-1], point_vec[i],include_collinear)){
                up.pop_back();
            }
            up.push_back(point_vec[i]);
        }
        if(i==point_vec.size()-1 || ccw(p1,point_vec[i],p2,include_collinear)){
            while(down.size()>=2 && !ccw(down[down.size()-2], down[down.size()-1], point_vec[i],include_collinear)){
                down.pop_back();
            }
            down.push_back(point_vec[i]);
        }
    }

    if(include_collinear && up.size()==point_vec.size()){
        reverse(point_vec.begin(), point_vec.end());
        return;
    }
    point_vec.clear();
    for(int i=0;i<(int)up.size();i++){
        point_vec.push_back(up[i]);
    }
    for(int i=down.size()-2;i>0;i--){
        point_vec.push_back(down[i]);
    }

}




