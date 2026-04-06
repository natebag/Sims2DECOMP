// EGlobal::FreeSpriteRenderer(cXObject *)
// Address: 0x800416B8 | Size: 44 bytes
// FLAGS: -fno-elide-constructors

struct cXObject;

struct EGlobal {
    char pad[0x10C];
    void *m_spriteRenderer;
};

extern "C" void EGlobal_FreeSpriteRenderer(EGlobal* self, cXObject* obj);

void EGlobal__FreeSpriteRenderer(EGlobal* thisPtr, cXObject* obj) {
    if (thisPtr->m_spriteRenderer) {
        EGlobal_FreeSpriteRenderer(thisPtr, obj);
    }
}
