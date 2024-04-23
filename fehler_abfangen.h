#pragma once

#ifndef header_h
#define header_h

using namespace std;
#include<iostream>
#include<ctype.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define GROESSE 20

int pruefen_gueltig_integer(char[GROESSE]);
int pruefen_gueltig_float(char[GROESSE]);
int wandeln_integer(char[GROESSE]);
float wandeln_float(char[GROESSE]);

#endif // !header_h
