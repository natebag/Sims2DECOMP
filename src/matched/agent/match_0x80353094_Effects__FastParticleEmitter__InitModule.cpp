// 0x80353094 (48B) Effects::FastParticleEmitter::InitModule(void)
// Static init: InitParticlePool(); SetSeed2(0xdecafbad); InitPlatform();

namespace Effects {

void SetSeed2(int seed);

class FastParticleEmitter {
public:
    static void InitModule();
    static void InitPlatform();
    static void InitParticlePool();
};

void FastParticleEmitter::InitModule() {
    InitParticlePool();
    SetSeed2(0xdecafbad);
    InitPlatform();
}

}  // namespace Effects
