// 0x8017529C (8 bytes)
class CasSimState {
public:
    int GetStoredSimDescription();
};

int CasSimState::GetStoredSimDescription() {
    return (int)((char*)this + 0x12C);
}
