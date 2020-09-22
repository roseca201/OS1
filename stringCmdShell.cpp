#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "util.h"
/**
 *
 *
 * @author <Christopher Rose>
 * @email roseca201@potsdam.edu
 */


// Define a type for easy replacement
typedef int LString;
// Program CONSTANTS
const int MAX_STRING_COUNT = 10;

// Function forward declarations
/**
 * Is the given LString index valid?
 *
 * @param ndx index to check for validity
 * @return true if in safe index range; false otherwise
 */
bool isValidStringNdx(int ndx);

/**
 * Generate and print the prompt.
 *
 * @param strings array of ints; prompt includes indices
 * of non-empty strings so that list is checked here
 * @note Should generate and return the prompt string;
 * a function should have exactly ONE concern.
 */
void prompt(LString strings[MAX_STRING_COUNT]);
  
/**
 * Read one command parameter startinng at start.
 * The parameter is the next non-blank character.
 *
 * @param start pointer into null-terminated string to
 * find command parameter in.
 * @param first REFERENCE to char pointer; will point to
 * parameter, if one is found.
 * @return true with first set if non-blank found at or
 * after start; false with first left unchanged otherwise.
 */
bool readOneMore(char * start, char * & first);

/**
 * Read two command parameter startinng at start.
 * The parameter is the next non-blank character;
 * second parameter can be an escaped character.
 *
 * @param start pointer into null-terminated string to
 * find command parameter in.
 * @param first REFERENCE to char pointer; will point to
 * first parameter, if one is found.
 * @param second REFERENCE to char pointer; will point to
 * second parameter, if one is found.
 * @return true with first set if non-blank found at or
 * after start; false with first left unchanged otherwise.
 */
bool readTwoMore(char * start, char * & first, char * & second);

/**
 * Get pointer at next non-blank character UNLESS that
 * character is '\'. In that case, return pointer at the
 * character AFTER the slash (does not translate \n, etc.).
 *
 * @param start pointer at beginning of string to search
 * @return pointer at '\0', character after '\',
 * or next non-blank, whichever is found first.
 */
char * nextCharMaybeEscaped(char * start);

/**
 * Show help text
 * FIXME !
 */
void generalHelp();


/**
 * Show specific help text.
 * FIXME !
 *
 * @param cmdForHelp the command character to provide help on.
 */
void help(char cmdForHelp);

int newNode();

void delNode(int ndx);
  
// =========== LString Provider must rewrite these functions ==========
/**
 * Initialize the given LString, however that is done.
 *
 * @parm REFERENCE to an LString that must be initialized
 */
void init(LString & str);

/**
 * Is the LString empty?
 *
 * @param the LString to check for emptiness.
 */
bool isEmpty(LString str);
 
/**
 * The main function.
 *
 * @param argc - # of command-line arguments
 * @param argv - array of command-line arguments
 * @return 0 on termination
 */
int main(int argc, char *argv[]) {
  LString theStrings[MAX_STRING_COUNT];
  int pool[64];
  for (int n = 0; n < MAX_STRING_COUNT; ++n)
    init(theStrings[n]);

  bool done = false;
  while (!done) {
    // Input line from the user
    char line[80];

    // prompt and read line
    prompt(theStrings);
    done = (fgets(line, 80, stdin) == NULL);

    if (done)
      continue;

    // echo input if input is redirected from a file
    if (isInputRedirected())
      printf("%s", line);

    line[strlen(line) - 1] = '\0'; // chop EOLN with NULL (make line shorter)
    char * cmdChar = unMatch(line, ' ');
    if (*cmdChar == '\0')
      continue; // line contains only spaces

    if (*cmdChar == 'q') {
      done = true;
    } else if (*cmdChar == 'a') {
      char * list;
      char * ch;
      if (!readTwoMore(cmdChar + 1, list, ch)) {
        // FIXME error messagee
        continue;
      }
      int ndx = *list - '0';
      if (!isValidStringNdx(ndx)) {
        printf("%c is not a valid index.\n", ndx);
        continue;
      }
	  ndx = newNode();
	  pool[ndx].ch = *ch;
    //  printf("%c %c %c - Command not implemented.\n", *cmdChar, *list, *ch);
    } else if (*cmdChar == 'r') {
      char * list;
      char * ch;
      if (!readTwoMore(cmdChar + 1, list, ch)) {
        // FIXME error messagee
        continue;
      }
      int ndx = *list - '0';
      if (!isValidStringNdx(ndx)) {
        printf("%c is not a valid index.\n", ndx);
        continue;
      }
	  int curr = pool[free].ch
	  while(pool[free].next != -1) {
		  if (curr = *ch) {
			  delNode(curr);
		  } else {
			  curr = pool[pool[free].next].ch;
		  }
	  }
    //  printf("%c %c %c - Command not implemented.\n", *cmdChar, *list, *ch);
    } else if (*cmdChar == 'e') {
      char * list;
      if (!readOneMore(cmdChar + 1, list)) {
        // FIXME error messagee
        continue;
      }
      int ndx = *list - '0';
      if (!isValidStringNdx(ndx)) {
        printf("%c is not a valid index.\n", ndx);
        continue;
      }
	  int curr = pool[free].ch
	  while(pool[free].next != -1) {
			  delNode(curr);
			  curr = pool[pool[free].next].ch;
		  }
	  }
      // printf("%c %c - Command not implemented.\n", *cmdChar, *list);
    } else if (*cmdChar == 'c') {
      char * listA;
      char * listB;
      if (!readTwoMore(cmdChar + 1, listA, listB)) {
        // FIXME error messagee
        continue;
      }
      int ndxA = *listA - '0';
      if (!isValidStringNdx(ndxA)) {
        printf("%c is not a valid index.\n", ndxA);
      }
      int ndxB = *listB - '0';
      if (!isValidStringNdx(ndxB)) {
        printf("%c is not a valid index.\n", ndxB);
      }
	  int curr = pool[free].ch
		  while(pool[free].next != -1) {
			  curr = pool[pool[free].next].ch;
		  }
		  pool[ndxA].next = pool[ndxB].ch;
		  init(listB);
      // printf("%c %c %c - Command not implemented.\n", *cmdChar, *listA, *listB);
    } else if (*cmdChar == 'l') {
		int curr = pool[free].ch
		for (int i = 0; i < MAX_STRING_COUNT; i++) {
			while (pool[free].next != -1) {
				printf("%c", curr);
				curr = pool[pool[free].next].ch;
			}
			printf(" .\n");
		}
     // printf("%c - Command not implemented.\n", *cmdChar);
    } else if (*cmdChar == 'f') {
		for (int i = 0; i < 64; i++) {
			printf("[%c]", pool[i].next);
		}		
      //printf("%c - Command not implemented.\n", *cmdChar);
    } else if (*cmdChar == 'h') {
      char * aboutChar = unMatch(cmdChar+1, ' ');
      if (*aboutChar == '\0' ) {
        generalHelp();
      } else {
        help(*aboutChar);
      }
    } else {
      printf("Unrecognized command character, \"%c\". \"h\" for help.\n", *cmdChar);
    }
  }
}

