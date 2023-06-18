#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* mergeTwoSorted(Node* &left,Node* &right){
    if(left == NULL){
        return left;
    }
    if(right == NULL){
        return right;
    }
    Node* temp = new Node(-1);
    Node* mergedSorted = temp;

    while(left != NULL && right != NULL){
        if(left->data <= right->data){
            mergedSorted->next = left;
            mergedSorted = left;
            left = left->next;
        }else{
            mergedSorted->next = right;
            mergedSorted = right;
            right = right->next;
        }
    }

    if(left){
        mergedSorted->next = left;  
    }
    if(right){
        mergedSorted->next = right;
    }
    Node* newNode = temp->next;
    delete temp;
    return newNode;
}

    //🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟
//GO to leetcode :-> 2️⃣ Clone a Linked List with Random Pointer

// 👉 Method 1: Time:- O(n), space:- O(n)
// class Solution {
// public:
//     Node* helper(Node* &head, unordered_map<Node*, Node*> &mp){
//         if(head == 0) return 0;
//         Node* newHead = new Node(head->val);
//         mp[head] = newHead;
//         newHead->next = helper(head->next,mp);
//         if(head->random){
//             newHead->random = mp[head->random];
//         }
//         return newHead;
//     }
//     Node* copyRandomList(Node* head) {
        
//         unordered_map<Node*, Node*>mp;
//         return helper(head,mp);

//     }
// };

//GO to leetcode :-> 2️⃣ Clone a Linked List with Random Pointer
// 👉 Method 2:Time:- O(n), space:- O(1) 
//  Node* copyRandomList(Node* head) {
        

//         if(!head) return 0;

//         // Step 1: clone A-> A'
//         Node* it = head; //iterate over old head

//          while(it){
//             //  create clone node
//             Node* clonedNode = new Node(it->val);
//             clonedNode->next = it->next;
//             it->next = clonedNode;
//             it = it->next->next;
//          }

//         //  Step 2: Assign random links of A' with the helper of old node
//         it = head;
//         while(it){
//             Node* clonedNode = it->next;
//             clonedNode->random = it->random ? it->random->next : nullptr;
//             it = it->next->next;
//         }

//         // Step 3: Detach A' from A.
//         it = head;
//         Node* clonedHead = it->next;

//         while(it){
//             Node* clonedNode = it->next;
//             it->next = it->next->next;
//             if(clonedNode->next){
//                 clonedNode->next = clonedNode->next->next;
//             }
//             it = it->next;
//         }

//         return clonedHead;


//     }

//🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* sortList(Node* &head){
    if(head == NULL){
        return head;
    }
    if(head->next == NULL){
        return head;
    }
    // find the mid
    Node* mid = findMid(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    Node* sortedLeft = sortList(left);
    Node* sortedRight = sortList(right);

    return mergeTwoSorted(sortedLeft,sortedRight);

}

//🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟
// 4️⃣ Flatten a Linked List


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/
// Node* merge(Node* left, Node* right){
//     if(left == NULL){
//         return right;
//     }
//     if(right == NULL){
//         return left;
//     }
    
//     Node* ans = 0;
//     if(left->data < right->data){
//         ans = left;
//         left->bottom = merge(left->bottom,right);
//     }else{
//         ans = right;
//         right->bottom = merge(left,right->bottom);
//     }
//     return ans;
// }

// /*  Function which returns the  root of 
//     the flattened linked list. */
// Node *flatten(Node *root)
// {
//    // Your code here
//    if(!root) return 0;
//    Node* mergedLL = merge(root, flatten(root->next) );
//    return mergedLL;
// }

int findLength(Node* &head){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

//🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟
// 5️⃣ Print kth node from end of Linked List

int findEndOfK(Node* &head,int k){
    if(head == NULL){
        return -1;
    }
    int len = findLength(head);
    int position = len - k;
     if(position < 0){
        return -1;
    }
    Node* temp = head;
    for(int i=1;i<position;i++){
        temp = temp->next;
    }
    return temp->data;
}

//👉METHOD #2 RECURSIVE 5️⃣ Print kth node from end of Linked List

void recusiveFun(Node* &head,int &positionEndTail,int &ans){
    if(head == NULL){
        return;
    }
    recusiveFun(head->next,positionEndTail,ans);
    if(positionEndTail == 0){
        ans = head->data;
    }
    positionEndTail--;
}
int findEndOfkMethod2(Node* &head, int positionEndTail){
    int ans;
    recusiveFun(head, positionEndTail,ans);
    return ans;
}

//🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟
// 6️⃣ Intersection point of 2 Linked List (leetcode)
//  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//       ListNode* a = headA;
//         ListNode* b = headB;

//         while(a->next && b->next){
//             if(a== b){
//                 return a;
//             }
//             a = a->next;
//             b = b->next;
//         }
        
//         if(a->next == NULL && b->next == NULL && a->next != b->next) return NULL;

//         if(a->next == NULL){
//             // b is bigger or equal
//             int lenb = 0;
//             while(b->next != NULL){
//                 lenb++;
//                 b = b->next;
//             }
//             while(lenb--){
//                 headB = headB->next;
//             }
//         }else{
//             int lena = 0;
//             while(a->next != NULL){
//                 lena++;
//                 a = a->next;
//             }
//             while(lena--){
//                 headA = headA->next;
//             }
//         }

//         while(headA != headB){
//             headA = headA->next;
//             headB = headB->next;
//         }
//         return headA;
//     }

int main() {
    //🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟
// 1️⃣ Merge 2 sorted Linked List

// Node* head1 = new Node(1);
// Node* first1 = new Node(2);
// Node* second1 = new Node(4);

// head1->next = first1;
// first1->next = second1;
// second1->next = NULL;

// Node* head2 = new Node(1);
// Node* first2 = new Node(3);
// Node* second2 = new Node(4);

// head2->next = first2;
// first2->next = second2;
// second2->next = NULL;

// Node* result = mergeTwoSorted(head1,head2);
// cout << endl;
// print(result);
//🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟
// 3️⃣ Merge Sort in Linked List

// Node* head = new Node(4);
// Node* first = new Node(2);
// Node* second = new Node(1);
// Node* third = new Node(3);
// Node* fourth = new Node(8);
// Node* fifth = new Node(5);

// head->next = first;
// first->next = second;
// second->next = third;
// third->next = fourth;
// fourth->next = fifth;
// fifth->next = NULL;

// head = sortList(head);
// print(head);
//🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟
// 5️⃣ Print kth node from end of Linked List

// Node* head = new Node(1);
// Node* second = new Node(2);
// Node* third = new Node(3);
// Node* fourth = new Node(4);
// Node* fifth = new Node(5);

// head->next = second;
// second->next = third;
// third->next = fourth;
// fourth->next = fifth;
// fifth->next = NULL;

// cout << findEndOfK(head,3) << endl;  // output:- 2

// cout << findEndOfkMethod2(head,3) << endl; // output:- 2









    return 0;
}