// CUnlockDisplay::SetupForSocial(void)
// Address: 0x80077DD4 | Size: 40 bytes
// DOL:
//   stwu r1,-8(r1); mflr r0; stw r0,12(r1)
//   li r0,3; stw r0,1100(r3)
//   bl CUnlockDisplay::makeObjects
//   epilogue

struct CUnlockDisplay {
    char pad[0x44C];
    int field_44C;  // offset 1100

    void SetupForSocial();
    void makeObjects();
};

void CUnlockDisplay::SetupForSocial() {
    field_44C = 3;
    makeObjects();
}
