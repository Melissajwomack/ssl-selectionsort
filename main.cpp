#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;

//Node structure
struct node {
   int data;
   struct node *next;
};

//Class for node functions and head and tail initialization
class sll {
private:
    node *head, *tail;
public:
    sll() {
        head = NULL;
        tail = NULL;
    }
    
    //Function to create new node
    void newnode (int new_data) {
        node *tmp = new node;
        tmp->data = new_data;
        tmp->next = NULL;
        
        if (head == NULL) {
            head = tmp;
            tail = tmp;
        }
        
        else {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    
    //Fucntion to create 15 nodes with random integer values between 1 and 100
    void fifteennodes() {
        int i = 0;
        srand (time(NULL));
        while (i < 15) {
            int a = rand() % 100+1;
            this->newnode(a);
            i++;
        }
    }
    
    //Function to display list
     void traverse () {
        node *tmp = head;
        while(tmp->next) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
       cout  << endl;
    }
    
    //Function that calls recursive sort function and passes head node pointer
    void sort () {
        if (head == NULL) {
            return;
        }
    
        head = reselsort(head);
    }
    
    //Function to swap nodes that takes the following as parameteres: 
    //A reference to a the location of the head node (tmpref)
    //The pointer to the current head node (x)
    //The pointer to the current node that has the min value (y)
    //The pointer to the node berfore the current node that has the min value (prevy)
    void swap(struct node **tmpref, struct node *x, struct node *y, struct node *prevy) {
        //Set the location that stores the head pointer to store the pointer for the old min value node
        *tmpref = y;
        //Set the the pointer for the node prev to the old min node to point to the old head node
        prevy->next = x;
        //Create tmp pointer that points to the node after the min node
        struct node *tmp = y->next;
        //Set the node after the old min node to point to the node after the old head node
        y->next = x->next;
        //Set the old head node to point to the node after the old min node
        x->next = tmp;
    }
    
    //Recursive selection sort function that takes the head node pointer as an argument, 
    //swaps min and head node, and returns the new temporary "head" node pointer
    struct node  *reselsort(struct node *tmphead) {
        
        if (tmphead->next == NULL) {
            return tmphead;
        }
        struct node *min = tmphead;
        struct node *beforemin = NULL;
        struct node *ptr;
        
        for(ptr = tmphead; ptr->next != NULL; ptr = ptr->next) {
            if (ptr->next->data < min->data) { 
                min = ptr->next; 
                beforemin = ptr; 
            } 
        }
        
        if (min != tmphead) 
        swap(&tmphead, tmphead, min, beforemin); 
        
        //Recursive call to move to next node and continue
        tmphead->next = reselsort(tmphead->next); 
  
        return tmphead;
    }
};

int main() {
    
    //Initialize class with head and tail pointers set to null
    sll sll1;
    
   //Create 15 nodes with random numbers between 1 and 100
   sll1.fifteennodes();

    //Display list
    cout << "Original list: " << endl;
    sll1.traverse();
    
    //Selection sort
    sll1.sort();
    
    //Display sorted list
    cout << "\nSorted list: " << endl;
    sll1.traverse();
   return 0;
}
