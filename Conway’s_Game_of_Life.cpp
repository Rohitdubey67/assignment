#include <bits/stdc++.h>
using namespace std;

class Location
{
	public:
	
  // c is used  for storing the character at the location (either '#' or '.')
  char c;
  // p is used for storing the status of the location (either on or off)
  bool p;
  //k is used to store the count of neighbours af the any location
  int k;
  
  void get_c(char x)
  {
     c=x;
  }
  char put_c()
  {
  	return c;
  }
  void get_p(bool x)
  {
     p=x;
  }
  bool put_p()
  {
  	return p;
  }
  void get_k(int x)
  {
     k=x;
  }
  int put_k()
  {
  	return k;
  }
};

int main()
{
	int n,m,i,j;
    //taking size of grid in form of rows(n) and Columns(m)
	cin>>n>>m;
	// matrix a used to show current genration.
	// matrix b used to show next genration.
	Location a[n+2][m+2],b[n+2][m+2];

	for(i=0;i<=n+1;i++)
	{
		for(j=0;j<=m+1;j++)
		{
			if(i==0||j==0||i==n+1||j==m+1)
			{
				a[i][j].get_c('.');
				a[i][j].get_p(0);
				a[i][j].get_k(0);
			}
			else
			{
			char x;
			cin>>x;
			if(x=='#')
			{
			a[i][j].get_c('#');
			a[i][j].get_p(1);
			a[i][j].get_k(0);
			}
			else
			{
			    a[i][j].get_c('.');
			a[i][j].get_p(0);
			a[i][j].get_k(0);
			}
			}
		}
	}
  
  //counting neighbours..
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
	
	// genrating next genration matrix..
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			//location that has zero or one neighbor will be empty in the next generation
			if(a[i][j].k==1||a[i][j].k==0)
			{
				b[i][j].c='.';
				b[i][j].p=0;
				b[i][j].k=0;
			}
		
		   //location with two neighbors is stable
			else if(a[i][j].k==2)
			{
				b[i][j].c=a[i][j].c;
				b[i][j].p=a[i][j].p;
				b[i][j].k=0;
			}
			//location with three neighbors will contain a cell in the next generation
			else if(a[i][j].k==3)
			{
			    b[i][j].c='#';
			    b[i][j].p=1;
			    b[i][j].k=0;
			
			}
			//location with four or more neighbors will be empty in the next generation
			else if(a[i][j].k>=4)
			{
			b[i][j].c='.';
			b[i][j].p=0;
			b[i][j].k=0;
			}
		}
		}
		cout<<"Present genration population map:"<<endl;
		for(i=1;i<=n;i++)
		{
		    for(j=1;j<=m;j++)
		    cout<<a[i][j].c;
		    cout<<endl;
		}
		cout<<endl;
		cout<<"Next genration population map:"<<endl;
		for(i=1;i<=n;i++)
		{
		    for(j=1;j<=m;j++)
		    cout<<b[i][j].c;
		    cout<<endl;
		}
		cout<<endl;
		/* . unit testing .*/
		
		//unit test -1: if at any location count of neighbors is less then zero or more than 8 report an error...
		if(a[i][j].k<0&&a[i][j].k>8)
		cout<<"Error found";
		
		//unit test -2:
		if(a[i][j].k==0&&b[i][j].c=='#')
		cout<<"Error found";
		
		//unit test -3:
		if(a[i][j].k==1&&b[i][j].c=='#')
		cout<<"Error found";
		
		//unit test -4:
		if(a[i][j].k==2&&a[i][j].c!=b[i][j].c)
		cout<<"Error foound";
		
		//unit test -5:
		if(a[i][j].k==3&&b[i][j].c!='#')
		cout<<"Error found";
		
		//unit test -6:
		if(a[i][j].k==4&&b[i][j].c=='#')
		cout<<"Error found";
		
		//unit test -7:
		if(a[i][j].k>4&&b[i][j].c=='#')
		cout<<"Error found";
	}
