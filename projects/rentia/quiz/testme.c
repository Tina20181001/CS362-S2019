/* CS362 Random testing quiz
 * Name: Tianshu Ren
 * Date: May 12, 2019
 * Description: This is the random testing quiz from CS362.
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


char inputChar()
{
    int i;
    i = rand() % 9; //generate i from 0 to 8
    char c = 0;
    char inputArray[9] = {'[', '(', '{', ' ', 'a', 'x', '}', ')', ']'};//define array which contain 9 elements
    c = inputArray[i];//give inputArray[i] to c
    return c;
}

char *inputString()
{
    int i;
    int index;
    int value;
    char *s = malloc(sizeof(char)*value);
    value = (rand() % 6); //generate value from 0 to 5
    char string[6] = "rest"; //declare string

    //check situation for different string  s size
    for (i=0; i < value; i++) {
        index = rand() % 4; // generate value 0 to 3
        s[i] = string[index]; //give string[index] to s
    }
    s[value] = '\0'; // Null terminator to end of string.
    return s;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}

