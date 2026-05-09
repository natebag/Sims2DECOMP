// PRAGMA_STUB: ERFont::GetStringSize(unsigned wchar_t *, EWindow *, bool)
// FLAGS: -msdata=eabi -G 8
// 0x803179C8 ERFont::GetStringSize (56b)
extern void Impl(int* ret, void* self, unsigned short* str, int isWide, int flag, void* window);

int* ERFont_GetStringSize_wchar(int* retptr, void* self, unsigned short* str, void* window, int flag) {
    Impl(retptr, self, str, 1, flag, window);
    return retptr;
}
