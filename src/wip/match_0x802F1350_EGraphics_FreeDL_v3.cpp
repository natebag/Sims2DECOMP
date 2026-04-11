// 0x802F1350 EGraphics::FreeDL (64b)
// FLAGS: -fno-elide-constructors

struct EGraphics_SubObj {
    virtual void Free(int);
};

struct EGraphics {
    char pad[0x64];
    EGraphics_SubObj* subObj;
};

void EGraphics_FreeDL(EGraphics* self) {
    // DOL: mr r11, r3; cmpwi r11, 0
    // Explicit this check first
    if (!self) return;
    
    // Then load subObj
    EGraphics_SubObj* sub = self->subObj;
    if (sub) {
        sub->Free(3);
    }
}
