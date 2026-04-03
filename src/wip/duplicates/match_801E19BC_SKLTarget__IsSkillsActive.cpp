// 0x801E19BC (8 bytes)
class SKLTarget {
public:
    int IsSkillsActive();
};

int SKLTarget::IsSkillsActive() {
    return *(int*)((char*)this + 0x88);
}
