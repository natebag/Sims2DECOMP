// 0x802F1350 EGraphics::FreeDL (64b)
// FLAGS: -fno-elide-constructors
// TEST: Explicit sub-object pointer technique

struct EGraphics_SubObj {
    virtual void Free(int);
};

struct EGraphics {
    char pad[0x64];
    EGraphics_SubObj* subObj;
};

void EGraphics_FreeDL(EGraphics* self) {
    // Explicit sub-object pointer forces intermediate register
    EGraphics_SubObj* sub = self->subObj;
    if (sub) {
        sub->Free(3);
    }
}
