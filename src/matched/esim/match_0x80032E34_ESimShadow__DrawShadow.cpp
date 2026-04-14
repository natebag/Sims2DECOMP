/* ESimShadow::DrawShadow(ELevelDrawData &) at 0x80032E34 (84B) */

struct ELevelDrawData;
struct ERC;

struct SAnimator2 {
    void DrawPropsShadow(ERC *rc);
};

struct EIStaticModel {
    void DrawShadow(ELevelDrawData &data);
};

struct ELevelDrawData {
    char pad[0x98];
    ERC *m_rc;
};

struct ESimShadow : public EIStaticModel {
    char pad_base[0x320 - sizeof(EIStaticModel)];
    void *m_person;  /* 0x320 - cXPerson* */

    void DrawShadow(ELevelDrawData &data);
};

/* cXPerson vtable at offset 4, entry 49 (offset 392) = GetSAnimator */
typedef SAnimator2 *(*GetSAnimatorFn)(void *);

inline SAnimator2 *cXPerson_GetSAnimator(void *person)
{
    void **vt = *((void ***)(((char *)person) + 4));
    short adj = *(short *)((char *)vt + 392);
    GetSAnimatorFn fn = *(GetSAnimatorFn *)((char *)vt + 396);
    void *adjusted = (char *)person + adj;
    return fn(adjusted);
}

void ESimShadow::DrawShadow(ELevelDrawData &data)
{
    EIStaticModel::DrawShadow(data);
    SAnimator2 *anim = cXPerson_GetSAnimator(m_person);
    anim->DrawPropsShadow(data.m_rc);
}
