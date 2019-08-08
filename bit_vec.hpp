#include <math.h>
#include <algorithm>
using namespace std;
class bit_vec{
    string bins(int a,int len)
    {
        string maps="01";
        string r="";
        for (;a!=0;a=a/2)  
        {
            r=maps[a%2]+r;
        }
        while (r.size()!=len)
            {r='0'+r;}
    return r;
    }
    public :
    int size;char len;
    unsigned char *arr;
    bit_vec(int *p,int siz)
    {
        int h=0;
        for (int c(0);c<siz;c++)
        {
            h=max(h,*(p+c));
        }
        len=(unsigned char)((int)log2(h)+1);
        size=ceil(len*siz/8.0);
    arr=new unsigned char [size];
    for (int c(0);c<size;c++)arr[c]=0;
    int j=0;
    for (int c(0);c<siz;c++)
    {
        string rr=bins(*(p+c),len);
        for (int c1(0);c1<rr.size();c1++,j++)
        {
            arr[j/8]=(arr[j/8]|((rr[c1]-'0')<<(7-j%8)));
        
        }

    }

    }
    int size_in_bytes()
    {
        return size+5;
    }

    int ret(int i)
    {
        int res=0;
        for (int c(len*i);c<=len*i+len-1;c++)
        {
            res=res*2+((arr[c/8]&(1<<(7-c%8)))!=0);
        
        }
        return res;
    }
};