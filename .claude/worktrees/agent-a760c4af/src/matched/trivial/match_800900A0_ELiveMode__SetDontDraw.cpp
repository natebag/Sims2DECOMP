// 0x800900A0 (8 bytes)
class ELiveMode {
public:
    void SetDontDraw(int p);
};

void ELiveMode::SetDontDraw(int p) {
    *(int*)((char*)this + 0x34) = p;
}
