#include "autoservis.h"


autoservis::autoservis(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::autoservisClass)
{
    ui->setupUi(this);
    nacitanie_admin();
    nacitanie_firma();
    nacitanie_osoba();
    nacitanie_pracovnik();
    bool a;
    do{
        a = prihlasenie();
    } while (a == false);
    nacitanie();
    nacitanie_faktury();
    if (type == 0) {
        usertable();
    }
}
void Login::on_Prihlasenie_accepted()
{
    typel = ui2->comboBox->currentIndex();
}
void Login::on_Prihlasenie_rejected() {
    exit(0);
}

void autoservis::nacitanie() {
    if (sluzby.isEmpty()) { return; }
    QFileInfo fi(sluzby);
    if (fi.suffix() == "txt") {
        QFile file(sluzby);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
        QTextStream in(&file);
        QString n = in.readLine();
        b = n.toInt();
        for (size_t i = 0; i < n.toInt(); i++)
        {
            QString line = in.readLine();
            QString line1 = in.readLine();
            QString line2 = in.readLine();

            sluzba a(line1, line2.toInt());
            p.push_back(a);
        }
        file.close();
    }
    for (int j = 0; j < b; j++) {
        QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget);
        item->setText(0, QString("%1").arg(p[j].slu()));
        QTreeWidgetItem* item2 = new QTreeWidgetItem(ui->treeWidget);
        if (type == 1 && fir[index].getDPH() == "ano") {
            item2->setText(1, QString("%1").arg(p[j].c()*0.8));
        }
        else item2->setText(1, QString("%1").arg(p[j].c()));
        item->addChild(item2);
    }
}

void autoservis::nacitanie_admin() {
    QString fileName = "admin.txt";
    if (fileName.isEmpty()) { return; }
    QFileInfo fi(fileName);
    if (fi.suffix() == "txt") {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
        QTextStream in(&file);

        while (!in.atEnd())
        {
            QString line1 = in.readLine();
            QString line2 = in.readLine();
            QString line3 = in.readLine();
            administrator d(line1, line2);
            a.push_back(d);
            ad++;
        }
        file.close();
    }
}
void autoservis::nacitanie_osoba() {
    QString fileName = "osoba.txt";
    if (fileName.isEmpty()) { return; }
    QFileInfo fi(fileName);
    if (fi.suffix() == "txt") {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
        QTextStream in(&file);

        while (!in.atEnd())
        {
            QString line1 = in.readLine();
            QString line2 = in.readLine();
            QString line3 = in.readLine();
            QString line4 = in.readLine();
            QString line5 = in.readLine();
            QString line6 = in.readLine();
            QString line7 = in.readLine();
            fyz_osoba d(line1, line2, line3, line4, line5, line6.toInt());
            fyz.push_back(d);
            fy++;
        }
        file.close();
    }
}
void autoservis::nacitanie_firma() {
    QString fileName = "firma.txt";
    if (fileName.isEmpty()) { return; }
    QFileInfo fi(fileName);
    if (fi.suffix() == "txt") {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
        QTextStream in(&file);

        while (!in.atEnd())
        {
            QString line1 = in.readLine();
            QString line2 = in.readLine();
            QString line3 = in.readLine();
            QString line4 = in.readLine();
            QString line5 = in.readLine();
            QString line6 = in.readLine();
            QString line7 = in.readLine();
            QString line8 = in.readLine();
            QString line9 = in.readLine();
            firma d(line1, line2, line3, line4, line5, line6.toInt(), line7.toInt(), line8);
            fir.push_back(d);
            fr++;
        }
        file.close();
    }
}
void autoservis::nacitanie_pracovnik() {
    QString fileName = "zamestnanec.txt";
    if (fileName.isEmpty()) { return; }
    QFileInfo fi(fileName);
    if (fi.suffix() == "txt") {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
        QTextStream in(&file);

        while (!in.atEnd())
        {
            QString line1 = in.readLine();
            QString line2 = in.readLine();
            QString line3 = in.readLine();
            QString line4 = in.readLine();
            pracovnik d(line1, line2, line3);
            prac.push_back(d);
            za++;
        }
        file.close();
    }
}

