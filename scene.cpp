#include "scene.h"

Scene::Scene(QObject *parent)
{
    screenMode = "start";
}
void Scene::Init(int x_start)
{
    bgChange("start");
    //bgm = new QSound("../qt_picture_test/sound/bgm.wav");
    //bgm->play();
    click = new QSound(":sound/sound/click.wav");
    meow = new QSound(":sound/sound/meow.wav");
    drum_head = new QSound(":sound/sound/drum_head.wav");
    drum_rim = new QSound(":sound/sound/drum_rim.wav");
    //  setting the boundary , only lowerBound has a little different
    leftBound = x_start;
    rightBound = x_start+370;
    upperBound = 50;
    hitBound = x_start+120;
}
void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(screenMode == "start")
    {
        // Beginning page
        if((event->scenePos().x() >= btn_start->pos().x() && event->scenePos().x() <= btn_start->pos().x()+btn_w) && (event->scenePos().y() >= btn_start->pos().y() && event->scenePos().y() <= btn_start->pos().y()+btn_h))
        {
            //cout<< "Start Game"<< endl;
            //bgm->stop();
            click->play();
            removeItem(btn_start);
            removeItem(btn_exit);
            removeItem(btn_face);
            bgChange("play");
            // Goto setting the game initial
            screenMode = "play";
            gameInit();
        }
        // or click on exit
        else if((event->scenePos().x() >= btn_exit->pos().x() && event->scenePos().x() <= btn_exit->pos().x()+btn_w) && (event->scenePos().y() >= btn_exit->pos().y() && event->scenePos().y() <= btn_exit->pos().y()+btn_h))
        {
            //cout<< "exit"<< endl;
            //bgm->stop();
            click->play();
            bgChange("exit");
            screenMode = "exit"; // mode to exit
        }
        //or click on face
        else if((event->scenePos().x() >= btn_face->pos().x() && event->scenePos().x() <= btn_face->pos().x()+btn_face_w) && (event->scenePos().y() >= btn_face->pos().y() && event->scenePos().y() <= btn_face->pos().y()+btn_face_h))
        {
            //cout<<"face"<<endl;
            if(face_check == true)
            {
                addItem(btn_face);
                face_check = false;
            }
            else
            {
                this->removeItem(btn_face);
                face_check = true;
            }
            face_count++;
            //cout<<face_count<<endl;
            if(face_count > 10)
            {
                meow->play();
                screenMode = "bonus_start";
                cout<<"bonus_start"<<endl;
            }
        }
    }
    else if(screenMode == "exit")
    {
        if((event->scenePos().x() >= btn_no->pos().x() && event->scenePos().x() <= btn_no->pos().x()+btn_yes_w) && (event->scenePos().y() >= btn_no->pos().y() && event->scenePos().y() <= btn_no->pos().y()+btn_yes_h))
        {
            //cout<< "no exit"<< endl;
            click->play();
            screenMode = "start";
            //cout<<screenMode<<endl;
            bgChange("restart_from_exit");
        }
        if((event->scenePos().x() >= btn_yes->pos().x() && event->scenePos().x() <= btn_yes->pos().x()+btn_yes_w) && (event->scenePos().y() >= btn_yes->pos().y() && event->scenePos().y() <= btn_yes->pos().y()+btn_yes_h))
        {
            //cout<< "confirm exit"<< endl;
            click->play();
            //wait
            QTime t;
            t.start();
            while(t.elapsed()<500)//等待0.5秒
                QCoreApplication::processEvents();
            QApplication::quit();
        }
    }
    else if(screenMode == "play")
    {
        // Starting Page
        if(event->scenePos().x() > btn_pause->pos().x() && event->scenePos().x() <= btn_pause->pos().x()+btn_pause_w && event->scenePos().y() > btn_pause->pos().y() && event->scenePos().y() <= btn_pause->pos().y()+btn_pause_h)
        {
            click->play();
            pause_count++;
            if(pause_count > 1)
            {

                screenMode = "pause";
                bgChange("pause");

            }

        }
    }
    else if(screenMode == "pause")
    {
        if(event->scenePos().x() >= btn_back->pos().x() && event->scenePos().x() <= btn_back->pos().x()+btn_conti_w && event->scenePos().y() >= btn_back->pos().y() && event->scenePos().y() <= btn_back->pos().y()+btn_conti_h)
        {
            click->play();
            removeAllNumItems();
            bgChange("restart_from_pause");
            screenMode = "start";
        }
        else if(event->scenePos().x() >= btn_conti->pos().x() && event->scenePos().x() <= btn_conti->pos().x()+btn_conti_w && event->scenePos().y() >= btn_conti->pos().y() && event->scenePos().y() <= btn_conti->pos().y()+btn_conti_h)
        {
            click->play();
            countDown->stop();
        }
        if(event->scenePos().x() >= btn_retry->pos().x() && event->scenePos().x() <= btn_retry->pos().x()+btn_conti_w && event->scenePos().y() >= btn_retry->pos().y() && event->scenePos().y() <= btn_retry->pos().y()+btn_conti_h)
        {
            click->play();
            foreach (Hit *i , list)
            {
                this->removeItem(i);
                list.removeOne(i);
            }
            removeItem(btn_back);
            removeItem(btn_conti);
            removeItem(btn_retry);
            removeAllNumItems();
            bgChange("play");
            screenMode = "play";
            gameInit();
        }
    }
}
void Scene::keyPressEvent(QKeyEvent *event)
{
    if(screenMode == "play")
    {
        if(event->key() == Qt::Key_J || event->key() == Qt::Key_F)
        {
            QList<QGraphicsItem *> hit_list = this->collidingItems(judge);
            foreach (QGraphicsItem *i, hit_list)
            {
                HitR *item = dynamic_cast<HitR *>(i);
                this->removeItem(item);
                list.removeOne(item);
                delete item;
            }
            drum_head->play();
            if(event->key() == Qt::Key_J)
        {
            addItem(drum_r_r);
            QTime t;
            t.start();
            while(t.elapsed()<100)//等待0.1秒
                QCoreApplication::processEvents();
            removeItem(drum_r_r);
        }
            if(event->key() == Qt::Key_F)
        {
            addItem(drum_r_l);
            QTime t;
            t.start();
            while(t.elapsed()<100)//等待0.1秒
                QCoreApplication::processEvents();
            removeItem(drum_r_l);
        }
        }
        else if(event->key() == Qt::Key_K || event->key() == Qt::Key_D)
        {
            QList<QGraphicsItem *> hit_list = this->collidingItems(judge);
            foreach (QGraphicsItem *i, hit_list)
            {
                HitB *item = dynamic_cast<HitB *>(i);
                this->removeItem(item);
                list.removeOne(item);
                delete item;
            }
            drum_rim->play();
            if(event->key() == Qt::Key_K)
            {
                addItem(drum_b_r);
                QTime t;
                t.start();
                while(t.elapsed()<100)//等待0.1秒
                    QCoreApplication::processEvents();
                removeItem(drum_b_r);
            }
            if(event->key() == Qt::Key_D)
            {
                addItem(drum_b_l);
                QTime t;
                t.start();
                while(t.elapsed()<100)//等待0.1秒
                    QCoreApplication::processEvents();
                removeItem(drum_b_l);
            }
        }
        else if(event->key() == Qt::Key_Escape)
        {
            click->play();
            pause_count++;
            if(pause_count > 1)
            {
                screenMode = "pause";
                bgChange("pause");
            }
        }
    }
}

