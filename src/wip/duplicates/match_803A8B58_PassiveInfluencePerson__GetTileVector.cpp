// 0x803A8B58 (8 bytes)
class PassiveInfluencePerson {
public:
    int GetTileVector();
};

int PassiveInfluencePerson::GetTileVector() {
    return (int)((char*)this + 0x8);
}
