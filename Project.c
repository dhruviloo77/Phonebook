// Final Project by Dhruvil Shah & Harsh Patel
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining Structure
struct node
{
	char firstName[20];
	char lastName[20];
	int number;
	struct node *next;
};

void insert(char [],char[],int); //Function to insert names at beginning
void print_names(void); //Function to print names
void removeSpecific(); // Function to remove first name from the list
void LoadFromFile(FILE *);// Function to load data from file
void AddToFile(FILE *);// Function to add data at end of file

struct node *head=NULL; // structure type pointer head & assigning it to null

int main() // Main method
{

 	int num,read,number;// Num variable for switch case
	char inputFirstName[20],inputLastName[20];
	FILE *f = fopen("data.txt", "r");// Opening file in read mode
	FILE *fw = fopen("data.txt", "a");// Opening same file in append mode
	
	char enterName[20];// FirstName to be removed
	
	printf("            PhoneBook");
	printf("\n*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n");
	printf("Select From the following options :-\n 1. Add New Record\n 2. Retrieive Records \n 3. Delete Record \n 4. Load Records\n 5. Save Records\n");
	printf("*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n");
	scanf("\n%d",&num);


	switch(num)
	{
		case 1:// To insert in linked list
			while(strcmp(inputFirstName,"end") != 0)// Loop checks if inputFirstName is end or not
	{
		printf("Type end to stop");
		printf("\nEnter First Name: ");
		scanf("%s",&inputFirstName);
		if (strcmp(inputFirstName,"end") == 0)
			{
				break;
			}
		else
			{
				printf("\nEnter Last Name: ");
				scanf("%s",&inputLastName);
				printf("\nEnter Phone Number: ");
				scanf("%d",&number);
				insert(inputFirstName,inputLastName,number);// Call for insert function
			}
	
			printf("Name Inserted!!");
	}	
			printf("\nPress 1 to return to main menu or 0 exit");
			scanf("%d",&read);
			if(read == 1)
			return main();
			else
			exit(0);
			break;

		case 2:

			print_names(); // Calling print function
			printf("\nPress 1 to return to main menu or 0 exit");
			scanf("%d",&read);
			if(read == 1)
			return main();
			else
			exit(0);

		case 3:

			removeSpecific(enterName);// calling remove function
			printf("\nPress 1 to return to main menu or 0 exit");
			scanf("%d",&read);
			if(read == 1)
			return main();
			else
			exit(0);
		
		case 4:
		{
			LoadFromFile(f); // Calling load function to load data from file
			printf("\nPress 1 to return to main menu or 0 exit");
			scanf("%d",&read);
			if(read == 1)
			return main();
			else
			exit(0);
		}

		case 5:
			
		 	AddToFile(fw);// Calling add function from file
			printf("\nPress 1 to return to main menu or 0 exit");
			scanf("%d",&read);
			if(read == 1)
			return main();
			else
			exit(0);
			break;	
			

		default:
			printf("\nPlease Enter correct value");
			break;
	}

	return 0;
}

void insert(char* takeFirstName,char* takeLastName,int number) 
{
	struct node *newNode;
	newNode = (struct node *)malloc(sizeof(struct node));
	strcpy(newNode -> firstName,takeFirstName);
	strcpy(newNode -> lastName,takeLastName);
	newNode -> number = number;

	if(head == NULL)
	{
		newNode->next = NULL;
		head = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
}

void print_names(void)
{
	if(head == NULL)
	{
		printf("\nNo Records Found\n");
	}
	else
	{
		struct node *temp = head;
		printf("\n\nThe List is: ");
		while(temp->next != NULL)
	{
			printf("\nFirst Name: %s\nLast Name: %s\nPhone Number: %d \n",temp->firstName,temp->lastName,temp->number);
			temp = temp->next;
		}
		printf("\nFirst Name: %s\nLast Name: %s\nPhone Number: %d ",temp->firstName,temp->lastName,temp->number);
	}
}


void removeSpecific()
{
	char enterName[20];
	struct node *temp1 =head,*temp2 = NULL;
	printf("Enter name to be deleted: ");
	scanf("%s",&enterName);
	for( temp1; temp1->next != NULL;temp1 = temp1->next)
	{
		if(strcmp(enterName,temp1->firstName) == 0)// Finding the node
		{
			break;
		}
		temp2 = temp1;
	}
	  if ( temp1 != NULL )// Removing the node
   {
      if ( temp1 == head )
      {
         head = temp1->next;
      }
      else
      {
         temp2->next = temp1->next;
      }
	}
	free(temp1);// Deleting temp1
	printf("One Record Deleted");
	
}

void LoadFromFile(FILE *f)
{
			char characters[50];
			while(fscanf(f,"%s",characters))
			{
				puts(characters);
			};
			fclose(f);// Closing File
}

void AddToFile(FILE *fw)
{
	char firstWriteName[20],lastWriteName[20],numWr[20],inputFirstName[20];
	if(fw == NULL)
		   {
		      printf("Error in opening file");   
		      exit(1);             
		   }
			else{
				while(strcmp(inputFirstName,"end") != 0)
				{
					printf("Enter first Name : ");
					scanf("%s",firstWriteName);
					if(strcmp(firstWriteName,"end")==0){break;}
					else{
						fprintf(fw,"------------------\n",0);
						fprintf(fw,"Firstname:%s\n",firstWriteName);
						printf("Enter Last Name : ");
						scanf("%s",lastWriteName);
						fprintf(fw,"Lastname:%s\n",lastWriteName);
						printf("Enter Phone Number : ");
						scanf("%s",numWr);
						fprintf(fw,"Number:%s\n",numWr);
					}
				}
			fclose(fw);
	}
}
