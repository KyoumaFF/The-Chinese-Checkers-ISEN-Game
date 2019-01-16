SDL_Rect clickBoard(Dames game){
  int pursue = 1;
  SDL_Event event;
  SDL_Rect pos;

  while (pursue)
  {
      SDL_WaitEvent(&event);
      switch(event.type)
      {
        case SDL_QUIT:
              SDL_Quit();
              exit(0);
        case SDL_MOUSEBUTTONUP:
          for(int i=0; i < (game.sizeBoardL); i++){
            for(int j=0; j < (game.sizeBoardl); j++){
              if (event.button.button == SDL_BUTTON_LEFT
                  && event.button.x > game.board[i][j].pos.x
                  && event.button.x < game.board[i][j].pos.x + 42
                  && event.button.y > game.board[i][j].pos.y
                  && event.button.y < game.board[i][j].pos.y + 49){
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
  int pursue = 1;

  while (pursue)
  {
      SDL_WaitEvent(&event);
      switch(event.type)
      {
        case SDL_QUIT:
          pursue = 0;
          break;
      }
  }
}

void updateBoard(Dames game, SDL_Surface *screen){
  for(int i=0; i < (game.sizeBoardL); i++){
    for(int j=0; j < (game.sizeBoardl); j++){
      if((j%2)==0){
      game.board[i][j].pos.x = SCREEN_SHIFT_H + 42*i + 2*i;
      game.board[i][j].pos.y = SCREEN_SHIFT_V + 49*j - 11*j;
      }
      else{
      game.board[i][j].pos.x = SCREEN_SHIFT_H + 42*i -21 + 2*i;
      game.board[i][j].pos.y = SCREEN_SHIFT_V + 49*j - 11*j;
      }
      switch (game.board[i][j].player){
        case 0:
          game.board[i][j].cell = IMG_Load(cellchar[0][0]);
          break;
        case 1:
          game.board[i][j].cell = IMG_Load(cellchar[1][0]);
          break;
        case 2:
          game.board[i][j].cell = IMG_Load(cellchar[2][0]);
          break;
        case 3:
          game.board[i][j].cell = IMG_Load(cellchar[3][0]);
          break;
        case 4:
          game.board[i][j].cell = IMG_Load(cellchar[4][0]);
          break;
        case 5:
          game.board[i][j].cell = IMG_Load(cellchar[5][0]);
          break;
        case 6:
          game.board[i][j].cell = IMG_Load(cellchar[6][0]);
          break;
        case 8:
          game.board[i][j].cell = IMG_Load("../img/Cell_8.png");
          break;
        case 9:
        game.board[i][j].cell = IMG_Load("../img/Cell_9.png");
          break;
        case 11:
          game.board[i][j].cell = IMG_Load(cellchar[1][1]);
          break;
        case 12:
          game.board[i][j].cell = IMG_Load(cellchar[2][1]);
          break;
        case 13:
          game.board[i][j].cell = IMG_Load(cellchar[3][1]);
          break;
        case 14:
          game.board[i][j].cell = IMG_Load(cellchar[4][1]);
          break;
        case 15:
          game.board[i][j].cell = IMG_Load(cellchar[5][1]);
          break;
        case 16:
          game.board[i][j].cell = IMG_Load(cellchar[6][1]);
          break;
        default: game.board[i][j].cell = IMG_Load("../img/Cell_99.png");
      }
      SDL_BlitSurface(game.board[i][j].cell, NULL, screen, &game.board[i][j].pos);
      SDL_FreeSurface(game.board[i][j].cell);
    }
  }
displayFrame(screen);
}

void updateScreen(SDL_Surface *screen){
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 210, 210, 210));
  SDL_Flip(screen);
}

void displayFrame(SDL_Surface *screen){
  SDL_Surface *frame;
  SDL_Rect pos;
  frame = IMG_Load(framechar);
  pos.x = SCREEN_SHIFT_H -8;
  pos.y = SCREEN_SHIFT_V -6;
  SDL_BlitSurface(frame, NULL, screen, &pos);
  SDL_FreeSurface(frame);
}

void updateGame(Dames game, SDL_Surface *screen){
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 210, 210, 210));
  updateBoard(game, screen);
  SDL_Flip(screen);
}
