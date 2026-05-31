// 0x80056A18 ISimInstance::HasModel(void) (24 B)

struct ISimInstance {
    char pad_0000[0x120];
    void* m_model;

    bool HasModel();
};

bool ISimInstance::HasModel() {
    return m_model != 0;
}
