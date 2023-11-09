#include <iostream>

using namespace std;

class Phone 
{
protected:
    string model;
    string processor;
    int ram;

public:
    Phone(string _model, string _processor, int _ram)
        : model(_model), processor(_processor), ram(_ram) {}

    void makeCall() {
        //printf1("%d", str);
        cout << "Звонок с телефона" << endl;
    }

    void formattedOutput() 
    {
        int num = 123;
        printf("Число: %d\n", num); // выводит строку и значение переменной с переводом строки
        printf("Число в hex: %x\n", num); // выводит значение переменной в шестнадцатеричном формате
        printf("Число в oct: %o\n", num); // выводит значение переменной в восьмеричном формате
        printf("Число в scientific: %e\n", (float)num); // выводит значение переменной в научном формате
    }

    void formattedInput() 
    {
        int num;
        printf("Введите число: ");
        scanf_s("%d", &num); // считывает значение, введенное пользователем, и сохраняет в переменную num
        printf("Вы ввели: %d\n", num);
    }
};

struct Smartphone: Phone
{
public:
    Smartphone(string _model, string _processor, int _ram): Phone(_model, _processor, _ram)
    {
    
    }

    void sendMessage() {
        cout << "Отправка сообщения с " << model << endl;
    }
};

struct IPhone12: Phone
{

public:
    IPhone12() : Phone("IPhone12", "A15 Bionic", 4)
    {
    }

    void sendMessage() {
        cout << "Отправка сообщения с " << model << endl;
    }
};


class Laptop 
{
public:
    string model;
    string processor;
    double screenSize;

    Laptop(string _model, string _processor, double _screenSize)
        : model(_model), processor(_processor), screenSize(_screenSize) {}

    void runApplication() {
        cout << "Запуск приложения на " << model << endl;
    }

    void connectToWiFi() {
        cout << "Подключение к Wi-Fi на " << model << endl;
    }
};

class TV
{
public:
    string model;
    string resolution;
    double screenSize;

    TV(string _model, string _resolution, double _screenSize)
        : model(_model), resolution(_resolution), screenSize(_screenSize) {}

    void turnOn() {
        cout << "Включение " << model << endl;
    }

    void changeChannel() {
        cout << "Смена канала на " << model << endl;
    }

    void adjustVolume() {
        cout << "Регулировка громкости на " << model << endl;
    }
};

class Camera
{
public:
    string model;
    int resolution;
    string lensType;

    Camera(string _model, int _resolution, string _lensType)
        : model(_model), resolution(_resolution), lensType(_lensType) {}

    void takePhoto() {
        cout << "Съемка фотографии с " << model << endl;
    }

    void recordVideo() {
        cout << "Запись видео с " << model << endl;
    }

    void adjustSettings() {
        cout << "Изменение настроек камеры " << model << endl;
    }
  //  printf();
};


class Headphones 
{
public:
    string model;
    string type;
    string frequencyRange;

    Headphones(string _model, string _type, string _frequencyRange)
        : model(_model), type(_type), frequencyRange(_frequencyRange) {}

    void playMusic() {
        cout << "Воспроизведение музыки с " << model << endl;
    }

    void answerCall() {
        cout << "Ответ на вызов с " << model << endl;
    }

    void adjustVolume() {
        cout << "Регулировка громкости на " << model << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    Smartphone iphone13("iPhone 13", "A15 Bionic", 4);
    Smartphone iphone14("iPhone 14", "A15 Bionic", 4);
    Smartphone galaxyS21("Galaxy S21", "Exynos 2100", 8);
    Laptop macbookPro("MacBook Pro 2021", "Apple M1", 13.3);
    TV lgOLED("LG OLED65C1PUB", "4K", 65);
    Camera canonEOS("Canon EOS R5", 45, "RF");
    Headphones airPods("AirPods Pro", "беспроводные", "20 Гц - 20 кГц");

    //Наследование
    IPhone12 iphone12 = IPhone12();
    iphone12.makeCall();
    iphone12.formattedInput();
    iphone12.formattedOutput();

    iphone13.makeCall();
    iphone14.makeCall();
    galaxyS21.sendMessage();
    macbookPro.runApplication();
    lgOLED.turnOn();
    canonEOS.takePhoto();
    airPods.playMusic();
}
