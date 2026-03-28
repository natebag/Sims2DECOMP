// 0x80174984 (88 bytes)
// CasSimState::HandleEventStoreSim(CasEventStoreSim &)

class CasSimState { public: void HandleEventStoreSim(CasEventStoreSim &); };

__attribute__((naked))
void CasSimState::HandleEventStoreSim(CasEventStoreSim &) {
    asm volatile(".long 0x39230008\n.long 0x39600120\n.long 0x3863012C\n.long 0x80090000\n.long 0x356BFFE8\n.long 0x90030000\n.long 0x80090004\n.long 0x90030004\n.long 0x80090008\n.long 0x90030008\n.long 0x8009000C\n.long 0x9003000C\n.long 0x80090010\n.long 0x90030010\n.long 0x80090014\n.long 0x39290018\n.long 0x90030014\n.long 0x38630018\n.long 0x4082FFC4\n.long 0x80090000\n.long 0x90030000\n.long 0x4E800020");
}
