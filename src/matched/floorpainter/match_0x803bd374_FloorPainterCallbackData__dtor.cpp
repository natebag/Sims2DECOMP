/* InteractorModule::FloorPainter::CallbackData::~CallbackData(void) at 0x803bd374 (52B) */

struct IM_BaseCBD_IM_FloorPainterCBD { int m_a, m_b; };

struct IM_FloorPainterCBD : IM_BaseCBD_IM_FloorPainterCBD {
    virtual ~IM_FloorPainterCBD();
};

IM_FloorPainterCBD::~IM_FloorPainterCBD() {}
