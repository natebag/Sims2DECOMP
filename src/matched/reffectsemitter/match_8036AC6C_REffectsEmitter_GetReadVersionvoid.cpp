// 0x8036AC6C (12 bytes)
class REffectsEmitter {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short gREffectsEmitterData[];

unsigned short REffectsEmitter::GetReadVersion() const {
    return gREffectsEmitterData[1];
}
