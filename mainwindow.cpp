#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QtWebChannel/QWebChannel>


MainWindow :: MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui :: MainWindow) {
    ui -> setupUi(this);
    // Date Calculator Functions
    MainWindow :: connect(ui -> Date1, SIGNAL(dateChanged(QDate)), this, SLOT(UpdateWeekDay()));
    MainWindow :: connect(ui -> Date2, SIGNAL(dateChanged(QDate)), this, SLOT(UpdateWeekDay()));
    MainWindow :: connect(ui -> Date1, SIGNAL(dateChanged(QDate)), this, SLOT(UpdateIntervalDays()));
    MainWindow :: connect(ui -> Date2, SIGNAL(dateChanged(QDate)), this, SLOT(UpdateIntervalDays()));
    MainWindow :: connect(ui -> Date1, SIGNAL(dateChanged(QDate)), this, SLOT(UpdateIsLeapYear()));
    MainWindow :: connect(ui -> Date2, SIGNAL(dateChanged(QDate)), this, SLOT(UpdateIsLeapYear()));
    MainWindow :: connect(ui -> Date1, SIGNAL(dateChanged(QDate)), this, SLOT(UpdateDayOfYear()));
    MainWindow :: connect(ui -> Date2, SIGNAL(dateChanged(QDate)), this, SLOT(UpdateDayOfYear()));
    MainWindow :: connect(ui -> IntervalDays, SIGNAL(valueChanged(int)), this, SLOT(UpdateDate2()));
    //HTML Preview Functions
    MainWindow :: connect(ui -> HTMLEdit, SIGNAL(textChanged()), this, SLOT(UpdateHTMLPreview()));
}

MainWindow :: ~MainWindow() {
    delete ui;
}

// Date Calculator Functions
int GetWeekDay(int y, int m, int d) {//获取一个日期是当天的星期几（采用Kim Larsen计算公式）
    if (m == 1 || m == 2) {
        m += 12;
        y--;
    }//Kim Larsen中一年的一月和二月要折算到上一年的十三月和十四月
    int WeekDay = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;//Kim Larsen计算公式
    if (WeekDay == 0) WeekDay = 7;
    return WeekDay; //1 ~ 7 分别代表周一~周日
}

void MainWindow :: UpdateWeekDay() {
    int Date1WeekDay = GetWeekDay(ui -> Date1 -> date().year(), ui -> Date1 -> date().month(), ui -> Date1 -> date().day());
    QString WeekStr;
    switch(Date1WeekDay) {
        case 1: WeekStr = "周一"; break;
        case 2: WeekStr = "周二"; break;
        case 3: WeekStr = "周三"; break;
        case 4: WeekStr = "周四"; break;
        case 5: WeekStr = "周五"; break;
        case 6: WeekStr = "周六"; break;
        case 7: WeekStr = "周日"; break;
    }
    ui -> Date1WeekDayDisplay -> setText(WeekStr);
    int Date2WeekDay = GetWeekDay(ui -> Date2 -> date().year(), ui -> Date2 -> date().month(), ui -> Date2 -> date().day());
    switch(Date2WeekDay) {
        case 1: WeekStr = "周一"; break;
        case 2: WeekStr = "周二"; break;
        case 3: WeekStr = "周三"; break;
        case 4: WeekStr = "周四"; break;
        case 5: WeekStr = "周五"; break;
        case 6: WeekStr = "周六"; break;
        case 7: WeekStr = "周日"; break;
    }
    ui -> Date2WeekDayDisplay -> setText(WeekStr);
}

void MainWindow :: UpdateIntervalDays() {
    ui -> IntervalDays -> setValue(ui -> Date1 -> date().daysTo(ui -> Date2 -> date()));
}

void MainWindow :: UpdateDate2() {
    ui -> Date2 -> setDate(ui -> Date1 -> date().addDays(ui -> IntervalDays -> value()));
}

void MainWindow :: UpdateIsLeapYear() {
    if(ui -> Date1 -> date().isLeapYear(ui -> Date1 -> date().year())) {
        ui -> Date1IsLeapYear -> setText("闰年");
    } else {
        ui -> Date1IsLeapYear -> setText("平年");
    }

    if(ui -> Date2 -> date().isLeapYear(ui -> Date2 -> date().year())) {
        ui -> Date2IsLeapYear -> setText("闰年");
    } else {
        ui -> Date2IsLeapYear -> setText("平年");
    }
}

void MainWindow :: UpdateDayOfYear() {
    ui -> Date1DayOfYearDisplay -> setText(QString :: number(ui -> Date1 -> date().year()) + "年的第" + QString :: number(ui -> Date1 -> date().dayOfYear()) + "天");
    ui -> Date2DayOfYearDisplay -> setText(QString :: number(ui -> Date2 -> date().year()) + "年的第" + QString :: number(ui -> Date2 -> date().dayOfYear()) + "天");
}

//HTML Preview Functions
void MainWindow :: UpdateHTMLPreview() {

}
