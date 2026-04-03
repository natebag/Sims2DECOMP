// 0x801358B8 (8 bytes)
class iResFile {
public:
    int GetResFileData();
};

int iResFile::GetResFileData() {
    return *(int*)((char*)this + 0x8);
}
