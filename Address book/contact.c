#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include <ctype.h>

void createContact(AddressBook *addressBook)
{ 
    char ch[50], ch1[50], ch2[50];
    
    printf("Enter the name: ");
    scanf(" %[^\n]", ch);
    for(int i = 0; i < addressBook->contactCount; i++) 
    {
        if(strncmp(ch, addressBook->contacts[i].name,strlen(ch)) == 0) 
        {
            printf("Error: Name already exists.\n");
            return; 
        }
    }
    printf("Enter Mobile Number: ");
    scanf(" %[0-9]", ch1);
    if(strlen(ch1) != 10) {
        printf("Error: Invalid Mobile NUmber.\n");
        return;
    }
    for(int i = 0; i < addressBook->contactCount; i++) 
    {
        if(strncmp(ch1, addressBook->contacts[i].phone,strlen(ch1)) == 0) 
        {
            printf("Error: Mobile number already exists.\n");
            return; 
        }
    }
    printf("Enter the email: ");
    scanf(" %[^\n]", ch2);
    if (strchr(ch2, '@') == NULL || strchr(ch2, '.') == NULL) 
    {
        printf("Error: Invalid email address.\n");
        return;
    }
    
    for(int i = 0; i < addressBook->contactCount; i++) 
    {
        if(strncmp(ch2, addressBook->contacts[i].email,strlen(ch2)) == 0) 
        {
            printf("Error: Email ID already exists.\n");
            return; 
        }
    }
    int j = addressBook->contactCount;
    addressBook->contactCount++;
    for(int i=0;i<=j;i++)
    {
        strcpy(addressBook->contacts[j].name, ch);
        strcpy(addressBook->contacts[j].phone, ch1);
        strcpy(addressBook->contacts[j].email, ch2);
    }
    printf("\n");
    printf("Contact added successfully!\n");


}
void searchContact(AddressBook *addressBook) 
{
    int choice;
    int found = 0;
    
    printf("\nChoose Option to Search\n");
    printf("1. Name\n2. Mobile Number\n3. Email ID\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);
    getchar(); 
    
    switch (choice) 
    {
        case 1:
        {
            char name1[50];
            printf("Enter the Name to Search: ");
            scanf("%[^\n]", name1); 
            
            for (int i = 0; i < addressBook->contactCount; i++) 
            {
                if (strstr(addressBook->contacts[i].name, name1)) 
                {
                    printf("\nName: %s\n", addressBook->contacts[i].name);
                    printf("Phone Number: %s\n", addressBook->contacts[i].phone);
                    printf("Email ID: %s\n", addressBook->contacts[i].email);
                    found = 1;
                    //break;
                }
            }
            if (!found) 
            {
                printf("Contact Not Found\n");
            }
            break;
        }
        
        case 2:
        {
            char phone1[50];
            printf("Enter the Phone Number to Search: ");
            scanf("%[^\n]", phone1); 
            
            for (int i = 0; i < addressBook->contactCount; i++) 
            {
                if (strstr(addressBook->contacts[i].phone, phone1)) 
                {
                    printf("\nName: %s\n", addressBook->contacts[i].name);
                    printf("Phone Number: %s\n", addressBook->contacts[i].phone);
                    printf("Email ID: %s\n", addressBook->contacts[i].email);
                    found = 1;
                    //break;
                }
            }
            if (!found) 
            {
                printf("Contact Not Found\n");
            }
            break;
        }
        
        case 3:
        {
            char email1[50];
            printf("Enter the Email ID to Search: ");
            scanf("%[^\n]", email1); 
            
            for (int i = 0; i < addressBook->contactCount; i++) 
            {
                if (strstr(addressBook->contacts[i].email, email1)) 
                {
                    printf("\nName: %s\n", addressBook->contacts[i].name);
                    printf("Phone Number: %s\n", addressBook->contacts[i].phone);
                    printf("Email ID: %s\n", addressBook->contacts[i].email);
                    found = 1;
                    //break;
                }
            }
            if (!found) 
            {
                printf("Contact Not Found\n");
            }
            break;
        }
        
        default:
            printf("Invalid Choice\n");
            break;
    }
}

void editContact(AddressBook *addressBook) 
{
    int opt;
    printf("Enter the option:\n 1. Name\n 2. Email\n");
    getchar();  
    scanf("%d", &opt);

    switch (opt) 
    {
        case 1: 
        {
            char name2[50];
            int count = 0;
            printf("Enter the name: ");
            getchar();  
            scanf("%[^\n]", name2);
            for (int i = 0; i < addressBook->contactCount; i++) 
            {
                if (strstr(addressBook->contacts[i].name, name2)) 
                {
                    count++;
                    printf("%d. Name: %s\t",count,addressBook->contacts[i].name);
                    printf("Phone Number: %s\t",addressBook->contacts[i].phone);
                    printf("Email: %s\n",addressBook->contacts[i].email);
                }
            }

            if (count == 0) 
            {
                printf("No contacts found with the given name.\n");
                return;
            }

            int choice;
            printf("Enter the serial number of the contact to edit: ");
            scanf("%d", &choice);

            if (choice < 1 || choice > count) 
            {
                printf("Invalid choice.\n");
                return;
            }

            int contactIndex = -1;
            count = 0;
            for (int i = 0; i < addressBook->contactCount; i++) 
            {
                if (strstr(addressBook->contacts[i].name, name2)) 
                {
                    count++;
                    if (count == choice) 
                    {
                        contactIndex = i;
                        break;
                    }
                }
            }
            if (contactIndex != -1) 
            {
                int option1;
                printf("Enter the option for editing the contact:\n1. Name\n2. Phone Number\n3. Email\n");
                scanf("%d", &option1);

                switch (option1) 
                {
                    case 1: 
                    {
                        char newName[50];
                        printf("Enter the new name: ");
                        getchar();  
                        scanf("%[^\n]", newName);
                        int flag = 0;
                        for(int i=0;i<addressBook->contactCount;i++)
                        {
                            if(strstr(addressBook->contacts[i].name,newName) != NULL)
                            {
                                flag = 1;
                                break;
                            }
                            
                        }
                        if(flag == 1)
                        {
                            printf("Error: Name already exists\n");
                        }
                        else{
                            strcpy(addressBook->contacts[contactIndex].name, newName);
                            printf("\nName updated successfully.\n");
                        }
                        break;
                    }

                    case 2: 
                    {
                        char newPhone[20];
                        int val = 0;
                        
                        do {
                            printf("Enter the new phone number: ");
                            scanf("%s", newPhone); 
                            getchar(); 

                            
                            if (strlen(newPhone) == 10) {
                                val = 0;  
                                for (int i = 0; i < addressBook->contactCount; i++) {
                                    if (strcmp(addressBook->contacts[i].phone, newPhone) == 0) {
                                        val = 1;  
                                        break;
                                    }
                                }

                                
                                int isValid = 1;
                                for (int i = 0; i < 10; i++) {
                                    if (!isdigit(newPhone[i])) {
                                        isValid = 0;
                                        break;
                                    }
                                }

                                if (!isValid) 
                                {
                                    printf("Error: Invalid phone number. Must be 10 digits.\n");
                                } 
                                else if (val == 0) 
                                {
                                    strcpy(addressBook->contacts[contactIndex].phone, newPhone);
                                    printf("Phone number updated successfully.\n");
                                    break;  
                                } else 
                                {
                                    printf("Error: Phone number already exists.\n");
                                }

                            } else {
                                printf("Error: Invalid phone number. Must be exactly 10 digits.\n");
                            }
                        } while (1);
                        break;

                    }

                    case 3: 
                    {
                        char Email2[50];
                        printf("Enter the new email: ");
                        scanf("%s",Email2);
                        int flag = 0; 
                        if (strstr(Email2, "@") && strstr(Email2, ".")) 
                        {
                            for (int i = 0; i < addressBook->contactCount; i++) 
                            {
                                if (strcmp(addressBook->contacts[i].email, Email2) == 0)  
                                {
                                    flag = 1;  
                                    break;
                                }
                            }

                            if (flag == 0) 
                            {
                                strcpy(addressBook->contacts[contactIndex].email, Email2);
                                printf("Email updated successfully.\n");
                            } 
                            else 
                            {
                                printf("Error: Email already exists.\n");
                            }
                        } 
                        else 
                        {
                            printf("Error: Invalid email address.\n");
                        }
                        break;

                    }

                    default: 
                        printf("Invalid option.\n");
                        break;
                }
            }
            break;
        }

        case 2:
        {
            char email2[50];
            printf("Enter the email ID to search: ");
            getchar();
            scanf("%[^\n]",email2);
            int count = 0;
            for(int i=0;i<addressBook->contactCount;i++)
            {
                if (strstr(addressBook->contacts[i].email, email2)) 
                {
                count++;
                printf("%d. Name: %s\t",count,addressBook->contacts[i].name);
                printf("Phone NUmber: %s\t",addressBook->contacts[i].phone);
                printf("Email: %s\n",addressBook->contacts[i].email);
                }
            }
            if(count == 0)
            {
                printf("No contact found at given email address\n");
            }
            int choice;
            printf("Enter the serial number of the contact you want to edit: ");
            scanf("%d",&choice);
            if(choice < 1 && choice > count)
            {
                printf("Invalid Choice");
            }

            int contactIndex1 = -1;
            count = 0;
            for (int i = 0; i < addressBook->contactCount; i++) 
            {
                if (strstr(addressBook->contacts[i].email, email2)) 
                {
                    count++;
                    if (count == choice) 
                    {
                        contactIndex1 = i;
                        break;
                    }
                }
            }
            if(contactIndex1 != -1)
            {
                int opt;
                printf("Enter the Option you want to edit :\n");
                printf("1.Name\n2.Phone\n3.Email\n");
                scanf("%d",&opt);
                switch(opt)
                {
                    case 1:
                    {
                        char name2[30];
                        printf("Enter the New Name: ");
                        
                        getchar();  
                        scanf("%[^\n]", name2);
                        int flag = 0;
                        for(int i=0;i<addressBook->contactCount;i++)
                        {
                            if(strstr(addressBook->contacts[i].name,name2)!= NULL)
                            {
                                flag = 1;
                                break;
                            }
                        }
                        if(flag == 1)
                        {
                            printf("Error: Name already exixts\n");
                        }
                        else
                        {
                            strcpy(addressBook->contacts[contactIndex1].name, name2);
                            printf("Name updated successfully.\n");   
                        }
                        break;
                    }
                    case 2: 
                    {
                        char newPhone[20];
                        int val = 0;
                        
                        do {
                            printf("Enter the new phone number: ");
                            scanf("%19s", newPhone); 
                            getchar();  

                            
                            if (strlen(newPhone) == 10) {
                                val = 0;  
                                for (int i = 0; i < addressBook->contactCount; i++) {
                                    if (strcmp(addressBook->contacts[i].phone, newPhone) == 0) {
                                        val = 1;  
                                        break;
                                    }
                                }

                            
                                int isValid = 1;
                                for (int i = 0; i < 10; i++) {
                                    if (!isdigit(newPhone[i])) {
                                        isValid = 0;
                                        break;
                                    }
                                }

                                if (!isValid) {
                                    printf("Error: Invalid phone number. Must be 10 digits.\n");
                                } else if (val == 0) {
                                    strcpy(addressBook->contacts[contactIndex1].phone, newPhone);
                                    printf("Phone number updated successfully.\n");
                                    break;  
                                } else {
                                    printf("Error: Phone number already exists.\n");
                                }

                            } else {
                                printf("Error: Invalid phone number. Must be exactly 10 digits.\n");
                            }
                        } while (1);
                        break;
                    }

                    case 3: 
                    {
                        char Email2[50];
                        printf("Enter the new email: ");
                        getchar();  
                        scanf("%[^\n]", Email2);

                        int flag = 0; 
                        if (strstr(Email2, "@") && strstr(Email2, ".")) 
                        {
                            for (int i = 0; i < addressBook->contactCount; i++) 
                            {
                                if (strcmp(addressBook->contacts[i].email, Email2) == 0)  
                                {
                                    flag = 1;  
                                    break;
                                }
                            }

                            if (flag == 0) 
                            {
                                strcpy(addressBook->contacts[contactIndex1].email, Email2);
                                printf("Email updated successfully.\n");
                            } 
                            else 
                            {
                                printf("Error: Email already exists.\n");
                            }
                        } 
                        else 
                        {
                            printf("Error: Invalid email address.\n");
                        }
                        break;

                    }

                    default: 
                        printf("Invalid option.\n");
                        break;
                }

            }

        }
            break;

        default:
            printf("Invalid option.\n");
            break;
    }
}


void deleteContact(AddressBook *addressBook) 
{
    int choice;
    int found = 0;
    printf("\nChoose Option to Delete\n");
    printf("1. Name\n2. Phone Number\n3. Email ID\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();  
    switch (choice) 
    {
        case 1: 
        {
            char name[50];
            printf("Enter the Name to Delete: ");
            scanf("%[^\n]", name);
            
            printf("Contacts:\n");
            for (int i = 0; i < addressBook->contactCount; i++) 
            {
                if (strstr(addressBook->contacts[i].name, name)) 
                {
                    printf("Index %d:\n Name: %s\n", i, addressBook->contacts[i].name);
                    printf("Phone : %s\n", addressBook->contacts[i].phone);
                    printf("Email : %s\n", addressBook->contacts[i].email);
                    printf("\n");
                    found = 1;
                }
            }
            if (found) 
            {
                int index;
                printf("Enter the index of the contact to delete: ");
                scanf("%d", &index);
                
                if (index >= 0 && index < addressBook->contactCount) 
                {
    
                    for (int i = index; i < addressBook->contactCount - 1; i++) 
                    {
                        addressBook->contacts[i] = addressBook->contacts[i + 1];
                    }
                    addressBook->contactCount--;  
                    printf("Contact deleted successfully.\n");
                } 
                else 
                {
                    printf("Invalid index.\n");
                }
            } 
            else 
            {
                printf("No contacts found with the given name.\n");
            }
            break;
        }

        case 2: 
        {
            char phone[20];
            printf("Enter the Phone Number to Delete: ");
            scanf("%[^\n]", phone);
            
            printf("Contacts:\n");
            for (int i = 0; i < addressBook->contactCount; i++) 
            {
                if (strstr(addressBook->contacts[i].phone, phone) == 0) 
                {
                    printf("Index %d: Name: %s\n", i, addressBook->contacts[i].name);
                    printf("Phone : %s\n", addressBook->contacts[i].phone);
                    printf("Email : %s\n", addressBook->contacts[i].email);
                    found = 1;
                }
            }
            if (found) 
            {
                int index;
                printf("Enter the index of the contact to delete: ");
                scanf("%d", &index);
                
                if (index >= 0 && index < addressBook->contactCount) 
                {
                
                    for (int i = index; i < addressBook->contactCount - 1; i++) 
                    {
                        addressBook->contacts[i] = addressBook->contacts[i + 1];
                    }
                    addressBook->contactCount--;  
                    printf("Contact deleted successfully.\n");
                } 
                else 
                {
                    printf("Invalid index.\n");
                }
            } 
            else 
            {
                printf("No contacts found with the given phone number.\n");
            }
            break;
        }

        case 3:     
        {
            char email[50];
            printf("Enter the Email ID to Delete: ");
            scanf(" %[^\n]", email);  
    
            printf("Matching Contacts:\n");
            int found = 0;  
            for (int i = 0; i < addressBook->contactCount; i++) 
            {
                if (strstr(addressBook->contacts[i].email, email) ) 
                {
                    printf("Index %d: Name: %s\n", i, addressBook->contacts[i].name);
                    printf("Phone : %s\n", addressBook->contacts[i].phone); 
                    printf("Email : %s\n",addressBook->contacts[i].email);
                    found = 1;
                }
            }
            if (found) 
            {
                int index;
                printf("Enter the index of the contact to delete: ");
                scanf("%d", &index);
            
                if (index >= 0 && index < addressBook->contactCount) 
                {
                    for (int i = index; i < addressBook->contactCount - 1; i++) 
                    {
                        addressBook->contacts[i] = addressBook->contacts[i + 1];
                    }
                    addressBook->contactCount--;  
                    printf("Contact deleted successfully.\n");
                } 
                else 
                {
                    printf("Invalid index.\n");
                }
            } 
            else 
            {
                printf("No contacts found with the given email ID.\n");
            }
        }
        break;
        default :
            printf("Invalid Choice\n");
            break;
        }
}

void saveandEXIT(AddressBook *addressBook)
{
    saveContactsToFile(addressBook); 
}

void initialize(AddressBook *addressBook)
{
    addressBook->contactCount = 0;
    loadContactsFromFile(addressBook);
}

void listContacts(AddressBook *addressBook) 
{
    if (addressBook->contactCount == 0) {
        printf("No contacts found\n");
        return;
    }

    printf("Listing all contacts:\n");
    for (int i = 0; i < addressBook->contactCount; i++) {
        printf("Contact %d:\n", i + 1);
        printf("Name: %s |", addressBook->contacts[i].name);
        printf("Phone: %s |", addressBook->contacts[i].phone);
        printf("Email: %s ", addressBook->contacts[i].email); 
        printf("\n- - - - - - - -\n");
    }
}


