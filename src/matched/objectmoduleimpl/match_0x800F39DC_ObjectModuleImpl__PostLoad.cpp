// 0x800F39DC ObjectModuleImpl::PostLoad(iResFile*, int, bool) (128B)

struct iResFile;

struct OMNode {
    char pad0[92];
    OMNode* m_next;      // offset 92
    char pad1[236 - 96];
    int* m_vtbl;          // offset 236
};

struct ObjectModuleImpl {
    char pad[44];
    OMNode* m_first;      // offset 44
    void PostLoad(iResFile* file, int a2, bool a3);
};

extern "C" void ObjMod_PostLoadCleanup1(ObjectModuleImpl* self, iResFile* file);  // 0x800f36e4
extern "C" void ObjMod_PostLoadCleanup2(ObjectModuleImpl* self);                   // 0x800f587c

void ObjectModuleImpl::PostLoad(iResFile* file, int a2, bool a3) {
    OMNode* n = m_first;
    while (n != 0) {
        int* vt = n->m_vtbl;
        short adj = *(short*)((char*)vt + 48);
        void (*fn)(void*, int, bool) = (void (*)(void*, int, bool))*(void**)((char*)vt + 52);
        fn((char*)n + adj, a2, a3);
        n = n->m_next;
    }
    ObjMod_PostLoadCleanup1(this, file);
    ObjMod_PostLoadCleanup2(this);
}
