class EController {
public:
    int m_pad;
    int m_status;
    void OverrideStatus(int);
};
void EController::OverrideStatus(int status) { m_status = status; }
