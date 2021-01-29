#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(){
	pid_t pid[4] = {-1, -1, -1, -1}; //Vetor com processos filhos e netos
	int tempo[10] = {}; //Vetor que armazena a data de nascimento e de morte de cada processo
	int lifetime[5] = {}; //Vetor que armazena a duração de vida de cada processo
	int born[5][3] = {}; //Vetor que armazena, respectivamente, hora, minuto e segundo de nascimento de cada processo
	time_t meutempo; //Variável que vai guardar o horário local da máquina
	struct tm *horalocal; //Struct que vai separar a data local da máquina em cada medida de tempo

	//Nascimento do Pai
	meutempo = time(NULL);
	horalocal = localtime(&meutempo);

	tempo[0] = (horalocal->tm_min * 60) + horalocal->tm_sec; //Momento que nasceu em segundos
	
	born[0][0] = horalocal->tm_hour;
	born[0][1] = horalocal->tm_min;
	born[0][2] = horalocal->tm_sec;

	printf("[%d:%d:%d] Nasceu o Pai (PID = %d).\n", horalocal->tm_hour, horalocal->tm_min, horalocal->tm_sec, getpid());	
	sleep(14); //O pai tem o primeiro filho com 14 anos
	
	pid[0] = fork();

	if (pid[0] < 0){
		printf("Erro ao criar o processo.\n");
		exit(-1);
	}

	else if(pid[0] == 0){
		//Nascimento do Filho1
		meutempo = time(NULL);
		horalocal = localtime(&meutempo);
		
		tempo[2] = (horalocal->tm_min * 60) + horalocal->tm_sec; //Momento que nasceu

		born[1][0] = horalocal->tm_hour;
		born[1][1] = horalocal->tm_min;
		born[1][2] = horalocal->tm_sec;

		printf("[%d:%d:%d] Nasceu o Filho1 (PID = %d).\n", horalocal->tm_hour, horalocal->tm_min, horalocal->tm_sec, getpid());
		sleep(12); //O Filho1 vira pai aos 12 anos (o Pai vira avô pela primeira vez aos 26).

		pid[2] = fork();

		if (pid[2] < 0){
			printf("Erro ao criar o processo.\n");
			exit(-1);
		}

		else if(pid[2] == 0){
			//Nascimento do Neto1
			meutempo = time(NULL);
			horalocal = localtime(&meutempo);

			tempo[6] = (horalocal->tm_min * 60) + horalocal->tm_sec; //Momento que nasceu
			
			born[3][0] = horalocal->tm_hour;
			born[3][1] = horalocal->tm_min;
			born[3][2] = horalocal->tm_sec;

			printf("[%d:%d:%d] Nasceu o Neto1 (PID = %d).\n", horalocal->tm_hour, horalocal->tm_min, horalocal->tm_sec, getpid());
			sleep(12); //O Neto1 morre aos 12 anos.
			
			//Morte do Neto1
			meutempo = time(NULL);
			horalocal = localtime(&meutempo);

			tempo[7] = (horalocal->tm_min * 60) + horalocal->tm_sec; //Momento que morreu
			lifetime[3] = tempo[7]-tempo[6]; //Cálculo da duração da vida

			printf("[%d:%d:%d] Morreu o Neto1 (PID = %d). Ele nasceu em %d:%d:%d e viveu %d segundos.\n", horalocal->tm_hour, horalocal->tm_min, horalocal->tm_sec, getpid(), born[3][0], born[3][1], born[3][2], lifetime[3]);
			exit(0);
		}

		else{
			wait(NULL);
			sleep(6); //O Filho1 morre 6 anos depois do Neto1.

			//Morte do Filho1
			meutempo = time(NULL);
			horalocal = localtime(&meutempo);

			tempo[3] = (horalocal->tm_min * 60) + horalocal->tm_sec; //Momento que morreu
			lifetime[1] = tempo[3]-tempo[2]; //Cálculo da duração da vida

			printf("[%d:%d:%d] Morreu o Filho1 (PID = %d). Ele nasceu em %d:%d:%d e viveu %d segundos.\n", horalocal->tm_hour, horalocal->tm_min, horalocal->tm_sec, getpid(), born[1][0], born[1][1], born[1][2], lifetime[1]);
			exit(0);
		}
	}

	else{
		sleep(2); //O Filho2 nasce 2 anos depois do Filho1.

		pid[1] = fork();

		if (pid[1] < 0){
			printf("Erro ao criar o processo.\n");
			exit(-1);
		}

		else if(pid[1] == 0){
			//Nascimento de Filho2	
			meutempo = time(NULL);
			horalocal = localtime(&meutempo);

			tempo[4] = (horalocal->tm_min * 60) + horalocal->tm_sec; //Momento que nasceu

			born[2][0] = horalocal->tm_hour;
			born[2][1] = horalocal->tm_min;
			born[2][2] = horalocal->tm_sec;
			
			printf("[%d:%d:%d] Nasceu o Filho2 (PID = %d).\n", horalocal->tm_hour, horalocal->tm_min, horalocal->tm_sec, getpid());
			sleep(14); //Filho2 vira pai aos 14 anos (o Pai é avô novamente aos 30).
			
			pid[3] = fork();

			if (pid[3] < 0){
				printf("Erro ao criar o processo.\n");
				exit(-1);
			}

			else if(pid[3] == 0){
				//Nascimento de Neto2
				meutempo = time(NULL);
				horalocal = localtime(&meutempo);

				tempo[8] = (horalocal->tm_min * 60) + horalocal->tm_sec; //Momento que nasceu

				born[4][0] = horalocal->tm_hour;
				born[4][1] = horalocal->tm_min;
				born[4][2] = horalocal->tm_sec;
				
				printf("[%d:%d:%d] Nasceu o Neto2 (PID = %d).\n", horalocal->tm_hour, horalocal->tm_min, horalocal->tm_sec, getpid());
				sleep(18); //O Neto2 morre com 18 anos, dois anos depois de Filho2.
				
				meutempo = time(NULL);
				horalocal = localtime(&meutempo);

				tempo[9] = (horalocal->tm_min * 60) + horalocal->tm_sec; //Momento que morreu
				lifetime[4] = tempo[9]-tempo[8]; //Cálculo da duração da vida

				printf("[%d:%d:%d] Morreu o Neto2 (PID = %d). Ele nasceu em %d:%d:%d e viveu %d segundos.\n", horalocal->tm_hour, horalocal->tm_min, horalocal->tm_sec, getpid(), born[4][0], born[4][1], born[4][2], lifetime[4]);
				exit(0);
			}

			else{
				sleep(16); //O Filho2 morre aos 30 anos, dois anos antes de Neto2.

				meutempo = time(NULL);
				horalocal = localtime(&meutempo);
				
				tempo[5] = (horalocal->tm_min * 60) + horalocal->tm_sec; //Momento que morreu
				lifetime[2] = tempo[5]-tempo[4]; //Cálculo da duração da vida

				printf("[%d:%d:%d] Morreu o Filho2 (PID = %d). Ele nasceu em %d:%d:%d e viveu %d segundos.\n", horalocal->tm_hour, horalocal->tm_min, horalocal->tm_sec, getpid(), born[2][0], born[2][1], born[2][2], lifetime[2]);
				exit(0);
			}
		}

		else{
			wait(NULL); //Ele vai esperar 14 anos para ter o Filho1, depois mais 30 anos até que Filho1 (que é o primeiro a terminar) morra, e depois mais 16 para completar 60 anos e morrer.
			sleep(16);
			
			meutempo = time(NULL);
			horalocal = localtime(&meutempo);
			
			tempo[1] = (horalocal->tm_min * 60) + horalocal->tm_sec; //Momento que morreu
			lifetime[0] = tempo[1]-tempo[0]; //Cálculo da duração da vida

			printf("[%d:%d:%d] Morreu o Pai (PID = %d). Ele nasceu em %d:%d:%d e viveu %d segundos.\n", horalocal->tm_hour, horalocal->tm_min, horalocal->tm_sec, getpid(), born[0][0], born[0][1], born[0][2], lifetime[0]);
			exit(0);
		}
	}
	
	return 0;
}