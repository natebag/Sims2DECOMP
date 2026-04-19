// 0x80186E34 (108B) HUDTarget::SetVariable(char*, char*)
// isdigit(a[0]) ? player = a[0]-'0', ++a : player = 0; SetPlayerVariable(player, a, b).

extern "C" int isdigit(int);

class HUDTarget {
public:
    void SetPlayerVariable(int player, char* a, char* b);
    void SetVariable(char* a, char* b);
};

void HUDTarget::SetVariable(char* a, char* b) {
    int player = 0;
    if (isdigit((signed char)*a)) {
        player = (signed char)*a - '0';
        ++a;
    }
    this->SetPlayerVariable(player, a, b);
}
