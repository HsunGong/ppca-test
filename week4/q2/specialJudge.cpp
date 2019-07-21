#include <bits/stdc++.h>
#include <fstream>
#include <iostream>

using namespace std;

vector<string> name;

string GetProductOfTwoBigNum(string num1, string num2);
bool check(string name);
long long sum(string x);

int main()
{
    string n;
    while (!cin.eof())
    {
        cin >> n; // no .in or .out appended; with dir pos
        name.push_back(n);
    }
    // cout << "put end\n";

    for (auto iter : name)
    {
        cout << iter << ": " << check(iter) << '\n';
    }

    return 0;
}

bool check(string name)
{
    vector<string> a, n;
    string tmp;

    ifstream in;
    in.open(name + ".in");
    in >> tmp;
    while (!in.eof())
    {
        in >> tmp;
        a.push_back(tmp);
    }
    in.close();

    in.open(name + ".out");
    while (!in.eof())
    {
        in >> tmp;
        n.push_back(tmp);
    }
    in.close();

    cout << "get data from " << name << '\n';

    bool cc = true;
    while (!a.empty()){
        string aha = a.back();
        string nha = n.back();
        string an = GetProductOfTwoBigNum(aha, nha);

        long long left, right;
        left = sum(an);
        right = sum(nha) / stol(aha);

        if (!left == right && nha != "-1"){
            cc = false;
            break;   
        }

        a.pop_back();
        n.pop_back();
    }

    return cc;
}

long long sum(string x)
{
    long long ans = 0;
    for (auto iter : x)
    {
        ans += iter - '0';
    }
    return ans;
}

//求两个大数的乘积（两数均为正数）
string GetProductOfTwoBigNum(string strNumLeft, string strNumRight)
{
    if (strNumRight.empty() && strNumRight.empty())
    {
        return string("0");
    }

    //转换为数字
    for (string::size_type i = 0; i < strNumLeft.size(); ++i)
    {
        strNumLeft[i] -= '0';
    }
    for (string::size_type i = 0; i < strNumRight.size(); ++i)
    {
        strNumRight[i] -= '0';
    }

    string::size_type nMaxBits = strNumLeft.size() + strNumRight.size() + 1; //最大位数，多增加一位，便于编码
    string strProduct(nMaxBits, 0);
    char szTemp = 0;       //每位乘积，辅助变量
    char szCarrayTemp = 0; //进位信息

    for (int i = strNumRight.size() - 1; i >= 0; --i)
    {
        int k = strNumLeft.size() + i + 1;
        for (int j = strNumLeft.size() - 1; j >= 0; --j)
        {
            szTemp = (strNumRight[i] * strNumLeft[j] + strProduct[k]) % 10;
            szCarrayTemp = (strNumRight[i] * strNumLeft[j] + strProduct[k]) / 10;

            strProduct[k] = szTemp;
            strProduct[--k] += szCarrayTemp;
        }
    }

    //返回遍历strProduct，从而取出计算的结果
    string strResult;
    string::size_type k = 0;
    while (k < strProduct.size() && strProduct[k] == 0)
    {
        ++k;
    }
    for (; k < strProduct.size(); ++k)
    {
        strResult.push_back(strProduct[k] + '0'); //转换为字符
    }

    if (strResult.empty())
    {
        strResult.push_back('0');
    }

    return strResult;
}