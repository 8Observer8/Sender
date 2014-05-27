#ifndef SENDER_H
#define SENDER_H

#include <QString>
#include <QSerialPort>
#include "PortError.h"

class Sender {
public:

    Sender( QString portName,
            int baudRate = QSerialPort::Baud9600,
            int dataBits = QSerialPort::Data8,
            int parity = QSerialPort::NoParity,
            int stopBits = QSerialPort::OneStop,
            int flowControl = QSerialPort::NoFlowControl ) :
        m_portName( portName ), m_baudRate( baudRate ), m_dataBits( dataBits ),
        m_parity( parity ), m_stopBits( stopBits ), m_flowControl( flowControl )
    {

    }

    void send( const QByteArray &data ) throw( PortError ) {
        m_serialPort.setPortName( m_portName );

        if ( !m_serialPort.open( QIODevice::WriteOnly ) ) {
            throw PortError( m_serialPort.errorString( ).toStdString( ) );
        }

        m_serialPort.setBaudRate( QSerialPort::Baud9600 );
        m_serialPort.setDataBits( QSerialPort::Data8 );
        m_serialPort.setParity( QSerialPort::NoParity );
        m_serialPort.setStopBits( QSerialPort::OneStop );
        m_serialPort.setFlowControl( QSerialPort::NoFlowControl );

        if ( m_serialPort.write( data ) == -1 ) {
            throw PortError( m_serialPort.errorString( ).toStdString( ) );
        }
    }

private:
    QSerialPort m_serialPort;
    QString m_portName;
    int m_baudRate;
    int m_dataBits;
    int m_parity;
    int m_stopBits;
    int m_flowControl;
};

#endif // SENDER_H
