// 0x801E7080 (8 bytes)
class MMUTarget {
public:
    int GetCurrentGameplayChoice();
};

int MMUTarget::GetCurrentGameplayChoice() {
    return *(int*)((char*)this + 0xB8);
}
