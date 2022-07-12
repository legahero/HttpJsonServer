#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegExp>
#include <QStringList>
#include <qsql.h>
#include <qsqldatabase.h>

/*
 * QDB2，IBM DB2 7.1 以上的数据库版本
    QIBASE，Borland InterBase
    QMYSQL，MySQL
    QOCI，Qracel
    QODBC，ODBC，包括 Microsoft SQL Server
    QPSQL，PostgreSQL 7.3 及以上版本
    QSQLITE，SQLite 3
    QSQLITE2，SQLite 2
    QTDS，Sybase Adaptive Server
 */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->teLog->append("系统支持以下数据库:");
    QStringList drivers=QSqlDatabase::drivers();
    foreach(QString driver,drivers)
    {
        ui->teLog->append(driver);
    }

    /*
    QSqlDatabase db = QSqlDatabase::addDatabase("QOCI");
    db.setHostName("112.124.60.199");
    db.setDatabaseName("orcl");
    db.setUserName("szxf");
    db.setPassword("Zdst1234");

    if (!db.open())
    {
        QMessageBox::information(this, tr("提示"), tr("Oracle数据库连接失败！"), tr("确定"));
        qDebug() <<"error_Oracle:\n" << db.lastError().text();
    }


    QSqlQuery query;
    QMap<QString,QString> AreaMap;
    query.exec("SELECT AREA_ID,AREA_NAME FROM T_FIREPROOF_AREA");
    while (query.next())
    {
        QString AreaId=query.record().field(0).value().toString();
        QString AreaName=query.record().field(1).value().toString();
        AreaMap[AreaName]=AreaId;
    }
    //QSqlDatabase::database().commit();
    db.close();         //释放数据库连接
    */

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbStart_clicked()
{
    qDebug() << "MainWindow:on_pbStart_clicked,ThreadId:"<<QThread::currentThreadId()  ;

    QHttpServer *server = new QHttpServer(this);
    connect(server, &QHttpServer::updateRecvInfoSlot, this, &MainWindow::updateRecvInfoSlot);
    if(server->listen(QHostAddress::Any, qint16(ui->lePort->text().toInt())))
    {
        ui->teLog->append("http 服务已经启动!");
    }else
    {
        ui->teLog->append("http 服务启动失败!");
    }
}

void MainWindow::updateRecvInfoSlot(QJsonObject recv_obj)
{
    QJsonObject *prm = reinterpret_cast<QJsonObject *>(&recv_obj);
    QJsonObject::const_iterator it = prm->constBegin();
    QJsonObject::const_iterator end = prm->constEnd();

    while (it != end)
    {
        ui->teLog->append(it.key());
        ui->teLog->append(it.value().toVariant().toString());
        it++;
    }
}
