 #include "test_const.h"
 #include<iostream>
 using namespace std;
 
 int main(){
       test_const * test = new test_const(5);
       test->resize(4);

       //test_const tc = 1;
       //cout<<tc.getX()<<endl;

       test_const a(3);
       test_const b = a;
       b.getX();

       a = a;
       b = a;

       int test_const::*pmic;
       pmic = &test_const::y; // must be public ,if is private or protected will report error.

       b.*pmic = 4;
       cout<<"b.y="<<b.y<<endl;

       return 0;
 }
