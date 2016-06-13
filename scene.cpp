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

    hitBound = x_start+120;//hit消失的邊界
    sound_checkD = true;
    sound_checkC = true;
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
            if(sound_checkC)
            {
                click->play();
            }
            removeItem(btn_start);
            removeItem(btn_exit);
            removeItem(btn_face);
            removeItem(btn_teach);
            removeItem(btn_setting);
            delete btn_start;
            delete btn_exit;
            delete btn_face;
            delete btn_teach;
            delete btn_setting;

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
            if(sound_checkC)
            {
                click->play();
            }
            bgChange("exit");
            screenMode = "exit"; // mode to exit
        }
        else if((event->scenePos().x() >= btn_teach->pos().x() && event->scenePos().x() <= btn_teach->pos().x()+btn_w) && (event->scenePos().y() >= btn_teach->pos().y() && event->scenePos().y() <= btn_teach->pos().y()+btn_h))
        {
            if(sound_checkC)
            {
                click->play();
            }
            bgChange("teach");
            screenMode = "teach";
        }
        else if((event->scenePos().x() >= btn_setting->pos().x() && event->scenePos().x() <= btn_setting->pos().x()+btn_w) && (event->scenePos().y() >= btn_setting->pos().y() && event->scenePos().y() <= btn_setting->pos().y()+btn_h))
        {
            if(sound_checkC)
            {
                click->play();
            }
            bgChange("setting");
            screenMode = "setting";
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
                //screenMode = "bonus_start";
                //cout<<"bonus_start"<<endl;
            }
        }
    }
    else if(screenMode == "teach")
    {
        if(event->scenePos().x() >= btn_back->pos().x() && event->scenePos().x() <= btn_back->pos().x()+btn_conti_w && event->scenePos().y() >= btn_back->pos().y() && event->scenePos().y() <= btn_back->pos().y()+btn_conti_h)
        {
            if(sound_checkC)
            {
                click->play();
            }
            removeItem(btn_back);
            delete btn_back;
            bgChange("start");
            screenMode = "start";
        }
    }
    else if(screenMode == "setting")
    {
        if(event->scenePos().x() >= btn_back->pos().x() && event->scenePos().x() <= btn_back->pos().x()+btn_conti_w && event->scenePos().y() >= btn_back->pos().y() && event->scenePos().y() <= btn_back->pos().y()+btn_conti_h)
        {
            if(sound_checkC)
            {
                click->play();
            }
            removeItem(btn_back);
            removeItem(btn_open);
            removeItem(btn_close);
            removeItem(btn_openC);
            removeItem(btn_closeC);
            removeItem(sound_setD);
            removeItem(sound_setC);
            delete btn_back;
            delete btn_open;
            delete btn_close;
            delete btn_openC;
            delete btn_closeC;
            delete sound_setD;
            delete sound_setC;
            bgChange("start");
            screenMode = "start";
        }
        //設定擊鼓聲
        else if(event->scenePos().x() >= btn_open->pos().x() && event->scenePos().x() <= btn_open->pos().x()+btn_conti_w && event->scenePos().y() >= btn_open->pos().y() && event->scenePos().y() <= btn_open->pos().y()+btn_conti_h)
        {//開
            if(sound_checkC)
            {
                click->play();
            }
            sound_checkD = true;
            removeItem(sound_setD);
            sound_setD->setPos(430,230);
            addItem(sound_setD);
        }
        else if(event->scenePos().x() >= btn_close->pos().x() && event->scenePos().x() <= btn_close->pos().x()+btn_conti_w && event->scenePos().y() >= btn_close->pos().y() && event->scenePos().y() <= btn_close->pos().y()+btn_conti_h)
        {//關
            if(sound_checkC)
            {
                click->play();
            }
            sound_checkD = false;
            removeItem(sound_setD);
            sound_setD->setPos(530,230);
            addItem(sound_setD);
        }
        //設定點擊聲
        else if(event->scenePos().x() >= btn_openC->pos().x() && event->scenePos().x() <= btn_openC->pos().x()+btn_conti_w && event->scenePos().y() >= btn_openC->pos().y() && event->scenePos().y() <= btn_openC->pos().y()+btn_conti_h)
        {//開
            if(sound_checkC)
            {
                click->play();
            }
            sound_checkC = true;
            removeItem(sound_setC);
            sound_setC->setPos(430,130);
            addItem(sound_setC);
        }
        else if(event->scenePos().x() >= btn_closeC->pos().x() && event->scenePos().x() <= btn_closeC->pos().x()+btn_conti_w && event->scenePos().y() >= btn_closeC->pos().y() && event->scenePos().y() <= btn_closeC->pos().y()+btn_conti_h)
        {//關
            if(sound_checkC)
            {
                click->play();
            }
            sound_checkC = false;
            removeItem(sound_setC);
            sound_setC->setPos(530,130);
            addItem(sound_setC);
        }

    }
    else if(screenMode == "exit")
    {
        if((event->scenePos().x() >= btn_no->pos().x() && event->scenePos().x() <= btn_no->pos().x()+btn_yes_w) && (event->scenePos().y() >= btn_no->pos().y() && event->scenePos().y() <= btn_no->pos().y()+btn_yes_h))
        {
            //cout<< "no exit"<< endl;
            if(sound_checkC)
            {
                click->play();
            }
            screenMode = "start";
            bgChange("restart_from_exit");
        }
        else if((event->scenePos().x() >= btn_yes->pos().x() && event->scenePos().x() <= btn_yes->pos().x()+btn_yes_w) && (event->scenePos().y() >= btn_yes->pos().y() && event->scenePos().y() <= btn_yes->pos().y()+btn_yes_h))
        {
            //cout<< "confirm exit"<< endl;
            if(sound_checkC)
            {
                click->play();
            }
            //wait
            QTime t;
            t.start();
            while(t.elapsed()<300)//等待0.3秒
                QCoreApplication::processEvents();
            removeItem(btn_yes);
            removeItem(btn_no);
            delete btn_yes;
            delete btn_no;
            QImage bg;
            bg.load(":image/img/bg_exit88.png");
            setBackgroundBrush(bg);
            QTime tt;
            tt.start();
            while(tt.elapsed()<700)//等待0.7秒
                QCoreApplication::processEvents();
            QApplication::quit();
        }
    }
    else if(screenMode == "play")
    {
        // Starting Page
        if(event->scenePos().x() > btn_pause->pos().x() && event->scenePos().x() <= btn_pause->pos().x()+btn_pause_w && event->scenePos().y() > btn_pause->pos().y() && event->scenePos().y() <= btn_pause->pos().y()+btn_pause_h)
        {
            if(sound_checkC)
            {
                click->play();
            }
            pause_count++;
            if(pause_count > 1)
            {
                screenMode = "pause";
                bgChange("pause");
            }
        }
    }
    else if(screenMode == "pause" )
    {
        if(event->scenePos().x() >= btn_back->pos().x() && event->scenePos().x() <= btn_back->pos().x()+btn_conti_w && event->scenePos().y() >= btn_back->pos().y() && event->scenePos().y() <= btn_back->pos().y()+btn_conti_h)
        {
            if(sound_checkC)
            {
                click->play();
            }
            removeCountDownItems();
            removeScoreItems();
            bgChange("restart_from_pause");
            screenMode = "start";
        }
        /*else if(event->scenePos().x() >= btn_conti->pos().x() && event->scenePos().x() <= btn_conti->pos().x()+btn_conti_w && event->scenePos().y() >= btn_conti->pos().y() && event->scenePos().y() <= btn_conti->pos().y()+btn_conti_h)
        {
            click->play();
            countDown->stop();
        }*/
        else if(event->scenePos().x() >= btn_retry->pos().x() && event->scenePos().x() <= btn_retry->pos().x()+btn_conti_w && event->scenePos().y() >= btn_retry->pos().y() && event->scenePos().y() <= btn_retry->pos().y()+btn_conti_h)
        {
            if(sound_checkC)
            {
                click->play();
            }
            foreach (Hit *i , list)
            {
                this->removeItem(i);
                list.removeOne(i);
                delete i;
            }
            removeItem(btn_back);
            //removeItem(btn_conti);
            removeItem(btn_retry);
            delete btn_back;
            //delete btn_conti;
            delete btn_retry;
            removeCountDownItems();
            removeScoreItems();
            bgChange("play");
            screenMode = "play";
            gameInit();
        }
    }
    else if(screenMode == "score")
    {
        if(event->scenePos().x() >= btn_back->pos().x() && event->scenePos().x() <= btn_back->pos().x()+btn_conti_w && event->scenePos().y() >= btn_back->pos().y() && event->scenePos().y() <= btn_back->pos().y()+btn_conti_h)
        {
            if(sound_checkC)
            {
                click->play();
            }
            removeScoreItems();
            removeAwardItems();
            removeItem(head_fullcombo);
            delete head_fullcombo;
            bgChange("restart_from_pause");
            screenMode = "start";
        }
        /*else if(event->scenePos().x() >= btn_conti->pos().x() && event->scenePos().x() <= btn_conti->pos().x()+btn_conti_w && event->scenePos().y() >= btn_conti->pos().y() && event->scenePos().y() <= btn_conti->pos().y()+btn_conti_h)
        {
            click->play();
        }*/
        else if(event->scenePos().x() >= btn_retry->pos().x() && event->scenePos().x() <= btn_retry->pos().x()+btn_conti_w && event->scenePos().y() >= btn_retry->pos().y() && event->scenePos().y() <= btn_retry->pos().y()+btn_conti_h)
        {
            if(sound_checkC)
            {
                click->play();
            }
            foreach (Hit *i , list)
            {
                this->removeItem(i);
                list.removeOne(i);
                delete i;
            }
            removeItem(btn_back);
            //removeItem(btn_conti);
            removeItem(btn_retry);
            removeItem(head_fullcombo);
            delete btn_back;
            //delete btn_conti;
            delete btn_retry;
            delete head_fullcombo;
            removeScoreItems();
            removeAwardItems();
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
                hit_num++;//計算hit總數
                score_count++;
            }
            if(sound_checkD)
            {
                drum_head->play();
            }
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
                hit_num++;//計算hit總數
                score_count++;
            }
            if(sound_checkD)
            {
                drum_rim->play();
            }
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
        setBackgroundBrush(bg);
        // start
        btn_start = new Btn();
        QPixmap start;
        start.load(":image/img/btn_start.png");
        btn_w = start.width();
        btn_h = start.height();
        btn_start->setPixmap(start);
        btn_start->setPos(680,310);
        addItem(btn_start);
        // exit
        btn_exit = new Btn();
        QPixmap exit;
        exit.load(":image/img/btn_exit.png");
        btn_exit->setPixmap(exit);
        btn_exit->setPos(680,390);
        addItem(btn_exit);
        // face
        btn_face = new Btn();
        QPixmap face;
        face.load(":image/img/btn_face.png");
        btn_face_w = face.width();
        btn_face_h = face.height();
        btn_face->setPixmap(face);
        btn_face->setPos(312,103);
        addItem(btn_face);
        face_count = 0;
        face_check = false;
        //teach
        btn_teach = new Btn();
        QPixmap teach;
        teach.load(":image/img/btn_teach.png");
        btn_teach->setPixmap(teach);
        btn_teach->setPos(40,310);
        addItem(btn_teach);
        btn_setting = new Btn();
        QPixmap setting;
        setting.load(":image/img/btn_setting.png");
        btn_setting->setPixmap(setting);
        btn_setting->setPos(40,390);
        addItem(btn_setting);
    }
    else if(mode == "restart_from_exit")
    {
        removeItem(btn_yes);        
        removeItem(btn_no);
        delete btn_yes;
        delete btn_no;
        bgChange("start");
    }
    else if(mode == "restart_from_pause")
    {
        removeItem(btn_back);
        //removeItem(btn_conti);
        removeItem(btn_retry);
        delete btn_back;
        //delete btn_conti;
        delete btn_retry;
        foreach (Hit *i , list)
        {
            this->removeItem(i);
            list.removeOne(i);
            delete i;
        }
        bgChange("start");
    }
    else if(mode == "teach")
    {
        removeItem(btn_face);
        removeItem(btn_start);
        removeItem(btn_exit);
        removeItem(btn_teach);
        removeItem(btn_setting);
        delete btn_start;
        delete btn_exit;
        delete btn_face;
        delete btn_teach;
        delete btn_setting;

        QImage bg;
        bg.load(":image/img/bg_teach.png");
        this->setBackgroundBrush(bg);
        btn_back = new Btn();
        QPixmap back;
        back.load(":image/img/btn_back.png");
        btn_conti_w = back.width();
        btn_conti_h = back.height();
        btn_back->setPixmap(back);
        btn_back->setPos(630,380);
        addItem(btn_back);
    }
    else if(mode == "setting")
    {
        removeItem(btn_face);
        removeItem(btn_start);
        removeItem(btn_exit);
        removeItem(btn_teach);
        removeItem(btn_setting);
        delete btn_start;
        delete btn_exit;
        delete btn_face;
        delete btn_teach;
        delete btn_setting;

        QImage bg;
        bg.load(":image/img/bg_setting.png");
        this->setBackgroundBrush(bg);
        btn_back = new Btn();
        QPixmap back;
        back.load(":image/img/btn_back.png");
        btn_conti_w = back.width();
        btn_conti_h = back.height();
        btn_back->setPixmap(back);
        btn_back->setPos(630,380);
        addItem(btn_back);
        btn_open = new Btn();
        QPixmap open;
        open.load(":image/img/btn_open.png");
        btn_open->setPixmap(open);
        btn_open->setPos(430,230);
        addItem(btn_open);
        btn_close = new Btn();
        QPixmap close;
        close.load(":image/img/btn_close.png");
        btn_close->setPixmap(close);
        btn_close->setPos(530,230);
        addItem(btn_close);
        sound_setD = new Other();
        QPixmap s_setD;
        s_setD.load(":image/img/sound_setting.png");
        sound_setD->setPixmap(s_setD);
        if(sound_checkD)
        {
            sound_setD->setPos(430,230);
        }
        else
        {
            sound_setD->setPos(530,230);
        }
        addItem(sound_setD);

        btn_openC = new Btn();
        QPixmap openC;
        openC.load(":image/img/btn_open.png");
        btn_openC->setPixmap(openC);
        btn_openC->setPos(430,130);
        addItem(btn_openC);
        btn_closeC = new Btn();
        QPixmap closeC;
        closeC.load(":image/img/btn_close.png");
        btn_closeC->setPixmap(closeC);
        btn_closeC->setPos(530,130);
        addItem(btn_closeC);
        sound_setC = new Other();
        QPixmap s_setC;
        s_setC.load(":image/img/sound_setting.png");
        sound_setC->setPixmap(s_setC);
        if(sound_checkC)
        {
            sound_setC->setPos(430,130);
        }
        else
        {
            sound_setC->setPos(530,130);
        }
        addItem(sound_setC);
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
        judge->setPixmap(jud);
        judge->setPos(180,138);
        addItem(judge);

        initCountDownItems();
        initScoreItems();

        head_timeRemain = new Other();
        QPixmap h_t;
        h_t.load(":image/img/head_timeRemain.png");
        head_timeRemain->setPixmap(h_t);
        head_timeRemain->setPos(40,39);
        addItem(head_timeRemain);

        head_score = new Other();
        QPixmap h_s;
        h_s.load(":image/img/head_score.png");
        head_score->setPixmap(h_s);
        head_score->setPos(640,39);
        addItem(head_score);
    }
    else if(mode == "exit")
    {
        QImage bg;
        bg.load(":image/img/bg_exit.png");
        this->setBackgroundBrush(bg);

        removeItem(btn_start);
        removeItem(btn_exit);
        removeItem(btn_face);
        removeItem(btn_teach);
        removeItem(btn_setting);
        delete btn_start;
        delete btn_exit;
        delete btn_face;
        delete btn_teach;
        delete btn_setting;
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
        scoreCheck->stop();
        hitCheck->stop();

        removeItem(judge);
        removeItem(btn_pause);
        delete judge;
        delete btn_pause;
        QImage bg;
        bg.load(":image/img/bg_pause.png");
        this->setBackgroundBrush(bg);
        //retry
        btn_retry = new Btn();
        QPixmap retry;
        retry.load(":image/img/btn_retry.png");
        btn_conti_w = retry.width();
        btn_conti_h = retry.height();
        btn_retry->setPixmap(retry);
        btn_retry->setPos(280,360);
        addItem(btn_retry);
        //continue
        /*btn_conti = new Btn();
        QPixmap conti;
        conti.load(":image/img/btn_conti.png");
        btn_conti->setPixmap(conti);
        btn_conti->setPos(390,360);*/
        //addItem(btn_conti);
        //back
        btn_back = new Btn();
        QPixmap back;
        back.load(":image/img/btn_back.png");
        btn_back->setPixmap(back);
        btn_back->setPos(500,360);
        addItem(btn_back);
    }
    else if(mode == "score")
    {
        countDown->stop();//暫停倒數
        run->stop();
        hitAppear->stop();
        scoreCheck->stop();
        hitCheck->stop();

        QImage bg;
        bg.load(":/image/img/bg_score.png");
        this->setBackgroundBrush(bg);

        removeCountDownItems();
        removeScoreItems();
        removeItem(judge);
        removeItem(btn_pause);
        delete judge;
        delete btn_pause;
        initScoreItems();
        displayFinalScore(score_count);//顯示總分

        head_fullcombo = new Other();
        QPixmap h_f;
        h_f.load(":image/img/head_fullcombo.png");
        head_fullcombo->setPixmap(h_f);
        head_fullcombo->setPos(430,130);
        if(fullcombo_check)
        {
            addItem(head_fullcombo);
        }
        foreach (Hit *i , list)
        {
            this->removeItem(i);
            list.removeOne(i);
            delete i;
        }
        displatAward(score_count);
        //retry
        btn_retry = new Btn();
        QPixmap retry;
        retry.load(":image/img/btn_retry.png");
        btn_conti_w = retry.width();
        btn_conti_h = retry.height();
        btn_retry->setPixmap(retry);
        btn_retry->setPos(280,360);
        addItem(btn_retry);
        //continue
        /*btn_conti = new Btn();
        QPixmap conti;
        conti.load(":image/img/btn_conti.png");
        btn_conti_w = conti.width();
        btn_conti_h = conti.height();
        btn_conti->setPixmap(conti);
        btn_conti->setPos(390,360);*/
        //addItem(btn_conti);
        //back
        btn_back = new Btn();
        QPixmap back;
        back.load(":image/img/btn_back.png");
        btn_back->setPixmap(back);
        btn_back->setPos(500,360);
        addItem(btn_back);
    }
}

