#define WIDHT 800
#define HEIGHT 800

#define SCREEN_SHIFT_V 70
#define SCREEN_SHIFT_H 110

char *framechar = "../img/Frame_6.png";
char cellchar[6][2][20]={ {"../img/Cell_1.png","../img/Cell_11.png"},
                          {"../img/Cell_2.png","../img/Cell_12.png"},
                          {"../img/Cell_3.png","../img/Cell_13.png"},
                          {"../img/Cell_4.png","../img/Cell_14.png"},
                          {"../img/Cell_5.png","../img/Cell_15.png"},
                          {"../img/Cell_6.png","../img/Cell_16.png"},
                        };

int nbplayers=6;

int part[6]={1,2,3,4,5,6};
char partchar[7][6][20]={ {"../img/J0_1.png","../img/J0_2-6.png","../img/J0_3-5.png","../img/J0_4.png","../img/J0_3-5.png","../img/J0_2-6.png"},
                          {"../img/J1_1.png","../img/J1_2-6.png","../img/J1_3-5.png","../img/J1_4.png","../img/J1_3-5.png","../img/J1_2-6.png"},
                          {"../img/J2_1.png","../img/J2_2-6.png","../img/J2_3-5.png","../img/J2_4.png","../img/J2_3-5.png","../img/J2_2-6.png"},
                          {"../img/J3_1.png","../img/J3_2-6.png","../img/J3_3-5.png","../img/J3_4.png","../img/J3_3-5.png","../img/J3_2-6.png"},
                          {"../img/J4_1.png","../img/J4_2-6.png","../img/J4_3-5.png","../img/J4_4.png","../img/J4_3-5.png","../img/J4_2-6.png"},
                          {"../img/J5_1.png","../img/J5_2-6.png","../img/J5_3-5.png","../img/J5_4.png","../img/J5_3-5.png","../img/J5_2-6.png"},
                          {"../img/J6_1.png","../img/J6_2-6.png","../img/J6_3-5.png","../img/J6_4.png","../img/J6_3-5.png","../img/J6_2-6.png"},
                        };
