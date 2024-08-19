#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // TODO: Write a destrcutor to delete a node
    ~Node()
    {
        // write your code here
        cout << "Node with value: " << this->data << "deleted" << endl;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int findLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        len++;
    }
    // cout << "len: " << len << endl;
    return len;
}

Node *findMiddle(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is Null" << endl;
        return head;
    }
    if (head->next == NULL)
    {
        return head;
    }

    Node *slow = head;
    // Node* fast = head;
    Node *fast = head->next;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}
// Node* reverse(Node* &prev,Node* &curr) {
//     // base case
//     if(curr == NULL){
//         //LL reverse end on node (curr)
//         return prev;
//     }

//     Node* Nex = curr -> next;
//     curr -> next  = prev;

//    return reverse(curr,Nex);
// }
Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = curr->next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool checkPalindrome(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return true;
    }
    if (head->next == NULL)
    {
        // only 1 node
        return true;
    }

    // >1 node in LL

    // StepA: find the middle node;
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    // slow pointer is pointing to the middle node

    // Step B: reverse LL after middle/slow node
    Node *reverseLLKaHead = reverse(slow->next);
    // join the reversed LL into the left part
    slow->next = reverseLLKaHead;

    // Step C: start comparison
    Node *temp1 = head;
    Node *temp2 = reverseLLKaHead;
    while (temp2 != NULL)
    {
        if (temp1->data != temp2->data)
        {
            // not a palindome
            return false;
        }
        else
        {
            // if data is equal, then aage badh jao
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return true;
}
void removeDuplicates(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return;
    }
    if (head->next == NULL)
    {
        cout << "Single Node in LL" << endl;
        return;
    }

    // >1 node in LL
    Node *curr = head;

    while (curr != NULL)
    {
        if ((curr->next != NULL) && (curr->data == curr->next->data))
        {
            // equal
            Node *temp = curr->next;
            curr->next = curr->next->next;
            // delete node
            temp->next = NULL;
            delete temp;
        }
        else
        {
            // not equal
            curr = curr->next;
        }
    }
}

void sortZeroOneTwo(Node* &head) {
        //step1: find count of zeroes, ones and twos
        int zero = 0;
        int one = 0;
        int two = 0;

        Node* temp = head;
        while(temp != NULL) {
                if(temp -> data == 0)
                        zero++;
                else if(temp -> data == 1)
                        one++;
                else if(temp -> data == 2)
                        two++;
                temp = temp -> next;
        }

        //step2: fill 0, 1 and 2s in the original ll
        temp = head;
                // fill zeroes
                while(zero--) {
                        temp -> data = 0;
                        temp = temp -> next;
                }

                //fill ones
                while(one--) {
                        temp -> data = 1;
                        temp = temp -> next;
                }

                //fill 2s
                while(two--) {
                        temp -> data = 2;
                        temp = temp -> next;
                }
        

}

