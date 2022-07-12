#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "httpbase/qhttpserver.h"
#include "httpbase/qhttprequest.h"
#include "httpbase/qhttpresponse.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void updateRecvInfoSlot(QJsonObject recv_obj);

private slots:
    void on_pbStart_clicked();
private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
