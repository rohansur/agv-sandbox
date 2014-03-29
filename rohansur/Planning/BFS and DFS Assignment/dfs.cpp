#include <iostream>
#include <stack>


using namespace std;
class node
{
	public:
		int x;
		int y;

	node(int a,int b)
	{
		x=a;
		y=b;
	}
};

static int k=1;
void dfs(int a[5][10],node s)
{
	a[s.x][s.y]=k++;
	int dx[]={1,1,0,0,-1,-1,1,-1};
    int dy[]={0,1,1,-1,1,0,-1,-1};
    int i;

    for(i=1;i<8;i++)
    {
    	int newx=s.x+dx[i];
    	int newy=s.y+dy[i];
    	if(a[newx][newy]==-1)
    		dfs(a,node(newx,newy));
    }

}

int main()
{
	int a[5][10];
	int i,j;

	for(i=0;i<5;i++)
	{
		for(j=0;j<10;j++)
		{
			a[i][j]=-1;
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}

	dfs(a,node(0,0));

	for(i=0;i<5;i++)
	{

		for(j=0;j<10;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}

	cout<<"No. of elements = 50"<<endl;
	cout<<"No. of nodes traversed = "<<k-1<<endl;

}