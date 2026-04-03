// 0x800BADA4 (8 bytes)
class cGZMusic {
public:
    int IsPlaying();
};

int cGZMusic::IsPlaying() {
    return *(int*)((char*)this + 0x8);
}
