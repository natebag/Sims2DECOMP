// FLAGS: -fno-schedule-insns
// 0x80075A64 SimsMemCardWrap::ReloadHouseAndGlobals (88b)
// ASMPROC_gpr_relabel: swap=29:30, skip_opcodes=stmw,lmw

extern char* g_saveName;
extern void* g_someObj;
extern void* g_nghFileDesc;
extern int NghResFile__ReloadHouseAndGlobals_unsigned_char__unsigned_int(char*, unsigned char, unsigned int);
extern int CheckForFileDescriptorLeaks_char_ptr__int(void*, int);

int SimsMemCardWrap_ReloadHouseAndGlobals(int slot, int houseId) {
    int savedSlot = slot;
    int savedHouseId = houseId;
    int result = NghResFile__ReloadHouseAndGlobals_unsigned_char__unsigned_int(g_saveName, (unsigned char)savedSlot, savedHouseId);
    void* obj = g_someObj;
    void* nghFile = g_nghFileDesc;
    *(int*)((char*)obj + 0x0C) = 1;
    CheckForFileDescriptorLeaks_char_ptr__int(nghFile, savedSlot);
    return result;
}
