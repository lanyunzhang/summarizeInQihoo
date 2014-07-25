#include<boost/weak_ptr.hpp>
#include<boost/shared_ptr.hpp>
#include<stdio.h>

class fish;
typedef boost::weak_ptr<fish> fishptr;
typedef boost::shared_ptr<fish> sfishptr;

class fish{
    public:
        void swimming(){
            
        }
    private:
        int num;
};

int main(){
    sfishptr fp(new fish());
    fp->swimming();
    return 0;
}

/*
 *  use weak_ptr can decide if the shared_ptr is 
 *  dead or not.
 */
