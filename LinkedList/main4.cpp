#include<iostream>
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
            cout << temp->data << "";
            temp = temp->next;
      }
}

Node* reverseNode(Node* &head){
        Node* prev=NULL;
        Node* curr=head;
        Node* forwoard = curr->next;
        while(curr != NULL){
            forwoard = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forwoard;
        }
        return prev;
}

bool isPalindromeOrNot(Node* &head){
      if(head == NULL){
            cout << "L.L is empty" << endl;
            return true; // false use karsakte ho as require then says
      }
      if(head->next == NULL){
            return true;
      }
      // Step A: find the middle node
      Node* slow = head;
      Node* fast = head;

      while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
      }
      // middle is slow

      // Step B:
      Node* middleAfterRevese = reverseNode(slow->next);

      // Step C:
      slow->next = middleAfterRevese;

      // Step D:
      Node* temp = head;
      Node* temp2 = middleAfterRevese;

      while(temp2 != NULL){
            if(temp->data != temp2->data){
                  return false;
            }else{
                  temp = temp->next;
                  temp2 = temp2->next;
            }
      }
      return true;

}
void removeDuplicates(Node* &head){
  if(head == NULL){
      cout << "LL is empty" << endl;
      return;
  }
  if(head->next == NULL){
      cout << "single node present" << endl;
      return;
  }

  //Remove duplicate L.L
  Node* curr = head;
  while(curr != NULL){
      if((curr->next != NULL) && curr->data == curr->next->data){
            // equal
            Node* temp = curr->next;
            curr->next = curr->next->next;
            // delete
            temp->next = NULL;
            delete temp;

      }else{
            curr = curr->next;
      }
  }

}

void sortZeroOneTwoWithReplacement(Node* &head){
      if(head == NULL){
            cout << "LL is empty" << endl;
            return;
      }
      if(head->next == NULL){
            cout << "LL is single node" << endl;
      }

      int Zeros = 0;
      int Ones = 0;
      int Twos = 0;
      Node* temp = head;

      while(temp != NULL){
            if(temp->data == 0){
                  Zeros++;
            }else if(temp->data == 1){
                  Ones++;
            }else if(temp->data == 2){
                  Twos++;
            }
            temp = temp->next;
      }

      temp = head;

      while(Zeros--){
            temp->data = 0;
            temp = temp->next;
      }
      while(Ones--){
            temp->data = 1;
            temp = temp->next;
      }
      while(Twos--){
            temp->data = 2;
            temp = temp->next;
      }
        
            
}
Node* sort2(Node* &head){
     if(head == NULL){
      cout << "LL is empty" << endl;
     }
     if(head->next == NULL){
      // single node
      return head;
     }

// create dummy nodes
     Node* zeroHead = new Node(-1);
     Node* zeroTail = zeroHead;

     Node* oneHead = new Node(-1);
     Node* oneTail = oneHead;

     Node* twoHead = new Node(-1);
     Node* twoTail = twoHead;

     Node* curr = head;
     while(curr != NULL){
         if(curr->data == 0){
            // take out the zero wali node
                Node* temp = curr;
                curr = curr->next;
                temp->next = NULL;
            // append the zero node in zeroHead LL
             zeroTail->next = temp;
             zeroTail = temp;
            
         }else if(curr->data == 1){
             // take out the zero wali node
                Node* temp = curr;
                curr = curr->next;
                temp->next = NULL;
            // append the zero node in zeroHead LL
             oneTail->next = temp;
             oneTail = temp;

         }else if(curr->data == 2){
              // take out the zero wali node
                Node* temp = curr;
                curr = curr->next;
                temp->next = NULL;
            // append the zero node in zeroHead LL
             twoTail->next = temp;
             twoTail = temp;
         }
     }

  
      // remove dummy Nodes
      //  Step A one Dummy node Delete
       Node* temp = oneHead;
       oneHead = oneHead->next;
       temp->next = NULL;
       delete temp;

      //  Step B two dummy nodes Delete
      temp = twoHead;
      twoHead = twoHead->next;
      temp->next = NULL;
      delete temp;

// join list
if(oneHead != NULL){
      // one wali list is non empty
      zeroTail->next = oneHead;
      if(twoHead != NULL){
            oneTail->next = twoHead;
      }
}else{
      // one wali list is empty
      if(twoHead != NULL){
            zeroTail->next = twoHead;
      }
}

// remove zero head dummy node
temp = zeroHead;
zeroHead = zeroHead->next;
temp->next = NULL;
delete temp;

//  return head of the modified linked list 
return zeroHead;

}

