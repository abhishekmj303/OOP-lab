#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    Node(int data = 0)
    {
        this->data = data;
        this->next = NULL;
    }

    friend class CLinkList;
};

class CLinkList
{
    Node *head;
    int size;

    void createHead(int data)
    {
        Node *node = new Node(data);
        this->head = node;
        node->next = head;
        this->size = 1;
    }
    void insertHead(int data)
    {
        Node *temp = this->head;
        for (int i = 0; i < this->size - 1; i++)
        {
            temp = temp->next;
        }
        Node *node = new Node(data);
        node->next = head;
        temp->next = node;
        this->head = node;
        this->size++;
        return;
    }
    void insertTail(int data)
    {
        Node *temp = this->head;
        for (int i = 0; i < this->size - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = new Node(data);
        temp->next->next = this->head;
        this->size++;
        return;
    }
    void insertK(int data, int k)
    {
        Node *temp = this->head;
        for (int i = 0; i < k - 1; i++)
        {
            temp = temp->next;
        }
        Node *node = new Node(data);
        node->next = temp->next;
        temp->next = node;
        this->size++;
    }

    int destroyHead()
    {
        int data = head->data;
        delete this->head;
        this->head = NULL;
        this->size = 0;
        return data;
    }
    int deleteHead()
    {
        Node *temp = this->head;
        for (int i = 0; i < this->size - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = this->head->next;
        int data = this->head->data;
        delete this->head;
        this->head = temp->next;
        this->size--;
        return data;
    }
    int deleteTail()
    {
        Node *temp = this->head;
        for (int i = 0; i < this->size - 2; i++)
        {
            temp = temp->next;
        }
        Node *node = temp->next;
        int data = node->data;
        temp->next = this->head;
        delete node;
        this->size--;
        return data;
    }
    int deleteK(int k)
    {
        Node *temp = this->head;
        for (int i = 0; i < k - 1; i++)
        {
            temp = temp->next;
        }
        Node *node = temp->next;
        temp->next = node->next;
        int data = node->data;
        delete node;
        this->size--;
        return data;
    }

public:
    CLinkList()
    {
        this->head = NULL;
        this->size = 0;
    }

    void insert(int data)
    {
        if (head == NULL)
        {
            createHead(data);
            return;
        }
        insertTail(data);
    }
    void insert(int data, int pos)
    {
        if (pos <= 0 || pos > this->size + 1)
        {
            cout << "Invalid position" << endl;
        }
        else if (head == NULL)
        {
            createHead(data);
        }
        else if (pos == 1)
        {
            insertHead(data);
        }
        else if (pos == this->size + 1)
        {
            insertTail(data);
        }
        else
        {
            insertK(data, pos);
        }
    }

    void del()
    {
        if (size == 0)
        {
            cout << "The list is empty" << endl;
            return;
        }
        else if (size == 1)
        {
            cout << "Deleted: " << destroyHead() << endl;
        }
        else
        {
            cout << "Deleted: " << deleteTail() << endl;
        }
    }
    void del(int pos)
    {
        if (pos <= 0 || pos > this->size)
        {
            cout << "Invalid position" << endl;
        }
        else if (size == 0)
        {
            cout << "The list is empty" << endl;
        }
        else if (size == 1)
        {
            cout << "Deleted: " << destroyHead() << endl;
        }
        else if (pos == 1)
        {
            cout << "Deleted: " << deleteHead() << endl;
        }
        else if (pos == size)
        {
            cout << "Deleted: " << deleteTail() << endl;
        }
        else
        {
            cout << "Deleted: " << deleteK(pos) << endl;
        }
    }

    void search(int data)
    {
        int count = 0;
        Node *temp = this->head;
        cout << "Found at postions: ";
        for (int i = 0; i < size; i++)
        {
            if (temp->data == data)
            {
                cout << i + 1 << "  ";
                count++;
            }
            temp = temp->next;
        }
        if (count == 0)
        {
            cout << "None" << endl;
        }
        else
        {
            cout << endl;
        }
    }

    void display()
    {
        Node *temp = this->head;
        cout << "Circular Linked List: ";
        for (int i = 0; i < this->size; i++)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    int choice = 0;
    cout << "Circular Linked List: " << endl;
    cout << "\t1. Insert" << endl;
    cout << "\t2. Delete" << endl;
    cout << "\t3. Search" << endl;
    cout << "\t4. Display" << endl;
    cout << "\t5. Exit" << endl;

    CLinkList list;
    while (choice != 5)
    {
        cout << "\nOption: ";
        cin >> choice;

        if (choice == 1)
        {
            int data;
            char ch;
            cout << "Enter data to insert: ";
            cin >> data;
            cout << "Do you want to insert at end? (y/n): ";
            cin >> ch;
            if (ch == 'y')
            {
                list.insert(data);
            }
            else if (ch == 'n')
            {
                int pos;
                cout << "Enter the position to insert: ";
                cin >> pos;
                list.insert(data, pos);
            }
            else
            {
                cout << "Invalid choice" << endl;
            }
        }
        else if (choice == 2)
        {
            char ch;
            cout << "Do you want to delete at end? (y/n): ";
            cin >> ch;
            if (ch == 'y')
            {
                list.del();
            }
            else if (ch == 'n')
            {
                int pos;
                cout << "Enter the position to delete: ";
                cin >> pos;
                list.del(pos);
            }
            else
            {
                cout << "Invalid choice" << endl;
            }
        }
        else if (choice == 3)
        {
            int data;
            cout << "Enter the data to search: ";
            cin >> data;
            list.search(data);
        }
        else if (choice == 4)
        {
            list.display();
        }
        else if (choice == 5)
        {
            cout << "Exiting..." << endl;
        }
        else
        {
            cout << "Invalid Option" << endl;
        }
    }
}