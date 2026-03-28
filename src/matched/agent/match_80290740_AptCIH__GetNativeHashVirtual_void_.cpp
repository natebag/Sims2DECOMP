struct AptNativeHash;

struct AptCIH {
    AptNativeHash* GetNativeHash();
    AptNativeHash* GetNativeHashVirtual();
};

AptNativeHash* AptCIH::GetNativeHashVirtual() {
    return GetNativeHash();
}
