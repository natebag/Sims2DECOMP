// 0x800C1D5C (8 bytes)
class Interaction {
public:
    int GetStackVars();
};

int Interaction::GetStackVars() {
    return (int)((char*)this + 0x18);
}
