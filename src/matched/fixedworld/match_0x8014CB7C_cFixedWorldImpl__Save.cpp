// 0x8014CB7C cFixedWorldImpl::Save(iResFile*, int) (144B)

class _c2DArray {
public:
    int WriteToDisk(int file, unsigned int magic, short num, bool flag);
};

class cFixedWorldImpl {
public:
    char pad_00[44];
    _c2DArray* m_arr44;       // 44
    char pad_30[4];
    _c2DArray* m_arr52;       // 52
    _c2DArray* m_arr56;       // 56
    int Save(int file, int unused);
};

int cFixedWorldImpl::Save(int file, int /*u*/) {
    int r;
    r = m_arr44->WriteToDisk(file, 0x41727279, 11, true);
    if (r != 0) return r;
    m_arr56->WriteToDisk(file, 0x41727279, 12, true);
    r = m_arr52->WriteToDisk(file, 0x41727279, 8, true);
    if (r != 0) return r;
    return 0;
}
