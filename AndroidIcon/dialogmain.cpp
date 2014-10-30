#include "dialogmain.h"
#include "ui_dialogmain.h"

#include "PublicDialog/publicdialog.h"
#include <QFileDialog>
#include <QDesktopServices>
#include <QDebug>
DialogMain::DialogMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DialogMain)
{
    ui->setupUi(this);
    ui->pushButton_2->setEnabled(false);
    doPriviewIcon(":/Resource/Image/icon.png");
}

DialogMain::~DialogMain()
{
    delete ui;
}

void DialogMain::doPriviewIcon(const QString &path)
{
    QImage icon;
    icon.load(path);

    ui->label_036x036->setPixmap(QPixmap().fromImage(icon.scaled(36, 36)));
    ui->label_048x048->setPixmap(QPixmap().fromImage(icon.scaled(48, 48)));
    ui->label_072x072->setPixmap(QPixmap().fromImage(icon.scaled(72, 72)));
    ui->label_096x096->setPixmap(QPixmap().fromImage(icon.scaled(96, 96)));
    ui->label_144x144->setPixmap(QPixmap().fromImage(icon.scaled(144, 144)));
}

void DialogMain::on_pushButton_clicked()
{
    QFileDialog fFileDialog(this);
    fFileDialog.setWindowTitle(tr("选择图片文件"));
    fFileDialog.setNameFilter( tr("Image Files(*.png)") );
    fFileDialog.setWindowModality(Qt::WindowModal);
    if (fFileDialog.exec() == QDialog::Accepted)
    {
        m_qsSelectFile = fFileDialog.selectedFiles()[0];
        doPriviewIcon(m_qsSelectFile);
        ui->pushButton_2->setEnabled(true);
    }
}

void DialogMain::on_pushButton_2_clicked()
{
    auto doScaledImage = [](int w, int h,const QImage& icon, const QString& output, const QString& name )
    {
        QDir().mkpath(output);
        icon.scaled(w, h).save(output + name);
    };

    QString qsIconName = QInputDialogEx::getText(this, "图标名称", "请输入图标名称：", QLineEdit::Normal, "icon.png");
    if ( !qsIconName.isEmpty() )
    {
        QFileDialog openFilePath( this, " 请选择文件夹", "file");
        openFilePath.setFileMode( QFileDialog::DirectoryOnly );
        openFilePath.setWindowModality(Qt::WindowModal);
        if (openFilePath.exec() == QDialog::Accepted)
        {
            QImage icon;
            icon.load(m_qsSelectFile);

            QString qsSavePaht = openFilePath.selectedFiles()[0];
            doScaledImage(36 , 36 , icon, qsSavePaht + "/drawable-ldpi/"  , qsIconName);
            doScaledImage(48 , 48 , icon, qsSavePaht + "/drawable-mdpi/"  , qsIconName);
            doScaledImage(72 , 72 , icon, qsSavePaht + "/drawable-hdpi/"  , qsIconName);
            doScaledImage(96 , 96 , icon, qsSavePaht + "/drawable-xhdpi/" , qsIconName);
            doScaledImage(144, 144, icon, qsSavePaht + "/drawable-xxhdpi/", qsIconName);
        }
    }
}

void DialogMain::on_action_About_triggered()
{
    QMessageBoxEx::noIcon(this, tr("关于"),tr("<center><h2>AndroidIcon</h2><h5><br/>Copyright &copy; <a href='http://www.sollyu.com'>Sollyu</a> 2014-10-30 <br/>Version 1.01</h5></center>"));
}

void DialogMain::on_action_Help_triggered()
{
    QDesktopServices::openUrl(QUrl("http://www.sollyu.com/AndroidIcon/"));
}