void Scene::bgChange(QString mode)
{
    if(mode == "start")
    {
        QImage bg;
        bg.load(":image/img/bg_start.png");
        //bg = bg.scaled(870,550);
        setBackgroundBrush(bg);
        // start
        btn_start = new Btn();
        QPixmap start;
        start.load(":image/img/btn_start.png");
        //start = start.scaled(start.width(),start.height(),Qt::KeepAspectRatio);
        btn_w = start.width();
        btn_h = start.height();
        btn_start->setPixmap(start);
        btn_start->setPos(680,310);
        addItem(btn_start);
        // exit
        btn_exit = new Btn();
        QPixmap exit;
        exit.load(":image/img/btn_exit.png");
        exit = exit.scaled(exit.width(),exit.height(),Qt::KeepAspectRatio);
        btn_exit->setPixmap(exit);
        btn_exit->setPos(680,390);
        addItem(btn_exit);
        // face
        btn_face = new Btn();
        QPixmap face;
        face.load(":image/img/btn_face.png");
        face = face.scaled(face.width(),face.height(),Qt::KeepAspectRatio);
        btn_face_w = face.width();
        btn_face_h = face.height();
        btn_face->setPixmap(face);
        btn_face->setPos(312,103);
        addItem(btn_face);
        face_count = 0;
        //pause_count = 0;
        face_check = false;
    }
    else if(mode == "restart_from_exit")
    {
        removeItem(btn_yes);
        removeItem(btn_no);
        bgChange("start");
    }
    else if(mode == "restart_from_pause")
    {
        removeItem(btn_back);
        removeItem(btn_conti);
        removeItem(btn_retry);

        foreach (Hit *i , list)
        {
            this->removeItem(i);
            list.removeOne(i);
        }
        bgChange("start");
    }
    else if(mode == "play")
    {
        if(time_count == 0)
        {
            run->stop();
            countDown->stop();
            hitAppear->stop();
        }

        QImage bg;
        bg.load(":image/img/bg_play.png");
        //bg = bg.scaled(870,537);
        this->setBackgroundBrush(bg);

        btn_pause = new Btn();
        QPixmap pause;
        pause.load(":image/img/btn_pause.png");
        pause = pause.scaled(pause.width()*1/7,pause.height()*1/7,Qt::KeepAspectRatio);
        btn_pause_w = pause.width();
        btn_pause_h = pause.height();
        btn_pause->setPixmap(pause);
        btn_pause->setPos(20,470);
        addItem(btn_pause);
        pause_count = 0;

        drum_r_r = new Other();
        QPixmap drr;
        drr.load(":image/img/drum_red_right.png");
        drum_r_r->setPixmap(drr);
        drum_r_r->setPos(70,145);
        drum_r_l = new Other();
        QPixmap drl;
        drl.load(":image/img/drum_red_left.png");
        drum_r_l->setPixmap(drl);
        drum_r_l->setPos(30,145);
        drum_b_r = new Other();
        QPixmap dbr;
        dbr.load(":image/img/drum_blue_right.png");
        drum_b_r->setPixmap(dbr);
        drum_b_r->setPos(70,130);
        drum_b_l = new Other();
        QPixmap dbl;
        dbl.load(":image/img/drum_blue_left.png");
        drum_b_l->setPixmap(dbl);
        drum_b_l->setPos(17,130);
        judge = new Other();
        QPixmap jud;
        jud.load(":image/img/judge.png");
        judge_w = jud.width();
        judge_h = jud.height();
        judge->setPixmap(jud);
        judge->setPos(180,138);
        addItem(judge);

        initAllNumItems();
        head_timeRemain = new Other();
        QPixmap h_t;
        h_t.load(":image/img/head_timeRemain.png");
        head_timeRemain->setPixmap(h_t);
        head_timeRemain->setPos(40,39);
        addItem(head_timeRemain);
    }
    else if(mode == "exit")
    {
        QImage bg;
        bg.load(":image/img/bg_exit.png");
        //bg = bg.scaled(870,550);
        this->setBackgroundBrush(bg);
        /* second , remove btn - start and change ball */
        this->removeItem(btn_start);
        this->removeItem(btn_exit);
        this->removeItem(btn_face);

        btn_yes = new Btn();
        QPixmap yes;
        yes.load(":image/img/btn_yes.png");
        yes = yes.scaled(yes.width(),yes.height(),Qt::KeepAspectRatio);
        btn_yes_w = yes.width();
        btn_yes_h = yes.height();
        btn_yes->setPixmap(yes);
        btn_yes->setPos(320,260);
        addItem(btn_yes);
        btn_no = new Btn();
        QPixmap no;
        no.load(":image/img/btn_no.png");
        no = no.scaled(no.width(),no.height(),Qt::KeepAspectRatio);
        btn_no->setPixmap(no);
        btn_no->setPos(480,260);
        addItem(btn_no);
    }
    else if(mode == "pause")
    {
        countDown->stop();//暫停倒數
        run->stop();
        hitAppear->stop();

        removeItem(judge);
        removeItem(btn_pause);
        QImage bg;
        bg.load(":image/img/bg_pause.png");
        //bg = bg.scaled(870,550);
        this->setBackgroundBrush(bg);
        //continue
        btn_conti = new Btn();
        QPixmap conti;
        conti.load(":image/img/btn_conti.png");
        conti = conti.scaled(conti.width(),conti.height(),Qt::KeepAspectRatio);
        btn_conti_w = conti.width();
        btn_conti_h = conti.height();
        btn_conti->setPixmap(conti);
        btn_conti->setPos(280,280);
        addItem(btn_conti);
        //retry
        btn_retry = new Btn();
        QPixmap retry;
        retry.load(":image/img/btn_retry.png");
        retry = retry.scaled(retry.width(),retry.height(),Qt::KeepAspectRatio);
        btn_retry->setPixmap(retry);
        btn_retry->setPos(390,280);
        addItem(btn_retry);
        //back
        btn_back = new Btn();
        QPixmap back;
        back.load(":image/img/btn_back.png");
        back = back.scaled(back.width(),back.height(),Qt::KeepAspectRatio);
        btn_back->setPixmap(back);
        btn_back->setPos(500,280);
        addItem(btn_back);
    }
}

