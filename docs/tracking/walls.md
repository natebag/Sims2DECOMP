# Walls — Functions that did not match cleanly

This is the honest backlog. Each entry below is a function a matcher tried to
write clean C++ for but couldn't get to byte-identical output without reaching
for the banned tools (ASMPROC mutators, NON_MATCHING, register-pin, inline asm).

**Logging a wall is legitimate progress.** It documents what the frontier looks
like, what was tried, and what the next attempt should consider. Over months,
walls either get cracked by a smarter pass / a different compiler flag baseline /
a new contributor — or they stay as honest documentation of the project's
current ceiling.

## How to log

Add a new section at the bottom of this file with this shape:

```
## 0xADDRESS NameOfFunction (sizeB)

**Tried:** what you attempted (source shape, flag overrides, type variations).

**Asm shape that didn't reduce:** the specific DOL instruction pattern that no
C++ form you wrote could naturally emit. Paste 3-6 lines of the divergent
section if useful.

**Notes / hypotheses:** ideas for the next pass — possible compiler quirks,
struct-layout suspicions, candidate flag tweaks, etc.

**Logged by:** <matcher name>, YYYY-MM-DD.
```

## How to retry

If you (or a later pass) think you can crack a wall:

1. Read the entry.
2. Attempt a clean match using the new idea.
3. On clean MATCH → commit normally, then **delete the wall entry** here.
4. On MISMATCH → either iterate further or append a new "Retried" note to the
   existing entry (don't replace; preserve the trail).

## Walls

## 0x8009F570 BString::find_first_not_of(unsigned char, unsigned int) const (120B)

**Tried:** Natural while-loop —
`while (pos < length() && data()[pos] == c) ++pos; if (pos >= length()) return -1; return pos;`
with `unsigned char *data()` + `unsigned char c` (kills the `extsb` that signed
`char` would emit). Structure is byte-exact: the `b` to loop-cond, the two `bl
length`/`bl data` calls per iteration, the trailing third `bl length` check, and
the `li -1`/`mr pos` return all match the DOL instruction-for-instruction.

Variants tested (all keep `c` in r29 instead of spilling): operand-order swap
(`c == data()[pos]`), `for`-loop early-return form, signed-`char` + `(unsigned
char)` casts, `unsigned int length()`, `-O1`, `-fno-schedule-insns`.

**Asm shape that didn't reduce:** the DOL spills the `char` parameter to the
stack and reloads it each iteration, using only 2 callee-saved registers:

```
DOL:   stmw r30,16(r1)   ; saves r30,r31 only
       stb  r4,8(r1)      ; c spilled to stack home
       ...
       lbzx r9,r3,r31     ; data[pos]
       lbz  r0,8(r1)      ; reload c from stack
       cmpw r9,r0
MINE:  stmw r29,12(r1)    ; saves r29,r30,r31
       mr   r29,r4        ; c kept in callee-saved r29
       ...
       lbzx r0,r3,r31
       cmpw r0,r29        ; compare against c-in-register
```

SN ProDG at -O2 assigns `c` a callee-saved register (r29); the original build
left it in its stack home slot. This is a register-allocator cost-model choice,
not reachable from any natural C++ shape I found. (`volatile unsigned char cc =
c;` *does* force the spill and collapses the diff to a single 2-instruction
prologue swap — `stb`-before-`mr` vs `mr`-before-`stb` — but `volatile` is a
codegen hack the original didn't have, and even `-fno-schedule-insns` doesn't
flip the swap, so it's not a clean path.)

**Notes / hypotheses:** Next pass: find a natural source construct that makes
the allocator prefer the stack home for a `char` param used once per loop
iteration across two calls. Possibly a different live-range shape (e.g. the
original may have read `c` through a wider expression, or had a 4th short-lived
local that perturbed allocation order). The sibling looping char finds in this
family (find_char 0x8009F090, find_first_of(char) etc.) will hit the identical
wall — cracking the spill here unlocks the whole sub-family.

**Logged by:** Matcher-SN-2, 2026-05-30.

## 0x80241378 fabsf (36B) — and the whole libm float-return family

**Compiler:** MWCC GC-1.2.5n (`// COMPILER: mwcc`). This IS the right compiler
family for the math lib — see below — but it cannot reproduce one return idiom.

**Tried:** ~20 source shapes × full flag sweep. Bit-twiddle fabsf via:
single-union (`u.f=x; u.u&=0x7fffffff; return u.f`), pointer pun
(`*(unsigned long*)&x &= 0x7fffffff; return x`), union-pointer alias on `&x`,
union-reference alias, store-other-then-reload, fdlibm two-union
GET_FLOAT_WORD/SET_FLOAT_WORD, return-through-separate-float, reassign-param.
Flags swept: -O0..-O4, with/without `,p` peephole, `-opt noschedule`,
`-sym on`, `-g`, `-inline off`, no-opt. Also tried `mwcceppc_old.exe`
(same v2.3.3 build 163, adds a profiling `bl`/`nop` stub — worse).

**Asm shape that didn't reduce:** the function tail. DOL loads the result into
scratch `f0` then moves it to the return reg `f1`:
```
DOL:   c0010008  lfs  f0,8(r1)
       fc200090  fmr  f1,f0
       38210010  addi r1,r1,16
MINE:  c0210008  lfs  f1,8(r1)      ; MWCC always loads straight to f1
       38210010  addi r1,r1,16      ; (no fmr — register-coalesced away)
```
The pointer-pun form `*(unsigned long*)&x &= 0x7fffffff; return x;` matches
**7 of 9 instructions exactly** including the hard part: x spilled to `8(r1)`
(MWCC otherwise picks `12(r1)`; aliasing the param's own slot via `&x` is what
pins offset 8). The ONLY residual is the gratuitous `lfs f0; fmr f1,f0` return
move. No C++ source or flag I tried makes mwcc 1.2.5n emit it — its allocator
always coalesces the load into f1 directly.

**Family-wide:** `copysignf` (0x8024265C, 52B) ends with the identical
`...; stw r9,8(r1); lfs f0,8(r1); fmr f1,f0; addi; blr` tail. The float-return
idiom is shared across the libm family (fabsf, copysignf, almost certainly
sinf/cosf/sqrtf/fmodf wrappers). Cracking it once unlocks the family.

**Notes / hypotheses:** Initial hypothesis was an older/less-aggressive
Metrowerks codegen. **DISPROVEN 2026-05-30:** Tooling-Engineer extracted MWCC
1.0, 1.1, 1.1p1, 1.2.5 alongside 1.2.5n; all FIVE versions produce byte-identical
output for fabsf (`lfs f1,8(r1)` direct, no fmr) at -O1/-O2/-O4,p. Even MWCC 1.0
coalesces the return load into f1. So this is NOT a compiler-version wall.

**DUAL-COMPILER DISPROOF (final diagnosis, 2026-05-30):** Tested BOTH routes:
- MWCC 1.0/1.1/1.1p1/1.2.5/1.2.5n: all byte-identical, `lfs f1` direct, no fmr.
- SN ProDG 3.9.3 (cc1plus, fdlibm sf_fabs.c source) at -O0/-O1/-O2 ±schedule:
  gets offset 8 naturally BUT uses `r9` for the clrlwi/stw temp and loads direct
  to `f1`.

The DOL uses `r0` for the temp (`clrlwi r0,r0,1; stw r0,8(r1)`) AND `lfs f0;
fmr f1,f0`. **Neither compiler in the repo reproduces the r0+f0+fmr signature.**

Per the release map (`u2_ngc_release.map`), `fabsf` is linked from
`SN Systems\ngc\lib\libm.a(sf_fabs.o)` — a **precompiled static lib**. So the
DOL's fabsf was built once, into libm.a, with an **older SN/GCC toolchain not
present in this repo** (our cc1plus is the 3.9.3 release; the shipped libm.a
predates it). This is a **compiler-PROVENANCE wall**, common to precompiled
runtime libs: the math family (fabsf, copysignf, sinf, cosf, sqrtf, fmodf, ...)
will all share it. NOT MWCC territory, NOT forceable, NOT crackable with current
tools. Future pass: obtain the matching vintage SN libm build, or accept these
as a documented precompiled-lib ceiling.

Map note: symbols.txt's 0x80241378 is CORRECT for the DOL — the **DVD map**
(`u2_ngc_release_dvd.map`, the build that matches the DOL) lists fabsf there. The
release map's 0x803BFD98 is a *different build* (cm3-build25 ≠ DOL). No
symbols.txt error.

**Logged by:** Matcher-MWCC-SDK, 2026-05-30 (dual-compiler disproof, final).

## 0x8024D880 OSLoadContext (216B) — hand-written supervisor asm (PERMANENT wall class)

**Compiler:** N/A. This is not a compiler-codegen problem — the function is
hand-written PowerPC assembly that has NO C-language expression at all.

**Tried:** Read-only crackability assessment (per MainGuy: assess one hard
hand-asm SDK stub). Did not attempt a C source — the disassembly makes clear no
C compiler (MWCC or SN) can emit these instructions.

**Asm shape that no C can emit:** OSLoadContext restores a full OSContext thread
state and resumes via return-from-interrupt. The body uses privileged /
whole-register-file instructions with no C primitive:
```
lmw   r5,20(r3)      ; load-multiple: restore r5..r31 directly into the live GPR file
lmw   r13,52(r3)     ; (alt path) restore r13..r31
mtspr 913..919,r4    ; restore GQR0..GQR6 (paired-single graphics quantization regs)
mtcr  / mtlr / mtctr / mtxer        ; restore CR, LR, CTR, XER
mfmsr ; rlwinm (clear RI/EE) ; mtmsr ; restore MSR
mtsrr0 r4 ; mtsrr1 r4 ; rfi          ; load SRR0/SRR1 and return-from-interrupt
```
A C compiler cannot: write arbitrary GPRs/SPRs by number, `lmw` into the live
register file, manipulate MSR, or issue `rfi`. The function's entire purpose is
to overwrite the register state the C ABI assumes it owns, then atomically jump.

**Notes / hypotheses:** PERMANENT wall under the honesty rules — the only ways to
reproduce it (`__asm__`, `.byte`, ASMPROC injection, naked) are all banned. This
is the correct classification, not a temporary block. The sibling boot/kernel
asm stubs share this class and should NOT be attempted as clean C:
- 0x8024BB00 OSExceptionVector (156B) — exception entry, mtsprg/mfsrr/rfi
- 0x8024D800 OSSaveContext (128B) — stmw / mfspr GQRs / mfmsr
- 0x8024D53C __OSLoadFPUContext (292B) — lfd/psq_l FPR+paired-single restore
- SystemCallVector, RealMode, Config24MB/Config48MB, __VMBASE*ExceptionHandler
These are a documented hand-asm ceiling for the SDK kernel/boot layer. The
honest path for them is to leave the original bytes as a forced/injected stub
(scaffold), never claiming "matched." MWCC value lies elsewhere (small SDA /
struct-accessor SDK functions, and any pure-C SDK code like DVD/format logic).

**Logged by:** Matcher-MWCC-SDK, 2026-05-30.

## 0x800A3600 BString2::copy(unsigned short*, unsigned int, unsigned int) const (172B)

**Tried:** Natural clamp+copy delegation —
`if (pos > length()) throwrange(); if (count > length()-pos) count = length()-pos;
if (length() != 0) EAmemcpy(dest, data()+pos, count*2); return count;`
with in-class inline `data()` (same wide-char rep pattern as the landed BString2
accessors). **171 of 172 bytes match.** Verified the whole clamp, the double
length() calls, the inline data() guard, the `count*2` byte size (`rlwinm
rD,rS,1,0,30`), and the return all byte-exact.

**Asm shape that didn't reduce:** ONE instruction — the source-pointer add:
```
DOL:   add r4,r4,r9     ; r4=pos*2 (accumulator), r9=data → offset-first
MINE:  add r4,r9,r4     ; base-first (GCC commutative canonicalization)
```
Pure operand-order swap (the exact transform the now-banned `swap_operands`
mutator performed). Tried to flip it from source: `pos + data()`, `&data()[pos]`,
`(unsigned short*)((unsigned int)data() + pos*2)`, `(int)pos` signed index,
`const unsigned short* src = data()+pos;` temp, block-scoped. All emit base-first
`add r4,r9,r4`. GCC normalizes `ptr + int` to ptr-as-op0 regardless of source
spelling; the DOL's offset-first form comes from the original having `pos*2`
pre-computed in the memcpy src arg register (r4) and accumulating data into it.

**Notes / hypotheses:** Generalizes to the whole copy/substr-into-buffer family
in both BString and BString2 (any `memcpy(dest, data()+pos, ...)` where the src
lands directly in the arg register). Next pass: a source shape that forces the
offset to be the live accumulator in the arg reg before the base is added — or
accept as a commutative-`add` canonicalization wall. Do NOT force with
swap_operands/ASMPROC.

**Logged by:** Matcher-SN-2, 2026-05-30.

## 0x802B4358 AptValueWithHash::AptValueWithHash(int, int) (76B)

**Tried:** Natural ctor delegation — `AptValue_ctor(this,type); *(char**)(this+8)=vtable;
AptNativeHash_ctor((char*)this+12, hashSize);` with `extern char vtable[]` + extern
sub-ctors. With `-fno-schedule-insns`, 74 of 76 bytes match (prologue, both bl calls,
the saved-reg dance, vtable store, epilogue all byte-exact).

**Asm shape that didn't reduce:** the 2nd ctor's argument-setup ORDER (one adjacent
swap):
```
DOL:   lis r9 ; mr r4,r29 (arg2=hashSize) ; addi r9,lo ; addi r3,r30,12 (arg1=this+12) ; stw vtable
MINE:  lis r9 ; addi r3,r30,12 (arg1) ; addi r9,lo ; mr r4,r29 (arg2) ; stw vtable
```
DOL sets arg2 (r4) before arg1 (r3); GCC 2.95 sets arg1 before arg2 regardless of
source. Exactly the transform the now-banned `swap_adj` mutator performed (the forced
stub used 3 of them: la/mr, addi/mr, addi/la). Tried: default vs -fno-schedule-insns
vs both -fno-schedule-insns/insns2; vtable store before/after the call; this+12 into a
local; hashSize cast. All keep arg1-before-arg2.

**Notes:** Adjacent arg-setup-order scheduling wall, same class as the BString2::copy
`add`-canonicalization and StringDictByteGetVar register-coloring walls above. Low
leverage (76B niche ctor). Forced stub left untouched as scaffold. Do NOT force with
swap_adj/ASMPROC.

**Logged by:** Matcher-SN-1, 2026-05-30.

## 0x802D0E28 EAHeap::Compact(void) (96B)

**Tried:** Natural lock-guard —
`void* lock = m_field4fc; if(lock) LockEnter(lock); if(m_field4 & 1) DoCompact();
if(lock) LockLeave(lock);` with the struct field at 0x4FC and the `& 1` flag at 0x04.
Logic and call sequence are correct.

**Asm shape that didn't reduce:** the DOL spills the `lock` local to its stack
home and reloads+re-tests it after the call, using only r31 as callee-saved:
```
DOL:   stw  r31,20(r1)       ; only r31 saved
       lwz  r3,0x4fc(r31)    ; lock
       stw  r3,8(r1)         ; spill lock to stack home
       ...DoCompact...
       lwz  r3,8(r1)         ; reload lock, re-test
       cmpwi r3,0 ; beq ...
MINE:  mfcr r12 ; stmw r30,16(r1)   ; saves r30,r31 AND CR
       ...keeps lock in r30, caches (lock!=0) in a callee-saved CR bit...
```
SN ProDG at -O2 keeps `lock` in callee-saved r30 and caches the `lock != 0`
condition in CR across the `DoCompact()` call (hence the extra `mfcr`/CR save);
the DOL instead spilled `lock` to its stack home and re-tested. Re-reading the
field (`if (m_field4fc != 0) LockLeave(m_field4fc)`) is worse (SIZE_MISMATCH).
Same register-allocator class as the 0x8009F570 char-param spill wall — the
"keep-in-reg + cache-CR" vs "spill-to-stack-home + re-test" choice is not
reachable from natural C++ source at -O2.

**Logged by:** Matcher-SN-2, 2026-05-30.

## 0x8026FF94 AptActionInterpreter::valueToObject(AptValue*, AptValueObj*, AptValueObj**) (220B)

**Status:** NEAR-MATCH — 99% (432B/440B), exactly ONE instruction off. The entire
function byte-matches (prologue, the in-range/bit gate, the vtable+0x28 MI-adjustor
Convert() vcall, the shared store block, the tag==1/42 + 0x08000000 decision, the
m_ref/+0x0C name resolution, the getObject call, epilogue) EXCEPT one spot in the
tag-decision tail.

**Asm shape that didn't reduce:** scalar register-coloring. The DOL keeps the
reloaded `flags2` LONG-LIVED in r9 (paying an extra `mr r9,r0`) and burns r0 as the
transient tag scratch; SN ProDG colors the identical C++ the cheaper way (tag in r9,
`flags2` stays in r0, no `mr`):
```
DOL:   lwz r0,0(r31) ; mr r9,r0 ; clrlwi r0,r0,25 ; cmpwi r0,1 ... andis. r0,r9,2048 ... clrlwi r0,r9,25
MINE:  lwz r0,0(r31) ;          ; clrlwi r9,r0,25 ; cmpwi r9,1 ... andis. r9,r0,2048 ... clrlwi r0,r0,25
```
Both are valid; the DOL's choice costs one extra instruction (the `mr`). GCC 2.95's
greedy allocator deterministically parks `flags2` in r0 and refuses to emit the spill-
copy from natural source.

**Tried (11 honest reshapes, no surgery):** control-flow as `||`, `goto`-shared-label,
and explicit double-return (all give the same coloring); inline `(flags2&0x7F)` vs
cached `int tag` (caching drops the DOL's tag recompute → 4 instr short); ternary on
the src selection (×2, no change); reuse the head `flags` across the Convert() call
(GCC drops the reload → 6 instr short); `-fno-thread-jumps` FLAGS (no effect). Plus
Wall-Analyst's three shapes: redundant scalar copy `flags2_copy` (copy-propagated away
→ 432), late reload inside the doConvert block (coaxes flags2 INTO r9 but emits a fresh
`lwz` reload + drops the `mr` → 220B but 2 position diffs), and `register unsigned`
(ignored → 432). The r9-residency and the in-nested-block recompute cannot both be
satisfied: when `flags2` is live into the nested block GCC picks r0; when it is confined
to the outer block GCC will use r9 but then the nested tag needs its own load.

**Notes:** Same scalar-coloring class as 0x802D0E28 (EAHeap::Compact spill-vs-cache)
and 0x8009F570 (char-param spill). Confirmed a legitimate wall by Wall-Analyst after
the 3-shape pass. Forced ASMPROC stub left untouched as scaffold. Clean near-match
source preserved out-of-tree (F:/tmp/vto_nearmatch_SN3.cpp) in case a future
allocator-steering technique lands. Do NOT force with ASMPROC/register-pin.

**Logged by:** Matcher-SN-3, 2026-05-31.

## 0x8009C71C basic_string_ref::basic_string_ref(BString&, unsigned int, unsigned int) (168B)

**Tried:** Full semantics matched (`m_length/m_capacity=count`; if `count!=0`: `capacity=count+1`, `m_data = (count+1!=0) ? MainHeap()->Malloc(count+1,0) : 0`, `memmove(m_data,src.data()+offset,m_length)`, `m_data[m_length]=eos()`; else `m_data=0`; `ref_count=1`). Reshapes: pure ternary, explicit `char*` temp, `char* p=0` init, named local `n=count+1`, two-store branches, ctor init-list, flag matrix (default / `-fno-schedule-insns` / insns2 / both), `-fno-elide-constructors`.

**Asm shape that didn't reduce:** DOL register map: `this=r30, src=r29, offset=r28, count+1=r31` (4 callee-saved, single merged `m_data` store). Pure-ternary clean shape but SN ProDG colors `this=r31 / count+1=r30` (swapped). A pointer temp flips the coloring correct but materializes a 5th callee-saved reg + an `mr` the DOL lacks. ~19 diffs, all the `this/count+1` cascade. Greedy-allocator priority order differs: DOL prioritizes short-live-range `count+1` into r31; my build prioritizes `this` into r31.

**Notes / hypotheses:** Not reachable from honest C++ without a temp the DOL doesn't pay for. Allocator-aware wall — same class as 0x8009F570 (char-param spill-vs-promote). Near-match WIP preserved in `src/wip/allocator_wall/`. Future pass: source shape that makes `count+1` the shorter-lived value so the allocator promotes it over `this`.

**Logged by:** Matcher-SN-4, 2026-05-30.

## 0x8009C9D0 basic_string_ref::basic_string_ref(char, unsigned int) (200B)

**Tried:** Full semantics matched (`throwlength` on `n==-1`; `m_length/m_capacity=n`; if `n!=0`: `capacity=n+1`, alloc, fill-loop `m_data[i]=c` for `i<m_length`, `m_data[m_length]=eos()`; else `m_data=0`; `ref_count=1`). Full flag matrix.

**Asm shape that didn't reduce:** DOL spills `char` param `c` to its stack home (`stb r4,8(r1)` prologue + `lbz` reload in loop) using only 2 callee-saved (`this=r30`, `n→n+1` reuses `r31`). SN ProDG promotes `c` to callee-saved `r29` (3 regs), making the body 1 instruction shorter (196 vs 200B) — SIZE_MISMATCH. Cannot force the param stack-spill from honest C++.

**Notes / hypotheses:** Same allocator-wall class as 0x8009C71C and 0x8009F570 — spill-vs-promote heuristic for short-lived params. Near-match WIP in `src/wip/allocator_wall/`. Future pass: a source shape that convinces the allocator not to callee-save `c`.

**Logged by:** Matcher-SN-4, 2026-05-30.

## 0x8009DAC0 BString::operator=(char) (172B)

**Tried:** Full COW semantics matched (`if ref_count()==1 && reserve()>1: *point()=c; point()[1]=eos(); m_rep->m_length=1; else delete_ref(); m_rep=new basic_string_ref(c,1)`). Flag matrix default / `-fno-schedule-insns` / insns2. `m_length=1` store correctly reuses the `ref_count` register (GCC knows `==1` in-branch). All logic byte-exact.

**Asm shape that didn't reduce:** DOL spills the `char` param to its stack home (`stb r4,8(r1)` prologue) and reloads it (`lbz` + `extsb`) for the rep ctor arg — uses NO callee-saved reg for `c`. SN ProDG promotes `c` to callee-saved `r30`, eliminating the spill store + the `extsb`, making the body 2 instructions shorter (336 vs 344B) — SIZE_MISMATCH. Cannot force the param stack-spill from honest C++.

**Notes / hypotheses:** Identical char-param spill-vs-promote heuristic divergence as `0x8009C9D0`. Any `char`/`wchar` param function with the param live across calls hits this wall class. Near-match WIP in `src/wip/allocator_wall/`.

**Logged by:** Matcher-SN-4, 2026-05-30.

## 0x800A1EB4 BString2::operator=(unsigned short) (168B)

**Tried:** Full COW semantics matched (wchar sibling of `0x8009DAC0`: `if ref_count()==1 && reserve()>1: *point()=c; point()[1]=eos(); m_rep->m_length=1; else delete_ref(); m_rep=new basic_string_ref2(c,1)`). `m_length=1` reuses `ref_count` reg. Full flag matrix.

**Asm shape that didn't reduce:** DOL spills the `wchar` param to its stack home (`sth r4,8(r1)`, 32-byte frame) and reloads it (`lhz`) at each use. SN ProDG promotes it to callee-saved `r30` (24-byte frame, no spill). Same byte size but the spill-vs-promote register/frame divergence makes every `c`-access + frame setup differ — MISMATCH throughout. Cannot force the stack-spill from honest C++.

**Notes / hypotheses:** Exact `wchar` analogue of `0x8009DAC0` char-param spill wall. Confirms the rule: any `char`/`wchar` value-param live across calls hits spill-vs-promote. 4th entry in this allocator-wall family. Near-match WIP in `src/wip/allocator_wall/`.

**Logged by:** Matcher-SN-4, 2026-05-30.

## 0x800E1540 cXObjectImpl::GetFrontFaceDirection (84B)

**Tried:** Full semantics + shape matched. Single-blrl vcall getter: `z = m_x(0x8C)->m_y(0x50)->VcallAt20()` (FaceY vtable@0, slot20/offset160, MS-ABI 8-byte entries via 19 filler pure-virtuals); `if(!z) return 0; return z->m_w(0x38)->m_dir(short@0x7A)`. Branch layout, tail, vtable-slot recipe, lha/add this-adjust all byte-exact. Reshapes: `if(z)`/`if(!z)` polarity, 1 & 2 intermediate locals, inline helper `GetY(m_x)`, `register` qualifiers, deref-syntax swap `(*(*m_x).m_y)`, with/without `-fno-schedule-insns`.

**Asm shape that didn't reduce:** Only the 3-deep ptr-chain prologue register coloring differs. DOL: `lwz r4,140(r3)[m_x]; lwz r11,80(r4)[m_y]; lwz r9,0(r11)[vt]; ... add r3,r11,r3`. SN ProDG: `lwz r9,140(r3); lwz r10,80(r9); lwz r11,0(r10); ... add r3,r10,r3`. DOL starts the temp chain at the low volatile r4; GCC 2.95/SN greedily starts at r9 (→r9/r10/r11). All three are volatile regs — pure allocation-order divergence. Forced stub used the banned `ASMPROC_region_gpr_relabel rename="9:4,10:11,11:9"` for exactly this.

**Notes / hypotheses:** Register-coloring wall. The ternary-intermediate anticoloring technique ([[feedback_ternary_intermediate_anticoloring]]) does not structurally apply — there is no conditional intermediate to leverage, and adding a live value to perturb the allocator would add instructions (breaking the byte size). No natural C++ shape reliably forces GCC 2.95's starting volatile register. Second-opinioned with Wall-Analyst (concurred: legitimate volatile-register-choice wall). Likely representative of the broader cXObjectImpl/ObjectModuleImpl MI-vcall coloring-wall class.

**Logged by:** Matcher-SN-5, 2026-05-31.

## 0x80095E0C StateMachine::GetCurStateId (28B)

**Tried:** Natural getter — `if (m_curState) return m_curState->GetId(); return -1;` and equivalents. Logic is correct.

**Asm shape that didn't reduce:** GCC static-branch-prediction layout mismatch. DOL emits a `bne`-skip form (falls through to the non-null path, branches over the `li -1` return); SN ProDG emits `beq`-to-end (falls through to the `li -1` null path, branches to the non-null body). Tried `if(!m_curState) return -1; return m_curState->GetId();` and `goto` forms — GCC 2.95 consistently picks the `beq`-to-end layout regardless of source polarity.

**Notes / hypotheses:** Static branch-prediction layout wall — GCC 2.95 prefers the null/false branch as fall-through for pointer-null guards. Not reachable from honest C++ without ASMPROC. Left as inject-forced stub (minor, 28B). If a future technique for controlling fall-through layout emerges (beyond `goto`), retry here.

**Logged by:** Matcher-SN-5, 2026-05-31.

## 0x80190DF4 InteractionHelper::GetNext(IHRecord*) (24B)

**Tried:** Full semantics matched: `n = rec->m_next(0x4); return n ? n : rec->m_alt(0xC)`. if-form and ternary, flag matrix default / -fno-schedule-insns / insns2.

**Asm shape that didn't reduce:** DOL holds m_next in scratch r0 and copies it to r3 before the test: `lwz r0,4(r4); mr r3,r0; cmpwi r0,0; bnelr; lwz r3,12(r4); blr` (24B). GCC 2.95/SN loads directly into the return reg r3 and tests r3 (`lwz r3,4(r4); cmpwi r3,0; bne...`), eliminating the `mr r3,r0` → 20B, SIZE_MISMATCH. No natural C++ produces the load-to-scratch-then-mr form; forced stub injected it via nop_before + replace_insn.

**Notes / hypotheses:** Scratch-register coloring wall (value evicted to r0 then mr'd to r3). Same class as the GetAllocByteCount r9-scratch case but there a `this`-live ternary forced it; here there is no second live value to leverage. Log + move on.

**Logged by:** Matcher-SN-5, 2026-05-31.

## 0x80224048 InteractorModule::WallManipulator::GetAffectedWallHeight (24B)

**Tried:** Full semantics matched: `return (m_flags(0xC4) & 0x100) ? gHi : gLo` (two SDA float consts). Ternary, if-early-return, pre-load-local-then-if, flag matrix.

**Asm shape that didn't reduce:** DOL speculatively loads gHi, then returns early on the flag: `lwz r0,0xC4(3); andi. r9,r0,256; lfs f1,gHi(13); bnelr; lfs f1,gLo(13); blr`. GCC 2.95/SN predicts the bit-test-true as unlikely and branches over it instead (`andi.; bne L; lfs gLo; blr; L: lfs gHi; blr`) — gLo as fall-through, no speculative gHi load, no bnelr. Forced stub injected the DOL form via inject_before.

**Notes / hypotheses:** Branch-prediction/speculative-load layout wall (same class as GetCurStateId 0x80095E0C). GCC's static predictor lays out the unlikely branch as the taken path; DOL's build speculatively loaded the "true" const and used bnelr. Not forceable from honest C++.

**Logged by:** Matcher-SN-5, 2026-05-31.

## 0x802D0AA4 EAHeap::Malloc(unsigned int, int) (204B) — and siblings Calloc 0x802D0C84, MallocAligned 0x802D0B70

**Tried:** Full recursive heap-walk logic matched (size-guard; `if(this!=DebugHeap()) AttemptPoolAlloc(size,8)`; `MallocFromHeap`; then 2-level sub-heap recursion `m_subHeapA@0x52c` / `m_subHeapB@0x530`). Reshapes: separate locals, single result var, `goto`-single-return, `register void* result`, full flag matrix. Wall-Analyst consulted (3 shapes).

**Asm shape that didn't reduce:** DOL threads the single result var through `r0` with a redundant copy at each exit (`mr. r0,r3; mr r3,r0; bne`) — result's home reg = `r0`, copied to `r3` for return. SN ProDG copy-propagates result directly into `r3` (`mr. r3,r3; bne`), eliminating 3 `mr` instructions → 192B vs 204B — SIZE_MISMATCH (12B / 3 instructions short).

**Notes / hypotheses:** Copy-propagation wall — the original 2005 SN ProDG build missed propagating `result`→`r3` (a known GCC-2.x quirk with early-return/merge control flow); our verify SN ProDG performs the propagation. NOT reachable by blocking copy-prop from honest C++ (`goto` / `register` both fail). Calloc + MallocAligned are exact byte-siblings (same `r0`-threading) — one fix unlocks all 3. Logic fully solved. Future pass: try a different SN ProDG point-version, or revisit if the verify compiler changes. WIPs in `src/wip/eaheap_near/`.

**Logged by:** Matcher-SN-4, 2026-05-31.

## 0x80364ED0 ERenderSurface::SetSize(int,int,int) (24B)

**Tried:** Full semantics matched: `m_p(0x18)=p; m_w(0x0)=w; m_h(0x4)=h; return 1`. Plain member stores and `volatile int*` stores (volatile to pin store order), flag matrix default / -fno-schedule-insns / insns2.

**Asm shape that didn't reduce:** DOL aliases `this` to r9 and materializes the return value mid-body: `mr r9,r3; stw r6,24(r9); li r3,1; stw r4,0(r9); stw r5,4(r9); blr` (24B). The `li r3,1` lands BETWEEN the first and second store, which forces `this` out of r3 into r9. GCC 2.95/SN either (a) keeps `this` in r3 and emits `li r3,1` LAST (no mr, 20B) under volatile/-fno-schedule-insns, or (b) reorders the stores (h before p) under default scheduling. No flag/source combo yields the mr + source store-order + mid-body li together. Forced stub used this_alias_rN + swap_adj.

**Notes / hypotheses:** Return-value-scheduling + this-alias wall. The DOL build scheduled the return-constant load early; GCC won't without the banned this_alias/swap_adj. Same family as the op_index sret-mr case but there default scheduling produced the mr naturally; here it costs the store order.

**Logged by:** Matcher-SN-5, 2026-05-31.

## 0x80317A28 ERFont::SetColor(float) (24B)

**Tried:** Full semantics matched: `m_color[0..3] = c` stored in DOL order [0],[3],[1],[2]. Direct array stores and `float* base = m_color;` rebase-pointer form, flag matrix.

**Asm shape that didn't reduce:** DOL stores color[0] via the full this+88 displacement, THEN rebases `addi r3,r3,88` and stores the other three at small displacements: `stfs f1,88(3); addi r3,r3,88; stfs f1,12(3); stfs f1,4(3); stfs f1,8(3)` (24B). GCC 2.95/SN stores all four via full displacements off r3 (`stfs 88,100,92,96`) with no rebase → 20B, SIZE_MISMATCH. Forced stub injected the addi-rebase via swap_adj + force_reg.

**Notes / hypotheses:** Address-rebase scheduling wall — DOL emitted an `addi` base-adjust to shrink displacements; GCC keeps the wide displacements. Not forceable from honest C++ (a `float* base = m_color;` local rebases ALL four stores, not three-after-one).

**Logged by:** Matcher-SN-5, 2026-05-31.

## 0x8036049C ERTQuantize4D::IndexToNode (32B) + 0x803604BC ERTQuantize4D::NodeToIndex (44B)

**Tried:** Full logic matched for both. `IndexToNode`: `idx ? (char*)m_nodes + idx*72 : 0`. `NodeToIndex`: `node ? node - m_nodes : 0`. All operand-reorder, uint-cast base, product-into-local, `register` temp variants. Full flag matrix.

**Asm shape that didn't reduce:** Pure r3-reuse register-coloring wall (same class as cXObjectImpl::GetFrontFaceDirection 0x800E1540). `IndexToNode`: DOL `mulli r9,r4,72; lwz r0,4104(r3); add r3,r0,r9` (product→r9, base→r0); GCC 2.95 `mulli r0; lwz r3,4104(r3); add r3,r3,r0` (greedily reuses r3=this/return for base). `NodeToIndex`: DOL works entirely in r9 (`lwz r9; subf r9; mullw r9,magic; rlwinm r3,r9`); GCC works entirely in r3. Old forced stubs used `ASMPROC_replace_insn` for r3→r9/r0 relabels (banned).

**Notes / hypotheses:** No natural C++ shape reliably forces GCC 2.95 to start the volatile-register chain at r9 instead of r3. Wall-Analyst concurs. Do NOT force with ASMPROC.

**Logged by:** Matcher-SN-6, 2026-05-31.

## 0x80320A00 ERShader::GetModifiableColor(unsigned) (48B) — and palette-fallback-redundant-li family

**Tried:** Full logic matched: `p = this->m_14(palette); if(!p){ obj=this->m_18(base); p=0; if(obj) p=obj->m_14; } return p->colors[0x40+idx*4]`. 11 of 12 instructions match. `if`/`else` explicit `p=0` and ternary `m_base?m_base->m_14:0` — GCC drops the `li` both ways.

**Asm shape that didn't reduce:** DOL emits a redundant `li r9,0` at offset 0x10 (the fallback-zero assignment) even though r9 is provably already 0 from the entry `cmpwi r9,0` check. GCC 2.95 value-tracks r9==0 and eliminates the dead store → 44B vs 48B SIZE_MISMATCH. No natural C++ reproduces a provably-dead store. Old forced stub injected the whole body via `ASMPROC_inject_before` (banned).

**Family:** SN ProDG is less aggressive than devkitPPC GCC 2.95 at dead-`li` elimination. Predicted same-idiom walls (analyzed, not attempt-burned): `0x8032086C IsMultiTextureShader` (72B), `0x80320708 GetSupportDecal` (72B) — identical `m_14`/`m_18` fallback chain + redundant `li`. Sibling of the r3-reuse coloring family — both are GCC-more-aggressive-than-SN-ProDG compiler-difference walls.

**Notes / hypotheses:** Recognize-and-skip the whole palette-fallback family; only a whole-body ASMPROC inject can force the dead `li`, which is banned. Do NOT force.

**Logged by:** Matcher-SN-6, 2026-05-31.

## 0x8037520C C_MTX44RotRad (112B) + 0x80372CE4 C_MTXRotRad (112B) — MWCC addi-vs-mr + redundant-fmr round-trip

**Tried:** Full logic matched. Natural SDK source: `sinA = sinf(rad); cosA = cosf(rad); C_MTX(44)RotTrig(m, axis, sinA, cosA);` with `sinf/cosf/RotTrig` declared extern. All 3 bl relocations resolve correctly; matrix-builder delegate is correct.

**Asm shape that didn't reduce (108B obj vs 112B DOL, off by one instr):** Two coupled codegen-form diffs at our fixed MWCC config:
1. **addi-vs-mr**: our MWCC emits `addi r30,r3,0` / `addi r31,r4,0` to stash the `m`/`axis` args in callee-saved regs; the DOL emits `mr r30,r3` / `mr r31,r4` (`or rD,rS,rS`). Same diff parked for C_MTXConcat 0x8037203C.
2. **redundant-fmr round-trip**: the DOL spills `rad` to f31 then RELOADS it with a redundant `fmr f1,f31` immediately before `bl sinf` (f1 already held rad). Our MWCC value-tracks f1==rad and elides the reload → one fewer instruction → the 4B size shortfall.

**Notes / hypotheses:** Both are compiler-internal choices (register-copy form + redundant-spill-reload), not source-controllable — the DOL was built with a slightly less-aggressive MWCC point release than verify_mwcc.py's GC-1.2.5n. Same root cause as the parked FRAME C_MTXConcat near-miss. The two RotRad funcs are structurally identical, so both wall together; do NOT chase (only post-compile asm surgery could force the mr/redundant-fmr, which is banned).

**Logged by:** Matcher-MWCC-SDK-3, 2026-05-31.

## 0x803738C0 C_MTXLightFrustum (148B) — MWCC stack-param-load scheduler tie

**Tried:** Full logic matched (all 19 fp ops + 16 stores byte-correct in isolation). Texture-projection frustum: `m[0][0]=scaleS*(2*n*tmp); m[0][2]=scaleS*((r+l)*tmp)-transS; m[1][1]=scaleT*(2*n*tmp); m[1][2]=scaleT*((t+b)*tmp)-transT; m[2][2]=-1` with `tmp=1/(r-l)` then `1/(t-b)`. Operand orders all derived from the DOL and confirmed correct (the same recipe landed C_MTXLightOrtho 0x80373A20 clean).

**Asm shape that didn't reduce:** transT is the 9th float arg → passed on the stack (`lfs f12,56(r1)`). The DOL hoists that stack-param load to slot 2 (immediately after `stwu`); our verify_mwcc.py GC-1.2.5n schedules it ~6 instructions later, which cascades a global ~1-slot shift across the whole body (20 mismatched offsets, all same-opcode reorderings — no instruction-count diff). Tried forcing the early load via a `float tt = transT;` local at function top → MWCC elided the copy, no change.

**Notes / hypotheses:** Pure list-scheduler tie on incoming-stack-FP-argument placement — not controllable from honest C++ at our fixed flags. The leaf siblings with ≤8 float args (Ortho/Frustum/Perspective/LightOrtho) all matched first-try; only the >8-arg Light variants spill to the stack and hit this. Predicted same-class wall (not attempt-burned): C_MTXLightPerspective 0x80373954 (204B, also takes scaleS/scaleT/transS/transT → stack spill). Do NOT force (only post-compile reorder could fix the schedule, which is banned).

**Logged by:** Matcher-MWCC-SDK-3, 2026-05-31.
