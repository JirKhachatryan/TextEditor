#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QString>

namespace Ui {
class FileManager;
}

class FileManager : public QDialog
{
    Q_OBJECT

public:
    explicit FileManager(QWidget *parent = nullptr);
    ~FileManager();
public slots:
    void openFile();
signals:
    void openF(QString);
private:
    QLineEdit* fileDir;
    Ui::FileManager *ui;
};

#endif // FILEMANAGER_H
