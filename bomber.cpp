#include <cstdio>               //FORMATA O CRONOMETRO
#include <string>               //UTILIZADA PARA LER A OPCAO DO MENU
#include <iostream>             //ENTRADA E SAIDA DE DADOS
#include <windows.h>            //TRECHO QUE NAO DEVE SER MODIFICADO
#include <conio.h>              //TRECHO QUE NAO DEVE SER MODIFICADO
#include <chrono>               //UTILIZADA PARA TIRAR LENTIDAO
#include <cstdlib>              //UTILIZADA PARA O RAND
#include <ctime>                //UTILIZADA PARA O RAND

using namespace std;


// ==================== MENU ====================

int Menu() {
    string entrada;

    system("cls");

    cout << "==============================\n";
    cout << "           BOMBERMAN\n";
    cout << "==============================\n\n";

    cout << "   1 - Jogar\n";
    cout << "   2 - Sair\n";
    cout << "   3 - Como Jogar\n";
    cout << "   4 - Creditos\n\n";

    while (true) {
        cout << "Escolha: ";

        if (!getline(cin, entrada)) {
            return 2;
        }

        if (entrada == "1") return 1;
        if (entrada == "2") return 2;
        if (entrada == "3") return 3;
        if (entrada == "4") return 4;

        cout << "\nOpcao invalida! Digite 1, 2, 3 ou 4.\n\n";
    }
}


void Creditos() {
    system("cls");

    cout << "==============================\n";
    cout << "           CREDITOS\n";
    cout << "==============================\n\n";

    cout << "   Criado para a disciplina AP2, por:\n";
    cout << "   - Aluno Marcelo de Oliveira Junior\n";
    cout << "   - Aluno Marlon Vritzl\n";
    cout << "   - Aluno Joao\n";

    system("pause");
}

void ComoJogar() {
    system("cls");

    cout << "==============================\n";
    cout << "          COMO JOGAR\n";
    cout << "==============================\n\n";

    cout << "MOVIMENTACAO:\n";
    cout << "Use as teclas W, A, S e D ou as setas:\n\n";

    cout << "   W ou seta para cima     - Mover para cima\n";
    cout << "   S ou seta para baixo    - Mover para baixo\n";
    cout << "   A ou seta para esquerda - Mover para esquerda\n";
    cout << "   D ou seta para direita  - Mover para direita\n\n";

    cout << "BOMBA:\n";
    cout << "Pressione a barra de ESPACO para colocar uma bomba.\n";
    cout << "A bomba explode depois de 2 segundos.\n\n";

    cout << "REGRAS DO JOGO:\n";
    cout << "- Elimine todos os inimigos para vencer.\n";
    cout << "- A explosao pode destruir os blocos do mapa.\n";
    cout << "- Paredes indestrutiveis bloqueiam a explosao.\n";
    cout << "- Nao encoste nos inimigos.\n";
    cout << "- Afaste-se da bomba, pois a explosao tambem\n";
    cout << "  pode atingir o jogador.\n";
    cout << "- Apenas uma bomba pode ser colocada por vez.\n\n";

    cout << "Pressione qualquer tecla para voltar ao menu.\n";

    system("pause");
}

void GameOver() {
    system("cls");

    cout << "==============================\n";
    cout << "          GAME OVER!\n";
    cout << "==============================\n\n";

    cout << "Voce perdeu!\n\n";

    system("pause");
}


void Vitoria() {
    system("cls");

    cout << "==============================\n";
    cout << "         VOCE VENCEU!\n";
    cout << "==============================\n\n";

    system("pause");
}


bool TentarNovamente() {

    char resposta;

    system("cls");

    cout << "==============================\n";
    cout << "       TENTAR NOVAMENTE?\n";
    cout << "==============================\n\n";

    cout << "   1 - Sim\n";
    cout << "   0 - Nao\n\n";

    while (true)
    {
        cout << "Escolha: ";
        cin >> resposta;

        if (resposta == '1') {
            return true;
        }

        if (resposta == '0') {
            return false;
        }

        cout << "\nOpcao invalida! Digite 1 ou 0.\n\n";
    }
}


// ==================== MAIN ====================

