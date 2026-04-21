/* ADDRESS-SQUATTER FAKE — do not trust the original header below. */
/*   - Filename claimed: InteractorModule::InteractorManager::Update @ 0x8035AD78 (84B) */
/*   - DVD map says 0x8035AD78 is actually EConfig::GetFirst(EString&, EString&) (36B). */
/*   - The REAL InteractorManager::Update lives at 0x8020B4C8 (84B) and is already */
/*     correctly matched in src/matched/interactormodule/match_0x8020B4C8_*.cpp. */
/*   - These two trivial wrappers coincidentally byte-match DOL[0x8035AD78..+84B], */
/*     which spans EConfig::GetFirst (36B) + the start of EConfig::GetNext (48B). */
/*     Not a real decomp of either function. Moved to wip/version_diff by OpusReview */
/*     during S13 Audit Cycle 2 (2026-04-21) per full-tree tools/size_sweep.sh sweep. */
/* */
/* Original (fabricated) header below — left for provenance only. */
/* InteractorModule::InteractorManager::Update(float) at 0x8035AD78 (84 bytes) */
/* Contains two wrapper functions calling an internal at 0x8035AC94 */

namespace InteractorModule {

class InteractorManager {
public:
    void _InternalUpdate(int a, int b, int c);
    void Update(int a, int b);
    void ChangeActiveInteractorToNull(int a, int b, int c);
};

void InteractorManager::Update(int a, int b) {
    _InternalUpdate(a, b, 0);
}

void InteractorManager::ChangeActiveInteractorToNull(int a, int b, int c) {
    _InternalUpdate(b, c, a);
}

}
