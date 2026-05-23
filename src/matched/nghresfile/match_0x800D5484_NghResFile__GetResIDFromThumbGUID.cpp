// 0x800D5484 NghResFile::GetResIDFromThumbGUID(unsigned int) (60B)
struct NghResFile {
    char pad[404];
    unsigned int m_guids[36];
};

unsigned int NghResFile__GetResIDFromThumbGUID(NghResFile* self, unsigned int guid) {
    unsigned int* arr = self->m_guids;
    for (int i = 0; i < 36; i++) {
        if (arr[i] == guid) return (unsigned short)(i + 1);
    }
    return 0;
}
