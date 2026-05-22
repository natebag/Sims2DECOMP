// 0x80089074 ISimsCounterTopObject::GetTypeKey(void) (12B)
// lwz r9, 100(r3) ; lfs f1, 56(r9) ; blr

struct ISimsCounterTopObject {
    char _pad[100];
    struct Sub {
        char _pad2[56];
        float m_key;
    }* m_ptr;
    float GetTypeKey() const;
};

float ISimsCounterTopObject::GetTypeKey() const {
    return m_ptr->m_key;
}
