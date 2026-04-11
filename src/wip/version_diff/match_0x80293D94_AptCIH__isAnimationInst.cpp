int CIH_GetType(void *);
int CIH_IsVisible(void *);

struct CIH_IsAnimS {
    int isAnimationInst(int checkVisible);
};

int CIH_IsAnimS::isAnimationInst(int checkVisible) {
    int result = 0;
    if (CIH_GetType(this) == 0x12) {
        if (checkVisible == 0) {
            if (CIH_IsVisible(this) == 0) {
                result = 1;
            }
        }
    }
    return result;
}
