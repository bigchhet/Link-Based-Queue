#include <iostream>
#include <string>

using namespace std;

class Node
{
    //redefine how to declare a Node*
    typedef Node* nodeptr;

    //necessary attributes for a node
    private:
        int data;
        nodeptr link;
        nodeptr prev;
    public:
        Node();
        friend class Queue;
};

class Queue
{
    //redefine how to declare a Node*
    typedef Node* nodeptr;

    //necessary attributes for a queue
    private:
        nodeptr front;
        nodeptr end;
        int count;

    //necessary functions for a queue
    public:
        Queue(); 
        void Enqueue(int);
        int Dequeue();
        bool IsEmpty();

};

//constructor for node
Node::Node()
{
    data = 0;
    link = NULL;
}

//constructor for queue
Queue::Queue()
{
    front = NULL;
    end = NULL;
    count = 0;
}

void Queue::Enqueue(int data)
{
    ///declare new node
    nodeptr n = new Node;

    //set the new nodes data component equal to user input
    n->data = data;

    //if queue is empty set the front and end pointer to the first node
    if(front == NULL)
    {   
        //update necessary pointers to look at n
        front = n;
        end = n;
        n = front;
        n = end;
        //increment count variable  
        count++;
    }

    else
    {
        //set the n prev pointer to look back at end pointer
        n->prev = end;

        //update the end pointer to link to n essentially looking forward to n
        end->link = n;

        //update end to be new node which basically means the new node has become new end
        end = n;

        //increment count variable
        count++;  
    }
}

int Queue::Dequeue()
{
    //initialize the temporary node m
    nodeptr m = new Node;

    //initialzew value variable to return to user later
    int value = 0;

    //this code will execute when the Queue is empty
    if(IsEmpty())
    {
        //inform user the Queue is empty and exit program
        cout << "Queue is empty. Nothing to dequeue." << endl;
        delete m;
        exit(1);    
    }

    //this code will automatically run when the user calls the function and the Queue is not empty
    else
    {
        m = front;

        front = front->link;

        value = m->data;

        delete m;

        count--;
    }

    //return the value of deleted node
    return value;
}

bool Queue::IsEmpty()
{
    //initalize local bool variable
    bool value;

    //this code will run if the count variable is equal to 0, which means the queue is empty
    if(count == 0)
    {
        //set the local bool variable to true
        value = true;
    }

    //this code will run if the code variable is no 0, which means the queue is not empty
    else
    {
        //set the local bool variable to false
        value = false;
    }

    //return the bool variable to caller
    return value;
}

int main()
{
    //declare LinkBasedQueue
    Queue LinkBasedQueue;

    //initialize variable to store user input
    int value = 0;
    int num = 0;
    int index = 1;

    //inform user to input data and how to break out of code
    cout << "Enter an integer to insert into the queue: (ENTER 0 to stop)" << endl;

    //store inital input into local variable
    cout << "["<< index << "]: "; 
    cin >> value;

    //this code will continue to prompt user for more data while their input does not equal 0
    while (value != 0)
    {
        //update the value of index variable
        index++;

        //enqueue user input
        LinkBasedQueue.Enqueue(value);

        //store inital input into local variable
        cout << "["<< index << "]: "; 
        cin >> value;
    }

    //add newline for improved readibility
    cout << endl;

    //prompt user how many nodes they would like to dequeue
    cout << "How many nodes would you like to dequeue: " << endl;
    //store user input into local variable
    cin >> num;

    //add newline for improved readibility
    cout << endl;

    //inform user that the following nodes were removed from the queue
    cout << "The following nodes were dequeued in this order: " << endl;
    for (int i = 1; i <= num; i++)
    {
        //indicate what nodes were dequeued
        cout << "["<< i << "]: " << LinkBasedQueue.Dequeue() << endl;
    }

    //add newline for improved readibility
    cout << endl;

    //indicate the end of program
    cout << "-----------------END------------------" << endl;
    
    return 0;
}