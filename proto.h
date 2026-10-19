#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

struct album {
  char * title;
  char * artist;
  int tracks;
};

int accesses;
int recNum;
int databaseSize;

struct album *library; //after messing around for far too long I realized a lot of my issues were solved if I didn't have to pass the library pointer in to every function, and then deal with all the function nesting
struct album *head;
struct album *mover;

void loadAlbum();

void startDatabase() {
  loadAlbum("Tommy", "The Who", 24, library);
  library++;

  loadAlbum("Back in Black", "AC/DC", 10, library);
  library++;

  loadAlbum("London Calling", "The Clash", 19, library);
  library++;
  
  loadAlbum("Appetite for Destruction", "Guns and Roses", 12, library);
  library++;

  loadAlbum("Led Zeppelin IV", "Led Zeppelin", 8, library);

  library = head;
  recNum = 5;
}
