// c++ day9.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//一.函数模板
#include <iostream>
using namespace std;
#include<string>
//1.模板的两种使用方法
//a.自动类型推导      swap(a,b);
//b.显示类型推导      swap<Elemtype>(a,b);
//2.注意事项
//a.自动类型推导，推导出的类型必须一致才能使用
//b.必须确定出T的数据类型，才可以使用
//二.类模板
//1.类模板没有自动类型推导
//2.类模板在模板参数列表中可以有默认参数
template<class name,class age= int>      //template<class name,class age> 
class Person {
public:
    Person(name Name, age Age) {
        this->m_name = Name;
        this->m_age = Age;
    }
    name m_name;
    age m_age;
    void show() {
        cout << this->m_name << "\t" << "\t" << this->m_age << endl;
    }
};
void test01() {
    Person <string>p1("田景臣", 18);//Person p1("田景臣", 18); 会报错 。因为：类模板没有自动类型推导
    p1.show();    //这里就可以不加int
}
//3.类模板中成员函数创建时机  ：类模板的成员函数在调用时才创建
class person1 {
public:
    void show1() {
        cout << "person1 show" << endl;
    }
};
class person2 {
public:
   void show2() {
        cout << "person2 show" << endl;
    }
};
template <class T>
class Myclass {
public:
    T infj;
    void  func1() {
        infj.show1();
    }
    void func2() {
        infj.show2();
    }
};
void tst01(int a) {
    Myclass<person1> M1;
   //Myclass<person1>::func1();
    M1.func1();
   // M1.func2();
}
//4.类模板对象作函数参数
 template<class  T1,class T2>
 class people {
 public:
people(T1 name,T2 age) {
    this->m_name = name;
    this->m_age = age;
}
void show() {
    cout << this->m_name << "\t" << this->m_age << endl;
}
T1 m_name;
T2 m_age;
 };
// a.指定传入类型
 void printpeople(people<string, int>&p)
 {
     p.show();
 }
 void test01(char a) {
     people<string,int>p("孙悟空", 999);
     printpeople(p);
}
 //b.参数模板化
 template<class  T1, class T2>  //加个这个下一行不报错
 void printpeople2(people<T1, T2>& p) {
     p.show();
 }
 void test02() {
     people<string, int>p("猪八戒", 99);
     printpeople2(p);

 }

int main()
{
    //test01();
    tst01(2);
    test01('p');
    test02();
    std::cout << "Hello World!\n";
}
