// 0x8030440C EController::Flush (40b)

struct ButtonData_F {
    char pad[0x18];
    int field_18;
    char pad2[0x4];
    int field_20;
};

struct EController_F {
    char pad[0x1FC];
    ButtonData_F* m_prevData;
    ButtonData_F* m_curData;
    void Flush();
};

void EController_F::Flush() {
    m_curData->field_20 = 0;
    m_curData->field_18 = 0;
    m_prevData->field_20 = 0;
    m_prevData->field_18 = 0;
}