void autoservis::zapis_admin() {
    QString fileName = "admin.txt";
    if (fileName.isEmpty()) { return; }
    QFileInfo fi(fileName);
    if (fi.suffix() == "txt") {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
        QTextStream out(&file);

        for (int i = 0; i < ad; i++)
        {
            out << a[i].getName() << "\n";
            out << a[i].getHeslo() << "\n";
            out << "\n";
        }
        file.close();
    }
}
void autoservis::zapis_osoba() {
    QString fileName = "osoba.txt";
    if (fileName.isEmpty()) { return; }
    QFileInfo fi(fileName);
    if (fi.suffix() == "txt") {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
        QTextStream out(&file);

        for (int i = 0; i < fy; i++)
        {
            out << fyz[i].getName() << "\n";
            out << fyz[i].getHeslo() << "\n";
            out << fyz[i].getMeno() << "\n";
            out << fyz[i].getZnacka() << "\n";
            out << fyz[i].getModel() << "\n";
            out << fyz[i].getRok() << "\n";
            out << "\n";
        }
        file.close();
    }
}
void autoservis::zapis_firma() {
    QString fileName = "firma.txt";
    if (fileName.isEmpty()) { return; }
    QFileInfo fi(fileName);
    if (fi.suffix() == "txt") {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
        QTextStream out(&file);

        for (int i = 0; i < fr; i++)
        {
            out << fir[i].getName() << "\n";
            out << fir[i].getHeslo() << "\n";
            out << fir[i].getNazov() << "\n";
            out << fir[i].getZnacka() << "\n";
            out << fir[i].getModel() << "\n";
            out << fir[i].getRok() << "\n";
            out << fir[i].getICO() << "\n";
            out << fir[i].getDPH() << "\n";
            out << "\n";
        }
        file.close();
    }
}
void autoservis::zapis_pracovnik() {
    QString fileName = "zamestnanec.txt";
    if (fileName.isEmpty()) { return; }
    QFileInfo fi(fileName);
    if (fi.suffix() == "txt") {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
        QTextStream out(&file);

        for (int i = 0; i < za; i++)
        {
            out << prac[i].getName() << "\n";
            out << prac[i].getHeslo() << "\n";
            out << prac[i].getPozicia() << "\n";
            out << "\n";
        }
        file.close();
    }
}

