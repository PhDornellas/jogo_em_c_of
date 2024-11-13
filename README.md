1. Nome e sobrenome dos membros do projeto e seus respectivos usuários no GitHub:

✅ Pedro Dornellas (@PhDornellas)

✅ João Paulo Melo (@Joaopaulomelo1)

✅ Gabriel Angelo Prata (@GabrielPrataa)

2. Nome da disciplina:

✅ Programação Imperativa e Funcional - 2024.2.

3. Nome da instituição de ensino:

✅ CESAR School.

4. Nome do jogo:

✅ Battle of Luck

5. Instruções detalhadas para compilar e executar o jogo:

✅ ### Instruções para Compilar e Executar o Jogo "Battle of Luck"

*Compilação:*

Certifique-se de que você está no diretório raiz do projeto.  

Execute o seguinte comando para compilar o jogo:  

gcc -I cli-lib/include cli-lib/src/main.c cli-lib/src/screen.c cli-lib/src/keyboard.c cli-lib/src/timer.c -o jogo  

*Execução:*

Para iniciar o jogo, execute o comando:  

./jogo  

O jogo será iniciado, e você poderá seguir as instruções no terminal para jogar "Battle of Luck".

6. Breve descrição do jogo, incluindo as regras e como interagir com ele

✅ ## Descrição do Jogo :

 Pedra, Papel e Tesoura traz para o terminal o popular jogo de "Pedra, Papel e Tesoura". As regras do jogo são simples:

- *Pedra* ganha de *Tesoura*

- *Tesoura* ganha de *Papel*

- *Papel* ganha de *Pedra*

Neste jogo, o jogador compete contra o computador, que faz uma escolha aleatória a cada rodada. Ao fim de cada rodada, o vencedor é anunciado, e o jogador pode decidir se deseja continuar jogando ou encerrar a sessão.

✅ ### Como Jogar: 

1. Após iniciar o jogo, o jogador escolhe uma das opções:

   - *0* para Pedra

   - *1* para Papel

   - *2* para Tesoura

2. O computador faz sua escolha automaticamente, de maneira aleatória.

3. O programa exibe o resultado da rodada e indica quem venceu ou se houve empate.

4. O jogador pode então optar por jogar novamente ou sair do jogo.
