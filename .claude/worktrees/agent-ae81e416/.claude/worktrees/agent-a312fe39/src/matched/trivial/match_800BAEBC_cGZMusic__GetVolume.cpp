// 0x800BAEBC (8 bytes)
class cGZMusic {
public:
    int GetVolume();
};

int cGZMusic::GetVolume() {
    return *(int*)((char*)this + 0x14);
}
