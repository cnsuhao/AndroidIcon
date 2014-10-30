#include "publicdialog.h"

int QMessageBoxEx::information(QWidget *parent, const QString &title, const QString &text, QMessageBox::StandardButtons buttons, QMessageBox::StandardButton defaultButton)
{
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setParent(parent);
    msgBox.setWindowTitle(title);
    msgBox.setText(text);
    msgBox.setStandardButtons(buttons);
    msgBox.setDefaultButton(defaultButton);
    msgBox.setWindowModality(Qt::WindowModal);
    return msgBox.exec();
}

int QMessageBoxEx::question(QWidget *parent, const QString &title, const QString &text, QMessageBox::StandardButtons buttons, QMessageBox::StandardButton defaultButton)
{
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setParent(parent);
    msgBox.setWindowTitle(title);
    msgBox.setText(text);
    msgBox.setStandardButtons(buttons);
    msgBox.setDefaultButton(defaultButton);
    msgBox.setWindowModality(Qt::WindowModal);
    return msgBox.exec();
}

int QMessageBoxEx::warning(QWidget *parent, const QString &title, const QString &text, QMessageBox::StandardButtons buttons, QMessageBox::StandardButton defaultButton)
{
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setParent(parent);
    msgBox.setWindowTitle(title);
    msgBox.setText(text);
    msgBox.setStandardButtons(buttons);
    msgBox.setDefaultButton(defaultButton);
    msgBox.setWindowModality(Qt::WindowModal);
    return msgBox.exec();
}

int QMessageBoxEx::critical(QWidget *parent, const QString &title, const QString &text, QMessageBox::StandardButtons buttons, QMessageBox::StandardButton defaultButton)
{
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setParent(parent);
    msgBox.setWindowTitle(title);
    msgBox.setText(text);
    msgBox.setStandardButtons(buttons);
    msgBox.setDefaultButton(defaultButton);
    msgBox.setWindowModality(Qt::WindowModal);
    return msgBox.exec();
}

int QMessageBoxEx::noIcon(QWidget *parent, const QString &title, const QString &text, QMessageBox::StandardButtons buttons, QMessageBox::StandardButton defaultButton)
{
    QMessageBox msgBox;
    msgBox.setParent(parent);
    msgBox.setWindowTitle(title);
    msgBox.setText(text);
    msgBox.setStandardButtons(buttons);
    msgBox.setDefaultButton(defaultButton);
    msgBox.setWindowModality(Qt::WindowModal);
    return msgBox.exec();
}

void QMessageBoxEx::aboutQt(QWidget *parent, const QString &title)
{
    QMessageBox msgBox(parent);
    msgBox.setWindowModality(Qt::WindowModal);
    return msgBox.aboutQt(parent, title);
}

QString QInputDialogEx::getText(QWidget *parent, const QString &title, const QString &label, QLineEdit::EchoMode echo, const QString &text, Qt::WindowFlags flags, Qt::InputMethodHints inputMethodHints)
{
    QInputDialog inputDialog(parent, flags);
    inputDialog.setWindowModality(Qt::WindowModal);
    inputDialog.setWindowTitle(title);
    inputDialog.setLabelText(label);
    inputDialog.setTextEchoMode(echo);
    inputDialog.setTextValue(text);
    inputDialog.setInputMethodHints(inputMethodHints);
    if ( inputDialog.exec() == QDialog::Accepted )
        return inputDialog.textValue();
    else
        return NULL;
}


QString QFileDialogEx::getOpenFileName(QWidget *parent, const QString &caption, const QString &dir, const QString &filter, QFileDialog::Options options)
{
    QFileDialog fFileDialog(parent, caption, dir, filter);
    fFileDialog.setWindowModality(Qt::WindowModal);
    fFileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fFileDialog.setOptions(options);
    if (fFileDialog.exec() == QDialog::Accepted)
        return fFileDialog.selectedFiles()[0];
    else
        return NULL;
}


QString QFileDialogEx::getSaveFileName(QWidget *parent, const QString &caption, const QString &dir, const QString &filter, QFileDialog::Options options)
{
    QFileDialog fFileDialog(parent, caption, dir, filter);
    fFileDialog.setWindowModality(Qt::WindowModal);
    fFileDialog.setOptions(options);
    fFileDialog.setAcceptMode(QFileDialog::AcceptSave);
    if (fFileDialog.exec() == QDialog::Accepted)
        return fFileDialog.selectedFiles()[0];
    else
        return NULL;
}
