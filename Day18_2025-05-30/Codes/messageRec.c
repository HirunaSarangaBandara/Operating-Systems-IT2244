//Receive
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

//Structure for message queue
struct mesg_buffer{
	long mesg_type;
	char mesg_text[100];
} message;

int main(){
	key_t key;
	int msgid;
	
	//ftok to generate unique key
	key =  ftok("Profile", 65);
	
	//msgget create the message queue
	//and returns identifier
	msgid = msgget(key, 0666 | IPC_CREAT);
	
	//msgrcv to receive message
	msgrcv(msgid, &message, sizeof(message), 1, 0);

	//display the message
	printf("Data received is : %s\n", message.mesg_text);
	
	//do destroy the message queue
	msgctl(msgid, IPC_RMID, NULL);
	
return 0;
}