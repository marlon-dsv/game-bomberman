#include <iostream>             //ENTRADA E SAIDA DE DADOS
#include <windows.h>            //TRECHO QUE NAO DEVE SER MODIFICADO
#include <conio.h>              //TRECHO QUE NAO DEVE SER MODIFICADO
#include <chrono>               //UTILIZADA PARA TIRAR LENTIDAO
#include <cstdlib>              //UTILIZADA PARA O RAND
#include <ctime>                //UTILIZADA PARA O RAND

using namespace std;


// ==================== MENU ====================

int Menu(){
    int opcao;

    system("cls");

    cout << "==============================\n";
    cout << "           BOMBERMAN\n";
    cout << "==============================\n\n";

    cout << "   1 - Jogar\n";
    cout << "   2 - Sair\n";
    cout << "   3 - Creditos\n\n";

    cout << "Escolha: ";
    cin >> opcao;

    if(opcao != 1 && opcao != 2 && opcao != 3)
    {
        cout << "\nOpcao invalida!\n";

        system("pause");

        return 0;
    }

    return opcao;
}


void Creditos(){
    system("cls");

    cout << "==============================\n";
    cout << "           CREDITOS\n";
    cout << "==============================\n\n";

    cout << "   Criado para a disciplina AP2, por:\n";
    cout << "   - Aluno Marcelo\n";
    cout << "   - Aluno Marlon Vritzl\n";
    cout << "   - Aluno João\n";

    system("pause");
}


void GameOver(){
    system("cls");

    cout << "==============================\n";
    cout << "          GAME OVER!\n";
    cout << "==============================\n\n";

    cout << "Voce perdeu!\n\n";

    system("pause");
}


void Vitoria(){
    system("cls");

    cout << "==============================\n";
    cout << "         VOCE VENCEU!\n";
    cout << "==============================\n\n";

    system("pause");
}


bool TentarNovamente(){

    char resposta;

    system("cls");

    cout << "==============================\n";
    cout << "       TENTAR NOVAMENTE?\n";
    cout << "==============================\n\n";

    cout << "   1 - Sim\n";
    cout << "   0 - Nao\n\n";

    cout << "Escolha: ";
    cin >> resposta;

    if(resposta == '1')
    {
        return true;
    }

    return false;
}


// ==================== MAIN ====================

