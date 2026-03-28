class EController {
public:
    int m_id;
    int m_status;
    int GetStatus();
};
int EController::GetStatus() { return m_status; }
