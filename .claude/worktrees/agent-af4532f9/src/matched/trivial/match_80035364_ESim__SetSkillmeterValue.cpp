// 0x80035364 (8 bytes)
class ESim {
public:
    void SetSkillmeterValue(float p);
};

void ESim::SetSkillmeterValue(float p) {
    *(float*)((char*)this + 0x3F0) = p;
}
