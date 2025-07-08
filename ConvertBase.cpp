// 111111  1111  11    11  1111  111111 1111  111111  
//   11   11  11  11  11  11  11   11    11   11      
//   11  11    11   11   11    11  11    11   111111  
//   11   11  11  11  11  11  11   11    11       11  
//   11    1111  11    11  1111    11   1111  111111  

/*##### Submission By - Saumy Tiwari #####*/

/*################ Macros ################*/

#include <bits/stdc++.h>
#include "MyLib.h"
using namespace std;
using ll = long long;
ll I, i, j, k, l, a, b, c, x, y;
#define ll_MAX LLONG_MAX
#define ll_MIN LLONG_MIN
#define f1(I,t,b) for((I) = (0);(I) < (t);(I)+=(b))
#define f2(I,a,t,b) for((I) = (a);(I) < (t);(I)+=(b))
#define d_ll(n) ll n;cin>>n;
#define d_string(s) string s;cin>>s;
#define d_float(n) float n;cin>>n;
#define d_double(n) double n;cin>>n;
#define d_llArray(a,n) ll a[n];f1(i,n,1){cin>>a[i];}
#define d_floatArray(a,n) float a[n];f1(i,n,1){cin>>a[i];}
#define d_doubleArray(a,n) double a[n];f1(i,n,1){cin>>a[i];}
#define Fast_IO ios_base::sync_with_stdio(false);cin.tie(0);//fast input and output

/*########### Extra Functions ###########*/

string convertBase(string number, int baseA, int baseB)
{

  if (baseA < 2 || baseB < 2 || baseA > 36 || baseB > 36)
  {
    return "Invalid base (must be between 2 and 36)";
  }

  long long decimal = 0;
  int power = 1;
  for (int i = number.length() - 1; i >= 0; i--)
  {
    char digit = number[i];
    int value;
    if (isdigit(digit))
    {
      value = digit - '0';
    }
    else 
    {
      value = toupper(digit) - 'A' + 10;
    }
    if (value >= baseA)
    {
      return "Invalid number for base " + to_string(baseA);
    }
    decimal += value * power;
    power *= baseA;
  }

  string result;
  if (decimal == 0)
  {
    result = "0";
  }
  else
  {
    while (decimal > 0)
    {
      int remainder = decimal % baseB;
      char digit;
      if (remainder < 10)
      {
        digit = remainder + '0';
      }
      else
      {
        digit = remainder - 10 + 'A';
      }
      result = digit + result;
      decimal /= baseB;
    }
  }
  return result;
}

/*################ Code #################*/

int main()
{
    Fast_IO
    cout<<convertBase("SAUMY",35,10)<<endl;
}