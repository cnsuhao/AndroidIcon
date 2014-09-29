#ifndef DIALOGMAIN_H
#define DIALOGMAIN_H

#include <QDialog>

namespace Ui {
class DialogMain;
}

class DialogMain : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMain(QWidget *parent = 0);
    ~DialogMain();

    void doPriviewIcon(const QString& path);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::DialogMain *ui;
    QString         m_qsSelectFile;
};

#endif // DIALOGMAIN_H
