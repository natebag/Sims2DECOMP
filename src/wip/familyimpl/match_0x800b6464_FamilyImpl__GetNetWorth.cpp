/* 0x800b6464 (60 bytes) - FamilyImpl::GetNetWorth(void) */
extern void* g_familyImplHelper;  // SDA -21476(r13)

class FamilyImpl {
public:
    int GetNetWorth(void);
};

int FamilyImpl::GetNetWorth() {
    void* obj = g_familyImplHelper;
    void* vtable = *(void**)obj;
    short offset = *(short*)((char*)vtable + 56);
    void* func = *(void**)((char*)vtable + 60);
    void* inst = (char*)obj + offset;
    return ((int (*)(void*, FamilyImpl*))func)(inst, this);
}
