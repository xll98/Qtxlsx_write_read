#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtXlsx/QtXlsx>
#include <QtWidgets>
#define WORKXLSX  "./workspace/out.xlsx";
using namespace QXlsx;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
	QString filePath = WORKXLSX
	if (filePath.isEmpty())
		return;
	Document xlsx(filePath);
	CellRange range;
	range = xlsx.dimension();
	//int rowCount = range.rowCount();//4
	int rowCount = 2;
	int now = xlsx.read(rowCount, 2).toInt();
	while (now > 0)
	{
		rowCount++;
		now = xlsx.read(rowCount, 2).toInt();
	}
	rowCount--;

	int colCount = range.columnCount();//22

	for (int i = 0; i < colCount; i++)
	{
		QString hs = xlsx.read(1, i + 1).toString();
		ui->tableWidget->horizontalHeaderItem(i)->setText(hs);
	}


	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j <= colCount; j++) {
			QString v = xlsx.read(i+2, j+1).toString();
			ui->tableWidget->setItem(i, j, new QTableWidgetItem(v));
		}
	}
	ui->tableWidget->setRowCount(rowCount-1);
}

void MainWindow::on_outbtn_clicked()
{
	Document out;
	QString outPath = WORKXLSX
	QStringList list = out.sheetNames();
	QVariant v;
	int rowCount = ui->tableWidget->rowCount();
	int colCount = ui->tableWidget->columnCount();
	for (int i = 0; i < colCount; i++)
	{
		v = ui->tableWidget->horizontalHeaderItem(i)->text();
		out.write(1, i + 1, v);
	}

	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			v = ui->tableWidget->item(i, j)->text();
			out.write(i + 2, j + 1, v);
		}
	}
	out.saveAs(outPath);
}

void MainWindow::on_insertbtn_clicked()
{
	int rowCount = ui->tableWidget->rowCount();
	int colCount = ui->tableWidget->columnCount();
	ui->tableWidget->insertRow(rowCount);
	for (int j = 0; j < colCount; j++)
	{
		ui->tableWidget->setItem(rowCount, j, new QTableWidgetItem());
	}
	
}