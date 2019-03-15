int playerIA, nbgris;
Dames *TableauTaillePions, *TableauTailleGris;

Dames copyDames(Dames boardtocopy){
  Dames copy;
  Dames_Case **board =initBoard(17,13, 0,0,0,0,0,0);

  copy.board=board;
  copy.sizeBoardL = boardtocopy.sizeBoardl /*17*/;
  copy.sizeBoardl = boardtocopy.sizeBoardL /*13*/;

  for(int i=0; i<copy.sizeBoardl; i++){
    for(int j=0; j<copy.sizeBoardL; j++){
      copy.board[i][j] = boardtocopy.board[i][j];
    }
  }
  return copy;
}

void TableauTaillePionsInit(Dames* TableauTaillePions, Dames TabInit){

    TableauTaillePions = (Dames*) malloc(10*sizeof(Dames));
    if(TableauTaillePions == NULL){fprintf(stderr,"Allocation impossible");exit(EXIT_FAILURE);}

    for(int i=0;i<10;i++){
      TableauTaillePions[i]=copyDames(TabInit);
    }
}

int griserTabPions(Dames *TableauTaillePions, int playerIA){ //Va griser chacun des pions possibles.
  int gris=0;
  for(int numTab=1; numTab<11/*((10*modeparts)+1)*/; numTab++){ //Pour parcourir les pions de toutes les pointes
    int compt=0; //Pour griser une case différente à chaque fois.
    SDL_Rect pospion;
    for(int i=0; i<17; i++){
      for(int j=0; j<13; j++){
        if(TableauTaillePions[numTab-1].board[i][j].player == playerIA){
            //PROBLEMEcompt++; pospion.x=i; pospion.y=j; //Enregistre la pos du pion n
            //if(compt==numTab){potential_Moves(TableauTaillePions[numTab-1], pospion, -1);} //si le nieme pion du nime tableau alors le griser
        }
      }
    }
    /*for(int numTab=1; numTab<11/*((10*modeparts)+1)*//*; numTab++){ //Pour compter le nombre total de cases grises.
      for(int i=0; i<17; i++){
        for(int j=0; j<13; j++){
          if(TableauTaillePions[numTab-1].board[i][j].player == 8){gris++;}
        }
      }
    }*/
  }
return gris;
}



void TableauTailleGrisInit(Dames* TableauTailleGris, Dames* TableauTaillePions, int nbgris){

  TableauTailleGris = (Dames*) malloc(nbgris*sizeof(Dames));
  if(TableauTailleGris == NULL){fprintf(stderr,"Allocation impossible");exit(EXIT_FAILURE);}

  for(int i=0;i<nbgris;i++)
    {TableauTailleGris[i].board=initBoard(13,17, 0,0,0,0,0,0);}

  int pos=0;
  for(int b=0;b<(10*modeparts);b++){
    int cgris=0;
    for(int i=0; i<13; i++){
      for(int j=0; j<17; j++){
        if(TableauTaillePions[b].board[i][j].player == 8){cgris++;}
      }
    }
    for(int a=pos;a<(pos+cgris);a++){
      TableauTailleGris[a]=copyDames(TableauTaillePions[b]);
    }
    pos+=cgris;
  }
}

