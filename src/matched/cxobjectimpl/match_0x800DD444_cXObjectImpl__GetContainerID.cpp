// 0x800DD444 (88 bytes)
// cXObjectImpl::GetContainerID(void)

struct PlacementSpec {
    char _pad[0x0C];
    void* field_C;
    char _pad2[0x08];
};

extern "C" void PlacementSpec_ctor(PlacementSpec* spec, void* obj);

class cXObjectImpl {
public:
    void* GetContainerID();
};

void* cXObjectImpl::GetContainerID() {
    PlacementSpec spec;
    PlacementSpec_ctor(&spec, this);
    void* obj = spec.field_C;
    if (!obj) return 0;
    char* sub = *(char**)((char*)obj + 4);
    char* vtbl = *(char**)((char*)sub + 4);
    short adj = *(short*)(vtbl + 0x328);
    void* fn = *(void**)(vtbl + 0x32C);
    return ((void* (*)(void*))fn)(sub + adj);
}
