// 0x803562D0 (60B) Effects::FastParticleEmitter::Accept(EffectsVisitor&)
// MI-vcall to slot 3 of EffectsVisitor (typeinfo + 2 fillers + VisitFastParticleEmitter).

namespace Effects {
class FastParticleEmitter;
}

class EffectsVisitor {
public:
    virtual void Filler1() = 0;
    virtual void Filler2() = 0;
    virtual void VisitFastParticleEmitter(Effects::FastParticleEmitter* e) = 0;
};

namespace Effects {

class FastParticleEmitter {
public:
    void Accept(::EffectsVisitor& v);
};

void FastParticleEmitter::Accept(::EffectsVisitor& v) {
    v.VisitFastParticleEmitter(this);
}

}  // namespace Effects
