#include<stdio.h>
#include<boost/function.hpp>
#include<boost/bind.hpp>

class Company{
    public:
        typedef boost::function<void(int sum)> callback;
        void print(){
            callback_(10);
        }
        Company(int e){
            employee = e;
        }
        void setCallback(callback cb){
           callback_ = cb; 
        }

    private:
        int employee;
        callback callback_;
};

class Employee{
    public:
        Employee(std::string name){
            name_ = name;
        } 
        void print(int sum){
            printf("name=%s,sum=%d\n",name_.c_str(),sum);
        }
        void setName(std::string name){
            name_ = name;
        }
    private:
        std::string name_;
};


int main(){
    Company qihoo(6000);
    Employee employee("lanyun");
    qihoo.setCallback(boost::bind(&Employee::print,&employee,_1));
    employee.setName("zhanglanyun"); // change the object
    qihoo.print();

    const Employee  el("zly");
    Employee* elc = const_cast<Employee*>(&el);
    //Employee* elc = &el;
    elc->setName("zlys");
    elc->print(100);

    //char* p="123";
    //p[0] = "1";
}
// when to use boost::bind , when to use raw function
// why somewhere use function to  
// the second args type for bind is pointer type
// add args
// _1 is 占位符
