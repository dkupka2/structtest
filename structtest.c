/* here we go with a struct memory allocation test */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct foo Foo_t;

typedef struct bar Bar_t;

struct foo {
  int x;
  char fee[999];
};

struct bar {
  int y;
  char bee[999];
};

int main(void) {

  Foo_t *left = malloc( 1 * sizeof(Foo_t) );
  Bar_t *lisa = malloc(256 * sizeof(Bar_t) );

  if (left == NULL) {
    printf("Unable to allocate, try to make it right\n");
    return -1;
  }

  if (lisa == NULL) {
    printf("Aye carumba!  Don't have a cow, man!\n");
    return -1;
  }

  strcpy(left->fee, "tee"); 
  strcpy(lisa->bee, "mee");

  printf("left->fee: %s\n", left->fee);
  printf("lisa->bee: %s\n\n", lisa->bee);

  strcpy(left[0].fee, "whoa,");
  strcpy(lisa[0].bee, "there!");
  strcpy(left[1].fee, "this should not work,"); /* undefined behavior - may work, may cause issues or crash */
  strcpy(lisa[1].bee, "but this might?");

  printf("new left->fee: %s\n", left->fee);
  printf("new lisa->bee: %s\n", lisa->bee);
  printf("left[1].fee: %s\n", left[1].fee); /* undefined behavior - may work, may cause issues or crash */
  printf("lisa[1].bee: %s\n", lisa[1].bee);

  return 0;
}
