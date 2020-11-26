/*
   Simple attempt to move the cursor top-left (home),
   use colour, clear screen etc.
   Will only work on ANSI compliant terminals :
   https://en.wikipedia.org/wiki/ANSI_escape_code
   such as xterm, WSL etc.
*/

#include <stdio.h>
#include <time.h>

enum neillcol {black=30, red, green, yellow, blue, magenta, cyan, white};
typedef enum neillcol neillcol;

#define BACKGROUND 10

void neillclrscrn(void);
void neillcursorhome(void);
void neillfgcol(const neillcol c);
void neillbgcol(const neillcol c);
void neillreset(void);
void neillbusywait(const double secs);