bool autoservis::prihlasenie() {
    Login* login = new Login;
    if (login->exec()) {
        type = login->t();
        std::string heslo = QCryptographicHash::hash(login->getHeslo().toStdString().c_str(), QCryptographicHash::Md4).toHex();

        if (login->t() == 0) {
            int n = 0;
            for (int i = 0; i < ad; i++) {
                if (login->getName() == a[i].getName() && heslo == a[i].getHeslo().toStdString()) {
                    index = i;
                    n++;
                }

            }
            if (n == 1) {
                ui->groupBox_4->setVisible(false);
                ui->pushButton_2->setVisible(false);
                ui->groupBox_9->setVisible(false);
                ui->groupBox_10->setVisible(false);
                ui->lineEdit->setText(a[index].getName());
                ui->lineEdit->setEnabled(false);
                return true;
            }
            else {
                msgBox.setText(u8"Zlé meno alebo heslo.");
                msgBox.exec();
                return false;
            }
        }
        if (login->t() == 1) {
            int n = 0;
            for (int i = 0; i < fr; i++) {
                if (login->getName() == fir[i].getName() && heslo == fir[i].getHeslo().toStdString()) {
                    index = i;
                    n++;
                }
            }
            if (n == 1) {
                ui->pushButton_5->setVisible(false);
                ui->pushButton_7->setVisible(false);
                ui->groupBox_9->setVisible(false);
                ui->groupBox_7->setVisible(false);
                ui->label_12->setVisible(false);
                ui->lineEdit_6->setVisible(false);
                ui->lineEdit->setText(fir[index].getName());
                ui->lineEdit->setEnabled(false);
                ui->lineEdit_11->setText(fir[index].getNazov());
                ui->lineEdit_4->setText(fir[index].getZnacka());
                ui->lineEdit_10->setText(fir[index].getModel());
                ui->lineEdit_9->setText(QString("%1").arg(fir[index].getRok()));
                ui->lineEdit_8->setText(QString("%1").arg(fir[index].getICO()));
                ui->lineEdit_7->setText(fir[index].getDPH());
                return true;
            }
            else {
                msgBox.setText(u8"Zlé meno alebo heslo.");
                msgBox.exec();
                return false;
            }
        }
        if (login->t() == 2) {
            int n = 0;
            for (int i = 0; i < fy; i++) {
                if (login->getName() == fyz[i].getName() && heslo == fyz[i].getHeslo().toStdString()) {
                    index = i;
                    n++;
                }
            }
            if (n == 1) {
                ui->pushButton_5->setVisible(false);
                ui->pushButton_7->setVisible(false);
                ui->groupBox_9->setVisible(false);
                ui->groupBox_7->setVisible(false);
                ui->groupBox_12->setVisible(false);
                ui->label_12->setVisible(false);
                ui->lineEdit_6->setVisible(false);
                ui->lineEdit->setText(fyz[index].getName());
                ui->lineEdit->setEnabled(false);
                ui->lineEdit_11->setText(fyz[index].getMeno());
                ui->lineEdit_4->setText(fyz[index].getZnacka());
                ui->lineEdit_10->setText(fyz[index].getModel());
                ui->lineEdit_9->setText(QString("%1").arg(fyz[index].getRok()));
                return true;
            }
            else {
                msgBox.setText(u8"Zlé meno alebo heslo.");
                msgBox.exec();
                return false;
            }
        }
        if (login->t() == 3) {
            int n = 0;
            for (int i = 0; i < za; i++) {
                if (login->getName() == prac[i].getName() && heslo == prac[i].getHeslo().toStdString()) {
                    index = i;
                    n++;
                }
            }
            if (n == 1) {
                ui->groupBox_3->setVisible(false);
                ui->pushButton_3->setVisible(false);
                ui->pushButton_5->setVisible(false);
                ui->pushButton_7->setVisible(false);
                ui->groupBox_7->setVisible(false);
                ui->groupBox_7->setVisible(false);
                ui->groupBox_11->setVisible(false);
                ui->groupBox_12->setVisible(false);
                ui->lineEdit->setText(prac[index].getName());
                ui->lineEdit->setEnabled(false);
                ui->lineEdit_6->setText(prac[index].getPozicia());
                return true;
            }
            else {
                msgBox.setText(u8"Zlé meno alebo heslo.");
                msgBox.exec();
                return false;
            }
        }
    }
    else {
        login->close();
        close();
    }
}
void autoservis::nacitanie_faktury() {
    QString fileName;
    if (type == 1) {
        fileName = fir[index].getName() + "f"+ ".txt";
    }
    else if (type == 2) {
        fileName = fyz[index].getName() + "f" +".txt";
    }
    else return;
    if (fileName.isEmpty()) { return; }
    QFileInfo fi(fileName);
    if (fi.suffix() == "txt") {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            return;
        }
        QTextStream in(&file);
        minute = 0;
        while (!in.atEnd())
        {
            QString line1 = in.readLine();
            QString line2 = in.readLine();
            sluzba d(line1, line2.toInt());
            faktura.push_back(d);
            minute += line2.toInt();
            f++;
        }
        file.close();
    }
    if (f == 0) return;
    else {
        for (int j = 0; j < f; j++) {
            QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget_2);
            item->setText(0, QString("%1").arg(faktura[j].slu()));
            QTreeWidgetItem* item2 = new QTreeWidgetItem(ui->treeWidget_2);
            item2->setText(1, QString("%1").arg(faktura[j].c()));
            item->addChild(item2);
        }
        ui->lineEdit_3->setText(QString("%1").arg(minute));
    }
   
}
void autoservis::vytvorenie_faktury()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        "Save file", "", tr("Txt file(*.txt);;All files (*.)"));

    if (fileName.isEmpty()) { return; }

    QFileInfo fi(fileName);
    if (fi.suffix() == "txt") {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
        QTextStream out(&file);
        if (type == 1) {
            out << fir[index].getNazov() << "\n";
        }
        if (type == 2) {
            out << fyz[index].getName() << "\n";
        }
        for (size_t i = 0; i < faktura.length(); i++)
        {
            out << faktura[i].slu() << "\n";
            out << faktura[i].c() << "\n";
            out << "\n";
        }
        out << minute;
        file.close();
    }

}
void autoservis::ulozenie_nakupu()
{
    QString fileName;
    if (type == 1) {
        fileName = fir[index].getName() + "f" + ".txt";
    }
    else if (type == 2) {
        fileName = fyz[index].getName() + "f" + ".txt";
    }
    else return;

    if (fileName.isEmpty()) { return; }

    QFileInfo fi(fileName);
    if (fi.suffix() == "txt") {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
        QTextStream out(&file);
        
        for (size_t i = 0; i < faktura.length(); i++)
        {
            out << faktura[i].slu() << "\n";
            out << faktura[i].c() << "\n";
        }
        file.close();
    }
}
void autoservis::usertable() {
    int pocet = ad + fr + fy + za;
    ui->tableWidget->setRowCount(pocet);
    ui->tableWidget->setColumnCount(9);
    int row = 0;
    for (int i = 0; i < ad; i++) {
        QTableWidgetItem* item = new QTableWidgetItem();
        QTableWidgetItem* item2 = new QTableWidgetItem();
        QTableWidgetItem* item3 = new QTableWidgetItem();
        QTableWidgetItem* item4 = new QTableWidgetItem();
        QTableWidgetItem* item5 = new QTableWidgetItem();
        QTableWidgetItem* item6 = new QTableWidgetItem();
        QTableWidgetItem* item7 = new QTableWidgetItem();
        QTableWidgetItem* item8 = new QTableWidgetItem();
        QTableWidgetItem* item9 = new QTableWidgetItem();
        item->setText(a[i].getName());
        item2->setText(a[i].getHeslo());
        item3->setText("-");
        item4->setText("-");
        item5->setText("-");
        item6->setText("-");
        item7->setText("-");
        item8->setText("-");
        item9->setText("-");
        ui->tableWidget->setItem(row, 0, item);
        ui->tableWidget->setItem(row, 1, item2);
        ui->tableWidget->setItem(row, 2, item3);
        ui->tableWidget->setItem(row, 3, item4);
        ui->tableWidget->setItem(row, 4, item5);
        ui->tableWidget->setItem(row, 5, item6);
        ui->tableWidget->setItem(row, 6, item7);
        ui->tableWidget->setItem(row, 7, item8);
        ui->tableWidget->setItem(row, 8, item9);
        row++;
    }
    for (int i = 0; i < fr; i++) {
        QTableWidgetItem* item = new QTableWidgetItem();
        QTableWidgetItem* item2 = new QTableWidgetItem();
        QTableWidgetItem* item3 = new QTableWidgetItem();
        QTableWidgetItem* item4 = new QTableWidgetItem();
        QTableWidgetItem* item5 = new QTableWidgetItem();
        QTableWidgetItem* item6 = new QTableWidgetItem();
        QTableWidgetItem* item7 = new QTableWidgetItem();
        QTableWidgetItem* item8 = new QTableWidgetItem();
        QTableWidgetItem* item9 = new QTableWidgetItem();
        item->setText(fir[i].getName());
        item2->setText(fir[i].getHeslo());
        item3->setText(fir[i].getNazov());
        item4->setText(fir[i].getZnacka());
        item5->setText(fir[i].getModel());
        item6->setText(QString("%1").arg(fir[i].getRok()));
        item7->setText(QString("%1").arg(fir[i].getICO()));
        item8->setText(fir[i].getDPH());
        item9->setText("-");
        ui->tableWidget->setItem(row, 0, item);
        ui->tableWidget->setItem(row, 1, item2);
        ui->tableWidget->setItem(row, 2, item3);
        ui->tableWidget->setItem(row, 3, item4);
        ui->tableWidget->setItem(row, 4, item5);
        ui->tableWidget->setItem(row, 5, item6);
        ui->tableWidget->setItem(row, 6, item7);
        ui->tableWidget->setItem(row, 7, item8);
        ui->tableWidget->setItem(row, 8, item9);
        row++;
    }
    for (int i = 0; i < fy; i++) {
        QTableWidgetItem* item = new QTableWidgetItem();
        QTableWidgetItem* item2 = new QTableWidgetItem();
        QTableWidgetItem* item3 = new QTableWidgetItem();
        QTableWidgetItem* item4 = new QTableWidgetItem();
        QTableWidgetItem* item5 = new QTableWidgetItem();
        QTableWidgetItem* item6 = new QTableWidgetItem();
        QTableWidgetItem* item7 = new QTableWidgetItem();
        QTableWidgetItem* item8 = new QTableWidgetItem();
        QTableWidgetItem* item9 = new QTableWidgetItem();
        item->setText(fyz[i].getName());
        item2->setText(fyz[i].getHeslo());
        item3->setText(fyz[i].getMeno());
        item4->setText(fyz[i].getZnacka());
        item5->setText(fyz[i].getModel());
        item6->setText(QString("%1").arg(fyz[i].getRok()));
        item7->setText("-");
        item8->setText("-");
        item9->setText("-");
        ui->tableWidget->setItem(row, 0, item);
        ui->tableWidget->setItem(row, 1, item2);
        ui->tableWidget->setItem(row, 2, item3);
        ui->tableWidget->setItem(row, 3, item4);
        ui->tableWidget->setItem(row, 4, item5);
        ui->tableWidget->setItem(row, 5, item6);
        ui->tableWidget->setItem(row, 6, item7);
        ui->tableWidget->setItem(row, 7, item8);
        ui->tableWidget->setItem(row, 8, item9);
        row++;
    }
    for (int i = 0; i < za; i++) {
        QTableWidgetItem* item = new QTableWidgetItem();
        QTableWidgetItem* item2 = new QTableWidgetItem();
        QTableWidgetItem* item3 = new QTableWidgetItem();
        QTableWidgetItem* item4 = new QTableWidgetItem();
        QTableWidgetItem* item5 = new QTableWidgetItem();
        QTableWidgetItem* item6 = new QTableWidgetItem();
        QTableWidgetItem* item7 = new QTableWidgetItem();
        QTableWidgetItem* item8 = new QTableWidgetItem();
        QTableWidgetItem* item9 = new QTableWidgetItem();
        item->setText(prac[i].getName());
        item2->setText(prac[i].getHeslo());
        item3->setText("-");
        item4->setText("-");
        item5->setText("-");
        item6->setText("-");
        item7->setText("-");
        item8->setText("-");
        item9->setText(prac[i].getPozicia());
        ui->tableWidget->setItem(row, 0, item);
        ui->tableWidget->setItem(row, 1, item2);
        ui->tableWidget->setItem(row, 2, item3);
        ui->tableWidget->setItem(row, 3, item4);
        ui->tableWidget->setItem(row, 4, item5);
        ui->tableWidget->setItem(row, 5, item6);
        ui->tableWidget->setItem(row, 6, item7);
        ui->tableWidget->setItem(row, 7, item8);
        ui->tableWidget->setItem(row, 8, item9);
        row++;
    }
}

