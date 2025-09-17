//завдання 1
#include <iostream>
#include <string>
using namespace std;

union Number {
    int digits;
    char word[9];
};

struct Car {
    string color;
    string model;
    bool isWord;
    Number num;
};

void inputCar(Car& c) {
    cout << "Введіть колір: ";
    cin >> c.color;
    cout << "Введіть модель: ";
    cin >> c.model;

    cout << "Номер (1 - цифри, 2 - слово): ";
    int type;
    cin >> type;

    if (type == 1) {
        c.isWord = false;
        cout << "Введіть 5-значний номер: ";
        cin >> c.num.digits;
    }
    else {
        c.isWord = true;
        cout << "Введіть слово (до 8 символів): ";
        cin >> c.num.word;
    }
}

void printCar(const Car& c) {
    cout << "Модель: " << c.model << " | Колір: " << c.color << " | Номер: ";
    if (c.isWord) cout << c.num.word;
    else cout << c.num.digits;
    cout << endl;
}

void editCar(Car& c) {
    cout << "Редагування машини:\n";
    inputCar(c);
}

void printAll(Car arr[], int n) {
    cout << "\nУсі машини:\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ") ";
        printCar(arr[i]);
    }
}

void searchCar(Car arr[], int n) {
    cout << "Пошук машини за номером: ";
    string s;
    cin >> s;
    bool found = false;

    for (int i = 0; i < n; i++) {
        if ((!arr[i].isWord && to_string(arr[i].num.digits) == s) ||
            (arr[i].isWord && s == arr[i].num.word)) {
            cout << "Знайдено: ";
            printCar(arr[i]);
            found = true;
        }
    }
    if (!found) cout << "Машину не знайдено.\n";
}

int main() {
    Car arr[10];
    int n = 3; 

    for (int i = 0; i < n; i++) {
        cout << "\nВведення машини #" << i + 1 << endl;
        inputCar(arr[i]);
    }

    printAll(arr, n);
    editCar(arr[0]);
    printAll(arr, n);
    searchCar(arr, n);

    return 0;
}

//завдання 2
//#include <iostream>
//#include <string>
//using namespace std;
//
//enum Type { BIRD = 1, CATTLE, HUMAN };
//
//union Characteristic {
//    float flightSpeed;  
//    bool isEvenToed;
//    int iq;
//};
//
//struct Entity {
//    float speed;
//    Type type;
//    string color;
//    Characteristic info;
//};
//
//void inputEntity(Entity& e) {
//    cout << "Введіть швидкість пересування: ";
//    cin >> e.speed;
//    cout << "Тип (1 - птах, 2 - худоба, 3 - людина): ";
//    int t;
//    cin >> t;
//    e.type = (Type)t;
//
//    cout << "Колір: ";
//    cin >> e.color;
//
//    if (e.type == BIRD) {
//        cout << "Швидкість польоту: ";
//        cin >> e.info.flightSpeed;
//    }
//    else if (e.type == CATTLE) {
//        cout << "Парнокопитна (1 - так, 0 - ні): ";
//        cin >> e.info.isEvenToed;
//    }
//    else {
//        cout << "Рівень IQ: ";
//        cin >> e.info.iq;
//    }
//}
//
//void printEntity(const Entity& e) {
//    cout << "Тип: ";
//    if (e.type == BIRD) cout << "Птах";
//    else if (e.type == CATTLE) cout << "Худоба";
//    else cout << "Людина";
//
//    cout << " | Швидкість: " << e.speed
//        << " | Колір: " << e.color << " | ";
//
//    if (e.type == BIRD) cout << "Швидкість польоту: " << e.info.flightSpeed;
//    else if (e.type == CATTLE) cout << "Парнокопитна: " << (e.info.isEvenToed ? "Так" : "Ні");
//    else cout << "IQ: " << e.info.iq;
//
//    cout << endl;
//}
//
//void editEntity(Entity& e) {
//    cout << "Редагування сутності:\n";
//    inputEntity(e);
//}
//
//void printAll(Entity arr[], int n) {
//    cout << "\nСписок сутностей:\n";
//    for (int i = 0; i < n; i++) {
//        cout << i + 1 << ") ";
//        printEntity(arr[i]);
//    }
//}
//
//void searchEntity(Entity arr[], int n) {
//    cout << "Пошук за характеристикою (введіть число): ";
//    float x;
//    cin >> x;
//    bool found = false;
//
//    for (int i = 0; i < n; i++) {
//        if ((arr[i].type == BIRD && arr[i].info.flightSpeed == x) ||
//            (arr[i].type == CATTLE && arr[i].info.isEvenToed == (bool)((int)x)) ||
//            (arr[i].type == HUMAN && arr[i].info.iq == (int)x)) {
//            cout << "Знайдено: ";
//            printEntity(arr[i]);
//            found = true;
//        }
//    }
//    if (!found) cout << "Нічого не знайдено.\n";
//}
//
//int main() {
//    Entity arr[10];
//    int n = 3;
//
//    for (int i = 0; i < n; i++) {
//        cout << "\nВведення сутності #" << i + 1 << endl;
//        inputEntity(arr[i]);
//    }
//
//    printAll(arr, n);
//    editEntity(arr[1]);
//    printAll(arr, n);
//    searchEntity(arr, n);
//
//    return 0;
//}