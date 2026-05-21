// 0x800C02B4 (100B) IFFResFile2::GetBlockHeader(IFFHeader*, int)

class MemFile;
class IFFHeader;

extern "C" int Seek_function_800A6298(MemFile*, int);
extern "C" int Read_function_800A61F0(MemFile*, IFFHeader*, int*);

class IFFResFile2 {
public:
    int GetBlockHeader(IFFHeader* hdr, int idx);
};

int IFFResFile2::GetBlockHeader(IFFHeader* hdr, int idx) {
    int size = 76;
    MemFile* mf = (MemFile*)((char*)this + 16);
    int rc1 = Seek_function_800A6298(mf, idx);
    if (rc1 != 0) return rc1;
    int rc2 = Read_function_800A61F0(mf, hdr, &size);
    if (rc2 != 0) return rc2;
    return 0;
}
