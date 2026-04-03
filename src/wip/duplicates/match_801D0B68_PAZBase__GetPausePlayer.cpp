// 0x801D0B68 (8 bytes)
class PAZBase {
public:
    int GetPausePlayer();
};

int PAZBase::GetPausePlayer() {
    return *(int*)((char*)this + 0x84);
}
