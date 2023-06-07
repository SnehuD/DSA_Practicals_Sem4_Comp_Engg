/* . Consider telephone book database of N clients. Make use of a hash table 
implementation to quickly lookupclient ‘stelephonenumber. Makeuseoftwo collision 
handling techniques and compare them using number of comparisons required to find 
a set of telephone numbers */
#include <iostream>
#include <cstring>
using namespace std;

struct node
{
    string value;
    node* next;
};

class hashing
{
public:
    node* HashTable[10];

    hashing()
    {
        for (int i = 0; i < 10; i++)
        {
            HashTable[i] = NULL;
        }
    }
	int HashFunction(const string& key) {
    	int sum = 0;
    	for (size_t i = 0; i < key.length(); i++) {
        	sum += key[i];
    	}
    	return sum % 10;
	}
    node* create_node(const string& value)
    {
        node* temp = new node;	
        temp->next = NULL;
        temp->value = value;
        return temp;
    }

    void display()
    {
        for (int i = 0; i < 10; i++)
        {
            node* temp = HashTable[i];
            cout << "a[" << i << "] : ";
            while (temp != NULL)
            {
                cout << " ->" << temp->value;
                temp = temp->next;
            }
            cout << "\n";
        }
    }

    int searchElement(const string& value)
    {
        bool flag = false;
        int hash_val = HashFunction(value);
        node* entry = HashTable[hash_val];
        cout << "\nElement found at: ";
        while (entry != NULL)
        {
            if (entry->value == value)
            {
                cout << hash_val << " : " << entry->value << endl;
                flag = true;
            }
            entry = entry->next;
        }
        if (!flag)
            return -1;
        return 0;
    }

    void deleteElement(const string& value)
    {
        int hash_val = HashFunction(value);
        node* entry = HashTable[hash_val];
        node* prev = NULL;

        if (entry != NULL && entry->value == value)
        {
            HashTable[hash_val] = entry->next;
            delete entry;
            return;
        }

        while (entry != NULL && entry->value != value)
        {
            prev = entry;
            entry = entry->next;
        }

        if (entry == NULL)
            return;

        prev->next = entry->next;
        delete entry;
    }

    void insertElement(const string& value)
    {
        int hash_val = HashFunction(value);

        node* temp = create_node(value);

        if (HashTable[hash_val] == NULL)
        {
            HashTable[hash_val] = temp;
        }
        else
        {
            node* current = HashTable[hash_val];
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = temp;
        }
    }
};

int main()
{
    int ch;
    string data, search, del;
    hashing h;
    do
    {
        cout << "\nTelephone:\n1. Insert\n2. Display\n3. Search\n4. Delete\n5. Exit\n";
        cin >> ch;
        switch (ch)
        {
            case 1:
                cout << "\nEnter phone no. to be inserted: ";
                cin >> data;
                h.insertElement(data);
                break;
            case 2:
                h.display();
                break;
            case 3:
                cout << "\nEnter the number to be searched: ";
                cin >> search;
                if (h.searchElement(search) == -1)
                {
                    cout << "No element found at key\n";
                    continue;
                }
                break;
            case 4:
                cout << "\nEnter the phone number to be deleted: ";
                cin >> del;
                h.deleteElement(del);
                cout << "Phone number deleted\n";
                break;
        }
    } while (ch != 5);

    return 0;
}

/* 

Hash Table:

A hash table is a data structure that provides efficient insertion, deletion, and retrieval operations.
It is based on the concept of hashing, which maps keys to indices in an array for quick access to stored values.
The array used in a hash table is often called the "hash table" or "hash array," and each index is referred to as a "bucket" or "slot."
The size of the hash table is typically determined based on the expected number of elements and the desired load factor.
Hashing Function:

A hashing function is used to convert a given key (e.g., client name) into an index within the hash table.
The hashing function should distribute keys uniformly across the available indices to minimize collisions.
An ideal hashing function ensures a good distribution of keys and minimizes the number of collisions.
Basic Operations:

Insertion:

The key-value pair is hashed to compute the index where the value will be stored.
If the index is already occupied (collision occurs), the collision handling technique is applied.
The value is inserted at the appropriate index using the chosen collision handling technique.
Retrieval:

The key is hashed to determine the index where the value should be located.
If the index contains the desired value, it is returned.
If the index is empty or contains a different value, collision resolution techniques are applied to find the correct value.
Deletion:

The key is hashed to compute the index where the value is expected to be stored.
If the index contains the desired value, it is removed from the hash table.
If the index is empty or contains a different value, collision resolution techniques are used to locate and delete the correct value.
Types of Collision Handling Techniques:

Chaining:

In chaining, each index in the hash table stores a linked list of elements that hash to the same index.
When a collision occurs, the new element is appended to the linked list at the corresponding index.
The linked list allows multiple elements with the same hash value to be stored.
Retrieval involves traversing the linked list at the computed index to find the desired value.

Open Addressing:

In open addressing, all elements are stored directly in the hash table itself, without using additional data structures like linked lists.
When a collision occurs, an alternative location (often determined by a probing sequence) is found within the hash table to store the collided element.
Probing sequences can be linear probing (incrementing by a constant value), quadratic probing (incrementing by square of an offset), or double hashing (using a second hash function).
Retrieval involves following the probing sequence until the desired value is found or an empty slot is encountered. */


//-----SnehuD-----
