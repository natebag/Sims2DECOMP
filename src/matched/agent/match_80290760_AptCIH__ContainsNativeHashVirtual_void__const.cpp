struct AptNativeHash;

struct AptCIH {
    AptNativeHash* GetNativeHash();
    int ContainsNativeHashVirtual() const;
};

int AptCIH::ContainsNativeHashVirtual() const {
    AptCIH* self = (AptCIH*)this;
    return self->GetNativeHash() != 0 ? 1 : 0;
}
