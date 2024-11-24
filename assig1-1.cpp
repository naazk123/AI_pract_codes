#include <iostream>
using namespace std;

class Queue{
    public:
        int front,rear,size;
        int *arr;

        Queue(int n){
            front=rear=-1;
            size=n;
            arr=new int[size];
        }

        ~Queue(){
            delete[] arr;
        }

        bool isFull()
        {
            if(rear==size-1)
                return 1;
            else
                return 0;
        }

        bool isEmpty()
        {
            if(front==-1)
                return 1;
            else    
                return 0;
        }

        void Enqueue(int a)
        {
            if(isFull())
                cout<<"Queue is full!!!"<<endl;
            else{
                if(front==-1 && rear==-1)
                    front=rear=0;
                else{
                    rear++;
                }
                arr[rear]=a;
            }
        }

        int Dequeue()
        {
            int a;
            if(isEmpty())
                cout<<"Queue is empty!!!"<<endl;
            else{
                a=arr[front];
                if(rear==0)
                {
                    
                    rear=front=-1;
                }
                else{
                    front++;
                }
                return a;
            }
        }
};

int main()
{
    int n;
    cout<<"Enter number of nodes"<<endl;
    cin>>n;
    int graph[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            graph[i][j]=0;
        
    }
   
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<graph[i][j];
        cout<<endl;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"Are nodes "<<i<<" and "<<j<<" connected?(Yes-->1/ No-->0)"<<endl;
            cin>>graph[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<graph[i][j];
        cout<<endl;
    }

    Queue q1(n);
    int visited[n]={0};
    int source, dest;
    cout<<"Enter source node"<<endl;
    cin>>source;
    cout<<"Enter destination node"<<endl;
    cin>>dest;
    q1.Enqueue(source);
    while(!q1.isEmpty()){
        int a=q1.Dequeue();
        visited[a]=1;
        cout<<a<<" ";
        if(a==dest)
            break;
        else{
            for(int i=0;i<n;i++)
            {
                if(graph[a][i]==1 && visited[i]==0)
                        q1.Enqueue(i);
            }
        }
    }

    int branch[n];
    for(int i=0;i<n;i++)
    {
        int a=0;
        for(int j=0;j<n;j++)
        {
            if(graph[i][j]==1 && i<j)
            {
                a++;
            }
        }
        branch[i]=a;
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<branch[i]<<" ";
    }

    int depth[n];
    depth[0]=0;
    for(int i=1;i<n;i++)
    {
        // for(int j=0;j<n;j++)
        {
            if(graph[i][0]==1)
                depth[i]=1;
            else
                depth[i]=99;
        }
    }

    for(int i=1;i<n;i++)
    {
        int a;
        if(depth[i]<99)
           a=i;
        for(int j=1;j<n;j++)
        {
            if(graph[j][a]==1 && j>i)
                depth[j]=depth[a]+1;
        }
        
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<depth[i]<<" ";
    }

}