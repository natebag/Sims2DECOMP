/* EString::ConvertToBackslashes(char*) @ 0x802D3FD8 (44 bytes) */
/* Canonical class layout from include/types/EString.h */

class EString {
public:
    static void ConvertToBackslashes(char* str);
};

void EString::ConvertToBackslashes(char* str) {
    unsigned char c = *str;
    if (c == 0) return;
    do {
        if (c == '/') {
            *str = '\\';
        }
        c = *++str;
    } while (c != 0);
}
