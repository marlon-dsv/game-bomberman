💣 Bomberman em C++

Projeto de um jogo inspirado no clássico Bomberman, desenvolvido em C++ para a disciplina de AP2.

O jogo funciona no console do Windows e apresenta um mapa com paredes, blocos destrutíveis, bombas e inimigos que se movimentam de forma aleatória. O objetivo do jogador é utilizar as bombas para destruir os fantasmas e vencer a partida.

🎮 Funcionalidades
🕹️ Movimentação do jogador pelo mapa.
💣 Plantio de bombas utilizando a tecla Espaço.
💥 Explosões com alcance configurável.
🧱 Destruição de blocos.
👻 Cinco fantasmas com movimentação aleatória.
⚔️ Sistema de colisão entre jogador e fantasmas.
💀 Sistema de Game Over.
🏆 Sistema de vitória ao eliminar todos os fantasmas.
🔄 Opção de jogar novamente.
📜 Menu principal com opções de jogar, sair e visualizar os créditos.
⏱️ Sistema de tempo para controlar movimentação dos inimigos, bombas e explosões.
🎮 Controles
Tecla	Ação
W / ↑	Mover para cima
S / ↓	Mover para baixo
A / ←	Mover para a esquerda
D / →	Mover para a direita
Espaço	Colocar uma bomba
🗺️ Estrutura do mapa

O mapa é representado por uma matriz bidimensional:

0 → Espaço livre
1 → Parede
2 → Bloco destrutível

As paredes impedem a movimentação e também bloqueiam as explosões. Já os blocos destrutíveis podem ser destruídos pelas bombas.

💣 Sistema de bombas

O jogador pode colocar uma bomba quando não existe outra bomba ativa. Após 1 segundo, a bomba explode e gera uma explosão nas quatro direções.

A explosão:

Atinge o espaço onde a bomba foi colocada.
Se propaga para cima, baixo, esquerda e direita.
É bloqueada por paredes.
Destrói blocos destrutíveis.
Elimina fantasmas atingidos.
Pode eliminar o próprio jogador caso ele esteja na área da explosão.

Após 500 ms, a explosão desaparece.

👻 Sistema dos fantasmas

O jogo possui 5 fantasmas, que se movimentam automaticamente pelo mapa.

A cada 500 ms, cada fantasma escolhe uma direção aleatória e tenta se movimentar. Eles não conseguem atravessar paredes ou blocos.

Caso o jogador encoste em um fantasma, a partida termina.

🏆 Condições de vitória e derrota
Vitória

O jogador vence quando consegue eliminar todos os fantasmas utilizando as bombas.

Derrota

O jogador perde caso:

Entre em contato com um fantasma;
Seja atingido pela explosão de uma bomba.

Após perder, o jogo oferece a opção de iniciar uma nova partida.

🛠️ Tecnologias utilizadas
C++
iostream — entrada e saída de dados.
windows.h — controle do console do Windows e posicionamento do cursor.
conio.h — leitura de teclas em tempo real.
chrono — controle dos intervalos de tempo do jogo.
cstdlib e ctime — geração de movimentos aleatórios dos fantasmas.
🧠 Conceitos praticados

O projeto utiliza diversos conceitos fundamentais de programação em C++, como:

Matrizes bidimensionais;
Estruturas de repetição;
Estruturas condicionais;
Funções;
Vetores;
Variáveis booleanas;
Manipulação de caracteres no console;
Geração de números aleatórios;
Controle de tempo;
Detecção de colisões;
Organização de um jogo baseado em um loop principal.
▶️ Como executar

O projeto foi desenvolvido para ser executado em Windows, devido à utilização das bibliotecas windows.h e conio.h.

Clone este repositório.
Abra o projeto em uma IDE compatível com C++, como Visual Studio ou Code::Blocks.
Compile o código.
Execute o programa pelo console.
👨‍💻 Autores

Projeto desenvolvido para a disciplina AP2 por:

Marcelo
Marlon Vritzl
João

💣 Divirta-se e tente eliminar todos os fantasmas!
