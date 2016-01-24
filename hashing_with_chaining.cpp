#include <iostream>
#include <cstdlib>

using namespace std ;

struct node {
    int value ;
    struct node * next ;
};


/********************************** Menu *****************************************/

void menu() {
    
    cout << "*********** MENU **********" << endl ;
    cout << "1. Insert item" << endl ;
    cout << "2. Delete item" << endl ;
    cout << "3. Display item" << endl ;
    cout << "4. Exit" << endl ;
}


/***************************** Hash Generator ************************************/

int hashFunction(int value) {
    return (value % 9) ;
}


/****************************** Insert New Node *********************************/

void Insert(int value, node * hashTable) {
    
    // store hash for a corresponding value
    int hash = hashFunction(value) ;
    
    // if hashTable is initially empty
    if (hashTable[hash].value == -1) {
        
        hashTable[hash].value = value ;
    }
    
    // else if hashTable is not empty
    else if(hashTable[hash].value != -1) {
        
        /*   Create New Node To Be inserted  */
        node * temp = new node ;
        temp -> value = value ;
        temp -> next = NULL ;
        
        // create a temporary variable and store initial address from hashTable for a specific hash
        node * temp1 = &hashTable[hash] ;
        
        while (temp1 -> next != NULL) {
            temp1 = temp1 -> next ;
        }
        
        temp1->next = temp;
    }
    
    return ;
}

/****************************** Delete Node ******************************************/

void Delete(int value, node * hashTable) {

    int hash = hashFunction(value) ;
    node * temp = &hashTable[hash] ;
    bool found = false ;
    
    
    if(temp->value == value) {
        temp->value = -1 ;
        temp->next = NULL ;
        found = true;
    }
    else {
        while (temp -> next != NULL) {
            
            if (temp -> next -> value == value) {
                temp -> next = temp -> next -> next ;
                found = true;
                break;
            }
            
            temp = temp -> next ;
        }
    }
    
    if (found == false)
        cout << "Not Found" << endl ;

    return ;
}

/****************************** Sub-Part Of Display() Method *******************************/

void Display1(node * hashTable) {
    
    if(hashTable->next == NULL) {
        if(hashTable->value != -1)
            cout << hashTable->value << " " ;
        return;
    }
    else {
        cout << hashTable->value << " ";
        Display1(hashTable->next);
    }
}

/****************************** Display Method **********************************************/

void Display(node * hashTable) {
    
    node * temp = hashTable;

    for (int i = 0 ; i < 10 ; ++i) {
        Display1(&hashTable[i]);
        hashTable = temp ;
    }
    
    return ;
}


/********************************** Main Function ********************************************/
int main() {
    
    // Initially we hava an hashtable of 10 nodes in which each node is a pointer
    // to the root node of a linked list
    node hashTable[10];
    
    for (int i = 0; i < 10; ++i) {
    
        hashTable[i].next = NULL ;
        hashTable[i].value = -1 ;
    }
    
    // Display the Menu
    menu();
    
    int ch , value;
    cout << "\nEnter your choice : ";
    cin >> ch;
    
    while (ch >= 1 && ch <= 3) {
        
        system("cls");
        
        if (ch == 1) {
            cout << "\nEnter Value To insert : " ;
            cin >> value ;
            Insert(value, hashTable) ;
        }
        
        if (ch == 2) {
            cout << "\nEnter Value To delete : ";
            cin >> value ;
            Delete(value, hashTable);
        }
        
        if (ch == 3)
            Display(hashTable);
        
        system("cls");
        menu();
        cout << "\nEnter your choice : " ;
        cin >> ch;
        
        if (ch == '\n') {
            cin >> ch ;
        }
    }
    
    if (ch == 4)
        cout << "\nBye\n\n" ;
    else
        cout << "\nUnexpectedly exit\n\n";
    
    return 0;
}
