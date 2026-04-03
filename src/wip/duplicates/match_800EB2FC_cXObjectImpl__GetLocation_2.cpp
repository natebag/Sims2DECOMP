// 0x800EB2FC (8 bytes)
class cXObjectImpl {
public:
    int GetLocation();
};

int cXObjectImpl::GetLocation() {
    return (int)((char*)this + 0x68);
}