void autoservis::on_pushButton_5_clicked() {
    Newuser* m = new Newuser();
    m->exec();
    a.clear();
    fir.clear();
    fyz.clear();
    prac.clear();
    ad = 0;
    fr = 0;
    fy = 0;
    za = 0;
    nacitanie_admin();
    nacitanie_firma();
    nacitanie_osoba();
    nacitanie_pracovnik();
    ui->tableWidget->clearContents();
    usertable();
}
void autoservis::on_pushButton_2_clicked() {
    QString a = ui->treeWidget->currentItem()->text(0);
    for (size_t i = 0; i < b; i++)
    {
        if (a == p[i].slu()) {
            if (type == 1 && fir[index].getDPH() == "ano") {
                p[i].changec(0.8);
            }
            minute += p[i].c();

            faktura.push_back(p[i]);
            ui->lineEdit_3->setText(QString("%1").arg(minute));
            QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget_2);
            item->setText(0, QString("%1").arg(p[i].slu()));
            QTreeWidgetItem* item2 = new QTreeWidgetItem(ui->treeWidget_2);
            if (type == 1) {
                item2->setText(1, QString("%1").arg(p[i].c()));
            }
            else item2->setText(1, QString("%1").arg(p[i].c()));
            item->addChild(item2);
            f++;
        }
    }
}
void autoservis::on_pushButton_7_clicked() {
    ui->treeWidget->clear();
    QString fileName = QFileDialog::getOpenFileName(this,
        "Open file", "", tr("Txt file(*.txt);;All files (*.)"));
    QString fileName2 = "sluzby.txt";
    if (fileName.isEmpty()) { return; }
    if (fileName2.isEmpty()) { return; }
    QFileInfo fi(fileName);
    if (fi.suffix() == "txt") {
        QFile file(fileName);
        QFile file2(fileName2);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
        if (!file2.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
        QTextStream in(&file);
        QTextStream out(&file2);
        QString n = in.readLine();
        out << n << "\n";
        b = n.toInt();
        p.clear();
        for (size_t i = 0; i < n.toInt(); i++)
        {
            QString line = in.readLine();
            QString line1 = in.readLine();
            QString line2 = in.readLine();
            sluzba a(line1, line2.toInt());
            p.push_back(a);
            out << line << "\n";
            out << line1 << "\n";
            out << line2 << "\n";
        }
        file2.close();
        file.close();
    }
    for (int j = 0; j < b; j++) {
        QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget);
        item->setText(0, QString("%1").arg(p[j].slu()));
        QTreeWidgetItem* item2 = new QTreeWidgetItem(ui->treeWidget);
        item2->setText(1, QString("%1").arg(p[j].c()));
        item->addChild(item2);
    }
}
void autoservis::on_pushButton_4_clicked()
{
    for (int i = 0; i < fr; i++) {
        if (ui->lineEdit_2->text() == fir[i].getName()) {
            type = 1;
            index = i;
        }
    }
    for (int i = 0; i < fy; i++) {
        if (ui->lineEdit_2->text() == fyz[i].getName()) {
            type = 2;
            index = i;
        }
    }
    nacitanie_faktury();
}
void autoservis::on_pushButton_9_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        "Save file", "", tr("Txt file(*.txt);;All files (*.)"));

    if (fileName.isEmpty()) { return; }

    QFileInfo fi(fileName);
    if (fi.suffix() == "txt") {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
        QTextStream out(&file);
        if (type == 1) {
            QString fileName2 = fir[index].getName() + "f" + ".txt";
            QFile file2(fileName2);
            file2.remove();
            out << fir[index].getNazov() << "\n";
            out << "\n";
        }
        if (type == 2) {
            QString fileName2 = fyz[index].getName() + "f" + ".txt";
            QFile file2(fileName2);
            file2.remove();
            out << fyz[index].getName() << "\n";
            out << "\n";
        }
        for (size_t i = 0; i < faktura.length(); i++)
        {
            out << faktura[i].slu() << "\n";
            out << faktura[i].c() << "\n";
            out << "\n";
        }
        out << "celkova suma:" << minute;
        file.close();
    }
    faktura.clear();
    ui->treeWidget_2->clear();
    ui->lineEdit_3->clear();
}
void autoservis::on_pushButton_6_clicked()
{
    if (type == 1) {
        fir[index].setNazov(ui->lineEdit_11->text());
        fir[index].setZnacka(ui->lineEdit_4->text());
        fir[index].setModel(ui->lineEdit_10->text());
        fir[index].setRok(ui->lineEdit_9->text().toInt());
        fir[index].setICO(ui->lineEdit_8->text().toInt());
        fir[index].setDPH(ui->lineEdit_7->text());
        zapis_firma();
    }
    if (type == 2) {
        fyz[index].setMeno(ui->lineEdit_11->text());
        fyz[index].setZnacka(ui->lineEdit_4->text());
        fyz[index].setModel(ui->lineEdit_10->text());
        fyz[index].setRok(ui->lineEdit_9->text().toInt());
        zapis_osoba();
    }
    if (type == 3) {
        prac[index].setPozicia(ui->lineEdit_6->text());
        zapis_pracovnik();
    }
}
void autoservis::on_pushButton_8_clicked()
{
    int row = 0;
    for (int i = 0; i < ad; i++) {
        QTableWidgetItem* Item = ui->tableWidget->item(row, 0);
        QTableWidgetItem* Item2 = ui->tableWidget->item(row, 1);
        QString name = Item->text();
        QString heslo = Item2->text();
        QString sifra = QString(QCryptographicHash::hash(heslo.toStdString().c_str(), QCryptographicHash::Md4).toHex());
        
        a[i].setName(name);
        if (heslo == a[i].getHeslo()) {
            a[i].setHeslo(heslo);
        }
        else a[i].setHeslo(sifra);
        row++;
    }
    zapis_admin();
    for (int i = 0; i < fr; i++) {
        QTableWidgetItem* Item = ui->tableWidget->item(row, 0);
        QTableWidgetItem* Item2 = ui->tableWidget->item(row, 1);
        QTableWidgetItem* Item3 = ui->tableWidget->item(row, 2);
        QTableWidgetItem* Item4 = ui->tableWidget->item(row, 3);
        QTableWidgetItem* Item5 = ui->tableWidget->item(row, 4);
        QTableWidgetItem* Item6 = ui->tableWidget->item(row, 5);
        QTableWidgetItem* Item7 = ui->tableWidget->item(row, 6);
        QTableWidgetItem* Item8 = ui->tableWidget->item(row, 7);
        QString name = Item->text();
        QString heslo = Item2->text();
        QString meno = Item3->text();
        QString znacka = Item4->text();
        QString model = Item5->text();
        int rok = Item6->text().toInt();
        int ICO = Item7->text().toInt();
        QString DPH = Item8->text();
        QString sifra = QString(QCryptographicHash::hash(heslo.toStdString().c_str(), QCryptographicHash::Md4).toHex());
        fir[i].setName(name);
        if (heslo == fir[i].getHeslo()) {
            fir[i].setHeslo(heslo);
        }
        else fir[i].setHeslo(sifra);
        fir[i].setNazov(meno);
        fir[i].setZnacka(znacka);
        fir[i].setModel(model);
        fir[i].setRok(rok);
        fir[i].setICO(ICO);
        fir[i].setDPH(DPH);
        row++;
    }
    zapis_firma();
    for (int i = 0; i < fy; i++) {
        QTableWidgetItem* Item = ui->tableWidget->item(row, 0);
        QTableWidgetItem* Item2 = ui->tableWidget->item(row, 1);
        QTableWidgetItem* Item3 = ui->tableWidget->item(row, 2);
        QTableWidgetItem* Item4 = ui->tableWidget->item(row, 3);
        QTableWidgetItem* Item5 = ui->tableWidget->item(row, 4);
        QTableWidgetItem* Item6 = ui->tableWidget->item(row, 5);
        QString name = Item->text();
        QString heslo = Item2->text();
        QString meno = Item3->text();
        QString znacka = Item4->text();
        QString model = Item5->text();
        int rok = Item6->text().toInt();
        QString sifra = QString(QCryptographicHash::hash(heslo.toStdString().c_str(), QCryptographicHash::Md4).toHex());
        fyz[i].setName(name);
        if (heslo == fyz[i].getHeslo()) {
            fyz[i].setHeslo(heslo);
        }
        else fyz[i].setHeslo(sifra);
        fyz[i].setMeno(meno);
        fyz[i].setZnacka(znacka);
        fyz[i].setModel(model);
        fyz[i].setRok(rok);
        row++;
    }
    zapis_osoba();
    for (int i = 0; i < za; i++) {
        QTableWidgetItem* Item = ui->tableWidget->item(row, 0);
        QTableWidgetItem* Item2 = ui->tableWidget->item(row, 1);
        QTableWidgetItem* Item3 = ui->tableWidget->item(row, 8);
        QString name = Item->text();
        QString heslo = Item2->text();
        QString meno = Item3->text();
        QString sifra = QString(QCryptographicHash::hash(heslo.toStdString().c_str(), QCryptographicHash::Md4).toHex());
        prac[i].setName(name);
        if (heslo == prac[i].getHeslo()) {
            prac[i].setHeslo(heslo);
        }
        else prac[i].setHeslo(sifra);
        prac[i].setPozicia(meno);
        row++;
    }
    zapis_pracovnik();
}
void autoservis::on_pushButton_10_clicked()
{
    QString del = ui->tableWidget->currentItem()->text();
    for (int i = 0; i < ad; i++) {
        if (del == a[i].getName()) {
            a.remove(i);
            a.shrink_to_fit();
            ad--;
        }
    }
    for (int i = 0; i < fy; i++) {
        if (del == fyz[i].getName()) {
            fyz.remove(i);
            fyz.shrink_to_fit();
            fy--;
        }
    }
    for (int i = 0; i < fr; i++) {
        if (del == fir[i].getName()) {
            fir.remove(i);
            fir.shrink_to_fit();
            fr--;
        }
    }
    for (int i = 0; i < za; i++) {
        if (del == prac[i].getName()) {
            prac.remove(i);
            prac.shrink_to_fit();
            za--;
        }
    }
    usertable();
}

