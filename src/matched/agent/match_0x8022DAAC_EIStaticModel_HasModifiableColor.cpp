// PRAGMA_STUB: EIStaticModel::HasModifiableColor(void)
// 0x8022DAAC EIStaticModel::HasModifiableColor (52b)

extern int HasModifiableColorTarget(void*);

struct EIStaticModel {
    char pad[0x120];
    void* m_color;
};

int EIStaticModel_HasModifiableColor(EIStaticModel* self) {
    void* p = self->m_color;
    if (!p) return 0;
    return HasModifiableColorTarget(p);
}
