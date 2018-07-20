#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    //scene(new QGraphicsScene(0, 0, 1024, 640)),
    scene(new Scene),
    //bgm(new QMediaPlayer),
    /*timer(new QTimer),
    count_timer(new QTimer),
    instant_timer(new QTimer),
    monster_timer(new QTimer),*/
    ui(new Ui::MainWindow),
    signalMapper1(new QSignalMapper) {

    ui->setupUi(this);
    connect(scene->timer, SIGNAL(timeout()), signalMapper1, SLOT(map()));

    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,1024,640);
    ui->graphicsView->setFixedSize(ui->graphicsView->scene()->width(), ui->graphicsView->scene()->height());//adjust the scene to the margin!!!
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->bar_player->setFixedHeight(10);
    ui->bar_monster->setFixedHeight(10);

    QPixmap pix(":/img/battlekaishi.gif");
    ui->label_warstart->setStyleSheet("border-image:url(:/img/battlekaishi.gif);");
    ui->label_warstart->setScaledContents( true );
    ui->label_warstart->setPixmap(pix);

    QPixmap pix1(":/img/endgame.gif");
    ui->label_warexit->setStyleSheet("border-image:url(:/img/endgame.gif);");
    ui->label_warexit->setScaledContents( true );
    ui->label_warexit->setPixmap(pix1);

    QPixmap pix2(":/img/clock.gif");
    ui->label_clock->setStyleSheet("border-image:url(:/img/clock.gif);");
    ui->label_clock->setScaledContents( true );
    ui->label_clock->setPixmap(pix2);


    ui->timeclock->setSegmentStyle(QLCDNumber::Flat);
    ui->timeclock->setPalette(Qt::transparent);

    ui->scoreclock->setSegmentStyle(QLCDNumber::Flat);
    ui->scoreclock->setPalette(Qt::transparent);

    ui->bar_monster->setRange(0,30000);
    ui->bar_player->setRange(0,100);
    /*ui->bar_monster->setStyleSheet("::chunk {"
                                   "background-color: "
                                   "qlineargradient(x0: 0, x2: 1, "
                                   "stop: 0 green, stop: 0.6 green, "
                                   "stop: 0.8 orange, "
                                   "stop: 1 red"
                                   ")}");*/
    ui->bar_monster->setMinimum(0);
    ui->bar_monster->setMaximum(30000);
    ui->bar_player->setMinimum(0);
    ui->bar_player->setMaximum(100);

    ui->label_monsterhp->setAlignment(Qt::AlignRight);
    ui->label_playerhp->setAlignment(Qt::AlignRight);

    gametitle();

    ui->graphicsView->show();

    connect(ui->btn_start, SIGNAL(clicked()), this, SLOT(startwar()));
    connect(ui->btn_exit, SIGNAL(clicked()), this, SLOT(exitwar()));
    connect(ui->btn_restart, SIGNAL(clicked()), this, SLOT(restartwar()));

    connect(ui->btn_intoinstruction, SIGNAL(clicked()), this, SLOT(gameinstruction()));
    connect(ui->btn_outinstruction, SIGNAL(clicked()), this, SLOT(gametitle()));

    connect(scene->count_timer, SIGNAL(timeout()), this, SLOT(PcollideM()));

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::gameinstruction() {
    QPixmap pix3(":/img/gameinstruction.png");
    ui->label_instruction->setStyleSheet("border-image:url(:/img/gameinstruction.png);");
    ui->label_instruction->setScaledContents( true );
    ui->label_instruction->setPixmap(pix3);

    QPixmap pix4(":/img/x.gif");
    ui->label_leaveinsturction->setStyleSheet("border-image:url(:/img/x.gif);");
    ui->label_leaveinsturction->setScaledContents( true );
    ui->label_leaveinsturction->setPixmap(pix4);

    ui->label_leaveinsturction->show();
    ui->label_instruction->show();
    ui->btn_outinstruction->show();

    qDebug()<<"Instruction of bathroom war."<<endl;

}

