struct Ret;
class Cls_8012C778 {
public:
    char m_pad[8];
    Ret* GetPtr();
};

Ret* Cls_8012C778::GetPtr() {
    return (Ret*)((char*)this + 8);
}
