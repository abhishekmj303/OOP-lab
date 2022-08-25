#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data = 0, Node *next = NULL, Node *prev = NULL)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
    int get_data()
    {
        return this->data;
    }
    friend class DLinkList;
};

class DLinkList
{
    Node *head;
    Node *tail;

    void tail_insert(Node *node)
    {
        if (head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

public:
    DLinkList(Node *head = NULL, Node *tail = NULL)
    {
        this->head = head;
        this->tail = tail;
    }

    void insert(Node *p)
    {
        if (head == NULL)
        {
            head = p;
            tail = p;
            return;
        }
        Node *temp = this->head;
        while (temp->data <= p->data && temp->next != NULL)
        {
            temp = temp->next;
        }
        if (temp->next == NULL && p->data >= temp->data)
        {
            temp->next = p;
            p->prev = temp;
            this->tail = p;
        }
        else if (temp == this->head)
        {
            this->head->prev = p;
            p->next = this->head;
            this->head = p;
        }
        else
        {
            p->prev = temp->prev;
            p->next = temp;
            p->prev->next = p;
            temp->prev = p;
        }

        return;
    }
    void del(int pos)
    {
        Node *temp = this->head;
        int i;
        for (i = 1; i < pos && temp->next != NULL; i++)
        {
            temp = temp->next;
        }
        if (pos > i || pos < 1)
        {
            cout << "Position " << pos << " does not exist" << endl;
            return;
        }
        if (this->tail == this->head)
        {
            delete this->head;
            this->tail = this->head = NULL;
            return;
        }
        if (temp->next == NULL)
        {
            tail = tail->prev;
            delete (tail->next);
            tail->next = NULL;
        }
        else if (temp == this->head)
        {
            head = head->next;
            delete (head->prev);
            head->prev = NULL;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete (temp);
        }
    }
    void destroy()
    {
        Node *temp = this->head;
        while (temp != NULL)
        {
            this->head = this->head->next;
            delete (temp);
            temp = this->head;
        }
        this->tail = this->head = NULL;
    }
    void display()
    {
        Node *temp = this->head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        return;
    }
    DLinkList merge(DLinkList list1, DLinkList list2)
    {
        Node *temp1 = list1.head;
        Node *temp2 = list2.head;
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->data < temp2->data)
            {
                this->tail_insert(new Node(temp1->data));
                temp1 = temp1->next;
            }
            else
            {
                this->tail_insert(new Node(temp2->data));
                temp2 = temp2->next;
            }
        }
        while (temp1 != NULL)
        {
            this->tail_insert(new Node(temp1->data));
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            this->tail_insert(new Node(temp2->data));
            temp2 = temp2->next;
        }
        return *this;
    }
};

int main()
{
    int choice = 0;
    cout << "Doubly Linked List" << endl;
    cout << "\t1. Insert" << endl;
    cout << "\t2. Delete" << endl;
    cout << "\t3. Display" << endl;
    cout << "\t4. Merge" << endl;
    cout << "\t5. Exit" << endl;

    DLinkList list1, list2, list3;
    while (choice != 5)
    {
        cout << "\nChoice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter the number to insert: ";
            cin >> data;
            list1.insert(new Node(data));
            break;
        }
        case 2:
        {
            int pos;
            cout << "Enter the position to delete: ";
            cin >> pos;
            list1.del(pos);
            break;
        }
        case 3:
        {
            cout << "Doubly Linked List: ";
            list1.display();
            break;
        }
        case 4:
        {
            list2.destroy();
            list3.destroy();
            int n;
            cout << "Enter the number of elements in list 2: ";
            cin >> n;
            cout << "Enter the list 2: ";
            for (int i = 0; i < n; i++)
            {
                int data;
                cin >> data;
                list2.insert(new Node(data));
            }
            list3.merge(list1, list2);
            cout << "List 1: ";
            list1.display();
            cout << "List 2: ";
            list2.display();
            cout << "Merged list: ";
            list3.display();
            break;
        }
        case 5:
        {
            cout << "Exiting..." << endl;
            break;
        }
        default:
            cout << "Invalid Option" << endl;
        }
    }
}