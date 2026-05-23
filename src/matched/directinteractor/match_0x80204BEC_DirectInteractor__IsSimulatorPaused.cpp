// 0x80204BEC (112B) InteractorModule::DirectInteractor::IsSimulatorPaused(void)
// SDA global at r13-21496 = g_pSimQuery (4-byte pointer → SDA access, offset masked).
// Vtable slot 2: virtual dtor takes 2 slots (SN ProDG MS-ABI) → GetSimulatorSpeed at slot 2.
// Float constant at 0x803FCB08 via lis r9,-32704; lfs f0,-13560(r9).
// goto-shared-label: forces cmpwi+bne+li1+b+li0 instead of GCC subfic+adde boolification.
// beq (speed fast path) and bne fall-through both target the shared ret1 li r3,1.

namespace InteractorModule {

class ISimulatorQuery {
public:
    virtual ~ISimulatorQuery() {}
    virtual float GetSimulatorSpeed() = 0;
};

extern ISimulatorQuery* g_pSimQuery;
extern char kSimPausedSpeedDI[16];

int AllPlayersActiveInputInteractors(int);

class DirectInteractor {
public:
    int m_playerId;
    bool IsSimulatorPaused();
};

bool DirectInteractor::IsSimulatorPaused() {
    float speed = g_pSimQuery->GetSimulatorSpeed();
    if (speed == *(float*)kSimPausedSpeedDI) goto ret1;
    if (AllPlayersActiveInputInteractors(m_playerId) != 0) goto ret0;
ret1:
    return true;
ret0:
    return false;
}

}
