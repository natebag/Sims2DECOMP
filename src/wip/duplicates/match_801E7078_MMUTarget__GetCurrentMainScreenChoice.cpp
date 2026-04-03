// 0x801E7078 (8 bytes)
class MMUTarget {
public:
    int GetCurrentMainScreenChoice();
};

int MMUTarget::GetCurrentMainScreenChoice() {
    return *(int*)((char*)this + 0xA4);
}
