struct RParticle {
    static void *operator new(unsigned int, void *p);
};
void *RParticle::operator new(unsigned int, void *p) { return p; }
