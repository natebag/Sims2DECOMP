// 0x8016222C CasMediator::DrawSim(void) (64B) — free-function → method consolidation
//
// Was `void CasMediator_DrawSim(CasMediator* self)` (free function with manual
// self ptr). Promoted to proper member method. Field renamed: `target` →
// `m_drawTarget` per project convention (m_ prefix for instance members).
//
// CasMediator layout: m_drawTarget at offset 0x14 — null-checked then dispatched
// to vtable slot 11 (cleanup/draw completion callback per the V11 semantics).

class DrawTarget {
public:
    int pad;
    virtual void V0();  virtual void V1();  virtual void V2();
    virtual void V3();  virtual void V4();  virtual void V5();
    virtual void V6();  virtual void V7();  virtual void V8();
    virtual void V9();  virtual void V10(); virtual void V11();
};

class CasMediator {
public:
    char pad[20];
    DrawTarget* m_drawTarget;
    void DrawSim(void);
};

void CasMediator::DrawSim(void) {
    if (m_drawTarget != 0) {
        m_drawTarget->V11();
    }
}
