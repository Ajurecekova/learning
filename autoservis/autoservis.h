#pragma once

#include <QtWidgets>
#include <iostream>
#include <fstream>
#include "ui_autoservis.h"
#include "ui_login.h"
#include "ui_newuser.h"

class sluzba {
private:
    QString s;
    double cena;
public:
    sluzba() {
        cena = 0; s = "";
    }
    sluzba(QString sl, int c) : s(sl), cena(c) {};
    int c() { return cena; }
    QString slu() { return s; }
    double changec(double n) {
        cena = cena * n;
        return cena; }
};

class fyz_osoba{
private:
    QString pmenofo, meno;
    QString heslofo, znacka, model;
    int rok;
public:
    fyz_osoba(QString pm, QString h, QString m, QString z, QString mod, int r) :pmenofo(pm), meno(m), heslofo(h), znacka(z), model(mod), rok(r) {};
    QString getName() { return pmenofo; }
    QString getHeslo() { return heslofo; }
    QString getMeno() { return meno; }
    QString getZnacka() { return znacka; }
    QString getModel() { return model; }
    int getRok() { return rok; }
    QString setMeno(QString a) { meno = a; return meno; }
    QString setZnacka(QString a) { znacka = a; return znacka; }
    QString setModel(QString a) { model = a; return model; }
    int setRok(int a) { rok = a; return rok; }
    QString setName(QString a) { pmenofo = a; return pmenofo; }
    QString setHeslo(QString a) { heslofo = a; return heslofo; }
};

class firma {
private:
    QString pmenof, nazov;
    QString heslof, znacka, model;
    int rok, ICO;
    QString DPH;
public:
    firma(QString pm, QString h, QString m, QString z, QString mod, int r, int i, QString d):pmenof(pm), nazov(m), heslof(h), znacka(z), model(mod), rok(r), ICO(i), DPH(d) {};
    QString getName() { return pmenof; }
    QString getHeslo() { return heslof; }
    QString getNazov() { return nazov; }
    QString getDPH() { return DPH; }
    QString getZnacka() { return znacka; }
    QString getModel() { return model; }
    int getICO() { return ICO; }
    int getRok() { return rok; }
    QString setNazov(QString a) { nazov = a; return nazov; }
    QString setDPH(QString a) { DPH = a; return DPH; }
    QString setZnacka(QString a) { znacka = a; return znacka; }
    QString setModel(QString a) { model = a; return model; }
    int setICO(int a) { ICO = a; return ICO; }
    int setRok(int a) { rok = a; return rok; }
    QString setName(QString a) { pmenof = a; return pmenof; }
    QString setHeslo(QString a) { heslof = a; return heslof; }
};

class pracovnik {
private:
    QString pmenop, heslop, pozicia;
public:
    pracovnik(QString pm, QString h, QString p) : pmenop(pm), heslop(h), pozicia(p) {};
    QString getName() { return pmenop; }
    QString getHeslo() { return heslop; }
    QString getPozicia() { return pozicia; }
    QString setPozicia(QString a) { pozicia = a; return pozicia; }
    QString setName(QString a) { pmenop = a; return pmenop; }
    QString setHeslo(QString a) { heslop = a; return heslop; }
};

class administrator {
private:
    QString menoa, heslo;
public:
    administrator(QString m, QString h) : menoa(m), heslo(h) {};
    QString getName() { return menoa; }
    QString getHeslo() { return heslo; }
    QString setName(QString a) { menoa = a; return menoa; }
    QString setHeslo(QString a) { heslo = a; return heslo; }
};

class Newuser : public QDialog
{
    Q_OBJECT

public:
    Newuser(QWidget* parent = Q_NULLPTR) : QDialog(parent), ui3(new Ui::NewUser)
    {
        ui3->setupUi(this);
        ui3->comboBox->setCurrentIndex(0);
        ui3->groupBox_2->setVisible(true);
        ui3->groupBox_3->setVisible(true);
        ui3->groupBox_4->setVisible(false);
        ui3->groupBox_5->setVisible(false);
        ui3->groupBox_6->setVisible(false);
        ui3->groupBox_7->setVisible(false);
        ui3->groupBox_8->setVisible(false);
        ui3->groupBox_9->setVisible(false);
        ui3->groupBox_10->setVisible(false);
    };
private:
    Ui::NewUser* ui3;
private slots:
    void on_comboBox_currentIndexChanged(int index);
    void on_pushButton_clicked();
};

class Login : public QDialog
{
    Q_OBJECT

public:
    Login(QWidget* parent = Q_NULLPTR): QDialog(parent), ui2(new Ui::Prihlasenie)
    {
        ui2->setupUi(this);
        ui2->lineEdit_2->setEchoMode(QLineEdit::Password);
    };
    QString getName() { return ui2->lineEdit->text(); }
    QString getHeslo() { return ui2->lineEdit_2->text(); }
    int t() { return typel; }
private:
    Ui::Prihlasenie* ui2;
    int typel=0;
private slots:
    void on_Prihlasenie_accepted();
    void on_Prihlasenie_rejected();
};

class autoservis : public QMainWindow
{
    Q_OBJECT

public:
    autoservis(QWidget *parent = Q_NULLPTR);
    void nacitanie();
    void nacitanie_admin();
    void nacitanie_osoba();
    void nacitanie_firma();
    void nacitanie_pracovnik();
    void zapis_admin();
    void zapis_osoba();
    void zapis_firma();
    void zapis_pracovnik();
    bool prihlasenie();
    void nacitanie_faktury();
    void vytvorenie_faktury();
    void ulozenie_nakupu();
    void usertable();
private:
    Ui::autoservisClass* ui;
    QMessageBox msgBox;
    QVector<sluzba> p;
    QVector<sluzba> faktura;
    QVector<administrator> a;
    QVector<firma> fir;
    QVector<fyz_osoba> fyz;
    QVector<pracovnik> prac;
    QString sluzby = "sluzby.txt";
    int ad=0, fr=0, fy=0, za=0;
    int f=0;
    int type=0, index=0;
    int b=0, minute=0;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_10_clicked();
};
