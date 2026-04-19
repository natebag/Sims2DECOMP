/* ERDataset::Construct(ERDataset*) at 0x803697B0 (32B) */
// 0x803697B0 (32 bytes)
class ERDataset {
public:
    ERDataset();
    void Construct(ERDataset* other);
};
static inline void* operator new(unsigned sz, void* p) { return p; }
void ERDataset::Construct(ERDataset*) {
    new(this) ERDataset;
}
