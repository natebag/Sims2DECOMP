/* ERBinary::Construct(ERBinary*) at 0x803684CC (32B) */
// 0x803684CC (32 bytes)
class ERBinary {
public:
    ERBinary();
    void Construct(ERBinary* other);
};
static inline void* operator new(unsigned sz, void* p) { return p; }
void ERBinary::Construct(ERBinary*) {
    new(this) ERBinary;
}
