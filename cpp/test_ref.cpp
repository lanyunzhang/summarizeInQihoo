#include<iostream>
using namespace std;

void increment(int*& i){i++;}

int main(){
    int m = 0;
    int* i= &m;
    cout<<"i="<<i<<endl;
    increment(i);
    cout<<"i="<<i<<endl;
    //cout<<*i<<endl;
    return 0;
}
