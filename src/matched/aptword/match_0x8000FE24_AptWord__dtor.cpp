// 0x8000FE24 AptWord::~AptWord(void) (176B)

extern int AptWord_vt[];
extern void __builtin_delete(void* p);

class ISymbol {
public:
    virtual void V0(); virtual void V1(); virtual void V2(); virtual void V3();
    virtual void V4(); virtual void V5(); virtual void V6(); virtual void V7();
    virtual void V8(); virtual void V9(); virtual void V10(); virtual void V11();
    virtual void V12(); virtual void V13(); virtual void V14(); virtual void V15();
    virtual void V16(); virtual void V17(); virtual void V18(); virtual void V19();
    virtual void V20(); virtual void V21(); virtual void V22(); virtual void V23();
    virtual void V24(); virtual void V25(); virtual void V26(); virtual void V27();
    virtual void V28(); virtual void V29(); virtual void V30(); virtual void V31();
    virtual void V32(); virtual void V33(); virtual void V34();
    virtual void Release(int);   // slot 1 in MI at offset 140's vtable: actually offset 8 of vt2
};

class Container140 {
public:
    char pad[140];
    int* m_subvt;   // 140 (vtable at offset 140)
};

class AptWord {
public:
    char pad_00[8];
    void* m_field8;       // 8 (heap-alloc)
    Container140* m_field12;
    Container140* m_field16;
    char pad_14[24];
    int* m_vt;             // 44 (sigh — MI inheritance)
};

extern "C" void AptWord_dtor(AptWord* self, int in_charge) {
    char* s = (char*)self;
    void* f8 = *(void**)(s + 8);
    *(int**)(s + 44) = AptWord_vt;
    if (f8 != 0) __builtin_delete(f8);
    Container140* c12 = *(Container140**)(s + 12);
    if (c12 == 0) goto skip;
    // vcall on c12: vtable at +140, slot 1 (offset 8)
    {
        int* vt = *(int**)((char*)c12 + 140);
        short adj = *(short*)((char*)vt + 8);
        void (*fn)(void*, int) = *(void(**)(void*, int))((char*)vt + 12);
        fn((char*)c12 + adj, 3);
    }
    {
        Container140* c16 = *(Container140**)(s + 16);
        if (c16 != 0) {
            int* vt = *(int**)((char*)c16 + 140);
            short adj = *(short*)((char*)vt + 8);
            void (*fn)(void*, int) = *(void(**)(void*, int))((char*)vt + 12);
            fn((char*)c16 + adj, 3);
            *(void**)(s + 16) = 0;
        }
    }
skip:
    if (in_charge & 1) {
        __builtin_delete(self);
    }
}
