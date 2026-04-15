struct DateResult {
    int sec;
    int min;
    int hour;
    int day;
    int month;
    int year;
};

int ParseDate(DateResult* out, char* str);

int XmlConvEpoch2Date(char* str, int* year, int* month, int* day, int* hour, int* min, int* sec) {
    DateResult result;
    char pad[16];
    int ret = -1;
    if (ParseDate(&result, str) != 0) {
        if (year != 0) { *year = result.year; }
        if (month != 0) { *month = result.month; }
        if (day != 0) { *day = result.day; }
        if (hour != 0) { *hour = result.hour; }
        if (min != 0) { *min = result.min; }
        if (sec != 0) { *sec = result.sec; }
        ret = 0;
    }
    return ret;
}
