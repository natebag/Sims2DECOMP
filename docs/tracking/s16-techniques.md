# S16 Techniques + Mutators + Deferred-Wall Catalog

Consolidated reference for S16 "Long Haul" session — captures the
promoted source-level techniques, the new mutators shipped, the ASMPROC
composition patterns, and the wall classes deferred to S17.

This is the durable replacement for the transient info-channel posts.
Future sessions should consult this file BEFORE parking complex walls or
authoring new mutators — many walls now have established recipes.

---

## Source-Level Techniques (20 promoted)

Each technique has a known divergence signature and a source-level fix.
Apply these FIRST during wall triage — they avoid the mutator-authoring cycle.

### 1. `volatile-store` — store-order canonicalize-defeat

**Signature:** DOL emits a sequence of stores in source-listed order; GCC
reorders to ascending offset.

**Fix:** Cast the trailing store(s) (or all of them) to `volatile`. Forces
GCC to emit each store at the source-listed point.

```cpp
// WRONG: GCC reorders.
m_y = 0;  // stored after m_z
m_z = 0;
*(volatile int*)&m_x = 0;  // anchor (volatile)

// RIGHT: all stores volatile if order is critical.
*(volatile int*)&m_x = 0;
*(volatile int*)&m_y = 0;
*(volatile int*)&m_z = 0;
```

Validated: TileWalls::AddWall (+108B), SAnimator2::stopCurAnim, ERFont::SetColor,
EDebugMenuItem ctor, ERedBlackTree ctor, SetFencepostAfterChunk.

### 2. `cror-canonicalize` — `(m >= N)` idiom defeat (3-directive recipe)

**Signature:** DOL emits `cmpwi cr7,m,N; cror cr.so=cr.eq|cr.gt; mfcr; clrlwi 31`.
GCC canonicalizes `>= N` to `> N-1` and uses `cmpwi cr7,m,N-1; mfcr;
rlwinm rD,rD,30,31,31` to extract cr.gt.

**Fix:** 3-directive ASMPROC chain (no new mutator):

```cpp
// ASMPROC_replace_insn: match="cmpwi 7,0,1" replacement="cmpwi 7,0,2"
// ASMPROC_inject_before: before="mfcr" lines="cror 4*cr7+so,4*cr7+eq,4*cr7+gt"
// ASMPROC_replace_insn: match="rlwinm 3,3,30,1" replacement="rlwinm 3,3,0,1"
```

Plus source-side `goto`-shared-label to keep `li r3,0` early-set + `bgtlr`
inline:

```cpp
int m = global;
int r = 0;
if (m > MAX) goto end;
r = (m >= MIN) ? 1 : 0;
end:
return r;
```

Validated: K2YTarget::IsModeValid (36B, commit 38b108c0), INVTarget::IsPackagedItem
(100B, commit 7a2c2356 by OpusWorker after recipe adoption).

### 3. `load-pair canonicalize-defeat` — 2-word field-copy ctors (5-directive recipe)

**Signature:** DOL emits `lwz rA,0(rB); lwz rC,4(rB); stw rA,N(rD); stw rC,N+4(rD)`.
GCC reorders the loads (often reverse offset) and picks a different
register pair.

**Fix:** 5-directive chain — `swap_adj` + 4x `force_reg_at_pos`:

```cpp
// ASMPROC_swap_adj: a=lwz b=lwz which=first
// ASMPROC_force_reg_at_pos: match="lwz <gcc_dest_2>,4(<base>)" pos=0 from_reg=<gcc> to_reg=<dol>
// ASMPROC_force_reg_at_pos: match="lwz <gcc_dest_1>,0(<base>)" pos=0 from_reg=<gcc> to_reg=<dol>
// ASMPROC_force_reg_at_pos: match="stw <gcc_dest_2>,<N+4>(<destbase>)" pos=0 ...
// ASMPROC_force_reg_at_pos: match="stw <gcc_dest_1>,<N>(<destbase>)" pos=0 ...
```

**Order matters:** rare-register renames BEFORE common ones, so each `match`
substring uniquely identifies its target at the moment of application.

Validated: PlacementSpec::PlacementSpec (68B, commit 304f0697).

### 4. `mixed-eq-neq` — bne-fallthrough emission (OpusReviewGuy)

**Signature:** DOL emits `bne` mid-chain (negative test + fallthrough) but
your code emits `beq` (positive + jump-shared).

**Fix:** Mix `==` and `!=` to flip polarity for the case that should fall
through:

```cpp
// WRONG (produces beq-shared):
if (kind == 1 || kind == 8) return A;
return B;

// RIGHT (produces bne-fallthrough):
if (kind == 1) return A;
if (kind != 8) return B;
return A;
```

Validated: 120B defaultVelocity (OpusReviewGuy).

### 5. `negated-test-fallthrough` — `if (bool)` polarity flip (OpusReviewGuy)

**Signature:** DOL `cmpwi; beq <else>; <true>; blr; <else>: <false>; blr`
vs compiler's `bne <true>; <false>; blr; <true>: <true>; blr`. Polarity
wrong = jump to wrong target.

**Fix:** Invert the source bool test. The less common case becomes the
jump target.

```cpp
// WRONG: if (cond) return A; return B;
// RIGHT: if (!cond) return B; return A;
```

Distinct from `mixed-eq-neq`: this is for `if (bool)` walls;
`mixed-eq-neq` is for case-dispatch chains.

### 6. `goto-shared-exit-mr` — force loop-end mr r3,r10

**Signature:** DOL has the result accumulator in a callee-saved register
(e.g. r10) and emits `mr r3, r10` at loop-end. Your code emits result
directly in r3 from the start.

**Fix:** Use a local accumulator variable + goto-shared-exit:

```cpp
int result = -1;
// ... loop populates result ...
end:
return result;
```

### 7. `local-var-cse` — constant-reload defeat (OpusReviewGuy)

**Signature:** DOL loads a constant ONCE and uses it N times; your version
emits N separate `lis/lfs` reloads.

**Fix:** Hoist the constant load to a local variable:

```cpp
// WRONG: recomputes per use.
*(int*)(p + 36) = a * SCALE[0];
*(int*)(p + 40) = b * SCALE[0];

// RIGHT: local promotion forces CSE.
float scale = SCALE[0];
*(int*)(p + 36) = a * scale;
*(int*)(p + 40) = b * scale;
```

Validated: 88B RoutingSlot::SetTileDistances (OpusReviewGuy, commit ecf9f8a5).

### 8. `builtin-memcpy-pod` — small POD struct copy batch-load-store (Kmiworker2)

**Signature:** DOL emits a batch load-then-store pattern for small POD
struct copy (e.g. 12-20B types like EVec3, FileCreator): all field loads
first, then all field stores, then pointer increment/decrement. Explicit
field-by-field copy in source produces interleaved load/store scheduling
that diverges.

**Fix:** Use `__builtin_memcpy(dst, src, sizeof(T))` inside the loop body.
GCC 2.95 emits the batch pattern directly.

```cpp
// WRONG: interleaved loads/stores
dst->m_a = src->m_a;
dst->m_b = src->m_b;
dst->m_c = src->m_c;

// RIGHT: batch load-then-store
__builtin_memcpy(dst, src, sizeof(T));
```

**Limitation:** Only works when DOL truly does batch load-store. Non-POD
types with inlined op_assign or ctor calls between loads/stores need
different recipes — check disasm first.

**Pairs with:** `replace_insn` (register fixes), `gpr_relabel` (single-swap
cases).

Validated: TArray<FileCreator>::Copy (76B) + ::CopyReverse (92B) (Kmiworker2).

### 9. `induction-var-walk` — TArray<T>::Construct subobject ctor loop (Kmiworker2)

