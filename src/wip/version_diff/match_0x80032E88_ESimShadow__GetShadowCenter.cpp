/* ESimShadow::GetShadowCenter(EVec3 &) at 0x80032E88 (112B) */

struct EVec3 {
    float x, y, z;
};

struct SAnimator2 {
    void GetBonePos(int boneIdx, EVec3 &out);
};

struct EIStaticModel {
    SAnimator2 *GetSAnimator(void);
};

struct ESimShadow : public EIStaticModel {
    char pad_base[0x320 - sizeof(EIStaticModel)];
    void *m_person;  /* 0x320 - cXPerson* */

    void GetShadowCenter(EVec3 &out);
};

/* cXPerson vtable at offset 4, entry 49 (offset 392) = GetSAnimator */
typedef SAnimator2 *(*GetSAnimatorFn)(void *);

inline SAnimator2 *cXPerson_GetSAnimator(void *person)
{
    void **vt = *((void ***)(((char *)person) + 4));
    short adj = *(short *)((char *)vt + 392);
    GetSAnimatorFn fn = *(GetSAnimatorFn *)((char *)vt + 396);
    char *adjusted = (char *)person + adj;
    return fn((void *)adjusted);
}

/* SAnimator2 vtable entry at offset 224/228 = GetBonePos */
typedef void (*GetBonePosFn)(void *, int, EVec3 &);

inline void SAnimator2_GetBonePos(SAnimator2 *anim, int boneIdx, EVec3 &out)
{
    void **vt = (void **)*((void **)anim);
    short adj = *(short *)((char *)vt + 224);
    GetBonePosFn fn = *(GetBonePosFn *)((char *)vt + 228);
    SAnimator2 *adjusted = (SAnimator2 *)((char *)anim + adj);
    fn(adjusted, boneIdx, out);
}

void ESimShadow::GetShadowCenter(EVec3 &out)
{
    SAnimator2 *anim = cXPerson_GetSAnimator(m_person);
    SAnimator2_GetBonePos(anim, 2, out);
    out.z = 0.0f;
}
