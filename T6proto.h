typedef struct {
  SDL_Surface *hex;
  SDL_Rect pos;
  int joueur;
} Hex_Case;

typedef struct {
  Hex_Case **board;
  int sizeBoardL;
  int sizeBoardl;
} Hex;

SDL_Rect click(Hex jeu);
void updateBoard(Hex jeu, SDL_Surface *ecran);
void updateScreen(SDL_Surface *ecran);
void displayContour(SDL_Surface *ecran);
void rafraichirjeu(Hex jeu, SDL_Surface *ecran);

Hex initHex(int n, int m, int p1, int p2, int p3, int p4, int p5, int p6);
Hex_Case **initBoard(int n, int m, int p1, int p2, int p3, int p4, int p5, int p6);
//Hex Deplac(jeu, pos.x, pos.y);
void deplacements_poss(Hex jeu, SDL_Rect pos, int saut);

void clearCasesGrises(Hex jeu);

int condition(SDL_Rect pos, SDL_Rect temp);

void freeBoard(Hex_Case **board);
int winHex(Hex jeu, int part[6], int n);
int tourpartour(Hex jeu, int nbjoueurs, int part[6], SDL_Surface *ecran);
