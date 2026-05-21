// 0x800F1520 (88B) ObjectFolderImpl::GetRumbleByName(char *)
// ASMPROC_swap_adj: a=lwz b=lis which=first

extern char str_RumbleTypeName[];

extern "C" void* helper_0x8031BA74(void* mgr, const char* type_name);
extern "C" void* helper_0x8031BB94(void* mgr, void* type, char* name);

class ObjectFolderImpl {
public:
    void* GetRumbleByName(char* name);
};

void* ObjectFolderImpl::GetRumbleByName(char* name) {
    void* mgr = *(void**)((char*)this + 1680);
    void* type = helper_0x8031BA74(mgr, str_RumbleTypeName);
    mgr = *(void**)((char*)this + 1680);
    void* result = helper_0x8031BB94(mgr, type, name);
    if (result) return result;
    return 0;
}
