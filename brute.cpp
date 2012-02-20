
#include <iostream>

using namespace std;

int is_valid(int a[][10], int x, int y, int val)
{
	int i, j, sum = 0, p = (x-1)/3, q = (y-1)/3;

	for(i=1; i<10; i++)
	{
		if (a[x][i]== val)
			sum++;
	}

	if (sum!=1)
		return 0;
	
	sum = 0;

	for(i=1; i<10; i++)
	{
		if (a[i][y]== val)
			sum++;
	}

	if (sum!=1)
		return 0;
	
	sum = 0;

	switch(p)
	{
		case 0:	if (q==0)
			{
				for(i=1; i<4; i++)
				{
					for(j=1; j<4; j++)
					{
						if (a[i][j]==val)
							sum++;
					}
				}

				if (sum!=1)
					return 0;
			}

			else if (q==1)
			{
				for(i=1; i<4; i++)
				{
					for(j=4; j<7; j++)
					{
						if (a[i][j]==val)
							sum++;
					}
				}

				if (sum!=1)
					return 0;
			}
			else
			{
				for(i=1; i<4; i++)
				{
					for(j=7; j<10; j++)
					{
						if (a[i][j]==val)
							sum++;
					}
				}
			
				if (sum!=1)
					return 0;
			}

			break;

		case 1:	if (q==0)
			{
				for(i=4; i<7; i++)
				{
					for(j=1; j<4; j++)
					{
						if (a[i][j]==val)
							sum++;
					}
				}

				if (sum!=1)
					return 0;
			}

			else if (q==1)
			{
				for(i=4; i<7; i++)
				{
					for(j=4; j<7; j++)
					{
						if (a[i][j]==val)
							sum++;
					}
				}

				if (sum!=1)
					return 0;
			}
			else
			{
				for(i=4; i<7; i++)
				{
					for(j=7; j<10; j++)
					{
						if (a[i][j]==val)
							sum++;
					}
				}
			
				if (sum!=1)
					return 0;
			}

			break;

		case 2:	if (q==0)
			{
				for(i=7; i<10; i++)
				{
					for(j=1; j<4; j++)
					{
						if (a[i][j]==val)
							sum++;
					}
				}

				if (sum!=1)
					return 0;
			}

			else if (q==1)
			{
				for(i=7; i<10; i++)
				{
					for(j=4; j<7; j++)
					{
						if (a[i][j]==val)
							sum++;
					}
				}

				if (sum!=1)
					return 0;
			}
			else
			{
				for(i=7; i<10; i++)
				{
					for(j=7; j<10; j++)
					{
						if (a[i][j]==val)
							sum++;
					}
				}
			
				if (sum!=1)
					return 0;
			}

			break;
	}

	return 1;
}


void put(int a[][10], int x, int y)
{
	int i, j;

	if (x>9)
	{
		cout<<"done\n";

		for(i=1; i<10; i++)
		{
			for(j=1; j<10; j++)
				cout<<" "<<a[i][j];

			cout<<"\n";
		}
	}

	else if (a[x][y]!=0)
	{
		if (y<9)
			put(a, x, y+1);
		else
			put(a, x+1, 1);
	}

	else
	{
		for(i=1; i<10; i++)
		{	
			a[x][y] = i;
			
			if (is_valid(a, x, y, i))
			{
				if (y<9)
					put(a, x, y+1);
				else
					put(a, x+1, 1);
			}

			a[x][y] = 0;
		}
	}
}
			
				
int main()
{
	int a[10][10], i, j;

	for(i=1; i<10; i++)
	{
		for(j=1; j<10; j++)
			cin>>a[i][j];
	}

	put(a, 1, 1);

}
