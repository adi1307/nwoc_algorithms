//Combination computation by Euler method
//Language Used: C++
//Combination calculation of large numbers is difficult
//Euler method performs well with large numbers
//Output: This algorithm will give the nCr value of two numbers
// Sample Input:
// N = 5   R = 3
// Sample Output:
// The value of nCr for numbers 5 and 3 is 10

//author:Aditya Kothari


#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000007

long long f[100001];

ll pow(ll val_1, ll val_2, ll MOD)
{
 ll x=1,y=val_1;
 while(val_2 > 0)
 	{
 		if(val_2%2 == 1)
 	{
 		x=(x*y);
 		if(x>MOD) x%=MOD;
 	}
 	y = (y*y);
 	if(y>MOD) y%=MOD;
 	val_2 /= 2;
 	}
 return x;
}
/* Modular Multiplicative Inverse
 Using Euler's Theorem
 a^(phi(m)) = 1 (mod m)
 a^(-1) = a^(m-2) (mod m) */
ll InverseEuler(ll obj, ll MOD)
{
 return pow(obj,MOD-2,MOD);
}

ll C(ll obj, ll sam, ll MOD)
{

 return (f[obj]*((InverseEuler(f[sam], MOD) * InverseEuler(f[obj-sam], MOD)) % MOD)) % MOD;
}

void main(){
	f[0] = 1;
	for(int i = 1 ; i <= 100000 ; i++)
		f[i] = (f[i-1]*i)%INF;
    ll objects,sample,answer;
    cout<<"Enter the number of Objects(n)\n";
    cin>>objects;
    cout<<"Enter the number of Sample(r)\n";
    cin>>sample;
 	answer=C(objects,sample,INF);
 	cout<<"The value of Combination(nCr) for numbers "<<objects<<" and "<<sample<<" is "<<answer<<"\n";
}