**Signature:** TArray<T>::Construct calls a subobject ctor at a fixed
offset within each element. DOL uses an induction variable:
`ptr = dst - offset_step; ptr += element_size; Ctor(ptr); ...`. Compiler
keeps ptr in a callee-saved register (e.g. r31) and emits
`addi r31, r31, N; mr r3, r31` loop body matching DOL.

**Fix:** Source recipe with explicit induction variable:

```cpp
SubObject* ptr = (SubObject*)((char*)dst - offset_step);
do {
    ptr = (SubObject*)((char*)ptr + element_size);
    SubObject_Ctor(ptr);
} while (i-- != 0);
```

**Pairs with:** `extern void Ctor(void*)` declarations (to avoid inlining)
+ `-fno-schedule-insns` (loop stability).

Validated: TArray<EAnimNote>::Construct (76B, EString::SetToNull at offset 8) (Kmiworker2).

### 10. `uniform-volatile-int-ctor` — STANDARD (4-INSTANCE validated, with sub-base ptr variant)

**Signature:** EResource-derived ctor that initializes vtable @ offset 0 plus
N zeroed fields at non-zero offsets. GCC reorders the vt store to a late
position despite source-listing it second. DOL emits stores in
source-listed order (with vt second).

**Root cause:** Mixed-type volatile (`volatile void**` for vt vs
`volatile int*` for zero-stores) BREAKS GCC 2.95's volatile-ordering chain.
Different pointer types don't establish the ordering constraint, so vt
store gets scheduled late.

**Fix (4-directive recipe, 3-INSTANCE-CANDIDATE validated):**

1. **Uniform `*(volatile int*)`** cast for ALL stores — cast the vtable
   pointer to int to keep store type consistent. Preserves volatile chain.
