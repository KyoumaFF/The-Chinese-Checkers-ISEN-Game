void menu_main(SDL_Surface *screen);
void settings(SDL_Surface *screen);
void game_config(SDL_Surface *screen);

void set_game_nbplayers(SDL_Surface *screen);
void nbplayersEq2(SDL_Surface *screen);void nbplayersEq3(SDL_Surface *screen);
void nbplayersEq4(SDL_Surface *screen);void nbplayersEq6(SDL_Surface *screen);

void set_bordMode(SDL_Surface *screen);
void ModeEq2_0(SDL_Surface *screen);void ModeEq2_1(SDL_Surface *screen);
void ModeEq2_2(SDL_Surface *screen);void ModeEq3(SDL_Surface *screen);
void ModeEq4_0(SDL_Surface *screen);void ModeEq4_1(SDL_Surface *screen);
void ModeEq4_2(SDL_Surface *screen);void ModeEq6(SDL_Surface *screen);

void set_playersStates(SDL_Surface *screen);

void game(SDL_Surface *screen);
void regles0(SDL_Surface *screen);
void test(SDL_Surface *screen);

void menu_main(SDL_Surface *screen){

  Button menu[4] = {

    initButtonImg((800/2 - 322/2), (213 - 90/2), "../img/Button_Game.png", game),
    initButtonImg((800/2 - 322/2), (338 - 90/2), "../img/Button_Rules.png", regles0),
    initButtonImg((800/2 - 322/2), (463 - 90/2), "../img/Button_Settings.png", settings),
    initButtonImg((800/2 - 322/2), (588 - 90/2), "../img/Button_Exit.png", exit),

  };

  SDL_Surface *text = initText("Dames chinoises", 36, 0x000000, TTF_STYLE_UNDERLINE | TTF_STYLE_ITALIC);

  displayColor(screen, 0xE9DBAD);
  displayText(screen, text, (screen->w)/2 - (text->w)/2 , 40);
  displayMenu(menu, screen, 4);
  waitEvent(menu, screen, 4);
}


void settings(SDL_Surface *screen){
  int inter=14;
  int btnHeight = 116+inter, btnWidth = 322;
  int xm = (screen->w)/2 - btnWidth/2;
  int ym = (screen->h)/2 - btnHeight/2;

  Button menu[3] = {

    initButtonRect(xm, ym - btnHeight, btnWidth, (btnHeight-inter), 0xFF4040, "Configuration actuelle", 32, 0xFFFFFF, TTF_STYLE_ITALIC, game_config),
    initButtonRect(xm, ym, btnWidth, (btnHeight-inter), 0xFF8040, "Parametres de Jeu", 32, 0xFFFFFF, TTF_STYLE_ITALIC, set_game_nbplayers),
    initButtonRect(xm, ym + btnHeight, btnWidth, (btnHeight-inter), 0xFFC040, "Retour Menu", 32, 0xFFFFFF, TTF_STYLE_ITALIC, menu_main),

  };

  SDL_Surface *text = initText("Parametres", 36, 0x000000, TTF_STYLE_UNDERLINE);

  displayColor(screen, 0xE9DBAD);
  displayText(screen, text, (screen->w)/2 - (text->w)/2 , 40);
  displayMenu(menu, screen, 3);
  waitEvent(menu, screen, 3);
}

void game_config(SDL_Surface *screen){
  char text_nb[2];
  sprintf(text_nb, "%d", nbplayers);

  int btnHeight = 90, btnWidth = 189;
  int xm = (screen->w)/2 - btnWidth/2;

  int partpos[12]={314,98,511,250,511,440,314,592,115,440,115,250};

  Button menu[1] = {
    initButtonImg(screen->w - 40 - btnWidth, screen->h - 40 - btnHeight, "../img/Button_Back.png", settings),

  };

  SDL_Surface *text = initText("Configuration actuelle du jeu", 36, 0x000000, TTF_STYLE_UNDERLINE);
  SDL_Surface *text_nbplayers = initText("Nombre de Joueurs:", 24, 0x000000, TTF_STYLE_NORMAL);
  SDL_Surface *text2_nbplayers = initText(text_nb, 24, 0x000000, TTF_STYLE_NORMAL);

  displayColor(screen, 0xE9DBAD);
  displayText(screen, text, (screen->w)/2 - (text->w)/2 , 40);
  displayText(screen, text_nbplayers, 40 , 140);
  displayText(screen, text2_nbplayers, 260 , 141);
  displayMenu(menu, screen, 1);


  displayImg(screen, 197, 243, "../img/Center_0.png");
  for(int i=0; i<6; i++){
    if (part[i]!=9){
      displayImg(screen, partpos[i*2], partpos[(i*2)+1], partchar[part[i]][i]);
    }
  }
  displayImg(screen, (screen->w - 585)/2, screen->h - 668 - 40, framechar);

  waitEvent(menu, screen, 1);
}

