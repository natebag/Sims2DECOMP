// 0x803A8EF4 (8 bytes)
class PassiveInfluenceTarget {
public:
    int GetTileVector();
};

int PassiveInfluenceTarget::GetTileVector() {
    return (int)((char*)this + 0x8);
}
