// 0x8003E190 (8 bytes) — li r3, 1; blr

namespace Effects { class EffectsSequencer; }

class EffectsPreRenderVisitor {
public:
    int Visit(Effects::EffectsSequencer& seq);
};

int EffectsPreRenderVisitor::Visit(Effects::EffectsSequencer& seq) {
    return 1;
}
