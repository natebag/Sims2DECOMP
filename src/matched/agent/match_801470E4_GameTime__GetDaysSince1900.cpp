/* GameTime::GetDaysSince1900(int, int, int) at 0x801470E4 (128B) */

int CountDaysInMonth(int year, int month);

int GetDaysSince1900(int year, int month, int day) {
    if (year <= 1899) return 0;
    if ((unsigned)(month - 1) > 11) return 0;

    int days = day - 1;
    int m;
    for (m = 1; m < month; m++) {
        days += CountDaysInMonth(year, m);
    }
    return days + (year - 1900) * 360;
}