void set_game_nbplayers(SDL_Surface *screen){
  int inter=16;
  int btnHeight = 90, btnWidth = 90;
  int xm = (screen->w)/2;
  int ym = (screen->h)/2 - btnHeight/2;

  Button menu[5] = {
    initButtonRect(xm - (2*btnWidth) - 1*inter - inter/2, ym, btnWidth, btnHeight, 0xFFC0C0, "2", 32, 0xFFFFFF, TTF_STYLE_UNDERLINE, nbplayersEq2),
    initButtonRect(xm - (1*btnWidth) - 0*inter - inter/2, ym, btnWidth, btnHeight, 0xFFC0C0, "3", 32, 0xFFFFFF, TTF_STYLE_UNDERLINE, nbplayersEq3),
    initButtonRect(xm + (0*btnWidth) + 0*inter + inter/2, ym, btnWidth, btnHeight, 0xFFC0C0, "4", 32, 0xFFFFFF, TTF_STYLE_UNDERLINE, nbplayersEq4),
    initButtonRect(xm + (1*btnWidth) + 1*inter + inter/2, ym, btnWidth, btnHeight, 0xFFC0C0, "6", 32, 0xFFFFFF, TTF_STYLE_UNDERLINE, nbplayersEq6),
    initButtonImg(screen->w - 40 - 189, screen->h - 40 - 90, "../img/Button_Back.png", settings),

  };

  SDL_Surface *text = initText("Parametrage du jeu", 36, 0x000000, TTF_STYLE_UNDERLINE);
  SDL_Surface *text_nbplayers = initText("Nombre de Joueurs", 30, 0x000000, TTF_STYLE_ITALIC);

  displayColor(screen, 0xE9DBAD);
  displayText(screen, text, (screen->w)/2 - (text->w)/2 , 40);
  displayText(screen, text_nbplayers, (screen->w)/2 - (text_nbplayers->w)/2 , 270);
  displayMenu(menu, screen, 5);

  waitEvent(menu, screen, 5);
}

void nbplayersEq2(SDL_Surface *screen){nbplayers=2;set_bordMode(screen);}
void nbplayersEq3(SDL_Surface *screen){nbplayers=3;set_bordMode(screen);}
void nbplayersEq4(SDL_Surface *screen){nbplayers=4;set_bordMode(screen);}
void nbplayersEq6(SDL_Surface *screen){nbplayers=6;set_bordMode(screen);}

