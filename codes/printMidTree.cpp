//
// Created by 15361 on 2019/9/6.
//

#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/* 小米笔试第二题
 * 给定格式二叉树，输出中序遍历
 * input :1(2(3,4(,5)),6(7,))
 * output:3245176
 *
 * 请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/

string str;
string ans;

void deal(int l, int r){
    if(l > r) {
        return;
    }
    int cont = 0,mid = -1;
    for(int i = l+2;i<r;i++){
        if(str[i] == '(') cont++;
        if(str[i] == ',' && cont == 0){
            mid = i;
            break;
        }
        if(str[i] == ')') cont--;
    }
    if(mid!=-1){
        deal(l+2,mid-1);
        ans = ans + str[l];
        deal(mid+1,r-1);
    }else {
        ans = ans + str[l];
    }

}

string solution(string input) {
    ans = "";
    str = input;
    int len = input.size();
    deal(0, len-1);
    return ans;
}
/******************************结束写代码******************************/


int main() {
    string res;

    string _input;
    getline(cin, _input);

    res = solution(_input);
    cout << res << endl;

    return 0;

}
