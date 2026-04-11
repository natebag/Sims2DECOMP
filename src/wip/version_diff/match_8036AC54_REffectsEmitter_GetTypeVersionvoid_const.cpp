// 0x8036AC54 (12 bytes)
class REffectsEmitter {
public:
    short GetTypeVersion() const;
};

extern char gREffectsEmitterData[];

short REffectsEmitter::GetTypeVersion() const {
    return *(short*)(gREffectsEmitterData + 0);
}
