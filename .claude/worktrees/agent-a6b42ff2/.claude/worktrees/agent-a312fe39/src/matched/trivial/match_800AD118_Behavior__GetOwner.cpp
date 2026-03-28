// 0x800AD118 (8 bytes)
class Behavior {
public:
    int GetOwner();
};

int Behavior::GetOwner() {
    return *(int*)((char*)this + 0x4);
}
