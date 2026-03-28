// 0x8015BBF0 (8 bytes)
class ObjectDataID {
public:
    void SetResourceID(int p);
};

void ObjectDataID::SetResourceID(int p) {
    *(short*)((char*)this + 0x4) = (short)p;
}
