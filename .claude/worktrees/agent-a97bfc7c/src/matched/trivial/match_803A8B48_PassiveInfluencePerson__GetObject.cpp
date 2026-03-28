// 0x803A8B48 (8 bytes)
class PassiveInfluencePerson {
public:
    int GetObject();
};

int PassiveInfluencePerson::GetObject() {
    return *(int*)((char*)this + 0x4);
}
