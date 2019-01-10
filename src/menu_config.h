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

void nbplayersEq2(SDL_Surface *screen){nbplayers=2;set_game_nbparts(screen);}
void nbplayersEq3(SDL_Surface *screen){nbplayers=3;set_game_nbparts(screen);}
void nbplayersEq4(SDL_Surface *screen){nbplayers=4;set_game_nbparts(screen);}
void nbplayersEq6(SDL_Surface *screen){nbplayers=6;set_game_nbparts(screen);}

void set_game_nbparts(SDL_Surface *screen){
  int inter=16;
  int btnHeight = 90, btnWidth = 90;
  int xm = (screen->w)/2;
  int ym = (screen->h)/2 - btnHeight/2;

  if(nbplayers==2){
  Button menu[3] = {
    initButtonRect(xm - (1*btnWidth) - 1*inter - btnWidth/2, ym, btnWidth, btnHeight, 0xFFC0C0, "1", 32, 0xFFFFFF, TTF_STYLE_UNDERLINE, nbpartsEq1),
    initButtonRect(xm - btnWidth/2                         , ym, btnWidth, btnHeight, 0xFFC0C0, "2", 32, 0xFFFFFF, TTF_STYLE_UNDERLINE, nbpartsEq2),
    initButtonRect(xm + 1*inter + btnWidth/2               , ym, btnWidth, btnHeight, 0xFFC0C0, "3", 32, 0xFFFFFF, TTF_STYLE_UNDERLINE, nbpartsEq3)
  };

  SDL_Surface *text = initText("Parametrage du jeu", 36, 0x000000, TTF_STYLE_UNDERLINE);
  SDL_Surface *text_nbplayers = initText("Nombre de Pointes par Joueurs", 30, 0x000000, TTF_STYLE_ITALIC);

  displayColor(screen, 0xE9DBAD);
  displayText(screen, text, (screen->w)/2 - (text->w)/2 , 40);
  displayText(screen, text_nbplayers, (screen->w)/2 - (text_nbplayers->w)/2 , 270);
  displayMenu(menu, screen, 3);

  waitEvent(menu, screen, 3);
  }

  if(nbplayers==3){
  Button menu[2] = {
    initButtonRect(xm - 1*btnWidth - inter/2, ym, btnWidth, btnHeight, 0xFFC0C0, "1", 32, 0xFFFFFF, TTF_STYLE_UNDERLINE, nbpartsEq1),
    initButtonRect(xm + inter/2             , ym, btnWidth, btnHeight, 0xFFC0C0, "2", 32, 0xFFFFFF, TTF_STYLE_UNDERLINE, nbpartsEq2)
  };

  SDL_Surface *text = initText("Parametrage du jeu", 36, 0x000000, TTF_STYLE_UNDERLINE);
  SDL_Surface *text_nbplayers = initText("Nombre de Pointes par Joueurs", 30, 0x000000, TTF_STYLE_ITALIC);

  displayColor(screen, 0xE9DBAD);
  displayText(screen, text, (screen->w)/2 - (text->w)/2 , 40);
  displayText(screen, text_nbplayers, (screen->w)/2 - (text_nbplayers->w)/2 , 270);
  displayMenu(menu, screen, 2);

  waitEvent(menu, screen, 2);
  }

  if(nbplayers==4){nbpartsEq1(screen);};
  if(nbplayers==6){nbpartsEq1(screen);};
};

void nbpartsEq1(SDL_Surface *screen){modeparts=1;set_boardParts(screen);}
void nbpartsEq2(SDL_Surface *screen){modeparts=2;set_boardParts(screen);}
void nbpartsEq3(SDL_Surface *screen){modeparts=3;set_boardParts(screen);}


