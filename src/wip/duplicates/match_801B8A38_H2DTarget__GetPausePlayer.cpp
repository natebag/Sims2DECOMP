// 0x801B8A38 (8 bytes)
class H2DTarget {
public:
    int GetPausePlayer();
};

int H2DTarget::GetPausePlayer() {
    return *(int*)((char*)this + 0xD0);
}
