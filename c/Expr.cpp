#include<iostream>
#include<ostream>
#include<string>

class Expr{
   public:
       Expr(){expr_left = expr_right = expr_num = NULL;};
       Expr(std::string op,int num);
       Expr(std::string op,int left,int right);
       Expr(std::string op,const Expr &e);
       Expr(std::string op,const Expr &l , const Expr &r);
       ~Expr();
       //Expr(const Expr& e);
       friend std::ostream& operator<<(std::ostream& os,const Expr& e);
   private:
       bool unary;
       bool binary;
       std::string op;
       int left;
       int right;
       int num;
       Expr* expr_left;
       Expr* expr_right;
       Expr* expr_num; 
};

Expr::Expr(std::string op,int num){
    this->op = op;
    this->num = num;
    unary  = true;
    binary = false;
    expr_left = expr_right = expr_num = NULL;
}

Expr::Expr(std::string op,int left,int right){
    this->op = op;
    this->left = left;
    this->right = right;
    unary  = false;
    binary = true;
    expr_left = expr_right = expr_num = NULL;
}

Expr::Expr(std::string op, const Expr& e){
    this->op = op;
    unary = true;
    binary = false;
    expr_num = new Expr();
    *expr_num = e; 
    expr_left = expr_right = NULL;
}

Expr::Expr(std::string op,const Expr& l ,const Expr& r){
    this->op = op;
    unary  = false;
    binary = true;
    expr_left = new Expr();
    expr_right = new Expr();
    *expr_left = l;
    *expr_right = r;
    expr_num = NULL;
}

Expr::~Expr(){
    if(expr_left  != NULL) { delete expr_left;}
    if(expr_right != NULL) { delete expr_right;}
    if(expr_num   != NULL) { delete expr_num;}
}
/**  default copy constructor 
Expr::Expr(const Expr& e){
    this->op = e.op;
    this->unary = e.unary;
    this->binary = e.binary;
    this->left = e.left;
    this->right = e.right;
    this->num = num;
    this->expr_left = e.expr_left;
    this->expr_right = e.expr_right;
    this->expr_num = e.expr_num;
} **/

std::ostream& operator<<(std::ostream& os,const Expr& e){

    if(e.unary){
        if(!e.expr_num)
            os<<"("<<e.op<<e.num<<")"; 
        else
            os<<"("<<e.op<<*(e.expr_left)<<")";
    }else if(e.binary){
        if(!e.expr_left || !e.expr_right)
            os<<"("<<e.left<<e.op<<e.right<<")"; 
        else
            os<<"("<<*(e.expr_left)<<e.op<<*(e.expr_right)<<")";
    }
    return os;
}

int main(){

    std::string a("*");
    std::string b("-");
    std::string c("+");
    Expr t(c,2,3);
    std::cout<<t<<std::endl;
    
    Expr f(b,5);
    std::cout<<f<<std::endl;

    Expr m(a,t,f);
    std::cout<<m<<std::endl;

    Expr u = Expr(a,Expr(b,5),Expr(c,3,4)); // call default operator= 
    std::cout<<u<<std::endl;

    Expr w = Expr(a,u,u);
    std::cout<<w<<std::endl;

    return 0;
}

/** failed!, mess code */
/** how to rewrite the code */
/** free 2 times */
