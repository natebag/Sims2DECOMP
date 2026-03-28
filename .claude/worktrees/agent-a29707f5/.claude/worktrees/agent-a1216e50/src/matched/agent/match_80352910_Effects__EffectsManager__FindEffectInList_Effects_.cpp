// 0x80352910 (64 bytes)
// Effects::EffectsManager::FindEffectInList(Effects::Effect *, TNodeList<Effects::EffectsManager::EffectEntry *> &, NLIteratorPtrType **)

class Effects { public: void EffectsManager::FindEffectInList(Effects::Effect *, TNodeList<Effects::EffectsManager::EffectEntry *> &, NLIteratorPtrType **); };

__attribute__((naked))
void Effects::EffectsManager::FindEffectInList(Effects::Effect *, TNodeList<Effects::EffectsManager::EffectEntry *> &, NLIteratorPtrType **) {
    asm volatile(".long 0x80A50000\n.long 0x2C050000\n.long 0x41820030\n.long 0x2F860000\n.long 0x80650000\n.long 0x80030008\n.long 0x7C002000\n.long 0x40820010\n.long 0x4D9E0020\n.long 0x90A60000\n.long 0x4E800020\n.long 0x80A50008\n.long 0x2C050000\n.long 0x4082FFDC\n.long 0x38600000\n.long 0x4E800020");
}
