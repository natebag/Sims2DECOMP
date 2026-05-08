// EFixedString::CharsEqualNoCase(char, char) - 0x802C8654 (124B)

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    static int CharsEqualNoCase(char a, char b);
};

int EFixedString::CharsEqualNoCase(char a, char b) {
    if (a == b) return 1;
    if ((unsigned int)(a - 'a') <= 25u) {
        if (b > 64) {
            if (b <= 90) {
                return (a - 32) == b;
            }
        }
    }
    if ((unsigned int)(b - 'a') <= 25u) {
        if (a > 64) {
            if (a <= 90) {
                return (b - 32) == a;
            }
        }
    }
    return 0;
}
