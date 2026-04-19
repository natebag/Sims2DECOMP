// VERSION_DIFF: phantom 32-byte frame (stwu r1,-32(r1) with no lr save/spills); 11 work instructions match perfectly
// 0x802096F8 (52B) InteractorModule::InteractorInputManager::InstanceData::InstanceData(void)

struct ID_Inner {
    int x;
    int y;
};

struct InstanceData {
    int field_00;
    int field_04;
    ID_Inner m_inner;
    char field_10;
    char pad[3];
    int field_14;
    int field_18;
    int field_1C;
    InstanceData();
};

InstanceData::InstanceData() {
    field_00 = 0;
    ID_Inner* p = &m_inner;
    field_04 = 0;
    p->y = 0;
    field_14 = -1;
    field_10 = 0;
    field_1C = 0;
}
