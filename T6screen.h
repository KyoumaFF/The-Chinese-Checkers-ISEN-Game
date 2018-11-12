
SDL_Rect clickBoard(Hex jeu){
  int continuer = 1;
  SDL_Event event;
  SDL_Rect pos;

  while (continuer)
  {
      SDL_WaitEvent(&event);
      switch(event.type)
      {
        case SDL_QUIT:
              SDL_Quit();
              exit(0);
          case SDL_MOUSEBUTTONUP:
            for(int i=0; i < (jeu.sizeBoardL); i++){
              for(int j=0; j < (jeu.sizeBoardl); j++){
                if (event.button.button == SDL_BUTTON_LEFT
                    && event.button.x > jeu.board[i][j].pos.x
                    && event.button.x < jeu.board[i][j].pos.x + jeu.board[i][j].hex->w
                    && event.button.y > jeu.board[i][j].pos.y
                    && event.button.y < jeu.board[i][j].pos.y + jeu.board[i][j].hex->h){
                      pos.x = i;
                      pos.y = j;
                      return pos;
                    }
              }
            }
      }
  }
}

void pause(){
  SDL_Event event;
  int continuer = 1;

  while (continuer)
  {
      SDL_WaitEvent(&event);
      switch(event.type)
      {
        case SDL_QUIT:
          continuer = 0;
          break;
      }
  }
}

void updateBoard(Hex jeu, SDL_Surface *ecran){
  for(int i=0; i < (jeu.sizeBoardL); i++){
    for(int j=0; j < (jeu.sizeBoardl); j++){
      if((j%2)==0){
      jeu.board[i][j].pos.x = SCREEN_SHIFT_H + 42*i + 2*i;
      jeu.board[i][j].pos.y = SCREEN_SHIFT_V + 49*j - 11*j;
      }
      else{
      jeu.board[i][j].pos.x = SCREEN_SHIFT_H + 42*i -21 + 2*i;
      jeu.board[i][j].pos.y = SCREEN_SHIFT_V + 49*j - 11*j;
      }
      switch (jeu.board[i][j].joueur) {
        case 0:
          jeu.board[i][j].hex = IMG_Load("img/Hex_0.png");
          break;
        case 1:
          jeu.board[i][j].hex = IMG_Load("img/Hex_1.png");
          break;
        case 2:
          jeu.board[i][j].hex = IMG_Load("img/Hex_2.png");
          break;
        case 3:
          jeu.board[i][j].hex = IMG_Load("img/Hex_3.png");
          break;
        case 4:
          jeu.board[i][j].hex = IMG_Load("img/Hex_4.png");
          break;
        case 5:
          jeu.board[i][j].hex = IMG_Load("img/Hex_5.png");
          break;
        case 6:
          jeu.board[i][j].hex = IMG_Load("img/Hex_6.png");
          break;
        case 8:
          jeu.board[i][j].hex = IMG_Load("img/Hex_8.png");
          break;
        case 9:
        jeu.board[i][j].hex = IMG_Load("img/Hex_9.png");
          break;
        case 11:
          jeu.board[i][j].hex = IMG_Load("img/Hex_11.png");
          break;
        case 12:
          jeu.board[i][j].hex = IMG_Load("img/Hex_12.png");
          break;
        case 13:
          jeu.board[i][j].hex = IMG_Load("img/Hex_13.png");
          break;
        case 14:
          jeu.board[i][j].hex = IMG_Load("img/Hex_14.png");
          break;
        case 15:
          jeu.board[i][j].hex = IMG_Load("img/Hex_15.png");
          break;
        case 16:
          jeu.board[i][j].hex = IMG_Load("img/Hex_16.png");
          break;
        default: jeu.board[i][j].hex = IMG_Load("img/Hex_99.png");
      }
      SDL_BlitSurface(jeu.board[i][j].hex, NULL, ecran, &jeu.board[i][j].pos);
    }
  }
displayContour(ecran);
}

void updateScreen(SDL_Surface *ecran){
  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
  SDL_Flip(ecran);
}

void displayContour(SDL_Surface *ecran){
  SDL_Surface *contour;
  SDL_Rect pos;
  contour = IMG_Load("img/Cadre.png");
  pos.x = SCREEN_SHIFT_H -8;
  pos.y = SCREEN_SHIFT_V -6;
  SDL_BlitSurface(contour, NULL, ecran, &pos);
}

void rafraichirjeu(Hex jeu, SDL_Surface *ecran){
  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
  updateBoard(jeu, ecran);
  SDL_Flip(ecran);
}
