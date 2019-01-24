Dames initDames(int n, int m, int p1, int p2, int p3, int p4, int p5, int p6){
  Dames cell;
  Dames_Case **board = initBoard(n, m, p1, p2, p3, p4, p5, p6);

  cell.board = board;
  cell.sizeBoardL = m;
  cell.sizeBoardl = n;
  return cell;
}


Dames_Case **initBoard(int n, int m, int p1, int p2, int p3, int p4, int p5, int p6){
  Dames_Case **board;
  board = (Dames_Case**) malloc(m * sizeof(Dames_Case*));
  if( board == NULL ) {
    fprintf(stderr,"Allocation failure");
    exit(EXIT_FAILURE);
  }
  for( int i = 0 ; i < m ; i++ ) {
    board[i] = (Dames_Case*) calloc (n, sizeof(Dames_Case));
    if( board[i] == NULL ) {
      fprintf(stderr,"Allocation failure");
      exit(EXIT_FAILURE);
    }
  }
  //definition de la area plateau
  for(int i=0; i < m; i++){
    for(int j=0; j < n; j++){
      board[i][j].pos.x = 0;
      board[i][j].pos.y = 0;
      board[i][j].cell = NULL;
      board[i][j].player = 0;
    }
  }
  for(int i=0; i<m; i++){
    if(i<5){
      for(int j=0; j<4; j++) { //avant la pointe haute
            board[i][j].player = 9;
            }
      for(int j=(6+i); j<(11-i); j++){ //avant la partie mediane
            board[i][j].player = 9;
            }
      for(int j=13; j<n; j++){ //avant la pointe basse
            board[i][j].player = 9;
            }
    }
  if(i>7){
    for(int j=0; j<4; j++) { //après la pointe haute
          board[i][j].player = 9;
    }
    for(int j=13; j<n; j++){ //apres la pointe basse
          board[i][j].player = 9;
    }
  }
  if(i==12){
      for(int j=6; j<11; j++) { //après la pointe haute
            board[i][j].player = 9;
      }
  }
}

board[2][8].player = 0;
board[0][5].player =9;
board[5][0].player = 9;
board[5][1].player = 9;
board[7][0].player = 9;
board[8][3].player = 0;
board[0][11].player = 9;
board[2][8].player = 0;
board[5][15].player = 9;
board[5][16].player = 9;
board[7][16].player = 9;
board[8][13].player = 0;
board[11][8].player = 9;

//initialisations des triangles
int p[6]={p1,p2,p3,p4,p5,p6};

int tabp[120]= {6,0,6,1,7,1,5,2,6,2,7,2,5,3,6,3,7,3,8,3,
                12,4,11,4,12,5,10,4,11,5,11,6,9,4,10,5,10,6,11,7,
                12,12,12,11,11,12,11,10,11,11,10,12,11,9,10,10,10,11,9,12,
                6,16,7,15,6,15,7,14,6,14,5,14,8,13,7,13,6,13,5,13,
                0,12,1,12,1,11,2,12,2,11,1,10,3,12,3,11,2,10,2,9,
                0,4,1,5,1,4,1,6,2,5,2,4,2,7,2,6,3,5,3,4};

for (int i=0; i<60; i++){
  board[ tabp[2*i] ] [ tabp[1+(2*i)] ].player = p[(i/10)];
}
return board;
}

void potential_Moves(Dames game, SDL_Rect pos, int jump){

int area2[12]={pos.x-1, pos.y-2,   pos.x-2, pos.y,   pos.x-1, pos.y+2,
                pos.x+1, pos.y-2,  pos.x+2, pos.y,  pos.x+1, pos.y+2};

int area[12];

if((pos.y%2)==0){
  int area[12]={pos.x, pos.y-1,   pos.x-1, pos.y,   pos.x, pos.y+1,
                pos.x+1, pos.y-1,  pos.x+1, pos.y,  pos.x+1, pos.y+1};
}
else{
  int area[12]={pos.x-1, pos.y-1,   pos.x-1, pos.y,   pos.x-1, pos.y+1,
                pos.x, pos.y-1,  pos.x+1, pos.y,  pos.x, pos.y+1};
}

for(int i=0; i<6; i++){ //Si on s'approche du bord du tableau
  if(area[i*2]<0 || area[i*2]>12 || area[(i*2)+1]<0 || area[(i*2)+1]>16){
    area[i*2]=0;
    area[(i*2)+1]=0;
  }
  if(area2[i*2]<0 || area2[i*2]>12 || area2[(i*2)+1]<0 || area2[(i*2)+1]>16){
    area2[i*2]=0;
    area2[(i*2)+1]=0;
  }
}

for(int i=0; i<6; i++){
  if(game.board[area[i*2]][area[(i*2)+1]].player != 9){

    //Si il s'agit donc d'un pion
    if(game.board[area[i*2]][area[(i*2)+1]].player != 0){
      if(jump!=0 && game.board[area2[i*2]][area2[(i*2)+1]].player == 0)
        {game.board[area2[i*2]][area2[(i*2)+1]].player = 8;}
    }

    //Si il s'agit d'un espace libre
    else{
      if(jump==-1){
        game.board[area[i*2]][area[(i*2)+1]].player = 8; //Si on est au premier turn on peut jumper a cote
      }
    }

  }
}
}

