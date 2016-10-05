#include <stdlib.h>
#include <stdio.h>

int mystrlen(char *c) {
  int s = 0;
  while (c[s]) {
    s += 1;
  }
  return s;
}

char * mystrncpy(char *dest, char *src, int n) {
  int c = 0;
  while(c < n) {
    if (c >= mystrlen(src)) {
      dest[c] = 0;
    } else {
      dest[c] = src[c];
    }
    c++;
  }
  return dest;
}

char * mystrcpy(char *dest, char *src) {
  return mystrncpy(dest, src, mystrlen(src)+2);
}

char * mystrncat(char *dest, char *src, int n) {
  int c = 0;
  while(c < n) {
    printf("mystrncat 3 of source onto dest: %s\n", dest);
    if (c >= mystrlen(src)) {
      dest[c + mystrlen(dest)] = 0;
    } else {
      dest[c + mystrlen(dest)] = src[c];
    }
    c++;
  }
  return dest;
}


int main() {
  printf("strlen of 'systems': %d\n", mystrlen("systems"));
  char a[] = "source";
  char b[] = "dest";
  char c[] = "dest";
  mystrncpy(b, a, 3);
  mystrcpy(c, a);
  printf("strncpy 4 of source into dest: %s\n", b);
  printf("strcpy source into dest: %s\n", c);

  char d[] = "source";
  char e[20] = "dest";
  mystrncat(e, d, 3);
  printf("mystrncat 3 of source onto dest: %s\n", e);
  return 0; 
}
