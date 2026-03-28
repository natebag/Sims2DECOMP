// 0x8001EAAC (8 bytes)
class ESimsCam {
public:
    void ForceFullScreen(int p);
};

void ESimsCam::ForceFullScreen(int p) {
    *(int*)((char*)this + 0x54C) = p;
}