void set_bordMode(SDL_Surface *screen){
if(nbplayers==2){
    int inter=16;
    int btnHeight = 90, btnWidth = 90;
    int xm = (screen->w)/2;
    int ym = (screen->h)/2 - btnHeight/2;

    Button menu[3] = {
      initButtonRect(xm - (2*btnWidth) - 1*inter - inter/2, ym, btnWidth, btnHeight, 0xFFC0C0, "2_0", 32, 0xFFFFFF, TTF_STYLE_UNDERLINE, ModeEq2_0),
      initButtonRect(xm - (1*btnWidth) - 0*inter - inter/2, ym, btnWidth, btnHeight, 0xFFC0C0, "2_1", 32, 0xFFFFFF, TTF_STYLE_UNDERLINE, ModeEq2_1),
      initButtonRect(xm + (0*btnWidth) + 0*inter + inter/2, ym, btnWidth, btnHeight, 0xFFC0C0, "2_2", 32, 0xFFFFFF, TTF_STYLE_UNDERLINE, ModeEq2_2)
    };

    SDL_Surface *text = initText("Parametrage du jeu", 36, 0x000000, TTF_STYLE_UNDERLINE);
    SDL_Surface *text_nbplayers = initText("Mode de Jeu", 30, 0x000000, TTF_STYLE_ITALIC);

    displayColor(screen, 0xE9DBAD);
    displayText(screen, text, (screen->w)/2 - (text->w)/2 , 40);
    displayText(screen, text_nbplayers, (screen->w)/2 - (text_nbplayers->w)/2 , 270);
    displayMenu(menu, screen, 3);

    waitEvent(menu, screen, 3);
}
if(nbplayers==3){
    int inter=16;
    int btnHeight = 90, btnWidth = 90;
    int xm = (screen->w)/2;
    int ym = (screen->h)/2 - btnHeight/2;

    Button menu[1] = {
      initButtonRect(xm - (2*btnWidth) - 1*inter - inter/2, ym, btnWidth, btnHeight, 0xFFC0C0, "3", 32, 0xFFFFFF, TTF_STYLE_UNDERLINE, ModeEq6)

    };

    SDL_Surface *text = initText("Parametrage du jeu", 36, 0x000000, TTF_STYLE_UNDERLINE);
    SDL_Surface *text_nbplayers = initText("Mode de Jeu", 30, 0x000000, TTF_STYLE_ITALIC);

    displayColor(screen, 0xE9DBAD);
    displayText(screen, text, (screen->w)/2 - (text->w)/2 , 40);
    displayText(screen, text_nbplayers, (screen->w)/2 - (text_nbplayers->w)/2 , 270);
    displayMenu(menu, screen, 1);

    waitEvent(menu, screen, 1);
}
if(nbplayers==4){
    int inter=16;
    int btnHeight = 90, btnWidth = 90;
    int xm = (screen->w)/2;
    int ym = (screen->h)/2 - btnHeight/2;

    Button menu[3] = {
      initButtonRect(xm - (2*btnWidth) - 1*inter - inter/2, ym, btnWidth, btnHeight, 0xFFC0C0, "4_0", 32, 0xFFFFFF, TTF_STYLE_UNDERLINE, ModeEq4_0),
      initButtonRect(xm - (1*btnWidth) - 0*inter - inter/2, ym, btnWidth, btnHeight, 0xFFC0C0, "4_1", 32, 0xFFFFFF, TTF_STYLE_UNDERLINE, ModeEq4_1),
      initButtonRect(xm + (0*btnWidth) + 0*inter + inter/2, ym, btnWidth, btnHeight, 0xFFC0C0, "4_2", 32, 0xFFFFFF, TTF_STYLE_UNDERLINE, ModeEq4_2)

    };

    SDL_Surface *text = initText("Parametrage du jeu", 36, 0x000000, TTF_STYLE_UNDERLINE);
    SDL_Surface *text_nbplayers = initText("Mode de Jeu", 30, 0x000000, TTF_STYLE_ITALIC);

    displayColor(screen, 0xE9DBAD);
    displayText(screen, text, (screen->w)/2 - (text->w)/2 , 40);
    displayText(screen, text_nbplayers, (screen->w)/2 - (text_nbplayers->w)/2 , 270);
    displayMenu(menu, screen, 3);

    waitEvent(menu, screen, 3);
}
if(nbplayers==6){
    int inter=16;
    int btnHeight = 90, btnWidth = 90;
    int xm = (screen->w)/2;
    int ym = (screen->h)/2 - btnHeight/2;

    Button menu[1] = {
      initButtonRect(xm - (2*btnWidth) - 1*inter - inter/2, ym, btnWidth, btnHeight, 0xFFC0C0, "6", 32, 0xFFFFFF, TTF_STYLE_UNDERLINE, ModeEq6)
    };

    SDL_Surface *text = initText("Parametrage du jeu", 36, 0x000000, TTF_STYLE_UNDERLINE);
    SDL_Surface *text_nbplayers = initText("Mode de Jeu", 30, 0x000000, TTF_STYLE_ITALIC);

    displayColor(screen, 0xE9DBAD);
    displayText(screen, text, (screen->w)/2 - (text->w)/2 , 40);
    displayText(screen, text_nbplayers, (screen->w)/2 - (text_nbplayers->w)/2 , 270);
    displayMenu(menu, screen, 1);

    waitEvent(menu, screen, 1);
}
}

void ModeEq2_0(SDL_Surface *screen){framechar="../img/Frame_2_0.png";set_playersStates(screen);}
void ModeEq2_1(SDL_Surface *screen){framechar="../img/Frame_2_1.png";set_playersStates(screen);}
void ModeEq2_2(SDL_Surface *screen){framechar="../img/Frame_2_2.png";set_playersStates(screen);}
void ModeEq4_0(SDL_Surface *screen){framechar="../img/Frame_4_0.png";set_playersStates(screen);}
void ModeEq4_1(SDL_Surface *screen){framechar="../img/Frame_4_1.png";set_playersStates(screen);}
void ModeEq4_2(SDL_Surface *screen){framechar="../img/Frame_4_2.png";set_playersStates(screen);}
void ModeEq6(SDL_Surface *screen){framechar="../img/Frame_6.png";set_playersStates(screen);}

