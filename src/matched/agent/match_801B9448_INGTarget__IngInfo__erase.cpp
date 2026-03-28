class INGTarget {
public:
    struct IngInfo {
        int m_field4;
        int m_field0;

        void erase();
    };
};

void INGTarget::IngInfo::erase() {
    m_field4 = 0;
    m_field0 = 0;
}
