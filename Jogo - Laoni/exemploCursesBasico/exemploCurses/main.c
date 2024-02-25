// https://pubs.opengroup.org/onlinepubs/7908799/xcurses/curses.h.html

#include <curses.h>
#include <stdlib.h>
#include <time.h>

// 8 colors for standard Curses
#define PALLETE_SIZE (COLOR_WHITE - COLOR_BLACK + 1)

// Estrutura com estado interno da aplicação
typedef struct gameData
{
    int ultimaTecla;
    int velocidade_alien;
} gameData;

typedef struct alien
{
    int x_alien;
    int y_alien;
} alien;

//////////////////////////////////////////////////////////////////////
// Funções auxiliares para a biblioteca Curses
//////////////////////////////////////////////////////////////////////
void initScreen()
{
#ifdef XCURSES
    Xinitscr(argc, argv);
#else
    initscr();
#endif

    if (has_colors())
    {
        int bg = 0, fg = 0;

        start_color();

        for(bg = COLOR_BLACK; bg <= COLOR_WHITE; bg++)
            for(fg = COLOR_BLACK; fg <= COLOR_WHITE; fg++)
                init_pair(bg*PALLETE_SIZE + fg + 1, fg, bg); // color 0 is system default (reserved)
    }

    // Trata a tecla Enter como \n
    //nl();
    // Teclas digitadas pelo usuário não aparecem na tela
    noecho();
    // 0 para cursor invisível
    curs_set(0);
    // Define getch como non-blocking de acordo com o timeout abaixo
    nodelay(stdscr, TRUE);
    // Timeout em 0 determina getch como non-blocking, não espera entrada do usuário
    timeout(0);
    // Habilita teclas de function (F1, F2, ...), flechas, etc
    keypad(stdscr, TRUE);
}

void setColor(short int fg, short int bg, chtype attr)
{
    chtype color = COLOR_PAIR(bg*PALLETE_SIZE + fg + 1);
    color |= attr;
    attrset(color);
}


//////////////////////////////////////////////////////////////////////
// Funções da aplicação
//////////////////////////////////////////////////////////////////////
void initGame(gameData * game)
{
    game->ultimaTecla = 1;
}

// Gerencia entradas do usuário e controla o estado interno em game
// Há diversas opções de teclas na Curses, como KEY_UP, KEY_DOWN, etc.
void handleInputs(gameData * game)
{
    int entrada = getch();
    int vertical = 0, horizontal = 0;

    if(entrada != -1)
        game->ultimaTecla = entrada;

    switch(game->ultimaTecla)
    {
        case 'q':
        case 'Q':
            curs_set(1);
            endwin();
            exit(EXIT_SUCCESS);
            break;
        case KEY_RESIZE:
            // Finaliza a tela atual e cria uma nova
            endwin();
            initScreen();

            clear();
            refresh();

            break;
    }
}

void doUpdate(gameData * game)
{
    game->velocidade_alien = (game->velocidade_alien + 1)%20;
}


