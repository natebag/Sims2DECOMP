// 0x802DB094 EA::Allocator::GeneralAllocator::ValidateHeap(EA::Allocator::GeneralAllocator::HeapValidationLevel) (84 B)
// Re-entrancy-guarded heap check: the guard word @ +0x494 is cached, and only if
// it is currently clear do we set it, run CheckState, then restore the cached
// value (so a nested ValidateHeap is a no-op reporting "valid"). The error code
// from CheckState is boolified with == 0 (subfic/adde) into the success return.
namespace EA { namespace Allocator {

struct GeneralAllocator {
    char pad[0x494];
    int  m_validationGuard;   // 0x494 = 1172
    bool ValidateHeap(int level);
    int  CheckState(int level);
};

bool GeneralAllocator::ValidateHeap(int level)
{
    int old = m_validationGuard;
    int err = 0;
    if (old == 0) {
        m_validationGuard = 1;
        err = CheckState(level);
        m_validationGuard = old;
    }
    return err == 0;
}

}}
