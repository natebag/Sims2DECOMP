// 0x8036AC3C (12 bytes)
class REffectsEmitter {
public:
    const char* GetTypeName() const;
};

extern char gREffectsEmitterData[];

const char* REffectsEmitter::GetTypeName() const {
    return *(const char**)(gREffectsEmitterData + 0);
}
