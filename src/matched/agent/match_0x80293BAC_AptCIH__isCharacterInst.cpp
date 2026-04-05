int CIH_GetType(void *);
int CIH_GetXxx(void *);

struct CIH_IsCharS {
    int isCharacterInst(void);
};

int CIH_IsCharS::isCharacterInst(void) {
    int result = 0;
    if (CIH_GetType(this) > 0x0B) {
        if (CIH_GetType(this) <= 0x13) {
            result = !CIH_GetXxx(this);
        }
    }
    return result;
}
