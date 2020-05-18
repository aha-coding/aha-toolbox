#ifndef BASICS_HPP
#define BASICS_HPP
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

void print(std :: string s) {
    std :: cout << s << std :: endl;
}

int GetUserWant() {
    print("欢迎来到啊哈工具箱！！");
    print("如其名，本工具箱由啊哈团队集合制作。具体可见下面的贡献名单。");
    print("功能区域：");
    print("1.日期计算区");
    print("666.关于&联系我们");
    print("请输入数字以代表功能区域。如输入1，代表进入日期计算区。输入完成请按下回车。");
    print("如果您想退出，请输入数字0.");
    int id;
    scanf("%d",&id);
    return id;
}

void stop() {
    print("请按任意键继续……");
    getchar();getchar();
    return ;
}

void ContactUs() {
    print("我们来自啊哈编程星球，是一群好伙伴。");
    print("开发者：啊哈编程星球team");
    print("IDEA:东北小蟹蟹");
    print("联系我们：");
    print("洛谷团队链接：https://www.luogu.com.cn/team/24439（强烈欢迎加入！）");
    print("团队QQ号：1037755952（特别强烈欢迎加入！）");
    print("本工具箱虽然简陋些，但也是开发人员们的心血哦quq。");
    stop();
}
