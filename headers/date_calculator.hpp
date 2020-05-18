/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-02-27 20:57:48 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-02-27 21:44:53
 */
#include <cstdio>
#include <iostream>
#ifndef DATE_CALCULATOR_HPP
#define DATE_CALCULATOR_HPP

class date {
private:
    const int days_notleap[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const int days_isleap[13]={0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool IsLeapYear(int y) {
        if (y % 400 == 0) return true;
        if (y % 100 == 0) return false;
        if (y % 4 == 0) return true;
        return false;
    }

    void GetYMD(int &y, int &m, int &d) {//输入年月日
        print("请输入年，月，日，输入格式如2020 1 1");
        scanf("%d%d%d", &y, &m, &d);
        while(m < 1 || m > 12) {
            print("输入的月份不合法！请重新输入月份，如1");
            scanf("%d", &m);
        }
        while((IsLeapYear(y) && (d < 1 || d > days_isleap[m])) || (!IsLeapYear(y) && (d < 1 || d > days_notleap[m]))) {
            print("输入的天数不合法！请重新输入天数，如1");
            scanf("%d", &d);
        }
        return ;
    }

    void GetYMD(int &my_y1, int &m1, int &d1, int &y2, int &m2, int &d2) {
        print("请输入第一个年，月，日，输入格式如2020 1 1");
        scanf("%d%d%d", &my_y1, &m1, &d1);
        while(m1 < 1 || m1 > 12) {
            print("输入的月份不合法！请重新输入月份，如1");
            scanf("%d", &m1);
        }
        while((IsLeapYear(my_y1) && (d1 < 1 || d1 > days_isleap[m1])) || (!IsLeapYear(my_y1) && (d1 < 1 || d1 > days_notleap[m1]))) {
            print("输入的天数不合法！请重新输入天数，如1");
            scanf("%d", &d1);
        }        

        print("请输入第二个年，月，日，输入格式如2020 1 1");
        scanf("%d%d%d", &y2, &m2, &d2);
        while(m2 < 1 || m2 > 12) {
            print("输入的月份不合法！请重新输入月份，如1");
            scanf("%d", &m2);
        }
        while((IsLeapYear(y2) && (d2 < 1 || d2 > days_isleap[m2])) || (!IsLeapYear(y2) && (d2 < 1 || d2 > days_notleap[m2]))) {
            print("输入的天数不合法！请重新输入天数，如1");
            scanf("%d", &d2);
        }       
    }

    void Mode1() {
        int y, m, d;
        GetYMD(y, m, d);
        //获取年月日
        if (m <= 2) {
            y--;
            m += 12;
        }
        //基姆拉尔森计算公式中，需要将一年的1月，2月替换为上一年的13月14月
        int week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7 + 1;
        //套用基姆拉尔森计算公式
        if (m > 12) {
            y++;
            m -= 12;
        }
        //复位
        printf("%d年%d月%d日是星期", y, m, d);
        switch(week) {
            case 1: printf("一");break;
            case 2: printf("二");break;
            case 3: printf("三");break;
            case 4: printf("四");break;
            case 5: printf("五");break;
            case 6: printf("六");break;
            case 7: printf("日");break;
        }
        print("。");
        //输出
        return ;
    }

    void Mode2() {
        int y, m, d;
        GetYMD(y, m, d);
        int ans = 0;
        if (IsLeapYear(y) && m > 1)
            for (int i = 1; i < m; i++)
                ans += days_isleap[i];
        else if (m > 1)
            for (int i = 1; i < m; i++)
                ans += days_notleap[i];
        
        ans += d;
        printf("%d年%d月%d日是%d年的第%d天\n", y, m, d, y, ans);
        return ;
    }

    int InnerMode2(int y, int m, int d) {
        int ans = 0;
        if (IsLeapYear(y) && m > 1)
            for (int i = 1; i < m; i++)
                ans += days_isleap[i];
        else if (m > 1)
            for (int i = 1; i < m; i++)
                ans += days_notleap[i];
        
        ans += d;
        return ans;        
    }

    bool TwoDatesIsSwap(int my_y1, int m1, int d1, int y2, int m2, int d2) {
        if (my_y1 != y2) return my_y1 > y2;
        if (m1 != m2) return m1 > m2;
        return d1 > d2;
    }

    int SwapTwoDates(int &my_y1, int &m1, int &d1, int &y2, int &m2, int &d2) {
        if (TwoDatesIsSwap(my_y1, m1, d1, y2, m2, d2)){
            std :: swap(my_y1, y2);
            std :: swap(m1, m2);
            std :: swap(d1, d2);
        }
    }

    void Mode3() {
        long ans = 0;
        int my_y1, m1, d1, y2, m2, d2;
        GetYMD(my_y1, m1, d1, y2, m2, d2);
        SwapTwoDates(my_y1, m1, d1, y2, m2, d2);

        if (my_y1 != y2) ans += 365 + IsLeapYear(my_y1) - InnerMode2(my_y1, m1, d1);
        if (my_y1 < y2 - 1) 
            for (int i = my_y1 + 1; i < y2; i++)
                ans += 365 + IsLeapYear(i);
        ans += InnerMode2(y2, m2, d2);
        printf("%d年%d月%d日距%d年%d月%d日有%ld天\n", my_y1, m1, d1, y2, m2, d2, ans);
        return ;
    }

    void Mode4() {
        int y, m, d;
        GetYMD(y, m, d);
        int days;
        print("请输入一个数字，代表从这一天开始向前或向后多少天。向后数值为正数，向前数值为负数。");
        scanf("%d", &days);
        printf("从%d年%d月%d日开始", y, m, d);
        if (days > 0) {
            printf("向后%d", days);
            while(days--) {
                d++;
                if (d > (IsLeapYear(y) ? days_isleap[m] : days_notleap[m])) {
                    m++;
                    d = 1;
                }
                if (m > 12) {
                    y++;
                    m = 1;
                }
            }
        }else if (days < 0) {
            printf("向前%d", -days);
            while(days++) {
                d--;
                if (d < 1) {
                    m--;
                    d = IsLeapYear(y) ? days_isleap[m] : days_notleap[m];      
                }
                if (m < 1) {
                    y--;
                    m = 12;
                }
            }
        }else printf("既不向前也不向后");
        printf("天是%d年%d月%d日。", y, m, d);
    }
public:
    int datecalc_init() {
        int id = 1;
        while(id) {
            print("\t\t\t\t啊哈工具箱-日期计算器");
            print("功能：");
            print("1.计算星期（某年某月某日是星期几）");
            print("2.计算当前日期在当年排第几天");
            print("3.计算相隔天数（俩日期之间相隔几天）");
            print("4.计算当前日期向前/后几天后的日期");
            print("0.退出日期计算器");
            print("请输入序号以进入相关功能！比如计算星期，请输入1.输入完成后请按回车！");
            scanf("%d", &id);
            switch(id) {
                case 1: Mode1();break;
                case 2: Mode2();break;
                case 3: Mode3();break;
                case 4: Mode4();break;
            }
            if (id) stop();
            clear();
        }
    }
};

#endif