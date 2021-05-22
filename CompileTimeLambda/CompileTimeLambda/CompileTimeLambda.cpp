// CompileTimeLambda.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<algorithm>
#include <array>
#include <vector>
using namespace std;


constexpr double f(double n)
{
    return [n] { return 0.3*n*n - 0.5*n + 4; }();
}

constexpr auto lam = [](double a, double b) { return 0.16665 * (b - a) * (f(a) + f(b) + 4 * f(0.5 * (a + b))); };

template<  typename T>
constexpr T IntSips(const int NN, T init) {
    for (int i = 0; i < NN; ++i) 
    {
        init += lam(i,i+1);
    }
    return init;
}

int main() {

    static_assert(IntSips(100, 0.0) < 97900);

    cout << IntSips(100,0.0);

}