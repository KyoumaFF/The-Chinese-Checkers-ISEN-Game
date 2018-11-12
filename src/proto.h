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

SDL_Rect click(Dames game);
void updateBoard(Dames game, SDL_Surface *screen);
void updateScreen(SDL_Surface *screen);
void displayFrame(SDL_Surface *screen);
void updateGame(Dames game, SDL_Surface *screen);

Dames initDames(int n, int m, int p1, int p2, int p3, int p4, int p5, int p6);
Dames_Case **initBoard(int n, int m, int p1, int p2, int p3, int p4, int p5, int p6);
//Dames Deplac(game, pos.x, pos.y);
void potential_Moves(Dames game, SDL_Rect pos, int jump);

void clearGreyCells(Dames game);

int testJumpOver(SDL_Rect pos, SDL_Rect temp);

void freeBoard(Dames_Case **board);
int winDames(Dames game, int part[6], int n);
int turnByTurn(Dames game, int nbplayers, int part[6], SDL_Surface *screen);
