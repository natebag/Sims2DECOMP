// 0x8032F92C (40B) ENgcGraphics::AllocMovie(void)
// `new ENgcMovie()` — 92B object via __builtin_new + default ctor.

class ENgcMovie {
public:
    char pad[92];
    ENgcMovie();
};

class ENgcGraphics {
public:
    ENgcMovie* AllocMovie();
};

ENgcMovie* ENgcGraphics::AllocMovie() {
    return new ENgcMovie();
}
