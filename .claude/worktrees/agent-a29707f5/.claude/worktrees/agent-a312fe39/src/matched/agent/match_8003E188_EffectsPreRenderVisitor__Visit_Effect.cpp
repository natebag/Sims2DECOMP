// 0x8003E188 (8 bytes) — li r3, 1; blr

namespace Effects { class Effect; }

class EffectsPreRenderVisitor {
public:
    int Visit(Effects::Effect& effect);
};

int EffectsPreRenderVisitor::Visit(Effects::Effect& effect) {
    return 1;
}
