#include "serialportreader.h"
#include <iomanip>      // std::setprecision
#include <QCoreApplication>
#include <stdlib.h>     /* atof */
#include <iostream>
#include <stdio.h>
#include <iostream>
#include <vector>

 int i = 0;
 std::vector<int> myvector (i);

SerialPortReader::SerialPortReader(QSerialPort *serialPort, QObject *parent) :
    QObject(parent),
    m_serialPort(serialPort),
    m_standardOutput(stdout)
{
    connect(m_serialPort, &QSerialPort::readyRead, this, &SerialPortReader::handleReadyRead);
}

void SerialPortReader::handleReadyRead()
{
    m_readData.append(m_serialPort->readAll());
    double value=0;
    QString payload;

    if (pp.payload(&m_readData,&payload))
    {
        do {
         myvector.push_back (value);
        } while (value);
        std::cout << "My vector stores " << int(myvector.size()) << " numbers.\n";
        value = payload.toDouble();
        std::cout << " This cycle produced: " << value << " watts." << std::endl;
    }

}


