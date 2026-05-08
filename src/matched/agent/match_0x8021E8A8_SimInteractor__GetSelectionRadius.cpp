// 0x8021E8A8 (64B) InteractorModule::SimInteractor::GetSelectionRadius(void)
// If m_field_532 is 0, returns a hardcoded default radius instead of base result.

extern char k_simInteractor_defaultRadius[16];

namespace InteractorModule {

class Interactor {
public:
    float GetSelectionRadius();
};

class SimInteractor : public Interactor {
public:
    char pad[528];
    int m_field_532;
    float GetSelectionRadius();
};

float SimInteractor::GetSelectionRadius() {
    float r = Interactor::GetSelectionRadius();
    if (!m_field_532) {
        r = *(float*)k_simInteractor_defaultRadius;
    }
    return r;
}

}
