#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QWidget>
#include <QtWidgets/QTableWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
	QTableWidget *tablewidget;
private:
    Ui::MainWindow *ui;
    
	void init();
private slots:
	void on_outbtn_clicked();
	void on_insertbtn_clicked();
};

#endif // MAINWINDOW_H
