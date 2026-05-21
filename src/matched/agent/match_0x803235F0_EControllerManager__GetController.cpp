// 0x803235F0 EControllerManager::GetController(unsigned int) (32B)
//
// Static index-bounded array fetch with early-return-on-out-of-range.
// Resolved by source-only goto-shared-label pattern (S15-PROMOTED) — forces
// GCC to pre-load `result = 0` + emit inline `bgtlr` instead of jumping to
// a separate `li r3, 0; blr` tail block.

extern void* EControllerManager_table[4];

class EControllerManager {
public:
    void* GetController(int idx);
};

void* EControllerManager::GetController(int idx) {
    void* result = 0;
    if (idx > 3) goto end;
    result = EControllerManager_table[idx];
end:
    return result;
}
