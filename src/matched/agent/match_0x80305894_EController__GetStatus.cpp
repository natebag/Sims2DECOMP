struct EController {
    char _pad[0x04];
    int m_status;
    int GetStatus();
};
int EController::GetStatus() { return m_status; }
