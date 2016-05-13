#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QApplication>//for using quit()
#include <QGraphicsPixmapItem>
#include <QWaitCondition>
#include <QString>
#include <QSound>
#include <QTimer>
#include <QTime>//for waiting
#include <time.h>//for qsrand
#include <QKeyEvent>//for key press
#include <typeinfo>//for typeid
#include "btn.h"
#include "num.h"
#include "hit.h"
#include "other.h"
#include "hitr.h"
#include "hitb.h"

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    /* function */
    Scene(QObject *parent = 0);
    void Init(int x_start ); // For screen initialize
    void bgChange(QString mode);//變換各種背景
    void gameInit(); // Start the game page
    //void hitMove();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void initCountDownItems();
    void removeCountDownItems();
    void initScoreItems();
    void removeScoreItems();
    void displayFinalScore(int final_score);
    void moveAllHit();
    void displatAward(int final_score);
    void removeAwardItems();
    //void meshHit();
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
    int time_count;
    HitR *hit_r;
    HitB *hit_b;
    int hit_num;
    int order[100];
    int hit_count;
    QList<Hit *> list;
    Other *drum_r_r;
    Other *drum_r_l;
    Other *drum_b_r;
    Other *drum_b_l;
    Other *judge;
    int judge_w;
    int judge_h;
    QList<QGraphicsItem *> hit_list;
    int score_count;
    bool fullcombo_check;
    Other *head_fullcombo;

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

    //For number
    Other *head_timeRemain;
    Other *head_score;
    Num *num_00;
    Num *num_10;
    Num *num_20;
    Num *num_30;
    Num *num_0;
    Num *num_1;
    Num *num_2;
    Num *num_3;
    Num *num_4;
    Num *num_5;
    Num *num_6;
    Num *num_7;
    Num *num_8;
    Num *num_9;

    Num *num_00s;
    Num *num_10s;
    Num *num_20s;
    Num *num_30s;
    Num *num_0s;
    Num *num_1s;
    Num *num_2s;
    Num *num_3s;
    Num *num_4s;
    Num *num_5s;
    Num *num_6s;
    Num *num_7s;
    Num *num_8s;
    Num *num_9s;

    //For award
    Other *award_A;
    Other *award_B;
    Other *award_C;
    Other *award_D;
    Other *award_F;
    Other *award_S;
    Other *award_SS;


    // For sound
    QSound *bgm;
    QSound *click;
    QSound *meow;
    QSound *drum_head;
    QSound *drum_rim;

    // For timer
    QTimer *run;
    QTimer *check;
    QTimer *countDown;
    QTimer *hitAppear;
    QTimer *hitCheck;
    QTimer *score_check;


    /* Use to control the scene page */
    QString screenMode;

    // For scene boundary
    int hitBound;
    int upperBound;
    int lowerBound;
    int leftBound;
    int rightBound;
public slots:
    void takeHitAway();
    void displayCountDown();
    void displayHitAppear();
    void displayScore();
};

#endif // SCENE_H
