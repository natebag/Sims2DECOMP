// 0x80321DA4 (8 bytes)
class ArcFileInfo {
public:
    int GetName();
};

int ArcFileInfo::GetName() {
    return *(int*)((char*)this + 0x0);
}
