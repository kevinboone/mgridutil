/*===========================================================================
  mgridutil 
  grid.h 
  Copyright (c)2019 Kevin Boone, GPL v3.0
===========================================================================*/

#pragma once

BOOL   grid_tolatlong (const char *_grid, double *lat, 
         double *longt, char **error);

double grid_dist (double lat1, double longt1, double lat2, double longt2);

