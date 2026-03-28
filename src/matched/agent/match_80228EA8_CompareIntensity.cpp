struct LightEntry {
    int pad0;
    float intensity;
    char pad1[0x24];
    float secondary;
};

int CompareIntensity(void *a, void *b) {
    LightEntry *la = (LightEntry *)a;
    LightEntry *lb = (LightEntry *)b;

    if (la->intensity < lb->intensity)
        return 1;
    if (la->intensity > lb->intensity)
        return -1;

    if (la->secondary > lb->secondary)
        return 1;
    if (la->secondary < lb->secondary)
        return -1;
    return 0;
}