void Scene::gameInit()
{
    qsrand(time(NULL));//產生隨機鼓面
    for(int i=0;i<100;i++)
    {
        order[i]=qrand()%5;
    }
    time_count = 30;
    hit_count = 0;
    lowerBound = 450+50; // 50 is the bias (every picture's have it's original boundary)
    // Set up timer to control each item
    run = new QTimer(this);
    connect(run , SIGNAL(timeout()) , this , SLOT(advance()));
    run->start(1);
    check = new QTimer(this);
    connect(check , SIGNAL(timeout()) , this , SLOT(takeHitAway()));
    check->start(1);//每0.001秒觸發一次，越小越流暢
    countDown = new QTimer(this);
    connect(countDown , SIGNAL(timeout()) , this , SLOT(displayCountDown()));
    countDown->start(1000);
    hitAppear = new QTimer(this);
    connect(hitAppear , SIGNAL(timeout()) , this , SLOT(displayHitAppear()));
    hitAppear->start(1000);
}

void Scene::takeHitAway()
{
    foreach(Hit *i , list)
    {
        if(i->pos().x() <= hitBound)
        {
            removeItem(i);
            list.removeOne(i);
            delete i;
        }
    }
}

void Scene::displayCountDown()
{
    switch (time_count/10) {//十位數
    case 0:
        removeItem(num_10);
        num_00->setPos(185,40);
        addItem(num_00);
        break;
    case 1:
        removeItem(num_20);
        num_10->setPos(185,40);
        addItem(num_10);
        break;
    case 2:
        removeItem(num_30);
        num_20->setPos(185,40);
        addItem(num_20);
        break;
    case 3:
        num_30->setPos(185,40);
        addItem(num_30);
        break;
    default:
        break;
    }
    switch (time_count%10) {//個位數
    case 0:
        removeItem(num_1);
        num_0->setPos(205,40);
        addItem(num_0);
        break;
    case 1:
        removeItem(num_2);
        num_1->setPos(205,40);
        addItem(num_1);
        break;
    case 2:
        removeItem(num_3);
        num_2->setPos(205,40);
        addItem(num_2);
        break;
    case 3:
        removeItem(num_4);
        num_3->setPos(205,40);
        addItem(num_3);
        break;
    case 4:
        removeItem(num_5);
        num_4->setPos(205,40);
        addItem(num_4);
        break;
    case 5:
        removeItem(num_6);
        num_5->setPos(205,40);
        addItem(num_5);
        break;
    case 6:
        removeItem(num_7);
        num_6->setPos(205,40);
        addItem(num_6);
        break;
    case 7:
        removeItem(num_8);
        num_7->setPos(205,40);
        addItem(num_7);
        break;
    case 8:
        removeItem(num_9);
        num_8->setPos(205,40);
        addItem(num_8);
        break;
    case 9:
        removeItem(num_0);
        num_9->setPos(205,40);
        addItem(num_9);
        break;
    default:
        break;
    }
    time_count--;
    //cout<<time_count<<" ";
    if(time_count < 0)
    {
        run->stop();
        countDown->stop();
        hitAppear->stop();
        //bgChange("score");
        //screenMode = "score";
    }
}

