// 0x802295CC (8 bytes)
class EInstance {
public:
    int GetPortalType();
};

int EInstance::GetPortalType() {
    return *(int*)((char*)this + 0x14);
}
