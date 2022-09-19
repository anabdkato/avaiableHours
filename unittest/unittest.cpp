#include "fileio.h"

#include <QtTest/QtTest>

class TestFileIO: public QObject
{
    Q_OBJECT

private slots:
    void avaiableHours_data();
    void avaiableHours();
};


void TestFileIO::avaiableHours_data()
{
    QTest::addColumn<QString>("stringHour");
    QTest::addColumn<QString>("stringMinute");
    QTest::addColumn<int>("result");

    QTest::newRow("antes de tudo abrir") << "8" << "59" << 0;
    QTest::newRow("depois de tudo fechar") << "23" << "01" << 0;
    QTest::newRow("quando os primeiros restaurantes abrem") << "9" << "00" << 0;
    QTest::newRow("quando a maior parte dos restaurantes abriu") << "11" << "00" << 0;
    QTest::newRow("quando todos os restaurantes ja estão abertos") << "14" << "30" << 0;
}

void TestFileIO::avaiableHours()
{
    FileIO file;
    QString filePath = "C://Qt//ADITUM//final//restaurant_hours.csv";

    QFETCH(QString, stringHour);
    QFETCH(QString, stringMinute);
    QFETCH(int, result);

    QCOMPARE(file.avaiableHours(filePath, stringHour, stringMinute).length(), result);
}

QTEST_MAIN(TestFileIO)

