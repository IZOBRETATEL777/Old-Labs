#include <iostream>
#include <iostream>
using namespace std;
//Bulbbasaur
int main()
{
  string str;
  int B=0,
  u=0,
  l=0,
  b=0,
  a=0,
  s=0,
  r=0,
  w=0;
  cin>>str;
  for (int i=0; i<str.size(); i++)
  {
    if (str[i]=='B')
      B++;
    if (str[i]=='u')
      u++;
      if (str[i]=='l')
        l++;
        if (str[i]=='b')
          b++;
          if (str[i]=='a')
            a++;
            if (str[i]=='s')
              s++;
              if (str[i]=='r')
                r++;

  }
  while(B!=0&&u!=0&&l!=0&&b!=0&&a!=0&&s!=0&&r!=0)
  {
    w++;

    B-=1;  u-=2;  l-=1;  b-=2;  a-=2;  s-=1;  r-=1;
  }
  cout<<w<<endl;
  return 0;
}
