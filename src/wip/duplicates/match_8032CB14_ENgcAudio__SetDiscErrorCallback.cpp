// 0x8032CB14 (8 bytes)
class ENgcAudio {
public:
    void SetDiscErrorCallback(int p);
};

void ENgcAudio::SetDiscErrorCallback(int p) {
    *(int*)((char*)this + 0x3C) = p;
}
