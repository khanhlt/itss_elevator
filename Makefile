all: floor elevator liftsensor liftctrl server
elevator: elevator_controler.o
	cc elevator_controler.o -o elevator -lpthread
liftsensor: lift_sensor.o
	cc lift_sensor.o -o liftsensor
floor: floor_controler.o
	cc floor_controler.o -o floor
liftctrl: lift_controler.o
	cc lift_controler.o -o liftctrl
server: server.o
	cc server.o -o server -lpthread
elevator_controler.o: elevator_controler.c
	cc -c elevator_controler.c
lift_sensor.o: lift_sensor.c
	cc -c lift_sensor.c
floor_controler.o: floor_controler.c
	cc -c floor_controler.c
lift_controler.o: lift_controler.c
	cc -c lift_controler.c
server.o: server.c
	cc -c server.c
clean:
	rm -f *.o
reset:
	rm -f *.o liftctrl liftsensor elevator floor server *.c~
