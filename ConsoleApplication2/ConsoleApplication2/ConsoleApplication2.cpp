#include <iostream>

using namespace std;

class Smartphone 
{
public:
    string model;
    string processor;
    int ram;

    Smartphone(string _model, string _processor, int _ram)
        : model(_model), processor(_processor), ram(_ram) {}

    void makeCall() {
        cout << "Звонок с " << model << endl;
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

    iphone13.makeCall();
    iphone13.makeCall();
    galaxyS21.sendMessage();
    macbookPro.runApplication();
    lgOLED.turnOn();
    canonEOS.takePhoto();
    airPods.playMusic();
}
