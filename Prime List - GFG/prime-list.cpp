//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
bool seive[20005];
    Node *primeList(Node *head){
        memset(seive,true,sizeof(seive));
        for(int i=2;i<20005;i++)
        {
            int temp=i;
            if(seive[i])
              {
                  for(int j=i+i;j<20005;j=j+i)
                     seive[j]=false;
              }
        }
        
        Node* ptr=head;
        while(ptr!=NULL)
        {
            int temp=ptr->val;
            if(temp==1)
                {
                    ptr->val=2;
                    ptr=ptr->next;
                    continue;
                }
            if(!seive[temp])
             {
                 int dis=1;
                while(true)
                {
                    if(seive[temp-dis]==true)
                    {
                        ptr->val=temp-dis;
                        break;
                    }    
                    if(seive[temp+dis]==true)
                    {
                        ptr->val=temp+dis;
                        break;
                    }
                    dis++;
                }
            
                
                
            }
            ptr=ptr->next;
            
        }
        return head;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends