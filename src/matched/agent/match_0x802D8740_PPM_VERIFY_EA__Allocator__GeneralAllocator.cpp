// FLAGS: -fno-schedule-insns
// 0x802D8740 PPM_VERIFY(EA::Allocator::GeneralAllocator (12B)
// subfic r0,r4,0; adde r3,r0,r4; blr — returns (param == 0)
namespace EA { namespace Allocator {
struct GeneralAllocator {
    int VerifyAddress(int param) const;
};
int GeneralAllocator::VerifyAddress(int param) const {
    return param == 0;
}
}}
