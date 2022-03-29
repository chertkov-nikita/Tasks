#include "interface.h"
#include "ui_interface.h"
#include "eventgraph.h"
#include "canvas.h"
#include <QFileDialog>
#include <QDebug>
#include <QErrorMessage>
#include <QFile>
#include <QTextStream>

interface::interface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::interface)
{
    ui->setupUi(this);
    ui->namefile->setText(fileName);
}

void interface::on_loadFileButton_clicked(){

    QString sPath = "C:/";
    fileName = QFileDialog::getOpenFileName(Q_NULLPTR,
                                            "Выберите файл",sPath, "*.txt");
    if(fileName == "")
   qDebug() << "No file was chosen.";
    else
   qDebug() << "file loaded";
    ui->namefile->setText("Открыт файл:"+fileName);
    if (!checkFile()){
        qDebug() << "Error";
        fileName = "";
        ui->namefile->setText("Открыт файл:"+fileName);
        QErrorMessage errorMessage;
        errorMessage.showMessage("Файл не выбран или повреждён");
        errorMessage.exec();}
}
void interface::on_paintButton_clicked(){

    if(fileName == ""){
        QErrorMessage errorMessage;
        errorMessage.showMessage("Файл не выбран или повреждён");
        errorMessage.exec();

}


    TEventGraph* s = new TEventGraph(sMatrix,ui->spinBox->value());
    TCanvas* w = new TCanvas(s);
    w->setWindowTitle(fileName);
    w->show();
}
bool interface::checkFile(){

    QFile file(fileName);
    int lineCount1 = 1;

    int buffer = 1;
    sMatrix = " ";
    if (!file.open(QIODevice::ReadOnly)){
        qDebug() << "Ошибка при открытии файла";
    return 0;}

    QByteArray arr = file.readAll();
    file.close();
for(int i = 0;i < arr.size();i++){
    if((arr[i] < '1' || arr[i] > '9') && arr[i] != '\r' && arr[i] !='\n' && arr[i] != ' ')
        return 0;
    if(arr[i] == '\n')
        lineCount1 ++;
    if(arr[i] - '0' > buffer)
        buffer = arr[i]-'0';

}
if(buffer > lineCount1)
    return 0;

  QString ma(arr);
  sMatrix = ma;
 return 1;


}
interface::~interface()
{
    delete ui;
}

