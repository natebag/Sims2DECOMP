// 0x802B6100 (8 bytes)
class AptValueGC {
public:
    int IsGarbageCollected();
};

int AptValueGC::IsGarbageCollected() {
    return 1;
}
