Here, we'll create a function that draws a 2D Menger Sponge using '#' character:
 - A level 0 sponge is a simple 1x1 square
 - A level 1 sponge is a 3x3 square of level 0 sponges, except for the center one, which is left empty
 - A level 2 sponge is a 3x3 square of level 1 sponges, except for the center one, which is left empty
 - …
The size of a level N Menger sponge is calculated as follows: 3^N
