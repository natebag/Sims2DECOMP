// 0x803C2448 EStorable::New (52b)
typedef unsigned int uint;

void *__builtin_new(uint);

struct EStorable {
    virtual ~EStorable(void);
    inline EStorable(void) {}
};

inline void *operator new(uint, void *p) { return p; }

EStorable *EStorable__New(void) {
    void *mem = __builtin_new(4);
    EStorable *p = new(mem) EStorable;
    return p;
}
