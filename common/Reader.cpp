#include "Reader.h"

Reader::Reader() {
  tape = NULL;
  tapeRemark = false;
  }

Reader::~Reader() {
  }

Byte Reader::translate(Byte in) {
  if (in >= 'a' && in <= 'z') in -= 32;
  switch (in) {
    case 'P': return 0;
    case 'Q': return 1;
    case 'W': return 2;
    case 'E': return 3;
    case 'R': return 4;
    case 'T': return 5;
    case 'Y': return 6;
    case 'U': return 7;
    case 'I': return 8;
    case 'O': return 9;
    case 'J': return 10;
    case '#': return 11;
    case 'S': return 12;
    case 'Z': return 13;
    case 'K': return 14;
    case '*': return 15;
    case '.': return 16;
    case 'F': return 17;
    case '@': return 18;
    case 'D': return 19;
    case '!': return 20;
    case 'H': return 21;
    case 'N': return 22;
    case 'M': return 23;
    case '&': return 24;
    case 'L': return 25;
    case 'X': return 26;
    case 'G': return 27;
    case 'A': return 28;
    case 'B': return 29;
    case 'C': return 30;
    case 'V': return 31;
    case '0': return 0;
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    }
  return 255;
  }

Boolean Reader::Mount(char* filename) {
  if (tape != NULL) fclose(tape);
  tape = fopen(filename, "r");
  if (tape == NULL) return false;
  return true;
  }

Byte Reader::Read() {
  Byte  i;
  Int32 count;
  char  flag;
  flag = 'N';
  while (flag == 'N') {
    count = 0;
    if (tape) {
      count = fread(&i,1,1,tape);
      if (count == 0) {
        fclose(tape);
        tape = NULL;
        }
      }
    if (count == 0) count = read(0,&i,1);
    if (count != 0) {
      if (i == '[') tapeRemark = true;
      else if (i == ']') tapeRemark = false;
      else if (!tapeRemark) {
        i = translate(i);
        if (i != 255) flag = 'Y';
        }
      } else flag = '*';
    }
  if (flag == 'Y') return i;
  return 255;
  }

