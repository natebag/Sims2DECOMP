// 0x8012C9F8 cXPersonImpl::SetChangingOutfitMode (8B)

struct cXPerson_SetChangingOutfitMode {
    char pad[0x530];
    int m_val;
    void SetChangingOutfitMode(int v);
};

void cXPerson_SetChangingOutfitMode::SetChangingOutfitMode(int v) {
    m_val = v;
}