void Scene::gameInit()
{
    hit_num = 0;
    qsrand(time(NULL));//產生隨機鼓面
    for(int i=0;i<100;i++)
    {
        order[i]=qrand()%5;
    }
    time_count = 30;
    score_count = 0;
    hit_count = 0;
    fullcombo_check = true;

    // Set up timer to control each item
    run = new QTimer(this);
    connect(run , SIGNAL(timeout()) , this , SLOT(advance()));
    run->start(1);//每0.001秒觸發一次，越小越流暢
    hitCheck = new QTimer(this);
    connect(hitCheck , SIGNAL(timeout()) , this , SLOT(takeHitAway()));
    hitCheck->start(1);
    countDown = new QTimer(this);
    connect(countDown , SIGNAL(timeout()) , this , SLOT(displayCountDown()));
    countDown->start(1000);
    hitAppear = new QTimer(this);
    connect(hitAppear , SIGNAL(timeout()) , this , SLOT(displayHitAppear()));
    hitAppear->start(1000);
    scoreCheck = new QTimer(this);
    connect(scoreCheck , SIGNAL(timeout()) , this , SLOT(displayScore()));
    scoreCheck->start(1);
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
            fullcombo_check = false;//有漏掉就不會fullcombo
            hit_num++;//計算總hit數
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
        if(num_1->isActive())
        {
            removeItem(num_1);
        }
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
        bgChange("score");
        screenMode = "score";
    }

}

