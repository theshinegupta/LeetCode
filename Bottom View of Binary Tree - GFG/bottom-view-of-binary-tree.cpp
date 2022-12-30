//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> bottomView(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        map<int,int> mp;
     stack<pair<int,int>> st;
     vector<int> res;
     
     if(root==NULL)
      return res;
      
     queue<pair<int,Node*>> q;
     q.push({0,root});
     st.push({0,root->data});
     q.push({10000000,NULL});
     
     while(!q.empty())
     {
         Node* temp=q.front().second;
         int currIdx=q.front().first;
         q.pop();
         
        //  if(mp.find(currIdx)==mp.end() && temp!=NULL)
        //  {
        //      mp.insert({currIdx,temp->data});
        //  }
        
        if(temp!=NULL)
         st.push({currIdx,temp->data});
         
         if(temp!=NULL)
         {
             if(temp->left!=NULL)
               q.push({currIdx-1,temp->left});
               
             if(temp->right!=NULL)
               q.push({currIdx+1,temp->right});
         }
         else
         {
             
            if(q.empty())
            break;
            q.push({10000000,NULL});
            
         }
           
         
         
     }
     
     while(!st.empty())
     {
        int currIdx=st.top().first;
        int temp=st.top().second;
        
        if(mp.find(currIdx)==mp.end())
         {
             mp.insert({currIdx,temp});
         }
         
         st.pop();
         
     }
     
    for(auto itr=mp.begin();itr!=mp.end();itr++)
    {
        int temp=itr->second;
        res.push_back(temp);
    }
     
     
     return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}



// } Driver Code Ends