void autoservis::on_pushButton_3_clicked() {
    QString a = ui->treeWidget_2->currentItem()->text(0);
    for (size_t i = 0; i < f; i++)
    {
        if (a == faktura[i].slu()) {
            minute -= faktura[i].c();
            faktura.remove(i);
            faktura.shrink_to_fit();
            ui->lineEdit_3->setText(QString("%1").arg(minute));
            ui->treeWidget_2->clear();
            for (int j = 0; j < faktura.length(); j++) {
                QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget_2);
                item->setText(0, QString("%1").arg(faktura[j].slu()));
                QTreeWidgetItem* item2 = new QTreeWidgetItem(ui->treeWidget_2);
                item2->setText(1, QString("%1").arg(faktura[j].c()));
                item->addChild(item2);
            }
            ui->lineEdit_3->setText(QString("%1").arg(minute));
            f--;
        }
    }
}
void autoservis::on_pushButton_clicked() {
    ulozenie_nakupu();
    close();
    autoservis* n = new autoservis;
    n->show();
}

void Newuser::on_comboBox_currentIndexChanged(int index) {
    if (ui3->comboBox->currentIndex() == 0) {
        ui3->groupBox_2->setVisible(true);
        ui3->groupBox_3->setVisible(true);
        ui3->groupBox_4->setVisible(false);
        ui3->groupBox_5->setVisible(false);
        ui3->groupBox_6->setVisible(false);
        ui3->groupBox_7->setVisible(false);
        ui3->groupBox_8->setVisible(false);
        ui3->groupBox_9->setVisible(false);
        ui3->groupBox_10->setVisible(false);
    }
    if (ui3->comboBox->currentIndex() == 1) {
        ui3->groupBox_2->setVisible(true);
        ui3->groupBox_3->setVisible(true);
        ui3->groupBox_4->setVisible(true);
        ui3->groupBox_5->setVisible(true);
        ui3->groupBox_6->setVisible(true);
        ui3->groupBox_7->setVisible(true);
        ui3->groupBox_8->setVisible(true);
        ui3->groupBox_9->setVisible(true);
        ui3->groupBox_10->setVisible(false);
    }
    if (ui3->comboBox->currentIndex() == 2) {
        ui3->groupBox_2->setVisible(true);
        ui3->groupBox_3->setVisible(true);
        ui3->groupBox_4->setVisible(true);
        ui3->groupBox_5->setVisible(true);
        ui3->groupBox_6->setVisible(true);
        ui3->groupBox_7->setVisible(true);
        ui3->groupBox_8->setVisible(false);
        ui3->groupBox_9->setVisible(false);
        ui3->groupBox_10->setVisible(false);
    }
    if (ui3->comboBox->currentIndex() == 3) {
        ui3->groupBox_2->setVisible(true);
        ui3->groupBox_3->setVisible(true);
        ui3->groupBox_4->setVisible(false);
        ui3->groupBox_5->setVisible(false);
        ui3->groupBox_6->setVisible(false);
        ui3->groupBox_7->setVisible(false);
        ui3->groupBox_8->setVisible(false);
        ui3->groupBox_9->setVisible(false);
        ui3->groupBox_10->setVisible(true);
    }

}
void Newuser::on_pushButton_clicked() {
    std::fstream myfile;
        if (ui3->comboBox->currentIndex() == 0) {
            myfile.open("admin.txt", std::ios::out | std::ios::app);
            if (myfile.is_open()) {
                myfile << ui3->lineEdit->text().toStdString() << std::endl;
                std::string sifra = QCryptographicHash::hash(ui3->lineEdit_2->text().toStdString().c_str(), QCryptographicHash::Md4).toHex();
                myfile << sifra << std::endl;
                myfile << std::endl;
            }
            myfile.close();
        }
        if (ui3->comboBox->currentIndex() == 1) {
            myfile.open("firma.txt", std::ios::out | std::ios::app);
            if (myfile.is_open()) {
                myfile << ui3->lineEdit->text().toStdString() << std::endl;
                std::string sifra = QCryptographicHash::hash(ui3->lineEdit_2->text().toStdString().c_str(), QCryptographicHash::Md4).toHex();
                myfile << sifra << std::endl;
                myfile << ui3->lineEdit_3->text().toStdString() << std::endl;
                myfile << ui3->lineEdit_4->text().toStdString() << std::endl;
                myfile << ui3->lineEdit_5->text().toStdString() << std::endl;
                myfile << ui3->lineEdit_6->text().toStdString() << std::endl;
                myfile << ui3->lineEdit_7->text().toStdString() << std::endl;
                myfile << ui3->lineEdit_8->text().toStdString() << std::endl;
                myfile << std::endl;
            }
            myfile.close();
        }
        if (ui3->comboBox->currentIndex() == 2) {
            myfile.open("osoba.txt", std::ios::out | std::ios::app);
            if (myfile.is_open()) {
                myfile << ui3->lineEdit->text().toStdString() << std::endl;
                std::string sifra = QCryptographicHash::hash(ui3->lineEdit_2->text().toStdString().c_str(), QCryptographicHash::Md4).toHex();
                myfile << sifra << std::endl;
                myfile << ui3->lineEdit_3->text().toStdString() << std::endl;
                myfile << ui3->lineEdit_4->text().toStdString() << std::endl;
                myfile << ui3->lineEdit_5->text().toStdString() << std::endl;
                myfile << ui3->lineEdit_6->text().toStdString() << std::endl;
                myfile << std::endl;
            }
            myfile.close();
        }
        if (ui3->comboBox->currentIndex() == 3) {
            myfile.open("zamestnanec.txt", std::ios::out | std::ios::app);
            if (myfile.is_open()) {
                myfile << ui3->lineEdit->text().toStdString() << std::endl;
                std::string sifra = QCryptographicHash::hash(ui3->lineEdit_2->text().toStdString().c_str(), QCryptographicHash::Md4).toHex();
                myfile << sifra << std::endl;
                myfile << ui3->lineEdit_9->text().toStdString() << std::endl;
                myfile << std::endl;
            }
            myfile.close();
        }
  
    close();
}
