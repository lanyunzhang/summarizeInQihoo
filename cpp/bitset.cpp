#include<bitset>
#include<iostream>

int main(){

    std::bitset<32> b;
    std::cout<<b.count()<<std::endl;
    b.set(3);
    std::cout<<b.count()<<std::endl;
    return 0;
}
