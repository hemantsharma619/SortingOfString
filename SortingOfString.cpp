#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<string>


 int findCiel(string s,char first,int l,int r)
 {
     int cielIndex=l,i;
     for(i=l+1;i<=r;i++)
     {
         if(s[i]>first&&s[i]<s[cielIndex])
           cielIndex=i;
     }
     return cielIndex;
 }
 void sortedPerm(string s)
 {
     int n=s.length();
     sort(s.begin(),s.end());
     bool isFinished=false;
     while(!isFinished)
     {
         cout<<s<<endl;
         int i;
         for(i=n-2;i>=0;--i)
         {
             if(s[i]<s[i+1])
             break;
         }
         if(i==-1)
         isFinished=true;
         else
         {
             int cielIndex=findCiel(s,s[i],i+1,n-1);
             swap(s[i],s[cielIndex]);
             string ss=s.substr(i+1);
             sort(ss.begin(),ss.end());
             s.replace(i+1,ss.length(),ss);
         }
     }
     
 }
int main()
{
    string s;
    cin>>s;
    sortedPerm(s);
    
    
}