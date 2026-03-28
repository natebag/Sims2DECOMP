struct AptValueNoGC {
    bool IsGarbageCollected() const;
};

bool AptValueNoGC::IsGarbageCollected() const {
    return false;
}
