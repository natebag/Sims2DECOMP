// 0x801E70C4 PZ1Target::GetTLA(void) (12B)
// Returns pointer to global TLA string (DOL: lis 3,-32705; addi 3,3,16220).

extern char g_PZ1Target_TLA[];

struct PZ1Target {
    char* GetTLA();
};

char* PZ1Target::GetTLA() {
    return g_PZ1Target_TLA;
}
