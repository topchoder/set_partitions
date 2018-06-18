#include <bits/stdc++.h>
using namespace std;
//this code generates all possible k partitions of an array
vector<vector<vector<int> > > getpart(vector<int> a,int k)
{
	vector<vector<vector<int> > > part;
    if(a.size()<k||k<=0) return part;//if number of elements is less than partitions or number of partitions is less than zero simply return
    if(k==1)//if only one simply copy the array
    {
        vector<vector<int> > tem3;
        tem3.push_back(a);
        part.push_back(tem3);
        return part;
    }
    vector<int> include_part=a;
    include_part.pop_back();
    //including the element in the previous partitons
    vector<vector<vector<int> > > include=getpart(include_part,k);
    for(int i=0;i<include.size();i++)
    {
        for(int j=0;j<include[i].size();j++)
        {
            include[i][j].push_back(a.at(a.size()-1));
            part.push_back(include[i]);
            include[i][j].pop_back();
        }
    }
    vector<int> addpart;
    addpart.push_back(a[a.size()-1]);
    //excluding the element from previous partitions and creating new partition
    vector<vector<vector<int> > > exclude=getpart(include_part,k-1);
    for(int i=0;i<exclude.size();i++)
    {
        vector<vector<int> > tem2=exclude.front();
        tem2.push_back(addpart);
        part.push_back(tem2);
    }
    return part;
}

signed main()
{
	vector<int> a;
	int n=4;
	for(int i=0;i<n;i++)
		a.push_back(i+1);
	int w=2;
	vector<vector<vector<int> > >b=getpart(a,w);
	for(int i=0;i<b.size();i++)
	{
		for(int j=0;j<b[i].size();j++)
		{
            for(int k=0;k<b[i][j].size();k++)
            	cout<<b[i][j][k]<<" ";
            cout<<"\n";
		}
		cout<<"\n\n\n";
	}
	return 0;
}
