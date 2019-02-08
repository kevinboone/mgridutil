/*======================================================================
 * gc.c 
 * Great circle functions
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
#include "math.h" 


/*======================================================================
 *   gc_dist
 *   Calculate the great-cicle distance in km 
 *   between two latitute/longitude points, expressed as degrees
 * =====================================================================*/
double gc_dist (double lat1, double longt1, double lat2, double longt2)
  {
  double _lat1 = torad (lat1);
  double _lat2 = torad (lat2);
  double _longt1 = torad (longt1);
  double _longt2 = torad (longt2);

  double dlat = fabs (_lat2 - _lat1);
  double dlongt = fabs (_longt2 - _longt1);
  
  double v = hav (dlat) + cos (_lat1)*cos(_lat2)*hav(dlongt); 
  
  double dsigma = 2 * asin (sqrt(v));

  return 6371.0 * dsigma;
  }

/*======================================================================
 *   gc_bearing
 *   Calculate the great-cicle bearing in degrees 
 *   between two latitute/longitude points, expressed as degrees
 *   Note that the bearing is _from_ point 1 _to_ point 2
 * =====================================================================*/
double gc_bearing (double lat1, double longt1, double lat2, double longt2)
  {
  double _lat1 = torad (lat1);
  double _lat2 = torad (lat2);
  double _longt1 = torad (longt1);
  double _longt2 = torad (longt2);

  double dlongt = _longt2 - _longt1;

  double c = cos(_lat1)*sin(_lat2) - sin(_lat1)*cos(_lat2)*cos(dlongt);
  double s = sin (dlongt)*cos(_lat2);
  
  double b =  todeg (atan2 (s, c));
  if (b < 0) b += 360;
  return b;
  }



