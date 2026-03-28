// 0x802F2320 (8 bytes)
class EGraphics {
public:
    void EnableWireframe(int p);
};

void EGraphics::EnableWireframe(int p) {
    *(int*)((char*)this + 0x318) = p;
}