void set_boardParts(SDL_Surface *screen){
  displayColor(screen, 0xE9DBAD);
  SDL_Surface *text = initText("Nombre de Sommets par Joueurs", 36, 0x000000, TTF_STYLE_UNDERLINE);
  displayText(screen, text, (screen->w)/2 - (text->w)/2 , 40);

  int btnHeight = 45, btnWidth = 45;

  int inter=16;
  int xm = (screen->w)/2;
  int ym = (screen->h)/2;

  Button menu[3] = {

    initButtonRect(xm-289          , ym + 20 - btnHeight/2, btnWidth, btnHeight, 0x000000, "<", 32, 0xFFFFFF, TTF_STYLE_ITALIC, comptminus_modepart),
    initButtonRect(xm+289 -btnWidth, ym + 20 - btnHeight/2, btnWidth, btnHeight, 0x000000, ">", 32, 0xFFFFFF, TTF_STYLE_ITALIC, comptplus_modepart),
    initButtonRect(xm+289 -btnWidth, ym + 342- btnHeight  , btnWidth, btnHeight, 0x000000, "OK", 28, 0xFFFFFF, TTF_STYLE_ITALIC, validparts),
  };
  switch(nbplayers){
    case 2:
      switch (modeparts){
        case 1: limitmodeparts=3;configDef=(comptmodeparts-1);displayImg(screen, xm-289 , ym-311, modegameschar[comptmodeparts-1]);break;
        case 2: limitmodeparts=6;configDef=(comptmodeparts+2);displayImg(screen, xm-289 , ym-311, modegameschar[comptmodeparts+2]);break;
        case 3: limitmodeparts=2;configDef=(comptmodeparts+8);displayImg(screen, xm-289 , ym-311, modegameschar[comptmodeparts+8]);break;
      }
      displayMenu(menu, screen, 3);
      waitEvent(menu, screen, 3);
      break;
    case 3:
      limitmodeparts=1;
      if(modeparts==1){configDef=(comptmodeparts+10);}
      else{configDef=(comptmodeparts+11);}
      set_boardMode(screen);break;
    case 4:
      limitmodeparts=3;
      configDef=(comptmodeparts+12);
      displayImg(screen, xm-289 , ym-311, modegameschar[comptmodeparts+12]);
      displayMenu(menu, screen, 3);
      waitEvent(menu, screen, 3);
      break;
    case 6:
      limitmodeparts=1;
      configDef=(comptmodeparts+15);
      set_boardMode(screen);break;
  }
}

void comptplus_modepart(SDL_Surface *screen){
  if(comptmodeparts>=limitmodeparts){comptmodeparts=1;}
  else{comptmodeparts+=1;}
  set_boardParts(screen);}

void comptminus_modepart(SDL_Surface *screen){
  if(comptmodeparts<=1){comptmodeparts=limitmodeparts;}
  else{comptmodeparts-=1;}
  set_boardParts(screen);}

void validparts(SDL_Surface *screen){set_boardMode(screen);}

void set_boardMode(SDL_Surface *screen){
  switch(configDef){
    case 0: framechar="../img/Frame_2_A.png"; part[0]=9; part[1]=9; part[2]=2; part[3]=9; part[4]=9; part[5]=1;break;
    case 1: framechar="../img/Frame_2_B.png"; part[0]=1; part[1]=9; part[2]=9; part[3]=2; part[4]=9; part[5]=9;break;
    case 2: framechar="../img/Frame_2_C.png"; part[0]=9; part[1]=1; part[2]=9; part[3]=9; part[4]=2; part[5]=9;break;
    case 3: framechar="../img/Frame_4_A.png"; part[0]=1; part[1]=9; part[2]=2; part[3]=2; part[4]=9; part[5]=1;break;
    case 4: framechar="../img/Frame_4_B.png"; part[0]=1; part[1]=1; part[2]=9; part[3]=2; part[4]=2; part[5]=9;break;
    case 5: framechar="../img/Frame_4_C.png"; part[0]=9; part[1]=1; part[2]=1; part[3]=9; part[4]=2; part[5]=2;break;
    case 6: framechar="../img/Frame_4_B.png"; part[0]=1; part[1]=2; part[2]=9; part[3]=2; part[4]=1; part[5]=9;break;
    case 7: framechar="../img/Frame_4_C.png"; part[0]=9; part[1]=1; part[2]=2; part[3]=9; part[4]=2; part[5]=1;break;
    case 8: framechar="../img/Frame_4_A.png"; part[0]=1; part[1]=9; part[2]=1; part[3]=2; part[4]=9; part[5]=2;break;
    case 9: framechar="../img/Frame_6.png"; part[0]=1; part[1]=1; part[2]=2; part[3]=2; part[4]=2; part[5]=1;break;
    case 10: framechar="../img/Frame_6.png"; part[0]=1; part[1]=2; part[2]=1; part[3]=2; part[4]=1; part[5]=2;break;
    case 11: framechar="../img/Frame_6.png"; part[0]=1; part[1]=0; part[2]=2; part[3]=0; part[4]=3; part[5]=0;break;
    case 12: framechar="../img/Frame_6.png"; part[0]=1; part[1]=1; part[2]=2; part[3]=2; part[4]=3; part[5]=3;break;
    case 13: framechar="../img/Frame_4_B.png"; part[0]=1; part[1]=2; part[2]=9; part[3]=3; part[4]=4; part[5]=9;break;
    case 14: framechar="../img/Frame_4_C.png"; part[0]=9; part[1]=1; part[2]=2; part[3]=9; part[4]=3; part[5]=4;break;
    case 15: framechar="../img/Frame_4_A.png"; part[0]=4; part[1]=9; part[2]=1; part[3]=2; part[4]=9; part[5]=3;break;
    case 16: framechar="../img/Frame_6.png"; part[0]=1; part[1]=2; part[2]=3; part[3]=4; part[4]=5; part[5]=6;break;
  }
  set_playersStates(screen);
}