int main()
{

    // Inicializa o gerador de numeros aleatorios uma unica vez.
    srand(static_cast<unsigned int>(time(NULL)));


    // ==================== INICIO DO TRECHO QUE NAO PODE SER MODIFICADO ====================.

    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);

    cursorInfo.bVisible = false;

    SetConsoleCursorInfo(out, &cursorInfo);


    short int CX = 0, CY = 0;

    COORD coord;

    coord.X = CX;
    coord.Y = CY;

    // ==================== FIM DO TRECHO QUE NAO DEVE SER MODIFICADO ====================


    // ==================== MENU ====================

    int opcao;

    do {
        opcao = Menu();

        if (opcao == 2) {
            system("cls");

            cout << "=============================\n";
            cout << "       SAINDO DO JOGO\n";
            cout << "=============================\n";

            return 0;
        }

        if (opcao == 3) {
            ComoJogar();
        }

        if (opcao == 4) {
            Creditos();
        }

    } while (opcao != 1);


    // ==================== JOGO ====================

    bool jogarNovamente = true;

    while (jogarNovamente) {

        // ==================== INICIO DO TRECHO QUE NAO PODE SER MODIFICADO ====================

        // ==================== MAPA ====================

        const int LINHAS = 11;
        const int COLUNAS = 13;

        /*
            0 = espaco livre
            1 = parede
            2 = bloco destrutivel
        */

        int m[LINHAS][COLUNAS] =
        {
            { 1,1,1,1,1,1,1,1,1,1,1,1,1 },
            { 1,0,0,0,0,0,2,0,0,2,0,0,1 },
            { 1,0,1,0,1,0,1,0,1,0,1,2,1 },
            { 1,2,2,0,0,2,0,0,2,0,2,0,1 },
            { 1,0,1,0,1,0,1,0,1,2,1,2,1 },
            { 1,0,0,2,0,0,2,0,2,2,0,2,1 },
            { 1,0,1,0,1,0,1,0,1,0,1,0,1 },
            { 1,0,0,0,2,0,0,0,2,0,0,0,1 },
            { 1,0,1,0,1,0,1,0,1,0,1,0,1 },
            { 1,0,0,2,0,0,2,0,0,2,0,0,1 },
            { 1,1,1,1,1,1,1,1,1,1,1,1,1 }
        };

        // ==================== FIM DO TRECHO QUE NAO DEVE SER MODIFICADO ====================


        // ==================== JOGADOR ====================

        int x = 1;
        int y = 1;


        // ==================== MAPA ALEATORIO ====================

        const int QUANTIDADE_BLOCOS = 25;

        for (int i = 0; i < LINHAS; i++)
        {
            for (int j = 0; j < COLUNAS; j++)
            {
                if (m[i][j] == 2)
                {
                    m[i][j] = 0;
                }
            }
        }

        m[1][1] = 0;
        m[1][2] = 0;
        m[2][1] = 0;
        m[1][3] = 0;
        m[3][1] = 0;

        int blocosGerados = 0;

        while (blocosGerados < QUANTIDADE_BLOCOS)
        {
            int aleatorioX = 1 + rand() % (LINHAS - 2);
            int aleatorioY = 1 + rand() % (COLUNAS - 2);

            if (m[aleatorioX][aleatorioY] == 0)
            {
                bool pertoDoJogador = false;

                if (aleatorioX == 1 && aleatorioY == 1)
                    pertoDoJogador = true;

                if (aleatorioX == 1 && aleatorioY == 2)
                    pertoDoJogador = true;

                if (aleatorioX == 2 && aleatorioY == 1)
                    pertoDoJogador = true;

                if (aleatorioX == 1 && aleatorioY == 3)
                    pertoDoJogador = true;

                if (aleatorioX == 3 && aleatorioY == 1)
                    pertoDoJogador = true;

                if (!pertoDoJogador)
                {
                    m[aleatorioX][aleatorioY] = 2;
                    blocosGerados++;
                }
            }
        }


        // ==================== FANTASMAS ====================

        const int NUM_FANTASMAS = 5;

        int fantasmaX[NUM_FANTASMAS];
        int fantasmaY[NUM_FANTASMAS];

        bool fantasmaAtivo[NUM_FANTASMAS] =
        {
            true, true, true, true, true
        };


        // ==================== NASCIMENTO ALEATORIO DOS FANTASMAS ====================

        for (int f = 0; f < NUM_FANTASMAS; f++)
        {
            bool posicaoValida = false;

            while (!posicaoValida)
            {
                int novoX = 1 + rand() % (LINHAS - 2);
                int novoY = 1 + rand() % (COLUNAS - 2);

                posicaoValida = true;

                if (m[novoX][novoY] != 0)
                {
                    posicaoValida = false;
                }

                if (novoX == x && novoY == y)
                {
                    posicaoValida = false;
                }

                if (novoX == 1 && novoY == 2)
                {
                    posicaoValida = false;
                }

                if (novoX == 2 && novoY == 1)
                {
                    posicaoValida = false;
                }

                for (int outro = 0; outro < f; outro++)
                {
                    if (fantasmaX[outro] == novoX &&
                        fantasmaY[outro] == novoY)
                    {
                        posicaoValida = false;
                    }
                }

                if (posicaoValida)
                {
                    fantasmaX[f] = novoX;
                    fantasmaY[f] = novoY;
                }
            }
        }


        // ==================== TEMPO DOS FANTASMAS ====================

        chrono::steady_clock::time_point ultimoMovimentoFantasma;

        ultimoMovimentoFantasma =
            chrono::steady_clock::now();

        const int TEMPO_FANTASMA = 800;


        // ==================== TEMPO DA BOMBA ====================

        bool bombaAtiva = false;

        int bombaX = -1;
        int bombaY = -1;

        chrono::steady_clock::time_point inicioBomba;
        inicioBomba = chrono::steady_clock::now();

        const int TEMPO_BOMBA = 2000;


        // ==================== TEMPO DA EXPLOSAO ====================

        bool explosaoAtiva = false;

        chrono::steady_clock::time_point inicioExplosao;

        inicioExplosao = chrono::steady_clock::now();

        const int TEMPO_EXPLOSAO = 500;

        const int ALCANCE = 1;

        bool explosao[LINHAS][COLUNAS] = { false };

        bool gameOver = false;
        bool venceu = false;


        // ==================== GERACAO DE ALEATORIOS ====================

        system("cls");

        CHAR_INFO tela[LINHAS * COLUNAS] = {};
        CHAR_INFO telaLarga[(LINHAS + 2) * COLUNAS * 2] = {};
        COORD tamanhoTela = { COLUNAS * 2, LINHAS + 2 };
        COORD origemTela = { 0, 0 };

        chrono::steady_clock::time_point inicioPartida =
            chrono::steady_clock::now();

        chrono::steady_clock::time_point proximoFrame =
            inicioPartida;

        const chrono::microseconds DURACAO_FRAME(33333);


        // ==================== LOOP ====================

        while (true) {
            chrono::steady_clock::time_point agoraFrame =
                chrono::steady_clock::now();

            if (agoraFrame < proximoFrame) {
                Sleep(1);
                continue;
            }

            proximoFrame = agoraFrame + DURACAO_FRAME;


            // ==================== DESENHA O MAPA + CORES ====================

            for (int i = 0; i < LINHAS; i++) {
                for (int j = 0; j < COLUNAS; j++) {

                    CHAR_INFO& celula = tela[i * COLUNAS + j];

                    // ==================================================
                    // VERIFICA SE O JOGADOR ESTA SOBRE A BOMBA
                    // ==================================================

                    bool jogadorSobreBomba =
                        bombaAtiva &&
                        i == x &&
                        j == y &&
                        x == bombaX &&
                        y == bombaY;

                    // ==================================================
                    // PISCAR ENTRE JOGADOR E BOMBA
                    // ==================================================

                    bool mostrarJogador =
                        jogadorSobreBomba &&
                        ((chrono::duration_cast<chrono::milliseconds>(
                            chrono::steady_clock::now() - inicioBomba
                        ).count() / 200) % 2 == 0);


                    if (i == x && j == y && !jogadorSobreBomba)
                    {
                        celula.Attributes = 32;
                        celula.Char.AsciiChar = 'J';
                    }

                    else if (jogadorSobreBomba && mostrarJogador)
                    {
                        // Mostra o jogador.
                        celula.Attributes = 32;
                        celula.Char.AsciiChar = 'J';
                    }

                    else if (jogadorSobreBomba && !mostrarJogador)
                    {
                        // Mostra a bomba.
                        celula.Attributes = 46;
                        celula.Char.AsciiChar = '@';
                    }

                    else {
                        bool desenhouFantasma = false;

                        for (int f = 0; f < NUM_FANTASMAS; f++) {
                            if (fantasmaAtivo[f] &&
                                i == fantasmaX[f] &&
                                j == fantasmaY[f])
                            {
                                celula.Attributes = 44;
                                celula.Char.AsciiChar = 'H';

                                desenhouFantasma = true;

                                break;
                            }
                        }


                        if (!desenhouFantasma) {

                            // ==================================================
                            // EXPLOSAO VERMELHA COM #
                            // ==================================================

                            if (explosaoAtiva && explosao[i][j]) {

                                // Fundo vermelho + texto vermelho claro.
                                celula.Attributes = 68;

                                // Mostra # no lugar do fogo.
                                celula.Char.AsciiChar = '#';
                            }

                            else if (bombaAtiva &&
                                     i == bombaX &&
                                     j == bombaY) {

                                celula.Attributes = 46;
                                celula.Char.AsciiChar = '@';
                            }

                            else {

                                if (m[i][j] == 0) {
                                    celula.Attributes = 32;
                                    celula.Char.AsciiChar = ' ';
                                }

                                else if (m[i][j] == 1) {
                                    celula.Attributes = 8;
                                    celula.Char.AsciiChar = char(219);
                                }

                                else if (m[i][j] == 2) {
                                    celula.Attributes = 135;
                                    celula.Char.AsciiChar = char(178);
                                }
                            }
                        }
                    }
                }
            }


            // ==================================================
            // CADA CASA OCUPA DUAS COLUNAS
            // ==================================================

            for (int i = 0; i < LINHAS; i++) {

                for (int j = 0; j < COLUNAS; j++) {

                    int destino =
                        i * COLUNAS * 2 + j * 2;

                    telaLarga[destino] =
                        tela[i * COLUNAS + j];

                    telaLarga[destino + 1] =
                        telaLarga[destino];

                    char simbolo =
                        telaLarga[destino].Char.AsciiChar;


                    if (simbolo == 'J') {

                        telaLarga[destino].Char.AsciiChar = 'P';
                        telaLarga[destino + 1].Char.AsciiChar = '1';
                    }

                    else if (simbolo == 'H') {

                        telaLarga[destino].Char.AsciiChar = 'E';
                        telaLarga[destino + 1].Char.AsciiChar = 'N';
                    }

                    else if (simbolo == '@')
                    {
                        telaLarga[destino].Char.AsciiChar = '(';
                        telaLarga[destino + 1].Char.AsciiChar = ')';
                    }

                    else if (simbolo == '#')
                    {
                        // Mantem # nos dois lados da casa
                        // para deixar o fogo mais visivel.
                        telaLarga[destino].Char.AsciiChar = '#';
                        telaLarga[destino + 1].Char.AsciiChar = '#';
                    }
                }
            }


            // ==================== PLACAR ====================

            int inimigosRestantes = 0;

            for (int f = 0; f < NUM_FANTASMAS; f++)
            {
                if (fantasmaAtivo[f])
                    inimigosRestantes++;
            }

            long long segundosPartida =
                chrono::duration_cast<chrono::seconds>(
                    chrono::steady_clock::now() - inicioPartida
                ).count();

            char placar[64];
            char cronometro[64];

            snprintf(
                placar,
                sizeof(placar),
                "Inimigos: %d",
                inimigosRestantes
            );

            int minutosPartida =
                static_cast<int>(segundosPartida / 60);

            int segundosNoMinuto =
                static_cast<int>(segundosPartida % 60);

            snprintf(
                cronometro,
                sizeof(cronometro),
                "Tempo: %02d:%02d",
                minutosPartida,
                segundosNoMinuto
            );

            const char* textosPainel[2] =
            {
                placar,
                cronometro
            };

            for (int linha = 0; linha < 2; linha++)
            {
                bool fimTexto = false;

                for (int coluna = 0;
                     coluna < COLUNAS * 2;
                     coluna++)
                {
                    CHAR_INFO& celulaPainel =
                        telaLarga[
                            (LINHAS + linha) *
                            COLUNAS * 2 +
                            coluna
                        ];

                    if (!fimTexto &&
                        textosPainel[linha][coluna] == '\0')
                    {
                        fimTexto = true;
                    }

                    celulaPainel.Char.AsciiChar =
                        fimTexto ?
                        ' ' :
                        textosPainel[linha][coluna];

                    celulaPainel.Attributes = 15;
                }
            }


            // ==================== ENVIA O MAPA AO CONSOLE ====================

            SMALL_RECT areaTela = {
                coord.X,
                coord.Y,
                short(coord.X + COLUNAS * 2 - 1),
                short(coord.Y + LINHAS + 1)
            };

            WriteConsoleOutputA(
                out,
                telaLarga,
                tamanhoTela,
                origemTela,
                &areaTela
            );


            // ==================== CONTROLES ====================

            if (_kbhit())
            {
                int tecla = _getch();

                if (tecla == 0 || tecla == 224)
                {
                    tecla = _getch();
                }

                int novoX = x;
                int novoY = y;


                if (tecla == 72 ||
                    tecla == 'w' ||
                    tecla == 'W')
                {
                    novoX--;
                }

                else if (tecla == 80 ||
                         tecla == 's' ||
                         tecla == 'S')
                {
                    novoX++;
                }

                else if (tecla == 75 ||
                         tecla == 'a' ||
                         tecla == 'A')
                {
                    novoY--;
                }

                else if (tecla == 77 ||
                         tecla == 'd' ||
                         tecla == 'D')
                {
                    novoY++;
                }


                // ==================== COLOCA A BOMBA ====================

                else if (tecla == 32)
                {
                    if (!bombaAtiva)
                    {
                        bombaAtiva = true;

                        bombaX = x;
                        bombaY = y;

                        inicioBomba =
                            chrono::steady_clock::now();
                    }
                }


                // ==================== VERIFICA MOVIMENTO ====================

                if (novoX >= 0 &&
                    novoX < LINHAS &&
                    novoY >= 0 &&
                    novoY < COLUNAS)
                {
                    if (m[novoX][novoY] == 0 &&
                        !(bombaAtiva &&
                          novoX == bombaX &&
                          novoY == bombaY))
                    {
                        x = novoX;
                        y = novoY;
                    }
                }
            }


            // ==================== MOVIMENTACAO DOS FANTASMAS ====================

            chrono::steady_clock::time_point agora;

            agora = chrono::steady_clock::now();

            chrono::milliseconds tempoFantasma;

            tempoFantasma =
                chrono::duration_cast<chrono::milliseconds>
                (agora - ultimoMovimentoFantasma);

            if (tempoFantasma.count() >= TEMPO_FANTASMA)
            {
                ultimoMovimentoFantasma =
                    chrono::steady_clock::now();

                for (int f = 0;
                     f < NUM_FANTASMAS;
                     f++)
                {
                    if (!fantasmaAtivo[f])
                        continue;


                    bool conseguiuMover = false;

                    int direcoes[4] =
                    {
                        0, 1, 2, 3
                    };


                    for (int i = 3; i > 0; i--)
                    {
                        int j = rand() % (i + 1);

                        int temp = direcoes[i];

                        direcoes[i] =
                            direcoes[j];

                        direcoes[j] =
                            temp;
                    }


                    for (int tentativa = 0;
                         tentativa < 4;
                         tentativa++)
                    {
                        int direcao =
                            direcoes[tentativa];

                        int novoX =
                            fantasmaX[f];

                        int novoY =
                            fantasmaY[f];


                        if (direcao == 0)
                            novoX--;

                        else if (direcao == 1)
                            novoX++;

                        else if (direcao == 2)
                            novoY--;

                        else
                            novoY++;


                        if (novoX < 0 ||
                            novoX >= LINHAS ||
                            novoY < 0 ||
                            novoY >= COLUNAS)
                        {
                            continue;
                        }


                        if (m[novoX][novoY] != 0)
                        {
                            continue;
                        }


                        if (bombaAtiva &&
                            novoX == bombaX &&
                            novoY == bombaY)
                        {
                            continue;
                        }


                        bool posicaoOcupada = false;

                        for (int outro = 0;
                             outro < NUM_FANTASMAS;
                             outro++)
                        {
                            if (outro != f &&
                                fantasmaAtivo[outro] &&
                                fantasmaX[outro] == novoX &&
                                fantasmaY[outro] == novoY)
                            {
                                posicaoOcupada = true;
                                break;
                            }
                        }


                        if (posicaoOcupada)
                        {
                            continue;
                        }


                        fantasmaX[f] = novoX;
                        fantasmaY[f] = novoY;

                        conseguiuMover = true;

                        break;
                    }
                }
            }


            // ==================== COLISAO COM FANTASMAS ====================

            for (int f = 0;
                 f < NUM_FANTASMAS;
                 f++)
            {
                if (fantasmaAtivo[f])
                {
                    if (x == fantasmaX[f] &&
                        y == fantasmaY[f])
                    {
                        gameOver = true;
                    }
                }
            }


            // ==================== CONTAGEM BOMBA ====================

            if (bombaAtiva)
            {
                agora =
                    chrono::steady_clock::now();

                chrono::milliseconds tempoBomba;

                tempoBomba =
                    chrono::duration_cast<chrono::milliseconds>
                    (agora - inicioBomba);


                if (tempoBomba.count() >= TEMPO_BOMBA)
                {
                    bombaAtiva = false;


                    // ==================== LIMPA EXPLOSAO ANTIGA ====================

                    for (int i = 0;
                         i < LINHAS;
                         i++)
                    {
                        for (int j = 0;
                             j < COLUNAS;
                             j++)
                        {
                            explosao[i][j] = false;
                        }
                    }


                    // ==================== CENTRO DA BOMBA ====================

                    explosao[bombaX][bombaY] = true;


                    // ==================== DIRECOES DA EXPLOSAO ====================

                    int dx[4] =
                    {
                        -1, 1, 0, 0
                    };

                    int dy[4] =
                    {
                        0, 0, -1, 1
                    };


                    // ==================== FAZ A EXPLOSAO E ALCANCE ====================

                    for (int d = 0;
                         d < 4;
                         d++)
                    {
                        for (int passo = 1;
                             passo <= ALCANCE;
                             passo++)
                        {
                            int nx =
                                bombaX +
                                dx[d] * passo;

                            int ny =
                                bombaY +
                                dy[d] * passo;


                            if (nx < 0 ||
                                nx >= LINHAS ||
                                ny < 0 ||
                                ny >= COLUNAS)
                            {
                                break;
                            }


                            if (m[nx][ny] == 1)
                            {
                                break;
                            }


                            if (m[nx][ny] == 2)
                            {
                                explosao[nx][ny] = true;

                                m[nx][ny] = 0;

                                break;
                            }


                            explosao[nx][ny] = true;
                        }
                    }


                    explosaoAtiva = true;

                    inicioExplosao =
                        chrono::steady_clock::now();


                    // ==================== VERIFICA FANTASMAS ATINGIDOS ====================

                    for (int f = 0;
                         f < NUM_FANTASMAS;
                         f++)
                    {
                        if (fantasmaAtivo[f])
                        {
                            if (explosao[
                                fantasmaX[f]
                            ][
                                fantasmaY[f]
                            ])
                            {
                                fantasmaAtivo[f] = false;
                            }
                        }
                    }
                }
            }


            // ==================== VERIFICA EXPLOSAO NO PERSONAGEM ====================

            if (explosaoAtiva)
            {
                for (int f = 0;
                     f < NUM_FANTASMAS;
                     f++)
                {
                    if (fantasmaAtivo[f] &&
                        explosao[
                            fantasmaX[f]
                        ][
                            fantasmaY[f]
                        ])
                    {
                        fantasmaAtivo[f] = false;
                    }
                }


                if (explosao[x][y])
                {
                    gameOver = true;
                }


                agora =
                    chrono::steady_clock::now();

                chrono::milliseconds tempoExplosao;

                tempoExplosao =
                    chrono::duration_cast<chrono::milliseconds>
                    (agora - inicioExplosao);


                if (tempoExplosao.count() >= TEMPO_EXPLOSAO)
                {
                    explosaoAtiva = false;
                }
            }


            // ==================== CASO VITORIA ====================

            bool todosMortos = true;

            for (int f = 0;
                 f < NUM_FANTASMAS;
                 f++)
            {
                if (fantasmaAtivo[f])
                {
                    todosMortos = false;
                }
            }

            if (todosMortos)
            {
                venceu = true;
            }


            // ==================== SAI DO JOGO ====================

            if (gameOver || venceu)
            {
                break;
            }
        }


        // ==================== RESULTADO ====================

        if (gameOver)
        {
            GameOver();

            jogarNovamente =
                TentarNovamente();

            if (jogarNovamente)
            {
                continue;
            }

            else
            {
                break;
            }
        }


        if (venceu)
        {
            Vitoria();

            jogarNovamente = false;
        }
    }


    return 0;
}
