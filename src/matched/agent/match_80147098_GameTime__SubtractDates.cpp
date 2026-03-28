class GameTime {
public:
    static int GetDaysSince1900(int year, int month, int day);
    static int SubtractDates(int year1, int month1, int day1, int year2, int month2, int day2);
};

int GameTime::SubtractDates(int year1, int month1, int day1, int year2, int month2, int day2) {
    int days1 = GetDaysSince1900(year1, month1, day1);
    int days2 = GetDaysSince1900(year2, month2, day2);
    return days1 - days2;
}
