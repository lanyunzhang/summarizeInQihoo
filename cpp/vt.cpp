#include<iostream>
using namespace std;

class Pa{
    public:
        virtual void print(){
            cout<<"Pa print()"<<endl;
        }
        virtual void eat(){
            cout<<"Pa eat()"<<endl;
        }
        void catchs(){
            cout<<"Pa catchs"<<endl;
        }
};

class Chi:public Pa{
    public:
        virtual void print(){
            cout<<"Chi print()"<<endl;
        }
        virtual void eat(){
            cout<<"Chi eat()"<<endl;
        }
        virtual void catchs(){
            cout<<"Chi catchs"<<endl;
        }
};

// has one byte.
class m{
};

int main(){
    Pa p;
    m M;
    cout<<sizeof(p)<<endl;
    cout<<sizeof(M)<<endl;
    p.print();
    Pa* ps = new Chi();
    ps->print();
    // not contains virutal pointer in child class
    ps->catchs();
}

// cut the object 

