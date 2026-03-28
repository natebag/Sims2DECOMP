class INGTarget {
public:
    char _pad[0x8C];
    int m_mealType;

    bool is_group_meal(void) const;
};

bool INGTarget::is_group_meal(void) const {
    return m_mealType == 2;
}
