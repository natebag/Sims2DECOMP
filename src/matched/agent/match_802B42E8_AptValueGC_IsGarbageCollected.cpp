struct AptValueGC {
    int IsGarbageCollected() const;
};

int AptValueGC::IsGarbageCollected() const {
    return 1;
}
