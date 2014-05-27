#include "Dialog.h"
#include "ui_Dialog.h"
#include <QSerialPort>
#include <QMessageBox>
#include "Sender.h"
#include "PortError.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_sendPushButton_clicked()
{
    Sender sender( ui->portNameComboBox->currentText( ) );
    QByteArray data;
    data.append( ui->byteSpinBox->value( ) );
    try {
        sender.send( data );
    } catch( const PortError &e ) {
        QMessageBox::critical( this, "Error", QString( e.what( ) ) );
        return;
    } catch( ... ) {
        QMessageBox::critical( this, "Error", "Error: unknown exception" );
        return;
    }
}
