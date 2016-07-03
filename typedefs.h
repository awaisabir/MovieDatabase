#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_SIZE 64
#define MAX_CAST_SIZE 2
#define C_OK 1
#define C_NOK -1

enum MovieGenre{
	Comedy = 1,
	Action = 2,
	Fantasy = 3,
	Horror = 4,
	Romance = 5,
	Thriller = 6,
};

typedef struct {
	char title[MAX_STR_SIZE];
	int year;
	enum MovieGenre genre;
	char castMembers[MAX_CAST_SIZE][MAX_STR_SIZE];
} Movie;

typedef struct Node{
	Movie *data;
  struct Node *next;
	struct Node *prev;
} NodeType;


typedef struct {
	NodeType *head;
	NodeType *tail;
} DblList;

void dl_init(DblList*);
void dl_add(DblList*, Movie*);
void dl_del(DblList*, Movie*);
void dl_printFwd(DblList*);
void dl_printBack(DblList*);
void dl_printByGenre(DblList*, enum MovieGenre);
void dl_cleanup(DblList*);

void createMovie(char *t, int y, enum MovieGenre mg, char *c, char *c2, Movie **newMovie);
void clearSTDIN(void);
