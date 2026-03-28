// 0x80229660 (8 bytes)
class EInstance {
public:
    int GetBounds();
};

int EInstance::GetBounds() {
    return (int)((char*)this + 0x3C);
}
