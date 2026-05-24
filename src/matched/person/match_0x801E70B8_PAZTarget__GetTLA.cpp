// 0x801E70B8 PAZTarget::GetTLA(void) (12B)
// Returns pointer to global TLA string (DOL: lis 3,-32705; addi 3,3,16212).

extern char g_PAZTarget_TLA[];

struct PAZTarget {
    char* GetTLA();
};

char* PAZTarget::GetTLA() {
    return g_PAZTarget_TLA;
}
