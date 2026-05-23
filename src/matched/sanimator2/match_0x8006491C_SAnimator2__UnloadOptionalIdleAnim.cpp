/* 0x8006491C (292 bytes) - SAnimator2::UnloadOptionalIdleAnim(void) */
typedef unsigned char u8;

extern char _animman[];
void GetStdAnimRef__cXPerson_ptr__StdAnimIdx__AnimRef_ptrr(u8* person, int type, u8** outRef);
u8* EResourceManager__GetRef_unsigned_int(u8* mgr, unsigned int id);
void EResourceManager__DelRef_unsigned_int_int(u8* mgr, unsigned int id, int mode);
void EResourceManager__DelRefAsync_unsigned_int(u8* mgr, unsigned int id);

struct SAnimator2 {
    char pad[4];
    u8* m_pPerson;
    char pad2[0x5F2];
    u8  m_portalModeType;
    char pad3[0x21];
    unsigned int m_flags;
    void UnloadOptionalIdleAnim();
};

void SAnimator2::UnloadOptionalIdleAnim() {
    int animType = -1;
    if (m_flags & 0x00100000u) {
        switch (m_portalModeType) {
        case 5:  animType = 60; break;
        case 9:  animType = 58; break;
        case 7:  animType = 62; break;
        case 8:  animType = 63; break;
        case 14: animType = 64; break;
        case 15: animType = 61; break;
        }
        if (animType != -1) {
            u8* animRef;
            GetStdAnimRef__cXPerson_ptr__StdAnimIdx__AnimRef_ptrr(m_pPerson, animType, &animRef);
            if (EResourceManager__GetRef_unsigned_int((u8*)_animman, *(unsigned int*)animRef)) {
                EResourceManager__DelRef_unsigned_int_int((u8*)_animman, *(unsigned int*)animRef, 1);
            } else {
                EResourceManager__DelRefAsync_unsigned_int((u8*)_animman, *(unsigned int*)animRef);
            }
        }
        m_flags &= ~0x00100000u;
    }
    m_portalModeType = 0;
    m_flags &= ~0x08000000u;
}
