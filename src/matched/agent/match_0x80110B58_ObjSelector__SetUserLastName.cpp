// 0x80110B58 ObjSelector::SetUserLastName(BString2 &) (92B)
//
// Sister of SetUserName @ 0x80110A80 — identical recipe, only differs in
// field offset (136 vs 132). 2-INSTANCE validation of "ctor-returns-this
// hint" technique (declare void* return type on the BString2_ctor extern).

class BString2;
extern "C" void* MainHeap();
extern "C" void* EAHeap_Malloc(void* heap, unsigned int sz, int flag);
extern "C" void* BString2_ctor(void* p);
extern "C" void BString2_op_assign(void* p, BString2& other);

class ObjSelector {
public:
    void SetUserLastName(BString2& name);
};

void ObjSelector::SetUserLastName(BString2& name) {
    void* p = *(void**)((char*)this + 136);
    if (p == 0) {
        void* heap = MainHeap();
        void* mem = EAHeap_Malloc(heap, 4, 0);
        *(void**)((char*)this + 136) = BString2_ctor(mem);
    }
    BString2_op_assign(*(void**)((char*)this + 136), name);
}
