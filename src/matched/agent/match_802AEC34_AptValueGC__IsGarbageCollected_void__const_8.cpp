struct AptValueGC8 {
    bool IsGarbageCollected() const;
};

bool AptValueGC8::IsGarbageCollected() const {
    return true;
}
