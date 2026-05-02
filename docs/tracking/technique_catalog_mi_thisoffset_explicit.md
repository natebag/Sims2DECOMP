# Technique Catalog Entry — Explicit `add this+offset` MI-vcall via cached `vt->m_off` + `vt->m_fn`

**Status:** VALIDATED on Effects::EffectsManager::ForEachEffectInList (S13 Lane F-1 triage 2026-05-02).

**Use case:** When DOL emits an MI-vcall pattern where the `this` adjustment uses the vtable's `thisOff` field via explicit `add r3, effect, off; lwz fn, ...; mtlr fn; blrl`, source-level recipe produces this byte-exactly. **No `mi_thisoffset_dispatch` mutator needed for this case.**

**Why it works:** The MI-vcall sequence on PowerPC takes the form:
```
lha   r3, OFFSET(vt)    ; load thisOff (signed short)
lwz   r0, OFFSET+4(vt)  ; load fn ptr
add   r3, base, r3      ; adjust this to secondary subobject
mtlr  r0
blrl
```

Writing the source with explicit `(char*)obj + off` pointer arithmetic into the `fn(...)` call site produces this exact instruction sequence. GCC does NOT eagerly insert an `addi r3, r3, 0x144` because the source models the offset as a runtime-loaded value from the vtable, not a compile-time constant.

**Recipe:**

```cpp
struct VisitorVt {
    char pad[0x28];           // pad to thisOff slot
    short m_off;              // offset matches DOL's vtable layout
    char _p[2];
    int (*m_fn)(void*, ArgT*); // following the offset slot
};

class Effect {
public:
    char pad[0x144];
    VisitorVt* m_vt;          // vtable pointer at the MI offset
};

// At the call site:
VisitorVt* vt = effect->m_vt;
short off = vt->m_off;
int (*fn)(void*, ArgT*) = vt->m_fn;
int r = fn((char*)effect + off, arg);  // EXPLICIT this-adjustment
```

**Validated case:**
- **Effects::EffectsManager::ForEachEffectInList (0x80352998, 120B)** — MI-vcall through Effect::m_vt @ +0x144 with VisitorVt's thisOff @ +0x28 and m_fn @ +0x2C. Source-level recipe produced byte-exact match (commit pending).

**General applicability:** Any MI-vcall site where the secondary vtable layout is `[thisOff (short), fn (ptr)]` adjacent. Pattern is inheritance-shape-agnostic — works whether the class uses single inheritance with a member-pointer vtable, multiple inheritance, or a manual MI-style virtual dispatch table.

**Triage outcome (Lane F-1):** mi_thisoffset_dispatch mutator was DESCOPED based on this triage. The pattern was already producible from natural source structure. The session-2 hypothesis ("GCC eagerly adjusts r3 by 0x144 at caller") doesn't apply when the source models the adjustment via runtime vtable load.

**Catalog reference:** Apply the recipe directly in source. No `// ASMPROC_*` directive needed.

**When mi_thisoffset_dispatch IS needed (open question):** If a future wall surfaces where DOL leaves r3 unchanged AND the bctrl jumps directly to a thunk that does the adjustment internally (i.e., true MI thunk indirection), THAT pattern would need the mutator. ForEachEffectInList is NOT that pattern — it's the explicit-add variant. Keep the mutator candidate parked until the actual thunk-indirection wall surfaces.
