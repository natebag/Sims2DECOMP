class INGTarget {
public:
    struct IngInfo {
        void *m_ptr1;
        void *m_ptr2;

        IngInfo();
    };
};

INGTarget::IngInfo::IngInfo() : m_ptr2(0), m_ptr1(0) {
}
