#!/bin/sh
HOST=localhost
SCALEX=10
SCALEY=25
height=$((SCALEY*15))
width=$((SCALEX*45))

# run server
gnome-terminal -e "./server" --geometry=45x15+0+0
gnome-terminal -e "./liftctrl" --geometry=45x15+0+$height

# run floor client
for i in {0..3}
do	
	height=$((i*7*SCALEY))
  gnome-terminal -e "./floor $HOST $((i+1))" --geometry=45x7+$width+$height
done	

# run elevator
width=$((width*2))
height=$((SCALEY*15))
gnome-terminal -e "./elevator $HOST" --geometry=45x15+$width+0
gnome-terminal -e "./liftsensor" --geometry=45x15+$width+$height
