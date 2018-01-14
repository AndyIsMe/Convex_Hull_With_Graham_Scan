#include "nodeverifier.h"
#include "unity.h"
#include <stdarg.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>


char *createMessage(char *message, ...){
  va_list args;
  char *buffer;
  int length;

  va_start(args,message);

  length = vsnprintf(buffer, 0, message, args);
  buffer = malloc(length+1);
  vsnprintf(buffer, length+1, message, args);

  return buffer;
}

void testAssertEqualNode(int x , int y, char *place, Point *points,int lineNo){
  char *error;
  if(x != points->x){
      error = createMessage("Expected x to be %d, but was %d",  \
                            points->x,x);
      UNITY_TEST_FAIL(lineNo,error);
    }
    else if(strcmp(place,points->place)==1){
        error = createMessage("Expected string to be %s, but was %s",  \
                              points->place,place);
      UNITY_TEST_FAIL(lineNo,error);
    }
  else if(y != points->y){
      error = createMessage("Expected y to be %d, but was %d",  \
                            points->y,y);
    UNITY_TEST_FAIL(lineNo,error);
    }


}
