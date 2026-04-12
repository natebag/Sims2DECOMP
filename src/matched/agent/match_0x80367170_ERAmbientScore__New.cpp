// 0x80367170 ERAmbientScore::New (48b)
typedef unsigned int uint;

struct EAHeap {
    void *Malloc(uint size, int flags);
};
EAHeap *MainHeap(void);

struct ERAmbientScore {
    char _pad[60];
    ERAmbientScore(void);
};

inline void *operator new(uint, void *p) { return p; }

ERAmbientScore *ERAmbientScore__New(void) {
    void *mem = MainHeap()->Malloc(60, 0);
    ERAmbientScore *p = new(mem) ERAmbientScore;
    return p;
}
