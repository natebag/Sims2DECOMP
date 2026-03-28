struct AptValueGC {
    bool IsGarbageCollected() const;
};

bool AptValueGC::IsGarbageCollected() const {
    return true;
}
