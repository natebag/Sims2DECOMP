// 0x801D6DEC (124B) PCTTarget::delete_dialog_selection_callback(int)

class BBHTarget;
class InteractorManager;

namespace InteractorModule {
    class GrabManipulator {
    public:
        void DestroyObjectInHand();
    };
}

extern "C" InteractorManager* GetSingleton__N16InteractorModule18InteractorManagerFv();
extern "C" void* GetPlayerInteractor__N16InteractorModule18InteractorManagerFiN16InteractorModule15InteractorType(InteractorManager*, int, int);
extern "C" void DestroyObjectInHand__N16InteractorModule16GrabManipulatorFv(void*);
extern "C" void SetSellingPig__9BBHTargetFb(BBHTarget*, bool);
extern "C" void SetCurrentPrice__9BBHTargetFi(BBHTarget*, int);
extern "C" void GetFireCodeValue__Fb(bool);

class PCTTarget {
public:
    char m_pad[132];
    int m_84_player;
    char m_pad88[240 - 136];
    int m_F0;
    char m_pad244[532 - 244];
    BBHTarget* m_214_bbh;
    void delete_dialog_selection_callback(int rc);
};

void PCTTarget::delete_dialog_selection_callback(int rc) {
    m_F0 = 0;
    if (rc != 0) return;
    InteractorManager* mgr = GetSingleton__N16InteractorModule18InteractorManagerFv();
    void* interactor = GetPlayerInteractor__N16InteractorModule18InteractorManagerFiN16InteractorModule15InteractorType(mgr, m_84_player, 2);
    if (interactor != 0) {
        DestroyObjectInHand__N16InteractorModule16GrabManipulatorFv(interactor);
    }
    if (m_214_bbh != 0) {
        SetSellingPig__9BBHTargetFb(m_214_bbh, false);
        SetCurrentPrice__9BBHTargetFi(m_214_bbh, 0);
    }
    GetFireCodeValue__Fb(true);
}
