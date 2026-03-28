// 0x801358C0 (8 bytes)
class iResFile {
public:
    void SetResFileData(int p);
};

void iResFile::SetResFileData(int p) {
    *(int*)((char*)this + 0x8) = p;
}
