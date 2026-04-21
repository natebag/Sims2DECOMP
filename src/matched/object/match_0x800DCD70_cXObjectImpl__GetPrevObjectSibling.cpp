// 0x800DCD70 cXObjectImpl::GetPrevObjectSibling(void) (76B)
// Pattern: EdithVariableSet prop lookup (key=14) + null check + delegation to HierGetParent
extern short* GetSomeProp(void* ctx, int key);  // EdithVariableSet::operator[]

struct cXObjectImpl {
    char pad[40];
    void* HierGetParent();
    void* GetPrevObjectSibling();
};

void* cXObjectImpl::GetPrevObjectSibling() {
    short* p = GetSomeProp((char*)this + 40, 14);
    if (*p != 0) return 0;
    return HierGetParent();
}
