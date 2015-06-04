Elevator simulation
============================================

This repo is for ITSS project

+ Use C socket & thread

##Quick run:

		make
		sh script.sh

##Usage:

+ Server (LiftMng) (server.c)

		./server

		+ press quit to exit

+ Lift Controller (LiftCtrl) (lift_controler.c)
		
		./liftctrl

+ Floor Client (opePanelX) (floor_controler.c)

		./floor <hostname> <floor_no>

	+ with floor 1st: press number from 2 to call request elevator;
	+ with floor 2nd and abov: press any number except 0 number
	+ press 0 to exit

+ Elevator Controller (LiftBody) (elevator_controler.c)

		./elevator <hostname>

+ Elevator Sensor (LiftSensor) (lift_sensor.c)

		./liftsensor

##Configure
	
+ `message.h`: configure `MY_PORT`
+ `client.h`: configure `MAX_CLIENTS` (elevator + floor client)		
+ `elevator.h`: configure `FLOOR_HEIGHT`, `ELEVATOR_HEIGHT`, `SENSOR_TIME_INTERVAL`, `ELEVATOR_SPEED`, `ELEVATOR_WAITING_TIME`

