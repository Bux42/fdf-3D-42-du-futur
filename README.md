# fdf-3D-42-du-futur

Utilisation:

git clone https://github.com/Bux42/fdf-3D-42-du-futur.git fdf3D

cd fdf3D

make

./fdf3D file ./maps/square.f3f 30

Usage: ./fdf3D file [map_path] [3D array size]

Controls: arrow keys & mouse wheel to rotate, '+' and '-' for the zoom

Map file creation:

[x,y,z]=>[x,y,z][x,y,z]

See the cube example in the maps folder.

It goes like XYZ starting position then => to which position should the starting position draw a line
