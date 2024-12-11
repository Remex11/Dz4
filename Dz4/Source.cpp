#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // 1. Определение минимального и максимального элементов в массиве
    const int SIZE = 10;
    int arr[SIZE];
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 100; // Заполнение массива случайными числами от 0 до 99
    }

    int minElement = arr[0];
    int maxElement = arr[0];

    for (int i = 1; i < SIZE; ++i) {
        if (arr[i] < minElement) minElement = arr[i];
        if (arr[i] > maxElement) maxElement = arr[i];
    }

    cout << "Минимальный элемент: " << minElement << endl;
    cout << "Максимальный элемент: " << maxElement << endl;

    // 2. Поиск суммы элементов, меньших указанного пользователем
    int lowerLimit, sum = 0;
    cout << "Введите нижний предел диапазона: ";
    cin >> lowerLimit;

    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] < lowerLimit) {
            sum += arr[i];
        }
    }

    cout << "Сумма элементов меньше " << lowerLimit << ": " << sum << endl;

    // 3. Определение месяца с максимальной и минимальной прибылью
    double profit[12];
    cout << "Введите прибыль фирмы за 12 месяцев: " << endl;

    for (int i = 0; i < 12; ++i) {
        cout << "Месяц " << (i + 1) << ": ";
        cin >> profit[i];
    }

    int startMonth, endMonth;
    cout << "Введите диапазон (начальный и конечный месяцы): ";
    cin >> startMonth >> endMonth;

    double maxProfit = profit[startMonth - 1];
    double minProfit = profit[startMonth - 1];
    int maxMonth = startMonth - 1;
    int minMonth = startMonth - 1;

    for (int i = startMonth - 1; i < endMonth; ++i) {
        if (profit[i] > maxProfit) {
            maxProfit = profit[i];
            maxMonth = i;
        }
        if (profit[i] < minProfit) {
            minProfit = profit[i];
            minMonth = i;
        }
    }

    cout << "Максимальная прибыль в месяце " << (maxMonth + 1) << ": " << maxProfit << endl;
    cout << "Минимальная прибыль в месяце " << (minMonth + 1) << ": " << minProfit << endl;

    return 0;
}