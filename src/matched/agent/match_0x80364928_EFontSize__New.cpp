// 0x80364928 EFontSize::New (40b)
struct EFontSize {
    char _pad[44];
    EFontSize(void);
};

EFontSize *EFontSize__New(void) {
    EFontSize *p = new EFontSize;
    return p;
}
