## number number number

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 0    Accepted Submission(s): 0


### Problem Description
* We define a sequence F:

* F0=0,F1=1;
* Fn=Fn?1+Fn?2 (n¡Ý2).

* Give you an integer k, if a positive number n can be expressed by
* n=Fa1+Fa2+...+Fak where 0¡Üa1¡Üa2¡Ü?¡Üak, this positive number is mjf?good. Otherwise, this positive number is mjf?bad.
* Now, give you an integer k, you task is to find the minimal positive mjf?bad number.
* The answer may be too large. Please print the answer modulo 998244353.
 

### Input
* There are about 500 test cases, end up with EOF.
* Each test case includes an integer k which is described above. (1¡Ük¡Ü109)
 

### Output
* For each case, output the minimal mjf?bad number mod 998244353.
 

### Sample Input
```
1
```` 

### Sample Output
```
4
```

```c++

#include <iostream>
#include<cstdio>

using namespace std;

long long c[2][2] = {{1,0},{0,1}};
long long a[2][2]={0,1,1,1},b[2][2];

int main()
{
    int k;

        while(~scanf("%d", &k)){


        k=2+2*k;

        c[0][0]=1;
        c[0][1]=0;
        c[1][0]=0;
        c[1][1]=1;

        a[0][0]=1;
        a[0][1]=1;
        a[1][0]=1;
        a[1][1]=0;

        while(k>0)
        {
            if(k%2==1)
            {
                b[0][0]=(c[0][0]*a[0][0]+c[0][1]*a[1][0])%998244353;
                b[0][1]=(c[0][0]*a[0][1]+c[0][1]*a[1][1])%998244353;
                b[1][0]=(c[1][0]*a[0][0]+c[1][1]*a[1][0])%998244353;
                b[1][1]=(c[1][0]*a[0][1]+c[1][1]*a[1][1])%998244353;

                c[0][0]=b[0][0];
                c[0][1]=b[0][1];
                c[1][0]=b[1][0];
                c[1][1]=b[1][1];

            }

            b[0][0]=(a[0][0]*a[0][0]+a[0][1]*a[1][0])%998244353;
            b[0][1]=(a[0][0]*a[0][1]+a[0][1]*a[1][1])%998244353;
            b[1][0]=(a[1][0]*a[0][0]+a[1][1]*a[1][0])%998244353;
            b[1][1]=(a[1][0]*a[0][1]+a[1][1]*a[1][1])%998244353;

            a[0][0]=b[0][0];
            a[0][1]=b[0][1];
            a[1][0]=b[1][0];
            a[1][1]=b[1][1];

            k=k/2;

        }

        cout<<(c[0][0]-1)%998244353<<endl;
    }


    return 0;
}


```

