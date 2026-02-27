#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <string>
#include <bits/stdc++.h>
#include <functional>
#include <utility>
#include <queue>
#include <fstream>
using namespace std;

map<vector<vector<int> >  ,bool> visited;
map<vector<vector<int> > , vector<vector<int> > > parent;
vector<vector<int> > goal(3,vector<int> (3));
int countt = 1;

bool visit(vector<vector<int> > a)
{
	if(visited[a]==true)
		return true;

	return false;
}
int manhattanDistance (vector<vector<int> > a , int moves)
{
	int dist = moves;
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			if(a[i][j] != 0)
			{
				for (int k=0; k<3; k++)
				{
					for (int l=0; l<3; l++)
					{
						if(a[i][j]==goal[k][l])
							dist+=(i-k)+(j-l);
					}
				}
			}
		}
	}
	return dist;
}

bool isGoal (vector<vector<int> > a){
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(a[i][j] != goal[i][j]) return 0;

		}
	}

	return 1;
}

bool safe(int i,int j)
{
	if(i>=0 && i<=2 && j>=0 && j<=2)
		return true;

	return false;
}


int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};

vector<vector<vector<int> > > neighbours(vector<vector<int> > a)
{
	pair<int,int> pos;
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++){
			if(a[i][j] == 0)
			{
				pos.first=i;
				pos.second=j;
				break;
			 }
		}

	}
	vector<vector<vector<int> > > position;
	for (int k=0; k<4; k++)
	{
		int cx = pos.first;
		int cy = pos.second;
		vector<vector<int> > n = a;
		if(safe(cx+dx[k], cy+dy[k]))
		{
			swap(n[cx+dx[k]][cy+dy[k]], n[cx][cy]);
			position.push_back(n);
		}
	}

	return position;
}

typedef pair<vector<vector<int> > , int> state;

struct operator_overload
{
	bool operator() (state &a, state &b)
	{
		int x = manhattanDistance(a.first,a.second);
		int y = manhattanDistance(b.first,b.second);
		return x<y;
	}
};

void print_path(vector<vector<int> > s, int moves)
{

	if(parent.count(s))
	print_path(parent[s],moves);

   // printf("\n");
    printf("Step #%d\n",countt);
    countt++;
    for(int i=0;i<3;i++)
    {
 	  for(int j=0;j<3;j++)
	  {
		 printf("%d ",s[i][j]);
	  }

	 cout<<endl;
/*Initial:
X 7 2
1 6 3
4 5 8

Goal:
X 1 2
3 4 5
6 7 8
*/
    }

   cout<<endl;

 return;
}

void solve(vector<vector<int> > a, int moves)
{
    priority_queue<state, vector<state>, operator_overload> pq;
	pq.push(state(a,moves));
	while(!pq.empty())
	{
		vector<vector<int> > v = pq.top().first;
		pq.pop();
		visited[v]=true;
		if(v==goal)
		{
			print_path(v,moves);
			break;
		}
		vector<vector<vector<int> > > ns = neighbours(v);
		vector<vector<vector<int> > >::iterator it;
		for(it=ns.begin();it!=ns.end();it++)
		{
			vector<vector<int> > temp = *it;
			if(!visit(temp))
			{
				parent.insert(pair<vector<vector<int> > , vector<vector<int> > >(temp,v));
				pq.push(state(temp,moves+1));
			}
		}
	}
	return;
}

int main()
{
	cout<<"Initial \n";
	vector<vector<int> > a(3,vector<int> (3));
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"Goal \n";
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>goal[i][j];
		}
	}
	solve(a,0);

}


