// 0x801E70A0 K2YTarget::GetSavedFirstName(void) (12B)
// Returns pointer to global string at 0x804FC0E4 (DOL: lis 3,-32688; addi 3,3,-16156).
// Linker resolves extern symbol; verify_match masks relocation field.

extern char g_K2YTarget_savedFirstName[];

struct K2YTarget {
    char* GetSavedFirstName();
};

char* K2YTarget::GetSavedFirstName() {
    return g_K2YTarget_savedFirstName;
}
