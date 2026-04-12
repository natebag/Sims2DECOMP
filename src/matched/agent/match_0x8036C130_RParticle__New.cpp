// 0x8036C130 RParticle::New (40b)
struct RParticle {
    char _pad[60];
    static void *operator new(unsigned int);
    RParticle(void);
};

RParticle *RParticle__New(void) {
    RParticle *p = new RParticle;
    return p;
}
