class cXObject;

// External function at 0x80037190
extern "C" void sub_80037190(cXObject*);

class EGlobal {
    char pad[268];
    cXObject* m_spriteRenderer;  // offset 268
public:
    void FreeSpriteRenderer(cXObject* obj);
};

void EGlobal::FreeSpriteRenderer(cXObject* obj) {
    cXObject* renderer = this->m_spriteRenderer;
    if (renderer != 0) {
        sub_80037190(renderer);
    }
}
