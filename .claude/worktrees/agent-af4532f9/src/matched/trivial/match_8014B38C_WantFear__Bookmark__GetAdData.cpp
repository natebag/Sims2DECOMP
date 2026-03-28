// 0x8014B38C (8 bytes)
class WantFear {
public:
    class Bookmark {
    public:
        int GetAdData();
    };
};

int WantFear::Bookmark::GetAdData() {
    return (int)((char*)(*(int*)((char*)this + 0x4)) + 0x10);
}
