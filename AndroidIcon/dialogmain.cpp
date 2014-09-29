#include "dialogmain.h"
#include "ui_dialogmain.h"

#include <QFileDialog>
#include <QDebug>
DialogMain::DialogMain(QWidget *parent) :
    QDialog(parent),
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

    ui->label_36x36->setPixmap(QPixmap().fromImage(icon.scaled(36, 36)));
    ui->label_48x48->setPixmap(QPixmap().fromImage(icon.scaled(48, 48)));
    ui->label_72x72->setPixmap(QPixmap().fromImage(icon.scaled(72, 72)));
    ui->label_96x96->setPixmap(QPixmap().fromImage(icon.scaled(96, 96)));
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
    auto doScaledImage = [](int w, int h,const QImage& icon, const QString& output, const QString& name = "icon.png" )
    {
        QDir().mkpath(output);
        icon.scaled(w, h).save(output + name);
    };

    QFileDialog openFilePath( this, " 请选择文件夹", "file");
    openFilePath.setFileMode( QFileDialog::DirectoryOnly );
    openFilePath.setWindowModality(Qt::WindowModal);
    if (openFilePath.exec() == QDialog::Accepted)
    {
        QImage icon;
        icon.load(m_qsSelectFile);

        QString qsSavePaht = openFilePath.selectedFiles()[0];
        doScaledImage(36, 36, icon, qsSavePaht + "/drawable-ldpi/");
        doScaledImage(48, 48, icon, qsSavePaht + "/drawable-mdpi/");
        doScaledImage(72, 72, icon, qsSavePaht + "/drawable-hdpi/");
        doScaledImage(96, 96, icon, qsSavePaht + "/drawable-xhdpi/");
    }
}
