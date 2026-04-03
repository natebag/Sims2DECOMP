// 0x802A865C (8 bytes)
class AptValueGC {
public:
    int IsGarbageCollected();
};

int AptValueGC::IsGarbageCollected() {
    return 1;
}
