// 0x80281D1C (8 bytes)
class AptValueGC {
public:
    int IsGarbageCollected();
};

int AptValueGC::IsGarbageCollected() {
    return 1;
}
