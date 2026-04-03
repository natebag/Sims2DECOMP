// 0x800C1D44 (8 bytes)
class Interaction {
public:
    int GetType();
};

int Interaction::GetType() {
    return *(int*)((char*)this + 0x4);
}
