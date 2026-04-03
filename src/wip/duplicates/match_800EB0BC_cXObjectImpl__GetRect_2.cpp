// 0x800EB0BC (8 bytes)
class cXObjectImpl {
public:
    int GetRect();
};

int cXObjectImpl::GetRect() {
    return (int)((char*)this + 0x70);
}
