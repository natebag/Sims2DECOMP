// 0x80089068 ISimsCounterTopObject::GetTypeName(void) (12B)
// lwz r9, 100(r3) ; lfs f1, 52(r9) ; blr

struct ISimsCounterTopObject {
    char _pad[100];
    struct Sub {
        char _pad2[52];
        float m_name;
    }* m_ptr;
    float GetTypeName() const;
};

float ISimsCounterTopObject::GetTypeName() const {
    return m_ptr->m_name;
}
