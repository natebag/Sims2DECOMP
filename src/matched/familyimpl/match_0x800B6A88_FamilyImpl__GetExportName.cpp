// 0x800B6A88 (100B) FamilyImpl::GetExportName(StringBuffer2 *)

class StringBuffer2;
extern char strFamilyImpl_prefix[];  // 0x803D99D8
extern "C" void helper_0x800A6D58(StringBuffer2* sb, const char* s, int n);
extern "C" void helper_0x800A71C4(StringBuffer2* sb, int v);

class FamilyImpl {
public:
    void GetExportName(StringBuffer2* out);
};

void FamilyImpl::GetExportName(StringBuffer2* out) {
    char* vt = *(char**)this;
    short adj = *(short*)(vt + 128);
    void* fn = *(void**)(vt + 132);
    ((void (*)(void*))fn)((char*)this + adj);
    helper_0x800A6D58(out, strFamilyImpl_prefix, -1);
    helper_0x800A71C4(out, *(int*)((char*)this + 8));
}
