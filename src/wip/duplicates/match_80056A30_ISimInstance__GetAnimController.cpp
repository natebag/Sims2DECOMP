// 0x80056A30 (8 bytes)
class ISimInstance {
public:
    int GetAnimController();
};

int ISimInstance::GetAnimController() {
    return (int)((char*)this + 0x334);
}
