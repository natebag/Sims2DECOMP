// EGlobal::FreeSpriteRenderer(cXObject *)
// Address: 0x800416B8 | Size: 44 bytes

struct cXObject;
struct EGlobal {
    char pad[0x10C];
    void *m_spriteRenderer; // offset 0x10C
    void FreeSpriteRenderer(cXObject *obj);
};

void EGlobal__FreeSpriteRenderer(EGlobal *thisPtr, cXObject *obj) {
    if (thisPtr->m_spriteRenderer != 0) {
        thisPtr->FreeSpriteRenderer(obj);
    }
}
