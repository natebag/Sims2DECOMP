// 0x800C1D64 (8 bytes)
class Interaction {
public:
    int GetLocalVars();
};

int Interaction::GetLocalVars() {
    return *(int*)((char*)this + 0x24);
}
