typedef unsigned char u8;
extern int VT_EFontCharacter__New[];
u8* alloc_EFontCharacter__New(int);
u8* EFontCharacter__New() {
    u8* obj = alloc_EFontCharacter__New(16);
    *(int**)(obj) = VT_EFontCharacter__New;
    return obj;
}
