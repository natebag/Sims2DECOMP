// 0x800C0318 (136B) IFFResFile2::SetBlockHeader(IFFHeader*, int)

class MemFile;
class IFFHeader;

extern "C" int SetPos_func_800A6298(MemFile*, int);
extern "C" int WriteBlock_func_800A5C88(MemFile*, IFFHeader*, int*);

class IFFResFile2 {
public:
    char m_pad0[320];
    int m_140;        // 320
    int m_144;        // 324
    int WriteHeader(MemFile* mf, int flag);
    int SetBlockHeader(IFFHeader* hdr, int idx);
};

int IFFResFile2::SetBlockHeader(IFFHeader* hdr, int idx) {
    int dirty = m_140;
    m_144 = 1;
    if (dirty != 0) {
        int rc = WriteHeader((MemFile*)((char*)this + 16), 0);
        if (rc != 0) return rc;
    }
    MemFile* mf = (MemFile*)((char*)this + 16);
    int rc2 = SetPos_func_800A6298(mf, idx);
    if (rc2 != 0) return rc2;
    int size = 76;
    return WriteBlock_func_800A5C88(mf, hdr, &size);
}
