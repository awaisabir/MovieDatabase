#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "typedefs.h"

//Function to initialize the list
void dl_init(DblList *dlist)
{
	dlist->head = NULL;
	dlist->tail = NULL;
}

//Function to add into the list
void dl_add(DblList *dlist, Movie *newMovie)
{
	NodeType *currentNode;
	NodeType *prevNode;
	NodeType *newNode;

	newNode = malloc(sizeof(NodeType));
	newNode->data = newMovie;
	newNode->next = NULL;
	newNode->prev = NULL;

	currentNode = dlist->head;
	prevNode = NULL;

	int check = 0;
	
	//cycle through the list
	while(currentNode != NULL)
	{
		if(strcmp(currentNode->data->title, newNode->data->title) > 0)
			break;

		//if the titles are the same, then promp the user that the movie has already been added
		if(strcmp(currentNode->data->title, newNode->data->title) == 0)
		{
			check = 1;
			printf("You can not add the same movie");
			break;
		}
		prevNode = currentNode;
		currentNode = currentNode->next;
	}
	
	//if movie is not the same title then add it into the list
	if(check == 0)
	{
	//if adding onto the head
		if(prevNode == NULL)
			dlist->head = newNode;
		
		else {
			prevNode->next = newNode;
		}
		newNode->prev = prevNode;
		newNode->next = currentNode;
		
		//if not the end then change the pointers
		if(currentNode != NULL)
			currentNode->prev = newNode;
	
		//if the end then make the new added node the tail
		if(newNode->next == NULL)
			dlist->tail = newNode;
	}
}
	
//Function to delete a node
void dl_del(DblList *dlist, Movie *newMovie)
{
	NodeType *currNode = dlist->head;
  NodeType *prevNode = NULL;

	//if list is empty then prompt
	if (currNode == NULL)
		printf("\n\nTHE LIST IS EMPTY. YOU CANNOT DELETE FROM AN EMPTY LIST\n\n");

	else{
		//cycle through the list
	 	while (currNode != NULL)
		{	 
				//if the same title then break from the loop
	  	 if(strcmp(currNode->data->title, newMovie->title) == 0)
	  	   break;

	    prevNode = currNode;
	 	  currNode = currNode->next;
	  }
	
		//if cycled and could not find the movie then prompt
	  if (currNode == NULL)
	  	 printf("\n\nThe Movie could not be found\n\n");

		else {
			//if removing head then make the next node the new head
	  	if (prevNode == NULL) {
	  	  dlist->head = currNode->next;
	  	} 
	  	else {
	  	  prevNode->next = currNode->next;
	  	} 
		
			//if anywhere in the middle then make the next node the currentNode
	  	if (currNode->next != NULL) {
	  	  currNode->next->prev = prevNode;
	  	}
			//if tail then make the previousnode the tail
			else 
				dlist->tail = prevNode;
	
  		free(currNode->data);
  		free(currNode);
		}
	}
}

//Function to print the list from head to tail
void dl_printFwd(DblList *dlist)
{
	NodeType *currentNode;
	currentNode = dlist->head;

	char temp[MAX_STR_SIZE];

	//cycle through the list from head to tail
	while(currentNode != NULL)
	{	
		//switch statement to dwitch the values based on the numbers in the enumerated struct
		switch(currentNode->data->genre)
			{
				case 1: 
					strcpy(temp, "Comedy");
					break;
				case 2:
					strcpy(temp, "Action");
					break;
				case 3:
					strcpy(temp, "Fantasy");
					break;
				case 4:
					strcpy(temp, "Horror");
					break;
				case 5:
					strcpy(temp, "Romance");
					break;
				case 6:
					strcpy(temp, "Thriller");
				break;
				
				default:
				break;
			}
		//print the information of the node
		printf("\nThe Movie is: %s\nThe year is: %d\nThe genre is: %s\nThe Cast Member One is: %s\nThe Cast Member Two is: %s\n",
         		currentNode->data->title, 
						currentNode->data->year,
						temp,
						currentNode->data->castMembers[0],
						currentNode->data->castMembers[1]);

			currentNode = currentNode->next;
		}
	
	printf("\n-----------This is the end of the list---------------\n");
	
}

