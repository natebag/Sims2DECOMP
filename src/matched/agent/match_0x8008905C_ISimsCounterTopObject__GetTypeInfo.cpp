// 0x8008905C ISimsCounterTopObject::GetTypeInfo(void) (12B)
// lwz r3, 100(r3) ; addi r3, r3, 52 ; blr
// Returns pointer to sub-object at *(this+100)+52

struct ISimsCounterTopObject {
    char _pad[100];
    char* m_selectorBase;  // at +100
    void* GetTypeInfo() const;
};

void* ISimsCounterTopObject::GetTypeInfo() const {
    return m_selectorBase + 52;
}
