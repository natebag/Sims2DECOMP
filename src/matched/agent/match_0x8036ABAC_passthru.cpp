/* REffectsEmitter::Construct(REffectsEmitter*) at 0x8036ABAC (32B) */
// 0x8036ABAC (32 bytes)
class REffectsEmitter {
public:
    REffectsEmitter();
    void Construct(REffectsEmitter* other);
};
static inline void* operator new(unsigned sz, void* p) { return p; }
void REffectsEmitter::Construct(REffectsEmitter*) {
    new(this) REffectsEmitter;
}
