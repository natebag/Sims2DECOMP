// 0x8032F954 (64B) ENgcGraphics::FreeMovie(EMovie *)
// MI vcall: non-virtual 8B base, vtable at offset 8, slot 7 (offset 56 = delta, 60 = fn).
// Release is the 7th virtual method — 6 fillers before it.

class EMovieData {
protected:
    char pad[8];
};

class EMovie : public EMovieData {
public:
    virtual void _f0() = 0;
    virtual void _f1() = 0;
    virtual void _f2() = 0;
    virtual void _f3() = 0;
    virtual void _f4() = 0;
    virtual void _f5() = 0;
    virtual void Release(int flags) = 0;
};

class ENgcGraphics {
public:
    void FreeMovie(EMovie* m);
};

void ENgcGraphics::FreeMovie(EMovie* m) {
    if (!m) return;
    m->Release(3);
}
