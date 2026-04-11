/* CasListener::HandleEvent(CasEvent &) at 0x80161A6C (228B) */

struct CasEvent {
    int m_type;
};

struct CasEventChangeFocus;
struct CasEventChangeSimS2C;
struct CasEventInitSim;
struct CasEventResetSim;
struct CasEventStoreSim;
struct CasEventMorphSimS2C;
struct CasEventResetSimDraw;
struct CasMediator;

struct CasListenerBase {
    void* m_pMediator;
};

class CasListener : public CasListenerBase {
public:
    virtual ~CasListener();
    virtual void HandleEvent(CasEvent& event);
    virtual void SetMediator(CasMediator*);
    virtual void HandleEventChangeFocus(CasEventChangeFocus&);
    virtual void HandleEventChangeSim(CasEventChangeSimS2C&);
    virtual void HandleEventInitSim(CasEventInitSim&);
    virtual void HandleEventResetSim(CasEventResetSim&);
    virtual void HandleEventStoreSim(CasEventStoreSim&);
    virtual void HandleEventMorphSim(CasEventMorphSimS2C&);
    virtual void HandleEventResetSimDraw(CasEventResetSimDraw&);
};

void CasListener::HandleEvent(CasEvent& event) {
    switch (event.m_type) {
        case 2: HandleEventChangeFocus((CasEventChangeFocus&)event); break;
        case 4: HandleEventChangeSim((CasEventChangeSimS2C&)event); break;
        case 0: HandleEventInitSim((CasEventInitSim&)event); break;
        case 1: HandleEventResetSim((CasEventResetSim&)event); break;
        case 3: HandleEventStoreSim((CasEventStoreSim&)event); break;
        case 5: HandleEventMorphSim((CasEventMorphSimS2C&)event); break;
        case 6: HandleEventResetSimDraw((CasEventResetSimDraw&)event); break;
    }
}
