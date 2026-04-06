// 0x801F0EC8 INVTarget__SetPriceCheatString_char_ptr__int__unsigned_short (52b)
// FLAGS: -fno-schedule-insns

extern void sub_802DE888(char* a, char* b, ...);

void INVTarget__SetPriceCheatString_char_ptr__int__unsigned_short(
    void* this_, 
    char* str, 
    int val, 
    unsigned short flags
) {
    sub_802DE888(str, "price", flags);
}