void Scene::displayScore()
{
    switch (score_count/10) {//十位數
    case 0:
        //removeItem(num_10s);
        num_00s->setPos(730,40);
        addItem(num_00s);
        break;
    case 1:
        removeItem(num_00s);
        num_10s->setPos(730,40);
        addItem(num_10s);
        break;
    case 2:
        removeItem(num_10s);
        num_20s->setPos(730,40);
        addItem(num_20s);
        break;
    case 3:
        removeItem(num_20s);
        num_30s->setPos(730,40);
        addItem(num_30s);
        break;
    default:
        break;
    }
    switch (score_count%10) {//個位數
    case 0:
        if(num_9->isActive())
        {
            removeItem(num_9s);
        }
        num_0s->setPos(750,40);
        addItem(num_0s);
        break;
    case 1:
        removeItem(num_0s);
        num_1s->setPos(750,40);
        addItem(num_1s);
        break;
    case 2:
        removeItem(num_1s);
        num_2s->setPos(750,40);
        addItem(num_2s);
        break;
    case 3:
        removeItem(num_2s);
        num_3s->setPos(750,40);
        addItem(num_3s);
        break;
    case 4:
        removeItem(num_3s);
        num_4s->setPos(750,40);
        addItem(num_4s);
        break;
    case 5:
        removeItem(num_4s);
        num_5s->setPos(750,40);
        addItem(num_5s);
        break;
    case 6:
        removeItem(num_5s);
        num_6s->setPos(750,40);
        addItem(num_6s);
        break;
    case 7:
        removeItem(num_6s);
        num_7s->setPos(750,40);
        addItem(num_7s);
        break;
    case 8:
        removeItem(num_7s);
        num_8s->setPos(750,40);
        addItem(num_8s);
        break;
    case 9:
        removeItem(num_8s);
        num_9s->setPos(750,40);
        addItem(num_9s);
        break;
    default:
        break;
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

void Scene::initCountDownItems()
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

void Scene::removeCountDownItems()
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
    delete num_0;
    delete num_1;
    delete num_2;
    delete num_3;
    delete num_4;
    delete num_5;
    delete num_6;
    delete num_7;
    delete num_8;
    delete num_9;
    delete num_00;
    delete num_10;
    delete num_20;
    delete num_30;
}

void Scene::initScoreItems()
{
    num_0s = new Num();
    QPixmap n_0;
    n_0.load(":image/img/num_0.png");
    num_0s->setPixmap(n_0);
    num_1s = new Num();
    QPixmap n_1;
    n_1.load(":image/img/num_1.png");
    num_1s->setPixmap(n_1);
    num_2s = new Num();
    QPixmap n_2;
    n_2.load(":image/img/num_2.png");
    num_2s->setPixmap(n_2);
    num_3s = new Num();
    QPixmap n_3;
    n_3.load(":image/img/num_3.png");
    num_3s->setPixmap(n_3);
    num_4s = new Num();
    QPixmap n_4;
    n_4.load(":image/img/num_4.png");
    num_4s->setPixmap(n_4);
    num_5s = new Num();
    QPixmap n_5;
    n_5.load(":image/img/num_5.png");
    num_5s->setPixmap(n_5);
    num_6s = new Num();
    QPixmap n_6;
    n_6.load(":image/img/num_6.png");
    num_6s->setPixmap(n_6);
    num_7s = new Num();
    QPixmap n_7;
    n_7.load(":image/img/num_7.png");
    num_7s->setPixmap(n_7);
    num_8s = new Num();
    QPixmap n_8;
    n_8.load(":image/img/num_8.png");
    num_8s->setPixmap(n_8);
    num_9s = new Num();
    QPixmap n_9;
    n_9.load(":image/img/num_9.png");
    num_9s->setPixmap(n_9);
    num_00s = new Num();
    num_00s->setPixmap(n_0);
    num_10s = new Num();
    num_10s->setPixmap(n_1);
    num_20s = new Num();
    num_20s->setPixmap(n_2);
    num_30s = new Num();
    num_30s->setPixmap(n_3);
}

void Scene::removeScoreItems()
{
    removeItem(head_score);
    removeItem(num_0s);
    removeItem(num_1s);
    removeItem(num_2s);
    removeItem(num_3s);
    removeItem(num_4s);
    removeItem(num_5s);
    removeItem(num_6s);
    removeItem(num_7s);
    removeItem(num_8s);
    removeItem(num_9s);
    removeItem(num_00s);
    removeItem(num_10s);
    removeItem(num_20s);
    removeItem(num_30s);
    delete num_0s;
    delete num_1s;
    delete num_2s;
    delete num_3s;
    delete num_4s;
    delete num_5s;
    delete num_6s;
    delete num_7s;
    delete num_8s;
    delete num_9s;
    delete num_00s;
    delete num_10s;
    delete num_20s;
    delete num_30s;
}

void Scene::displayFinalScore(int final_score)
{
    switch (final_score/10) {//十位數
    case 0:
        num_00s->setPos(300,135);
        addItem(num_00s);
        break;
    case 1:
        num_10s->setPos(300,135);
        addItem(num_10s);
        break;
    case 2:
        num_20s->setPos(300,135);
        addItem(num_20s);
        break;
    case 3:
        num_30s->setPos(300,135);
        addItem(num_30s);
        break;
    default:
        break;
    }
    switch (final_score%10) {//個位數
    case 0:
        num_0s->setPos(320,135);
        addItem(num_0s);
        break;
    case 1:
        num_1s->setPos(320,135);
        addItem(num_1s);
        break;
    case 2:
        num_2s->setPos(320,135);
        addItem(num_2s);
        break;
    case 3:
        num_3s->setPos(320,135);
        addItem(num_3s);
        break;
    case 4:
        num_4s->setPos(320,135);
        addItem(num_4s);
        break;
    case 5:
        num_5s->setPos(320,135);
        addItem(num_5s);
        break;
    case 6:
        num_6s->setPos(320,135);
        addItem(num_6s);
        break;
    case 7:
        num_7s->setPos(320,135);
        addItem(num_7s);
        break;
    case 8:
        num_8s->setPos(320,135);
        addItem(num_8s);
        break;
    case 9:
        num_9s->setPos(320,135);
        addItem(num_9s);
        break;
    default:
        break;
    }
}

void Scene::displatAward(int final_score)
{
    award_A = new Other();
    QPixmap a_A;
    a_A.load(":image/img/award_A.png");
    award_A->setPixmap(a_A);
    award_A->setPos(350,180);
    award_B = new Other();
    QPixmap a_B;
    a_B.load(":image/img/award_B.png");
    award_B->setPixmap(a_B);
    award_B->setPos(350,180);
    award_C = new Other();
    QPixmap a_C;
    a_C.load(":image/img/award_C.png");
    award_C->setPixmap(a_C);
    award_C->setPos(350,180);
    award_D = new Other();
    QPixmap a_D;
    a_D.load(":image/img/award_D.png");
    award_D->setPixmap(a_D);
    award_D->setPos(150,180);
    award_F = new Other();
    QPixmap a_F;
    a_F.load(":image/img/award_F.png");
    award_F->setPixmap(a_F);
    award_F->setPos(350,180);
    award_S = new Other();
    QPixmap a_S;
    a_S.load(":image/img/award_S.png");
    award_S->setPixmap(a_S);
    award_S->setPos(350,180);
    award_SS = new Other();
    QPixmap a_SS;
    a_SS.load(":image/img/award_SS.png");
    award_SS->setPixmap(a_SS);
    award_SS->setPos(350,180);

    if(final_score == hit_num)
    {
        addItem(award_SS);
    }
    else if(final_score*100 >= hit_num*95)
    {
        addItem(award_S);
    }
    else if(final_score*100 >= hit_num*90)
    {
        addItem(award_A);
    }
    else if(final_score*100 >= hit_num*80)
    {
        addItem(award_B);
    }
    else if(final_score*100 >= hit_num*70)
    {
        addItem(award_C);
    }
    else if(final_score*100 >= hit_num*60)
    {
        addItem(award_D);
    }
    else
    {
        addItem(award_F);
    }
}

void Scene::removeAwardItems()
{
    removeItem(award_A);
    removeItem(award_B);
    removeItem(award_C);
    removeItem(award_D);
    removeItem(award_F);
    removeItem(award_S);
    removeItem(award_SS);
    delete award_A;
    delete award_B;
    delete award_C;
    delete award_D;
    delete award_F;
    delete award_S;
    delete award_SS;
}
