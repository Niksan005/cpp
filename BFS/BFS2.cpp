#include <iostream>
using namespace std;
int mp[100][100], n;
int X,Y;

void print()
{
    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < n; x++)
        {
            cout<<mp[x][y]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}
void BFS(int k, int d)
{
    print();
    for(int y=0; y < n; y++)
    {
        for(int x=0; x < n; x++)
        {

            if( x==X && y==Y && mp[x][y]==k-1 && k-1!=0)
            {
                cout<<mp[X][Y]-1;
                return;
            }
            if(y>0  && mp[x][y]==k && mp[x][y-1]==0)
            {
                mp[x][y-1] = k+1;
            }
            if(y<n  && mp[x][y]==k && mp[x][y+1]==0)
            {
                mp[x][y+1] = k+1;
            }
            if(x>0  && mp[x][y]==k && mp[x-1][y]==0)
            {
                mp[x-1][y] = k+1;
            }
            if(x<n && mp[x][y]==k && mp[x+1][y]==0)
            {
                mp[x+1][y] = k+1;
            }
        }
    }
    BFS(k+1, d+1);
}
int main()
{
    cin>>n;
    char mp2[100][100];
    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < n; x++)
        {
            cin>>mp2[x][y];
            if(mp2[x][y]=='(')
            {
                mp[x][y] = 1;
            }
            else
            {
                mp[x][y] = 0;
            }
            if(mp2[x][y]==')')
            {
                X=x;
                Y=y;
            }
        }
    }
    BFS( 1, 0);
    return 0;
}
