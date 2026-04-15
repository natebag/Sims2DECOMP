/* UIHDTV::IsFoundNumberNegative(char *, int) - 0x8017BF2C (24 bytes) */

class UIHDTV {
public:
    int IsFoundNumberNegative(char* s, int idx);
};

int UIHDTV::IsFoundNumberNegative(char* s, int idx) {
    return s[idx - 1] == '-';
}
