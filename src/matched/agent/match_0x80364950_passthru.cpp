/* EFontSize::Construct(EFontSize*) at 0x80364950 (32B) */
// 0x80364950 (32 bytes)
class EFontSize {
public:
    EFontSize();
    void Construct(EFontSize* other);
};
static inline void* operator new(unsigned sz, void* p) { return p; }
void EFontSize::Construct(EFontSize*) {
    new(this) EFontSize;
}
