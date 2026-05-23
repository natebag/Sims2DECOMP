// 0x8021ECBC (112B) InteractorModule::SimInteractor::IsSimulatorPaused(void)
// Byte-identical to DirectInteractor::IsSimulatorPaused except float constant:
// DI: 0x803FCB08 (lis r9,-32704; lfs f0,-13560(r9)) → kSimPausedSpeedDI
// SI: 0x803FDD2C (lis r9,-32704; lfs f0,-8916(r9)) → kSimPausedSpeedSI
// Same SDA global g_pSimQuery, same vtable slot 2, same AllPlayersActiveInputInteractors.
// goto-shared-label: forces cmpwi+bne+li1+b+li0 instead of GCC subfic+adde boolification.

namespace InteractorModule {

class ISimulatorQuery {
public:
    virtual ~ISimulatorQuery() {}
    virtual float GetSimulatorSpeed() = 0;
};

extern ISimulatorQuery* g_pSimQuery;
extern char kSimPausedSpeedSI[16];

int AllPlayersActiveInputInteractors(int);

class SimInteractor {
public:
    int m_playerId;
    bool IsSimulatorPaused();
};

bool SimInteractor::IsSimulatorPaused() {
    float speed = g_pSimQuery->GetSimulatorSpeed();
    if (speed == *(float*)kSimPausedSpeedSI) goto ret1;
    if (AllPlayersActiveInputInteractors(m_playerId) != 0) goto ret0;
ret1:
    return true;
ret0:
    return false;
}

}
