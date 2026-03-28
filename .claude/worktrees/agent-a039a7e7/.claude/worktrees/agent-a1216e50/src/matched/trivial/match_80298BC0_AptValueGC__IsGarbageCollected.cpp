// 0x80298BC0 (8 bytes)
class AptValueGC {
public:
    int IsGarbageCollected();
};

int AptValueGC::IsGarbageCollected() {
    return 1;
}
