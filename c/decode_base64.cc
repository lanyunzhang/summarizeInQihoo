#include<stdio.h>
#include<string.h>
#include<map>

#define TABLE_SIZE 64

/** base64 encode and decode */

/** store by map */

char table[]={
    'A','B','C','D','E','F','G','H',
    'I','J','K','L','M','N','O','P',
    'Q','R','S','T','U','V','W','X',
    'Y','Z','a','b','c','d','e','f',
    'g','h','i','j','k','l','m','n',
    'o','p','q','r','s','t','u','v',
    'w','x','y','z','0','1','2','3',
    '4','5','6','7','8','9','+','/',
};

char bit[] ={
    0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01,
};

char bit_six[] = {
    0x20,0x10,0x08,0x04,0x02,0x01,
};

int getdv(const char* msg , int spos,int len){
    
    std::map<char,int> mtable;
    for(int i=0;i<TABLE_SIZE;i++){
        mtable[table[i]] = i;
    }
    int pos = spos;
    int byte_num = 0;
    int bit_num_in_byte = 0;
    int res = 0;
    for(pos = spos;pos<spos+len;pos++){
        byte_num = pos / 6;
        bit_num_in_byte = pos % 6;

        int value = mtable[msg[byte_num]];
        if(value & bit_six[bit_num_in_byte]){
           res = res + 1; 
        }
        if( (pos + 1) != (spos + len) ) res = res << 1;
    }
    return res;
}

char* decode(const char* msg){

    int len = strlen(msg);
    int size = len*6/8;
    int pos = 0;
    char* buf = new char[size+1];
    for(pos = 0;pos<size;pos++){
        int res = getdv(msg,pos*8,8);
        buf[pos] = (char)res;
    }
    return buf;
}

int getValue(const char* msg,int spos,int len){

    int pos = spos; 
    int byte_num = 0;
    int bit_num_in_byte = 0;
    int res = 0;
    for( pos = spos;pos <spos+len;pos++){
        byte_num = pos / 8;
        bit_num_in_byte = pos % 8;
          
        char c = msg[byte_num];
        if(c & bit[bit_num_in_byte]){
            res += 1;
        }
        if( (pos + 1) != (spos + len)) res = res << 1;
    }
    return res;
}

char* encode(const char* msg){
    int bpos =0;
    int mlen = strlen(msg);
    int bit_mlen = mlen*sizeof(char)*8;
    int size = mlen*8/6 + 1;
    char* buf = new char[size];
    int pos = 0; 
    while(bpos < bit_mlen){
        int idx = getValue(msg,bpos,6);
        buf[pos++] = table[idx];
        bpos += 6;
    }
    return buf;    
}

int main(){
   char* ems = encode("BC");
   char* msg = decode("QkM");
   printf("%s\n",ems);
   printf("%s\n",msg);
   return 0;
}


