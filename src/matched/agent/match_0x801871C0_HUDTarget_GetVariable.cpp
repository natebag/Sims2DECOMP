// 0x801871C0 (100B) HUDTarget::GetVariable(char*)
// Player-extraction sibling of SetVariable. 3 saved regs (no 3rd arg).

extern "C" int isdigit(int);

class HUDTarget {
public:
    char* GetPlayerVariable(int player, char* a);
    char* GetVariable(char* a);
};

char* HUDTarget::GetVariable(char* a) {
    int player = 0;
    if (isdigit((signed char)*a)) {
        player = (signed char)*a - '0';
        ++a;
    }
    return this->GetPlayerVariable(player, a);
}
