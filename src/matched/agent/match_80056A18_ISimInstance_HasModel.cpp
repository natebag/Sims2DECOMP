// 0x80056A18 (24 bytes) - ISimInstance::HasModel(void)
// lwz r0,288(r3); li r3,1; cmpwi r0,0; bnelr; li r3,0; blr

struct ISimInstance_HM {
    char pad[0x120];
    void* m_model;

    int HasModel();
};

int ISimInstance_HM::HasModel() {
    return m_model != 0;
}
