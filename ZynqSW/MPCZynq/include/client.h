// Client side C/C++ program to demonstrate Socket
// programming
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 9527
#define TCP_BUFFER_SIZE 4096
#define IN_LEN 40
#define OUT_LEN 40

int client(float input[IN_LEN], char* destip);
