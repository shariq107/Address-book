#include<stdio.h>
#include"contact.h"

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void saveandEXIT(AddressBook *addressBook);
int main() 
{
    int choice;
    AddressBook addressBook;
    addressBook.contactCount = 0;
    initialize(&addressBook); 

    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        printf("6. Save and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:          
                listContacts(&addressBook);
                break;
            case 6:
                saveandEXIT(&addressBook);
                break;
            default:
                printf("-----Exit------\n");
        }
    } while (choice != 7);
    
       return 0;
}
