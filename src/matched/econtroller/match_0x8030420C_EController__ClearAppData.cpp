struct EAppData;

void EAppData_ClearData(EAppData*);

struct EController {
    char _pad[0x200];
    EAppData* m_pAppData;
    void ClearAppData(bool);
};

void EController::ClearAppData(bool) {
    EAppData_ClearData(m_pAppData);
}
