// 0x800C6E44 (120 bytes)
// cXMTObjectImpl::SetMultiObjectData(int, int)

class cXMTObjectImpl {
public:
    void SetMultiObjectData(int a, int b);
};

void cXMTObjectImpl::SetMultiObjectData(int a, int b) {
    void* head = *(void**)((char*)this + 0x0C);
    void* node = this;
    if (head) node = head;
    while (node) {
        char* obj = *(char**)node;
        char* sub = *(char**)(obj + 4);
        char* vtbl = *(char**)(sub + 4);
        short adj = *(short*)(vtbl + 0x1E8);
        void* fn = *(void**)(vtbl + 0x1EC);
        ((void (*)(void*, int, short))fn)(sub + adj, a, (short)b);
        node = *(void**)((char*)node + 8);
    }
}
