// 0x80294178 (84 bytes) AptDate::dateIsYearLeap(int)
// Gregorian leap-year test: divisible by 4, and (not by 100, or by 400).
// The divisibility checks use the (year/N)*N == year idiom (matching the DOL's
// signed magic-division + mulli). Writing each comparison year-first
// (year != (year/100)*100) reproduces the DOL's cmpw/xor operand order and
// register allocation exactly — no register pinning needed.
struct AptDate {
    bool dateIsYearLeap(int);
};

bool AptDate::dateIsYearLeap(int year) {
    bool result = false;
    if ((year & 3) == 0) {
        if (year != (year / 100) * 100) {
            result = true;
        } else {
            result = (year == (year / 400) * 400);
        }
    }
    return result;
}
