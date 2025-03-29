#include<iostream>
#include<vector>

using namespace std;

template<class t1 , class t2>
class Hash_table
{
private:
    const int size = 10;
    struct node
    {
        t1 key;
        t2 value;
        node* next;
    };
    vector<node*> table;
    int length;
    int hash(t1 key)
    {
        return key % size;
    }
public:
        Hash_table()
        {
            length = 0;
            table.resize(size);
            for(int i = 0; i < size; i++)
            {
                table[i] = NULL;
            }
        }
    bool isempty()
    {
        return length == 0;
    }
    int getlength()
    {
        return length;
    }
    void insert(t1 iteam , t2 element)
    {
        int pos = hash(iteam);
        node* newnode = new node;
        newnode->key = iteam;
        newnode->value = element;
        newnode->next = table[pos];
        table[pos] = newnode;
        // if(table[pos] == NULL)
        // {
        //     table[pos] = newnode;
        // }
        // else
        // {
        //     node* curr = table[pos];
        //     while (curr->next != NULL)  curr = curr->next;
        //     curr->next = newnode;
        // }
        length++;
    }

    void remove(t1 iteam , t2 element)
    {
        if(isempty())
        {
            cout << "Table is empty\n";
            return;
        }
        int pos = hash(iteam);
        node* curr = table[pos];
        node* prev = NULL;
        if(curr->key == iteam && curr->value == element)
        {
            table[pos] = curr->next;
            delete curr;
            curr = NULL;
            length--;
        }
        else
        {
            while (curr != NULL)
            {
                if(curr->key == iteam && curr->value == element) break;
                prev = curr;
                curr = curr->next;
            }
            if(prev != NULL)
            {
                prev->next = curr->next;
                delete curr;
                curr = NULL;
                length--;
            }
            else cout << "Element not found\n";
        }
    }

    bool search(t1 iteam , t2 element)
    {
        if(isempty())
        {
            cout << "Table is empty\n";
            return false;
        }
        int pos = hash(iteam);
        node* curr = table[pos];
        while (curr != NULL)
        {
            if(curr->key == iteam && curr->value == element) return true;
            curr = curr->next;
        }
        return false;
    }

    void print()
    {
        node* curr;
        for(int i = 0;i < size;i++)
        {
            curr = table[i];
            if(curr == NULL) continue;
            cout << "{ ";
            while (curr != NULL)
            {
                if(curr->next != NULL) cout << curr->key << " : " << curr->value << " , ";
                else
                cout << curr->key << " : " << curr->value ;
                curr = curr->next;
            }
            cout << " }\n";
        }
    }

    void clear()
    {
        node* curr;
        node* temp;
        for(int i = 0;i < size;i++)
        {
            curr = table[i];
            while (curr != NULL)
            {
                temp = curr;
                curr = curr->next;
                delete temp;
            }
            table[i] = NULL;
        }
        length = 0;
    }
};

int main()
{
    Hash_table<int , string> h;
    h.insert(10 , "Moaaz");
    h.insert(99 , "Ahmed");
    h.insert(98 , "Ali");
    h.insert(8 , "Fatma");
    h.insert(3456 , "Amany");
    h.insert(1890 , "John");
    h.insert(1034 , "Sara");
    h.insert(100 , "Mona");
    h.insert(12 , "Nada");
    // h.remove(10 , "Moaaz");
    // h.clear();
    h.print();
    if(h.search(99 , "Ahmed")) cout << "Found\n";
    else cout << "Not Found\n";
    return 0;
}