void set_playersStates(SDL_Surface *screen){
  char text_nb[2];
  sprintf(text_nb, "%d", nbplayers);

  int btnHeight = 90, btnWidth = 189;
  int xm = (screen->w)/2 - btnWidth/2;

  int partpos[12]={314,98,511,250,511,440,314,592,115,440,115,250};

  Button menu[1] = {
    initButtonImg(screen->w - 40 - btnWidth, screen->h - 40 - btnHeight, "../img/Button_Back.png", settings),

  };

  SDL_Surface *text = initText("Configuration actuelle du jeu", 36, 0x000000, TTF_STYLE_UNDERLINE);
  SDL_Surface *text_nbplayers = initText("Nombre de Joueurs:", 24, 0x000000, TTF_STYLE_NORMAL);
  SDL_Surface *text2_nbplayers = initText(text_nb, 24, 0x000000, TTF_STYLE_NORMAL);

  displayColor(screen, 0xE9DBAD);
  displayText(screen, text, (screen->w)/2 - (text->w)/2 , 40);
  displayText(screen, text_nbplayers, 40 , 140);
  displayText(screen, text2_nbplayers, 260 , 141);
  displayMenu(menu, screen, 1);


  displayImg(screen, 197, 243, "../img/Center_0.png");
  for(int i=0; i<6; i++){
    if (part[i]!=9){
      displayImg(screen, partpos[i*2], partpos[(i*2)+1], partchar[part[i]][i]);
    }
  }
  displayImg(screen, (screen->w - 585)/2, screen->h - 668 - 40, framechar);

  waitEvent(menu, screen, 1);
}

void game(SDL_Surface *screen){
  Dames game;

  game = initDames(17,13,part[0],part[1],part[2],part[3],part[4],part[5]);
  updateGame(game, screen);

   int n = turnByTurn(game, nbplayers, part, screen);

  updateGame(game, screen);

  printf("\nPartie Terminé ! Joueur %d a gagné !!!\n",n);
  pause();
  menu_main(screen);
}
//
void regles0(SDL_Surface *screen){
  int btnHeight = 120, btnWidth = 322;
  int xm = (screen->w)/2 - btnWidth/2;

  Button menu[3] = {

    initButtonImgText(xm, 100, "RETOUR", 36, 0x000000, 0, "../img/Button_Back.png", menu_main),
    initButtonImgText(xm, 250, "REGLES", 36, 0x000000, 0, "../img/Button_Rules.png", menu_main),
    initButtonImg(xm, 450, "../img/Button_Exit.png", exit),

  };
  displayColor(screen, 0xFF0000);
  displayMenu(menu, screen, 3);
  waitEvent(menu, screen, 3);
}
//
void test(SDL_Surface *screen){


  Button menu[2] = {

    initButtonImg(50, (screen->h) - 100, "../img/Button_Back.png", settings),
    initButtonImg((screen->w) - 250, (screen->h) - 100, "../img/Button_Exit.png", exit)
    //initButtonImgText(400, 300, "Yolo", 36, 0xFFFFFF, 0, "../img/exit.png", exit),

  };

  SDL_Surface *text[6] = {
    initText("Regles du jeu", 36, 0x000000, TTF_STYLE_UNDERLINE),
    initText("blablaaaaaaa", 12, 0x000000, 0),
    initText("blablaaaaaaa", 12, 0x000000, 0),
    initText("blablaaaaaaa", 12, 0x000000, 0),
    initText("blablaaaaa", 12, 0x000000, 0),
    initText("blablaa", 12, 0x000000, 0)
  };

  displayColor(screen, 0xFF00FF);
  displayMenu(menu, screen, 2);
  displayParagraphCenter(screen, text, 60, 6);
  waitEvent(menu, screen, 2);
}

