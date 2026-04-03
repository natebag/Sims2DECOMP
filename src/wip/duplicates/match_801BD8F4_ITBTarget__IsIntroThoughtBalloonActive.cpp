// 0x801BD8F4 (8 bytes)
class ITBTarget {
public:
    int IsIntroThoughtBalloonActive();
};

int ITBTarget::IsIntroThoughtBalloonActive() {
    return *(int*)((char*)this + 0x88);
}
