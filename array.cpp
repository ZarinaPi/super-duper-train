// array.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <ctime>

using namespace std;
using namespace chrono;

static void random(int* arr, int n)
{
    int max = 99, min = -99;
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

static void output(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

static void bubbleSort(int arr[], int n)
{
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;

    start = steady_clock::now();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "Время потраченное на сортировку массива = " << result.count() << " в наносекундах.\n";
    cout << endl;
}

static void shakerSort(int arr[], int n)
{
    int low = 0, up = n - 1;
    int last, tmp;
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;

    start = steady_clock::now();
    while (low < up)
    {
        last = -1;
        for (int i = low; i < up; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                last = i;
            }
        }
        up = last;
        last = n;
        for (int i = up - 1; i >= low; i--)
        {
            if (arr[i] > arr[i + 1])
            {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                last = i;
            }
        }
        low = last + 1;
    }
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "Время потраченное на сортировку массива = " << result.count() << " в наносекундах.\n";
    cout << endl;
}

static void quickSort(int arr[], int left, int right)
{
    if (left > right) return;

    int p = arr[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j)
    {
        while (arr[i] < p)
        {
            i++;
        }
        while (arr[j] > p)
        {
            j--;
        }
        if (i <= j)
        {
            swap(arr[i], arr[j]);

            i++;
            j--;
        }
    }
    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

static void maxElement_minElement(int arr[], int n)
{
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;

    start = steady_clock::now();
    int max, min, average, count = 0;
    max = arr[0];
    min = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (max < arr[i]) max = arr[i]; 
        if (min > arr[i]) min = arr[i];
    }

    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "Время потраченное на нахождение максимального и минимально элемента массива = " << result.count() << " в наносекундах.\n";
    cout << endl;

    start = steady_clock::now();
    average = (max + min) / 2;
    cout << "Среднее значение максимального и минимального значения массива = " << average << endl;
    
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == average)
        {
            cout << "arr [" << i << "] = " <<  arr[i] << endl;
            count++;
        }
    }

    if (count == 0)
    {
        cout << "Элементы не найдено!" << endl;
    }
    else
    {
        cout << "Количество найденных значений = " << count << endl;
    }
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "Время потраченное на нахождение элементов равных среднему значению минимального и максимального элемента = " << result.count() << " в наносекундах.\n";
    cout << endl;
}

static void searchElement(int arr[], int n)
{
    int a, b, count_a = 0, count_b = 0;

    cout << "Введите число а = ";
    cin >> a;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < a)
            count_a++;
    }
    cout << "Количество элементов в массиве, которые меньше " << a << " = " << count_a;

    cout << endl;
    cout << "Введите число b = ";
    cin >> b;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > b)
            count_b++;
    }
    cout << "Количество элементов в массиве, которые больше " << b << " = " << count_b;

}

static void swapElement(int arr[], int n)
{
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;
    start = steady_clock::now();
    int i, j;

    cout << "Введите индекс первого элемента массива = ";
    cin >> i;
    i -= 1;
    cout << "Введите индекс второго элемента массива = ";
    cin >> j;
    j -= 1;

    swap(arr[i], arr[j]);
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "Время потраченное обмен элементов массива = " << result.count() << " в наносекундах.\n";
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");
    
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;

    const int n = 100;
    int arr[n]{};
    int choice;

    for (;;)
    {
        cout << "1.Пузырьковая сортировка." << endl;
        cout << "2.Шейкер-сортировка." << endl;
        cout << "3.Быстра сортировка." << endl;
        cout << "4.Нахождение максимального и минимального элемента массива. Среднее значение максимального и минимального значения массива." << endl;
        cout << "5.Выводит количество элементов в отсортированном массиве, которые меньше числа a. Выводит количество элементов в отсортированном массиве, которые больше числа b." << endl;
        cout << "6.Меняет местами элементы массива, индексы которых вводит пользователь." << endl;
        cout << "7.Выход из программы." << endl;
        cout << "Выберите пункт меню. И введите номер выбранного пункта = ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
        {
            random(arr, n);
            cout << endl;
            bubbleSort(arr, n);
            output(arr, n);
            cout << endl;
            memset(arr, 0, n * sizeof(int));
            
            break;
        }
        case 2:
        {
            random(arr, n);
            cout << endl;
            shakerSort(arr, n);
            output(arr, n);
            cout << endl;
            memset(arr, 0, n * sizeof(int));
            
            break;
        }
        case 3:
        {
            random(arr, n);
            cout << endl;
            start = steady_clock::now();
            quickSort(arr, 0, n - 1);
            end = steady_clock::now();
            result = duration_cast<nanoseconds>(end - start);
            cout << "Время потраченное на сортировку массива = " << result.count() << " в наносекундах.\n";
            cout << endl;
            output(arr, n);
            cout << endl;
            memset(arr, 0, n * sizeof(int));

            break;
        }
        case 4:
        {
            random(arr, n);
            cout << "Неотсортированный массив: ";
            output(arr, n);
            cout << endl;
            maxElement_minElement(arr, n);
            memset(arr, 0, n * sizeof(int));

            random(arr, n);
            quickSort(arr, 0, n - 1);
            cout << "Отсортированный массив: ";
            output(arr, n);
            maxElement_minElement(arr, n);
            output(arr, n);
            cout << endl;
            memset(arr, 0, n * sizeof(int));

            break;
        }
        case 5:
        {
            random(arr, n);
            quickSort(arr, 0, n - 1);
            cout << "Отсортированный массив: ";
            output(arr, n);
            searchElement(arr, n);
            output(arr, n);
            cout << endl;
            memset(arr, 0, n * sizeof(int));

            break;
        }
        case 6:
        {
            random(arr, n);
            cout << "Неотсортированный массив: " << endl;
            output(arr, n);
            cout << endl;
            swapElement(arr, n);
            cout << endl;
            output(arr, n);
            cout << endl;
            memset(arr, 0, n * sizeof(int));

            break;
        }
        default:
            return 0;
            break;
        }
    
    }
}