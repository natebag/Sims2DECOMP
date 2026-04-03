// 0x80189AC8 (8 bytes)
class HUDTarget {
public:
    int GetHudTransitionTarget();
};

int HUDTarget::GetHudTransitionTarget() {
    return *(unsigned char*)((char*)this + 0x100);
}
