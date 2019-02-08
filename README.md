This is a very simple command-line utility for Linux and similar, that
can do two things:

1. Convert a Maidenhead locator (4 or 6-charater) to a latitute and
longitude, and

2. Calulate the distance and bearing between two Maidenhead locators

Because Maidenhead locators are not particularly precise in themselves,
all results should be regarded as approximate. Moreover, for simplicity,
the utility assumes that the Earth is spherical, which it isn't.

If the program is invoked with one argument, it displays the
corresponding latitude and longitude, as a pair of decimal numbers.
Negative values are west/south.

If the program is invoked with two arguments, it calculates the
distance and bearing _from_ the first locator _to_ the second. This
emphasis is important because, despite common perception, you can't
reverse bearings on the Earth's surface by turning through 180 degrees --
not over significant distances, anyway.

If the --km switch is given, distance is displayed in kilometres,
otherwise in miles.

This code is distributed under the terms of the GNU Public Licence,
version 3.0.
 
