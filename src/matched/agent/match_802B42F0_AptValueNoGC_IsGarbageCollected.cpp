struct AptValueNoGC {
    int IsGarbageCollected() const;
};

int AptValueNoGC::IsGarbageCollected() const {
    return 0;
}