int main()
{
    // ==================== TRECHO QUE NAO DEVE SER MODIFICADO ====================

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

    do{
        opcao = Menu();

        if(opcao == 2){
            system("cls");

            cout << "=============================\n";
            cout << "       SAINDO DO JOGO\n";
            cout << "=============================\n";

            return 0;
        }

        if(opcao == 3){
            Creditos();
        }

    } while(opcao != 1);


    // ==================== JOGO ====================

    bool jogarNovamente = true;

    while(jogarNovamente)
    {
        // ==================== TRECHO QUE NAO DEVE SER MODIFICADO ====================

        // ==================== MAPA ====================

        const int LINHAS = 13;
        const int COLUNAS = 39;

        /*
            0 = espaco livre
            1 = parede
            2 = bloco destrutivel
        */

        int m[LINHAS][COLUNAS] =
        {
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,

            1,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,1,

            1,0,1,0,1,0,1,0,1,0,1,2,1,2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,

            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,2,0,2,0,0,0,0,0,0,0,2,0,1,

            1,2,1,0,1,0,1,0,1,0,1,2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,

            1,0,0,0,0,0,0,0,2,0,0,2,0,0,2,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1,

            1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,

            1,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,

            1,2,1,0,1,0,1,0,1,2,1,0,1,0,1,0,1,0,1,0,1,0,1,2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,

            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,2,2,2,2,2,0,0,2,0,0,0,0,1,

            1,0,1,0,1,0,1,0,1,0,1,0,1,2,1,0,1,0,1,0,1,2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,

            1,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,2,0,2,2,0,0,0,1,

            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
        };

        // ==================== FIM DO TRECHO QUE NAO DEVE SER MODIFICADO ====================


        // ==================== JOGADOR ====================

        int x = 1;
        int y = 1;


        // ==================== FANTASMAS ====================

        const int NUM_FANTASMAS = 5;

        int fantasmaX[NUM_FANTASMAS] = { 11, 1, 5, 7, 9 };

        int fantasmaY[NUM_FANTASMAS] = { 37, 35, 20, 30, 15 };

        bool fantasmaAtivo[NUM_FANTASMAS] = { true, true, true, true, true };


        // ==================== TEMPO DOS FANTASMAS ====================

        chrono::steady_clock::time_point ultimoMovimentoFantasma;

        ultimoMovimentoFantasma =
            chrono::steady_clock::now();

        const int TEMPO_FANTASMA = 500;


        // ==================== BOMBA ====================

        bool bombaAtiva = false;

        int bombaX = -1;
        int bombaY = -1;

        chrono::steady_clock::time_point inicioBomba;

        inicioBomba = chrono::steady_clock::now();

        const int TEMPO_BOMBA = 1000;


        // ==================== EXPLOSAO ====================

        bool explosaoAtiva = false;

        chrono::steady_clock::time_point inicioExplosao;

        inicioExplosao = chrono::steady_clock::now();

        const int TEMPO_EXPLOSAO = 500;

        const int ALCANCE = 1;

        bool explosao[LINHAS][COLUNAS] = {false};

        bool gameOver = false;
        bool venceu = false;


        // ==================== GERAÇÃO DE NUMEROS ALEATORIOS ====================

        srand(time(NULL));


        // ==================== LOOP DO JOGO ====================

        while(true)
        {
            // ==================== TRECHO QUE NAO DEVE SER MODIFICADO ====================

            // ==================== POSICIONA O CURSOR NO INICIO DO CONSOLE ====================

            SetConsoleCursorPosition(
                GetStdHandle(STD_OUTPUT_HANDLE),
                coord
            );


            // ==================== DESENHA O MAPA ====================

            for(int i = 0; i < LINHAS; i++){
                for(int j = 0; j < COLUNAS; j++)
                {
                    if(i == x && j == y)
                    {
                        cout << "J";
                    }

                    else
                    {
                        bool desenhouFantasma = false;

                        for(int f = 0; f < NUM_FANTASMAS; f++){
                            if(fantasmaAtivo[f] &&
                               i == fantasmaX[f] &&
                               j == fantasmaY[f])
                            {
                                cout << "H";

                                desenhouFantasma = true;

                                break;
                            }
                        }


                        if(!desenhouFantasma)
                        {
                            if(explosaoAtiva && explosao[i][j])
                            {
                                cout << "*";
                            }

                            else if(bombaAtiva &&
                                    i == bombaX &&
                                    j == bombaY)
                            {
                                cout << "O";
                            }

                            else
                            {
                                if(m[i][j] == 0)
                                    cout << " ";

                                else if(m[i][j] == 1)
                                    cout << char(219);

                                else if(m[i][j] == 2)
                                    cout << char(178);
                            }
                        }
                    }
                }

                cout << "\n";
            }


            // ==================== CONTROLES ====================

            if(_kbhit())
            {
                char tecla = getch();

                int novoX = x;
                int novoY = y;


                if(tecla == 72 || tecla == 'w' || tecla == 'W')
                {
                    novoX--;
                }

                else if(tecla == 80 || tecla == 's' || tecla == 'S')
                {
                    novoX++;
                }

                else if(tecla == 75 || tecla == 'a' || tecla == 'A')
                {
                    novoY--;
                }

                else if(tecla == 77 || tecla == 'd' || tecla == 'D')
                {
                    novoY++;
                }

                else if(tecla == 32)
                {
                    if(!bombaAtiva)
                    {
                        bombaAtiva = true;

                        bombaX = x;
                        bombaY = y;

                        inicioBomba =
                            chrono::steady_clock::now();
                    }
                }


                if(novoX >= 0 &&
                   novoX < LINHAS &&
                   novoY >= 0 &&
                   novoY < COLUNAS)
                {
                    if(m[novoX][novoY] == 0)
                    {
                        x = novoX;
                        y = novoY;
                    }
                }
            }

            // ==================== FIM DO TRECHO QUE NAO DEVE SER MODIFICADO ====================


            // ==================== MOVIMENTO DOS FANTASMAS ====================

            chrono::steady_clock::time_point agora;

            agora = chrono::steady_clock::now();

            chrono::milliseconds tempoFantasma;

            tempoFantasma = chrono::duration_cast<chrono::milliseconds>
                            (agora - ultimoMovimentoFantasma);

            if(tempoFantasma.count() >= TEMPO_FANTASMA)
            {
                ultimoMovimentoFantasma = chrono::steady_clock::now();

                for(int f = 0; f < NUM_FANTASMAS; f++)
                {
                    if(!fantasmaAtivo[f])
                        continue;

                    int novoX = fantasmaX[f];
                    int novoY = fantasmaY[f];

                    int direcao = rand() % 4;

                    if(direcao == 0)
                        novoX--;

                    else if(direcao == 1)
                        novoX++;

                    else if(direcao == 2)
                        novoY--;

                    else
                        novoY++;


                    if(novoX >= 0 &&
                       novoX < LINHAS &&
                       novoY >= 0 &&
                       novoY < COLUNAS)
                    {
                        if(m[novoX][novoY] == 0)
                        {
                            fantasmaX[f] = novoX;
                            fantasmaY[f] = novoY;
                        }
                    }
                }
            }


            // ==================== COLISAO COM FANTASMAS ====================

            for(int f = 0; f < NUM_FANTASMAS; f++)
            {
                if(fantasmaAtivo[f]) {
                    if(x == fantasmaX[f] &&
                       y == fantasmaY[f])
                    {
                        gameOver = true;
                    }
                }
            }


            // ==================== BOMBA ====================

            if(bombaAtiva)
            {
                agora = chrono::steady_clock::now();

                chrono::milliseconds tempoBomba;

                tempoBomba = chrono::duration_cast<chrono::milliseconds>
                             (agora - inicioBomba);

                if(tempoBomba.count() >= TEMPO_BOMBA)
                {
                    bombaAtiva = false;


                    // ==================== LIMPA EXPLOSAO ANTIGA ====================

                    for(int i = 0; i < LINHAS; i++)
                    {
                        for(int j = 0; j < COLUNAS; j++)
                        {
                            explosao[i][j] = false;
                        }
                    }


                    // ==================== CENTRO DA BOMBA ====================

                    explosao[bombaX][bombaY] = true;


                    // ==================== DIRECOES DA EXPLOSAO ====================

                    int dx[4] = {-1, 1, 0, 0};
                    int dy[4] = {0, 0, -1, 1};


                    // ==================== FAZ A EXPLOSAO ====================

                    for(int d = 0; d < 4; d++)
                    {
                        for(int passo = 1;
                            passo <= ALCANCE;
                            passo++)
                        {
                            int nx = bombaX + dx[d] * passo;
                            int ny = bombaY + dy[d] * passo;


                            if(nx < 0 ||
                               nx >= LINHAS ||
                               ny < 0 ||
                               ny >= COLUNAS)
                            {
                                break;
                            }


                            if(m[nx][ny] == 1)
                            {
                                break;
                            }


                            if(m[nx][ny] == 2)
                            {
                                explosao[nx][ny] = true;

                                m[nx][ny] = 0;

                                break;
                            }

                            explosao[nx][ny] = true;
                        }
                    }


                    explosaoAtiva = true;

                    inicioExplosao = chrono::steady_clock::now();


                    // ==================== VERIFICA QUAIS FANTASMAS FORAM ATINGIDOS ====================

                    for(int f = 0; f < NUM_FANTASMAS; f++)
                    {
                        if(fantasmaAtivo[f])
                        {
                            if(explosao[
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


            // ==================== EXPLOSAO ====================

            if(explosaoAtiva)
            {
                if(explosao[x][y])
                {
                    gameOver = true;
                }

                agora = chrono::steady_clock::now();

                chrono::milliseconds tempoExplosao;

                tempoExplosao = chrono::duration_cast<chrono::milliseconds>
                                (agora - inicioExplosao);

                if(tempoExplosao.count() >= TEMPO_EXPLOSAO)
                {
                    explosaoAtiva = false;
                }
            }


            // ==================== VITORIA ====================

            bool todosMortos = true;


            for(int f = 0; f < NUM_FANTASMAS; f++)
            {
                if(fantasmaAtivo[f])
                {
                    todosMortos = false;
                }
            }

            if(todosMortos)
            {
                venceu = true;
            }


            // ==================== SAI DO JOGO ====================

            if(gameOver || venceu)
            {
                break;
            }
        }


        // ==================== RESULTADO ====================

        if(gameOver)
        {
            GameOver();


            // ==================== PERGUNTA SE QUER JOGAR NOVAMENTE ====================

            jogarNovamente = TentarNovamente();

            if(jogarNovamente)
            {
                continue;
            }

            else
            {
                break;
            }
        }


        if(venceu)
        {
            Vitoria();

            jogarNovamente = false;
        }
    }


    return 0;
}