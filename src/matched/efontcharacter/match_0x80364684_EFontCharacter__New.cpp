// 0x80364684 EFontCharacter::New (52b)
typedef unsigned int uint;

void *__builtin_new(uint);

struct EFontCharacter {
    virtual ~EFontCharacter(void);
    inline EFontCharacter(void) {}
};

inline void *operator new(uint, void *p) { return p; }

EFontCharacter *EFontCharacter__New(void) {
    void *mem = __builtin_new(16);
    EFontCharacter *p = new(mem) EFontCharacter;
    return p;
}
