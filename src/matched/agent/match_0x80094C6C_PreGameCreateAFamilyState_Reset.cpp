// 0x80094C6C (52B) PreGameCreateAFamilyState::Reset(void)

struct PreGameCreateAFamilyState_Base {
    void Reset();
};

namespace GameData { void PrepCreateAFamilyData(void* target, int val); }

extern char g_cas_target[16];
extern char g_pregame_value[16];

struct PreGameCreateAFamilyState : public PreGameCreateAFamilyState_Base {
    void Reset();
};

void PreGameCreateAFamilyState::Reset() {
    PreGameCreateAFamilyState_Base::Reset();
    GameData::PrepCreateAFamilyData(g_cas_target, *(int*)g_pregame_value);
}
