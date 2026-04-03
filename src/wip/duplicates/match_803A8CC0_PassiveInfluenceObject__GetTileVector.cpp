// 0x803A8CC0 (8 bytes)
class PassiveInfluenceObject {
public:
    int GetTileVector();
};

int PassiveInfluenceObject::GetTileVector() {
    return (int)((char*)this + 0x8);
}
