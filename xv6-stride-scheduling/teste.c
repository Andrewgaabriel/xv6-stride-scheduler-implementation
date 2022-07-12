#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "syscall.h"

int teste0(void);
int teste1(void);
int teste2(void);
int teste3(void);
int teste4(int n, int *v);
int teste5(int n, int *v);

int main(int argc, char *argv[]) {
    int a;
    int v[argc];

    for (int i = 0; i < argc; i++) {
        v[i] = atoi(argv[i]);
    }

    a = atoi(argv[1]);

    if (a == 0) {
        printf(1, "teste COM definicao de bilhetes e processamento FINITO\n");
        teste0();
    } else if (a == 1) {
        printf(1, "teste COM definicao de bilhetes e processamento INFINITO\n");
        teste1();
    } else if (a == 2) {
        printf(1, "teste SEM definicao de bilhetes e processamento FINITO\n");
        teste2();
    } else if (a == 3) {
        printf(1, "teste SEM definicao de bilhetes e processamento INFINITO\n");
        teste3();
    } else if (a == 4) {
        printf(1, "teste COM definicao de bilhetes NO SHELL e processamento FINITO\n");
        teste4(argc,v);
    } else if (a == 5) {
        printf(1, "teste COM definicao de bilhetes NO SHELL e processamento INFINITO\n");
        teste5(argc,v);
    } else {
        printf(1, "no valid option\n");
    }
    exit();
}

void gastacpu(){
    for (int c = 0; c < 1742000; c++){
                for (int d = 0; d < 1739000; d++){
                    c = d * 1234.56 + c % 12346;
                }
            }
}


/* teste com definição de bilhetes e processamento de ~3s*/
int teste0() {

    int N = 3;
    int pid;
    int bilhetes[3] = {300, 1000, 30};

    for (int i = 0; i < N; i++) {
        pid = fork(bilhetes[i]);
        if (pid == 0) {
            for (int i = 0; i < 20; i++){   // 5 -> processamento de ~5s
                                            // 10 -> processamento de ~9s
                                            // 20 -> processamento de ~17s
                                            // 40 -> processamento de ~34s
                gastacpu();
            }
            
            printf(1, "P:%d B:%d\n",getpid(), bilhetes[i]);
            exit();
        }
    }

    for (int i = 0; i < 10; i++) {
        wait();
    }
    exit();
}



/* teste com definição de bilhetes e processamento infinito
 testa usando CTRL + P*/
int teste1() {

    int N = 3;
    int pid;
    int bilhetes[3] = {300, 1000, 30};

    for (int i = 0; i < N; i++) {
        pid = fork(bilhetes[i]);
        if (pid == 0) {
            for (;;);
            exit();
        }
    }

    for (int i = 0; i < 10; i++) {
        wait();
    }
    exit();
}




/* teste sem definição de bilhetes e processamento de ~3s*/
int teste2() {

    int pid;

    for (int i = 1; i < 10; i++) {
        pid = fork(10+i*40);
        if (pid == 0) {
            for (int i = 0; i < 20; i++){ 
                gastacpu();
            }
            printf(1, "P:%d B:%d\n",getpid(), 10+i*40);
            exit();
        }
    }

    for (int i = 0; i < 10; i++) {
        wait();
    }
    exit();
}



/* teste sem definição de bilhetes e processamento infinito
testa usando CTRL + P */
int teste3() {

    int pid;

    for (int i = 1; i < 10; i++) {
        pid = fork(10+i*40);
        if (pid == 0) {

            for(;;);
            exit();
        }
    }

    for (int i = 0; i < 10; i++) {
        wait();
    }
    exit();
}

/* teste COM definição de bilhetes NO SHELL e processamento FINITO
testa usando CTRL + P */
int teste4(int n, int *v) {

    int pid;

    for (int i = 2; i < n; i++) {
        pid = fork(v[i]);
        if (pid == 0) {
            for (int i = 0; i < 20; i++){ 
                gastacpu();
            }
            printf(1, "P:%d B:%d\n",getpid(), v[i]);
            exit();
        }
    }

    for (int i = 0; i < n-2; i++) { 
        wait();
    }
    exit();
}


/* teste COM definição de bilhetes NO SHELL e processamento INFINITO
testa usando CTRL + P */
int teste5(int n, int *v) {

    int pid;

    for (int i = 2; i < n; i++) {
        pid = fork(v[i]);
        if (pid == 0) {
            for(;;);
            exit();
        }
    }

    for (int i = 0; i < n-2; i++) { 
        wait();
    }
    exit();
}

