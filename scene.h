#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QApplication>//for using quit()
#include <QGraphicsPixmapItem>
#include <QWaitCondition>
#include <QSound>
#include <QTimer>
#include <QTime>//for waiting
#include "btn.h"


class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    /* function */
    Scene(QObject *parent = 0);
    void Init(int x_start ); // For screen initialize
    void bgChange(string mode);
    /*void bgChangeStart();
    void bgChangePlay(); // For background change from start to game
    void bgChangeExit();
    void bgChangePause();*/
    void bgRecover(); // For background change back to start page
    void gameInit(); // Start the game page
    //void hitMove();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    /* Variable */
    //start
    Btn *btn_start;
    Btn *btn_exit;
    Btn *btn_face;
    bool face_check;
    int face_count;
    int btn_w;
    int btn_h;
    int btn_face_w;
    int btn_face_h;
    //play
    Btn *btn_pause;
    int pause_count;
    int btn_pause_w;
    int btn_pause_h;
    //exit
    Btn *btn_yes;
    Btn *btn_no;
    int btn_yes_w;
    int btn_yes_h;
    //pause
    Btn *btn_conti;
    Btn *btn_back;
    Btn *btn_retry;
    int btn_conti_w;
    int btn_conti_h;

    int btn_small_w;
    int btn_small_h;

    // For sound
    QSound *bgm;
    QSound *click;
    QSound *meow;

    // For timer
    QTimer *timer;

    /* Use to control the scene page */
    string screenMode;
    // For scene boundary
    int upperBound;
    int lowerBound;
    int leftBound;
    int rightBound;

};

#endif // SCENE_H
