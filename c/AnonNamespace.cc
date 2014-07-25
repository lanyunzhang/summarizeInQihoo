#include<stdio.h>

namespace{

   int getResult(int num){
        return num*num;
   }
}

namespace zly{

    int get(){
       int square = getResult(4);
       return square;
    }

}

namespace top{
    namespace wxl{
        
        int get(){
            
            int square = getResult(4);
            return square;
        }
    }
}

int main(){
    int res = zly::get();
    printf("%d\n",res);

    int squ = top::wxl::get();
    printf("%d\n",squ);
}

// the same translate unit , 即只对一个编译单元可见，
// 对其它的编译单元，默认看不到这个匿名空间的变量和
// 函数，类似 static 的作用，但是还有所不同。
