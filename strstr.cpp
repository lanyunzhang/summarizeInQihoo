#include<cstring>
#include<cstdio>

/* implement strstr */

class Solution {
public:
    // build the next array
    void getNext(char* pattern,int* next){

       next[0] = -1;
       int j = 0;
       int k = -1;

       while(j<strlen(pattern)){
            if(k == -1 || pattern[j] == pattern[k]){
                ++j;
                ++k;
                next[j] = k;
            }else{
                k = next[k];
            }
       }
    }
    // first occurrence needle in haystack
    // haystack="",needle=""
    char *strStr(char *haystack, char *needle) {
         int len_hay = strlen(haystack);
         int len_need= strlen(needle);
	 if( len_hay == 0 && len_need == 0) return "";
	 if( len_hay != 0 && len_need == 0) return haystack;
         if( len_hay <  len_need ) return NULL;

         int* arr = new int[len_need + 1 ];
         getNext(needle,arr);
         
         int hay_pos = 0;
         int ned_pos = 0;

         while(hay_pos < len_hay){
            if( ned_pos == -1 || haystack[hay_pos] == needle[ned_pos]){
                ++hay_pos;
                ++ned_pos;
            }else{
                ned_pos = arr[ned_pos];
            }

            if( ned_pos == len_need ) return haystack + hay_pos - ned_pos;
            
         }
         return NULL;
    }
    
};
