#include "fileio.h"
#include <QFile>
#include <QTextStream>

FileIO::FileIO(QObject *parent) :
    QObject(parent)
{

}

QStringList FileIO::avaiableHours(QString source, QString hour, QString minute)
{
    QFile file(source);

    int hora = (hour.toInt() * 100) + minute.toInt();                                      //transforma hora inserida em número para comparação
    int iHoraAbertura;
    int iHoraFechamento;

    QString horarios;

    QString restaurante;
    QString abertura;
    QString horaAbertura;
    QString minutoAbertura;
    QString fechamento;
    QString horaFechamento;
    QString minutoFechamento;
    QStringList lista;

    if ( file.open(QIODevice::ReadOnly) ) {
        QString line;
        QTextStream t( &file );
        do {
            line = t.readLine();                                                            //le linha do arquivo

            restaurante = line.split(',').first().mid(1, horarios.length() - 2);            //nome do restaurante sem aspas

            horarios = line.split(',').last();
            horarios = horarios.mid(1, horarios.length() - 2);                              //horarios de funcionamento sem aspas

            abertura = horarios.split('-').first();                                         //separa os horários de abertura
            horaAbertura = abertura.split(':').first();
            minutoAbertura = abertura.split(':').last();                                    //separa horários de abertura em hora e minuto

            fechamento = horarios.split('-').last();                                        //separa os horarios de fechamento
            horaFechamento = fechamento.split(':').first();
            minutoFechamento = fechamento.split(':').last();                                //separa horários de fechamento em hora e minuto

            iHoraAbertura = (horaAbertura.toInt() * 100) + minutoAbertura.toInt();          //transforma horarios em número para comparação
            iHoraFechamento = (horaFechamento.toInt() * 100) + minutoFechamento.toInt();
            if (hora >= iHoraAbertura && hora <= iHoraFechamento)
            {
//                lista += restaurante + "\n";
                lista.append(restaurante);
            }

         } while (!line.isNull());
        file.close();
    } else {
        emit error("Unable to open the file");
        return QStringList();
    }
    return lista;
}

