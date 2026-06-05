// 0x802B5E54 (32B) AptObject::RegisterReferences(void) const
//
// GC reference registration for AptObject: simply chains to the base
// AptValueWithHash version (which registers the embedded hash's references).
// Frameful leaf-delegator (saves LR around the single base call). Clean
// structural C++.

struct AptValueWithHash {
    void RegisterReferences() const;   // base (bl 0x802B4180)
};

struct AptObject : public AptValueWithHash {
    void RegisterReferences() const;
};

void AptObject::RegisterReferences() const {
    AptValueWithHash::RegisterReferences();
}
