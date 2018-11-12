

Hex initHex(int n, int m, int p1, int p2, int p3, int p4, int p5, int p6){
  Hex hex;
  Hex_Case **board = initBoard(n, m, p1, p2, p3, p4, p5, p6);
  hex.board = board;
  hex.sizeBoardL = m;
  hex.sizeBoardl = n;
  return hex;
}


Hex_Case **initBoard(int n, int m, int p1, int p2, int p3, int p4, int p5, int p6){
  Hex_Case **board;
  board = (Hex_Case**) malloc(m * sizeof(Hex_Case*));
  if( board == NULL ) {
    fprintf(stderr,"Allocation impossible");
    exit(EXIT_FAILURE);
  }
  for( int i = 0 ; i < m ; i++ ) {
    board[i] = (Hex_Case*) calloc (n, sizeof(Hex_Case));
    if( board[i] == NULL ) {
      fprintf(stderr,"Allocation impossible");
      exit(EXIT_FAILURE);
    }
  }
  //definition de la zone plateau
  for(int i=0; i < m; i++){
    for(int j=0; j < n; j++){
      board[i][j].pos.x = 0;
      board[i][j].pos.y = 0;
      board[i][j].hex = NULL;
      board[i][j].joueur = 0;
    }
  }
  for(int i=0; i<m; i++){
    if(i<5){
      for(int j=0; j<4; j++) { //avant la pointe haute
            board[i][j].joueur = 9;
            }
      for(int j=(6+i); j<(11-i); j++){ //avant la partie mediane
            board[i][j].joueur = 9;
            }
      for(int j=13; j<n; j++){ //avant la pointe basse
            board[i][j].joueur = 9;
            }
    }
  if(i>7){
    for(int j=0; j<4; j++) { //après la pointe haute
          board[i][j].joueur = 9;
    }
    for(int j=13; j<n; j++){ //apres la pointe basse
          board[i][j].joueur = 9;
    }
  }
  if(i==12){
      for(int j=6; j<11; j++) { //après la pointe haute
            board[i][j].joueur = 9;
      }
  }
}

board[2][8].joueur = 0;
board[0][5].joueur =9;
board[5][0].joueur = 9;
board[5][1].joueur = 9;
board[7][0].joueur = 9;
board[8][3].joueur = 0;
board[0][11].joueur = 9;
board[2][8].joueur = 0;
board[5][15].joueur = 9;
board[5][16].joueur = 9;
board[7][16].joueur = 9;
board[8][13].joueur = 0;
board[11][8].joueur = 9;

//initialisations des triangles
int p[6]={p1,p2,p3,p4,p5,p6};

int tabp[120]= {6,0,6,1,7,1,5,2,6,2,7,2,5,3,6,3,7,3,8,3,
                12,4,11,4,12,5,10,4,11,5,11,6,9,4,10,5,10,6,11,7,
                12,12,12,11,11,12,11,10,11,11,10,12,11,9,10,10,10,11,9,12,
                6,16,7,15,6,15,7,14,6,14,5,14,8,13,7,13,6,13,5,13,
                0,12,1,12,1,11,2,12,2,11,1,10,3,12,3,11,2,10,2,9,
                0,4,1,5,1,4,1,6,2,5,2,4,2,7,2,6,3,5,3,4};

for (int i=0; i<60; i++){
  board[ tabp[2*i] ] [ tabp[1+(2*i)] ].joueur = p[(i/10)];
}
return board;
}

void deplacements_poss(Hex jeu, SDL_Rect pos, int saut){

int zone2[12]={pos.x-1, pos.y-2,   pos.x-2, pos.y,   pos.x-1, pos.y+2,
                pos.x+1, pos.y-2,  pos.x+2, pos.y,  pos.x+1, pos.y+2};

int zone[12];

if((pos.y%2)==0){
  int zone[12]={pos.x, pos.y-1,   pos.x-1, pos.y,   pos.x, pos.y+1,
                pos.x+1, pos.y-1,  pos.x+1, pos.y,  pos.x+1, pos.y+1};
}
else{
  int zone[12]={pos.x-1, pos.y-1,   pos.x-1, pos.y,   pos.x-1, pos.y+1,
                pos.x, pos.y-1,  pos.x+1, pos.y,  pos.x, pos.y+1};
}

for(int i=0; i<6; i++){ //Si on s'approche du bord du tableau
  if(zone[i*2]<0 || zone[i*2]>12 || zone[(i*2)+1]<0 || zone[(i*2)+1]>16){
    zone[i*2]=0;
    zone[(i*2)+1]=0;
  }
  if(zone2[i*2]<0 || zone2[i*2]>12 || zone2[(i*2)+1]<0 || zone2[(i*2)+1]>16){
    zone2[i*2]=0;
    zone2[(i*2)+1]=0;
  }
}

for(int i=0; i<6; i++){
  if(jeu.board[zone[i*2]][zone[(i*2)+1]].joueur != 9){

    //Si il s'agit donc d'un pion
    if(jeu.board[zone[i*2]][zone[(i*2)+1]].joueur != 0){
      if(saut!=0 && jeu.board[zone2[i*2]][zone2[(i*2)+1]].joueur == 0)
        {jeu.board[zone2[i*2]][zone2[(i*2)+1]].joueur = 8;}
    }

    //Si il s'agit d'un espace libre
    else{
      if(saut==-1){
        jeu.board[zone[i*2]][zone[(i*2)+1]].joueur = 8; //Si on est au premier tour on peut sauter a cote
      }
    }

  }
}
}

