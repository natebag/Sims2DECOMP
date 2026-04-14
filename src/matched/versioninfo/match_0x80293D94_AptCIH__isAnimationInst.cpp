// 0x80293D94 AptCIH::isAnimationInst (92b)

int CIH_GetType(void *);
int CIH_IsVisible(void *);

struct AptCIH_isAnimation {
    int isAnimationInst(int checkVisible);
};

int AptCIH_isAnimation::isAnimationInst(int checkVisible) {
    int result = 0;
    if (CIH_GetType(this) == 0x12) {
        if (checkVisible != 0) {
            result = 1;
        } else if (CIH_IsVisible(this) == 0) {
            result = 1;
        }
    }
    return result;
}
