// 0x801997C0 CASSelectionTarget::ConvertGridStringToOptionArrayIdx(char*) (72B)

extern "C" int AtoI(char* s);

class CASSelectionTarget {
public:
    int ConvertColRowToOptionIdx(char col, int row);
    int ConvertGridStringToOptionArrayIdx(char* s);
};

int CASSelectionTarget::ConvertGridStringToOptionArrayIdx(char* s) {
    char col = *s;
    int row = AtoI(s + 1);
    return ConvertColRowToOptionIdx(col, row);
}
