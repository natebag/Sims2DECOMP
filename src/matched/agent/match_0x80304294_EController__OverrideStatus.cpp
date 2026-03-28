struct EController {
    char _pad[0x04];
    int m_status;
    void OverrideStatus(int val);
};
void EController::OverrideStatus(int val) { m_status = val; }
