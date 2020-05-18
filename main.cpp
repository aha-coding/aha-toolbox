#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setWindowTitle("啊哈工具箱");
    return a.exec();
}
