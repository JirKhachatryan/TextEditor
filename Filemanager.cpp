#include "Filemanager.h"
#include "ui_Filemanager.h"

FileManager::FileManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileManager)
{

    QPushButton* ok = new QPushButton(tr("&OK"),this);
    QPushButton* close = new QPushButton(tr("&Close"), this);
    fileDir = new QLineEdit(this);
    QWidget::setFixedSize(300, 50);
    fileDir->resize(300,25);
    ok->resize(100,25);
    ok->move(0,25);
    close->resize(100,25);
    close->move(200,25);

    connect(close, &QPushButton::clicked, this, &QPushButton::close);
    connect(ok, &QPushButton::clicked, this, &FileManager::openFile);
    ui->setupUi(this);
}

void FileManager::openFile() {
    QString path = fileDir->text();
    close();
    emit openF(path);
}


FileManager::~FileManager()
{
    delete ui;
}
