int CIH_GetType(void *);
int CIH_IsVisible(void *);

struct CIH_IsButtonS {
    int isButtonInst(int checkVisible);
};

int CIH_IsButtonS::isButtonInst(int checkVisible) {
    int result = 0;
    if (CIH_GetType(this) == 0x0E) {
        if (checkVisible == 0) {
            if (CIH_IsVisible(this) == 0) {
                result = 1;
            }
        }
    }
    return result;
}
