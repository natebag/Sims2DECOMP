// 0x800754CC SimsMemCardWrap::IsDifferentCard(int, bool &) (124 B)

struct NghResFile { int pad[8]; int field20; int HasCardChanged(int, void*); };
extern NghResFile* g_nghResFile;
extern char* g_nghFileDesc;
extern void CheckForFileDescriptorLeaks_char_ptr__int(char*, int);

int SimsMemCardWrap_IsDifferentCard(int slot, int* different) {
    NghResFile* file = g_nghResFile;
    if (file->field20 == 1) {
        *different = file->field20;
        return 1;
    }
    int result = file->HasCardChanged(slot, different);
    if (result != 1) {
        *different = 1;
    }
    CheckForFileDescriptorLeaks_char_ptr__int(g_nghFileDesc, slot);
    return result;
}
