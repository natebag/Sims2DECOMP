// 0x800BA668 (8 bytes)
class cGZSnd {
public:
    int GetVolume();
};

int cGZSnd::GetVolume() {
    return *(int*)((char*)this + 0x20);
}