void drawScreen(gameData * game)
{
    srand( (unsigned)time(NULL) );
    int fg = 0, bg = 0, i = 0;
    static int y_torreta = 0, x_torreta = 33, indice_binario = 0, y_bala = 13, n_aliens = 0, activated_alien[7], acionar = 0;
    clear();

    printw("%d", game->velocidade_alien);

    static struct alien aliens[7];

    //gera posicoes aleatorias para o spawn de aliens
    if(activated_alien[n_aliens] == 0){
        aliens[n_aliens].x_alien = (rand() % 7)*8 + 26;
    }

    if(n_aliens == 7)
        n_aliens = 0;
    //if(n_aliens < 7)
    //n_aliens++;

    setColor(COLOR_BLUE, COLOR_BLACK, 0);

    for(i = 30; i < 86; i++){
        setColor(COLOR_WHITE, COLOR_BLACK, 0);
        mvaddch(0, i+1, ACS_HLINE);
    }
    mvaddch(0, 30, ACS_BSSB);
    for(i = 0; i < 15; i++){
        setColor(COLOR_WHITE, COLOR_BLACK, 0);
        mvaddch(i+1, 30, ACS_VLINE);
    }
    mvaddch(16, 30, ACS_SSBB);
    for(i = 30; i < 86; i++){
        setColor(COLOR_WHITE, COLOR_BLACK, 0);
        mvaddch(16, i+1, ACS_HLINE);
    }
    mvaddch(0, 86, ACS_BBSS);
    for(i = 0; i < 15; i++){
        setColor(COLOR_WHITE, COLOR_BLACK, 0);
        mvaddch(i+1, 86, ACS_VLINE);
    }
    mvaddch(16, 86, ACS_SBBS);

    //tubulacoes
    for(i = 0; i < 1; i++){
        setColor(COLOR_WHITE, COLOR_BLACK, 0);
        mvaddch(i+1, 38, ACS_VLINE);
    }
    for(i = 0; i < 1; i++){
        setColor(COLOR_WHITE, COLOR_BLACK, 0);
        mvaddch(i+1, 46, ACS_VLINE);
    }
    for(i = 0; i < 1; i++){
        setColor(COLOR_WHITE, COLOR_BLACK, 0);
        mvaddch(i+1, 54, ACS_VLINE);
    }
    for(i = 0; i < 1; i++){
        setColor(COLOR_WHITE, COLOR_BLACK, 0);
        mvaddch(i+1, 62, ACS_VLINE);
    }
    for(i = 0; i < 1; i++){
        setColor(COLOR_WHITE, COLOR_BLACK, 0);
        mvaddch(i+1, 70, ACS_VLINE);
    }
    for(i = 0; i < 1; i++){
        setColor(COLOR_WHITE, COLOR_BLACK, 0);
        mvaddch(i+1, 78, ACS_VLINE);
    }
    for(i = 0; i < 1; i++){
        setColor(COLOR_WHITE, COLOR_BLACK, 0);
        mvaddch(i+1, 86, ACS_VLINE);
    }
    printw("\n");

    switch(game->ultimaTecla){
        //tela inicial
        case 1:
            break;
        case 260:
            if(x_torreta >= 38)
                x_torreta = x_torreta - 8;
            game->ultimaTecla = -2;
            break;
        case 261:
            if(x_torreta < 80)
                x_torreta = x_torreta + 8;
            game->ultimaTecla = -2;
            break;
        case 32:
            acionar = 1;
            game->ultimaTecla = -2;
            break;
    }
    setColor(COLOR_CYAN, COLOR_BLACK, 0);
    mvaddch(14, x_torreta+2, ACS_VLINE);
    mvaddch(14, x_torreta, ACS_VLINE);
    mvaddch(14, x_torreta+1, ACS_BULLET);
    mvaddch(13, x_torreta+1, ACS_S9);
    setColor(COLOR_CYAN, COLOR_BLACK, 0);
    mvaddch(15, x_torreta+2, ACS_BLOCK);
    mvaddch(15, x_torreta+1, ACS_BLOCK);
    mvaddch(15, x_torreta, ACS_BLOCK);
    if(acionar == 1){
        setColor(COLOR_YELLOW, COLOR_BLACK, 0);
        mvaddch(y_bala, x_torreta+1, ACS_DEGREE);
        if(y_bala > 0){
            y_bala--;        }
        if(y_bala == 0){
            y_bala = 13;
            acionar = 3;
        }
    }
    if(aliens[n_aliens].y_alien < 16){
        setColor(COLOR_BLACK, COLOR_RED, 0);
        mvaddch(aliens[n_aliens].y_alien+1, aliens[n_aliens].x_alien + 8, ACS_DEGREE);
        //mvaddch(alien1.y_alien+3, alien1.x_alien + 8, ACS_S9);
        setColor(COLOR_RED, COLOR_BLACK, 0);
        mvaddch(aliens[n_aliens].y_alien+1, aliens[n_aliens].x_alien + 7, ACS_LARROW);
        mvaddch(aliens[n_aliens].y_alien+1, aliens[n_aliens].x_alien + 9, ACS_RARROW);
        n_aliens++;
    }
    if(game->velocidade_alien == 0){
        if(aliens[n_aliens].y_alien < 16){
            aliens[n_aliens].y_alien++;
            activated_alien[n_aliens] = 1;
        }
        if(aliens[n_aliens].y_alien == 16){
            aliens[n_aliens].y_alien = 0;
            activated_alien[n_aliens] = 0;
        }
    }
    // Exibe o conteúdo na tela (stdscr), getch() também ativa um refresh
    refresh();
}

int main(int argc, char *argv[])
{
    // estrutura com dados internos da aplicação
    gameData game;

    // inicializa a tela pelo Curses e o estado inicial da aplicação
    initScreen();
    initGame(&game);

    // Laço principal sem retorno, pode ser removido para exibição direta de informação na tela
	while(1)
    {
        // Gerencia entradas do usuário pelo teclado
        handleInputs(&game);

        // Gerencia lógica da aplicação
        doUpdate(&game);

        // Atualiza a tela
        drawScreen(&game);

        // Controla o FPS da aplicação
        napms(10);
    }

    // Encerra a tela inicializada em initScreen
    endwin();

	return 0;
}
