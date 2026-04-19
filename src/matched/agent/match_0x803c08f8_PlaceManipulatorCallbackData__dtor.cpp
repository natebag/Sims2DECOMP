/* InteractorModule::PlaceManipulator::CallbackData::~CallbackData(void) at 0x803c08f8 (52B) */

struct IM_BaseCBD_IM_PlaceManCBD { int m_a, m_b; };

struct IM_PlaceManCBD : IM_BaseCBD_IM_PlaceManCBD {
    virtual ~IM_PlaceManCBD();
};

IM_PlaceManCBD::~IM_PlaceManCBD() {}
