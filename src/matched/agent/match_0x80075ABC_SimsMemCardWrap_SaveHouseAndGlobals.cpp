// 0x80075ABC SimsMemCardWrap::SaveHouseAndGlobals (76b)

extern char* g_saveName;
extern void* g_nghFileDesc;
extern int NghResFile__SaveHouseAndGlobals_unsigned_char__unsigned_int(char*, unsigned char, unsigned int);
extern int CheckForFileDescriptorLeaks_char_ptr__int(void*, int);

int SimsMemCardWrap_SaveHouseAndGlobals(int slot, int houseId) {
    int result = NghResFile__SaveHouseAndGlobals_unsigned_char__unsigned_int(g_saveName, (unsigned char)slot, houseId);
    CheckForFileDescriptorLeaks_char_ptr__int(g_nghFileDesc, slot);
    return result;
}
