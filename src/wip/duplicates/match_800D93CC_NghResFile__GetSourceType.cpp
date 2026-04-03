// 0x800D93CC (8 bytes)
class NghResFile {
public:
    int GetSourceType();
};

int NghResFile::GetSourceType() {
    return *(int*)((char*)this + 0x20);
}
