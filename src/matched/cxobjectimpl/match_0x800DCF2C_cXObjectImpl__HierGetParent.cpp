// 0x800DCF2C (88 bytes)
// cXObjectImpl::HierGetParent(void)

extern "C" short* helper_0x800E4040(void* obj, int idx);

class cXObjectImpl {
public:
    void* HierGetParent();
};

void* cXObjectImpl::HierGetParent() {
    char* sub = *(char**)((char*)this + 4);
    char* sub2 = *(char**)((char*)sub + 4);
    char* vcall_ptr = sub2 + 0x488;
    short adj = *(short*)vcall_ptr;
    char* adjusted = sub + adj;
    short* val = helper_0x800E4040((char*)this + 0x28, 26);
    void* fn = *(void**)(vcall_ptr + 4);
    return ((void* (*)(void*, short))fn)(adjusted, *val);
}
