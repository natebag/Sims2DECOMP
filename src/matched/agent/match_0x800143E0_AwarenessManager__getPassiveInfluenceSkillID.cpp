// 0x800143E0 (112B) AwarenessManager::getPassiveInfluenceSkillID(signed char, AnimRef *&)

struct AnimRef;
struct cXPerson;

void GetMiscAnimRef(cXPerson* person, int skillID, AnimRef*& animRef);

struct AwarenessManager {
    char pad_0[52];
    cXPerson* m_cxperson;
    void getPassiveInfluenceSkillID(signed char param, AnimRef*& animRef);
};

void AwarenessManager::getPassiveInfluenceSkillID(signed char param, AnimRef*& animRef) {
    int skillID = 0;
    switch (param) {
        case 0:
        case 1:
            animRef = 0;
            return;
        case 2:
            skillID = 321;
            break;
        case 3:
            skillID = 322;
            break;
        case 4:
            skillID = 320;
            break;
    }
    GetMiscAnimRef(m_cxperson, skillID, animRef);
}
