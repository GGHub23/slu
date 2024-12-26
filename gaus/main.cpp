#include<Windows.h>
#include <iostream> 
#include <iomanip> 
#include <cmath>   
#include <string> 

void solve2(double peredxa, double peredya, double svoboda, double peredxb, double peredyb, double svobodb) {
    std::cout << "  Начало решения системы..." << "\n";
    double det = peredxa * peredyb - peredya * peredxb;
    if (fabs(det) < 1e-9) {
        std::cerr << "  Система не имеет единственного решения (определитель равен нулю или близок к нулю)." << "\n";
        return;
    }
    double x = (svoboda * peredyb - svobodb * peredya) / det;
    double y = (peredxa * svobodb - peredxb * svoboda) / det;
    std::cout << "  Решение системы:" << "\n";
    std::cout << "    x = " << std::fixed << std::setprecision(2) << x << "\n";
    std::cout << "    y = " << std::fixed << std::setprecision(2) << y << "\n";
    std::cout << "  Проверка решения:" << "\n";
    double check1 = peredxa * x + peredya * y; 
    double check2 = peredxb * x + peredyb * y;  
    std::cout << "    Уравнение 1: (" << std::fixed << std::setprecision(2) << peredxa << " * " << std::fixed << std::setprecision(2) << x << ") + (" << std::fixed << std::setprecision(2) << peredya << " * " << std::fixed << std::setprecision(2) << y << ") = " << std::fixed << std::setprecision(6) << check1 << " (должно быть = " << svoboda << ")" << "\n";
    std::cout << "    Уравнение 2: (" << std::fixed << std::setprecision(2) << peredxb << " * " << std::fixed << std::setprecision(2) << x << ") + (" << std::fixed << std::setprecision(2) << peredyb << " * " << std::fixed << std::setprecision(2) << y << ") = " << std::fixed << std::setprecision(6) << check2 << " (должно быть = " << svobodb << ")" << "\n";
    if (fabs(check1 - svoboda) > 1e-6) {
        std::cout << "   Внимание: проверка решения первого уравнения показала расхождение!" << "\n";
    }
    else {
        std::cout << "    Проверка решения первого уравнения пройдена." << "\n";
    }
    if (fabs(check2 - svobodb) > 1e-6) {
        std::cout << "    Внимание: проверка решения второго уравнения показала расхождение!" << "\n";
    }
    else {
        std::cout << "    Проверка решения второго уравнения пройдена." << "\n";
    }
    if (fabs(check1 - svoboda) <= 1e-6 && fabs(check2 - svobodb) <= 1e-6) {
        std::cout << "  Проверка решения пройдена для обоих уравнений." << "\n";
    }

    std::cout << "  Решение системы 2 завершено." << "\n";
}
void solve3(double peredxa, double peredya, double a1, double svoboda,
    double peredxb, double peredyb, double a2, double svobodb,
    double peredxc, double peredyc, double a3, double svobodc) {
    std::cerr << "  Функция solve3 не реализована. Используйте систему 2." << "\n";
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size;
    do {
        std::cout << "Введите кол-во уравнений (2 или 3): ";
        std::cin >> size;
        if (size != 2 && size != 3) {
            std::cout << "  Ошибка: введите 2 уравнения или 3." << "\n";
        }
    } while (size != 2 && size != 3);
    if (size == 2) {
        double peredxa, peredya, svoboda, peredxb, peredyb, svobodb;
        std::cout << "Введите коэффициенты первого уравнения (peredxa peredya svoboda): ";
        std::cin >> peredxa >> peredya >> svoboda;
        std::cout << "Введите коэффициенты второго уравнения (peredxb peredyb svobodb): ";
        std::cin >> peredxb >> peredyb >> svobodb;
        solve2(peredxa, peredya, svoboda, peredxb, peredyb, svobodb);
    }
    else if (size == 3) {
        std::cerr << "  Реализация для 3 уравнений нема, используйте 2." << "\n";
    }

    return 0;
}
double fabs(double n) {
    if (n < 0) return -n;
    return n;
}