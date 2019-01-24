int playerIA, nbgris;

Dames copyDames(Dames boardtocopy){
  Dames copy;

  copy.sizeBoardL = boardtocopy.sizeBoardL;
  copy.sizeBoardl = boardtocopy.sizeBoardl;

  for(int i=0; i<boardtocopy.sizeBoardL; i++){
    for(int j=0; j<boardtocopy.sizeBoardl; j++){
      copy.board[i][j] = boardtocopy.board[i][j];
    }
  }
  return copy;
}

Dames *TableauTaillePions;

void TableauTaillePionsInit(Dames* TableauTaillePions, Dames TabInit){

    TableauTaillePions = (Dames*) malloc(10*modeparts*sizeof(Dames));
    if(TableauTaillePions == NULL){fprintf(stderr,"Allocation impossible");exit(EXIT_FAILURE);}

    for(int i=0;i<(10*modeparts);i++)
      {TableauTaillePions[i].board=initBoard(17,13, 0,0,0,0,0,0);TableauTaillePions[i]=copyDames(TabInit);}
}

int griserTabPions(Dames *TableauTaillePions, int playerIA){ //Va griser chacun des pions possibles.
  int gris=0;
  for(int numTab=1; numTab<((10*modeparts)+1); numTab++){ //Pour parcourir les pions de toutes les pointes
    int compt=0; //Pour griser une case différente à chaque fois.
    SDL_Rect pospion;
    for(int i=0; i<13; i++){
      for(int j=0; j<17; j++){
        if(TableauTaillePions[numTab-1].board[i][j].player == playerIA){
            compt++; pospion.x=i; pospion.y=j; //Enregistre la pos du pion n
        if(compt==numTab){potential_Moves(TableauTaillePions[numTab-1], pospion, -1);} //si le nieme pion du nime tableau alors le griser
        }
      }
    }
    for(int numTab=1; numTab<((10*modeparts)+1); numTab++){ //Pour compter le nombre total de cases grises.
      for(int i=0; i<13; i++){
        for(int j=0; j<17; j++){
          if(TableauTaillePions[numTab-1].board[i][j].player == 8){gris++;}
        }
      }
    }
  }
return gris;
}

Dames* TableauTailleGris;

void TableauTailleGrisInit(Dames* TableauTailleGris, Dames* TableauTaillePions, int nbgris){

  TableauTailleGris = (Dames*) malloc(nbgris*sizeof(Dames));
  if(TableauTailleGris == NULL){fprintf(stderr,"Allocation impossible");exit(EXIT_FAILURE);}

  for(int i=0;i<nbgris;i++)
    {TableauTailleGris[i].board=initBoard(17,13, 0,0,0,0,0,0);}

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

void eval(){}

void turnIA(int playerIA, Dames TabInit){nbgris = griserTabPions(TableauTaillePions, playerIA);}
