#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // 1. ����������� ������������ � ������������� ��������� � �������
    const int SIZE = 10;
    int arr[SIZE];
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 100; // ���������� ������� ���������� ������� �� 0 �� 99
    }

    int minElement = arr[0];
    int maxElement = arr[0];

    for (int i = 1; i < SIZE; ++i) {
        if (arr[i] < minElement) minElement = arr[i];
        if (arr[i] > maxElement) maxElement = arr[i];
    }

    cout << "����������� �������: " << minElement << endl;
    cout << "������������ �������: " << maxElement << endl;

    // 2. ����� ����� ���������, ������� ���������� �������������
    int lowerLimit, sum = 0;
    cout << "������� ������ ������ ���������: ";
    cin >> lowerLimit;

    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] < lowerLimit) {
            sum += arr[i];
        }
    }

    cout << "����� ��������� ������ " << lowerLimit << ": " << sum << endl;

    // 3. ����������� ������ � ������������ � ����������� ��������
    double profit[12];
    cout << "������� ������� ����� �� 12 �������: " << endl;

    for (int i = 0; i < 12; ++i) {
        cout << "����� " << (i + 1) << ": ";
        cin >> profit[i];
    }

    int startMonth, endMonth;
    cout << "������� �������� (��������� � �������� ������): ";
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

    cout << "������������ ������� � ������ " << (maxMonth + 1) << ": " << maxProfit << endl;
    cout << "����������� ������� � ������ " << (minMonth + 1) << ": " << minProfit << endl;

    return 0;
}