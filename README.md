# ***Implementação do Escalonador de Processos por Passos (Stride Scheduling) no Sistema Operacional Xv6***

**Implementado por:** *[Andrew Gabriel](https://github.com/Andrewgaabriel) e [Igor Radkte](https://github.com/IgorRadtke)*   
**Plataforma:** *[Xv6](http://pdos.csail.mit.edu/6.828/2012/xv6.html)*

---

## :book: **Conteúdo:**

1. *[Objetivo Geral](#obj-geral)*
2. *[Objetivos Específicos](#obj-espc)*
3. *[Descrição](#descrição)*
4. *[Como testar/executar?](#how-test)*
5. *[Como instalar o emulador Qemu?](#instalarxv6)*


<div id='obj-geral'>

## :bow_and_arrow: **Objetivo Geral**

- Desenvolver conhecimento e prática de implementação de um componente básico (i.e., escalonador de processos) em um sistema operacional didático.

<div id="obj-espc">

## :dart: **Objetivos Específicos**

- **(A)** Estudar o código de uma implementação do Unix versão 6 para a plataforma Intel
(xv6, desenvolvido no MIT);
- **(B)** Analisar e planejar a implementação de dois escalonadores de processos;
- **(C)** Implementar os escalonadores;
- **(D)** Avaliar o escalonador através de experimentos.

<div id='descrição'>

## :newspaper: **Descrição**

- Implementar o escalonador de processos baseado em passos (stride cheduling). Na instanciação de um processo, deve-se passar ao sistema a quantidade de bilhetes que o novo processo recebe. Caso o usuário não forneça esse dado, o sistema assume um número
default de bilhetes. Assumir também um número máximo de bilhetes que um processo pode receber. Então é feita uma lógica para calcular o tamanho da passada (i. e. um valor constante dividido pelo número de bilhetes ) do processo.

<div id='how-test'/>

## :wrench: **Como testar/executar:**

- **Requisitos:**
  - *GCC compiler*
  - *Qemu emulator*


- **Como executar:**
  - **(1)** Faça uma cópia do repositório em sua máquina:

    ```
    $ git clone https://github.com/Andrewgaabriel/xv6-stride-scheduler-implementation.git
    ```

  - **(2)** Acesse o repositório executando os comando abaixo:
    ```bash
    $ cd xv6-stride-scheduler-implementation
    $ chmod 700 -R xv6-stride-scheduling
    $ cd xv6-stride-scheduling
    ```
  - **(3)** Compile o programa:
    ```bash
    $ make clean
    $ make
    ```
  - **(4)** Execute o emulador: (*caso não tenha o xv6 instalado siga essas [instruções](#instalarxv6):*)
    ```bash
    $ make qemu
    ```
  - **(5)** Dentro do emulador, para testar o escalonador, execute:
    ```bash
    $ teste <op>
    ```
    - Opções de teste:
      - `<op> = 0`: Teste COM definição de bilhetes e processamento FINITO.
      - `<op> = 1`: Teste COM definição de bilhetes e processamento INFINITO.
      - `<op> = 2`: Teste SEM definição de bilhetes e processamento FINITO.
      - `<op> = 3`: Teste SEM definição de bilhetes e processamento INFINITO.
      - `<op> = 4`: Teste COM definição de bilhetes no SHELL e processamento FINITO.
      - `<op> = 5`: Teste COM definição de bilhetes no SHELL e processamento INFINITO.
    - Para verificar o funcionamento do escalonador nas opções `<op> = 1` e `<op> = 3` você deve pressionar `CTRL + P` no emulador. Assim você verá os processos que estão sendo executados e suas respectivas informações. Para parar o processamento e fazer mais testes pressione `CTRL + K` para matar os processos.
    - Para as opções `<op> = 4` e `<op> = 5` você deve inserir a quantidade de bilhetes de cada processo, exemplo:
    ```
      $ teste 4 100 200 450 879
    ```

<div id="instalarxv6">

## :key: **Instruções para instalar o emulador:**

  ```bash
  $ sudo apt-get install qemu
  $ sudo apt-get install libc6-dev:i386
  $ chmod 700 -R xv6-stride-scheduling
