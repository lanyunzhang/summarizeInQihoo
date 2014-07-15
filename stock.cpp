/** at most sell two times. */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
      	int size = prices.size();
	if(size == 0) return 0;
	int start_pos = 0;
	int end_pos = 0;
	priority_queue<int> incr;
	for(vector<int>::iterator it = prices.begin()+1; it != prices.end(); it++){
		if( *it >= *(it - 1) ){
		    end_pos++;	
		}else{
		    incr.push(prices[end_pos] - prices[start_pos]);
	            end_pos += 1;
		    start_pos = end_pos;
		} 
	}  
	if(start_pos != end_pos) incr.push(prices[end_pos] - prices[start_pos]);
	if(incr.size() == 0) return 0;
	if(incr.size() == 1) return incr.top();
	else{
		int max1 = incr.top();
		incr.pop();
		int max2 = incr.top();
		return max1 + max2;
	}
	
		
    }
};

int main(){
	Solution s;
	int a[10] = { 5,3,9,7,8,3,2,4,9 };
	int b[10] = { 1,2,3,4,5,6,7,8,9 };
	int c[10] = { 9,8,7,6,5,4,3,2,1 };
	vector<int> v(a,a+9);
	cout<<s.maxProfit(v)<<endl;
	vector<int> vb(b,b+9);
	cout<<s.maxProfit(vb)<<endl;
	vector<int> vc(c,c+9);
	cout<<s.maxProfit(vc)<<endl;
}


/** 1 2 4 2 5 7 2 4 9 0 */
/** save startList and stopList , construct n  time */
