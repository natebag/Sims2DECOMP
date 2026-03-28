// 0x802F21E4 (8 bytes)
class EGraphics {
public:
    int NeedFlushToDestroy();
};

int EGraphics::NeedFlushToDestroy() {
    return 1;
}
