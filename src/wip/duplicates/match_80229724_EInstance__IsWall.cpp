// 0x80229724 (8 bytes)
class EInstance {
public:
    int IsWall();
};

int EInstance::IsWall() {
    return *(int*)((char*)this + 0x10);
}
