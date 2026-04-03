// 0x80321DB4 (8 bytes)
class ArcFileInfo {
public:
    int GetCopiedSize();
};

int ArcFileInfo::GetCopiedSize() {
    return *(int*)((char*)this + 0xC);
}
