/* EString::ConvertToForwardslashes(char*) @ 0x802D4004 (44 bytes) */
/* Canonical class layout from include/types/EString.h */

class EString {
public:
    static void ConvertToForwardslashes(char* str);
};

void EString::ConvertToForwardslashes(char* str) {
    unsigned char c = *str;
    if (c == 0) return;
    do {
        if (c == '\\') {
            *str = '/';
        }
        c = *++str;
    } while (c != 0);
}
