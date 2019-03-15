typedef struct {
  SDL_Surface *cell;
  SDL_Rect pos;
  int player;
} Dames_Case;

typedef struct {
  Dames_Case **board;
  int sizeBoardL;
  int sizeBoardl;
} Dames;

typedef struct {
  char *text;
  SDL_Surface *surface;
  SDL_Rect pos;
  SDL_Color rgb;
  void (*function)();
} Button;

SDL_Rect click(Dames game);
void updateBoard(Dames game, SDL_Surface *screen);
void updateScreen(SDL_Surface *screen);
void displayFrame(SDL_Surface *screen);
void updateGame(Dames game, SDL_Surface *screen);
void updateInfoTour(int n, SDL_Surface *screen);

Dames initDames(int n, int m, int p1, int p2, int p3, int p4, int p5, int p6);
Dames_Case **initBoard(int n, int m, int p1, int p2, int p3, int p4, int p5, int p6);
//Dames Deplac(game, pos.x, pos.y);
void potential_Moves(Dames game, SDL_Rect pos, int jump);

void clearGreyCells(Dames game);

int testJumpOver(SDL_Rect pos, SDL_Rect temp);

void freeBoard(Dames_Case **board);
int winDames(Dames game, int part[6], int n);
int turnByTurn(Dames game, int nbplayers, int part[6], SDL_Surface *screen);
void freeDames(Dames cell);

//MENU CONFIG
void menu_main(SDL_Surface *screen);
void settings(SDL_Surface *screen);
void game_config(SDL_Surface *screen);

void set_game_nbplayers(SDL_Surface *screen);
void nbplayersEq2(SDL_Surface *screen);void nbplayersEq3(SDL_Surface *screen);
void nbplayersEq4(SDL_Surface *screen);void nbplayersEq6(SDL_Surface *screen);

void set_game_nbparts(SDL_Surface *screen);
void nbpartsEq1(SDL_Surface *screen);
void nbpartsEq2(SDL_Surface *screen);
void nbpartsEq3(SDL_Surface *screen);

void set_boardParts(SDL_Surface *screen);
void comptplus_modepart(SDL_Surface *screen);
void comptminus_modepart(SDL_Surface *screen);
void validparts(SDL_Surface *screen);

void set_boardMode(SDL_Surface *screen);

void set_playersStates(SDL_Surface *screen);
void comptplus_player(SDL_Surface *screen);
void comptminus_player(SDL_Surface *screen);
void validcolor(SDL_Surface *screen);
void echangStates(int comptcolor,int comptplayer);
void game_config_2(SDL_Surface *screen);

void game(SDL_Surface *screen);
void rules0(SDL_Surface *screen);
void rules1(SDL_Surface *screen);
void rules2(SDL_Surface *screen);
void rules3(SDL_Surface *screen);

//MENU
SDL_Color colorConverter(unsigned long hexValue);

void initMenu(char font_name[]);

void displayImg(SDL_Surface *screen, int x, int y, char url[]);
void displayColor(SDL_Surface *screen, int hexColor);

SDL_Surface *initText(char text[], int fontSize, int hexColorFont, int params);
void displayText(SDL_Surface *surface, SDL_Surface *textSurface, int x, int y);
void displayParagraph(SDL_Surface *surface, SDL_Surface **textSurface, int x, int y, int nbLine);
void displayParagraphCenter(SDL_Surface *surface, SDL_Surface **textSurface, int y, int nbLine);

Button initButtonImgText(int x, int y, char text[], int fontSize,
  int hexColor, int params, char url[100], void (*function)());

Button initButtonImg(int x, int y, char url[100], void (*function)());
Button initButtonRect(
      int x, int y, int w, int h,
      int hexColorRect, char text[], int fontSize, int hexColorFont,
      int params, void (*function)()
    );

void displayButton(Button button, SDL_Surface *screen);
void displayMenu(Button menu[], SDL_Surface *screen, int nbButton);

int clickButton(Button button, SDL_Event event);
int waitEvent(Button menu[], SDL_Surface *screen, int nbButton);

//IA
Dames copyDames(Dames boardtocopy);
void TableauTaillePionsInit(Dames* TableauTaillePions, Dames TabInit);
int griserTabPions(Dames *TableauTaillePions, int playerIA);
void TableauTailleGrisInit(Dames* TableauTailleGris, Dames* TableauTaillePions, int nbgris);
void playgris(Dames* TableauTailleGris, Dames* TableauTaillePions);
int turnByTurnIA(Dames game,int nbplayers, int part[6], SDL_Surface *screen);
void turnIA(int playerIA, Dames TabInit);