void set_playersStates(SDL_Surface *screen){

  SDL_Surface *text = initText("Choix des couleurs par joueurs", 36, 0x000000, TTF_STYLE_UNDERLINE);
  displayColor(screen, 0xE9DBAD);
  displayText(screen, text, (screen->w)/2 - (text->w)/2 , 40);

  char text_nb[2];
  int cadre=(screen->h) - 90 - 20;
  int intercadre=cadre/(nbplayers+1);

  for(int i=1; i<(nbplayers+1); i++){
    sprintf(text_nb, "%d", i);

    SDL_Surface *text_nbplayers = initText("Joueur ", 24, 0x000000, TTF_STYLE_NORMAL);
    SDL_Surface *text2_nbplayers = initText(text_nb, 24, 0x000000, TTF_STYLE_NORMAL);
    displayText(screen, text_nbplayers, 200 , 90 + intercadre*i);
    displayText(screen, text2_nbplayers, 280 , 90 + intercadre*i);

    if(i<comptplayer){
      displayImg(screen, 320 , 90 + intercadre*i - 13, cellchar[i][0]);
    }
  }

  if(comptplayer<=nbplayers){
    int btnHeight = 45, btnWidth = 45;

    Button menu[3] = {

      initButtonRect(420, 90 + intercadre*comptplayer - 10, btnWidth, btnHeight, 0x000000, "<", 32, 0xFFFFFF, TTF_STYLE_ITALIC, comptminus_player),
      initButtonRect(480, 90 + intercadre*comptplayer - 10, btnWidth, btnHeight, 0x000000, ">", 32, 0xFFFFFF, TTF_STYLE_ITALIC, comptplus_player),
      initButtonRect(540, 90 + intercadre*comptplayer - 10, btnWidth, btnHeight, 0x000000, "OK", 28, 0xFFFFFF, TTF_STYLE_ITALIC, validcolor),
    };
    displayImg(screen, 320 , 90 + intercadre*comptplayer - 13, cellchar[comptcolor][0]);

    displayMenu(menu, screen, 3);

    waitEvent(menu, screen, 3);
  }
  else{
    comptcolor=1;
    comptplayer=1;
    menu_main(screen);
  }
}

void comptplus_player(SDL_Surface *screen){
  if (comptcolor==6){comptcolor=comptplayer;}
  else{comptcolor+=1;}
  set_playersStates(screen);}

void comptminus_player(SDL_Surface *screen){
  if(comptcolor==comptplayer){comptcolor=6;}
  else{comptcolor-=1;}
  set_playersStates(screen);}

void validcolor(SDL_Surface *screen){
  echangStates(comptplayer,comptcolor);
  comptplayer+=1;
  comptcolor=comptplayer;
  set_playersStates(screen);
}

void echangStates(int comptcolor,int comptplayer){
  char temp[6][20],temp2[2][20];
  for(int i=0;i<6;i++){
    strcpy(temp[i],partchar[comptcolor][i]);
    strcpy(partchar[comptcolor][i],partchar[comptplayer][i]);
    strcpy(partchar[comptplayer][i],temp[i]);
  }
  for(int i=0;i<2;i++){
    strcpy(temp2[i],cellchar[comptcolor][i]);
    strcpy(cellchar[comptcolor][i],cellchar[comptplayer][i]);
    strcpy(cellchar[comptplayer][i],temp2[i]);
  }
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
