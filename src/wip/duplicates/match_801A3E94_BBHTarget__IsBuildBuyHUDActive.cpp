// 0x801A3E94 (8 bytes)
class BBHTarget {
public:
    int IsBuildBuyHUDActive();
};

int BBHTarget::IsBuildBuyHUDActive() {
    return *(int*)((char*)this + 0x88);
}
