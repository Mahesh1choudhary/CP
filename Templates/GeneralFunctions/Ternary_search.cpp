https://www.hackerearth.com/practice/algorithms/searching/ternary-search/tutorial/


// TERNARY SEARCH ON INTEGERS
// finding maximum in array
int ternary_search(int l, int r){
    while(r-l>=3){
        int mid1=l+(r-l)/3;
        int mid2=r-(r-l)/3;
        if(find(mid1)<find(mid2)){
            l=mid1;
        }
        else r=mid2;
    }
    // now check values at l,l+1,l+2
}



// TERNARY SEARCH ON REALS
// error in ans will be (2/3)power(200) th of original interval(r-l)
double ternary_search(double l, double r){
    
    for(int i=0;i<200;i++){
        double mid1=(2*l+r)/3;
        double mid2=(l+2*r)/3;
        if(find(mid1)<find(mid2)){
            l=mid1;
        }
        else{
            r=mid2;
        }
    }

}

