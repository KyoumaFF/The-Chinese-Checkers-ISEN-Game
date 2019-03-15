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
void game_config_2(SDL_Surface *screen);

void game(SDL_Surface *screen);
void rules0(SDL_Surface *screen);void rules1(SDL_Surface *screen);
void rules2(SDL_Surface *screen);void rules3(SDL_Surface *screen);
void rules4(SDL_Surface *screen);void rules5(SDL_Surface *screen);

void IA2v2(SDL_Surface *screen);

////////////////////////////////////////////////////////////////////

void menu_main(SDL_Surface *screen){
  pageRules = 0;
  Button menu[5] = {

    initButtonImg((800/2 - 322/2), (213 - 90/2), "../img/Button_Game.png", game),
    initButtonImg((800/2 - 322/2), (338 - 90/2), "../img/Button_Rules.png", rules0),
    initButtonImg((800/2 - 322/2), (463 - 90/2), "../img/Button_Settings.png", settings),
    initButtonImg((800/2 - 322/2), (588 - 90/2), "../img/Button_Exit.png", exit),
    initButtonImg(50, 588, "../img/Cell_7.png", IA2v2)

  };

  SDL_Surface *text = initText("Dames chinoises", 36, 0x000000, TTF_STYLE_UNDERLINE | TTF_STYLE_ITALIC);

  displayColor(screen, 0xE9DBAD);
  displayText(screen, text, (screen->w)/2 - (text->w)/2 , 40);
  displayMenu(menu, screen, 5);
  waitEvent(menu, screen, 5);
}

