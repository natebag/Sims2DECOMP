// 0x80161BBC (4 bytes)
class CasEventResetSim {};

class CasListener {
public:
    void HandleEventResetSim(CasEventResetSim &);
};

void CasListener::HandleEventResetSim(CasEventResetSim &) {
    // No operation
}