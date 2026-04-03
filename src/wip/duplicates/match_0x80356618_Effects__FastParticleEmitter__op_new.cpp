namespace Effects {
struct FastParticleEmitter {
    static void *operator new(unsigned int, void *p);
};
}
void *Effects::FastParticleEmitter::operator new(unsigned int, void *p) { return p; }
