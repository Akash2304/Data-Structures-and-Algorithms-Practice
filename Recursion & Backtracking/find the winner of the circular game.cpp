/*********************************************************************************************************************************************************************
There are n friends that are playing a game. The friends are sitting in a circle and are numbered from 1 to n in clockwise order. More formally,
moving clockwise from the ith friend brings you to the (i+1)th friend for 1 <= i < n, and moving clockwise from the nth friend brings you to the 1st friend.

The rules of the game are as follows:

Start at the 1st friend.
Count the next k friends in the clockwise direction including the friend you started at. The counting wraps around the circle and may count some
friends more than once.
The last friend you counted leaves the circle and loses the game.
If there is still more than one friend in the circle, go back to step 2 starting from the friend immediately clockwise of the friend who just lost and repeat.
Else, the last friend in the circle wins the game.
Given the number of friends, n, and an integer k, return the winner of the game.

 

Example 1:


Input: n = 5, k = 2
Output: 3
Explanation: Here are the steps of the game:
1) Start at friend 1.
2) Count 2 friends clockwise, which are friends 1 and 2.
3) Friend 2 leaves the circle. Next start is friend 3.
4) Count 2 friends clockwise, which are friends 3 and 4.
5) Friend 4 leaves the circle. Next start is friend 5.
6) Count 2 friends clockwise, which are friends 5 and 1.
7) Friend 1 leaves the circle. Next start is friend 3.
8) Count 2 friends clockwise, which are friends 3 and 5.
9) Friend 5 leaves the circle. Only friend 3 is left, so they are the winner.
Example 2:

Input: n = 6, k = 5
Output: 1
Explanation: The friends leave in this order: 5, 4, 6, 2, 3. The winner is friend 1.
 

Constraints:

1 <= k <= n <= 500
 

Follow up:

Could you solve this problem in linear time with constant space?
*******************************************************************************************************************************************************************/

class Solution {
public:

void solve(int index,vector<int>v,int k,int &ans){
       
       if(v.size()==1)
       {
           ans=v[0];
           return ;
       }

       index=(index+k)%v.size();

       v.erase(v.begin()+index);

       solve(index,v,k,ans);
       

}
    int findTheWinner(int n, int k) {

        vector<int>v;

        for(int i=1;i<=n;i++)
        v.push_back(i);

        k=k-1;

        int index=0;
        int ans=-1;

        solve(index,v,k,ans);
        return ans;
        
    }
};

/*****************************************************************************************************************************************************************/

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        while(q.size()!=1){
            int x=k;
            while(x>1){
                int r=q.front();
                q.pop();
                q.push(r);
                x--;
            }
            q.pop();
        }
        return q.front();
    }
};

/****************************************************************************************************************************************************************/
class Solution {
public:
    int helper(ListNode *head,int k){
        ListNode *temp=head;  //For traversing through the List and delete every kth Node 
        while(head->next!=head){   //Till the last Node remains in the list i.e. the winner
            ListNode *pre=NULL;
            for(int i=1; i<k; i++){
                pre=temp;
                temp=temp->next;
            }
            //Deletion procedure
            if(temp==head)
                head=head->next;
            pre->next=temp->next;
            delete(temp);
            temp=pre->next;
        }
        //The last node remaining becomes the head of the Circular Linked List i.e. Winner
        return head->val;
    }
    int findTheWinner(int n, int k) {
        if(k==1)
            return n;
        //Designing Circular Linked List for Node 1,2,3,4,.....,n
        ListNode *head=NULL,*tail=NULL;
        for(int i=1; i<=n; i++){
            ListNode *node=new ListNode(i);
            if(head==NULL)
                head=tail=node;
            else{
                tail->next=node;
                tail=node;
            }
            tail->next=head;
        }
        //Helper function will eliminate the nodes and give us the winner
        return helper(head,k);
    }
};

/***************************************************************************************************************************************************************/

class Solution {
public:
    int helper(int n,int k){
        if(n==1)
            return 0;
        return (helper(n-1,k) + k) % n;
    }
    int findTheWinner(int n, int k) {
        return helper(n,k)+1;   //+1 is for converting 0-based indexing to 1-based indexing
    }
};

/*************************************************************************************************************************************************************/

***CONSTANT SPACE SOLUTION***

class Solution {
public:
    int helper(int n,int k){
        int ans = 0;
        for(int i=1; i<=n; i++){
            ans = (ans + k) % i;
        }
        return ans;
    }
    int findTheWinner(int n, int k) {
        return helper(n,k)+1;   //+1 is for conterting 0-based indexing to 1-based indexing
    }
};

