struct EControllerData;

void EControllerData_Reset(EControllerData*);

struct EController {
    char _pad[0x1FC];
    EControllerData* m_pData;
    void ResetControllerData(bool);
};

void EController::ResetControllerData(bool) {
    EControllerData_Reset(m_pData);
}
