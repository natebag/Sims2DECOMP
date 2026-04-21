/* 0x800689fc (68 bytes) - SAnimator2::UpdateAnimationValidity(void) */
class SAnimator2 {
public:
    char pad[8];
    void* m_animData;
    void UpdateAnimationValidity(void);
};

struct AnimBlock { char data[176]; };

void SAnimator2::UpdateAnimationValidity() {
    void* animData = m_animData;
    char* block = (char*)animData + 820;
    int valid = 1;
    int track = *(int*)(block + 8);
    AnimBlock* elem;
    if (track < 0) goto L_null;
    {
        AnimBlock* base = *(AnimBlock**)(block + 68);
        elem = (AnimBlock*)((char*)base + track * 176);
    }
    goto L_check;
L_null:
    elem = 0;
L_check:
    if (elem == 0) valid = 0;
    *(int*)((char*)m_animData + 0x394) = valid;
}
