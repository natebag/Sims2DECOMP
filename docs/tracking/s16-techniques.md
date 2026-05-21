# S16 Techniques + Mutators + Deferred-Wall Catalog

Consolidated reference for S16 "Long Haul" session — captures the
promoted source-level techniques, the new mutators shipped, the ASMPROC
composition patterns, and the wall classes deferred to S17.

This is the durable replacement for the transient info-channel posts.
Future sessions should consult this file BEFORE parking complex walls or
authoring new mutators — many walls now have established recipes.

---

## Source-Level Techniques (12 promoted)

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
