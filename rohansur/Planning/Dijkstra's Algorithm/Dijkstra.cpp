#include <iostream>
class node
{
	public:

		int seen;
		int d;
		node *prev;
		char c;
};
/*This code assumes that there are 8 vertices in the graph. To test the code, one may uncomment the sections below
and use the standard example, or give the required inputs.*/
int main()
{
	node a[8];
	int i,j,temp,min,pos;
	char name[]={'A','B','C','D','E','F','G','H'};
	node *current;
	for(i=0;i<8;i++)
	{
		a[i].seen=0;
		a[i].d=10000;
		a[i].c=name[i];
	}

	int mat[8][8];
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			std::cout<<"Enter the cost of the path from "<<name[i]<<" to "<<name[j]<<"."<<std::endl;
			std::cin>>mat[i][j];
			//mat[i][j]=0;
		}
	}
	/*mat[0][1]=20;mat[0][3]=80;mat[0][6]=90;mat[1][5]=10;mat[2][3]=10;mat[2][5]=50;mat[2][7]=20;mat[3][2]=10;mat[3][6]=20;
	mat[4][1]=50;mat[4][6]=30;mat[5][2]=10;mat[5][3]=40;mat[6][0]=20;*/
	a[0].d=0;
	a[0].prev=NULL;
	i=0;
	current=&a[0];
	while(pos!=-1)
	{
		min=10000;pos=-1;
		for(j=1;j<8;j++)
		{
			if(mat[i][j]!=0)
			{
				temp=mat[i][j]+current->d;
				if(temp<a[j].d)
				{
					a[j].d=temp;
					a[j].prev=current;
				}
			}
			if(a[j].d<min&&a[j].seen==0)
			{
				min=a[j].d;
				pos=j;
			}
		}
		i=pos;
		current=&a[pos];
		a[pos].seen=1;
	}

	for(i=1;i<8;i++)
	{
		if(a[i].d==10000)
		{
			std::cout<<"No path exists from A to "<<a[i].c<<"."<<std::endl<<std::endl;
			continue;
		}
		std::cout<<"Shortest path from A to "<<a[i].c<<" :"<<std::endl;
		current=&a[i];
		std::cout<<"Cost of path = "<<current->d<<std::endl;
		std::cout<<"Path taken : "<<std::endl;
		while(current->prev!=NULL)
		{
			std::cout<<current->c<<" -> ";
			current=current->prev;
		}
		std::cout<<current->c<<std::endl;

		std::cout<<std::endl;
	}
}