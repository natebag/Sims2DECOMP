struct Ret;

class Cls_8012C7E4 {
public:
    char m_pad[1016];
    Ret* GetPtr();
};

Ret* Cls_8012C7E4::GetPtr() {
    return (Ret*)((char*)this + 1016);
}
