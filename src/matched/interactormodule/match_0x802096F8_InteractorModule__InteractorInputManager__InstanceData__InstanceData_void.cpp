// 0x802096F8 (52B) InteractorModule::InteractorInputManager::InstanceData::InstanceData(void)
// Ctor: zero-init most fields, sentinel -1 at +0x14, sub-struct at +8.

namespace InteractorModule {
namespace InteractorInputManager {

struct Sub {
    int field0;
    int field4;
};

class InstanceData {
public:
    int m_f0;
    int m_f4;
    Sub m_sub;
    char m_b10;
    char pad11_13[3];
    int m_f14;
    char pad18_1B[4];
    int m_f1C;
    InstanceData();
};

}
}

using InteractorModule::InteractorInputManager::InstanceData;

InstanceData::InstanceData() {
    volatile int _dummy[6];
    m_f0 = 0;
    m_f4 = 0;
    Sub* psub = &m_sub;
    psub->field4 = 0;
    m_f14 = -1;
    m_b10 = 0;
    m_f1C = 0;
}