//Function to print from the tail to the head
void dl_printBack(DblList *dlist)
{
	NodeType *currentNode;
	currentNode = dlist->tail;
	
	char temp[MAX_STR_SIZE];
	
	//cycle from tail to head
	while(currentNode != NULL)
	{
		//switch statement to dwitch the values based on the numbers in the enumerated struct
		switch(currentNode->data->genre)
		{
			case 1: 
				strcpy(temp, "Comedy");
				break;
			case 2:
				strcpy(temp, "Action");
				break;
			case 3:
				strcpy(temp, "Fantasy");
				break;
			case 4:
				strcpy(temp, "Horror");
				break;
			case 5:
				strcpy(temp, "Romance");
				break;
			case 6:
				strcpy(temp, "Thriller");
				break;
			
			default:
				break;
			}
		//Print the info of the node
		printf("\nThe Movie is: %s\nThe year is: %d\nThe genre is: %s\nThe Main Character is: %s\nThe Supporting  is: %s\n",
       		currentNode->data->title, 
					currentNode->data->year,
					temp,
					currentNode->data->castMembers[0],
					currentNode->data->castMembers[1]);

			currentNode = currentNode->prev;	 
		}

	printf("\n-----------This is the end of the list---------------\n");
}

//Function to initialize the movie
void createMovie(char *t, int y, enum MovieGenre mg, char *c, char *c2, Movie **newMovie)
{
	(*newMovie) = malloc(sizeof(Movie));
	strcpy((*newMovie)->title, t);
	(*newMovie)->year = y;
	(*newMovie)->genre = mg;
	strcpy((*newMovie)->castMembers[0], c);
	strcpy((*newMovie)->castMembers[1], c2);
}

//Function to print by the genre
void dl_printByGenre(DblList *dlist, enum MovieGenre genre)
{
	NodeType *currentNode;
	currentNode = dlist->tail;

	char temp[MAX_STR_SIZE];
	int check = 0;
	//cycle through the nodes tail to head
	while(currentNode != NULL)
	{
		switch(currentNode->data->genre)
		{
			case 1: 
				strcpy(temp, "Comedy");
				break;
			case 2:
				strcpy(temp, "Action");
				break;
			case 3:
				strcpy(temp, "Fantasy");
				break;
			case 4:
				strcpy(temp, "Horror");
				break;
			case 5:
				strcpy(temp, "Romance");
				break;
			case 6:
				strcpy(temp, "Thriller");
				break;
			
			default:
				break;
		}
		//if the movies with the same genre are found then print them out
		if(currentNode->data->genre == genre)
			{
				check = 1;
				
				printf("\nThe Movie(s) of that genre we have are : %s\nThe year is: %d\nThe Cast Member One is: %s\nThe Cast Member Two is: %s\n",
            currentNode->data->title, 
						currentNode->data->year,
						currentNode->data->castMembers[0],
						currentNode->data->castMembers[1]);
			}
		
		currentNode = currentNode->prev;		
	}
		//if check is 0 then prompt the user that the genre does not exist
		if(check == 0)
			printf("\nThat genre does not exist\n\n");
}

//Function to cleanup everything
void dl_cleanup(DblList *dlist)
{
	NodeType *currentNode = dlist->head;
	NodeType *nextNode;

	//cycle through the list and clear everything
	while(currentNode != NULL)
	{
		nextNode = currentNode->next;
		free(currentNode->data);
		free(currentNode);
		currentNode = nextNode;
	}
	free(dlist);
}

//Function to clear lines of the Scanf
void clearSTDIN(void)
{
    int c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
