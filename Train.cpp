#include <iostream>
#include <cstdio>
#include "Train.hpp"

using namespace std;

static int  ReadTime();
static void PrintTime(int);

Train::Train()
{
    number = 1;
    num_of_stops = 2;
    num_of_coachs = 1;
    departure = 0;
    arrival = 3600;
}

void Train::ReadData()
{
    cout << "Номер потяга: ";
    cin >> number;

    cout << "Кількість зупинок: ";
    cin >> num_of_stops;

    cout << "Кількість вагонів: ";
    cin >> num_of_coachs;

    cout << "Відправлення [HH:MM]: ";
    departure = ReadTime();

    cout << "Прибуття [HH:MM]: ";
    arrival = ReadTime();

    return;    
}

void Train::PrintData()
{
    cout << "Номер потяга: " << number << endl;
    cout << "Кількість зупинок: " << num_of_stops << endl;
    cout << "Кількість вагонів: " << num_of_coachs << endl;

    cout << "Час відправлення: ";
    PrintTime(departure);
    cout << endl;

    cout << "Час прибуття: ";
    PrintTime(arrival);
    cout << endl;

    return;
}

void Train::PrintRideTime()
{
    const int SEC_PER_DAY = 86400;

    int ride_time = arrival-departure;
    if (ride_time <= 0) ride_time += SEC_PER_DAY;

    int hours = ride_time%SEC_PER_DAY/3600;
    int minutes = ride_time%3600/60;

    cout << "На маршрут витрачається: ";
    if (hours > 0) cout << hours << " годин, ";
    cout << minutes << " хвилин." << endl;

    return;
}

static int ReadTime()
{
    int hour, min;

    scanf("%d:%d", &hour, &min);

    return hour*3600+min*60;
}

static void PrintTime(int t)
{
    printf("%02d:%02d", t/3600, (t%3600)/60);
    return;
}

