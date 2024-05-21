#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startTime = QDateTime::currentDateTime();
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("datos_sensor.db");

    if (!db.open()) {
        qDebug() << "Error al abrir la base de datos.";
    }

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateUI);
    timer->start(60000); // Actualizar cada minuto

    updateUI(); // Llamar a updateUI inmediatamente para actualizar la información al inicio
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}

void MainWindow::updateUI()
{
QSqlQuery query("SELECT * FROM datos_sensores ORDER BY timestamp DESC LIMIT 1", db);
if (query.next()) {
    QString lastData = "ID: " + query.value(0).toString() +  " "
                       "Timestamp: " + query.value(1).toString() + " "
                       "T: " + query.value(2).toString() + " "
                       "H: " + query.value(3).toString() + " "
                       "HS: " + query.value(4).toString() + " "
                       "Velocidad del viento: " + query.value(5).toString() + " "
                       "Dirección del viento: " + query.value(6).toString() + "\n"
                       "Precipitación: " + query.value(7).toString() + " "
                       "Intensidad de luz: " + query.value(8).toString();

    qDebug() << "Last data:" << lastData; // Imprimir datos en la consola para verificar
    ui->lastDataLabel->setText("Último dato guardado:\n" + lastData);
} else {
    ui->lastDataLabel->setText("Último dato guardado: N/A");
}


    qint64 seconds = startTime.secsTo(QDateTime::currentDateTime());
    ui->timeElapsedLabel->setText("Tiempo transcurrido: " + QString::number(seconds) + " segundos");
}
