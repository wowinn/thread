#include <iostream>
#include <thread>

using namespace std;

class TA
{
    int& m_i;

public:
    TA(int& i) :m_i(i)
    {
        cout << "TA()构造函数被执行" << endl;
    }

    TA(const TA& ta) :m_i(ta.m_i)
    {
        cout << "TA()拷贝构造函数被执行" << endl;
    }

    ~TA()
    {
        cout << "~TA()析构函数被执行" << endl;
    }

    void operator()()
    {
        cout << "我的线程opreator()开始执行了" << endl;

        cout << "我的线程opreator()执行完了" << endl;

        cout << "m_i1=" << m_i << endl;
        cout << "m_i2=" << m_i << endl;
        cout << "m_i3=" << m_i << endl;
        cout << "m_i4=" << m_i << endl;
        cout << "m_i5=" << m_i << endl;
    }
};

void myprint()
{
    cout << "我的线程开始执行了" << endl;

    cout << "我的线程执行完了1" << endl;

    cout << "我的线程执行完了2" << endl;
    cout << "我的线程执行完了3" << endl;
    cout << "我的线程执行完了4" << endl;
    cout << "我的线程执行完了5" << endl;
    cout << "我的线程执行完了6" << endl;
    cout << "我的线程执行完了7" << endl;
    cout << "我的线程执行完了8" << endl;
}

int main()
{
    thread my_thread1(myprint);  //传入函数
    if (my_thread1.joinable())   //joinable()判断是否可以执行join()或者detach()函数
    {
        my_thread1.join();       //join()函数为阻塞主线程，主线程需等待其他线程执行完在执行
    }
    else
    {
        cout << "1:joinable == false" << endl;
    }
    //my_thread1.join();    //创建的线程只能执行join()或者detch(),并且只能执行一次，否则会有异常
    //my_thread1.detach();  //detach()函数可以理解为该线程与主线程分离了，主线程不必再等待该线程执行结束
                            //执行detach()函数的线程会被C++运行时库接管


    int i = 4;
    TA ta(i);
    thread my_thread2(ta);  //传入对象  //创建线程时执行的是拷贝构造函数
    my_thread2.join();
    //my_thread2.detach();

    auto my_lambda = [] {
        cout << "lambda函数" << endl;
    };
    thread my_thread3(my_lambda);   //传入lambda表达式
    my_thread3.join();
    //my_thread3.detach();

    cout << "主线程1" << endl;
    cout << "主线程2" << endl;
    cout << "主线程3" << endl;
    cout << "主线程4" << endl;
    cout << "主线程5" << endl;
    cout << "主线程6" << endl;
    cout << "主线程7" << endl;
    cout << "主线程8" << endl;

    return 0;
}
