// 0x802B4180 (40B) AptValueWithHash::RegisterReferences(void) const
//
// GC reference registration for AptValueWithHash: delegates to the embedded
// AptNativeHash (@0x0C), passing the owning value as the context argument. The
// member-call adjusts `this` to &m_hash (this+12) while the original `this` is
// forwarded as the AptValue* owner. Frameful leaf-delegator. Clean structural C++.

struct AptValue;   // owner argument type (passed as this)

struct AptNativeHash {
    void RegisterReferences(AptValue* owner) const;   // bl 0x802AAE30
};

struct AptValueBase {   // AptValue head: 2 data words + vptr = 12 bytes
    char _pad[0x0C];
};

struct AptValueWithHash : public AptValueBase {
    AptNativeHash m_hash;   // 0x0C
    void RegisterReferences() const;
};

void AptValueWithHash::RegisterReferences() const {
    m_hash.RegisterReferences((AptValue*)this);
}
