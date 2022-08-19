/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Prihlasenie
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *comboBox;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;

    void setupUi(QDialog *Prihlasenie)
    {
        if (Prihlasenie->objectName().isEmpty())
            Prihlasenie->setObjectName(QString::fromUtf8("Prihlasenie"));
        Prihlasenie->resize(400, 292);
        Prihlasenie->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 247, 238)"));
        buttonBox = new QDialogButtonBox(Prihlasenie);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(20, 230, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(Prihlasenie);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(40, 10, 341, 191));
        groupBox->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 188, 133)"));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        comboBox = new QComboBox(groupBox_4);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_3->addWidget(comboBox);


        verticalLayout->addWidget(groupBox_4);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(groupBox_3);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout->addWidget(groupBox_3);


        retranslateUi(Prihlasenie);
        QObject::connect(buttonBox, SIGNAL(rejected()), Prihlasenie, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), Prihlasenie, SLOT(accept()));

        comboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Prihlasenie);
    } // setupUi

    void retranslateUi(QDialog *Prihlasenie)
    {
        Prihlasenie->setWindowTitle(QCoreApplication::translate("Prihlasenie", "Prihlasovanie", nullptr));
        groupBox->setTitle(QString());
        groupBox_4->setTitle(QString());
        label_3->setText(QCoreApplication::translate("Prihlasenie", "Typ:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Prihlasenie", "Admin", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Prihlasenie", "Firma", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Prihlasenie", "Fyzick\303\241 osoba", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Prihlasenie", "Zamestnanec", nullptr));

        comboBox->setCurrentText(QCoreApplication::translate("Prihlasenie", "Admin", nullptr));
        groupBox_2->setTitle(QString());
        label->setText(QCoreApplication::translate("Prihlasenie", "Meno:", nullptr));
        groupBox_3->setTitle(QString());
        label_2->setText(QCoreApplication::translate("Prihlasenie", "Heslo:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Prihlasenie: public Ui_Prihlasenie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
