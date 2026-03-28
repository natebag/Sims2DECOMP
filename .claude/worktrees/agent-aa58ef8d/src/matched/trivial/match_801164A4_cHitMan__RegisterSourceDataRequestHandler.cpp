// 0x801164A4 (8 bytes)
class cHitMan {
public:
    int RegisterSourceDataRequestHandler(int p);
};

int cHitMan::RegisterSourceDataRequestHandler(int p) {
    *(int*)((char*)this + 0x30) = p; return 1;
}
