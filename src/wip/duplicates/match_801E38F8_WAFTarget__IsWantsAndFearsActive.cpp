// 0x801E38F8 (8 bytes)
class WAFTarget {
public:
    int IsWantsAndFearsActive();
};

int WAFTarget::IsWantsAndFearsActive() {
    return *(int*)((char*)this + 0x88);
}
