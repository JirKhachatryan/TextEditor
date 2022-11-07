#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QString>
#include <QPushButton>
#include <QTextEdit>
#include <QFile>

#include "Filemanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int tab_count;
    QString adress;



public slots:
    void fileSave();
    void readfile(QString);
    void newFile();
    void saveAs(QString);
    void OpenFileManager();
    void SaveFileManager();

private:
    void resizeEvent(QResizeEvent*);
    QTextEdit* line;

    QMenu *file;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
