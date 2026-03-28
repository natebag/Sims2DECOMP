// 0x80161BB8 (4 bytes)
class CasEventInitSim;

class CasListener {
public:
    void HandleEventInitSim(CasEventInitSim &);
};

void CasListener::HandleEventInitSim(CasEventInitSim &) {
    // No operation
}