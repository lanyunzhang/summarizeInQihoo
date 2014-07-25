#ifndef TEST_CONST_H
#define TEST_CONST_H

class test_const{
    public:
       int y;
       explicit test_const(int sx):x(sx){}; 
       // can not call not const function 
       // in const function
       // if set private , Type a = b is not valid.
       test_const(const test_const& tc);
       // if set private , then a=b is not valid.
       test_const& operator=(const test_const& tc);
       int getX() const {
            return x;
       }
       // default is inline
       void setX(int sx){
            x = sx;
       }
       void resize(int sz);
    private:
        int x;
};

#endif 
