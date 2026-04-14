// 0x800D6C08 NghResFile::AreHouseContentsLoaded(unsigned int) const (44B)
struct HouseEntry {
    char pad[8];
    int m_contentsFlag;
};

struct NghResFile {
    char pad[316];
    HouseEntry* m_houses[1];
};

int NghResFile__AreHouseContentsLoaded(NghResFile* self, unsigned int id) {
    HouseEntry* e = self->m_houses[id - 1];
    int r = 1;
    if (e->m_contentsFlag == 0) r = 0;
    return r;
}
