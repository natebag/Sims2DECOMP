// 0x80293C08 AptCIH::isButtonInst (92b)

int CIH_GetType(void *);
int CIH_IsVisible(void *);

struct AptCIH_isButton {
    int isButtonInst(int checkVisible);
};

int AptCIH_isButton::isButtonInst(int checkVisible) {
    int result = 0;
    if (CIH_GetType(this) == 0x0E) {
        if (checkVisible != 0) {
            result = 1;
        } else if (CIH_IsVisible(this) == 0) {
            result = 1;
        }
    }
    return result;
}
