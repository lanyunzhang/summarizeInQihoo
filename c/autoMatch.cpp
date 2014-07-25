#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

/*
 *   Description: 判断Pk是否为Pqa的后缀 
 *     k==0,Pk==ε,k>0时,Pk==P[0..k-1],
 *       Pq==[0..q-1]，取其后k-1个字符为P[q-k+1..q-1] 
 *       */

bool Expect_Prefix(const char *P, int k, int q, char a)
{
    if(k == 0)
        return true;
    if(k == 1)//q==0时k==1,因为k = min(m,q+1); 
    {
        return P[k-1] == a;
    }
    return P[k-1]==a && (strncmp(P,P+q-k+1,k-1)==0);//此处q>=1,k>=2
}

vector<map<char,int> > Compute_Transition_Function(const char *P, const char *a)    
{
    int m = strlen(P);
    int j =0;
    int k =0;
    vector<map<char,int> > transition_map(m+1);//一定要加参数 

    for(int q=0; q<=m; q++)
    {       
        j =0;
        while(a[j]!='\0')
        {
            k = min(m,q+1);//此处1<=k<=m,k==0时P0==ε 
            while(!Expect_Prefix(P,k,q,a[j]))
            {
                k--;//总是会找到合适的k值，至少k==0符合要求 
            }   
            transition_map[q][a[j]] = k;    
            j++;                
        }
    }

    //for(int i=0;i<transition_map.size();i++){
    //    for(int j=0;j<m;j++){
    //       cout<<"i="<<i<<" j="<<transition_map[i][j]<<endl;
    //  }
    //}

    return transition_map;
} 

void Finite_Automation_Matcher(const char* T, const char* P, const char *a)
{
    int n = strlen(T);
    int m = strlen(P);
    int q = 0;//初始状态为0 
    vector<map<char,int> > transition_map;//状态转移表 

    transition_map = Compute_Transition_Function(P, a);// 构造状态转移表 

    for(int i=0; i<n; i++)
    {
        q = transition_map[q][T[i]];
        if(q==m)
        {
            cout<<"Pattern occurs with shift "<<i-m+1<<endl;
        }
    }
}

int main(int argc, char *argv[])
{
    const int Max_Length = 1000;
    const char * ALPHABET = "abcdefghijklmnopqrstuvwxyz";
    char T[Max_Length];
    char P[Max_Length];

    while(gets(T))
    {
        gets(P);
        Finite_Automation_Matcher(T,P,ALPHABET);
        cout<<"next case:"<<endl;
    }

    system("PAUSE");
    return EXIT_SUCCESS;
}


