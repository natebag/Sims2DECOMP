// 0x802F2358 (8 bytes)
class EGraphics {
public:
    int IsInsideBeginEnd();
};

int EGraphics::IsInsideBeginEnd() {
    return *(int*)((char*)this + 0x4);
}
