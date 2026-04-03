// 0x802295C4 (8 bytes)
class EInstance {
public:
    void SetPortalType(int p);
};

void EInstance::SetPortalType(int p) {
    *(int*)((char*)this + 0x14) = p;
}
