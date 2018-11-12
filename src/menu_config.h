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
void jeu();

void menu_main(SDL_Surface *screen){
  Button menu[4] = {

    initButton((800/2 - 322/2), (213 - 90/2), "Yolo", "../img/Jeu.png", jeu),
    initButton((800/2 - 322/2), (338 - 90/2), "Yolo", "../img/Regles.png", regles0),
    initButton((800/2 - 322/2), (463 - 90/2), "Yolo", "../img/Parametres.png", settings),
    initButton((800/2 - 322/2), (588 - 90/2), "Yolo", "../img/Quitter.png", exit),

  };
  displayMenu(menu, screen, 4);
  waitEvent(menu, screen, 4);
}

void settings(SDL_Surface *screen){
  Button menu[2] = {

    initButton(0, 0, "Yolo", "../img/Retour.png", menu_main),
    initButton(400, 300, "Yolo", "../img/Quitter.png", exit),

  };

  displayMenu(menu, screen, 2);
  waitEvent(menu, screen, 2);
}

void regles0(SDL_Surface *screen){
  Button menu[3] = {

    initButton((1*800/5 - 189/2), (800 - 120), "Yolo", "../img/Retour.png", menu_main),
    initButton((4*800/5 - 189/2), (800 - 120), "Yolo", "../img/Suivant.png", regles1),
    initButton((800/2 - 174/2), (800/2 - 163/2), "Yolo", "../img/Texte0.png", exit),

  };
  displayMenu(menu, screen, 3);
  waitEvent(menu, screen, 3);
}

void regles1(SDL_Surface *screen){
  Button menu[3] = {

    initButton((1*800/5 - 189/2), (800 - 120), "Yolo", "../img/Retour.png", regles0),
    initButton((4*800/5 - 189/2), (800 - 120), "Yolo", "../img/Suivant.png", regles2),
    initButton((800/2 - 174/2), (800/2 - 163/2), "Yolo", "../img/Texte1.png", exit),

  };
  displayMenu(menu, screen, 3);
  waitEvent(menu, screen, 3);
}

void regles2(SDL_Surface *screen){
  Button menu[3] = {

    initButton((1*800/5 - 189/2), (800 - 120), "Yolo", "../img/Retour.png", regles1),
    initButton((4*800/5 - 189/2), (800 - 120), "Yolo", "../img/Suivant.png", regles3),
    initButton((800/2 - 174/2), (800/2 - 163/2), "Yolo", "../img/Texte2.png", exit),

  };
  displayMenu(menu, screen, 3);
  waitEvent(menu, screen, 3);
}

void regles3(SDL_Surface *screen){
  Button menu[3] = {

    initButton((1*800/5 - 189/2), (800 - 120), "Yolo", "../img/Retour.png", regles2),
    initButton((4*800/5 - 189/2), (800 - 120), "Yolo", "../img/Suivant.png", regles4),
    initButton((800/2 - 174/2), (800/2 - 163/2), "Yolo", "../img/Texte3.png", exit),

  };
  displayMenu(menu, screen, 3);
  waitEvent(menu, screen, 3);
}

void regles4(SDL_Surface *screen){
  Button menu[3] = {

    initButton((1*800/5 - 189/2), (800 - 120), "Yolo", "../img/Retour.png", regles3),
    initButton((4*800/5 - 189/2), (800 - 120), "Yolo", "../img/Suivant.png", regles5),
    initButton((800/2 - 174/2), (800/2 - 163/2), "Yolo", "../img/Texte4.png", exit),

  };
  displayMenu(menu, screen, 3);
  waitEvent(menu, screen, 3);
}

void regles5(SDL_Surface *screen){
  Button menu[3] = {

    initButton((1*800/5 - 189/2), (800 - 120), "Yolo", "../img/Retour.png", regles4),
    initButton((4*800/5 - 189/2), (800 - 120), "Yolo", "../img/Suivant.png", regles6),
    initButton((800/2 - 174/2), (800/2 - 163/2), "Yolo", "../img/Texte5.png", exit),

  };
  displayMenu(menu, screen, 3);
  waitEvent(menu, screen, 3);
}

void regles6(SDL_Surface *screen){
  Button menu[3] = {

    initButton((1*800/5 - 189/2), (800 - 120), "Yolo", "../img/Retour.png", regles5),
    initButton((4*800/5 - 189/2), (800 - 120), "Yolo", "../img/Suivant.png", regles7),
    initButton((800/2 - 174/2), (800/2 - 163/2), "Yolo", "../img/Texte6.png", exit),

  };
  displayMenu(menu, screen, 3);
  waitEvent(menu, screen, 3);
}

void regles7(SDL_Surface *screen){
  Button menu[3] = {

    initButton((1*800/5 - 189/2), (800 - 120), "Yolo", "../img/Retour.png", regles6),
    initButton((4*800/5 - 189/2), (800 - 120), "Yolo", "../img/Suivant.png", regles8),
    initButton((800/2 - 174/2), (800/2 - 163/2), "Yolo", "../img/Texte7.png", exit),

  };
  displayMenu(menu, screen, 3);
  waitEvent(menu, screen, 3);
}

void regles8(SDL_Surface *screen){
  Button menu[3] = {

    initButton((1*800/5 - 189/2), (800 - 120), "Yolo", "../img/Retour.png", regles7),
    initButton((4*800/5 - 189/2), (800 - 120), "Yolo", "../img/Menu.png", menu_main),
    initButton((800/2 - 174/2), (800/2 - 163/2), "Yolo", "../img/Texte8.png", exit),

  };
  displayMenu(menu, screen, 3);
  waitEvent(menu, screen, 3);
}

void jeu(SDL_Surface *screen){
    int part[6]={1,2,0,0,2,0};
    int nbjoueurs=2;
    Hex jeu;

    jeu = initHex(17,13,part[0],part[1],part[2],part[3],part[4],part[5]);
    rafraichirjeu(jeu, screen);

     int n = tourpartour(jeu, nbjoueurs, part, screen);

    rafraichirjeu(jeu, screen);

    printf("\nPartie Terminé ! Joueur %d a gagné !!!\n",n);
    pause();
    menu_main(screen);
}
