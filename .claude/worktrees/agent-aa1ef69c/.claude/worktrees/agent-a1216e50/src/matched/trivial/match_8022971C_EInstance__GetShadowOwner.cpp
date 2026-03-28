// 0x8022971C (8 bytes)
class EInstance {
public:
    int GetShadowOwner();
};

int EInstance::GetShadowOwner() {
    return *(int*)((char*)this + 0x18);
}
