// 0x8036AC48 (12 bytes)
class REffectsEmitter {
public:
    const char* GetTypeKey() const;
};

extern char gREffectsEmitterData[];

const char* REffectsEmitter::GetTypeKey() const {
    return *(const char**)(gREffectsEmitterData + 0);
}