void MainWindow::gametitle() {

    QPixmap pix(":/img/toilet.gif");
    ui->label_toilet->setStyleSheet("border-image:url(:/img/toilet.gif);");
    ui->label_toilet->setScaledContents( true );
    ui->label_toilet->setPixmap(pix);

    scene->cockroach->hide();
    scene->human->hide();
    ui->timeclock->hide();
    ui->scoreclock->hide();
    ui->bar_player->hide();
    ui->bar_monster->hide();
    ui->label_bigskill->hide();
    ui->label_monster->hide();
    ui->label_player->hide();
    ui->label_toilet->show();
    ui->label_gamelose->hide();
    ui->label_gamewin->hide();
    ui->label_gameeven->hide();
    ui->label_clock->hide();
    ui->label_monsterhp->hide();
    ui->label_playerhp->hide();
    ui->label_instruction->hide();
    ui->btn_intoinstruction->show();
    ui->label_leaveinsturction->hide();
    ui->btn_outinstruction->hide();
    ui->btn_restart->hide();

    QPixmap pim6(":/img/bathroomstart.gif");
    scene->setBackgroundBrush(pim6.scaled(1024,640,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

}

void MainWindow::backgametitle() { //just in case(因為當時我不確定gametitle能不能同時當一個普通的function，又當一個slots)

    QPixmap pix(":/img/toilet.gif");
    ui->label_toilet->setStyleSheet("border-image:url(:/img/toilet.gif);");
    ui->label_toilet->setScaledContents( true );
    ui->label_toilet->setPixmap(pix);

    scene->cockroach->hide();
    scene->human->hide();
    ui->timeclock->hide();
    ui->bar_player->hide();
    ui->bar_monster->hide();
    ui->label_bigskill->hide();
    ui->label_monster->hide();
    ui->label_player->hide();
    ui->label_toilet->show();
    ui->label_gamelose->hide();
    ui->label_gamewin->hide();
    ui->label_clock->hide();
    ui->label_monsterhp->hide();
    ui->label_playerhp->hide();
    ui->label_instruction->hide();
    ui->btn_intoinstruction->show();
    ui->label_leaveinsturction->hide();
    ui->btn_outinstruction->hide();

    QPixmap pim(":/img/bathroomstart.gif");
    scene->setBackgroundBrush(pim.scaled(1024,640,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    /*QSound music("/music/What-is-Love.wav");
    music.play();*/
}

void MainWindow::startwar() {
    scene->gamestart();

    //scene->cockroach->show();
    //scene->human->show();
    ui->btn_start->hide();
    ui->btn_exit->hide();
    ui->label_warexit->hide();
    ui->label_warstart->hide();
    ui->label_toilet->hide();
    ui->label_bigskill->show();
    ui->label_monster->show();
    ui->label_player->show();
    ui->timeclock->show();
    ui->scoreclock->show();
    ui->timeclock->display(scene->count);
    ui->bar_player->show();
    ui->bar_monster->show();
    ui->label_clock->show();
    ui->label_monsterhp->show();
    ui->label_playerhp->show();
    ui->label_instruction->hide();
    ui->btn_intoinstruction->hide();
    ui->label_leaveinsturction->hide();
    ui->label_gamelose->hide();
    ui->label_gamewin->hide();
    ui->label_gameeven->hide();

    QPixmap p1;
    p1.load(":/img/humanbeing1.gif");
    scene->human->setPixmap((p1).scaled(97, 145));

    connect(scene->count_timer, SIGNAL(timeout()), this, SLOT(timedisplay()));
    connect(scene->instant_timer, SIGNAL(timeout()), this, SLOT(timedisplay_instantly()));

    scene->human->connect(scene->monster_timer, SIGNAL(timeout()), scene->human, SLOT(move()));

    //scene->checkgamestart=1;

    QPixmap pim(":/img/bathroom.gif");
    scene->setBackgroundBrush(pim.scaled(1024,640,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    //QSound music(":/music/sakurawar.wav");
    //music.play();


    /*bgm->setMedia(QUrl("qrc:/music/sakurawar.mp3"));
    bgm->setVolume(70);
    bgm->play();*/


}

void MainWindow::exitwar() {
    exit(1);
}

void MainWindow::timedisplay() {
    scene->count--;
    ui->timeclock->display(scene->count);


    if((scene->cockroach->x()==scene->human->x())&&(scene->cockroach->y()==scene->human->y())) {
        scene->cockroach->hp--;
    }

    if(scene->count==0) {
        disconnect(scene->count_timer, SIGNAL(timeout()), this, SLOT(timedisplay()));
        scene->human->disconnect(scene->monster_timer, SIGNAL(timeout()), scene->human, SLOT(move()));
        scene->checkgamestart=0;

    }

    if(scene->count==160||scene->count==140||scene->count==120||scene->count==100||scene->count==80||scene->count==60||scene->count==40||scene->count==20)
        scene->hppotion++;

    if(scene->human->hp>=5000) {
        bullet *b = new bullet;
        //bullet *a = new bullet;
        if(qrand() % 2 == 0) {
            b->setPixmap(QPixmap(":/img/liquidsoap1.gif").scaled(30, 64));
            // c->setPixmap(QPixmap(":/img/poop.gif").scaled(50, 50));
            // d->setPixmap(QPixmap(":/img/poop.gif").scaled(50, 50));
        } else {
            b->setPixmap(QPixmap(":/img/liquidsoap3.gif").scaled(28, 62));
            // c->setPixmap(QPixmap(":/img/poop.gif").scaled(50, 50));
            // d->setPixmap(QPixmap(":/img/poop.gif").scaled(50, 50));
        }
        //a->setPixmap(QPixmap(":/img/liquidsoap1.gif").scaled(30, 59));
        //a->setPos(scene->human->x() + scene->human->pixmap().width() / 2 - b->pixmap().width() / 2 + 20, scene->human->y() + b->pixmap().height());
        //b->setPixmap(QPixmap(":/img/liquidsoap3.gif").scaled(28, 57));
        b->setPos(scene->human->x() + scene->human->pixmap().width() / 2 - b->pixmap().width() / 2, scene->human->y() + b->pixmap().height());

        signalMapper1->setMapping(scene->timer, scene->cockroach);
        connect(signalMapper1, SIGNAL(mapped(QObject *)), b, SLOT(Mfly(QObject *)));
        //connect(signalMapper1, SIGNAL(mapped(QObject *)), a, SLOT(Mfly(QObject *)));
        //scene->addItem(static_cast<QGraphicsPixmapItem*>(a));
        scene->addItem(static_cast<QGraphicsPixmapItem*>(b));
        /*if((scene->count==0 && scene->cockroach->hp>0 && scene->human->hp>0) || (scene->cockroach->hp>0 && scene->human->hp<=0) || (scene->cockroach->hp<=0 && scene->human->hp>0)){
          b->scene()->removeItem(b);
          delete b; //try to test
        }*/

    } else {
        bullet *b = new bullet;
        bullet *a = new bullet;
        a->setPixmap(QPixmap(":/img/liquidsoap2.gif").scaled(30, 77));
        a->setPos(scene->human->x() + scene->human->pixmap().width() / 2 - b->pixmap().width() / 2 + 20, scene->human->y() + b->pixmap().height());
        b->setPixmap(QPixmap(":/img/liquidsoap4.gif").scaled(28, 74));
        b->setPos(scene->human->x() + scene->human->pixmap().width() / 2 - b->pixmap().width() / 2, scene->human->y() + b->pixmap().height());

        signalMapper1->setMapping(scene->timer, scene->cockroach);
        connect(signalMapper1, SIGNAL(mapped(QObject *)), a, SLOT(angryMfly(QObject *)));
        connect(signalMapper1, SIGNAL(mapped(QObject *)), b, SLOT(angryMflyleft(QObject *)));
        scene->addItem(static_cast<QGraphicsPixmapItem*>(a));
        scene->addItem(static_cast<QGraphicsPixmapItem*>(b));

        /*if((scene->count==0 && scene->cockroach->hp>0 && scene->human->hp>0) || (scene->cockroach->hp>0 && scene->human->hp<=0) || (scene->cockroach->hp<=0 && scene->human->hp>0)){
          a->scene()->removeItem(a);
          b->scene()->removeItem(b);
          delete a;
          delete b;
        }*/

    }

}

void MainWindow::timedisplay_instantly() {
    ui->bar_player->setValue(scene->cockroach->hp);
    ui->bar_monster->setValue(scene->human->hp);
    ui->scoreclock->display(scene->totalscore());
    //scene->score++;// test


    if(scene->hppotion > 0) {
        QPixmap pix2(":/img/clock1.gif");
        ui->label_clock->setStyleSheet("border-image:url(:/img/clock1.gif);");
        ui->label_clock->setScaledContents( true );
        ui->label_clock->setPixmap(pix2);
    } else {
        QPixmap pix2(":/img/clock.gif");
        ui->label_clock->setStyleSheet("border-image:url(:/img/clock.gif);");
        ui->label_clock->setScaledContents( true );
        ui->label_clock->setPixmap(pix2);
    }
    if(scene->bigskill==5) {
        QPixmap pix1(":/img/magic5.gif");
        ui->label_bigskill->setStyleSheet("border-image:url(:/img/magic5.gif);");
        ui->label_bigskill->setScaledContents( true );
        ui->label_bigskill->setPixmap(pix1);
    } else if(scene->bigskill==4) {
        QPixmap pix1(":/img/magic4.gif");
        ui->label_bigskill->setStyleSheet("border-image:url(:/img/magic4.gif);");
        ui->label_bigskill->setScaledContents( true );
        ui->label_bigskill->setPixmap(pix1);
    } else if(scene->bigskill==3) {
        QPixmap pix1(":/img/magic3.gif");
        ui->label_bigskill->setStyleSheet("border-image:url(:/img/magic3.gif);");
        ui->label_bigskill->setScaledContents( true );
        ui->label_bigskill->setPixmap(pix1);
    } else if(scene->bigskill==2) {
        QPixmap pix1(":/img/magic2.gif");
        ui->label_bigskill->setStyleSheet("border-image:url(:/img/magic2.gif);");
        ui->label_bigskill->setScaledContents( true );
        ui->label_bigskill->setPixmap(pix1);
    } else if(scene->bigskill==1) {
        QPixmap pix1(":/img/magic1.gif");
        ui->label_bigskill->setStyleSheet("border-image:url(:/img/magic1.gif);");
        ui->label_bigskill->setScaledContents( true );
        ui->label_bigskill->setPixmap(pix1);
    } else {
        QPixmap pix1(":/img/magic0.gif");
        ui->label_bigskill->setStyleSheet("border-image:url(:/img/magic0.gif);");
        ui->label_bigskill->setScaledContents( true );
        ui->label_bigskill->setPixmap(pix1);
    }

    if(scene->human->hp<5000) {
        QPixmap p;
        p.load(":/img/humanbeing2.gif");
        scene->human->setPixmap((p).scaled(123, 145));
    }

    if(scene->cockroach->hp<=0 && scene->human->hp>0) { //it means player loses.
        QPixmap pix1(":/img/losewar.gif");
        ui->label_gamelose->setStyleSheet("border-image:url(:/img/losewar.gif);");
        ui->label_gamelose->setScaledContents( true );
        ui->label_gamelose->setPixmap(pix1);
        scene->checkgamestart=0;
        disconnect(scene->count_timer, SIGNAL(timeout()), this, SLOT(timedisplay()));
        scene->human->disconnect(scene->monster_timer, SIGNAL(timeout()), scene->human, SLOT(move()));
        scene->cockroach->hide();
        scene->human->hide();//
        scene->cockroach->setPos(0, 0);// for the purpose of being not attacked after score shows.
        scene->human->setPos(1024, 640);// for the purpose of being not attacked after score shows.
        ui->label_gamelose->show();
        ui->btn_restart->show();


    }
    if(scene->cockroach->hp>0 && scene->human->hp<=0) { //it means player win.
        QPixmap pix1(":/img/winwar.gif");
        ui->label_gamewin->setStyleSheet("border-image:url(:/img/winwar.gif);");
        ui->label_gamewin->setScaledContents( true );
        ui->label_gamewin->setPixmap(pix1);
        scene->checkgamestart=0;
        disconnect(scene->count_timer, SIGNAL(timeout()), this, SLOT(timedisplay()));
        scene->human->disconnect(scene->monster_timer, SIGNAL(timeout()), scene->human, SLOT(move()));
        scene->human->hide();
        scene->cockroach->hide();//
        scene->cockroach->setPos(0, 0);//
        scene->human->setPos(1024, 640);//
        ui->label_gamewin->show();
        ui->btn_restart->show();

    }
    if(scene->count==0 && scene->cockroach->hp>0 && scene->human->hp>0) { //it means game even.
        QPixmap pix1(":/img/evengame.gif");
        ui->label_gameeven->setStyleSheet("border-image:url(:/img/evengame.gif);");
        ui->label_gameeven->setScaledContents( true );
        ui->label_gameeven->setPixmap(pix1);
        scene->checkgamestart=0;
        disconnect(scene->count_timer, SIGNAL(timeout()), this, SLOT(timedisplay()));
        scene->human->disconnect(scene->monster_timer, SIGNAL(timeout()), scene->human, SLOT(move()));
        scene->human->hide();//
        scene->cockroach->hide();//
        scene->cockroach->setPos(0, 0);//
        scene->human->setPos(1024, 640);//

        ui->label_gameeven->show();
        ui->btn_restart->show();
    }

    /*if((scene->count==0 && scene->cockroach->hp>0 && scene->human->hp>0) || (scene->cockroach->hp>0 && scene->human->hp<=0) || (scene->cockroach->hp<=0 && scene->human->hp>0))
        ~bullet();*/
        //try to remove bullet on the spot


    ui->label_monsterhp->setText((QString("%1 / 30000").arg(scene->human->hp)));
    ui->label_playerhp->setText((QString("%1 / 100").arg(scene->cockroach->hp)));

    if(scene->cockroach->hp<=0) {
        ui->label_playerhp->setText("0 / 100");
        ui->bar_player->setValue(0);

    }
    if(scene->human->hp<=0) {
        ui->label_monsterhp->setText("0 / 30000");
        ui->bar_monster->setValue(0);
    }

}


void MainWindow::PcollideM(){


    qreal bigrangex= scene->cockroach->x()+40; //to tell whether it collides with the monster
    qreal bigrangey= scene->cockroach->y()+40;
    qreal smallrangex= scene->cockroach->x()-40;
    qreal smallrangey= scene->cockroach->y()-40;

    if((scene->human->x()<=bigrangex) && (scene->human->x()>=smallrangex) && (scene->human->y()<=bigrangey) && (scene->human->y()>=smallrangey)){
        scene->cockroach->hp=scene->cockroach->hp-10;
        //score=score-70;
        scene->cockroach->score=scene->cockroach->score-70;
    }
}

void MainWindow::restartwar(){

    ui->btn_restart->hide();
    startwar();

}
