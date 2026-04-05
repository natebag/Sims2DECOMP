int CIH_GetType(void *);
int CIH_IsVisible(void *);

struct CIH_IsSpriteS {
    int isSpriteInst(int checkVisible);
};

int CIH_IsSpriteS::isSpriteInst(int checkVisible) {
    int result = 0;
    if (CIH_GetType(this) == 0x0D && checkVisible == 0) {
        if (CIH_IsVisible(this) == 0) {
            result = 1;
        }
    }
    return result;
}
