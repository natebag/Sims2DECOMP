// 0x800C1C7C (8 bytes)
class Interaction {
public:
    int GetPerson();
};

int Interaction::GetPerson() {
    return *(int*)((char*)this + 0x8);
}
