/* 0x800b6428 (60 bytes) - FamilyImpl::GetFriendCount(void) */
extern void* g_familyImplHelper;  // SDA -21476(r13)

class FamilyImpl {
public:
    int GetFriendCount(void);
};

int FamilyImpl::GetFriendCount() {
    void* obj = g_familyImplHelper;
    void* vtable = *(void**)obj;
    short offset = *(short*)((char*)vtable + 48);
    void* func = *(void**)((char*)vtable + 52);
    void* inst = (char*)obj + offset;
    return ((int (*)(void*, FamilyImpl*))func)(inst, this);
}
