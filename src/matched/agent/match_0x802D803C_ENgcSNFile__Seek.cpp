// 0x802D803C ENgcSNFile::Seek(int, EFile::SeekType) (68B)

struct ENgcSNFile {
    char pad00[0x14];
    int m_size;
    char pad18[0x18];
    int m_pos;
    char pad34[0x8];
    int m_dirty;

    int Seek(int offset, int origin);
};

int ENgcSNFile::Seek(int offset, int origin) {
    if (origin == 1) {
        m_pos += offset;
    } else if (origin == 0) {
        m_pos = offset;
    } else {
        m_pos = m_size - offset;
    }
    m_dirty = 1;
    return m_pos;
}
