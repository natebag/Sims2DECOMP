class INGTarget {
public:
    struct IngInfo {
        void *m_ptr1;
        void *m_ptr2;

        void erase();
    };
};

void INGTarget::IngInfo::erase() {
    m_ptr1 = 0;
    m_ptr2 = 0;
}
