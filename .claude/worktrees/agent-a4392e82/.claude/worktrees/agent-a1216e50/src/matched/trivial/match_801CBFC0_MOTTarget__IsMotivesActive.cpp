// 0x801CBFC0 (8 bytes)
class MOTTarget {
public:
    int IsMotivesActive();
};

int MOTTarget::IsMotivesActive() {
    return *(int*)((char*)this + 0x88);
}
