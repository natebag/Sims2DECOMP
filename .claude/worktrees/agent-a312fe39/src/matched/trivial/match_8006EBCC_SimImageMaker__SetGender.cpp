// 0x8006EBCC (8 bytes)
class SimImageMaker {
public:
    void SetGender(int p);
};

void SimImageMaker::SetGender(int p) {
    *(int*)((char*)this + 0x88) = p;
}
