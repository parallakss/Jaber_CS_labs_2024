#include <iostream>

namespace {
const int kNominativeSingularHours = 1;
const int kGenitiveSingularHoursBegin = 2;
const int kGenitiveSingularHoursEnd = 4;

const int kNominativeSingularMinutes = 1;
const int kNominativePluralMinutesBegin = 2;
const int kNominativePluralMinutesEnd = 4;
const int kGenitivePluralMinutesBegin = 5;
const int kGenitivePluralMinutesEnd = 9;
const int kGenitivePluralMinutes = 0;
const int kTensGenitivePluralMinutes = 1;

const int kTwelveHourTimeFormat = 12;

const int kMorningBegin = 5;
const int kAfternoonBegin = 12;
const int kEveningBegin = 18;
const int kLastHourBeforeNight = 23;
const int kNightBegin = 0;

const int kMinHours = 0;
const int kMaxHours = 23;
const int kMinMinutes = 0;
const int kMaxMinutes = 59;

const int kDecimalBase = 10;
}  // namespace

int main(int, char**) {
    int minutes = 0;
    int hours = 0;

    std::cout << "Введите числовое значение чассов от 0 до 23 и минут от 0 до 59" << '\n';
    std::cin >> hours >> minutes;

    if (hours > kMaxHours || minutes > kMaxMinutes || hours < kMinHours || minutes < kMinMinutes) {
        std::cout << "Введены неправильные данные" << '\n';
        return 1;
    }

    if (minutes == kNightBegin && hours == kMinMinutes) {
        std::cout << "полночь" << '\n';
        return 0;
    } else if (hours == kAfternoonBegin && minutes == kMinMinutes) {
        std::cout << "полдень" << '\n';
        return 0;
    }

    int timeTwelveHourSystem = (hours > kTwelveHourTimeFormat) ? hours - kTwelveHourTimeFormat : hours;

    if (timeTwelveHourSystem == kNominativeSingularHours) {
        std::cout << timeTwelveHourSystem << " час ";
    } else if (timeTwelveHourSystem >= kGenitiveSingularHoursBegin && timeTwelveHourSystem <= kGenitiveSingularHoursEnd) {
        std::cout << timeTwelveHourSystem << " часа ";
    } else {
        std::cout << timeTwelveHourSystem << " часов ";
    }

    int firstDigitMinutes = minutes / kDecimalBase;
    int secondDigitMinutes = minutes % kDecimalBase;

    if (minutes != kMinMinutes) {
        if (secondDigitMinutes == kNominativeSingularMinutes && firstDigitMinutes != kTensGenitivePluralMinutes) {
            std::cout << minutes << " минута ";
        } else if (secondDigitMinutes >= kNominativePluralMinutesBegin && secondDigitMinutes <= kNominativePluralMinutesEnd &&
                   firstDigitMinutes != kTensGenitivePluralMinutes) {
            std::cout << minutes << " минуты ";
        } else if ((secondDigitMinutes >= kGenitivePluralMinutesBegin && secondDigitMinutes <= kGenitivePluralMinutesEnd) ||
                   secondDigitMinutes == kGenitivePluralMinutes || firstDigitMinutes == kTensGenitivePluralMinutes) {
            std::cout << minutes << " минут ";
        }
    }

    if (hours >= kMorningBegin && hours < kAfternoonBegin) {
        std::cout << "утра";
    } else if (hours >= kAfternoonBegin && hours < kEveningBegin) {
        std::cout << "дня";
    } else if (hours >= kEveningBegin && hours <= kLastHourBeforeNight) {
        std::cout << "вечера";
    } else if (hours >= kNightBegin && hours < kMorningBegin) {
        std::cout << "ночи";
    }

    if (minutes == kMinMinutes) {
        std::cout << " ровно";
    }
    std::cout << "\n";
    return 0;
}
