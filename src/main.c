/*======================================================================
 * main.c 
 * Copyright (c)2019 Kevin Boone, GPL v3.0
 * =====================================================================*/
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <getopt.h>
#include <math.h>
#include "defs.h" 
#include "grid.h" 
#include "gc.h" 

#define MILES_PER_KM 0.621371

int main (int argc, char **argv)
  {
  BOOL show_version = FALSE;
  BOOL show_usage = FALSE;
  BOOL km = FALSE;

  static struct option long_options[] = 
   {
     {"version", no_argument, NULL, 'v'},
     {"help", no_argument, NULL, '?'},
     {"km", no_argument, NULL, 'k'},
     {0, 0, 0, 0}
   };

  int opt;
  while (1)
   {
   int option_index = 0;
   opt = getopt_long (argc, argv, "v?k",
     long_options, &option_index);

   if (opt == -1) break;

   switch (opt)
     {
     case 0:
        if (strcmp (long_options[option_index].name, "version") == 0)
          show_version = TRUE;
        else if (strcmp (long_options[option_index].name, "help") == 0)
          show_usage = TRUE;
        else if (strcmp (long_options[option_index].name, "km") == 0)
          km = TRUE;
	else
          exit (-1);
        break;

     case 'v': show_version = TRUE; break;
     case 'k': km = TRUE; break;
     case '?': show_usage = TRUE; break;
     default:  exit(-1);
     }
   }

  if (show_usage)
    {
    printf ("Usage %s [options]\n", argv[0]);
    printf ("  -k, --km              distance in km\n");
    printf ("  -v, --version         show version information\n");
    printf ("  -?                    show this message\n");
    exit (0);
    }
 
  if (show_version)
    {
    printf ("mgridutil " VERSION "\n");
    printf ("Copyright (c)2019 Kevin Boone\n");
    printf ("Distributed according to the terms of the GPL, v3.0\n");
    exit (0);
    }

  int args = argc - optind;

  if (args == 0)
    {
    printf ("At least one Maidenhead grid locator must be specified\n");
    exit (-1);
    }

  char *grid2 = NULL;
  char *grid1 = argv[optind];
  if (args >= 2)
    grid2 = argv[optind + 1];

  char *error = NULL;

  if (grid2)
    {
    double lat1, longt1;
    grid_tolatlong (grid1, &lat1, &longt1, &error);
    if (error)
      {
      printf ("%s: %s\n", argv[0], error);
      free (error);
      }
    else
      {
      double lat2, longt2;
      grid_tolatlong (grid2, &lat2, &longt2, &error);
      if (error)
        {
        printf ("%s: %s\n", argv[0], error);
        free (error);
        }
      else
        {
	double dist = gc_dist (lat1, longt1, lat2, longt2);
	double bearing = gc_bearing (lat1, longt1, lat2, longt2);
	if (km)
	  printf ("%d km, ", (int)dist);
	else
	  printf ("%d miles, ", (int)(dist * MILES_PER_KM));
        printf ("bearing %d degrees\n", (int)bearing);
	}
      }
    }
  else
    {
    double lat, longt;
    grid_tolatlong (grid1, &lat, &longt, &error);
    if (error)
      {
      printf ("%s: %s\n", argv[0], error);
      free (error);
      }
    else
      {
      printf ("%.2f, %.2f\n", lat, longt);
      }
    }
  }


