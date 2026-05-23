// 0x8003E048 GameEffectsManager::PreRender(void) (76B)
//
// One local EffectsPreRenderVisitor on stack; ForEachActiveEffect called with it.
// stw r29, 8(r1) at +52 is the inline dtor vtable-reset: EffectsPreRenderVisitor::~dtor
// chains into Effects::EffectsVisitor::~dtor which resets vtable to EffectsVisitor's.
// GCC inlines both empty dtors, dead-stores the intermediate reset, leaving one stw.

namespace Effects {

struct Effect;
struct FastParticleEmitter;
struct EffectsSequencer;

class EffectsVisitor {
public:
    virtual ~EffectsVisitor() {}
    virtual void Visit(Effect&) = 0;
    virtual void Visit(FastParticleEmitter&) = 0;
    virtual void Visit(EffectsSequencer&) = 0;
};

class EffectsManager {
public:
    static EffectsManager* GetSingleton();
    void ForEachActiveEffect(EffectsVisitor&);
};

} // namespace Effects

class EffectsPreRenderVisitor : public Effects::EffectsVisitor {
public:
    ~EffectsPreRenderVisitor() {}
    void Visit(Effects::Effect&);
    void Visit(Effects::FastParticleEmitter&);
    void Visit(Effects::EffectsSequencer&);
};

class GameEffectsManager {
public:
    void PreRender();
};

void GameEffectsManager::PreRender() {
    EffectsPreRenderVisitor visitor;
    Effects::EffectsManager::GetSingleton()->ForEachActiveEffect(visitor);
}
