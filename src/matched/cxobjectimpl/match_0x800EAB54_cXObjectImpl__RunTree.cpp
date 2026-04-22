// 0x800EAB54 (112 bytes)
// cXObjectImpl::RunTree(char*)

class cXObjectImpl {
public:
    void RunTree(char* tree);
};

void cXObjectImpl::RunTree(char* tree) {
    char* sub = *(char**)((char*)this + 4);
    char* vtbl = *(char**)((char*)sub + 4);
    short adj1 = *(short*)(vtbl + 0x378);
    char* vcall2_ptr = vtbl + 0xF0;
    void* fn1 = *(void**)(vtbl + 0x37C);
    char* this1 = sub + adj1;
    short adj2 = *(short*)vcall2_ptr;
    char* this2 = sub + adj2;
    void* result = ((void* (*)(void*))fn1)(this1);
    void* fn2 = *(void**)(vcall2_ptr + 4);
    ((void (*)(void*, void*, int, char*, int))fn2)(this2, result, 0, tree, 0);
}
