/* InteractorModule::GrabManipulator::CallbackData::~CallbackData(void) at 0x803c08c4 (52B) */

struct IM_BaseCBD_IM_GrabManCBD { int m_a, m_b; };

struct IM_GrabManCBD : IM_BaseCBD_IM_GrabManCBD {
    virtual ~IM_GrabManCBD();
};

IM_GrabManCBD::~IM_GrabManCBD() {}
