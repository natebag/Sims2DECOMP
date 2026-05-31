// 0x801BC984 INGTarget::is_group_meal(void) (20 B)

struct INGTarget {
    char pad_0000[0x8c];
    int m_mealType;

    bool is_group_meal();
};

bool INGTarget::is_group_meal() {
    return m_mealType == 2;
}
