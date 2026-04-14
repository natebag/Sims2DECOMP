// 0x800D541C NghResFile::StoreFamilyThumbGUID(int, int, unsigned int) (64B)
struct NghResFile {
    char pad[404];
    unsigned int m_guids[36];
};

extern int NghResFile__GetThumbIdFromFamilyAndIndex(NghResFile* self, int fam, int idx);

void NghResFile__StoreFamilyThumbGUID(NghResFile* self, int fam, int idx, unsigned int guid) {
    int id = NghResFile__GetThumbIdFromFamilyAndIndex(self, fam, idx);
    self->m_guids[id - 1] = guid;
}
