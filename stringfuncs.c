#include <stdlib.h>
#include <stdio.h>
#define MIN(a,b) (((a)<(b))?(a):(b))

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
    //printf("%c\n", dest[c]);
    c++;
  }
  // printf("%s", dest);
  return dest;
}

char * mystrcpy(char *dest, char *src) {
  return mystrncpy(dest, src, mystrlen(src)+2);
}

char * mystrncat(char *dest, char *src, int n) {
  int c = 0;
  int destlen = mystrlen(dest);
  while(c < n) {
    //printf("%s\n", dest);
    if (c >= mystrlen(src)) {
      dest[c + destlen] = 0;
    } else {
      dest[c + destlen] = src[c];
    }
    c++;
  }
  return dest;
}

char * mystrcat(char *dest, char *src) {
  return mystrncat(dest, src, mystrlen(src));
}

int mystrcmp(char *s1, char *s2) {
  int min = MIN(mystrlen(s1), mystrlen(s2));
  int i = 0;
  while(i < min) {
    if (s1[i] != s2[i]) {
      return s1[i] - s2[i];
    }
    i++;
  }
  return 0;
}

char * mystrchr(char *s, int c) {
  int i = 0;
  while(i < mystrlen(s)) {
    if (s[i] == c) {
      return &s[i];
    }
    i++;
  }
  return NULL;
}

int main() {
  printf("\nSTRLEN\nstrlen of 'systems': %d\n", mystrlen("systems"));
  char a[] = "source";
  char b[] = "dest";
  char c[] = "dest";
  printf("\n//STRNCPY AND STRCPY\na: %s\nb: %s\nc: %s\n", a, b, c);
  printf("b after strncpy 4 of a: %s\n", mystrncpy(b, a, 4));
  printf("c after strcpy of a: %s\n", mystrcpy(c, a));

  char d[] = "source";
  char e[20] = "dest";
  char f[20] = "dest";
  printf("\nSTRNCAT AND STRCAT\nd: %s\ne: %s\nf: %s\n", d, e, f);
  printf("e after strncat 5 of d: %s\n", mystrncat(e, d, 5));
  printf("f after strcat of d: %s\n", mystrcat(f, d));

  char g[] = "abcde";
  char h[] = "abcde";
  char i[] = "abcdz";
  printf("\nSTRCMP\ng: %s\nh: %s\ni: %s\n", g, h, i);
  printf("g strcmp h: %d\n", mystrcmp(g, h));
  printf("h strcmp i: %d\n", mystrcmp(h, i));
  printf("i strcmp h: %d\n", mystrcmp(i, h));

  char j[] = "abcde";
  printf("\nSTRCHR\nj: %s\n", j);
  printf("strchr 'd' in j: %p or %c\n", mystrchr(j, 'd'), *mystrchr(j, 'd'));
  
  return 0; 
}