// I'm working here
int newNode() {
	int node = free;
	free = pool[free].next
	return node;
}

void delNode(int ndx) {
	pool[ndx].next = free;
	free = ndx;
}

// ----- LString Provider Update! -----
// initialize an LString
void init(LString & str) {
  str = -1;
}

// check whether LString is empty
bool isEmpty(LString str) {
  return str = ' ';
}


// display general help
void generalHelp() {
  printf("[a]dd         list: add a char to the end.\n");
  printf("[r]emove      list: remove first matching char.\n");
  printf("[e]mpty       list: release all nodes from list.\n");
  printf("[c]oncat      list list: concatenate the two lists.\n");
  printf("[l]ist        print all non-empty lists.\n");
  printf("[f]ree nodes  print free-list node numbers.\n");
  printf("[h]elp        print this help.\n");
  printf("[q]uit        quit program.\n");
  printf("h [c]         give specific help on command c.\n");
}

// display command-specific help (or error message)
void help(char cmdForHelp) {
  printf("<<< SPECIALIZED HELP TEXT (%c) >>>\n", cmdForHelp);
  if (cmdForHelp = 'a') {
	  printf("add a char to a given string\n");
	  printf("a n c\n");
	  printf("n is a number 0-9, which linked list to append to\n");
	  printf("c is a single character right after a single space\n");
  } else if (cmdForHelp = 'r') {
	  printf("remove a char in a given string\n");
	  printf("r n c\n");
	  printf("n is a number 0-9, which linked list to remove from\n");
	  printf("c is a single character right after a single space\n");
	  printf("lists each string in each linked list\n");
  } else if (cmdForHelp = 'e') {
	  printf("empties each array\n");
      printf("e n\n");
	  printf("n is a number 0-9, which linked list to remove from\n");
  } else if (cmdForHelp = 'c') {
	  printf("concatenate two lists; second list nulled\n");
      printf("c n m\n");
	  printf("n is a first list number\n");
	  printf("m is a second list number\n");
	  printf("String n should be n followed by m; m nulled out.\n");
  } else if (cmdForHelp = 'f') {
	  printf("prints free-list node numbers.\n");
  } else if (cmdForHelp = 'q') {
	  printf("quits the program\n");
  }
}

// ----- Utility Functions -----
// is ndx valid string index?
bool isValidStringNdx(int ndx) {
  return (0 <= ndx) && (ndx < MAX_STRING_COUNT);
}

// generate and display a prompt w/ list of non-empty LString
void prompt(LString strings[MAX_STRING_COUNT]) {
  printf("Non-empty Lists :: ");
  bool anyNonEmpty = false;
  for (int i = 0; i < MAX_STRING_COUNT; ++i) {
    if (!isEmpty(strings[i])) {
      printf("%d", i);
      anyNonEmpty = true;
    }
  }
  if (anyNonEmpty)
    printf(" ");

  printf(":: cmd? ");
}

// ----- I/O Routines -----
// read a possibly escaped space or other char. NOT \n,\r,\t, etc.
char * nextCharMaybeEscaped(char * start) {
  char * ch = unMatch(start, ' ');
  if (*ch == '\\')
    ch++;
  return ch;
}

// could we read (and store) one more character parameter?
bool readOneMore(char * start, char * & first) {
  first = unMatch(start, ' ');
  return *first;
}

// could we read (and store) two more character parameters? Second might be escaped.
bool readTwoMore(char * start, char * & first, char * & second) {
  first = unMatch(start, ' ');
  if (*first != '\0')
    second = nextCharMaybeEscaped(first+1);
  return *first && *second;
}
