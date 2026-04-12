// 0x8036AC54 (12 bytes)
class REffectsEmitter {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short gREffectsEmitterData[];

unsigned short REffectsEmitter::GetTypeVersion() const {
    return gREffectsEmitterData[0];
}