void clearGreyCells(Dames game){
  for(int i=0; i<13; i++){
    for(int j=0; j<17; j++){
      if(game.board[i][j].player == 8){
        game.board[i][j].player = 0;
      }
    }
  }
}

int testJumpOver(SDL_Rect pos, SDL_Rect temp){
 if(temp.x>=pos.x-1 && temp.x<=pos.x+1 && temp.y>=pos.y-1 && temp.y<=pos.y+1){
   return(0);
 }
return 1;
}

int winDames(Dames game, int part[6], int n){
  //table decalée de 3 pour les verifications
  int tabp[120]= {6,16,7,15,6,15,7,14,6,14,5,14,8,13,7,13,6,13,5,13,
                  0,12,1,12,1,11,2,12,2,11,1,10,3,12,3,11,2,10,2,9,
                  0,4,1,5,1,4,1,6,2,5,2,4,2,7,2,6,3,5,3,4,
                  6,0,6,1,7,1,5,2,6,2,7,2,5,3,6,3,7,3,8,3,
                  12,4,11,4,12,5,10,4,11,5,11,6,9,4,10,5,10,6,11,7,
                  12,12,12,11,11,12,11,10,11,11,10,12,11,9,10,10,10,11,9,12};

  int comptj=0, comptpion=0;

  for (int i=0; i<60; i++){
    if(part[(i/10)]==n){
      comptj+=1;
      if(game.board[ tabp[2*i] ] [ tabp[1+(2*i)] ].player == n)
        {comptpion+=1;}
    }
  }
  if(comptj==comptpion){
    /*
    int victory[44]={4,0, 4,1, 3,2, 2,2, 1,2,
                      8,0, 9,1, 9,2, 10,2, 11,2,
                      0,8, 12,8,
                      8,16, 9,15, 9,14, 10,14, 11,14,
                      4,16, 4,15, 3,14, 2,14, 1,14};
    for(int i=0; i<22; i++){
      game.board[ victory[2*i] ] [ victory[1+(2*i)] ].player = n;
    }*/
  return(1);
  }
return(0);
}

int turnByTurn(Dames game,int nbplayers, int part[6], SDL_Surface *screen){
  int turn = 0;
  int n=1;
  while(winDames(game, part, n) == 0){

    n =(turn%nbplayers)+1;
    SDL_Rect pos, temp;
    SDL_Rect start; //empeche de revenir au meme tableau

    updateGame(game, screen);
    updateInfoTour(n, screen);
    //On chosit une première case
    do{
      pos = clickBoard(game, screen);
    }while(game.board[pos.x][pos.y].player != n);

    game.board[pos.x][pos.y].player = n+10;
    updateGame(game, screen);
    updateInfoTour(n, screen);

    int jump = -1;
    do{
      potential_Moves(game, pos, jump);
      updateGame(game, screen);
      updateInfoTour(n, screen);

      //Si c'est le premier jump
      if(jump == -1){
        do{
          temp=clickBoard(game, screen);
        }while(game.board[temp.x][temp.y].player != 8 && game.board[temp.x][temp.y].player != n );

        //Si on choisit une autre case finalement
        if(game.board[temp.x][temp.y].player == n){
          game.board[pos.x][pos.y].player = n;
          pos = temp;
          game.board[pos.x][pos.y].player = n+10;
          clearGreyCells(game); //Efface les case grises
        }
        //Sinon on jumpe
        else{
          jump = testJumpOver(pos, temp); //Determine si on jumpe un pion
          game.board[pos.x][pos.y].player = 0;
          if(jump==0){
          pos = temp;
          game.board[pos.x][pos.y].player = n;
          }
          if(jump==1){
          start = pos; //enregistre la pos de start
          pos = temp;
          game.board[pos.x][pos.y].player = n+10;
          updateGame(game, screen);
          updateInfoTour(n, screen);
          }
          clearGreyCells(game);
        }
      }

      //Si c'est pas le premier jump
      else{
        do{
          temp=clickBoard(game, screen);
        }while(game.board[temp.x][temp.y].player != 8 && game.board[temp.x][temp.y].player != (n+10) );

        //Si on s'arrete à sa position
        if(game.board[temp.x][temp.y].player == (n+10) && (start.x != temp.x || start.y != temp.y) ){
          jump = 0;
          game.board[pos.x][pos.y].player = n;
          clearGreyCells(game);
        }
        //Si on continue de jumper
        else{
          game.board[pos.x][pos.y].player = 0;
          pos = temp;
          game.board[pos.x][pos.y].player = n+10;
          clearGreyCells(game);
        }
      }

    }while(jump!=0);
  turn++;
  }
return(n);
}

void freeDames(Dames cell){
  free(cell.board);
  cell.board = NULL;
}
