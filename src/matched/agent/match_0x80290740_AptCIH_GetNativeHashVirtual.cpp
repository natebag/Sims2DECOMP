// 0x80290740 (32B) AptCIH::GetNativeHashVirtual(void)
// Thunk to AptCIH::getNativeHash(void) const

class AptCIH {
public:
    void GetNativeHashVirtual(void);
    void getNativeHash(void) const;
};

void AptCIH::GetNativeHashVirtual(void) {
    getNativeHash();
}
