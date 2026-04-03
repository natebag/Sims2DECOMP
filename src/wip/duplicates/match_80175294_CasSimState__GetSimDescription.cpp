// 0x80175294 (8 bytes)
class CasSimState {
public:
    int GetSimDescription();
};

int CasSimState::GetSimDescription() {
    return (int)((char*)this + 0x8);
}
