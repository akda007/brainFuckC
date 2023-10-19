#include <stdio.h>
#include <stdlib.h>

void execution(FILE *file, char c);
void loop(FILE *file, char c);

unsigned * cursor; 

void loop(FILE *file, char c) {
  int offset;
  while (*cursor != 0) {
    offset = 1;
    while((c = fgetc(file)) != ']' && c != EOF) {
      offset++;
      
      if (c == '\n') {
        continue;
      }

      execution(file, c);
    }

    if (c == EOF || *cursor == 0) {
      return;
    }

    fseek(file, -offset, SEEK_CUR);
  }
}

// Program execution
void execution(FILE *file, char c){
    switch (c) {
      case '+':
        if (*cursor == 255){
          *cursor = 0;
        } else {
          (*cursor)++;  
        }        
        break;
      case '-':
        if (*cursor == 0){
          *cursor = 255;
        } else {
          (*cursor)--;  
        } 
        break;
      case '>':
        cursor++;
        break;
      case '<':
        cursor--;
        break;
      case '.':
        printf("%c", *cursor);
        break;
      case ',':
        scanf("%c", cursor);
        break;
      case '[':
        loop(file, c);
      default:
        break;

    }

}


int main() {
  puts("Brainfuck C");

  FILE *file = fopen("code.bf", "r");

  int move_count = 0;

  unsigned c;
  while ((c = fgetc(file)) != EOF)  {
    if (c == '>') move_count++;
  }


  rewind(file);

  unsigned * mem = calloc(move_count * 2, sizeof(unsigned));
  cursor = mem;

  while ((c = fgetc(file)) != EOF) {
    execution(file, c);
  }

  free(mem);

  fclose(file);
  return 0;
}
