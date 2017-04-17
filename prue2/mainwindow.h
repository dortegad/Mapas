#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <opencv2/opencv.hpp>

namespace Ui {
class MainWindow;
}

class Region
{
public:
    std::vector < cv::Point> puntos;
    cv::Scalar color;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pBPlantilla_clicked();

    void on_pBImagen_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
