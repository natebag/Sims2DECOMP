// 0x80148B7C (8 bytes)
class StackElem {
public:
    int GetParams();
};

int StackElem::GetParams() {
    return (int)((char*)this + 0x14);
}
