/* include/types/EAHeap.h — canonical layout for EAHeap + FPHeap
 *
 * S17 TypeArchaeologist Phase 2 deliverable #13.
 *
 * Provenance: promoted from the mature legacy header include/core/eaheap.h
 * (which itself was already evidence-grounded against the EAHeap ctor /
 * Malloc / Free chain). Cross-checked against 13+ matched .cpp files under
 * src/matched/agent/ at addresses 0x802D07xx..0x802D0F24 (DVD-map build).
 *
 * EAHeap inherits from `EA::Allocator::GeneralAllocator` — the base class
 * has a ~0x528-byte layout that we deliberately leave opaque here (it's
 * pure EA SDK, no game logic). Game-side fields start at +0x528.
 *
 * EAHeap is THE universal allocator. Every operator new / malloc / aligned
 * allocation in the game routes through MainHeap / RootHeap / specialized
 * pool heaps. Writers converting allocation-heavy code should `#include
 * "types/EAHeap.h"` and call MainHeap()->MallocAligned(...) etc directly.
 */
#ifndef SIMS2_TYPES_EAHEAP_H
#define SIMS2_TYPES_EAHEAP_H

#include "../types.h"

namespace EA {
namespace Allocator {

/* Opaque base — actual layout lives in the EA SDK, not the game code.
 * Reserve 0x528 bytes so derived EAHeap fields land at the right offsets. */
struct GeneralAllocator {
    /* EAHeap ctor evidence (0x802D09DC): `addi r0, r31, 0x528` for m_name
       store proves base size ≥ 0x528. */
    /* 0x000 */ u8 _opaqueBase[0x528];

    /* Enum used by EAHeap::ValidateHeap — opaque values, treat as int. */
    enum HeapValidationLevel { HVL_OPAQUE = 0 };
};

} /* namespace Allocator */
} /* namespace EA */

/* ============================================================================
 * AllocPoolManager<T> — fixed-array pool wrapper (used by EAHeap statics)
 *
 * Layout: header + raw pool data accessed with stride sizeof(T).
 * Used for the static s_poolBlocks member (ProtectedAllocPool instances).
 * ========================================================================== */
template <typename T>
struct AllocPoolManager {
    /* 0x00 */ s32 m_count;
    /* 0x04 */ s32 m_pad;
    /* 0x08 */ char m_poolData[1]; /* flexible-array tail (raw pool data) */
};

struct ProtectedAllocPool; /* forward — defined in fastallocpool.h */

/* ============================================================================
 * EAHeap — primary heap class
 *
 * Layout (evidenced by EAHeap::EAHeap ctor at 0x802D09DC and the
 * Malloc/MallocAligned/Free family):
 *   0x000..0x527  EA::Allocator::GeneralAllocator base (opaque)
 *   0x528         m_name        (char*)
 *   0x52C         m_parentHeap  (EAHeap*)
 *   0x530         m_auxHeap     (EAHeap*)
 *
 * Total size at least 0x534. The base allocator may extend further; treat
 * fields beyond 0x534 as opaque.
 * ========================================================================== */
struct EAHeap : public EA::Allocator::GeneralAllocator {
    /* 0x528 */ char*   m_name;
    /* 0x52C */ EAHeap* m_parentHeap;
    /* 0x530 */ EAHeap* m_auxHeap;
};

/* ============================================================================
 * FPHeap — fixed-pool heap variant (overrides Malloc/Free/ValidatePools)
 *
 * Adds no instance fields above EAHeap — variant behavior is purely vtable.
 * ========================================================================== */
struct FPHeap : public EAHeap {};

/* ============================================================================
 * Function prototypes — matched EAHeap/FPHeap methods (DVD-map addresses)
 * ========================================================================== */

/* Lifecycle (EAHeap) */
extern "C" void f_802D09DC(void); /* EAHeap::EAHeap(char*, void*, u32, EAHeap*, EAHeap*) */
extern "C" void f_802D070C(void); /* EAHeap::InitializeHeapStatics()          */
extern "C" void f_802D0A5C(void); /* EAHeap::Init(void*, u32)                 */
extern "C" void f_802D09AC(void); /* EAHeap::SetNextCheckPoint()              */
/* extern "C" int  EAHeap_GetCurrentCheckPoint(void);    -- static, no f_*    */

/* Allocation (EAHeap) */
extern "C" void* f_802D0AA4(void); /* EAHeap::Malloc(u32 size, int align)     */
extern "C" void* f_802D0B70(void); /* EAHeap::MallocAligned(u32 size, u32 align, u32 offset, int flags) */
extern "C" void* f_802D0C84(void); /* EAHeap::Calloc(u32 count, u32 size, int flags) */
extern "C" void  f_802D0D78(void); /* EAHeap::Free(void* ptr)                 */
extern "C" void  f_802D0E28(void); /* EAHeap::Compact(void)                   */
extern "C" void  f_802D0E88(void); /* EAHeap::Clear(void)                     */
extern "C" void  f_802D0ED4(void); /* EAHeap::ValidateHeap(HeapValidationLevel)*/
extern "C" void  f_802D0F24(void); /* EAHeap::FindHeapForAddress(void*) const */

/* Named heap accessors (return EAHeap*). Listed without f_ symbols since
 * these are the public C API; the named entries below are the canonical
 * lookup points. */
extern "C" EAHeap* RootHeap(void);
extern "C" EAHeap* MainHeap(void);
extern "C" EAHeap* ResourceHeap(void);
extern "C" EAHeap* VMHeap(void);
extern "C" EAHeap* DebugHeap(void);
extern "C" EAHeap* CUIHeap(void);
extern "C" EAHeap* AudioHeap(void);
extern "C" EAHeap* ShaderHeap(void);
extern "C" EAHeap* TextureHeap(void);
extern "C" EAHeap* AnimationHeap(void);
extern "C" EAHeap* ModelHeap(void);
extern "C" EAHeap* FlashesHeap(void);
extern "C" EAHeap* AptHeap(void);
extern "C" void    f_802CFE64(void); /* RootHeap (matched stub address)       */
extern "C" void    f_802CFF00(void); /* MainHeap (matched stub address)       */

/* C-flavored allocator API (route through the active EAHeap) */
extern "C" void* malloc(unsigned int size);
extern "C" void  free(void* ptr);
extern "C" void* realloc(void* ptr, unsigned int size);
extern "C" void* calloc(unsigned int count, unsigned int size);
extern "C" void* memalign(unsigned int align, unsigned int size);

/* C++ allocator hooks (SN ProDG name-mangled forms) */
void* __builtin_new(unsigned int size);
void* __builtin_vec_new(unsigned int size);
void  __builtin_delete(void* ptr);
void  __builtin_vec_delete(void* ptr);

/* Default-allocator helpers */
void* DefaultAlloc(unsigned int size);
void  DefaultFree(void* ptr);

/* SDA-located globals */
extern int g_currentCheckPoint;

#endif /* SIMS2_TYPES_EAHEAP_H */
