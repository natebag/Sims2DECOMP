// 0x800C8860 (8 bytes)
class NamespaceSelector {
public:
    int GetTreeSetResource();
};

int NamespaceSelector::GetTreeSetResource() {
    return *(int*)((char*)this + 0x30);
}