void Scene::displayHitAppear()
{
    if(order[hit_count] == 0)
    {
        //not creat hit
    }
    else if(order[hit_count]%2 == 1)
    {
        hit_r = new HitR();
        QPixmap H_r;
        H_r.load(":image/img/hit_r.png");
        hit_r->setPixmap(H_r);
        hit_r->setPos(770,153);
        addItem(hit_r);
        list.push_back(hit_r);
    }
    else if(order[hit_count]%2 == 0)
    {
        hit_b = new HitB();
        QPixmap H_b;
        H_b.load(":image/img/hit_b.png");
        hit_b->setPixmap(H_b);
        hit_b->setPos(770,153);
        addItem(hit_b);
        list.push_back(hit_b);
    }
    hit_count++;
}

void Scene::initAllNumItems()
{
    num_0 = new Num();
    QPixmap n_0;
    n_0.load(":image/img/num_0.png");
    num_0->setPixmap(n_0);
    num_1 = new Num();
    QPixmap n_1;
    n_1.load(":image/img/num_1.png");
    num_1->setPixmap(n_1);
    num_2 = new Num();
    QPixmap n_2;
    n_2.load(":image/img/num_2.png");
    num_2->setPixmap(n_2);
    num_3 = new Num();
    QPixmap n_3;
    n_3.load(":image/img/num_3.png");
    num_3->setPixmap(n_3);
    num_4 = new Num();
    QPixmap n_4;
    n_4.load(":image/img/num_4.png");
    num_4->setPixmap(n_4);
    num_5 = new Num();
    QPixmap n_5;
    n_5.load(":image/img/num_5.png");
    num_5->setPixmap(n_5);
    num_6 = new Num();
    QPixmap n_6;
    n_6.load(":image/img/num_6.png");
    num_6->setPixmap(n_6);
    num_7 = new Num();
    QPixmap n_7;
    n_7.load(":image/img/num_7.png");
    num_7->setPixmap(n_7);
    num_8 = new Num();
    QPixmap n_8;
    n_8.load(":image/img/num_8.png");
    num_8->setPixmap(n_8);
    num_9 = new Num();
    QPixmap n_9;
    n_9.load(":image/img/num_9.png");
    num_9->setPixmap(n_9);
    num_00 = new Num();
    num_00->setPixmap(n_0);
    num_10 = new Num();
    num_10->setPixmap(n_1);
    num_20 = new Num();
    num_20->setPixmap(n_2);
    num_30 = new Num();
    num_30->setPixmap(n_3);
}

void Scene::removeAllNumItems()
{
    removeItem(head_timeRemain);
    removeItem(num_0);
    removeItem(num_1);
    removeItem(num_2);
    removeItem(num_3);
    removeItem(num_4);
    removeItem(num_5);
    removeItem(num_6);
    removeItem(num_7);
    removeItem(num_8);
    removeItem(num_9);
    removeItem(num_00);
    removeItem(num_10);
    removeItem(num_20);
    removeItem(num_30);
}

