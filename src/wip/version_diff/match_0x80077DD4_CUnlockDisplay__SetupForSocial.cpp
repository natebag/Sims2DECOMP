// CUnlockDisplay::SetupForSocial(void *)
// Address: 0x80077DD4 | Size: 40 bytes
// FLAGS: -fno-elide-constructors

struct CUnlockDisplay {
    char pad[0x44C];
    int field_44C;
};

extern "C" void CUnlockDisplay_InitSocial(CUnlockDisplay* self, void* ptr);

void CUnlockDisplay__SetupForSocial(void *ptr) {
    CUnlockDisplay *thisPtr = (CUnlockDisplay *)ptr;
    thisPtr->field_44C = 3;
    CUnlockDisplay_InitSocial(thisPtr, ptr);
}
