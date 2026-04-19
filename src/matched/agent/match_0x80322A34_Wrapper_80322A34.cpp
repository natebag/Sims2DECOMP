/* REffectsAttachment::Construct(REffectsAttachment*) at 0x80322A34 (32B) */
// 0x80322A34 (32 bytes)
class REffectsAttachment {
public:
    REffectsAttachment();
    void Construct(REffectsAttachment* other);
};
static inline void* operator new(unsigned sz, void* p) { return p; }
void REffectsAttachment::Construct(REffectsAttachment*) {
    new(this) REffectsAttachment;
}
