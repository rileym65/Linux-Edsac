#ifndef _READER_H
#define _READER_H

#include <stdio.h>

class Reader {
  protected:
    FILE*   tape;
    Boolean tapeRemark;
  public:
    Reader();
    ~Reader();
    Boolean Mount(char* filename);
    Byte    Read();
    Byte    Translate(Byte in);
  };

#endif

