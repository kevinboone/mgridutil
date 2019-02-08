/*======================================================================
 * grid.c 
 * Maidenhead grid functions
 * Copyright (c)2019 Kevin Boone, GPL v3.0
 * =====================================================================*/
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include "defs.h" 
#include "grid.h" 
#include "gc.h" 


/*======================================================================
 * Convert a maidenhead grid location into lat/long. If there supplied
 *   grid string is invalid, return FALSE, and write **error. The caller
 *   must be prepared to free *error if the return is FALSE.
 * If only a four-character grid is supplied, "ll" is appended, to give
 *   a location towards the centre.
 * =====================================================================*/
BOOL grid_tolatlong (const char *_grid, double *lat, 
    double *longt, char **error)
  {
  int l = strlen (_grid);
  if (l != 4 && l != 6)
    {
    asprintf (error, "Grid locator must be four or six characters");
    return FALSE;
    }

  char grid[7];
  for (int i = 0; i < l; i++)
    {
    grid[i] = _grid[i];
    }
  grid[6] = 0;

  if (l == 4)
    {
    grid[4] = 'l';
    grid[5] = 'l';
    }

  double two = grid[1];
  two -= 65;
  two *= 10;

  double four = grid[3] - '0';

  double six = grid[5];
  six -= 97;
  six /= 24;
  six += 1.0/48;
  six -= 90;

  *lat = two + four + six; 

  double one = grid[0];
  one -= 65;
  one *= 20;

  double three = grid[2] - '0';
  three *= 2;
  double five = grid[4];
  five -= 97;
  five /= 12;
  five += 1.0/24;

  *longt = one + three + five - 180;
  return TRUE;
  }

