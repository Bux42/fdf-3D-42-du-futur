# fdf-3D-42-du-futur

Utilisation:

git clone https://github.com/Bux42/fdf-3D-42-du-futur.git fdf3D

cd fdf3D

make

Usage: ./fdf3D [map_path] [3D array size]

Example: ./fdf3D ./maps/square.f3f 30

Controls:

	arrow keys to rotate
	
	'+' and '-' for the zoom

	'/' and '*' for shaking effect

	suppr to delete drawn lines from the end to the beginning
	
	space to set current cursor position as the start of a new line

	'6' and '4' to move cursor in Z axis

	'5' and '2' to move cursor in X axis

	'1' and '3' to move cursor in Y axis

	's' to save current line drawn with cursor

	delete to hide current line drawn with cursor

	'r' to activate random colors

	'p' to print current lines into instructions

[x,y,z]=>[x,y,z][x,y,z]

See the cube example in the maps folder.

It goes like XYZ starting position then => to which position should the starting position draw a line

![alt text](https://i.imgur.com/UjrwnoC.png)
