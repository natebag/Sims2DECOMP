// 0x8032F6BC (64B) ENgcGraphics::FreeDL(EDL *, RCMode)
// MI vcall: vtable at offset 100, slot 1 (8B delta, 12B fn) = Release(int).
// RCMode mode arg unused in the dispatch (only the dl pointer goes through null check).

enum RCMode {};

class EDLData {
protected:
    char pad[100];
};

class EDL : public EDLData {
public:
    virtual void Release(int flags) = 0;
};

class ENgcGraphics {
public:
    void FreeDL(EDL* dl, RCMode mode);
};

void ENgcGraphics::FreeDL(EDL* dl, RCMode) {
    if (!dl) return;
    dl->Release(3);
}
