#include <stdio.h>
#include "functions.h"

void main() {
  head = malloc(sizeof(head));
  head->title = malloc(100);
  head->artist = malloc(100);
  mover = malloc(sizeof(mover));
  mover->title = malloc(100);
  mover->artist = malloc(100);
  library = malloc(5 * sizeof(library));
  head = library;
  mover = library;
  startDatabase();
  int cont = 121;
  int enter;
  while(cont == 121) {
    menu();
    printf("Would you like to continue? [y/n] ");
    cont = getchar();
    enter = getchar();
    while(enter != 10) {
      enter = getchar();
    }
    printf("\n");
  }
  free(library);
}
