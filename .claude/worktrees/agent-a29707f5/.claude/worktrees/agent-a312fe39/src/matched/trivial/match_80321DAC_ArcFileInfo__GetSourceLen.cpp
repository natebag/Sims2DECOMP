// 0x80321DAC (8 bytes)
class ArcFileInfo {
public:
    int GetSourceLen();
};

int ArcFileInfo::GetSourceLen() {
    return *(int*)((char*)this + 0x8);
}
