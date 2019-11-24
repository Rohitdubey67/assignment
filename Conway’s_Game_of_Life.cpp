#include <bits/stdc++.h>
using namespace std;
struct s
{
  // c is used  for storing the character at the location
  char c;
  // p is used for storing the status of the location (either on or off)
  bool p;
  //k is used to store the count of neighbours af the any location
  int k;
};
int main()
{
	int n,m,i,j;
    //taking size of grid in form of rows(n) and Columns(m)
	cin>>n>>m;
	s a[n+2][m+2];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>a[i][j].c;
			//here # is used for occupied location
			if(a[i][j].c=='#')
			a[i][j].p=1;
			else
			a[i][j].p=0;
			a[i][j].k=0;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
            //if at any location element is present than update value of k for all neighbours of this element
			if(a[i][j].p==1)
			{
				a[i-1][j].k++;
				a[i][j-1].k++;
				a[i-1][j-1].k++;
				a[i+1][j].k++;
				a[i+1][j-1].k++;
				a[i+1][j+1].k++;
				a[i][j+1].k++;
				a[i-1][j+1].k++;
			}
		}
	}	
	
/*	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
		cout<<a[i][j].k<<" ";	
		}
		cout<<endl;
	}     */

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			//location that has zero or one neighbor will be empty in the next generation
			if(a[i][j].k==1||a[i][j].k==0)
			{
				a[i][j].c='.';
				a[i][j].p=0;
				a[i][j].k=0;
			}
		
		   //location with two neighbors is stable
			else if(a[i][j].k==2)
			{
				a[i][j].c=a[i][j].c;
				a[i][j].p=a[i][j].p;
				a[i][j].k=0;
			}
			//location with three neighbors will contain a cell in the next generation
			else if(a[i][j].k==3)
			{
			    a[i][j].c='#';
			    a[i][j].p=1;
			    a[i][j].k=0;
			
			}
			//location with four or more neighbors will be empty in the next generation
			else if(a[i][j].k>=4)
			{
			a[i][j].c='.';
			a[i][j].p=0;
			a[i][j].k=0;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
	 for(j=1;j<=m;j++)
	 {
			cout<<a[i][j].c;
	 }
	 cout<<endl;
 }
}
