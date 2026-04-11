#include<iostream>
#include<fstream>


using namespace std;

//declaration
int choice;

//stack



struct Book
{
    int id;
    string author,title;
};

struct Node
{
    Book data;
    Node* next;
};


//save to file
void saveToFile(Node* head) {
    ofstream outFile("books.txt");
    Node* temp = head;
    while (temp != nullptr) {
        outFile << temp->data.id << "\t"
                << temp->data.title << "\t"
                << temp->data.author << endl;
        temp = temp->next;
    }
    outFile.close();
}


//add
void add(Node*& head) {
    Node* newNode = new Node(); // Dynamic memory allocation

    cout << "Enter id: ";
    cin >> newNode->data.id;
    cin.ignore();
    cout << "Enter Title: ";
    getline(cin, newNode->data.title);
    cout << "Enter author: ";
    getline(cin, newNode->data.author);

    // Points the new book to the current head, then makes this the new head
    newNode->next = head;
    head = newNode;

    saveToFile(head);
    cout << "Book added successfully.\n";
}


//delete
void delt(Node*& head) {
    if (head == nullptr) return;

    int searchID;
    cout << "Enter ID to delete: ";
    cin >> searchID;

    Node* temp = head;
    Node* prev = nullptr;

    // If the book to delete is the head
    if (temp != nullptr && temp->data.id == searchID) {
        head = temp->next;
        delete temp; // Free memory
        saveToFile(head);
        return;
    }

    // Search for the ID
    while (temp != nullptr && temp->data.id != searchID) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) return;

    // Unlink the node and free memory
    prev->next = temp->next;
    delete temp;
    saveToFile(head);
}

//edit
void edit(Node* head)
{
    if (head == nullptr)
    {
        cout << "No books to edit." << endl;
        return;
    }

    int searchID;
    cout << "Enter ID of book to edit: ";
    cin >> searchID;
    cin.ignore();

    Node* current = head;
    while (current != nullptr)
    {
        if (current -> data.id == searchID)
        {
            cout << "Enter new Title: ";
            getline(cin, current -> data.title);
            cout << "Enter new Author: ";
            getline(cin, current -> data.author);

            saveToFile(head);
            cout << "Book updated successfully." << endl;
            return;
        }
        current = current -> next; //Move to next node
    }
    cout << "Book not found." << endl;
}

//display
void display(Node* head)
{
    if (head == nullptr)
    {
        cout << "No books in the library." << endl;
        return;
    }

    Node* temp = head;
    cout << "\n--- Library Books ---" << endl;
    cout << "ID\tTitle\tAuthor" << endl;
    cout << "-----------------" << endl;

    while (temp != nullptr)
    {
        cout << temp -> data.id << "\t"
             << temp -> data.title << "\t\t"
             << temp -> data.author << endl;
        temp = temp -> next; // Move temp to the next node
    }
    cout << "-------------------------------------------" << endl;
}

int main()
{
    Node* head = nullptr;


        do
        {
            cout<<"\n ------------Libary system------------ \n";
            cout<<"1. Add Book \n";
            cout<<"2. Delete Book \n";
            cout<<"3. Edit Book details \n";
            cout<<"4. Display all books \n";
            cout<<"5. Search Book \n";
            cout<<"6. Exit\n";
            cout<<"Enter a number: ";
            cin>>choice;

            if(choice >0 && choice < 6)
            {
                switch(choice)
                {
                    case 1:add(head); break;
                    case 2:delt(head); break;
                    case 3:edit(head); break;
                    case 4:display(head); break;

                }
            }
            else if (choice == 6)
            {
                break;
            }
            else
            {
                cout<<"Invalid choice.";
            }


        }while (choice != 6);


}