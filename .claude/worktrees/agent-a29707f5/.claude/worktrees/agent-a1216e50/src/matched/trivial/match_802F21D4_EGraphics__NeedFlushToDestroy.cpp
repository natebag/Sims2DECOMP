// 0x802F21D4 (8 bytes)
class EGraphics {
public:
    int NeedFlushToDestroy();
};

int EGraphics::NeedFlushToDestroy() {
    return 1;
}