void playgris(Dames* TableauTailleGris, Dames* TableauTaillePions){
  //init gris
  int posgris=0;
  for(int numTab=1; numTab<((10*modeparts)+1); numTab++){ //Pour parcourir les pions de toutes les pointes
    int comptgris=0; //Pour compter le nb de cases grises.
    SDL_Rect pospion;
    for(int i=0; i<13; i++){
      for(int j=0; j<17; j++){
        if(TableauTaillePions[numTab-1].board[i][j].player == playerIA){comptgris++;} //compte le nb de cases grises du tab
        if(TableauTaillePions[numTab-1].board[i][j].player == playerIA+10){pospion.x=i; pospion.y=j;} //Enregistre la pos du pion grisé
      }
    }

    //playgris
    for(int comptab_g=0;comptab_g<(posgris+comptgris);++comptab_g){ //Parcours les tableaux gris issus du pion n
      int comptpions_g=0; //compteur de pions gris trouvés
      for(int i=0; i<13; i++){
        for(int j=0; j<17; j++){
          if(TableauTaillePions[posgris+comptab_g].board[i][j].player == 8){
            comptpions_g++;
            if(comptpions_g==comptab_g){ //si il s'agit de la case grise voulue
              TableauTailleGris[posgris+comptab_g].board[i][j].player == playerIA; //on déplace le pion
              TableauTailleGris[posgris+comptab_g].board[pospion.x][pospion.y].player == 0; //on enleve l'ancienne position
              clearGreyCells(TableauTailleGris[posgris+comptab_g]); //on verrouille en supprimant les cases grises.
            }
          }
        }
      }
    }
    posgris+=comptgris; //décale pos gris du nb de cases grises issues du tableau du pion n
  }
}

void turnIA(int playerIA, Dames TabInit){Dames *Tableau; TableauTaillePionsInit(Tableau,TabInit);griserTabPions(Tableau,2);}

/*
int winBoard(Dames game){
  int win=0;
  for(int i=1; i<=nbplayers; i++){
    win = winDames(game, part[6], i);
    if(win!=0){return(i*1)}
  }
  return 0;
}

int Min(int** jeu,int profondeur){
  if(profondeur == 0 || winBoard(jeu)!=0)
    {return eval(jeu);}

  int min = 10000;
  int tmp;

  TableauTailleGris(jeu);

  for(int i=0;i<TableauTailleGris;i++){

        tmp = Max(jeu,profondeur-1);
        if(tmp < min)
            {min = tmp;}

        jeu[i][j] = 0;
      }
    }
  }
  return min;


int Min(int** jeu,int profondeur){
  if(profondeur == 0 || gagnant(jeu)!=0)
    {return eval(jeu);}

  int min = 10000;
  int tmp;

  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){

      if(jeu[i][j] == 0){
        jeu[i][j] = 1;

        tmp = Max(jeu,profondeur-1);
        if(tmp < min)
            {min = tmp;}

        jeu[i][j] = 0;
      }
    }
  }
  return min;
}

int Max(int** jeu,int profondeur){
  if(profondeur == 0 || gagnant(jeu)!=0)
    {return eval(jeu);}

  int max = -10000;
  int tmp;

  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){

      if(jeu[i][j] == 0){
        jeu[i][j] = 2;

        tmp = Min(jeu,profondeur-1);
        if(tmp > max)
            {max = tmp;}

        jeu[i][j] = 0;
      }
    }
  }
  return max;
}
*/

int turnByTurnIA(Dames game,int nbplayers, int part[6], SDL_Surface *screen){
  int turn = 0;
  int n=1;
  while(winDames(game, part, n) == 0){

    n =(turn%nbplayers)+1;
    SDL_Rect pos, temp;
    SDL_Rect start; //empeche de revenir au meme tableau

    updateGame(game, screen);
    updateInfoTour(n, screen);
    //On chosit une première case
    if(n==1){
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
  }


    else{

    int nbgris;
    Dames *TableauTaillePions, *TableauTailleGris;
    turnIA(n,game);
/*
    TableauTaillePionsInit(TableauTaillePions, game);
    printf("Ouais");
    nbgris = griserTabPions(TableauTaillePions, n);

    TableauTailleGrisInit(TableauTailleGris, TableauTaillePions, nbgris);

    playgris(TableauTailleGris, TableauTaillePions);

    int random;
    random = (rand()%(20+0)+1);
    printf("%d\n",random);
    /*
    game=TableauTailleGris[random];
    */
/*
    for(int i=0; i<10; i++){freeDames(TableauTaillePions[i]);}
    for(int i=0; i<nbgris; i++){freeDames(TableauTailleGris[i]);}*/
  }


  turn++;
  }
return(n);
}
