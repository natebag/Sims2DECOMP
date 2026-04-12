// 0x80293B50 AptCIH::isSpriteInst (92b)

int CIH_GetType(void *);
int CIH_IsVisible(void *);

struct AptCIH_isSprite {
    int isSpriteInst(int checkVisible);
};

int AptCIH_isSprite::isSpriteInst(int checkVisible) {
    int result = 0;
    if (CIH_GetType(this) == 0x0D) {
        if (checkVisible != 0) {
            result = 1;
        } else if (CIH_IsVisible(this) == 0) {
            result = 1;
        }
    }
    return result;
}
