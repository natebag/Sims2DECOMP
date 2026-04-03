// 0x802D283C (8 bytes)
class EStream {
public:
    int IsStreamingStructure();
};

int EStream::IsStreamingStructure() {
    return *(int*)((char*)this + 0x0);
}
