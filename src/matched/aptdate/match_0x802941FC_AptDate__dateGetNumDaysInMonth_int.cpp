// 0x802941FC AptDate::dateGetNumDaysInMonth(int month, int year) (172B) — clean
//
// Returns the number of days in a (0-indexed) month: 30 for Apr/Jun/Sep/Nov,
// 28/29 for Feb (via dateIsYearLeap), 31 otherwise. The result is pre-seeded to
// 31 (the common case, hoisted before the comparison tree) and the switch lists
// every month explicitly so SN ProDG emits the full binary search.

struct AptDate {
    int dateIsYearLeap(int year);                    // @0x80294178
    int dateGetNumDaysInMonth(int month, int year);  // @0x802941FC
};

int AptDate::dateGetNumDaysInMonth(int month, int year) {
    int days = 31;
    switch (month) {
        case 0: case 2: case 4: case 6: case 7: case 9: case 11:
            days = 31;
            break;
        case 1:
            days = dateIsYearLeap(year) ? 29 : 28;
            break;
        case 3: case 5: case 8: case 10:
            days = 30;
            break;
    }
    return days;
}
