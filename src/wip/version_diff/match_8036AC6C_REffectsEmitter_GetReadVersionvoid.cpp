// 0x8036AC6C (12 bytes)
class REffectsEmitter {
public:
    short GetReadVersion() const;
};

extern char gREffectsEmitterData[];

short REffectsEmitter::GetReadVersion() const {
    return *(short*)(gREffectsEmitterData + 0);
}
