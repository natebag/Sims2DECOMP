// 0x802BB8D4 (8 bytes)
class AptValueNoGC {
public:
    int IsGarbageCollected();
};

int AptValueNoGC::IsGarbageCollected() {
    return 0;
}
