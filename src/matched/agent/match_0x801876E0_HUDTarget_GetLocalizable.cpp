// 0x801876E0 (100B) HUDTarget::GetLocalizable(char*)
// Player-extraction sibling of GetVariable, returns localizable string.

extern "C" int isdigit(int);

class HUDTarget {
public:
    char* GetPlayerLocalizable(int player, char* a);
    char* GetLocalizable(char* a);
};

char* HUDTarget::GetLocalizable(char* a) {
    int player = 0;
    if (isdigit((signed char)*a)) {
        player = (signed char)*a - '0';
        ++a;
    }
    return this->GetPlayerLocalizable(player, a);
}
