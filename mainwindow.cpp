#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    tab_count=0;
    adress="0";

    file = menuBar()->addMenu("&File");
    QAction *quit = new QAction("&Exit", this);
    QAction *open = new QAction("&Open", this);
    QAction *save = new QAction("&Save", this);
    QAction *save_as = new QAction("Save as", this);
    QAction *new_file = new QAction("&New File", this);
   // QTabWidget *tab = new QTabWidget();
    file->addAction(new_file);
    file->addAction(open);
    file->addAction(save);
    file->addAction(save_as);
    file->addAction(quit);



    line = new QTextEdit(this);
    line->setGeometry(0, file->geometry().height(), window()->geometry().width(), window()->geometry().height() - file->geometry().height());




    connect(quit, &QAction::triggered, qApp, QApplication::quit);
    connect(open, &QAction::triggered, this, &MainWindow::OpenFileManager);
    connect(save, &QAction::triggered, this, &MainWindow::fileSave);
    connect(new_file, &QAction::triggered, this, &MainWindow::newFile);
    connect(save_as, &QAction::triggered, this, &MainWindow::SaveFileManager);
   // save->setEnabled(0);
}

void MainWindow::newFile(){
    adress="0";
    line->clear();
}

void MainWindow::saveAs(QString adr){
    qDebug() << "Loading...";
    QFile file(adr);
    adress=adr;
    close();
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream(&file);
        stream << line->toPlainText() + "\n";
    }
}


void MainWindow::OpenFileManager() {
    FileManager file;
    file.show();
    connect(&file, &FileManager::openF, this, &MainWindow::readfile);
    //file.setModal(true);
    file.exec();
}

void MainWindow::SaveFileManager() {
    FileManager file;
    file.show();
     connect(&file, &FileManager::openF, this, &MainWindow::saveAs);
     //file.setModal(true);
    file.exec();
}

void MainWindow::readfile(QString adr){
    QFile file(adr);
    if(!file.exists()){
        qDebug() << "Error....";
    }
    else{
      qDebug() << "Loading...";
     MainWindow::adress=adr;
    }

    QString linefile;
    line->clear();

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while (!stream.atEnd()){
            linefile = stream.readLine();
            line->setText(line->toPlainText() + linefile + "\n");
        }
    }
    file.close();
    this->update();
}



void MainWindow::fileSave() {
    if(adress=="0")
    {
        qDebug()<<"Error. txt don't saved";
    }
    else
    {
        QFile file( adress );
        if ( file.open(QIODevice::ReadWrite) )
        {
            QTextStream stream(&file);
            stream << line->toPlainText() + "\n";
        }
    }
}



void MainWindow::resizeEvent(QResizeEvent*)
{
    line->setGeometry(0, file->geometry().height(), window()->geometry().width(), window()->geometry().height() - file->geometry().height());

}

MainWindow::~MainWindow()
{
    delete ui;
}