void clearCasesGrises(Hex jeu){
  for(int i=0; i<13; i++){
    for(int j=0; j<17; j++){
      if(jeu.board[i][j].joueur == 8){
        jeu.board[i][j].joueur = 0;
      }
    }
  }
}

int condition(SDL_Rect pos, SDL_Rect temp){
 if(temp.x>=pos.x-1 && temp.x<=pos.x+1 && temp.y>=pos.y-1 && temp.y<=pos.y+1){
   return(0);
 }
return 1;
}

int winHex(Hex jeu, int part[6], int n){
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
      if(jeu.board[ tabp[2*i] ] [ tabp[1+(2*i)] ].joueur == n)
        {comptpion+=1;}
    }
  }
  if(comptj==comptpion){
    int victoire[44]={4,0, 4,1, 3,2, 2,2, 1,2,
                      8,0, 9,1, 9,2, 10,2, 11,2,
                      0,8, 12,8,
                      8,16, 9,15, 9,14, 10,14, 11,14,
                      4,16, 4,15, 3,14, 2,14, 1,14};
    for(int i=0; i<22; i++){
      jeu.board[ victoire[2*i] ] [ victoire[1+(2*i)] ].joueur = n;
    }
  return(1);
  }
return(0);
}

int tourpartour(Hex jeu,int nbjoueurs, int part[6], SDL_Surface *ecran){
  int tour = 0;
  int n=0;
  while(winHex(jeu, part, n) == 0){

    n =(tour%nbjoueurs)+1;
    SDL_Rect pos, temp;
    SDL_Rect depart; //empeche de revenir au meme tableau

    rafraichirjeu(jeu, ecran);

    //On chosit une première case
    do{
      pos = clickBoard(jeu);
    }while(jeu.board[pos.x][pos.y].joueur != n);

    jeu.board[pos.x][pos.y].joueur = n+10;
    rafraichirjeu(jeu, ecran);

    int saut = -1;
    depart.x=0;
    depart.y=0;
    do{
      deplacements_poss(jeu, pos, saut);
      rafraichirjeu(jeu, ecran);

      //Si c'est le premier saut
      if(saut == -1){
        do{
          temp=clickBoard(jeu);
        }while(jeu.board[temp.x][temp.y].joueur != 8 && jeu.board[temp.x][temp.y].joueur != n );

        //Si on choisit une autre case finalement
        if(jeu.board[temp.x][temp.y].joueur == n){
          jeu.board[pos.x][pos.y].joueur = n;
          pos = temp;
          jeu.board[pos.x][pos.y].joueur = n+10;
          clearCasesGrises(jeu); //Efface les case grises
        }
        //Sinon on saute
        else{
          saut = condition(pos, temp); //Determine si on saute un pion
          jeu.board[pos.x][pos.y].joueur = 0;
          if(saut==0){
          pos = temp;
          jeu.board[pos.x][pos.y].joueur = n;
          }
          if(saut==1){
          depart = pos; //enregistre la pos de depart
          pos = temp;
          jeu.board[pos.x][pos.y].joueur = n+10;
          rafraichirjeu(jeu, ecran);
          }
          clearCasesGrises(jeu);
        }
      }

      //Si c'est pas le premier saut
      else{
        do{
          temp=clickBoard(jeu);
        }while(jeu.board[temp.x][temp.y].joueur != 8 && jeu.board[temp.x][temp.y].joueur != (n+10) );

        //Si on s'arrete à sa position
        if(jeu.board[temp.x][temp.y].joueur == (n+10) && (depart.x != temp.x || depart.y != temp.y) ){
          saut = 0;
          jeu.board[pos.x][pos.y].joueur = n;
          clearCasesGrises(jeu);
        }
        //Si on continue de sauter
        else{
          jeu.board[pos.x][pos.y].joueur = 0;
          pos = temp;
          jeu.board[pos.x][pos.y].joueur = n+10;
          clearCasesGrises(jeu);
        }
      }

    }while(saut!=0);
  tour++;
  }
return(n);
}

/*
void freeHex(Hex hex){
  free(hex);
  hex = NULL;
}
*/
