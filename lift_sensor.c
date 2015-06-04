/**
* @author pvhau
* Lift controller controls lift
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "message.h"
#include "elevator.h"

void sendMsgRequest();
void waitMsg(long type);

struct msgbuf buf;
int msqid;
key_t key;  


int main(int argc, char *argv[]) {
  
  /*LiftSensor==================================================*/
  if(argc != 1){
    printf("Invalid parameter.\nUsage: liftsensor\n");
    exit(0);
  }    
  
  /* init shared memory segment */
  if ((key = ftok("request_elevator", 'B')) == -1) {
    perror("ftok");
    exit(1);
  }

  if ((msqid = msgget(key, 0644 | IPC_CREAT)) == -1) {
    perror("msgget");
    exit(1);
  }

  // process message
  while(1){ 
    sendMsgRequest();
    waitMsg(MSG_TYPE_SENSOR_RESPONSE);
    double height = buf.command.floor;
    printf("[LIFTSENSOR] height: %.2f, floor: %d, state: %s\n", height, (int) ( height / FLOOR_HEIGHT) + 1, (getFloor(height) > 0 ? "ON":"OFF"));
    msleep(SENSOR_TIME_INTERVAL);
  }

  if (msgctl(msqid, IPC_RMID, NULL) == -1) {
    perror("msgctl");             
  }

  return 1;
}//main

void sendMsgRequest(){
  setupBufMessage(&buf, MSG_TYPE_SENSOR_REQUEST, 0, 0);
  msgsnd(msqid, &buf, sizeof(struct msgbuf) - sizeof(long), 0);
}

void waitMsg(long type){
  int size = msgrcv(msqid, &buf, sizeof(struct msgbuf) - sizeof(long), type, 0);
  if (size == -1){
    perror("msgrcv");
    exit(1);
  }
}