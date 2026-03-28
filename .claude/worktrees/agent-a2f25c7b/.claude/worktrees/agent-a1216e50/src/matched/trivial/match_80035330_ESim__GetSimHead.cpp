// 0x80035330 (8 bytes)
class ESim {
public:
    int GetSimHead();
};

int ESim::GetSimHead() {
    return *(int*)((char*)this + 0x628);
}
