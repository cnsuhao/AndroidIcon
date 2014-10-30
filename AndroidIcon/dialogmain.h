#ifndef DIALOGMAIN_H
#define DIALOGMAIN_H

#include <QMenuBar>
#include <QMainWindow>

namespace Ui {
class DialogMain;
}

class DialogMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit DialogMain(QWidget *parent = 0);
    ~DialogMain();

    void doPriviewIcon(const QString& path);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_action_About_triggered();

    void on_action_Help_triggered();

private:
    Ui::DialogMain *ui;
    QString         m_qsSelectFile;
};

#endif // DIALOGMAIN_H
