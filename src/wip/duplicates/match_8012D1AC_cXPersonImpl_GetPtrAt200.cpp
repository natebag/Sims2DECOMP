struct Ret;

class Cls_8012D1AC {
public:
    char m_pad[200];
    Ret* GetPtr();
};

Ret* Cls_8012D1AC::GetPtr() {
    return (Ret*)((char*)this + 200);
}
