// 0x8006491C SAnimator2::UnloadOptionalIdleAnim(void) (292 B)
typedef unsigned char u8;

extern char _animman[];
void GetStdAnimRef__cXPerson_ptr__StdAnimIdx__AnimRef_ptrr(u8* person, int type, u8** outRef);
u8* EResourceManager__GetRef_unsigned_int(u8* mgr, unsigned int id);
void EResourceManager__DelRef_unsigned_int_int(u8* mgr, unsigned int id, int mode);
void EResourceManager__DelRefAsync_unsigned_int(u8* mgr, unsigned int id);

void SAnimator2__UnloadOptionalIdleAnim_void(u8* self) {
    int animType = -1;
    if (*(unsigned int*)(self + 0x61C) & 0x00100000u) {
        switch (*(unsigned char*)(self + 0x5FA)) {
        case 5:  animType = 60; break;
        case 9:  animType = 58; break;
        case 7:  animType = 62; break;
        case 8:  animType = 63; break;
        case 14: animType = 64; break;
        case 15: animType = 61; break;
        }
        if (animType != -1) {
            u8* animRef;
            GetStdAnimRef__cXPerson_ptr__StdAnimIdx__AnimRef_ptrr(*(u8**)(self + 4), animType, &animRef);
            if (EResourceManager__GetRef_unsigned_int((u8*)_animman, *(unsigned int*)animRef)) {
                EResourceManager__DelRef_unsigned_int_int((u8*)_animman, *(unsigned int*)animRef, 1);
            } else {
                EResourceManager__DelRefAsync_unsigned_int((u8*)_animman, *(unsigned int*)animRef);
            }
        }
        *(unsigned int*)(self + 0x61C) &= ~0x00100000u;
    }
    *(unsigned char*)(self + 0x5FA) = 0;
    *(unsigned int*)(self + 0x61C) &= ~0x08000000u;
}
