// Облати видимости данных

#include <iostream>

int _X;//Гобальная переменная с нулем, надо ее выделить, напр _, заглавная и т.д.
const double _PI = 3.1416;//Глобальная константа
int _ARR[5];//Глобальный массив, заполняется нулями

void print_X() {
    std::cout << _X << std::endl; //Используем переменную _Х
}

void use_static() {//Статическая переменная
    static int a = 1;
    std::cout << a << std::endl;
    a++;
    if (a > 5) a = 1;
}

int power(int num1 = 1, int num2 = 2) { //=2 - параметр по умолчанию
    int res = 1;
    for (int i = 1; i <= num2; i++)
        res *= num1;

    return res;
}

inline int absolute(int num) { //Встраимые ф-ции
    return num < 0 ? -num : num;
}

inline int sum_AB(int A, int B) { //Встраиваемые ф-ции
    int sum = 0;
    for (int i = A; i < B; i++)
        sum += i;
    
    return sum;
}

//Перегруженные функции
int max(int num1, int num2) {
    std::cout << "INT\n";
    return num1 > num2 ? num1 : num2;
}

double max(double num1, double num2) {
    std::cout << "DOUBLE\n";
    return num1 > num2 ? num1 : num2;
}

int max(int num1, int num2, int num3) {
    std::cout << "3 INT\n";
    return num1 > (num2 > num3 ? num2 : num3) ? num1 : (num2 > num3 ? num2 : num3);
}

//Шаблонные функции
template <typename T>
T absol(T num) {
    return num < 0 ? -num : num;
}


int main()
{
    setlocale(LC_ALL, "rus");
    int n;// Локальная переменная блока main()

    //Локальные переменные
   // i = 10; //Ошибка, вне области видимости

  //  for (int i = 0; i < 5; i++) { //i - локальная переменная
     //   int x = 5;
    //    std::cout << '*';
    //}
        // i = 10; //Ошибка, вне области видимости
     //   std::cout << std::endl;
        //x = 5; //Ошибка
        //int x = i * 10; // Все локальные переменные существуют строго внетри фигурных скобках, в которых они были объявлены
       // std::cout << "X=" << x << '\n';

        //Работа с глобальной переменной
     //   _X = 7;
    //    print_X();

//Статические переменные
//for (int i = 0; i < 10; i++)
    //use_static();
// std::cout << a; //Ошибка
//use_static();
//use_static();
//use_static();
//use_static();

  //  std::cout << "4^3" <<'\t' << power(4, 3) << '\n';
  //  std::cout << "5^2" << power(5, 2) << '\n';

  //  std::cout << "5^2" << power(5) << '\n';//Параметр по умолчанию
  //  std::cout << "5^2" << power() << '\n';//Параметр по умолчанию


    //Встраиваемые, перегруженные и шаблонные функции

    // Встраимые функции

    std::cout << "Введите число: ";
    std::cin >> n;
    std::cout << '|' << n << "|=" << absolute(n) << '\n';

    std::cout << "Сумма чисел от 5 до 10: " << sum_AB(5, 10);
   
    //Перегруженные функции

    std::cout << max(10, 15) << std::endl;
    std::cout << max(5.7, 5.1) << std::endl;//Значения передаются с параметром int
    std::cout << max(5, 8, 2) << std::endl;

    //Шаблонные функции
std::cout << absol(-7) << std::endl;
std::cout << absol(-7.5) << std::endl;


}



