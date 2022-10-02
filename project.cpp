#include <iostream>
using namespace std;

class Node
{
public:
    int num;
    Node *next;

    Node(int x)
    {
        num = x;
        next = NULL;
    }
};

void insertnode(Node *&head, int data)
{
    Node *newnode = new Node(data);
    if (head == NULL)
    {
        head = newnode;

        return;
    }

    Node *temp = head;
    while (temp->next != NULL)

        temp = temp->next;
    temp->next = newnode;
}

Node *intersectionpoint(Node *head, Node *head2)
{

    Node *a = head;
    Node *b = head2;

    while (a != b)
    {
        a = a == NULL ? head2 : a->next;
        b = b == NULL ? head : b->next;
    }

    return a;
}

void printnode(Node *head)
{
    while (head->next != NULL)
    {
        cout << head->num << "->";
        head = head->next;
    }
    cout << head->num << endl;
}

int main()
{
    Node *head = NULL;

    insertnode(head, 5);
    insertnode(head, 15);
    insertnode(head, 25);
    insertnode(head, 35);
    Node *head1 = head;
    head = head->next->next;
    Node *headsec = NULL;
    insertnode(headsec, 3);
    Node *head2 = headsec;
    headsec->next = head;
    // printing of the lists
    cout << "List1: ";
    printnode(head1);
    cout << "List2: ";
    printnode(head2);
    // checking if intersection is present
    Node *answerNode = intersectionpoint(head, head2);
    if (answerNode == NULL)
        cout << "No intersection\n";
    else
        cout << "The intersection point is " << answerNode->num << endl;

    return 0;
}
