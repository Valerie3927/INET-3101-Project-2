#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "proto.h"

void printAll() {
  printf(":: Music Library ::\n\n");
  for (int i = 0; i < recNum; i++) {
    printf(":: Album: %s ::\n", mover->title);
    printf(":: Artist: %s ::\n", mover->artist);
    printf(":: This Album has %d tracks ::\n\n", mover->tracks);
    mover++;
  }
  mover = head;
}

void loadAlbum(char * title, char * artist, int tracks, struct album * dest) {
  fprintf(stderr, ":: %s ::\n", title);
  fprintf(stderr, ":: %d ::\n", strlen(title));
  dest->title = malloc(strlen(title));
  memcpy(dest->title, title, strlen(title));
  fprintf(stderr, ":: %s ::\n", dest->title);
  fprintf(stderr, ":: %s ::\n", artist);
  fprintf(stderr, ":: %d ::\n", strlen(artist));
  dest->artist = malloc(strlen(artist));
  memcpy(dest->artist, artist, strlen(artist));
  fprintf(stderr, ":: %s ::\n", dest->artist);
  dest->tracks = tracks;
  fprintf(stderr, ":: %d ::\n", dest->tracks);
}
/*
void addRec() {
  recNum++;
  accesses++;
}
*/
void addRec() {
  int i, k;
  char *line = malloc(100);
  size_t linec = 0;
  struct album * temp = malloc(sizeof(temp));
  printf("Enter the album name: ");
  i = getline(&line, &linec, stdin);
  if (i == -1) {
    perror("Line Failed to Read :: ");
  } else {
    temp->title = malloc(strlen(line-1));
    memcpy(temp->title, line, strlen(line-1));
    printf("Enter the artist name: ");
    i = getline(&line, &linec, stdin);
    if (i == -1) {
      perror("Line Failed to Read :: ");
    } else {
      temp->artist = malloc(strlen(line-1));
      memcpy(temp->artist, line, strlen(line-1));
      printf("Enter the number of tracks: ");
      i = getline(&line, &linec, stdin);
      if (i == -1) {
        perror("Line Failed to Read :: ");
      } else {
        k = atoi(line);
        temp->tracks = k;
      }
    }
  }
  mover = head;
  recNum++;
  struct album *libTemp;
  libTemp = malloc((recNum) * sizeof(libTemp));
  fprintf(stderr, "libTemp constructed\n");
  for (i = 0; i < recNum-1; i++) {
    char *tempTitle = mover->title;
    fprintf(stderr, "Mover->title points to: %s\n", mover->title);
    fprintf(stderr, "tempTitle points to: %s\n", tempTitle);
    char *tempArtist = mover->artist;
    loadAlbum(tempTitle, tempArtist, mover->tracks, libTemp);
    libTemp++;
    mover++;
  }
  loadAlbum(temp->title, temp->artist, temp->tracks, libTemp);
  library = libTemp;
  head = library;
  mover = library;

  accesses++;
}

void delRec() {
  recNum--;
  accesses++;
}

int accessNum() {
  return(accesses);
}

void menu() {
  int sel, enter;

  printf("MENU\n\n");
  printf("1. Print all Albums\n");
  printf("2. Print number of Albums\n");
  printf("3. Print size of Database\n");
  printf("4. Add Album\n");
  printf("5. Delete Album\n");
  printf("6. Print Number of Accesses to Database\n");
  printf("7. Exit\n\n");
  printf("Enter Selection: ");
  sel = getchar() - 48; //subtracting 48 from the entered selection turns it from ASCII for a number into that integer
  enter = getchar();
  switch(sel) {
    case 1:
      printAll();
      break;
    case 2:
      printf("There are %d albums in this Database\n\n", recNum);
      break;
    case 3:
      printf("The Database is %d bytes\n\n", (recNum * sizeof(head)));
      break;
    case 4:
      addRec();
      break;
    case 5:
      delRec();
      break;
    case 6:
      printf("Database has been Accessed %d times\n\n", accesses);
      break;
    case 7: exit(0);
      break;
  }
}
