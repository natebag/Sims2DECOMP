// 0x8017BE8C UIHDTV::IsNumber(char) (20B)
// addi,-48 + subfic,9 + li + adde = (c - '0') <= 9 ? unsigned

struct UIHDTV {
    int IsNumber(char c);
};

int UIHDTV::IsNumber(char c) {
    return (unsigned int)(c - '0') <= 9;
}
