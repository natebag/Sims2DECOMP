// 0x800752B4 SimsMemCardWrap::HasInvalidGame (80b)

extern void* g_nghFileDesc;
extern int NghResFile__IsSaveGameValid_char_ptr__int__bool_ref(void*, int, int*);

int SimsMemCardWrap_HasInvalidGame(int slot, int* result, int /*index*/) {
    int local = 1;
    int ret = NghResFile__IsSaveGameValid_char_ptr__int__bool_ref(g_nghFileDesc, slot, &local);
    *result = local ^ 1;
    return ret;
}
