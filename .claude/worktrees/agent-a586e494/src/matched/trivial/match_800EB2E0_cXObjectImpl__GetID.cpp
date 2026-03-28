// 0x800EB2E0 (8 bytes)
class cXObjectImpl {
public:
    short GetID();
};

short cXObjectImpl::GetID() {
    return *(short*)((char*)this + 0x64);
}
