#ifndef PUBLICDIALOG_H
#define PUBLICDIALOG_H

#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>

/**
 * @brief The QMessageBoxEx class
 * MessageBox类. 主要实现了MAC没有窗口特效问题
 */
namespace QMessageBoxEx
{
    int information(QWidget *parent, const QString &title, const QString &text, QMessageBox::StandardButtons buttons = QMessageBox::Ok, QMessageBox::StandardButton defaultButton = QMessageBox::NoButton);
    int question(QWidget *parent, const QString &title, const QString &text, QMessageBox::StandardButtons buttons = QMessageBox::StandardButtons(QMessageBox::Yes | QMessageBox::No), QMessageBox::StandardButton defaultButton = QMessageBox::NoButton);
    int warning(QWidget *parent, const QString &title, const QString &text, QMessageBox::StandardButtons buttons = QMessageBox::Ok, QMessageBox::StandardButton defaultButton = QMessageBox::NoButton);
    int critical(QWidget *parent, const QString &title, const QString &text, QMessageBox::StandardButtons buttons = QMessageBox::Ok, QMessageBox::StandardButton defaultButton = QMessageBox::NoButton);
    int noIcon(QWidget *parent, const QString &title, const QString &text, QMessageBox::StandardButtons buttons = QMessageBox::Ok, QMessageBox::StandardButton defaultButton = QMessageBox::NoButton);
    void aboutQt(QWidget *parent, const QString &title = QString());
}

namespace QInputDialogEx
{
    QString getText(QWidget *parent, const QString &title, const QString &label, QLineEdit::EchoMode echo = QLineEdit::Normal, const QString &text = QString(), Qt::WindowFlags flags = 0, Qt::InputMethodHints inputMethodHints = Qt::ImhNone);
}

namespace QFileDialogEx {
    QString getOpenFileName(QWidget *parent = 0, const QString &caption = QString(), const QString &dir = QString(), const QString &filter = QString(), QFileDialog::Options options = 0);
    QString getSaveFileName(QWidget *parent = 0, const QString &caption = QString(), const QString &dir = QString(), const QString &filter = QString(), QFileDialog::Options options = 0);
}

#endif // PUBLICDIALOG_H
