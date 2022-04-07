
#include<bits/stdc++.h>
using namespace std;
int Ans[100000];
int numb = 0;

struct Node
{
    int data;
    Node* link;
};

Node* top;

// Utility function to add an element
// data in the stack insert at the beginning
void push(int data)
{

    // Create new node temp and allocate memory in heap
    Node* temp = new Node();

    // Check if stack (heap) is full.
    // Then inserting an element would
    // lead to stack overflow
    if (!temp)
    {
        cout << "\nStack Overflow";
        exit(1);
    }

    // Initialize data into temp data field
    temp->data = data;

    // Put top pointer reference into temp link
    temp->link = top;

    // Make temp as top of Stack
    top = temp;
}

// Utility function to check if
// the stack is empty or not
int isEmpty()
{
    //If top is NULL it means that
    //there are no elements are in stack
    return top == NULL;
}

// Utility function to return top element in a stack
int peek()
{

    // If stack is not empty , return the top element
    if (!isEmpty())
        return top->data;
    else
        exit(1);
}

// Utility function to pop top
// element from the stack
void pop()
{
    Node* temp;

    // Check for stack underflow
    if (top == NULL)
    {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }
    else
    {

        // Assign top to temp
        temp = top;

        // Assign second node to top
        top = top->link;

        //This will automatically destroy
        //the link between first node and second node

        // Release memory of top node
        //i.e delete the node
        free(temp);
    }
}

// Function to print all the
// elements of the stack
void display()
{
    Node* temp;

    // Check for stack underflow
    if (top == NULL)
    {
        cout << "\nStack Underflow";
        exit(1);
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {

            // Print node data
            cout << temp->data << "-> ";

            // Assign temp link to temp
            temp = temp->link;
        }
    }
}
 struct QNode {
    int data;
    QNode* next;
    QNode(int d)
    {
        data = d;
        next = NULL;
    }
};

struct Queue {
    QNode *fronts, *rear;
    Queue()
    {
        fronts = rear = NULL;
    }

    void enQueue(int x)
    {

        // Create a new LL node
        QNode* temp = new QNode(x);

        // If queue is empty, then
        // new node is front and rear both
        if (rear == NULL) {
            fronts = rear = temp;
            return;
        }

        // Add the new node at
        // the end of queue and change rear
        rear->next = temp;
        rear = temp;
    }

    // Function to remove
    // a key from given queue q
    void deQueue()
    {
        // If queue is empty, return NULL.
        if (fronts == NULL)
            return;

        // Store previous front and
        // move front one node ahead
        QNode* temp = fronts;
        fronts = fronts->next;

        // If front becomes NULL, then
        // change rear also as NULL
        if (fronts == NULL)
            rear = NULL;

        delete (temp);
    }
};


void Ispalimore(string letters)
{


        Queue q;
        int a = 0;
        for(int i = 0; i < letters.size(); i++)
        {
                int Inttest = (int)letters[i] - 48;

                      q.enQueue(Inttest);
        push(Inttest);

        }


        while (a != letters.size()&& (q.fronts)->data == peek() )
        {
            a++;
           pop();
           q.deQueue();
        }

        if ( a== letters.size()){

            if( stoi(letters) % 2 != 0)
            {

            numb++;
                Ans[numb] = stoi(letters);
            }

        }
        else
        {


        }




}


int main()
{
int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
stringstream ss;
ss << i;
string str = ss.str();
    Ispalimore(str);

    }

     for(int i = 1; i <= numb; i++)
     {
       cout << Ans[i] << " ";
     }

    return 0;
}
