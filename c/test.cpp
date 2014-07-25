#include<iostream>
#include<cstdio>
using namespace std;

class A{
};
class B{
    private:
        A a;
    public:
        A& func(){
            printf("%p***\n",&a);
            return a;
        }
};


int main(){
    B* b = new B();
    
    A& a = b->func();
    printf("%p\n",b->func());
    printf("%p\n",b->func());
    printf("%p\n",b->func());
    printf("%p\n",a);
    //cout<<a<<endl;
    //cout<<aa<<endl;
}
