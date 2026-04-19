/* EFontData::Construct(EFontData*) at 0x80364AB8 (32B) */
// 0x80364AB8 (32 bytes)
class EFontData {
public:
    EFontData();
    void Construct(EFontData* other);
};
static inline void* operator new(unsigned sz, void* p) { return p; }
void EFontData::Construct(EFontData*) {
    new(this) EFontData;
}
