// 0x80094DB0 (56B) InLevelCreateASimState::Reset(void)

struct InLevelCreateASimState_Base {
    void Reset();
};

namespace UIDB { int UIDBGetInt(char* key); }

namespace GameData { void LoadCreateASim(void* target, int value, int flags); }

extern char g_cas_key_str[];
extern char g_cas_target[16];

struct InLevelCreateASimState : public InLevelCreateASimState_Base {
    void Reset();
};

void InLevelCreateASimState::Reset() {
    InLevelCreateASimState_Base::Reset();
    GameData::LoadCreateASim(g_cas_target, UIDB::UIDBGetInt(g_cas_key_str), 0);
}