void settings(SDL_Surface *screen){
  int inter=14;
  int btnHeight = 115+inter, btnWidth = 446;
  int xm = (screen->w)/2 - btnWidth/2;
  int ym = (screen->h)/2 - btnHeight/2;

  Button menu[3] = {
    initButtonImg(xm, ym - btnHeight, "../img/ConfigAct2.png", game_config),
    initButtonImg(xm, ym            , "../img/ParamJeu.png", set_game_nbplayers),
    initButtonImg(xm, ym + btnHeight, "../img/RetourMenu2.png", menu_main)
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
  SDL_Surface *text_nbplayers = initText("Nombre de joueurs :", 24, 0x000000, TTF_STYLE_NORMAL);
  SDL_Surface *text2_nbplayers = initText(text_nb, 24, 0x000000, TTF_STYLE_NORMAL);

  displayColor(screen, 0xE9DBAD);
  displayText(screen, text, (screen->w)/2 - (text->w)/2 , 40);
  displayText(screen, text_nbplayers, 40 , 140);
  displayText(screen, text2_nbplayers, 265 , 141);
  displayMenu(menu, screen, 1);

  displayImg(screen, (screen->w - 585)/2, screen->h - 668 - 40, "../img/Frame_0.png");
  displayImg(screen, 197, 243, "../img/Center_0.png");
  displayImg(screen, (screen->w - 585)/2, screen->h - 668 - 40, "../img/Frame_2_A.png");
  displayImg(screen, (screen->w - 585)/2, screen->h - 668 - 40, "../img/Frame_2_B.png");
  for(int i=0; i<6; i++){
    if (part[i]!=9){
      displayImg(screen, partpos[i*2], partpos[(i*2)+1], partchar[part[i]][i]);
    }
  }

  waitEvent(menu, screen, 1);
}

void set_game_nbplayers(SDL_Surface *screen){
  int inter=16;
  int btnHeight = 90, btnWidth = 116;
  int xm = (screen->w)/2;
  int ym = (screen->h)/2 - btnHeight/2;

  Button menu[4] = {
    initButtonImg(xm - (2*btnWidth) - 1*inter - inter/2, ym, "../img/Btn_2.png", nbplayersEq2),
    initButtonImg(xm - (1*btnWidth) - 0*inter - inter/2, ym, "../img/Btn_3.png", nbplayersEq3),
    initButtonImg(xm + (0*btnWidth) + 0*inter + inter/2, ym, "../img/Btn_4.png", nbplayersEq4),
    initButtonImg(xm + (1*btnWidth) + 1*inter + inter/2, ym, "../img/Btn_6.png", nbplayersEq6)
  };

  SDL_Surface *text = initText("Parametrage du jeu", 36, 0x000000, TTF_STYLE_UNDERLINE);
  SDL_Surface *text_nbplayers = initText("Nombre de joueurs :", 30, 0x000000, TTF_STYLE_NORMAL);

  displayColor(screen, 0xE9DBAD);
  displayText(screen, text, (screen->w)/2 - (text->w)/2 , 40);
  displayText(screen, text_nbplayers,70, 270);
  displayMenu(menu, screen, 4);

  waitEvent(menu, screen, 4);
}

void nbplayersEq2(SDL_Surface *screen){nbplayers=2;set_game_nbparts(screen);}
void nbplayersEq3(SDL_Surface *screen){nbplayers=3;set_game_nbparts(screen);}
void nbplayersEq4(SDL_Surface *screen){nbplayers=4;set_game_nbparts(screen);}
void nbplayersEq6(SDL_Surface *screen){nbplayers=6;set_game_nbparts(screen);}

void set_game_nbparts(SDL_Surface *screen){
  int inter=16;
  int btnHeight = 90, btnWidth = 116;
  int xm = (screen->w)/2;
  int ym = (screen->h)/2 - btnHeight/2;
  comptmodeparts = 1;

  if(nbplayers==2){
  Button menu[4] = {
    initButtonImg(xm - (1*btnWidth) - 1*inter - btnWidth/2, ym, "../img/Btn_1.png", nbpartsEq1),
    initButtonImg(xm - btnWidth/2                         , ym, "../img/Btn_2.png", nbpartsEq2),
    initButtonImg(xm + 1*inter + btnWidth/2               , ym, "../img/Btn_3.png", nbpartsEq3),
    initButtonImg(40, screen->h - 40 - 90, "../img/Button_Back.png", set_game_nbplayers)
  };

  SDL_Surface *text = initText("Parametrage du jeu", 36, 0x000000, TTF_STYLE_UNDERLINE);
  SDL_Surface *text_nbplayers = initText("Nombre de pointes par joueur :", 30, 0x000000, TTF_STYLE_NORMAL);

  displayColor(screen, 0xE9DBAD);
  displayText(screen, text, (screen->w)/2 - (text->w)/2 , 40);
  displayText(screen, text_nbplayers, 70 , 270);
  displayMenu(menu, screen, 4);

  waitEvent(menu, screen, 4);
  }

  if(nbplayers==3){
  Button menu[3] = {
    initButtonImg(xm - 1*btnWidth - inter/2, ym, "../img/Btn_1.png", nbpartsEq1),
    initButtonImg(xm + inter/2             , ym, "../img/Btn_2.png", nbpartsEq2),
    initButtonImg(40, screen->h - 40 - 90, "../img/Button_Back.png", set_game_nbplayers)
  };

  SDL_Surface *text = initText("Parametrage du jeu", 36, 0x000000, TTF_STYLE_UNDERLINE);
  SDL_Surface *text_nbplayers = initText("Nombre de pointes par joueur :", 30, 0x000000, TTF_STYLE_NORMAL);

  displayColor(screen, 0xE9DBAD);
  displayText(screen, text, (screen->w)/2 - (text->w)/2 , 40);
  displayText(screen, text_nbplayers, 70 , 270);
  displayMenu(menu, screen, 3);

  waitEvent(menu, screen, 3);
  }

  if(nbplayers==4){nbpartsEq1(screen);};
  if(nbplayers==6){nbpartsEq1(screen);};
};

void nbpartsEq1(SDL_Surface *screen){modeparts=1;set_boardParts(screen);}
void nbpartsEq2(SDL_Surface *screen){modeparts=2;set_boardParts(screen);}
void nbpartsEq3(SDL_Surface *screen){modeparts=3;set_boardParts(screen);}


void set_boardParts(SDL_Surface *screen){
  comptplayer=comptcolor=1;
  displayColor(screen, 0xE9DBAD);
  SDL_Surface *text = initText("Disposition du Plateau", 36, 0x000000, TTF_STYLE_UNDERLINE);
  displayText(screen, text, (screen->w)/2 - (text->w)/2 , 40);

  int btnHeight = 45, btnWidth = 80;

  int inter=16;
  int xm = (screen->w)/2;
  int ym = (screen->h)/2;

  Button menu[4] = {
    initButtonImg(xm-289     , ym + 20 - btnHeight/2, "../img/Arrow1_2.png", comptminus_modepart),
    initButtonImg(xm+289 - 58, ym + 20 - btnHeight/2, "../img/Arrow2_2.png", comptplus_modepart),
    initButtonImg(xm+289 - 70, ym + 342- btnHeight  , "../img/Ok_2.png", validparts),
    initButtonImg(40, screen->h - 40 - 90, "../img/Button_Back.png", set_game_nbparts)
  };
  switch(nbplayers){
    case 2:
      switch (modeparts){
        case 1: limitmodeparts=3;configDef=(comptmodeparts-1);displayImg(screen, xm-292 , ym-314, "../img/Frame_0.png");displayImg(screen, xm-289 , ym-311, modegameschar[comptmodeparts-1]);break;
        case 2: limitmodeparts=6;configDef=(comptmodeparts+2);displayImg(screen, xm-292 , ym-314, "../img/Frame_0.png");displayImg(screen, xm-289 , ym-311, modegameschar[comptmodeparts+2]);break;
        case 3: limitmodeparts=2;configDef=(comptmodeparts+8);displayImg(screen, xm-292 , ym-314, "../img/Frame_0.png");displayImg(screen, xm-289 , ym-311, modegameschar[comptmodeparts+8]);break;
      }
      displayMenu(menu, screen, 4);
      waitEvent(menu, screen, 4);
      break;
    case 3:
      limitmodeparts=1;
      if(modeparts==1){configDef=(comptmodeparts+10);}
      else{configDef=(comptmodeparts+11);}
      set_boardMode(screen);break;
    case 4:
      menu[3]=initButtonImg(40, screen->h - 40 - 90, "../img/Button_Back.png", set_game_nbplayers);
      limitmodeparts=3;
      configDef=(comptmodeparts+12);
      displayImg(screen, xm-294 , ym-314, "../img/Frame_0.png");
      displayImg(screen, xm-289 , ym-311, modegameschar[comptmodeparts+12]);
      displayMenu(menu, screen, 4);
      waitEvent(menu, screen, 4);
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
    case 0: framechar="../img/Frame_6.png"; part[0]=7; part[1]=7; part[2]=2; part[3]=7; part[4]=7; part[5]=1;break;
    case 1: framechar="../img/Frame_6.png"; part[0]=1; part[1]=7; part[2]=7; part[3]=2; part[4]=7; part[5]=7;break;
    case 2: framechar="../img/Frame_6.png"; part[0]=7; part[1]=1; part[2]=7; part[3]=7; part[4]=2; part[5]=7;break;
    case 3: framechar="../img/Frame_6.png"; part[0]=1; part[1]=7; part[2]=2; part[3]=2; part[4]=7; part[5]=1;break;
    case 4: framechar="../img/Frame_6.png"; part[0]=1; part[1]=1; part[2]=7; part[3]=2; part[4]=2; part[5]=7;break;
    case 5: framechar="../img/Frame_6.png"; part[0]=7; part[1]=1; part[2]=1; part[3]=7; part[4]=2; part[5]=2;break;
    case 6: framechar="../img/Frame_6.png"; part[0]=1; part[1]=2; part[2]=7; part[3]=2; part[4]=1; part[5]=7;break;
    case 7: framechar="../img/Frame_6.png"; part[0]=7; part[1]=1; part[2]=2; part[3]=7; part[4]=2; part[5]=1;break;
    case 8: framechar="../img/Frame_6.png"; part[0]=1; part[1]=7; part[2]=1; part[3]=2; part[4]=7; part[5]=2;break;
    case 9: framechar="../img/Frame_6.png"; part[0]=1; part[1]=1; part[2]=2; part[3]=2; part[4]=2; part[5]=1;break;
    case 10: framechar="../img/Frame_6.png"; part[0]=1; part[1]=2; part[2]=1; part[3]=2; part[4]=1; part[5]=2;break;
    case 11: framechar="../img/Frame_6.png"; part[0]=1; part[1]=0; part[2]=2; part[3]=0; part[4]=3; part[5]=0;break;
    case 12: framechar="../img/Frame_6.png"; part[0]=1; part[1]=1; part[2]=2; part[3]=2; part[4]=3; part[5]=3;break;
    case 13: framechar="../img/Frame_6.png"; part[0]=1; part[1]=2; part[2]=7; part[3]=3; part[4]=4; part[5]=7;break;
    case 14: framechar="../img/Frame_6.png"; part[0]=7; part[1]=1; part[2]=2; part[3]=7; part[4]=3; part[5]=4;break;
    case 15: framechar="../img/Frame_6.png"; part[0]=4; part[1]=7; part[2]=1; part[3]=2; part[4]=7; part[5]=3;break;
    case 16: framechar="../img/Frame_6.png"; part[0]=1; part[1]=2; part[2]=3; part[3]=4; part[4]=5; part[5]=6;break;
  }
  set_playersStates(screen);
}

void set_playersStates(SDL_Surface *screen){

  SDL_Surface *text = initText("Choix des couleurs", 36, 0x000000, TTF_STYLE_UNDERLINE);
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

    Button menu[4] = {
      initButtonImg(415, 90 + intercadre*comptplayer - 10, "../img/Arrow1_2.png", comptminus_player),
      initButtonImg(480, 90 + intercadre*comptplayer - 10, "../img/Arrow2_2.png", comptplus_player),
      initButtonImg(545, 90 + intercadre*comptplayer - 10, "../img/Ok_2.png", validcolor),
      initButtonImg(40, screen->h - 40 - 60, "../img/Retour3.png", set_boardParts)
    };

    if(nbplayers == 3){menu[3]=initButtonImg(40, screen->h - 40 - 60, "../img/Retour3.png", set_game_nbparts);}
    if(nbplayers == 6){menu[3]=initButtonImg(40, screen->h - 40 - 60, "../img/Retour3.png", set_game_nbplayers);}
    displayImg(screen, 320 , 90 + intercadre*comptplayer - 13, cellchar[comptcolor][0]);

    displayMenu(menu, screen, 4);

    waitEvent(menu, screen, 4);
  }
  else{
    comptcolor=1;
    comptplayer=1;
    game_config_2(screen);
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
  for(int i=0;i<3;i++){
    strcpy(temp2[i],cellchar[comptcolor][i]);
    strcpy(cellchar[comptcolor][i],cellchar[comptplayer][i]);
    strcpy(cellchar[comptplayer][i],temp2[i]);
  }
}

void game_config_2(SDL_Surface *screen){
  char text_nb[2];
  sprintf(text_nb, "%d", nbplayers);

  int btnHeight = 90, btnWidth = 189;
  int xm = (screen->w)/2 - btnWidth/2;

  int partpos[12]={314,98,511,250,511,440,314,592,115,440,115,250};

  Button menu[2] = {
    initButtonImg(screen->w - 40 - 189, screen->h - 40 - 90, "../img/Button_Next.png", settings),
    initButtonImg(40, screen->h - 40 - 90, "../img/Button_Back.png", set_playersStates)
  };

  SDL_Surface *text = initText("Configuration actuelle du jeu", 36, 0x000000, TTF_STYLE_UNDERLINE);
  SDL_Surface *text_nbplayers = initText("Nombre de joueurs :", 24, 0x000000, TTF_STYLE_NORMAL);
  SDL_Surface *text2_nbplayers = initText(text_nb, 24, 0x000000, TTF_STYLE_NORMAL);

  displayColor(screen, 0xE9DBAD);
  displayText(screen, text, (screen->w)/2 - (text->w)/2 , 40);
  displayText(screen, text_nbplayers, 40 , 140);
  displayText(screen, text2_nbplayers, 265 , 141);
  displayMenu(menu, screen, 2);

  displayImg(screen, (screen->w - 585)/2, screen->h - 668 - 40, "../img/Frame_0.png");
  displayImg(screen, 197, 243, "../img/Center_0.png");
  displayImg(screen, (screen->w - 585)/2, screen->h - 668 - 40, "../img/Frame_2_A.png");
  displayImg(screen, (screen->w - 585)/2, screen->h - 668 - 40, "../img/Frame_2_B.png");
  for(int i=0; i<6; i++){
    if (part[i]!=9){
      displayImg(screen, partpos[i*2], partpos[(i*2)+1], partchar[part[i]][i]);
    }
  }

  waitEvent(menu, screen, 2);
}

void game(SDL_Surface *screen){
  Dames game;

  game = initDames(17,13,part[0],part[1],part[2],part[3],part[4],part[5]);
  updateGame(game, screen);

   int n = turnByTurn(game, nbplayers, part, screen);

  updateGame(game, screen);
  displayImg(screen, (screen->w)/2 - 749/2,(screen->w)/2 - 158/2, cellchar[n][2]);

  SDL_Surface *text = initText("Partie terminee ! Le joueur    a gagne !!! ", 26, 0x000000, TTF_STYLE_NORMAL);
  displayText(screen, text, (screen->w)/2 - (text->w)/2 , (screen->h)/2 - (text->h)/2);

  char text_nb[2];
  sprintf(text_nb, "%d", n);
  SDL_Surface *text1 = initText(text_nb, 26, 0x000000, TTF_STYLE_NORMAL);
  displayText(screen, text1, (screen->w)/2 - (text1->w)/2 + 90, (screen->h)/2 - (text1->h)/2);

  Button menu[1] = {
    initButtonImg(40, screen->h - 40 - 90, "../img/Button_Back.png", menu_main)
  };
  displayMenu(menu, screen, 1);
  waitEvent(menu,screen, 1);
}

void rules0(SDL_Surface *screen){
  Button menu[2] = {
    initButtonImg((screen->w)/2 - 94, screen->h - 40 - 90, "../img/Button_Menu.png", menu_main),
    initButtonImg((screen->w) - 40 - 189, (screen->h) - 40 - 90, "../img/Button_Next.png", rules1)
  };
  displayColor(screen, 0xE9DBAD);

  SDL_Surface *title = initText("Regles du jeu", 36, 0x000000, TTF_STYLE_UNDERLINE);
  displayText(screen, title, (screen->w)/2 - (title->w)/2 , 40);

  SDL_Surface *textrules1[3]=
  { initText("Le jeu de dames chinoises est un jeu au tour par tour", 20, 0x000000, 0),
    initText("qui se joue de 2 a 6 joueurs sur un plateau de 121 cases", 20, 0x000000, 0),
    initText("avec des pions de differentes couleurs.", 20, 0x000000, 0)};

  displayImg(screen, 180,190, "../img/Rules0_00.png");
  displayImg(screen, 444,207, "../img/Rules0_01.png");

  SDL_Surface *textrules2[2]=
  { initText("Le plateau peut avoir toutes ses pointes occupees ou en avoir certaines", 20, 0x000000, 0),
    initText("inutilisees. Les joueurs ne peuvent pas aller sur ces pointes inutilisees", 20, 0x000000, 0)};

  displayImg(screen, 180,460, "../img/Rules0_02.png");
  displayImg(screen, 448,460, "../img/Rules0_03.png");

  displayParagraphCenter(screen, textrules1, 130, 3);
  displayParagraphCenter(screen, textrules2, 420, 2);
  displayMenu(menu, screen, 2);
  waitEvent(menu,screen, 2);
}

void rules1(SDL_Surface *screen){
  Button menu[3] = {
    initButtonImg(40, screen->h - 40 - 90, "../img/Button_Back.png", rules0),
    initButtonImg((screen->w)/2 - 94, screen->h - 40 - 90, "../img/Button_Menu.png", menu_main),
    initButtonImg((screen->w) - 40 - 189, (screen->h) - 40 - 90, "../img/Button_Next.png", rules2)
  };
  displayColor(screen, 0xE9DBAD);

  SDL_Surface *title = initText("Regles du jeu", 36, 0x000000, TTF_STYLE_UNDERLINE);
  displayText(screen, title, (screen->w)/2 - (title->w)/2 , 40);

  displayImg(screen, 310,90, "../img/Rules01_00.png");

  SDL_Surface *textrules1[2]=
  { initText("Le but du jeu est de reunir tous ses", 20, 0x000000, 0),
    initText("pions dans la pointe opposee a celle de depart.", 20, 0x000000, 0)};

  displayImg(screen, 128,370, "../img/Rules01_01.png");
  displayImg(screen, 409,370, "../img/Rules01_02.png");

  displayParagraphCenter(screen, textrules1, 328, 2);
  displayMenu(menu, screen, 3);
  waitEvent(menu,screen, 3);
}

void rules2(SDL_Surface *screen){
  Button menu[3] = {
    initButtonImg(40, screen->h - 40 - 90, "../img/Button_Back.png", rules1),
    initButtonImg((screen->w)/2 - 94, screen->h - 40 - 90, "../img/Button_Menu.png", menu_main),
    initButtonImg((screen->w) - 40 - 189, (screen->h) - 40 - 90, "../img/Button_Next.png", rules3)
  };
  displayColor(screen, 0xE9DBAD);

  SDL_Surface *title = initText("Regles du jeu", 36, 0x000000, TTF_STYLE_UNDERLINE);
  displayText(screen, title, (screen->w)/2 - (title->w)/2 , 40);

  displayImg(screen, 310,90, "../img/Rules02_00.png");

  SDL_Surface *textrules1[2]=
  { initText("Si vous avez plusieurs pointes, il faut reunir", 20, 0x000000, 0),
    initText("vos pions dans toutes les pointes opposees aux votres.", 20, 0x000000, 0)};

  displayImg(screen, 128,370, "../img/Rules02_01.png");
  displayImg(screen, 409,370, "../img/Rules02_02.png");

  displayParagraphCenter(screen, textrules1, 328, 2);
  displayMenu(menu, screen, 3);
  waitEvent(menu,screen, 3);
}

void rules3(SDL_Surface *screen){
  Button menu[3] = {
    initButtonImg(40, screen->h - 40 - 90, "../img/Button_Back.png", rules2),
    initButtonImg((screen->w)/2 - 94, screen->h - 40 - 90, "../img/Button_Menu.png", menu_main),
    initButtonImg((screen->w) - 40 - 189, (screen->h) - 40 - 90, "../img/Button_Next.png", rules4)
  };
  displayColor(screen, 0xE9DBAD);

  SDL_Surface *title = initText("Regles du jeu", 36, 0x000000, TTF_STYLE_UNDERLINE);
  displayText(screen, title, (screen->w)/2 - (title->w)/2 , 40);

  SDL_Surface *undertitle = initText("Deplacements:", 24, 0x000000, TTF_STYLE_UNDERLINE | TTF_STYLE_ITALIC);
  displayText(screen, undertitle, 80, 170);

  SDL_Surface *text0 = initText("Il y a 2 types de deplacements possibles avec les pions.", 20, 0x000000, 0);
  displayText(screen, text0, (screen->w)/2 - (text0->w)/2 , 210);
  SDL_Surface *text1 = initText("Le                   sur des cases libres adjacentes.", 20, 0x000000, 0);
  displayText(screen, text1, (screen->w)/2 - (text1->w)/2 , 240);
  SDL_Surface *text2 = initText("saut simple", 20, 0xFF0000, TTF_STYLE_UNDERLINE);
  displayText(screen, text2, 218, 240);
  SDL_Surface *text3 = initText("Ce saut peut se faire dans une des 6 directions si la case concernee est libre.", 20, 0x000000, 0);
  displayText(screen, text3, (screen->w)/2 - (text3->w)/2 , 260);

  displayImg(screen, 110, 320, "../img/Rules03_00.png");
  displayImg(screen, 192, 393, "../img/MiniClickB.png");
  displayImg(screen, 360, 390, "../img/Arrow.png");
  displayImg(screen, 480, 320, "../img/Rules03_01.png");

  SDL_Surface *text4 = initText("Le saut simple est unique et marque la fin du tour du joueur.", 20, 0x000000, 0);
  displayText(screen, text4, (screen->w)/2 - (text4->w)/2 , 550);

  displayMenu(menu, screen, 3);
  waitEvent(menu,screen, 3);
}

void rules4(SDL_Surface *screen){
  Button menu[3] = {
    initButtonImg(40, screen->h - 40 - 90, "../img/Button_Back.png", rules3),
    initButtonImg((screen->w)/2 - 94, screen->h - 40 - 90, "../img/Button_Menu.png", menu_main),
    initButtonImg((screen->w) - 40 - 189, (screen->h) - 40 - 90, "../img/Button_Next.png", rules5)
  };
  displayColor(screen, 0xE9DBAD);

  SDL_Surface *title = initText("Regles du jeu", 36, 0x000000, TTF_STYLE_UNDERLINE);
  displayText(screen, title, (screen->w)/2 - (title->w)/2 , 40);

  SDL_Surface *undertitle = initText("Deplacements:", 24, 0x000000, TTF_STYLE_UNDERLINE | TTF_STYLE_ITALIC);
  displayText(screen, undertitle, 80, 170);

  SDL_Surface *text1 = initText("Le                     sur une case libre derriere une case occupee.", 20, 0x000000, 0);
  displayText(screen, text1, (screen->w)/2 - (text1->w)/2 , 240);
  SDL_Surface *text2 = initText("saut de pion", 20, 0x0000FF, TTF_STYLE_UNDERLINE);
  displayText(screen, text2, 154, 240);
  SDL_Surface *text3 = initText("Ce saut aussi peut se faire dans les 6 directions si la case concernee est libre.", 20, 0x000000, 0);
  displayText(screen, text3, (screen->w)/2 - (text3->w)/2 , 260);

  displayImg(screen, 110, 320, "../img/Rules04_00.png");
  displayImg(screen, 192, 393, "../img/MiniClickB.png");
  displayImg(screen, 360, 390, "../img/Arrow.png");
  displayImg(screen, 480, 320, "../img/Rules04_01.png");

  SDL_Surface *text4 = initText("Le saut de pion peut etre repete tant que des cases sont libres.", 20, 0x000000, 0);
  displayText(screen, text4, (screen->w)/2 - (text4->w)/2 , 540);

  displayMenu(menu, screen, 3);
  waitEvent(menu,screen, 3);
}

void rules5(SDL_Surface *screen){
  Button menu[2] = {
    initButtonImg(40, screen->h - 40 - 90, "../img/Button_Back.png", rules4),
    initButtonImg((screen->w)/2 - 94, screen->h - 40 - 90, "../img/Button_Menu.png", menu_main)
  };
  displayColor(screen, 0xE9DBAD);

  SDL_Surface *title = initText("Regles du jeu", 36, 0x000000, TTF_STYLE_UNDERLINE);
  displayText(screen, title, (screen->w)/2 - (title->w)/2 , 40);

  SDL_Surface *undertitle = initText("Deplacements:", 24, 0x000000, TTF_STYLE_UNDERLINE | TTF_STYLE_ITALIC);
  displayText(screen, undertitle, 80, 170);

  SDL_Surface *text0 = initText("L'enchainement de sauts de pions prend fin une fois", 20, 0x000000, 0);
  displayText(screen, text0, (screen->w)/2 - (text0->w)/2 , 240);

  SDL_Surface *text1 = initText(" que le joueur valide la case de deplacement.", 20, 0x000000, 0);
  displayText(screen, text1, (screen->w)/2 - (text1->w)/2 , 260);

  SDL_Surface *text2 = initText("Une fois les sauts de pions commences, le joueur", 20, 0x000000, 0);
  displayText(screen, text2, (screen->w)/2 - (text2->w)/2 , 540);

  SDL_Surface *text3 = initText("ne peut pas terminer son saut sur sa case d'origine.", 20, 0x000000, 0);
  displayText(screen, text3, (screen->w)/2 - (text3->w)/2 , 560);

  displayImg(screen, 40, 354, "../img/Rules05_00.png");
  displayImg(screen, 39, 397, "../img/miniClickB_2.png");

  displayImg(screen, 160, 400, "../img/miniArrow.png");
  displayImg(screen, 190, 354, "../img/Rules05_01.png");
  displayImg(screen, 237, 397, "../img/miniClickB_2.png");

  displayImg(screen, 310, 400, "../img/miniArrow.png");
  displayImg(screen, 340, 354, "../img/Rules05_02.png");
  displayImg(screen, 412, 355, "../img/miniClickB_2.png");

  displayImg(screen, 460, 400, "../img/miniArrow.png");
  displayImg(screen, 490, 354, "../img/Rules05_03.png");
  displayImg(screen, 562, 355, "../img/miniClickB_2.png");

  displayImg(screen, 610, 400, "../img/miniArrow.png");
  displayImg(screen, 640, 354, "../img/Rules05_04.png");

  displayMenu(menu, screen, 2);
  waitEvent(menu,screen, 2);
}

void IA2v2(SDL_Surface *screen){
  Dames game;
  part[0]=1;part[3]=2;part[1]=part[2]=part[4]=part[5]=7;nbplayers=2;modeparts=1;

  game = initDames(17,13,part[0],part[1],part[2],part[3],part[4],part[5]);
  updateGame(game, screen);

  int n = turnByTurnIA(game, nbplayers, part, screen);

  updateGame(game, screen);
  displayImg(screen, (screen->w)/2 - 749/2,(screen->w)/2 - 158/2, cellchar[n][2]);

  SDL_Surface *text = initText("Partie terminee ! Le joueur    a gagne !!! ", 26, 0x000000, TTF_STYLE_NORMAL);
  displayText(screen, text, (screen->w)/2 - (text->w)/2 , (screen->h)/2 - (text->h)/2);

  char text_nb[2];
  sprintf(text_nb, "%d", n);
  SDL_Surface *text1 = initText(text_nb, 26, 0x000000, TTF_STYLE_NORMAL);
  displayText(screen, text1, (screen->w)/2 - (text1->w)/2 + 90, (screen->h)/2 - (text1->h)/2);

  Button menu[1] = {
    initButtonImg(40, screen->h - 40 - 90, "../img/Button_Back.png", menu_main)
  };
  displayMenu(menu, screen, 1);
  waitEvent(menu,screen, 1);
}
