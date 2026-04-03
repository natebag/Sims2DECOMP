// 0x8013562C (8 bytes)
class iResFile {
public:
    void SetError(int p);
};

void iResFile::SetError(int p) {
    *(int*)((char*)this + 0x4) = p;
}
