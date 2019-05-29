#include "serialportreader.h"
#include <QCoreApplication>
#include <QSerialPort>
#include <QStringList>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream standardOutput(stdout);
    QSerialPort serialPort;
    const QString serialPortName = "COM4";

    serialPort.setPortName(serialPortName);
    serialPort.setBaudRate(9600);



    if (!serialPort.open(QIODevice::ReadOnly)) {
        standardOutput << QObject::tr("Failed to open port %1, error: %2")
                          .arg(serialPortName)
                          .arg(serialPort.errorString())
                       << endl;
        return 1;
    }

    SerialPortReader serialPortReader(&serialPort);

    return a.exec();
}
