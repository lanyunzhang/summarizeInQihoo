#include <iostream> 
#include <string> 
using namespace std; 

class Expr_node 
{ 
    friend class Expr;  //友元类可以被继承 
    int use;                  //引用计数 
    public: 
        virtual void print(ostream&) const = 0; 
        Expr_node():use(1) {} 
        virtual ~Expr_node() {} 
        virtual int eval(){}
}; 

class Expr                     //句柄类 
{ 
    friend ostream& operator<<(ostream &o, const Expr &e); 
    private: 
        Expr_node *p;       //指向基类的指针 
    public: 

        Expr(int n); 

        Expr(const string &op, Expr t); 

        Expr(const string &op, Expr left, Expr right); 

        Expr(const Expr &t); 

        Expr& operator=(const Expr&); 
        
        int eval();

        ~Expr() 
        {  
            if(--p->use == 0) 
                delete p; 
        } 

}; 


class Int_node: public Expr_node 
{ 
    private: 
        int n; 
    public: 
        Int_node(int k):n(k) {} 
        void print(ostream &o) const 
        { 
            o << n; 
        } 
        int eval(){ return n; } 

}; 


class Unary_node: public Expr_node 
{ 
    private: 

        //friend class Expr; 
        string op; 
        Expr opnd; 
    public: 

        Unary_node(const string &a, Expr b):op(a), opnd(b) {} 

        void print(ostream &o) const 
        { 
            o << "(" << op << opnd << ")"; 
        } 
        int eval(){
            if(op == "-") return -(opnd.eval());
        }
}; 

class Binary_node: public Expr_node 
{ 
    private: 

        //friend class Expr; 

        string op; 
        Expr left; 
        Expr right; 

    public: 

        Binary_node(const string &a, Expr b, Expr c):op(a), left(b), right(c) {} 
        void print(ostream &o) const 
        { 
            o << "(" << left << op << right << ")"; 
        } 
        int eval(){
            if( op == "+" ) return left.eval() + right.eval();
            else if( op == "-" ) return left.eval() - right.eval();
            else if( op == "*" ) return left.eval() * right.eval();
            else if( op == "/" ) return left.eval() / right.eval();
        }
}; 

Expr::Expr(int n) { p = new Int_node(n); } 

Expr::Expr(const string& op, Expr t) { p = new Unary_node(op,t); } 

Expr::Expr(const string &op, Expr left, Expr right) { p = new Binary_node(op, left, right); } 

Expr::Expr(const Expr& t) { p = t.p; ++p->use; } 

Expr& Expr::operator=(const Expr& rhs) 
{ 
    rhs.p->use++; 
    if(--p->use == 0) 
        delete p; 
    p = rhs.p; 
    return *this; 
} 

int Expr::eval(){ return p->eval();}

ostream& operator<<(ostream &o, const Expr &e) 
{ 
    e.p->print(o); 
    return o; 
} 


int main() 
{ 
    Expr t = Expr("*", 

            Expr("-", Expr(5)), 

            Expr("+", Expr(3), Expr(4))); 

    cout << t << endl; 
    cout <<" the value of t is "<< t.eval()<<endl;
    return 0;
} 
