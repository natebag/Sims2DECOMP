// 0x8015BBE8 (8 bytes)
class ObjectDataID {
public:
    void SetNamespaceID(int p);
};

void ObjectDataID::SetNamespaceID(int p) {
    *(int*)((char*)this + 0x0) = p;
}
