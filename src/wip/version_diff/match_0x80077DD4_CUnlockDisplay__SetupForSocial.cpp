// CUnlockDisplay::SetupForSocial(void *)
// Address: 0x80077DD4 | Size: 40 bytes

struct CUnlockDisplay {
    char pad[0x44C];
    int field_44C;
    void InitSocial(void *);
};

void CUnlockDisplay__SetupForSocial(void *ptr) {
    CUnlockDisplay *thisPtr = (CUnlockDisplay *)ptr;
    thisPtr->field_44C = 3;
    thisPtr->InitSocial(ptr);
}
