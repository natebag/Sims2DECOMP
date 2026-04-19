/* InteractorModule::Interactor::CallbackData::~CallbackData(void) at 0x803bd340 (52B) */

struct IM_BaseCBD_IM_InteractorCBD { int m_a, m_b; };

struct IM_InteractorCBD : IM_BaseCBD_IM_InteractorCBD {
    virtual ~IM_InteractorCBD();
};

IM_InteractorCBD::~IM_InteractorCBD() {}
