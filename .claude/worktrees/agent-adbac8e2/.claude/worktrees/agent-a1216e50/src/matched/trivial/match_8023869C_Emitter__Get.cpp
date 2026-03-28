// 0x8023869C (8 bytes)
class Emitter {
public:
    int Get();
};

int Emitter::Get() {
    return *(int*)((char*)this + 0x7C);
}
