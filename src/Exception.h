
#ifndef Exception_H
#define Exception_H
#include "CExceptionConfig.h"
#include "error.h"


typedef struct Exception Exception;
typedef Exception* ExceptionPtr;
struct Exception {
  char *msg;
  int  errorCode;
  void *data;
};

Exception *createException(char *msg, int errorCode);
void freeException(Exception *e);
void dumpException(Exception *e);
void throwException(int errorCode, void *data, char *message, ...);


#endif // Exception_H
