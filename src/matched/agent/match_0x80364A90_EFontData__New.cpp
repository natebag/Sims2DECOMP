// 0x80364A90 EFontData::New (40b)
struct EFontData {
    char _pad[56];
    EFontData(void);
};

EFontData *EFontData__New(void) {
    EFontData *p = new EFontData;
    return p;
}