Node* addTwoNumbers(Node* &head1, Node* &head2){

      if(head1 == NULL){
            return head2;
      }
      if(head2 == NULL){
            return head1;
      }

      // Step 1: reverse both linked lists
      head1 = reverseNode(head1);
      head2 = reverseNode(head2);

      // step 2: add both LL
      Node* ansHead = NULL;
      Node* ansTail = NULL;
      int carry = 0;

      while(head1 != NULL && head2 != NULL){
            int sum = carry + head1->data + head2->data;
            int digit = sum % 10;
            carry = sum / 10;

            Node* temp = new Node(digit);
            if(ansHead == NULL){
                  ansHead = temp;
                  ansTail = temp;
            }else{
                  ansTail->next = temp;
                  ansTail = temp;
            }
            head1 = head1->next;
            head2 = head2->next;

      }

      // head1 data greater than head2
      while(head1 != NULL){
            int sum = carry + head1->data;
            int digit = sum % 10;
            carry = sum / 10;

            Node* temp = new Node(digit);
            ansTail->next = temp;
            ansTail = temp;
            head1 = head1->next;
      }

      // head2 data greater than head1
      while(head2 != NULL){
            int sum = carry + head2->data;
            int digit = sum % 10;
            carry = sum / 10;

            Node* temp = new Node(digit);
            ansTail->next = temp;
            ansTail = temp;
            head2 = head2->next;
      }

      while(carry != 0){
            int sum = carry;
            int digit = sum % 10;
            carry = sum / 10;

            Node* temp = new Node(digit);
            ansTail->next = temp;
            ansTail = temp;
      }

      // Step 3: reverse the ans LL
       ansHead = reverseNode(ansHead);
       
       return ansHead;
}


int main() {
//🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟
//1️⃣ whether Palindrome not or yes // :- Time Complexity O(n);

// Node* head = new Node(10);
// Node* second = new Node(20);
// Node* third = new Node(30);
// Node* fourth = new Node(30);
// Node* fifth = new Node(20);
// Node* sixth = new Node(10);

// head->next = second;
// second->next = third;
// third->next = fourth;
// fourth->next = fifth;
// fifth->next = sixth;

// bool result = isPalindromeOrNot(head);
// cout << result << endl;

// if(result){
//       cout << "L.L is Palindrome" << endl;
// }else{
//    cout << "L.L is not Palindrome" << endl;
// }

//🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟
//2️⃣ Remove duplicate from a Sorted on LL // :- Time Complexity O(n);

// Node* head = new Node(1);
// Node* second = new Node(2);
// Node* third = new Node(2);
// Node* fourth = new Node(3);
// Node* fifth = new Node(4);
// Node* sixth = new Node(4);
// Node* seventh = new Node(5);
// Node* eigth = new Node(6);
// Node* ninth = new Node(6);

// head->next = second;
// second->next = third;
// third->next = fourth;
// fourth->next = fifth;
// fifth->next = sixth;
// sixth->next = seventh;
// seventh->next = eigth;
// eigth->next = ninth;
// ninth->next = NULL;

// print(head);
// removeDuplicates(head);
// cout << endl;
// print(head);
//🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟
//3️⃣ Sorted 0's,1's,2's // :- Time Complexity O(n)
// Node* head = new Node(0);
// Node* second = new Node(2);
// Node* third = new Node(1);
// Node* fourth = new Node(1);
// Node* fifth = new Node(0);
// Node* sixth = new Node(1);
// Node* seventh = new Node(1);
// Node* eigth = new Node(0);
// Node* ninth = new Node(2);

// head->next = second;
// second->next = third;
// third->next = fourth;
// fourth->next = fifth;
// fifth->next = sixth;
// sixth->next = seventh;
// seventh->next = eigth;
// eigth->next = ninth;
// ninth->next = NULL;

// cout << "Soreted before" << endl;
// print(head); 
// Replacement methods
// sortZeroOneTwoWithReplacement(head);
// cout << endl;
// cout << "Sorted after" << endl;
// print(head); 

// cout << "Sorted after" << endl;
// print(head);

// head = sort2(head);
// cout << endl;
// cout << "Sorted after" << endl;
// print(head);
// cout<< endl;

//🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟🌟
// 4️⃣ Add 2 numbers represented by Linked List

Node* head1 = new Node(9);
Node* second1 = new Node(9);
head1->next = second1;

Node* head2 = new Node(9);
Node* second2 = new Node(9);
Node* third2 = new Node(9);
head2->next = second2;
second2->next = third2;

Node* ans = addTwoNumbers(head1, head2);
print(ans);
cout << endl;

return 0;



      
    return 0;
}