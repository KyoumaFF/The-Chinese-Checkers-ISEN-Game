int part[6]={1,9,9,2,9,9};
int nbplayers=2;

void menu_main(SDL_Surface *screen);
void regles0(SDL_Surface *screen);
void regles1(SDL_Surface *screen);
void regles2(SDL_Surface *screen);
void regles3(SDL_Surface *screen);
void regles4(SDL_Surface *screen);
void regles5(SDL_Surface *screen);
void regles6(SDL_Surface *screen);
void regles7(SDL_Surface *screen);
void regles8(SDL_Surface *screen);
void settings(SDL_Surface *screen);
void game(SDL_Surface *screen, int part[6], int nbplayers);

void menu_main(SDL_Surface *screen){
  Button menu[4] = {

    initButton((800/2 - 322/2), (213 - 90/2), "Yolo", "../img/Button_Game.png", game),
    initButton((800/2 - 322/2), (338 - 90/2), "Yolo", "../img/Button_Rules.png", regles0),
    initButton((800/2 - 322/2), (463 - 90/2), "Yolo", "../img/Button_Settings.png", settings),
    initButton((800/2 - 322/2), (588 - 90/2), "Yolo", "../img/Button_Exit.png", exit),

  };
  displayMenu(menu, screen, 4);
  waitEvent(menu, screen, 4);
}

void settings(SDL_Surface *screen){
  Button menu[2] = {

    initButton(0, 0, "Yolo", "../img/Button_Back.png", menu_main),
    initButton(400, 300, "Yolo", "../img/Button_Exit.png", exit),

  };

  displayMenu(menu, screen, 2);
  waitEvent(menu, screen, 2);
}

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

<<<<<<< HEAD
void game(SDL_Surface *screen){
=======
void game(SDL_Surface *screen, int part[6], int nbplayers){
>>>>>>> 5824458b9b172a0179c35c82fb52f7be71b5d03f
    Dames game;

    game = initDames(17,13,part[0],part[1],part[2],part[3],part[4],part[5]);
    updateGame(game, screen);

     int n = turnByTurn(game, nbplayers, part, screen);

    updateGame(game, screen);

    printf("\nPartie Terminé ! Joueur %d a gagné !!!\n",n);
    pause();
    menu_main(screen);
}
