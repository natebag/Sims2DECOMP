// 0x801E70AC K2YTarget::GetSavedLastName(void) (12B)
// Returns pointer to global string at 0x804FC124 (DOL: lis 3,-32688; addi 3,3,-16092).

extern char g_K2YTarget_savedLastName[];

struct K2YTarget {
    char* GetSavedLastName();
};

char* K2YTarget::GetSavedLastName() {
    return g_K2YTarget_savedLastName;
}
