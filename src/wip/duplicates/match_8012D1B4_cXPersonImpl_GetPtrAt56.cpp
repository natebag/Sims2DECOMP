struct Ret;

class Cls_8012D1B4 {
public:
    char m_pad[56];
    Ret* GetPtr();
};

Ret* Cls_8012D1B4::GetPtr() {
    return (Ret*)((char*)this + 56);
}