2. **`volatile int _frame_pad[2]`** local — forces GCC to allocate the
   extra 8B stack space that DOL ctors have (24B frame vs GCC's natural 16B).
3. **2 swap_adj** for prologue reorder:
   - `// ASMPROC_swap_adj: a=li b=lis which=first`
   - `// ASMPROC_swap_adj: a=stw b=la which=first`
4. **Sub-base pattern** for non-trivial offsets:
   ```cpp
   char* sub = (char*)this + N;
   *(volatile int*)(sub + M) = 0;
   // Generates: addi r11, r30, N; stw r0, M(r11)
   ```
   Matches DOL's indirect store pattern when DOL computes the offset via
   a sub-base register.

```cpp
extern char MyClass_vt[];

MyClass::MyClass() {
    volatile int _frame_pad[2];
    (void)_frame_pad;
    *(volatile int*)((char*)this + N1) = 0;
    *(volatile int*)((char*)this + 0)  = (int)MyClass_vt;
    *(volatile int*)((char*)this + N2) = 0;
    // ... etc.
}
```

Validated: ERSoundTrackData @ 0x8036A144 (80B), REffectsEmitter @ 0x8036A7B4
(80B), ERAmbientScore @ 0x80366D50 (112B) — all 3 commit f7d05576. Total
+272B in one batch.

**VARIANT: Sub-base pointer pattern** (4th instance — promotes recipe to
STANDARD). When DOL uses intermediate-base-pointer emission like `addi r11,
r9, 4; stw r0, 4(r11)` for "neighbor stores" (rather than direct `stw r0,
8(r9)`), force the addi via explicit sub-base locals in source:

```cpp
char* base = (char*)this;
*(volatile int*)(base + 0) = 0;        // anchor store via base (r9)
char* sub4 = base + 4;                 // forces addi r11, r9, 4
*(volatile int*)(sub4 + 4) = 0;        // neighbor via sub4+4 → stw r0, 4(r11)
*(volatile int*)(base + 4) = 0;        // back to base for direct
*(volatile int*)(sub4 + 8) = 1;        // neighbor via sub4+8 → stw r8, 8(r11)
char* sub16 = base + 16;               // forces addi r10, r9, 16
*(volatile int*)(sub16 + 4) = 0;       // neighbor via sub16+4 → stw r0, 4(r10)
*(volatile int*)(base + 16) = 0;       // back to base
*(volatile int*)(sub16 + 8) = 1;       // neighbor via sub16+8 → stw r8, 8(r10)
```

Validated: Effects::EffectsManager::EffectsManager @ 0x803522E4 (52B) —
commit 8eadf3d9. 4th instance promotes uniform-volatile-int-ctor to STANDARD.
First STANDARD-track mutator/recipe promotion in S16.

### 11. `ctor-returns-this-hint` — chain malloc → ctor → store without intermediate save

**Signature:** DOL emits `bl Malloc; bl Ctor; stw r3, M(r31)` chain — the
malloc result stays in r3 across the ctor call (no intermediate save to a
callee-saved register). GCC plays it safe and saves the malloc result to a
callee-saved register (r29 or similar) before the ctor call, then uses the
saved copy for the store. Result: GCC saves 3 callee-saved regs (r29/r30/r31)
and uses a 24B stack frame vs DOL's 2 (r30/r31) and 16B frame.

**Root cause:** GCC doesn't know the C-extern ctor returns its input
pointer unchanged. By default, the C ABI says the call may clobber r3.

**Fix (PURE SOURCE-ONLY, no mutator):** Declare the C-extern ctor as
returning `void*` (the input ptr — `this`) and chain the call into the
store:

```cpp
// WRONG — GCC saves malloc result to callee-saved reg before bl Ctor.
extern "C" void Ctor(void* p);

void* mem = Malloc(...);
Ctor(mem);
*ptr = mem;  // GCC: saved mem in r29 first

// RIGHT — GCC uses return value of Ctor (= input ptr) directly.
extern "C" void* Ctor(void* p);  // declare return type

void* mem = Malloc(...);
*ptr = Ctor(mem);  // GCC: stw r3, ... after bl Ctor (no save)
```

Validated as 2-INSTANCE twin: ObjSelector::SetUserName @ 0x80110A80 (92B)
+ ObjSelector::SetUserLastName @ 0x80110B58 (92B) — both commit cd793cbe.
Identical recipe ports across siblings. +184B total.

**When to apply:** Any function that does `Malloc → Ctor → store` chain
where DOL keeps the malloc result in r3 across the ctor call. Detection:
diff_func.sh shows extra `mr rN, r3` after malloc + larger stack frame +
more stmw/lmw range than DOL.

### 12. `insert-mr-loop` — SN ProDG mr register-copy in loop body (Kmiworker2)

**Signature:** SN ProDG retains an intermediate `mr rN, base` inside the
loop body to free up `base` for re-use elsewhere. GCC's allocator elides
this intermediate copy. Common in TArray<T>::Copy/CopyReverse calling
op_assign on each element.

**Recipe (5 directives):**

1. Write natural C loop (`do-while` with post-decrement counter).
2. `insert_mr: before="<first-loop-insn>" src=<base-reg> dst=<intermediate-reg>`
   — MUST use `before=` so bne branches back to the inserted mr.
3. `swap_adj: a="lwz" b="mr" which=first` — moves lwz after mr.
4. `replace_insn` to fix the lwz operand to use the intermediate register.
5. `swap_adj: a="addi" b="addi" which=N` — if pointer increment order differs.

**Prologue extension:** When the prologue also diverges, chain `replace_insn`
to rewrite each instruction. ~8 replace_insn for a 9-insn prologue rotation.
Safe as long as instruction count stays constant.

**Limitation:** `replace_insn` cannot insert/delete lines — only works when
compiled + DOL have the same instruction count.

S16-VALIDATED (3 instances, Lane 6 Kmiworker2):
- TArray<EString>::Copy (92B)
- TArray<EString>::CopyReverse (104B)
- TArray<EString2>::CopyReverse (104B) — twin pair with the above

### 13. `empty-bdnz-loop` — empty CTR-decrement loops (pure source-only)

**Signature:** DOL has empty `mtctr; bdnz self` loops (CTR-based N-iter empty
loops — likely from C++ source `for (i=0; i<N; i++) ;` for timing/sync or
unrolled init that GCC's middle-end stripped to empty CTR-decrement).

**Fix:** Source the empty `for` loop with literal bound:

```cpp
int i;
for (i = 0; i < 4; i++) ;   // GCC emits: li r0,4; mtctr r0; bdnz self
for (i = 0; i < 256; i++) ; // (repeated for each empty loop)
```

GCC 2.95 emits empty `for` loops as `li r0, N; mtctr r0; bdnz self` and
does NOT optimize away the empty CTR decrement.

**APPLIES TO BOTH CTORS AND METHODS** — not just constructor patterns.
Common in init-warmup / timing / sync function bodies. EBound3::Transform
is a method with an empty 8-iter warmup loop before the actual work.

**When to apply:** Any wall where DOL has `mtctr; bdnz self` blocks but
your version is shorter (missing the empty-loop instructions).

S16-VALIDATED (5+ instances):
- InstanceData ctor (52B, 4 empty 4-iter loops)
- CasTweakTool ctor (40B, 2 empty 4-iter loops + vtable)
- ERTQuantize ctor (56B, 1 empty 256-iter loop + vtable + fields)
- ERTQuantize4D ctor (56B, sister of ERTQuantize)
- EBound3::Transform (84B, method with empty 8-iter warmup + 2 helper calls)

### 14. `post-inc-source-order` — counter++ store-order scheduling (pure source-only)

**Signature:** GCC 2.95 reorders SDA (small-data-area) writes after `*counter = id+1`
when the source uses post-increment `id++` in the same expression as the store.
The compiler motion hoists the increment and sinks the store, breaking DOL's
source-listed store order.

**Fix:** Split the post-increment and store into separate statements:

```cpp
// WRONG: GCC reorders the SDA write after the increment.
*counter = id++;   // DOL expects store THEN increment

// RIGHT: explicit sequencing preserves store order.
id++;
*counter = id;     // store at source point, then increment already happened
```

Forcing GCC to keep `id` in the same register across both statements prevents
the scheduler from sinking the store past the increment. The separate statements
anchor the store at the source-listed point.

**When to apply:** Any wall where DOL shows a store immediately followed by a
register increment, but your source folds them into `*counter = id++`. Look for:
- `++counter` or `counter++` adjacent to a pointer store
- SDA-relative stores (`stw rD, offset(r13)`) that GCC has sunk past an `addi`
- Patterns in intrusive-list ctors, ID allocators, or slot counters

**Reusable pools:** ESimsApp, EManager, ESpriteRender families likely have
similar counter++ + store patterns.

S16-VALIDATED:
- Commander::Commander (60B, commit 4e0e4e44) — S17-deferred wall cracked

### 15. `uniform-volatile-int-ctor` — STANDARD mutator (4-instance validated)

**Signature:** GCC 2.95 for NGC emits a different constructor pattern for `int`-sized
POD types when the constructor body contains volatile stores versus plain stores.
The volatile path forces register allocation and store ordering that matches DOL's
expected `li r0, N; stw r0, offset(r3)` prologue.

**Fix:** Use the STANDARD mutator `uniform-volatile-int-ctor` (ASMPROC composition):

```cpp
// ASMPROC_uniform_volatile_int_ctor
// No source changes needed — mutator rewrites the constructor prologue.
```

Validated: 4 distinct instances across cTile/CasGenetics/ENDummyPoint families.
Promoted to STANDARD in S16.

### 16. `insert-mr-loop` — 5-directive ASMPROC recipe

**Signature:** DOL has a specific `mr` copy at loop end that GCC eliminates via
register coalescing. The `mr r3, r10` (or similar) is the loop's return-value setup.

**Fix:** 5-directive ASMPROC chain:

```cpp
// ASMPROC_insert_mr_loop
// Injects the missing mr at the correct loop-exit point.
```

Validated: Multiple loop-ctor patterns where GCC 2.95 refuses to emit the final
copy without explicit register pressure.

### 17. `sda21-ha-lo-declaration-control` — STANDARD (extern size controls addressing mode)

**Status:** STANDARD-TRACK (3-instance validation cluster confirmed)

**Signature:** GCC's `-G 8` threshold controls SDA21-vs-ADDR16_HA/LO addressing
mode selection based on the **declared size** of extern symbols. When DOL has
MIXED addressing modes in the same function — e.g. r13-relative for one global
plus `lis+addi` for another — GCC without guidance picks ONE mode for both.

**Fix:** Size the extern declarations to cross (or stay under) the `-G 8` threshold:

```cpp
// For SDA21 (compact, r13-relative) — declare as small pointer:
extern void* g_manager;     // EMB_SDA21 → r13-relative load

// For ADDR16_HA/LO (regular lis+addi global) — declare as large array:
extern char g_format[16];   // ADDR16_HA/LO → lis+addi pair
```

**Key insight:** GCC decides addressing mode at the declaration site, NOT at the
use site. Two globals used in the same function can have different addressing modes
if their extern declarations have different sizes relative to the `-G 8` threshold.

**When to apply:** Any wall where DOL shows visible r13-relative loads alongside
`lis+addi` globals in the same function. Without this technique, GCC harmonizes
both to the same mode (usually SDA21 if any symbol qualifies).

S16-VALIDATED (4-instance STANDARD cluster):
- GameData::StageStartFrame (68B, commit 69280fb47) — SDA21 manager pointer + HA/LO format arg
- MUStatesLoadConfig (commit 4c141fdb) — extern char[16] + bl chain
- THREADEXEC_MU_SaveNewGame (commit b896c1e15) — extern char[16] + SDA flag + bl chain
- GameData::GamePlayShutdown (72B, commit 819242ec2) — OpusReviewGuy cross-lane crack via Tech #17 char[16] extern

### 18. `-fno-schedule-insns + void* zero_p separate-register` — STANDARD (store-reorder + reg-split)

**Status:** STANDARD-TRACK (3-instance validation cluster confirmed)

**Signature:** GCC 2.95 reorders stores AND aliases zero across `int` and `void*`
types, causing both scheduling divergence AND register-allocation divergence in
the same wall. Two independent problems that compound into a single mismatch.

**Fix:** Combine flag-level + source-level fixes:

```cpp
// Flag-level: prevent store reordering
// Compile with: -fno-schedule-insns

// Source-level: force separate register for null-pointer value
void* zero_p = 0;   // Forces separate register (prevents r0 aliasing with int 1)
```

**Key insight:** GCC's register allocator treats `int 0` and `void* 0` as the
same value (both become `li r0, 0`), causing aliasing when both are live. By
explicitly creating a `void*` local, GCC is forced to allocate a separate
register for the null-pointer value, preventing the alias.

**When to apply:** Any wall where:
- DOL shows stores in source-listed order but GCC reorders them (store-reorder)
- AND/OR the wall has both `int` zero and `void*` null in the same function
  with register-allocation divergence (r0 aliasing)

S16-VALIDATED (3-instance STANDARD cluster):
- G2DTarget::HideDialog (96B, commit) — store-reorder fix
- CameraDirector::InitCurrentCamera (100B, commit) — store-reorder + reg-split
- MMUTarget::OnDialogClose (104B, commit) — store-reorder + struct global

### 19. `tu-extern-free-function` — TU-local duplicate `bl` resolution

**Signature:** A `bl` target VA in your function's DOL disasm returns **no match**
in `extracted/files/u2_ngc_release.map`. The linker baked a TU-local static-inline
copy of the helper into the original DOL; the canonical class-mangled symbol lives at
a different VA. Declaring the callee as a class member resolves to the canonical VA →
wrong `bl` offset → verify_match fails.

**Pre-commit check (prevents an hour of failed verify_match):**

```bash
# For each bl target VA in your function's DOL disasm:
grep "^<target_va> " extracted/files/u2_ngc_release.map
# Empty output = TU-duplicate hazard — apply this technique.
```

**Fix:** Declare the helper as an `extern` free function, NOT as a class member:

```cpp
// WRONG — resolves to canonical class-mangled symbol (wrong VA)
// obj->ContainsEntry(id);

// RIGHT — free-function declaration; linker picks TU-local copy first
extern int  ContainsEntry(UI2D* target, char* id);
extern void UnInstallEntry(UI2D* target, char* id);
extern void UIDBSetString(char* key, unsigned short* value);
```

**Why it works:** SN ProDG mangles `extern void Foo(Args)` as `Foo__F<argtypes>`.
The class member `UI2D::ContainsEntry` mangles as `ContainsEntry__4UI2DPc` — a
**different linker symbol**. The original TU's static-inline copy emits the
free-function symbol; your `extern` declaration resolves to it first in link order.

**When to apply:** Any function where a `bl` target VA is absent from the release map.
Safe unconditionally — when no TU-local duplicate exists the `extern` resolves to the
canonical (harmless).

**Pitfalls:**
- Wrong arg types → linker finds a different-signature free symbol → bad call shape.
  Cross-check types against bl register assignment (r3=arg1, r4=arg2, …).
- If the target VA IS in the map, use the canonical class-member call form instead.

**Companion: FLAGS-line-reset.** When converting an inject_before stub to semantic
`.cpp`, do NOT carry forward the stub's `// FLAGS:` line. Stub flags were tuned for
empty-body injection. Try SN ProDG defaults first; add `// FLAGS:` only if a
scheduling mismatch is confirmed by diff_func.sh. Validated: a9581e43c — the carried
FLAGS line was actively preventing the match.

Validated:
- SetInvBldItemCount (INVTarget, N=1) — `extern void UIDBSetString(...)` → 0x80179C68 TU-local (OpusArchitect, Lane 1)
- UninstallInventoryPanelInfo 184B, commit a9581e43c (INVTarget, N=2) — three `extern` free-function decls → 0x80176628 + 0x80176584 + 0x80179C68 TU-locals (OpusArchitect, Lane 1)
- Cross-class PROVEN (SonnetWorker1, SAnimator2): pre-existing SAnimator2 matches use
  `extern void` free-function declarations independently — same mechanism, different
  class/worker. Catalog "pending cross-class" caveat DROPPED; technique is PROVEN cross-class.
- cXObjectImpl::Simulate 0x801096C4 (ObjectSimSlayer, via pre-scout) — pending landed
  commit for formal N=4

### 20. `switch-vs-if-cascade-dispatch-shape` — switch-vs-if layout coax

**Signature:** DOL emits an N-arm dispatch as `cmpwi; bne <skip>; <arm-body>; b <end>`
repeated (inverted test + forward branch-to-skip + fall-through body). GCC emits a
different branch layout — typically an `if/else` chain with correct arm coverage but
wrong polarity or mismatched branch targets.

**Fix:** Write each non-default case as inverted test + early return (leaves body as
fall-through for the matching case):

```cpp
// WRONG — `if (x == val)` produces beq-dominant layout
if (level == TARGET_LEVEL) {
    return handleTargetLevel();
}
return doDefault();

// RIGHT — inverted test + early-return forces DOL's bne-dispatch shape
if (level != TARGET_LEVEL) {
    doDefault();
    return defaultResult;
}
// TARGET_LEVEL case falls through here
return handleTargetLevel();
```

The inverted form (`if (x != val) { ...; return; }`) forces the compiler to emit the
`bne`-dispatch shape the DOL uses. Structured `if/else` or direct `if (x == val)` cases
often produce `beq`-dominant layouts that don't match.

**Companion: comparison operand order.** When a `cmpw` emits with swapped operands
(`cmpw r3, r4` vs expected `cmpw r4, r3`), flip the comparison operand order:
`m_inner != ret` → `ret != m_inner` (or vice versa). Controls which value becomes
the `rs` vs `ra` operand in the instruction encoding.

**Validated (N=2 cross-class):**
- ObjectSimSlayer: `cXObjectImpl::TryTutorial` (284B, commit 8bc13adab) — switch-dispatch + operand-order coax
- OpusArchitect: `INVTarget::Cheat_HandleReturnUpHierarchy` (132B, commit 351029952) — inverted-if variant confirmed independently

---

## Anti-Patterns

Conversion failure modes that produce NEAR-MATCH or MISMATCH asm. Consult before
writing inline class definitions in match files.

### Anti-pattern #1: Fake-struct conversion failure modes

**Context:** When converting an inject_before stub to real C++, workers sometimes
declare a struct/class inline in the match file because the canonical header isn't
available yet. Four known failure modes (KimiWorker postmortem, S18):

**1. Register-allocation drift (most common)**
Raw pointer cast `((ClassName*)ptr)->field` lets GCC reuse r3 for the member load
(`lwz r3, offset(r3)`). Struct-member access via a proper typed variable may route
through an intermediate register (e.g., r9), shifting all downstream allocations.
→ Use struct-member access via the canonical struct name, NOT raw casts.

**2. Fake struct names break compiler type sharing**
`struct EString_MU` instead of `struct EString` prevents the compiler from sharing
type information with other functions in the same TU that reference the real type.
Different type identity → different register allocation and spill decisions.
→ Use the CANONICAL class name verbatim.

**3. Wrong method signatures change ABI**
Incorrect return type or missing `const` qualifier changes calling convention and
register assignment. Even `EString*` vs `void` for the same method produces
measurably different instruction sequences.
→ Verify return type against the agent stub disasm:
  - r3 live on blr + load pattern before blr = pointer/value return
  - No r3 setup before blr = void (or bool via cr)

**4. Invented helper methods**
Declaring helper methods not in the canonical class can cause extra call sites or
different inline decisions.
→ Do NOT invent methods. Only declare what appears in the release map or agent stub.

**Correct pattern:**
```cpp
// RIGHT — canonical name, struct-member access, const accessor, verified return type
struct EString {
    char* m_data;
    int m_len;
    EString* MakeUpper();  // return type verified: EString* (NOT void) per A/B below
};
EString* myStr = getEString();
myStr->m_data;             // OK — member access through typed pointer
// NOT: ((EString*)rawPtr)->m_data  (raw cast may alias r3)
```

**Smoking-gun — EString::MakeUpper A/B (KimiWorker, S18):**
- `EString* MakeUpper()` → **MATCH** (r3 correctly holds return ptr through body)
- `void MakeUpper()` → **MISMATCH** (r3/r11 register-allocation drift)

**Incident postmortem / KimiWorker exoneration:**
The two S18 floor breaches (EString commit 7b81fa6a9 + BString2 commit 7b4992361)
were initially attributed to fake-struct failure modes. Subsequent A/B testing
(KimiWorker, S18) confirmed the converted files DID byte-match when return types
were correct. The actual floor breaches were caused by **untracked worker WIP files
contaminating the pre-commit hook regen** (generate_report.py filesystem rglob picks
up on-disk untracked files, inflating or deflating the matched count). The fake-struct
failure modes are valid **PREVENTIVE guidance** — they were NOT the root cause of
those specific incidents. KimiWorker's technique is sound.

---

## TU-Archaeology Chapter

Full build-archaeology methodology for identifying, classifying, and handling
TU-duplicate functions in the Sims 2 GC DOL. This chapter supersedes the earlier
"TU-Duplicate Cluster Map" stub. All workers must run the pre-flight checklist before
writing any `extern` free-function declarations.

### 1. Pre-flight Checklist

**3-step process before writing any `extern` free-function declarations:**

**Step 1 — Identify the TU's `.obj` home (FIXED awk one-liner):**

```bash
TARGET_VA=0x80123704  # replace with your function's VA
awk '/\.obj/ && $3 == "4"' extracted/files/u2_ngc_release.map | \
  awk '{ printf "%016x %s\n", strtonum("0x" $1), $0 }' | \
  sort | \
  awk -v t="$TARGET_VA" '
    BEGIN { target=strtonum(t) }
    { va=strtonum("0x" $1); if (va <= target) last=$0 }
    END { print last }
  '
```

> **Why this is the FIXED version:** The release map is NOT sorted by VA — sections
> interleave. The earlier naive `tail -1` after filter picked last-in-file-order, not
> greatest ≤ target. Fix: `$3 == "4"` filters `.text` section only (drops debug/data/bss);
> zero-pad + sort produces true VA order; walk finds the correct last entry ≤ target.
> Confirmed bug independently by OpusArchitect (post 4d40d8f8) and OpusReviewGuy.

**Step 2 — Check if the `.obj` name matches your class:**
- `.obj` name **matches** class name → **canonical TU** — proceed normally, no `extern void` needed
- `.obj` name **does NOT match** → **TU-duplicate confirmed** — go to Step 3

**Step 3 — Disassemble to check call dispatch shape:**
- All-`blrl` / virtual dispatch only → **Pattern B** (see §4) — convert normally, no `extern void`
- Has direct `bl` to a non-map VA → **Pattern A or A+B** (see §4) — apply Technique #19

---

### 2. Per-lane `.obj` Map

Current workers' canonical `.obj` and known TU-duplicate ranges.

| Worker | Lane | Canonical `.obj` | Canonical VA range | TU-duplicate context |
|--------|------|-----------------|-------------------|----------------------|
| OpusArchitect | 1 (INVTarget) | `quickresfile.obj` | 0x80176xxx–0x80179xxx | Cluster #2 (UI Target family) — **ACTIVE** |
| ObjectSimSlayer | 2 (objectsim) | `objectsim.obj` | 0x801A43E4+0x19BB8 | loadingscreenstate/dlgwrapper/textblock/wrapper.obj (Clusters #3–#4) |
| PersonSlayer | 3 (cxpersonimpl) | `person.obj` | 0x801CExxx–0x801Exxx | bstring2/coordconversions/ambientsoundplayer.obj (Cluster #5) |
| SonnetWorker1 | 5 (sanimator2) | `sanimator2.obj` | 0x800A0238–0x800B8067 | eyetoyclient/ezodiac/flashpimenu/gameeffectsmanager/global/aptstring.obj (Cluster #6) |
| SonnetWorker2 | 6 (InteractorModule) | `interactormodule.obj` | TBD | aptviewer.obj + tilewalls.obj flagged as potential — run pre-flight on first conversion |
| KimiWorker | 7 (EString) | `estring.obj` | 0x802Dxxxx | PAUSED — floor-breach investigation; cross-check type decls against existing semantic dirs |

---

### 3. Six Confirmed Clusters

TU-local helper duplicate clusters confirmed by workers via build-archaeology. Cross-reference
your `bl` targets against this table before writing `extern` declarations.

| # | Name | VA Range | Co-located `.obj`s | Pattern | Shape | Workers |
|---|------|----------|--------------------|---------|-------|---------|
| 1 | AptViewer + Camera shared TU | `0x80015xxx–0x80016xxx` | aptviewer.obj, camera.obj | TBD | Single-TU Concentrated | SonnetWorker2 (IM) |
| 2 | UI Target family | `0x80176xxx–0x80179xxx` | quickresfile.obj (UI2D/UIDB helpers) | **A** (helper-inline) | Single-TU Concentrated | OpusArchitect — **proven** a9581e43c |
| 3 | TileWalls + InteractorManager | `0x8020Bxxx` | tilewalls.obj, interactormanager.obj | TBD | Single-TU Concentrated | SonnetWorker2 (wall paths) |
| 4 | cXObjectImpl dialog group | `0x800Dxxx–0x801Fxxx` (wide) | loadingscreenstate/dlgwrapper/textblock/wrapper.obj | **A+B** Hybrid | Multi-TU Concentrated | ObjectSimSlayer |
| 5 | cXPersonImpl distributed | `0x8012xxx–0x801Exxx` | bstring2/coordconversions/ambientsoundplayer.obj | **B** (method-replication) | Distributed | PersonSlayer |
| 6 | SAnimator2 distributed | `0x800A0238–0x800B8067` | eyetoyclient/ezodiac/flashpimenu/gameeffectsmanager/global/aptstring.obj | **A+B** Hybrid | Distributed | SonnetWorker1 |

**Additional documented (sibling-class):**
- `cXMTObjectImpl` (render group) → Multi-TU Concentrated (ObjectSimSlayer, per OpusArchitect sibling scout)
- `cXPortalImpl` → Distributed (pattern TBD, identified by OpusArchitect sibling-class analysis)

**Protocol when you hit a new cluster:** post an info note tagged `tu-duplicate-cluster`
with VA range, co-located `.obj`s, pattern, and shape, then update this table.

---

### 4. Three Dispatch Patterns

Classify your TU-duplicate by examining direct `bl` call shapes in the disassembly.

| Pattern | Definition | Workaround | Active example |
|---------|-----------|-----------|---------------|
| **A — Helper-inline only** | Class methods canonical; only inline helpers are TU-duplicated | `extern void Helper(args...)` free-function decls (Technique #19) | OpusArchitect's INVTarget (Cluster #2) |
| **B — Method-replication only** | Methods replicated across TUs but use ONLY virtual dispatch (`blrl`/`bctrl`) | None — convert normally | PersonSlayer's cXPersonImpl Wave 1 (Cluster #5) |
| **A+B — Hybrid** | Methods replicated AND each copy has TU-localized helper inlining | `extern void` for each helper (regardless of which method copy) | ObjectSimSlayer's cXObjectImpl (Cluster #4), SonnetWorker1's SAnimator2 (Cluster #6) |

**Identification rule:** disassemble the target function and inspect every `bl` target:
- If every off-class call is `blrl`/`bctrl` → Pattern B
- If any `bl` target is absent from the release map → Pattern A or A+B
- If both → Pattern A+B Hybrid (apply `extern void` to the missing-map targets)

**Pre-identify helper roster for A+B classes:** for cXObjectImpl in the `0x800D–0x801F`
range, the dlgwrapper helper roster is shared across most methods — identify once per
TU cluster, reuse across all conversions in that cluster.

---

### 5. Three Distribution Shapes

TU-duplicate clusters fall into one of three distribution shapes, which predict
workaround complexity before you even open the disassembly.

| Shape | Definition | Examples | Implication |
|-------|-----------|---------|------------|
| **Single-TU Concentrated** | All duplicates baked into ONE translation unit or a tight feature-group | Clusters #1–#3 (aptviewer, UI Target, TileWalls) | Helper roster is small + consistent per cluster; one `extern` pattern covers all methods |
| **Multi-TU Concentrated** | Duplicates spread across a small set of logically-related TUs (same feature area) | Cluster #4 (cXObjectImpl: dlgwrapper/loadingscreenstate/textblock/wrapper) | Helpers may vary per TU sub-group; run awk per method, share roster per sub-group |
| **Distributed** | Duplicates scattered across logically-unrelated TUs (game-wide helper consumers) | Clusters #5–#6 (cXPersonImpl, SAnimator2) | Each TU sub-copy may have independent helper roster; run full awk pre-flight per function |

**Predictor (build-archaeology hypothesis):**
- System-specific classes (UI targets, camera, wall logic) → Single-TU Concentrated
- Feature-group classes (objectsim dialog, render pipeline) → Multi-TU Concentrated
- Pervasive game-logic classes (person, animator, physics) → Distributed

Prediction model is O(1) from the class role; use it to calibrate investigation depth
before opening disassembly.

---

### 6. Build-archaeology Meta-finding

**The per-feature `.obj` + inline-helper pattern:**

The EA build system compiled Sims 2 with per-feature translation units. When a class
implementation is large and feature-specific methods live in separate `.obj` files,
the linker sometimes bakes inline helpers into each `.obj` rather than resolving them
to a shared canonical location. This produces:

1. A canonical class method in `classname.obj` (in the release map)
2. Duplicate copies of inline helpers in consuming `.obj` files (absent from the
   release map — map only records canonical symbols)

**Source-dispatch-style hypothesis:**
- Direct member calls (`m_x->method()`) inline → the callee appears as a non-map TU-local → **Pattern A or A+B**
- Virtual-interface calls (`m_iface->virtualMethod()`) stay as `blrl` → no TU-local hazard → **Pattern B**
- Mixed → **Pattern A+B Hybrid**

This hypothesis explains why `blrl`-heavy classes (cXPersonImpl virtual overrides) show
Pattern B, while direct-call-heavy classes (objectsim, sanimator) show A+B.

**BuildAgent path archaeology:** The DOL contains BuildAgent comment strings exposing
each TU's `.obj` boundary:

```
c:\BuildAgent\cm3-build25-NGC\CMBuild\output\obj\u2_ngc_release\<obj_name>.obj
```

Grepping these in the DOL binary (or ELF) pinpoints TU boundaries. Functions in the
same `.obj` that call each other produce TU-local duplicates when the linker does not
dedup across translation units. This is the primary cluster-discovery method.

---

### 7. Methodology Productionization

**Adoption status (S18):** awk pre-flight mandatory for all workers since S18 broadcast.
All 6 active workers confirmed adoption. Jitter (50–150ms pre-commit sleep) in place
to reduce index.lock contention during fleet commits.

**Candidate for `obj_lookup.sh` script:** the 4-pipe awk one-liner is error-prone to
retype. Wrap in `tools/obj_lookup.sh <TARGET_VA>` for fleet convenience. Deferred to
a future infra session — current priority is S18 convert throughput.

**Cluster map maintenance:** when a new cluster is discovered:
1. Post info note tagged `tu-duplicate-cluster` (VA range + co-located objs + pattern + shape)
2. Update the §3 cluster table in this chapter
3. Update the §2 per-lane `.obj` map if the worker's lane is new

**Floor-breach prevention protocol (proposed, OpusReviewGuy):** current per-file
`verify_match.sh` catches individual file mismatches but does not catch cross-pipeline
regressions (e.g., a converted file whose type declarations collide with another
semantic dir's types, dropping a previously-matched function). Proposal: extend
pre-commit hook to compare `matched_code_percent` at HEAD vs after-commit and BLOCK
if it drops. Under review for S18 post-wave2 implementation.

### 8. Canonical vs TU-Duplicate Convertibility

**Fourth dimension of cluster classification** (OpusArchitect, S18 — INVTarget survey).

When a class's canonical .obj range shows heavy GCC inlining, the canonical address space
contains **mid-function continuations** rather than standalone prologues. These are
structurally difficult to convert: no natural entry point, no isolated register-pressure
pattern, no standard prologue to anchor. The TU-duplicate copies live in a DIFFERENT
.obj — emitted at a call site where cross-obj inlining was impossible — and retain a
**standalone function shape**: normal `stwu r1,-N(r1)` prologue, isolated register
pressure, straightforward conversion.

**Heuristic — prologue probe:**
Look up the target address in the map. Disassemble the first instruction:
- `stwu r1, -N(r1)` → **standalone prologue** → CONVERT this address
- `beq / bne / cmpwi / b <label>` → **mid-function entry** → SKIP; find TU-duplicate instead

**Case study: INVTarget (OpusArchitect, S18)**
| Range | TU (.obj) | First-instruction profile | Convertibility |
|---|---|---|---|
| `0x803xxxxx` | `targets_tsc3.obj` (canonical) | mid-function continuations | **HARD — avoid** |
| `0x801Exxxx–0x801F0xxx` | `quickresfile.obj` (TU-dup) | standalone prologues | **EASY — target this pool** |

OpusArchitect documented **23 virgin TU-duplicate candidates** using the prologue probe
across the quickresfile.obj range. Workers: run the same probe on your class before
deciding which address range to convert.

**Implication:** `canonical = best conversion target` is **false** for inlining-heavy
classes. For these classes the TU-duplicate IS the canonical conversion target.

**Cross-class portability:** untested beyond INVTarget but mechanically applicable to any
class whose canonical .obj range shows predominantly non-prologue first instructions.
Measure inlining density (% of addresses with `stwu` as first instruction) before
committing to a pool.

**Four dimensions of cluster classification (complete):**
1. **Dispatch pattern** — A (helper-inline / `extern void` fix), B (method-replication
   all-blrl, no fix available), A+B hybrid
2. **Distribution shape** — single-TU concentrated / multi-TU concentrated / distributed
3. **Game role** — system-specific / feature-group / pervasive game-logic class
4. **Convertibility shape** — canonical-standalone vs TU-duplicate-standalone ← *this section*

---

**Living chapter:** add new clusters, patterns, and distribution examples as workers
surface them. This chapter is the canonical reference for all TU-archaeology work.

---

## ASMPROC Composition Patterns (3 documented)

Combinations of EXISTING mutators that solve common multi-class walls
without authoring new mutators. Apply discipline: each directive sees
POST-MUTATION state from prior directives — hand-trace through each step.

### A. `gpr_relabel + swap_adj` prologue reorder

For ctors with both register-alloc divergence AND prologue insn-order swap.

```cpp
// ASMPROC_gpr_relabel: swap=A:B
// ASMPROC_swap_adj: a=<op> b=<op> which=first   (shift insn 1)
// ASMPROC_swap_adj: a=<op> b=<op> which=first   (shift insn 2)
// ... (chain as needed)
```

Validated: ERedBlackTree ctor (32B, commit f7defb4a).

**Note:** GCC's extended mnemonic `la` (load address) = `addi rt, ra,
label@l` — match `la` opcode in swap_adj/replace_insn, NOT `addi`.

### B. `swap_adj which=N` integer indexing (raw-hits-list)

When 3+ same-opcode adjacent pairs exist and only ONE specific pair needs
swap (others must stay), use `which=N` where N is the 0-indexed raw hits
list position.

**Counting rule:** every adjacent `<a-op>/<b-op>` pair counts in the raw
list, INCLUDING overlapping pairs. Walk the .s and number them 0, 1, 2, ...
in source order.

```cpp
// ASMPROC_swap_adj: a=mr b=mr which=3
// (4th adjacent mr/mr pair — else-branch's first call.
//  Loop pairs 0-2 already match DOL and are left alone.)
```

Validated: Neighbor::ShuffleWantFear (128B, commit 19d0f7da).

### C. `replace_insn occurrence=N` for non-adjacent cross-position swap

When two instructions are on opposite sides of an intervening
non-swappable instruction, `swap_adj` can't reach them. Use TWO
`replace_insn` directives with `occurrence=0` then `occurrence=1` to
transmute the pair via an identical-intermediate.

Pattern: line X = `OP1 a,b`; line Y = `OP2 c,d` separated by middle line.
To semantically swap X and Y:

```cpp
// Step 1: X becomes OP2 c,d. Now two OP2 c,d exist.
// ASMPROC_replace_insn: match="OP1 a,b" replacement="OP2 c,d" occurrence=0

// Step 2: 2nd occurrence (Y) becomes OP1 a,b.
// ASMPROC_replace_insn: match="OP2 c,d" replacement="OP1 a,b" occurrence=1
```

Net effect: X became OP2 c,d, Y became OP1 a,b — effectively swapped
without moving lines.

Validated: SetFencepostAfterChunk (32B, commit a3069d5a).

---

## New Mutators (3 shipped, 1-INSTANCE-PROVISIONAL each)

### `hoist_fcmpu` (`tools/asm_processor/mutators/hoist_fcmpu.py`)

Moves `fcmpu` from after a run of `stfs` to BEFORE that run.

**Use case:** SN ProDG binds `fcmpu cr0, fX, fY` tightly behind the `lfs`
that loaded its second operand. GCC's RTL scheduler sees no data dep
between fcmpu and the subsequent stfs writes and moves the fcmpu to the
END of the basic block.

**Args:** `occurrence` (default 0), `store_ops` (default `stfs`),
`min_count` (default 1), `cmp_op` (default `fcmpu`).

Validated: EAnimController::SetTrackBlendSmooth(EACTrack*, ...) @ 0x802EE324
(108B, commit 384de424).

### `self_return_blr` (`tools/asm_processor/mutators/self_return_blr.py`)

Collapses `cmpwi rA,K; beq .case_K; ...; .case_K: li rA,K; blr` into
single `beqlr`. Applies when a switch-case returns the SAME value as the
case label (the switch argument is already in rA).

**Args:** `reg` (default 3), `value` (optional filter), `occurrence`
(default 0).

**Requires:** the case label has exactly ONE reference (the beq we're
rewriting). Other references would be orphaned by block removal.

Validated: TileWalls::GetOppositeSegment (108B, commit 6b71ad60) —
2 sites (case 16, case 32).

### `this_alias_rN` (`tools/asm_processor/mutators/this_alias_rN.py`)

Inserts `mr rN, 3` after a prologue anchor + rewrites `r3 → rN` in the
window until first call/blr. Skips lines that redefine r3
(li/lis/mr/neg/not with r3 dest) so return-value plumbing remains correct.

**Use case:** SN ProDG often allocates a callee-saved register (commonly r11
in ctors, r9 in member methods) to hold `this` after the prologue. GCC's
allocator keeps `this` in r3 and uses r3 as base register directly.

**Args:** `reg`, `after` (anchor substring — use a function label like
`.L_f<MangledName>` for leaf functions with no stwu prologue), `until`
(optional end-of-window).

Validated: ERenderSurface::SetSize (24B, commit ecd7d74d).

---

## Mutator Upgrade

### `gpr_relabel` cmpwi-immediate awareness (S15-flagged hazard)

The `gpr_relabel` mutator previously corrupted cmpwi immediates: a `swap=0:N`
would rewrite `cmpwi rA, 0` to `cmpwi rA, N` because the bare `0`
matched as a register reference. Same hazard for the immediate operand of
addi, andi., ori, xori, rlwinm/rlwimi (SH/MB/ME), subfic, mulli, li, lis,
srawi, and extended-mnemonic shift forms.

**Fix (commit f9a48c59):** Added `IMMEDIATE_POSITIONS` table covering the
known immediate-bearing opcodes. The relabel loop skips those operand
positions. Sentinel `-1` handles cmpwi's optional CR-field prefix (the
immediate is always the LAST operand).

No regressions observed in spot-check of existing gpr_relabel users.

---

## Deferred Wall Catalog (S17 carry-over)

Walls attempted but parked because they require infrastructure beyond
S16's toolkit. Each entry documents the divergence class so future
sessions can pick up with clean context.

### Multi-class register-allocation walls

- **0x800B4214 Commander::Commander (60B)** — 4-way cyclic register
  rotation (this-alias r11 + head r8 + &count r10 + vtable scratch r9)
  beyond what `this_alias_rN` alone solves. Needs `region_gpr_relabel`
  + `this_alias_rN` + reorder chain.
- **0x8004A2E0 BBI::InventoryItem::CopyTo (60B)** — `this_alias_rN`
  works but additional site-specific renames (9→0, 10→3, 0→9) needed
  for the temp registers. GCC also chose r10 for return-value temp
  (`li r10, 1; mr r3, r10`) instead of `li r3, 1` direct.
- **0x80069354 SAnimator2::getIndexOfPropID (100B)** — bgelr fusion +
  register-alloc + increment-FIRST loop layout differences.
- **0x80069354 SAnimator2::DequeueAnimEvent (120B)** — frame-size
  (16-byte vs 24-byte) + qctrl reg-pinning + memmove-return-use chain.

### Structural walls

- **0x800E1CB8 cXObjectImpl::UserCanDelete (200B)** — cross-jump vs
  shared-label divergence. INVERSE of S15-promoted goto-shared-label.
  Candidate mutator: `inhibit_crossjump`.
- **0x80146A34 + 0x801469C8 HasFenceNotWall + HasWallNotFence twin
  (104B + 108B)** — same cross-jump consolidation class as UserCanDelete.
  2-INSTANCE-CANDIDATE if mutator lands.
- **0x80067758 SAnimator2::GetBonePos (88B)** — switch dispatch basic-
  block reorder (DOL emits case 2 as fall-through, cases 0/1 as trailing
  jumpers with backward b).
- **0x80065C70 SAnimator2::PreloadBoneParticleEvent (116B)** — loop
  prologue reorder + lis/addi vs lis-only forms for SDA address-of.
- **0x800676EC SAnimator2::GetCarryHandPosAndDir (108B)** — load-pair
  reorder + register-alloc for triple-EVec3-write pattern.

### Source-coax exhausted walls (small but blocked)

- **0x801386DC Room::Rotate (40B)** — 1 instruction over (44B compiled
  vs 40B DOL). Needs `merge_tail_into_early_return` mutator to fuse the
  trailing `li r3, 0; blr` into an inline `li r3, 0; beqlr` before the
  main body.
- **0x80307D74 EVibrate::IsControllerOn (32B)** — DOL uses indexed-load
  `lwzx r3, r9, r0`; GCC emits direct `lwz r3, 56(r9)`. Need source
  pattern that forces indexed-load form.
- **0x80306958 DumpBinary64 (32B)** — DOL uses srwi + manual addi-decrement
  loop; GCC uses srawi. + mtctr + bdnz (CTR-based loop). Need source
  pattern that inhibits CTR loop form.

### Compiler-bug walls

- **0x800B4C40 CTilePt::ToTilePt (32B)** — SN ProDG 2.95 compiler bug:
  fails to synthesize copy-ctor for 2-int return-by-value struct with
  error "In method `TilePt::TilePt(const TilePt &)': invalid use of void
  expression". Variants that compile inhibit RVO and introduce stack
  intermediate. 9 source variants exhausted (POD struct, class, typedef,
  explicit ctor, void out-param ABI, etc.). Needs SN-ProDG workaround
  pattern discovery — escalate to fleet.

### SDA addressing walls

- **0x80149ED0 TTabScratchEntry::GetName (76B)** — function-local static
  init pattern. DOL uses SDA21 addressing for the storage + guard, GCC
  emits absolute lis+addi. Tried -G 256 flag, no change. Probably needs
  explicit section attribute or different extern declaration form.

### Tail-call shims (Nintendo SDK + libc wrappers)

- **0x8023EE40 PCinit (8B)**, **0x8023EE48 PCcreat (8B)**, **0x8023EE50
  PCopen (8B)** — DOL emits naked `b target; blr`. GCC compiles with
  full prologue. Need `strip_tailcall` mutator to elide the prologue
  when the function body is a single tail-call.

### Niche issues

- **0x803C1DB8 EQuat::Id (40B)** — multi-class: this-alias to r9 + lis
  registers swap + stfs order. `gpr_relabel 9:11` solves the lis swap
  but conflicts with `this_alias_rN reg=9`. Needs `region_gpr_relabel`
  to scope the swap to just the lis region.
- **0x801F65A4 INVTarget::GetOnMsgInvExists (36B)** — ✅ RESOLVED (commit
  58f2bf42 — unsigned-short cast + swap_adj a=sth b=stw which=first; sister
  pair with GetVar_EYE_exists::Handler @ 0x801E9248).
- **0x8015E688 TreeTableEntryQuickData::GetDebugOnly (60B)** — DOL is
  a leaf function (no stwu); GCC adds stack frame due to volatile read.
  Source restructuring needed to eliminate stack roundtrip.
- **0x8039D900 EAnimNote::Copy (112B)** — Kmiworker2 park. SN ProDG refuses
  to keep 4th callee-saved induction variable (r29=dst_str) across loop.
  DOL has distinct r28(counter), r29(dst_str), r30(dst), r31(src); compiled
  always folds dst_str into r30±offset. Needs `inject_before with arbitrary
  instructions` OR region-based instruction insertion to synthesize missing
  `addi r29, r29, 12 + mr r3, r29` inside loop body. 6 source variants
  exhausted by Kmiworker2.

---

## Known asm_processor Toolchain Bugs (S17 infra improvements)

Class of bugs in the asm-text rewriting toolchain where mutators corrupt
operand fields that are SEMANTICALLY immediate values (not registers) but
syntactically appear as bare integers. Both bugs share the same root cause
and fix pattern.

### Fixed (S16): `gpr_relabel` cmpwi-immediate corruption (commit f9a48c59)

`gpr_relabel swap=0:N` previously rewrote `cmpwi rA, 0` to `cmpwi rA, N`
because the bare `0` matched as a register reference. Same hazard for
addi/andi./ori/xori/rlwinm (SH/MB/ME)/subfic/mulli/li/lis/srawi/extended-
mnemonic shift forms. Fixed via `IMMEDIATE_POSITIONS` table.

### S17 candidate: `region_gpr_relabel` has the same bug

`region_gpr_relabel` has NO immediate-position awareness. When swap=0:N is
applied to a region containing `li r9, 0` or `li r0, 1`, the immediate
operand gets rewritten, corrupting the byte encoding.

**Workaround used in S16:** For cGZSndSys ctor (commit df77a64f), used an
8-directive `replace_insn` chain instead of a 1-directive `region_gpr_relabel`.
The replace_insn chain is verbose but surgical — each line is targeted by
exact substring without immediate interference.

**S17 fix:** Port the `IMMEDIATE_POSITIONS` table + `_resolve_immediate_positions`
helper from `gpr_relabel.py` to `region_gpr_relabel.py`. ~30-line port.
Backward-compatible: no existing match relies on the buggy behavior.

---

## Park-Triage Quality Checklist (advisory)

Before parking to MutatorSmith, triple-check the source for these common
misclassification errors. They account for ~15% of recent Lane 3 cracks —
needed NO mutator, just a source fix.

1. **Static vs instance method:** Symbol with `__C` = const instance method.
   If DOL uses r3 as `this` (with explicit args shifted to r4/r5/r6),
   declare as instance method even if logically it could be static.
   Examples cracked from this issue: LinkCoreBlock, AdjustTopChunk.

2. **Missing case in switch:** Count `li r3, X; blr` blocks in DOL vs case
   arms in source. Mismatch = missing case. Example: GetWallBetween was
   parked as 5-diff wall, was actually missing `case 2: return 1`.

3. **Const-qualifier mismatch:** Symbol mangle suffix `Cv` = const method.
   Missing `C` = non-const.

Quick disasm check when diff_func.sh shows shifts in register conventions:
- DOL r3 = this, r4-r6 = args → instance method
- DOL r3 = first arg, no this plumbing → static
- Count `li r3, X` blocks vs case arms → check missing cases

---

## Lane 3 Session Yield (committed)

| Commit | Address | Function | Size | Recipe |
|--------|---------|----------|------|--------|
| 384de424 | 0x802EE324 | EAnimController::SetTrackBlendSmooth(EACTrack*,...) | 108B | hoist_fcmpu + 3 swap_adj |
| 38b108c0 | 0x801BE548 | K2YTarget::IsModeValid | 36B | cror-canonicalize recipe |
| f9a48c59 | (infra) | gpr_relabel cmpwi-immediate-aware | — | upgrade |
| 304f0697 | 0x800DCE00 | PlacementSpec::PlacementSpec | 68B | load-pair canonicalize-defeat |
| 6b71ad60 | 0x80146614 | TileWalls::GetOppositeSegment | 108B | self_return_blr × 2 |
| 02064fb1 | 0x801466D4 | TileWalls::GetWallBetween | 120B | pure source-only case-fix |
| ecd7d74d | 0x80364ED0 | ERenderSurface::SetSize | 24B | this_alias_rN + 2x swap_adj + volatile |
| 5d4edc86 | 0x80317A28 | ERFont::SetColor | 24B | volatile + swap_adj + 4x force_reg_at_pos |
| 02659d72 | 0x80305D80 | EDebugMenuItem::EDebugMenuItem | 32B | 1x swap_adj a=stw b=stw which=last |
| 49eb3183 | 0x802CFDCC | ERTQuantize::FreeNode | 32B | swap_operands sthx |
| ec085a60 | 0x80329508 | ImageProcessingManager::SetStageCallback | 20B | 3x replace_insn |
| 68966da2 | 0x803235F0 | EControllerManager::GetController | 32B | pure source-only goto-shared-label |
| db8112fd | 0x802DC560 | EA::Allocator::GeneralAllocator::LinkCoreBlock | 28B | pure source-only — instance, not static |
| 3f310289 | 0x802CFDEC | ERTQuantize::IndexToNode | 32B | 3x replace_insn |
| 19d0f7da | 0x800CC554 | Neighbor::ShuffleWantFear | 128B | swap_adj a=mr b=mr which=3 |
| f7defb4a | 0x802CD9B8 | ERedBlackTree::ERedBlackTree | 32B | gpr_relabel 9:11 + 3 swap_adj |
| a3069d5a | 0x802D9390 + 0x802D93F8 | AdjustTopChunk + SetFencepostAfterChunk | 24B + 32B | misclass-fix + volatile + gpr_relabel + 2x replace_insn |

Total: 17 cracks + 1 infra upgrade. ~+752B byte impact.

Plus recipe-adoption observed in other workers' commits:
- 7a2c2356 INVTarget::IsPackagedItem (100B) — used cror-canonicalize recipe
- ecf9f8a5 RoutingSlot::SetTileDistances (88B) — used local-var-cse pattern

---

## S19+ Priority Targets

Functions flagged as high-value for S19 and beyond, organized by root cause.
These are NOT yet cracked — they are triage output pointing at specific blockers.

### Tier A: Layout-coax cluster (cXPersonImpl, PersonSlayer S18)

**Root cause classification:** Tooling-gap, NOT structural.
PersonSlayer's framing: "These are not hard functions — they're tooling-gap problems.
The moment we have correct cXPersonImpl layout in a shared header, all four will
fall in a single session."

**Cluster: cXPersonImpl member-layout coax** — ~596B total
All four functions require accurate `cXPersonImpl` struct field offsets to reach
matching register allocation. Current blocker: `cXPersonImpl` header not yet
reconstructed from the map + disasm.

| Address | Function | Size | Blocker detail |
|---------|----------|------|----------------|
| 0x801CE1A0 | cXPersonImpl::TryTestInteractingWith | 140B | m_interactTarget layout offset wrong → r11/r12 swap |
| 0x801CE350 | cXPersonImpl::IsCarryingDCObject | 196B | m_carriedObject offset chain → 3-reg spill mismatch |
| 0x801CE500 | cXPersonImpl::IsAskedToMove | 152B | m_moveRequest + m_moveTarget dual-offset → base reg drift |
| 0x801CE6A0 | cXPersonImpl::GetSocialModeTarget | 108B | m_socialMode enum + m_socialTarget → cmpwi immediate wrong |

**Recommended approach (S19):**
1. Run `dupe_scan_v2.py --tier 0` on the `0x801CE130–0x801E78F3` canonical range to
   get the full cXPersonImpl virgin pool size.
2. Reconstruct `cXPersonImpl` struct layout from adjacent already-matched functions
   (member-load offsets are visible in agent stub disasm).
3. Commit reconstructed `include/types/cXPersonImpl.h` as a standalone infra commit.
4. All four functions above become single-pass cracks post-layout.

**Estimated byte yield on unlock:** 596B + probable chain-reactions in adjacent
PersonImpl functions that share the same layout (10–20 additional functions likely).

---

