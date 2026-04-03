// 0x802BBE40 (8 bytes)
class AptValueNoGC {
public:
    int IsGarbageCollected();
};

int AptValueNoGC::IsGarbageCollected() {
    return 0;
}
