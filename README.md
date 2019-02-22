# mgridutil

v0.0.1

## What is this?

`mgridutil` is a very simple command-line utility for Linux and similar, that
can do two things:

1. Convert a Maidenhead grid locator (4 or 6-charater) to a latitute and
longitude, and

2. Calulate the distance and bearing between two Maidenhead locators

It is primarily intended for working out the distance between
two amateur radio stations.

`mgridutil` is wrtten in standard C, but with GNU extensions; any recent
version of GCC on any platform should be able to build it.

## Usage

If the program is invoked with one argument, it displays the
corresponding latitude and longitude, as a pair of decimal numbers.
Negative values are west/south.

If the program is invoked with two arguments, it calculates the
distance and bearing _from_ the first locator _to_ the second. This
emphasis is important because, despite common perception, you can't
reverse bearings on the Earth's surface by turning through 180 degrees --
not over significant distances, anyway.

If the `--km` switch is given, distance is displayed in kilometres,
otherwise in miles.

## Building

Get the source from https://github.com/kevinboone/mgridutil.

To build and install:

    $ make
    $ sudo make install

## Limitations

Because Maidenhead locators are not particularly precise in themselves,
all results should be regarded as approximate. Moreover, for simplicity,
the utility assumes that the Earth is spherical, which it isn't.

Garbage in, garbage out -- the utility doesn't (and, for the most part can't)
check that a grid locator makes sense. 

## Author and copyright

`mgridutil` is written and maintained by Kevin Boone. It is is open souce 
under the terms of the GPL, version 3.0.

Please report bugs, etc., to kevin@bearontheair.co.uk

 
