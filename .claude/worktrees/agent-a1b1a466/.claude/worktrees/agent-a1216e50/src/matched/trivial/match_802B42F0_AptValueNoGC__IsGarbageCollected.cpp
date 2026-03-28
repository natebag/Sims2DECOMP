// 0x802B42F0 (8 bytes)
class AptValueNoGC {
public:
    int IsGarbageCollected();
};

int AptValueNoGC::IsGarbageCollected() {
    return 0;
}