/* ANCIEN CODE

int part[6]={1,1,2,2,3,3};
int nbplayers=3;

framechar = "../img/Frame_2_2.png";
part[0]=9; part[1]=1; part[2]=9; part[3]=9; part[4]=2; part[5]=9;
nbplayers=2;

void regles0(SDL_Surface *screen){
  Button menu[3] = {

    initButton((1*800/5 - 189/2), (800 - 120), "Yolo", "../img/Button_Back.png", menu_main),
    initButton((4*800/5 - 189/2), (800 - 120), "Yolo", "../img/Button_Next.png", regles1),
    initButton((800/2 - 174/2), (800/2 - 163/2), "Yolo", "../img/Rules_text_0.png", exit),

  };
  displayMenu(menu, screen, 3);
  waitEvent(menu, screen, 3);
}

void regles1(SDL_Surface *screen){
  Button menu[3] = {

    initButton((1*800/5 - 189/2), (800 - 120), "Yolo", "../img/Button_Back.png", regles0),
    initButton((4*800/5 - 189/2), (800 - 120), "Yolo", "../img/Button_Next.png", regles2),
    initButton((800/2 - 174/2), (800/2 - 163/2), "Yolo", "../img/Rules_text_1.png", exit),

  };
  displayMenu(menu, screen, 3);
  waitEvent(menu, screen, 3);
}

void regles2(SDL_Surface *screen){
  Button menu[3] = {

    initButton((1*800/5 - 189/2), (800 - 120), "Yolo", "../img/Button_Back.png", regles1),
    initButton((4*800/5 - 189/2), (800 - 120), "Yolo", "../img/Button_Next.png", regles3),
    initButton((800/2 - 174/2), (800/2 - 163/2), "Yolo", "../img/Rules_text_2.png", exit),

  };
  displayMenu(menu, screen, 3);
  waitEvent(menu, screen, 3);
}

void regles3(SDL_Surface *screen){
  Button menu[3] = {

    initButton((1*800/5 - 189/2), (800 - 120), "Yolo", "../img/Button_Back.png", regles2),
    initButton((4*800/5 - 189/2), (800 - 120), "Yolo", "../img/Button_Next.png", regles4),
    initButton((800/2 - 174/2), (800/2 - 163/2), "Yolo", "../img/Rules_text_3.png", exit),

  };
  displayMenu(menu, screen, 3);
  waitEvent(menu, screen, 3);
}

void regles4(SDL_Surface *screen){
  Button menu[3] = {

    initButton((1*800/5 - 189/2), (800 - 120), "Yolo", "../img/Button_Back.png", regles3),
    initButton((4*800/5 - 189/2), (800 - 120), "Yolo", "../img/Button_Next.png", regles5),
    initButton((800/2 - 174/2), (800/2 - 163/2), "Yolo", "../img/Rules_text_4.png", exit),

  };
  displayMenu(menu, screen, 3);
  waitEvent(menu, screen, 3);
}

void regles5(SDL_Surface *screen){
  Button menu[3] = {

    initButton((1*800/5 - 189/2), (800 - 120), "Yolo", "../img/Button_Back.png", regles4),
    initButton((4*800/5 - 189/2), (800 - 120), "Yolo", "../img/Button_Next.png", regles6),
    initButton((800/2 - 174/2), (800/2 - 163/2), "Yolo", "../img/Rules_text_5.png", exit),

  };
  displayMenu(menu, screen, 3);
  waitEvent(menu, screen, 3);
}

void regles6(SDL_Surface *screen){
  Button menu[3] = {

    initButton((1*800/5 - 189/2), (800 - 120), "Yolo", "../img/Button_Back.png", regles5),
    initButton((4*800/5 - 189/2), (800 - 120), "Yolo", "../img/Button_Next.png", regles7),
    initButton((800/2 - 174/2), (800/2 - 163/2), "Yolo", "../img/Rules_text_6.png", exit),

  };
  displayMenu(menu, screen, 3);
  waitEvent(menu, screen, 3);
}

void regles7(SDL_Surface *screen){
  Button menu[3] = {

    initButton((1*800/5 - 189/2), (800 - 120), "Yolo", "../img/Button_Back.png", regles6),
    initButton((4*800/5 - 189/2), (800 - 120), "Yolo", "../img/Button_Next.png", regles8),
    initButton((800/2 - 174/2), (800/2 - 163/2), "Yolo", "../img/Rules_text_7.png", exit),

  };
  displayMenu(menu, screen, 3);
  waitEvent(menu, screen, 3);
}

void regles8(SDL_Surface *screen){
  Button menu[3] = {

    initButton((1*800/5 - 189/2), (800 - 120), "Ysolo", "../img/Button_Back.png", regles7),
    initButton((4*800/5 - 189/2), (800 - 120), "Yolo", "../img/Button_Menu.png", menu_main),
    initButton((800/2 - 174/2), (800/2 - 163/2), "Yolo", "../img/Rules_text_8.png", exit),

  };
  displayMenu(menu, screen, 3);
  waitEvent(menu, screen, 3);
}
*/
