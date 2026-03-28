// 0x802AEC3C (8 bytes)
class AptValueNoGC {
public:
    int IsGarbageCollected();
};

int AptValueNoGC::IsGarbageCollected() {
    return 0;
}
