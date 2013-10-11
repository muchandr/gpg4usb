#include "qmlpage.h"
#include <QtDeclarative/QDeclarativeView>
#include <QVBoxLayout>
#include <QDebug>
#include <QDeclarativeContext>


QMLPage::QMLPage(const QString qmlfile, QWidget *parent) :
    QWidget(parent)
{

    // http://harmattan-dev.nokia.com/docs/library/html/qt4/qml-integration.html
    QDeclarativeView *qmlView = new QDeclarativeView;
    qmlView->setSource(QUrl::fromLocalFile("keydetails.qml"));

    QDeclarativeContext *context = qmlView->rootContext();
    context->setContextProperty("var1", "derText");

    qDebug() << "qml:::::" << QUrl::fromLocalFile("keydetails.qml");


    //QWidget *widget = myExistingWidget();
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(qmlView);
}