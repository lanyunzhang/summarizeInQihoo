#include<iostream>

class md{
   public:
      int val;
      virtual void g(int a){ std::cout<<"md g"<<std::endl;}
      char v1;
};

class mc:public md{
   public:
       char v2;
       void g(int b){ std::cout<< "mc g"<<std::endl;}
};

class mb:public mc{
   public:
	char v3;
};

int main(){
   md d; 
   d.g(1); // md g
   mc c;
   mb b;
   std::cout<<sizeof(d)<<std::endl;
   std::cout<<sizeof(c)<<std::endl;
   std::cout<<sizeof(b)<<std::endl;	

   md* dd = new mc();
   dd->g(1); // mc g
   //std::cout<<"sizeof md ="<<sizeof(md)<std::endl;
   //std::cout<<"sizeof md*="<<sizeof(*dd)<<std::endl;
   (*dd).g(1); // why ??? --> 

   md mmd = (*dd);
   mmd.g(1); // md g
   return 0;
}
/** 8 12 12  depending on compliler */
