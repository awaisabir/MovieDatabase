#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "typedefs.h"

int main()
{
	//variables to handle the entered data
	int year = 0;
	int genre = 0;
	int num = 0;
 	int choice = 0;
 	int genreChoice = 0;
	int i;

	char title[MAX_STR_SIZE];
	char mainCharacter[MAX_STR_SIZE];
	char supportingRole[MAX_STR_SIZE];
	
	Movie *entered_movie;
	Movie *temp;

	//list instance and initialization
	DblList *movie_list;
	movie_list = malloc(sizeof(DblList));
	dl_init(movie_list); 


	while(1) 
	{
		//Opening Menu Options
		printf("\nChoose what you want to do:\n (1) Add movie(s)\n (2) Delete a movie\n (3) Print Forward\n (4) Print Backwards\n (5) Print by Genre\n (6) Exit\n");

		//Check if the entered value is within the number of options
		if (scanf("%d", &choice) != 1 || choice < 1 || choice > 6)
		{
			printf("\nEnter an integer of that range\n");
			dl_cleanup(movie_list);
			break;
		}	

	//alternate between the choices
		switch(choice) 
		{
			//case 1 (user wants to add)
			case 1:
	
 				printf("\nEnter the number of movies you want to add\n");
				if (scanf("%d", &num) != 1 || num < 1)
				{
					printf("\Enter a positive integer\n");
					dl_cleanup(movie_list);
					break;
				}
	
				/*loop through the number of movies entered
				 *ask the user to input all the info of the movie(s)
				*/
				for(i=0; i<num; i++) {
						clearSTDIN();
	
						printf("\nEnter a movie title for movie number %d:\n", i+1);
						fgets(title, sizeof(title), stdin);
						title[strlen(title)-1] = '\0';
	
						//Ask for the cast members (main character and supporting role)
						printf("\nEnter the main character of the movie:\n");
						fgets(mainCharacter, sizeof(mainCharacter), stdin);
						mainCharacter[strlen(mainCharacter)-1] = '\0';
		
						printf("\nEnter the supporting role of the movie:\n");
						fgets(supportingRole, sizeof(supportingRole), stdin);
						supportingRole[strlen(supportingRole)-1] = '\0';
		
						//ask for the year
						printf("\nEnter the year the movie was made:\n");
	
						if (scanf("%d", &year) != 1 || year < 1)
						{
							printf("\nPlease enter ONLY positive integers for the year\n");
							dl_cleanup(movie_list);
							return C_NOK;
						}
						
						//ask for the genre of the movie entered
						printf("\nSelect the genre your movie is in with using an integer:\n(1) Comedy\n(2) Action\n(3) Fantasy\n(4) Horror\n(5) Romance\n(6) Thriller\n");
						if (scanf("%d", &genre) != 1 || genre < 1 || genre > 6)
						{
							printf("\nEnter an integer in the range(s) 1 to 6\n");
							dl_cleanup(movie_list);
							break;
						}
					//create the instance of the movie based on he user input
					createMovie(title,year,genre,mainCharacter, supportingRole, &entered_movie);
					dl_add(movie_list, entered_movie);
				}	
			break;
			
			//case 2 (user wants to delete)
			case 2:
			
				clearSTDIN();
				
				//enter the title of the movie wanted to be deleted
				printf("\nEnter the title of the movie you want to delete (Must be the same as previous movies entered)\n");
				fgets(title, sizeof(title), stdin);
				title[strlen(title)-1] = '\0';
				createMovie(title, 0, 1, "nothing", "nothing", &temp);
	
				dl_del(movie_list, temp);
				free(temp);
				//dl_printFwd(movie_list);
			break;

			case 3: //print the list forward
					dl_printFwd(movie_list);
			break;
		
			case 4: //print the list backwards
				dl_printBack(movie_list);
			break;
		
			case 5: //print by genre

				clearSTDIN();

				printf("\nPlease select the genre:\n(1) Comedy\n(2) Action\n(3) Fantasy\n(4) Horror\n(5) Romance\n(6) Thriller\n");
				if (scanf("%d", &genreChoice) != 1 || genreChoice > 6 || genreChoice < 1)
				{
					printf("\nPlease enter an integer of that range\n");
					dl_cleanup(movie_list);
					return C_NOK;
				} 
						dl_printByGenre(movie_list, genreChoice);
				
			break;
		
			case 6: //exit out of the whole program
				dl_cleanup(movie_list);
				return C_NOK;
				break;
			}
		}	
	return C_OK;
}
