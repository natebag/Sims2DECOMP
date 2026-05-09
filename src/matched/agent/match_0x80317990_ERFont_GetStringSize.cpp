// PRAGMA_STUB: ERFont::GetStringSize(char *, EWindow *, bool)
// FLAGS: -msdata=eabi -G 8
// 0x80317990 ERFont::GetStringSize (56b)
extern void Impl(int* ret, void* self, char* str, int zero, int flag, void* window);

int* ERFont_GetStringSize(int* retptr, void* self, char* str, void* window, int flag) {
    Impl(retptr, self, str, 0, flag, window);
    return retptr;
}
