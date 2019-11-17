#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void digitBtn(char ch);
    void start();
    void evaluation();

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_dot_clicked();

    void on_delepushButton_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_less_clicked();

    void on_pushButton_mul_clicked();

    void on_pushButton_exc_clicked();

    void on_pushButton_res_clicked();

    void on_pushButton_pow_clicked();

    void on_pushButton_left_clicked();

    void on_pushButton_right_clicked();

    void on_pushButton_equal_clicked();

    void on_pushButton_clicked();

    bool isresult();

    bool isMark1(char ch);

private:
    Ui::MainWindow *ui;

      bool complete;//表达式是否计算完成
};

#endif // MAINWINDOW_H
