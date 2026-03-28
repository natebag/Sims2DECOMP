// 0x800D93C0 (8 bytes)
class NghResFile {
public:
    int GetCurrentHouse();
};

int NghResFile::GetCurrentHouse() {
    return (int)((char*)(*(int*)((char*)this + 0x24)) + 0x1);
}
