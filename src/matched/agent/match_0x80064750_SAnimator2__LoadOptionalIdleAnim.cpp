// 0x80064750 SAnimator2::LoadOptionalIdleAnim(void) (264 B)
typedef unsigned char u8;

extern char _animman[];
void GetStdAnimRef__cXPerson_ptr__StdAnimIdx__AnimRef_ptrr(u8* person, int type, u8** outRef);
u8* EResourceManager__GetRef_unsigned_int(u8* mgr, unsigned int id);
void EResourceManager__AddRefAsync_unsigned_int(u8* mgr, unsigned int id);

u8* SAnimator2__LoadOptionalIdleAnim_void(u8* self) {
    int animType;
    switch (*(unsigned char*)(self + 0x5FA)) {
    case 5:  animType = 60; break;
    case 9:  animType = 58; break;
    case 7:  animType = 62; break;
    case 8:  animType = 63; break;
    case 14: animType = 64; break;
    case 15: animType = 61; break;
    default: return 0;
    }
    u8* animRef;
    GetStdAnimRef__cXPerson_ptr__StdAnimIdx__AnimRef_ptrr(*(u8**)(self + 4), animType, &animRef);
    if (!(*(unsigned int*)(self + 0x61C) & 0x00100000u)) {
        if (!EResourceManager__GetRef_unsigned_int((u8*)_animman, *(unsigned int*)animRef)) {
            EResourceManager__AddRefAsync_unsigned_int((u8*)_animman, *(unsigned int*)animRef);
            *(unsigned int*)(self + 0x61C) |= 0x00100000u;
        } else {
            *(unsigned int*)(self + 0x61C) |= 0x08000000u;
        }
    }
    return animRef;
}