Node* sort2(Node* &head) {
        if(head == NULL) {
                cout << "LL is empty " << endl;
                return NULL;
        }
        if(head -> next == NULL) {
                //sngle node in LL
                return head;
        }

        //create dummy nodes
        Node* zeroHead = new Node(-101);
        Node* zeroTail = zeroHead; 

        Node* oneHead = new Node(-101);
        Node* oneTail = oneHead; 

        Node* twoHead = new Node(-101);
        Node* twoTail = twoHead; 

        //traverse the original LL
        Node* curr = head;
        while(curr != NULL) {

                if(curr -> data == 0) {
                        //take out the zero wali node
                        Node* temp = curr;
                        curr = curr -> next;
                        temp -> next = NULL;

                        //append the zero node in zeroHead LL
                        zeroTail -> next = temp;
                        zeroTail = temp;

                }
                else if(curr -> data == 1) {
                        //take out the one wali node
                        Node* temp = curr;
                        curr = curr -> next;
                        temp -> next = NULL;

                        //append the zero node in zeroHead LL
                        oneTail -> next = temp;
                        oneTail = temp;

                }
                else if(curr -> data == 2) {
                        //take out the zero wali node
                        Node* temp = curr;
                        curr = curr -> next;
                        temp -> next = NULL;

                        //append the zero node in zeroHead LL
                        twoTail -> next = temp;
                        twoTail = temp;

                }
        }

        //ab yha pr, zero , one, two, teeno LL readyv h 

        // join them 
        //remove dummmy nodes

        //modify one wali list
        Node* temp = oneHead;
        oneHead = oneHead -> next;
        temp -> next = NULL;
        delete temp;

        //modify two wali list
        temp = twoHead;
        twoHead = twoHead -> next;
        temp -> next = NULL;
        delete temp;

        //join list
        if(oneHead != NULL) {
                // one wali list is non empty
                //zero wali list ko one wali list se attach krdia 
                zeroTail -> next = oneHead;
                
                if(twoHead != NULL)
                        oneTail -> next = twoHead;
        }
        else{
                //one wali list is empty
                if(twoHead != NULL)
                        zeroTail -> next = twoHead;
        }

        //remove zerohead dummy Node
        temp = zeroHead;
        zeroHead = zeroHead -> next;
        temp -> next = NULL;
        delete temp;
        
        //return head of the modified linked list
        return zeroHead;

}
Node* addTwoLL(Node* &head1, Node* &head2) {

        if(head1 == NULL)
                return head2;
        if(head2 == NULL)
                return head1; 

        //step1 : reverse both linked list
        head1 = reverse(head1);
        head2 = reverse(head2);

        //step2: add both linked list
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        int carry = 0;

        while(head1 != NULL && head2 != NULL) {
                //calculate sum
                int sum = carry + head1 -> data + head2 -> data;
                //find digit to create node for
                int digit = sum % 10;
                //calculate carry
                carry = sum / 10;

                //create a new Node for the digit
                Node* newNode = new Node(digit);
                //attach the newNode into the answer wali linked list
                if(ansHead == NULL) {
                        //first node insert krre ho
                        ansHead = newNode;
                        ansTail = newNode;
                }
                else {
                        ansTail -> next = newNode;
                        ansTail = newNode;
                }
                head1 = head1 -> next;
                head2 = head2 -> next;
        }

        //jab head1 list ki length head2 list se jada hogi
        while(head1 != NULL) {
                int sum = carry + head1 -> data;
                int digit = sum % 10;
                carry = sum / 10;
                Node* newNode = new Node(digit);
                ansTail -> next = newNode;
                ansTail = newNode;
                head1 = head1 -> next;
        }

        //jab head2 list ki length head1 list se jada hogi
        while(head2 != NULL) {
                int sum = carry + head2 -> data;
                int digit = sum % 10;
                carry = sum / 10;
                Node* newNode = new Node(digit);
                ansTail -> next = newNode;
                ansTail = newNode;
                head2 = head2 -> next;
        }

        //handle carry ko alag se
        while(carry != 0) {
                int sum = carry;
                int digit = sum % 10;
                carry = sum / 10;
                Node* newNode = new Node(digit);
                ansTail -> next = newNode;
                ansTail = newNode;
        }


        //step3: reverse the ans linked list
        ansHead = reverse(ansHead);
        return ansHead;
}




int main()
{

    // 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

    //   ❓ 4. whether Palindrome not or yes

    // Node* head = new Node(10);
    // Node* first = new Node(20);
    // Node* second = new Node(30);
    // Node* third = new Node(40);
    // Node* fourth = new Node(50);
    // Node* fifth = new Node(60);

    // head->next = first;
    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;
    // fifth->next = NULL;

    // bool isPalindrome = checkPalindrome(head);
    // if(isPalindrome){
    //     if(head == NULL){
    //         cout << "LL is Palindrome" << endl;
    //     }else{
    //         cout << "LL is not Palindrome" << endl;
    //     }

// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

//   ❓  5. Remove duplicate from a Sorted on LL

// Node *head = new Node(1);
// Node *second = new Node(2);
// Node *third = new Node(2);
// Node *fourth = new Node(3);
// Node *fifth = new Node(4);
// Node *sixth = new Node(4);
// head->next = second;
// second->next = third;
// third->next = fourth;
// fourth->next = fifth;
// fifth->next = sixth;

// cout << "input LL: ";
// print(head);

// removeDuplicates(head);
// cout << "output LL: ";
// print(head);



// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

//   ❓  6.  Sorted 0's,1's,2's 🌟Method 1 & 2

// Node* head = new Node(2);
//   Node* second = new Node(2);
//   Node* third = new Node(1);
//   Node* fourth = new Node(1);
//   Node* fifth = new Node(0);
//   Node* sixth = new Node(0);
//   head -> next = second;
//   second -> next = third;
//   third -> next = fourth;
//   fourth -> next = fifth;
//   fifth -> next = sixth;

//   cout << "input LL: ";
//   print(head);

// //   sortZeroOneTwo(head);
// //   print(head);
  
//   cout << "printing the sorted list " << endl;
//   Node* temp = NULL;
//   head = sort2(head);
//   //cout << "Came out of sort function" << endl;
//   print(head);


// 🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟

//   ❓  7 Add 2 numbers represented by Linked List O(max(m,n))

 Node* head1 = new Node(9);
        Node* second1 = new Node(9);
        head1 -> next = second1;

        Node* head2 = new Node(9);
        Node* second2 = new Node(9);
        // Node* third2 = new Node(4);
        head2 -> next = second2;
       // second2 -> next = third2;

        Node* ans = addTwoLL(head1, head2);

        print(ans);




return 0;

}