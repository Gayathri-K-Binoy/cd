#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[50];
int pos = 0;

// Function declarations
void E();
void E_();
void T();
void T_();
void F();
void advance() { pos++; }

// ---------------- PARSER FUNCTIONS ----------------

void E() {
  printf("E -> T E'\n");
  T();
  E_();
}

void E_() {
  if (input[pos] == '+') {
    printf("E' -> + T E'\n");
    advance();
    T();
    E_();
  } else {
    printf("E' -> ε\n");
  }
}

void T() {
  printf("T -> F T'\n");
  F();
  T_();
}

void T_() {
  if (input[pos] == '*') {
    printf("T' -> * F T'\n");
    advance();
    F();
    T_();
  } else {
    printf("T' -> ε\n");
  }
}

void F() {
  if (input[pos] == 'i') {
    printf("F -> i\n");
    advance();
  } else if (input[pos] == '(') {
    printf("F -> (E)\n");
    advance();
    E();
    if (input[pos] == ')')
      advance();
    else {
      printf("Error: expected ')'\n");
      exit(1);
    }
  } else {
    printf("Error: invalid symbol '%c'\n", input[pos]);
    exit(1);
  }
}

// ---------------- MAIN FUNCTION ----------------
int main() {
  printf("Grammar:\n");
  printf(
      "E -> T E'\nE' -> + T E' | ε\nT -> F T'\nT' -> * F T' | ε\nF -> (E) | "
      "i\n\n");

  printf("Enter expression: ");
  scanf("%s", input);

  printf("\nDerivations:\n");
  E();

  if (input[pos] == '\0')
    printf("\nParsing successful!\n");
  else
    printf("\nSyntax error at '%c'\n", input[pos]);

  return 0;
}
