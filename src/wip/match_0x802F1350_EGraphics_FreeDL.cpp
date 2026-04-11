// 0x802F1350 EGraphics::FreeDL (64b)
// FLAGS: -fno-elide-constructors

struct EGraphics_SubObj {
    void* vtable;
    virtual void Free(int);
};

struct EGraphics {
    char pad[0x64];
    EGraphics_SubObj* subObj;
};

// C-style function that matches DOL null-check pattern
void EGraphics_FreeDL(EGraphics* self) {
    if (!self) return;
    if (self->subObj) {
        self->subObj->Free(3);
    }
}
