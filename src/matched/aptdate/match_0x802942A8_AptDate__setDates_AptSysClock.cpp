// 0x802942A8 AptDate::setDates(AptSysClock* src, AptSysClock* dst, int offset) (312B) — clean
//
// Copies a clock from src to dst applying an hour offset, then normalizes the
// resulting day/month/year if the offset pushed the hour out of [0,23]:
//  - hour > 23: hour %= 24, advance the day (rolling month/year forward).
//  - hour <  0: hour = 24 - offset, retreat the day (rolling month/year back,
//               resetting the day to that month's length).
// h1 (stored hour, reused for the %24) and h2 (the comparison value) are read
// separately: the store to dst->hours may alias src->hours, so the compiler
// reloads src->hours for the second read rather than reusing h1.

struct AptSysClock {
    int sec;     // 0x00
    int min;     // 0x04
    int hours;   // 0x08
    int pad0C;   // 0x0C
    int day;     // 0x10  (1-based)
    int month;   // 0x14  (0-based, 0..11)
    int year;    // 0x18
    int ms;      // 0x1C
};

struct AptDate {
    int dateGetNumDaysInMonth(int month, int year);              // @0x802941FC
    void setDates(AptSysClock* src, AptSysClock* dst, int offset); // @0x802942A8
};

void AptDate::setDates(AptSysClock* src, AptSysClock* dst, int offset) {
    int year = src->year;
    dst->year = year;
    int month = src->month;
    dst->month = month;
    int day = src->day;
    dst->day = day;
    int h1 = src->hours - offset;
    dst->hours = h1;
    int h2 = src->hours - offset;
    if (h2 > 23) {
        dst->hours = h1 % 24;
        int dim = dateGetNumDaysInMonth(month, year);
        int nd = dst->day + 1;
        dst->day = nd;
        if (nd > dim) {
            dst->day = 1;
            int nm = dst->month + 1;
            dst->month = nm;
            if (nm > 11) {
                dst->month = 0;
                dst->year = dst->year + 1;
            }
        }
    } else if (h2 < 0) {
        int pd = day - 1;
        dst->hours = 24 - offset;
        dst->day = pd;
        if (pd <= 0) {
            int pm = month - 1;
            dst->month = pm;
            if (pm < 0) {
                dst->month = 11;
                dst->year = year - 1;
            }
            dst->day = dateGetNumDaysInMonth(dst->month, dst->year);
        }
    }
    dst->min = src->min;
    dst->sec = src->sec;
    dst->ms = src->ms;
}
