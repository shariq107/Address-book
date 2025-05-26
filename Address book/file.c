#include <stdio.h>
#include <string.h>
#include "file.h"  
#include "contact.h"
void saveContactsToFile(AddressBook *addressBook) 
{
    FILE *ptr = fopen("contact.txt", "w");  
    if(ptr == NULL)
    {
        printf("Error: Could not open file\n");
        return;
    }
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(ptr, "%s\t", addressBook->contacts[i].name);
        fprintf(ptr, "%s\t", addressBook->contacts[i].phone);
        fprintf(ptr, "%s\t", addressBook->contacts[i].email);
        putc('\n', ptr);
    }
    fclose(ptr);
    printf("Contacts saved to file successfully\n"); 
}


void loadContactsFromFile(AddressBook *addressBook) 
{
    FILE *fptr=fopen("contact.txt","r");
    if(fptr==NULL)
    {
        printf("File is not present");
        return;
    }
    char data[100];
    int i = 0;
    while(fgets(data,sizeof(data),fptr))
    {
        char *name=strtok(data,",");
        char *phone=strtok(NULL,",");
        char *email=strtok(NULL,"\n");
        if(name && phone && email && addressBook->contactCount<100)
        {
            strcpy(addressBook->contacts[addressBook->contactCount].name,name);
            strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);
            strcpy(addressBook->contacts[addressBook->contactCount].email,email);
            addressBook->contactCount++;
            i = 1;
        }
    }
    fclose(fptr);
    if(i == 1)
    {
        printf("Contacts loaded successfully\n");
    }
    else{
        printf("LOAD ERROR\n");
    }
    
}
