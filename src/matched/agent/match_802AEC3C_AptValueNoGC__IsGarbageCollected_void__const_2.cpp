struct AptValueNoGC2 {
    bool IsGarbageCollected() const;
};

bool AptValueNoGC2::IsGarbageCollected() const {
    return false;
}
