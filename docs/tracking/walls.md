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

**Retried (Pi/GPT-5.5 + SN-VERSION 3.8.1/3.7/3.5, 2026-06-04):** Reconstructed the natural loop and tested default plus all three older SN point-versions. All emitted the same promoted-char shape (`c` in r29, save r29/r30/r31) rather than the DOL stack-home `stb r4,8(r1)` / `lbz` reload with only r30/r31 saved. Wall remains.

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

**Retried (Pi/GPT-5.5 + SN-VERSION 3.8.1/3.7/3.5, 2026-06-04):** Reconstructed the natural lock-guard body and tested default plus all three older SN point-versions. All emitted the same keep-lock-in-r30 + cached-CR shape (`mfcr`, r30/r31 save, `beq cr4`) rather than the DOL's stack-home spill/reload with only r31 saved. Wall remains.

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

**Retried (Pi/GPT-5.5 + SN-VERSION 3.8.1/3.7/3.5, 2026-06-04):** Re-ran the preserved near-match WIP under default and all three older SN point-versions. All emitted the same coloring as default (`this` in r31, `count+1` in r30) rather than the DOL's `this` r30 / `count+1` r31 allocation. Wall remains.

## 0x8009C9D0 basic_string_ref::basic_string_ref(char, unsigned int) (200B)

**Tried:** Full semantics matched (`throwlength` on `n==-1`; `m_length/m_capacity=n`; if `n!=0`: `capacity=n+1`, alloc, fill-loop `m_data[i]=c` for `i<m_length`, `m_data[m_length]=eos()`; else `m_data=0`; `ref_count=1`). Full flag matrix.

**Asm shape that didn't reduce:** DOL spills `char` param `c` to its stack home (`stb r4,8(r1)` prologue + `lbz` reload in loop) using only 2 callee-saved (`this=r30`, `n→n+1` reuses `r31`). SN ProDG promotes `c` to callee-saved `r29` (3 regs), making the body 1 instruction shorter (196 vs 200B) — SIZE_MISMATCH. Cannot force the param stack-spill from honest C++.

**Notes / hypotheses:** Same allocator-wall class as 0x8009C71C and 0x8009F570 — spill-vs-promote heuristic for short-lived params. Near-match WIP in `src/wip/allocator_wall/`. Future pass: a source shape that convinces the allocator not to callee-save `c`.

**Logged by:** Matcher-SN-4, 2026-05-30.

**Retried (Pi/GPT-5.5 + SN-VERSION 3.8.1/3.7/3.5, 2026-06-04):** Re-ran the preserved near-match WIP under default and all three older SN point-versions. All emitted the same 196B promoted-char shape (`c` in r29, 24B frame) and did not reproduce the DOL's stack-home `stb`/`lbz` char spill. Wall remains.

## 0x8009DAC0 BString::operator=(char) (172B)

**Tried:** Full COW semantics matched (`if ref_count()==1 && reserve()>1: *point()=c; point()[1]=eos(); m_rep->m_length=1; else delete_ref(); m_rep=new basic_string_ref(c,1)`). Flag matrix default / `-fno-schedule-insns` / insns2. `m_length=1` store correctly reuses the `ref_count` register (GCC knows `==1` in-branch). All logic byte-exact.

**Asm shape that didn't reduce:** DOL spills the `char` param to its stack home (`stb r4,8(r1)` prologue) and reloads it (`lbz` + `extsb`) for the rep ctor arg — uses NO callee-saved reg for `c`. SN ProDG promotes `c` to callee-saved `r30`, eliminating the spill store + the `extsb`, making the body 2 instructions shorter (336 vs 344B) — SIZE_MISMATCH. Cannot force the param stack-spill from honest C++.

**Notes / hypotheses:** Identical char-param spill-vs-promote heuristic divergence as `0x8009C9D0`. Any `char`/`wchar` param function with the param live across calls hits this wall class. Near-match WIP in `src/wip/allocator_wall/`.

**Logged by:** Matcher-SN-4, 2026-05-30.

**Retried (Pi/GPT-5.5 + SN-VERSION 3.8.1/3.7/3.5, 2026-06-04):** Re-ran the preserved near-match WIP under default and all three older SN point-versions. All emitted the same 336B promoted-char shape (`c` in r30, 24B frame), still missing the DOL stack-home `stb`/reload/extsb and 32B frame. Wall remains.

## 0x800A1EB4 BString2::operator=(unsigned short) (168B)

**Tried:** Full COW semantics matched (wchar sibling of `0x8009DAC0`: `if ref_count()==1 && reserve()>1: *point()=c; point()[1]=eos(); m_rep->m_length=1; else delete_ref(); m_rep=new basic_string_ref2(c,1)`). `m_length=1` reuses `ref_count` reg. Full flag matrix.

**Asm shape that didn't reduce:** DOL spills the `wchar` param to its stack home (`sth r4,8(r1)`, 32-byte frame) and reloads it (`lhz`) at each use. SN ProDG promotes it to callee-saved `r30` (24-byte frame, no spill). Same byte size but the spill-vs-promote register/frame divergence makes every `c`-access + frame setup differ — MISMATCH throughout. Cannot force the stack-spill from honest C++.

**Notes / hypotheses:** Exact `wchar` analogue of `0x8009DAC0` char-param spill wall. Confirms the rule: any `char`/`wchar` value-param live across calls hits spill-vs-promote. 4th entry in this allocator-wall family. Near-match WIP in `src/wip/allocator_wall/`.

**Logged by:** Matcher-SN-4, 2026-05-30.

**Retried (Pi/GPT-5.5 + SN-VERSION 3.8.1/3.7/3.5, 2026-06-04):** Re-ran the preserved near-match WIP under default and all three older SN point-versions. All emitted the same promoted-wchar 24B-frame shape; none reproduced the DOL 32B frame with `sth r4,8(r1)` / stack reload. Wall remains.

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

**Retried (Pi/GPT-5.5 + SN-VERSION 3.8.1/3.7/3.5, 2026-06-04):** Took solved WIP `src/wip/eaheap_near/match_0x802D0AA4_EAHeap__Malloc_unsigned.cpp`, prepended each SN-VERSION marker, and ran `verify_match.sh --strict` at 0x802D0AA4/204. All three older point-versions produced the same 192B object shape as default for this body (still 12B short; same copy-prop/branch-tail layout), so the EAHeap copy-prop family remains walled.

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

**Retried (Pi/GPT-5.5 + SN-VERSION 3.8.1/3.7/3.5, 2026-06-04):** Rebuilt the natural palette-fallback body under default and SN-VERSION 3.8.1/3.7/3.5. All emitted the same 44B object and continued to eliminate the redundant `li r9,0` after loading `m_base`; no point-version tested reproduces the DOL's 48B dead-li shape. Wall remains.

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

## 0x80373954 C_MTXLightPerspective (204B) — MWCC prologue save/move grouping under high FPR pressure

**Tried:** Full logic matched. Texture-projection perspective: `angle=fovY*0.5; angle*=PI/180; cot=1/tanf(angle); m[0][0]=scaleS*(cot/aspect); m[0][2]=-transS; m[1][1]=cot*scaleT; m[1][2]=-transT; m[2][2]=-1`. All operand orders + the tanf bl + `mr r31,r3` correct (same recipe landed C_MTXPerspective 0x803741D0 clean). 6 float args (no stack spill).

**Asm shape that didn't reduce:** five values (aspect/scaleS/scaleT/transS/transT) must survive the `bl tanf`, so MWCC saves f27–f31. The DOL groups the prologue as *all 5 stfd saves + stw r31, then all 6 fmr/mr param-moves*; our verify_mwcc.py GC-1.2.5n interleaves stfd with fmr, which cascades the deg-to-rad constant into a different FPR (DOL `fmuls f1,f2,f1` vs ours `fmuls f1,f7,f1`) and shifts ~10 prologue offsets.

**Notes / hypotheses:** Pure prologue instruction-grouping + register-allocation difference under 5-callee-saved-FPR pressure — not controllable from honest C++. Same root class as C_MTX44RotRad 0x8037520C (callee-saved frame scheduling). The lower-pressure sibling C_MTXPerspective (3 saved FPRs) matched first-try; this one just crosses the pressure threshold where our MWCC's prologue scheduler diverges from the DOL's. Do NOT force.

**Logged by:** Matcher-MWCC-SDK-3, 2026-05-31.

## 0x80373430 C_MTXQuat (240B) — dense-leaf scheduler tie

**Tried:** Full logic matched. Canonical quaternion→3x4: `s = 2.0f/(x²+y²+z²+w²)` (no s!=0 guard — DOL has no branch), then xs/ys/zs, the 12 products (wx,wy,wz,xx,xy,xz,yy,yz,zz), then the 9 rotation entries `m[0][0]=1-(yy+zz)`, `m[0][1]=xy-wz`, etc. The sum/division/xs/ys/zs prefix (first ~22 instrs) matches byte-perfect; all operand orders correct.

**Asm shape that didn't reduce:** the dense tail (12 independent fmuls + 9 fadds/fsubs + 12 stfs) is a list-scheduler tie. The DOL interleaves the diagonal-square products (computed z,y,x order), the cross products, and the stores in one specific order; our verify_mwcc.py GC-1.2.5n picks a different valid interleaving (~24 same-opcode reordered offsets, no instruction-count diff). Tried two product-grouping source orders (w-first, diagonal-first) — neither reproduces the DOL interleave; the diagonal-first reorder also broke the previously-matching prefix.

**Notes / hypotheses:** Too many independent ops with equal scheduler priority → the tie is not resolvable from honest C++ at fixed flags. Same dense-leaf class as the big matrix ops. Do NOT force. (The smaller projection-matrix builders match because they have a forced dependency chain per row; Quat's products are mutually independent, so the scheduler has freedom the DOL's compiler resolved differently.)

**Logged by:** Matcher-MWCC-SDK-3, 2026-05-31.

## 0x80372DC4 C_MTXRotTrig (260B) — MWCC branch-to-return peephole (shared-epilogue) + switch rotation family

**Tried:** Full logic matched. Canonical `switch(axis){ case 'x': case 'X': <X-rot stores>; break; case 'y': case 'Y': ...; case 'z': case 'Z': ...; }` with the standard X/Y/Z 3x4 rotation matrices (consts 1.0f/0.0f, `-sinA` via fneg). ALL three case bodies + the binary-search dispatch tree (cmpwi 120/89/88/91/122…) byte-match exactly. Tried both C++ and `// LANG: c` — identical result. Size matches (260B, no count diff).

**Asm shape that didn't reduce:** 5 branch encodings only. The DOL routes every `break` and every dispatch-default to a SHARED epilogue `blr` at 0x80372ec4 (`b 0x80372ec4` / `bge 0x80372ec4`); our verify_mwcc.py GC-1.2.5n applies a branch-to-return peephole and emits the return in place (`blr` / `bgelr`) at each site instead of branching to the shared blr. Same size, same opcodes elsewhere — only `b end→blr` and `bge end→bgelr` differ.

**Notes / hypotheses:** Compiler-version peephole difference — the DOL's MWCC point-release did NOT fold branch-to-return; ours does. Not controllable from honest C++ at fixed flags (the function is frameless/void, so there's no multi-instruction epilogue to block the peephole). **FAMILY WALL** — same shape predicted (not attempt-burned) for the other switch-on-axis rotation builders: C_MTXRotAxisRad's trig-dispatch tail, C_MTX44RotTrig 0x803752EC, C_MTX44RotAxisRad 0x803754DC. Do NOT force.

**Logged by:** Matcher-MWCC-SDK-3, 2026-05-31.

## 0x8025AE60 C_VECReflect (212B) — MWCC addi-vs-mr param-save (FRAME) wall

**Tried:** Full logic matched (212B, NO size diff in the natural form). Canonical: build `uVec = -src`, `C_VECNormalize(&uVec,&uVec)`, `C_VECNormalize(normal,&nVec)`, `dot=C_VECDotProduct(&uVec,&nVec)`, `dst[i]=2*nVec[i]*dot-uVec[i]`, `C_VECNormalize(dst,dst)`. All 3 masked bl calls, the float math, the local-vector stack offsets (uVec@32, nVec@20) and the 2.0f const all correct.

**Asm shape that didn't reduce:** exactly 5 register-copy encodings. Our verify_mwcc.py GC-1.2.5n emits `addi rD,rS,0` where the DOL emits `mr rD,rS` (`or rD,rS,rS`) for the param→callee-saved saves (`r30=normal`, `r31=dst`) and the call-arg setups (`r4=r3`, `r3=r30`), plus the resulting prologue `stw r30` shifts one slot. Same addi-vs-mr class parked for C_MTXConcat 0x8037203C and C_MTX44RotRad 0x8037520C. Tried explicit pointer-local form (`Vec* u=&uVec`) to coax mr → MWCC spilled the pointers to stack instead (236B, worse).

**Notes / hypotheses:** MWCC's register-copy emission (`addi rD,rS,0` vs `or rD,rS,rS`) is compiler-internal and context-dependent — C_MTXPerspective's single `mr r31,r3` param-save DID match, but multi-copy FRAME prologues consistently fall to addi here. Not controllable from honest C++. **CLASS WALL** for the remaining FRAME C_VEC*/C_MTX* funcs with several param-saves (the sqrt cluster, MultVecArray, Concat/Inverse). Do NOT force.

**Logged by:** Matcher-MWCC-SDK-3, 2026-05-31.

## 0x8037E270 DSPSendMailToDSP (20B) — MWCC lis-r4/srwi instruction order

**Tried:** Constant-address (`*(volatile u16*)0xCC005000 = mail >> 16; *(volatile u16*)0xCC005002 = mail;`), pointer-to-0xCC005000 form, local base variable (`unsigned int base = 0xCC000000; base[0x2800]=...`), extern-array form (produces 24B, wrong size). All source shapes produce srwi before lis r4 in MWCC output. Note: FLAGS are silently ignored for MWCC files (verify_mwcc.py has no FLAGS support); -fno-schedule-insns/-fno-schedule-insns2 were tried but have no effect.

**Asm shape that didn't reduce:**
```
DOL:   lis r4,-13312    ← address first
       srwi r0,r3,16   ← then shift
       sth r0,0x5000(r4)
       sth r3,0x5002(r4)
MWCC:  srwi r0,r3,16   ← shift first
       lis r4,-13312    ← then address
       sth r0,0x5000(r4)
       sth r3,0x5002(r4)
```
Byte-identical except first two instructions swapped. All stores and result correct.

**Notes / hypotheses:** MWCC 1.2.5n scheduler computes dependent values (srwi) before address materializations (lis) for HW-register setters. The DOL's lis-first ordering suggests either a different 1.2.5n build or a source form that forced the address into a register before the computation. The extern-array form fixes the ordering for reads (DSPReadCPUToDSPMbox matched) but produces 24B for writes, so can't be used for the 20B store form. **CLASS WALL** for constant-address HW-register setters with a leading srwi/rlwinm computation.

**Logged by:** Matcher-MWCC-SDK, 2026-06-04.

## 0x802DC4E0 EA::Allocator::GeneralAllocator::GetUsableSize(void*) const (64B)

**Tried:** Logic fully solved (chunk = p-8; size = mnSize & ~7; if (mnSize&2) return
size-8; next = chunk+size; if (next->mnSize&1) return size-4; return 0; with the
p==0 and bit0-clear paths sharing one `li r3,0`). 7 source forms x flag sweep:
`return size-4` form, `size-=4; return size` form, explicit-bool form, fallthrough
`else` block (Wall-Analyst Reshape 1), `else if` chain. Flags: default,
-fno-schedule-insns, -fno-schedule-insns2, -fno-peephole, -fno-delayed-branch (all
accepted, none reduced). -fno-reorder-blocks REJECTED by SN ProDG 3.9.3.

**Asm shape that didn't reduce:** TWO coupled GCC2.95 divergences.
(1) **Jump layout:** DOL keeps BOTH early-returns inline —
`andi. 2; beq L1; addi -8; blr; L1: ...`. GCC2.95 consistently out-of-lines
whichever early-return is the `if`-THEN block (here `return size-8`), emitting
`bne <out-of-line>`; only the `else`/fallthrough stays inline. The two source forms
trade off WHICH block is out-of-lined; never both inline.
(2) **Load-delay fill:** in L1 the DOL emits `lwz; andi. 1; addi -4; bnelr`; GCC2.95
emits `lwz; addi -4; andi. 1; bnelr` (sinks the independent `addi` into the load-use
slot) even with -fno-schedule-insns/insns2/-fno-delayed-branch/-fno-peephole — so it
is a combine/RTL-emission choice, not a controllable pass.

**Notes / hypotheses:** GCC2.95 jump-layout + load-delay scheduling wall — a genuine
compiler-point-version difference. NOTE: installed SN ProDG 3.8.1/3.7/3.5 are BYTE-IDENTICAL
to the 3.9.3 default (confirmed Pi + Opus-1, sn-version-calibration), so `// SN-VERSION`
CANNOT resolve this — do NOT burn a SN-VERSION attempt. Awaits a real period-correct SN
compiler (the 2005 build's exact point release) or objdiff-tier diffing. Logic 100% solved.
Second-opinioned by Wall-Analyst (3 reshapes, concurred legitimate).

**Logged by:** Matcher-Opus-2, 2026-06-04.

## 0x802D9030 EA::Allocator::GeneralAllocator::GetLargeBinIndexFromChunkSize(unsigned int) (104B)

**Tried:** Logic fully solved — 5-tier descending shift/threshold cascade
(`t = size>>6; if (t<=32) return t+56;` ... final tier preloads 126 default + returns
t+124 if t<=2). Natural cascade source, with default and -fno-schedule-insns.

**Asm shape that didn't reduce:** GCC2.95 3.9.3 optimizes the cascade TIGHTER than the
DOL. DOL per tier: `srwi r9,r3,N; cmplwi r9,T; bgt Lnext; addi r3,r9,K; blr` (size stays
in r3, shift in r9, 3 insns, branch over an inline return). Our SN ProDG precomputes the
result and uses a conditional-return-via-lr: `mr r0,r3` (save size) then per tier
`srwi r3,r0,N; cmplwi r3,T; addi r3,r3,K; blelr` (2 insns/tier, size spilled to r0).
The `blelr` form is shorter -> SIZE_MISMATCH (and different coloring: r0 vs r9 for size).

**Notes / hypotheses:** Compiler-point-version peephole/cost-model difference — 3.9.3
emits the `addi;blelr` fused form; the 2005 build emitted the looser `bgt;addi;blr`.
Not source-controllable on 3.9.3. NOTE: installed SN ProDG 3.8.1/3.7/3.5 are BYTE-IDENTICAL
to 3.9.3 (sn-version-calibration), so `// SN-VERSION` will NOT help — awaits a real
period-correct SN compiler or objdiff. Logic 100% solved.

**Logged by:** Matcher-Opus-2, 2026-06-04.

## 0x80280FBC AptActionInterpreter::_FunctionAptActionInstanceOf (560B)

**Tried:** Full clean structural C++ decode (the InstanceOf opcode: pop 2 operands,
call isObjectOfType, alloc/reuse a boolean GC-box, GC-bookkeep, cleanup-dispatch
slot1/slot2 with method-ids 211/220, push result; plus a degenerate top<=1 path).
Decode is **100% correct** — compiles to a ~96% byte match (only ~5 instr / 20B off
on 560B). Reshapes applied: Wall-Analyst B1 (split `newtop=top+1; newtop-=top;`) —
**worked**, fixed the callee-saved-hoist so prologue matches (stmw r26 / frame 32).
vptr-offset bug fixed (declare 2 head words + virtuals only, access m_payload@0xC
manually so SN keeps vptr@0x08). SN-VERSION 3.8.1 / 3.7 / 3.5 all byte-identical to
3.9.3 (no-op). Operand-read reshapes A1 (char*+byte offset) and A3 (&base[idx]
intermediates) did not force the DOL's two-base form.

**Asm shape that didn't reduce:**
- (A) operand read — DOL materializes TWO independent scaled bases:
  `addi r9,r29,-1; slwi r9,r9,2; slwi r11,r29,2; add r9,r9,data; add r11,r11,data; lwz r3,-4(r11); lwz r4,-4(r9)`
  GCC-3.9.3 CSEs ONE base: `slwi 9,top,2; add 9,9,data; lwz 3,-4(9); lwz 4,-8(9)` (3 instr shorter).
- (B/coloring) DOL `this`→r31, origtop→r29; GCC `this`→r29 (pervasive reg renumber, likely downstream of A).

**Notes / hypotheses:** objdiff / Lane-B class — strength-reduction/addressing-mode
CSE difference between the 2005 SN ProDG point-version and the installed 3.5/3.7/3.8.1/3.9.3.
No installed SN version differs, and GCC source shapes don't override the array-base CSE
at -O2. **CastOp 0x802811EC (568B) is the SAME wall** (near-identical opcode handler) —
do NOT solo-grind; both await a real instruction-level objdiff pass or a not-installed
SN point-version. Full decode + best attempt: memory project_s20_opus1_isobjectoftype +
F:\tmp\opus1_280fbc.cpp.

**Logged by:** Matcher-Opus-1, 2026-06-04.

## MWCC lhzu/lwzu RMW peephole class — 4 functions

The MWCC GC-1.2.5n `-O4,p` peephole optimizer converts a read-modify-write pattern
`lhz/lwz r0, N(rB); ...; sth/stw r0, N(rB)` into `lhzu/lwzu r0, N(rB); ...; sth/stw r0, 0(rB)`.
The DOL was compiled without this peephole (uses plain `lhz/lwz` with offset N for both).
No source-level change prevents it; the `volatile` qualifier and separate named variables
both fail. The only fix would be a MWCC flag to disable the peephole (`-O4` without `p`).

### 0x8026732C AISetStreamVolLeft (28B)

**Tried:** `extern volatile unsigned int __AIStreamRegs[]; reg = __AIStreamRegs[1]; ...; __AIStreamRegs[1] = new_reg;`
(separate named variables). MWCC: `lwzu r0, 4(r4); ...; stw r0, 0(r4)`. DOL: `lwz r0, 4(r4); ...; stw r0, 4(r4)`.

### 0x80267358 AISetStreamVolRight (28B)

**Tried:** symmetric to AISetStreamVolLeft. Same wall.

### 0x80266F28 AIStartDMA (24B)

**Tried:** `extern volatile unsigned short __AIDMARegs[]; __AIDMARegs[27] | 0x8000 → __AIDMARegs[27] = ...`
MWCC: `lhzu r0, 54(r3); ...; sth r0, 0(r3)`. DOL: `lhz r0, 54(r3); ...; sth r0, 54(r3)`.

### 0x80266F40 AIStopDMA (24B)

**Tried:** symmetric to AIStartDMA. Same wall.

**Notes / hypotheses:** The `-O4,p` peephole `p` flag is the culprit. A per-file flag
override stripping `,p` from the MWCC flags would need verify_mwcc.py support (a new
`// MWCC-FLAGS:` marker). **CLASS WALL** for all MWCC RMW setters using extern-array at
base+nonzero_offset. Tooling fix: add per-file `-O4` (no `,p`) override to verify_mwcc.py.

**Logged by:** Matcher-MWCC-SDK, 2026-06-04.

## 0x802B0838 AptValue::toString(char*) const (132B)

**Tried:** Full clean decode (EAStringC refcount-inlining tier): default-construct a
temp EAStringC sharing the static empty rep g_emptyStringRep@0x8043E6B4 (refcount++ @
rep+0, u16), delegate to the EAStringC& overload (0x802B08BC), strcpy(out, tmp.data()
= rep+8), then inlined dtor `if(--rep->refcount==0) Deallocate(heap, rep, rep->size+9)`.
Decode is CORRECT — compiles ~90% byte-match. Needed `EAStringCRep` >8B (added inline
`char data[8]`) to force absolute lis@ha/@l addressing instead of @sda21 (the
<=8B-struct SDA-placement trap) — that fixed the head. Both implicit-dtor and
explicit-release source forms tested.

**Asm shape that didn't reduce:** the dtor tail. DOL keeps the free block INLINE
(refcount!=0 -> `bne` to epilogue at +0x14, free falls through) and uses r4 for the
reloaded rep:
  `lwz r4,8(r1); lhz r9,0(r4); ...; bne +0x14; lhz r5,4(r4); lwz r3,heap; addi r5,9; bl Deallocate`
GCC-3.9.3 REORDERS the cold Deallocate block OUT-OF-LINE past the epilogue (`bne +0x74`)
and colors the rep into r11 instead of r4. `-fno-reorder-blocks` is NOT a valid cc1plus
3.9.3 option, so the inline placement can't be forced.

**Notes / hypotheses:** objdiff / SN-point-version class (cold-block reorder + coloring),
same family as InstanceOf 0x80280FBC. The 2005 SN build did not out-of-line the cold
free; installed 3.9.3 does. Awaits a real not-installed SN point-version / objdiff. The
EAStringC refcount-inline + >8B-rep-forces-absolute-addr decode is reusable for the
AptValue toString/getVariable string-returning family.

**Logged by:** Matcher-Opus-1, 2026-06-04.

## 0x802D945C EA::Allocator::GeneralAllocator::MakeChunkFromCore(unsigned int, unsigned int) (68B)

**Tried:** natural body `mnSize = a|b; mnPriorSize = 0; AddDoubleFencepost(0, a|b); return this;`
with three operand/temp variations: `a|b`, `b|a`, and an explicit `unsigned int packed = b|a`
local. Default scheduling. Prologue (`stmw r30` saving the unused r31), the two header
stores, the AddDoubleFencepost delegate call, and the `mr r3,r30` return all match.

**Asm shape that didn't reduce:** the packed value `(a|b)` register home.
```
DOL:       or  r5,r4,r5      ; a|b computed directly INTO r5 (the 3rd-arg reg)
           stw r5,4(r30)     ; this->mnSize = a|b
           li  r4,0
           stw r0,0(r30)
           bl  AddDoubleFencepost   ; r5 already holds a|b -> no extra move
COMPILED:  or  r4,r4,r5      ; a|b computed into r4
           mr  r5,r4         ; <-- extra move to put it in the 3rd-arg reg r5
           stw r4,4(r30)
           li  r4,0
           ...
```
SN ProDG 3.9.3 colors `a|b` into r4 and inserts `mr r5,r4`; the 2005 build colored it
straight into r5. One extra instruction, cascades the tail.

**Notes / hypotheses:** register-allocation/coloring version diff (same class as the
this-alias-mr / CSE-coloring walls). Not source-coaxable from the 3 reshapes tried.
Candidate for Lane D re-validation with a different model family (GPT-5.5/Pi) or a
period-correct SN-ProDG point-version. The sibling AddDoubleFencepost (0x802D9418) it
delegates to is itself a separate version wall (base-sharing).

**Logged by:** Matcher-Opus-2b, 2026-06-04.

## 0x802860AC AptArray::get(int) const (56B) — cross-jump / block-order wall (CONFIRMED clean-attempt)

**Status:** forced ASMPROC stub (`anti_tail_merge`) remains; clean conversion confirmed
not achievable under SN ProDG 3.9.3 -O2.

**What the function does (fully decoded):**
```c
AptValue* AptArray::get(int idx) const {        // m_data@0x24, m_count@0x2C
    if (idx >= 0 && idx < m_count) {            // signed: mr. (sign) + cmpw (count)
        AptValue* v = m_data[idx];              // lwzx via slwi idx*4
        if (v) return v;                        // bnelr
        return gpAptUndefined;                  // D2 (SDA -22936(r13))
    }
    return gpAptUndefined;                       // D1 (SDA -22936(r13))
}
```
DOL layout: `[tests] [D1=lwz default;blr] [valid block] [D2=lwz default;blr]` — the
bounds-default block D1 sits BETWEEN the tests and the valid block; the count test
is `blt VALID` (forward, jumping over D1). D1 and D2 are byte-identical but kept as
two separate blocks.

**Clean attempts (all under real SN ProDG 3.9.3):**
- Shape A (`if (idx>=0 && idx<count){v=..; if(v)ret; return D2;} return D1;`):
  keeps D1 and D2 as TWO separate tails (no merge!) but emits order
  `[tests][valid][D2][D1]` — GCC defers the cold bounds-default `.L3` to function
  end. Correct block count, wrong order.
- Shape E / H (guard clause `if(idx<0||idx>=count) return D1; ... return D2;`, and
  the if/else form): emit the exact DOL block ORDER `[tests][D1][valid][D2]` but
  GCC cross-jumps/tail-merges the two identical `lwz gpAptUndefined@sda21; blr`
  blocks into ONE (96B vs DOL 112B-hex / 56B).
- Shape D (`goto valid` with D1 between): jump-threaded away → merged.
- Flags tested (no effect on the merge): `-fno-thread-jumps`, `-fno-cse-follow-jumps`,
  `-fno-rerun-cse-after-loop`, `-fno-gcse`. `-fno-crossjumping` does not exist in
  the 2.95-based SN cc1plus. `-O1` = same as `-O2` for shape A (wrong order); `-O0`
  generates a stack frame and is structurally unrelated.

**Conclusion:** GCC 2.95/SN-3.9.3 at -O2 either (a) keeps two tails but places the
cold block at function end (shape A), or (b) places blocks in DOL order but merges
the two identical tails (shape E). The DOL needs BOTH two-tails AND DOL order, which
no clean source shape produces — the block-order vs tail-merge behaviors are coupled
and not source- or flag-controllable here. Genuine cross-jump/block-layout wall;
the `anti_tail_merge` post-cc1plus mutator remains the only route. Re-test only with
a different SN-ProDG point-version if one is ever installed.

**Logged by:** Matcher-Opus-1b, 2026-06-05.

---

## 0x802D94C4 EA::Allocator::GeneralAllocator::GetBlockInfoForChunk(Chunk*, BlockInfo*) const (224B)

Scheduler-tie wall (store-vs-computation interleave). The function is fully
understood: a 3-case BlockInfo filler — `chunkSize=mnSize&~7`, `flag2=mnSize&2`,
`next=chunk+chunkSize`; if `next->mnSize&1` (in use) it calls `GetUsableSize` and
writes type-2 info (prev-fenced sub-case walking back over `mPrevSize`, or the
ordinary sub-case), else writes type-4 free info. Semantics and field offsets all
confirmed against the forced stub.

**Attempts (all real SN ProDG 3.9.3, verified in isolated outdir):**
- Default scheduling, natural source: CORRECT register allocation (inUse in r11,
  field14 zero-reuse via r27/r11 all match) but the scheduler reorders the
  independent BlockInfo stores within each branch — ~12 store-order offsets differ.
- `-fno-schedule-insns`: fixes some store order but BREAKS allocation — inUse moves
  to r9 (`andi. r9` vs DOL `andi. r11`), cascading the field14 zero-reuse bytes.
- `-fno-schedule-insns2` alone: worse — prologue `mr` order and the `li` constant
  registers diverge too (pre-RA scheduling is needed for the prologue).
- `volatile BlockInfo*` stores + default scheduling: BEST — restores the correct
  allocation AND pins store order; only the field4 value computation
  (`mPrevSize + chunkSize + 16`, two reloads) interleaves differently: the DOL
  spreads its `lwz/add/addi` between the field14/mpData/fieldC stores (slot-filling),
  while the verify compiler batches them after the volatile stores. ~12 offsets, all
  the same instructions in a different interleave.

**Conclusion:** the DOL needs default-scheduling allocation, DOL store order, AND
the field4 sub-computation interleaved between the stores — three constraints that
no clean source shape / flag combination satisfies simultaneously (volatile pins
stores at the cost of the interleave; non-volatile gets the interleave at the cost
of store order). Genuine pre-RA scheduler-tie. Re-test only with a different SN
ProDG point-version, or if a future technique can bias slot-fill order.

**Logged by:** Matcher-Opus-2c, 2026-06-05.

## 0x802AA400 AptNativeHash::GetFirstItem(void) (112B) — 1-instr count-coloring near-match

**Status:** forced ASMPROC stub remains; clean attempt reaches 27/28 instructions
(entire loop body + materialized-bool + sentinel + entries->r0/`mr r3,r0` prologue
all byte-match); off by ONE instruction in the loop-bound register.

**Decoded (clean source verified to 1-instr):**
```c
AptNativeHashEntry* AptNativeHash::GetFirstItem() {        // m_capacity@0, m_entries@4
    if (m_entries == 0) return 0;                          // lwz r0,4(r3); cmpwi; bne
    int count = m_capacity;
    AptNativeHashEntry* e = m_entries;
    for (int i = 0; i < count; ++i, ++e) {
        void* key = e->m_key;
        int occupied = (key != 0);                         // li 1; cmpwi; bne; li 0
        if (occupied) { if (key != SENTINEL_0x8043E6B4) return e; }
    }
    return 0;
}
```
**The 1-instr diff:** DOL loads count into r3 (greedy reuse of the dead `this`
register), runs the loop-entry guard `cmpw r10,r3`, then `mr r8,r3` to the persistent
loop register (r3 reclaimed for `e`). My SN-3.9.3 invocation allocates count directly
into r8 (one fewer instruction — no `mr r8,r3`). Tested 5 source shapes (for / while /
do-while / inline-m_capacity / count-var) x 4 scheduling-flag combos: count never
lands in r3 first. Unlike the sibling GetNextItem (0x802AA470, LANDED clean) whose
coloring was fixable by splitting the pointer compute (`e=current; e=e+1` forces the
early `mr r3,r4` + `this->r9`), GetFirstItem's diff is a loop-*bound* register choice
in the header, not a value move — not source- or flag-inducible here. "this-alias /
count-coloring" wall class. Re-test only with a different SN point-version.

**Logged by:** Matcher-Opus-1b, 2026-06-05.

## 0x802AAE30 AptNativeHash::RegisterReferences(AptValue*) const (220B) — 3-instr register-base lwzx-swap near-match

**Status:** forced ASMPROC stub remains; clean attempt matches 217/220 bytes
(everything EXCEPT 3 instructions in the entry-scan loop).

**Decoded (clean source verified to 3-instr):** GC reference registration in 3 sections,
each calling `gcFn(owner, ref, desc)` through a global fn-ptr via mtlr;blrl:
1. `if (m_8@0x08)  gcFn(owner, m_8,  *gAptHashDesc1 + 8)`  -- gAptHashDesc1 = ptr @0x8049D3BC
2. `if (m_12@0x0C) gcFn(owner, m_12, *gAptHashDesc2 + 8)`  -- gAptHashDesc2 = ptr @0x8049D59C
3. `if (m_entries@0x04) for(i=0;i<m_capacity@0x00;i++){ e=&entries[i]; if(e->value@+4) gcFn(owner, e->value, e->key@+0 + 8); }`
Entry stride 8 {key@0,value@4}; m_entries/m_capacity re-read each iter (callback clobber).
Descriptor globals declared `extern void* g[]` to force absolute lis/lwz (relocs masked) -
THESE MATCHED. The mtlr;blrl fn-ptr recipe, both fixed-field blocks, the loop structure,
guard, and the value (add+lwz4) all byte-match.

**The 3-instr diff (entry loop only):**
- 0x8C: DOL `add r9,r31,r11` (offset-IV first) vs mine `add r9,r11,r31` (base first)
- 0x9C: DOL `lwzx r5,r31,r11` (offset-IV first) vs mine `lwzx r5,r11,r31` (base first)
- 0xAC: DOL `mtlr r9` vs mine `mtlr r11` (fn-ptr reg, follows from the above)

**Why unfixable cleanly:** the base operand (m_entries, r11) is RE-READ inside the loop
(call clobber) -> a *register* base, not a symbol base. GCC canonicalizes the indexed
`add`/`lwzx` with the re-read register base as rA; the DOL puts the offset induction var
(r31) as rA. The honest index-first source fix ([[feedback_lwzx_source_canonicalization]])
only flips operand order for SYMBOL bases, not register bases (confirmed: tried `i*8 +
(char*)m_entries` and an explicit `off` byte-offset IV - neither flipped it; the explicit
IV also reordered the loop guard, making it worse). This is the documented "register-base
lwzx swap_operands" wall class; the banned swap_operands mutator is the only route. Re-test
with a different SN point-version.

**Logged by:** Matcher-Opus-1b, 2026-06-05.

---

## 0x802DA588 GeneralAllocator::DescribeChunk(Chunk*, char*, unsigned int) — 352B

**Status:** forced ASMPROC stub remains; clean C++ matches 87/88 instructions
(everything EXCEPT one redundant register-preservation copy).

**Fully decoded & clean-verified to 1 instruction.** Formats one heap chunk into a
debug string: memset two scratch buffers, hex-dump the chunk body via GetDataPreview
(0x802DA3EC, landed clean 42b983611), then two variadic SnprintfLocal (0x802D86B0) calls
(`"addr: 0x%08x%csize: %10u (%8x)%cdata: %s%c"` + flag line `"attr: %s %s%c"`). Returns
clamped char count. Confirmed recipes that DID match (all banked):
- **memset emits `crxor 6,6,6` (varargs marker)** in this TU -> declare memset VARIADIC
  `extern "C" void* memset(void*, int, ...);` (original called it through an implicit/
  unprototyped decl -> varargs convention). GetDataPreview's TU used a real prototype (no
  crxor) -> the two functions are in different TUs; set memset's decl PER FILE.
- **buffers held in callee-saved regs:** `char* pBufA = bufferA;` (else GCC recomputes
  `addi r1,16` 3x instead of keeping it in r28). bufferA[257]@16(1), bufferB[514]@280(1).
- **flag separation:** `unsigned isInternal = flags & 4; if (isInternal || (flags & 2))`
  with isInternal reused for s1 — prevents GCC folding `(f&4)||(f&2)` into a single
  `andi. r0,r0,6`. &2 is intentionally re-tested (DOL re-ANDs it for the s2 select).
- **return clamp:** write `if (n > 0) return (unsigned)n; return 0;` NOT
  `return n>0?n:0;` — the if/return form makes the n<=0 / no-flag / n2<=0 early exits
  CONVERGE on one shared `mr r3,r30; cmpwi r30,0; bgt; li r3,0` block (the ternary lets
  GCC fuse `mr. r3,r30` and split the n<=0 path, going 1 short).
- shared "mapped" literal used for both s1-false and s2-false (DOL shares 0x8041E658);
  reloc masked so literal content is cosmetic.

**The 1-instruction diff:** DOL loads the flag word into **r0** then `mr r11,r0` to preserve
it (because the subsequent `andi. r0,r11,2` would clobber r0); the SAME compiler from clean
source loads flags into **r4** and reuses r4 for every `andi. r0,r4,N`, so no copy is needed.

**Why unfixable cleanly:** pure register-allocation. GCC (SN ProDG 3.9.3) produces the
*more efficient* allocation (flags in a non-arg-conflicting reg, no redundant `mr`); the
original picked r0 (an arg/scratch reg) and paid a preservation copy. No source lever found
to force flags into r0: tried default / -fno-schedule-insns / -fno-schedule-insns2 / both
(default & sched2-off both give the 87-insn near-match; sched-off is worse at 86), int-vs-
unsigned flags, if/return vs ternary, separate accumulator. This is the "register-allocation
coloring" wall class (compiler emits better code than the original). Re-test under a different
SN point-version. Working clean source parked at build/verify/dc3.cpp.

**Logged by:** Matcher-Opus-2d, 2026-06-05.

## AptDate::sMethod_get* raw-field getter sub-family (14 functions, ~180B each) — register-numbering coloring wall

**Addresses (all forced ASMPROC stubs remain):**
- 0x80294960 getDate (field 0x34)        - 0x80295080 getUTCDate (0x54)
- 0x80294AD4 getFullYear (0x3C)          - 0x802951F4 getUTCFullYear (0x5C)
- 0x80294B88 getHours (0x2C)             - 0x802952A8 getUTCHours (0x4C)
- 0x80294C3C getMilliseconds (0x40)      - 0x8029535C getUTCMilliseconds (0x60)
- 0x80294CF0 getMinutes (0x28)           - 0x80295410 getUTCMinutes (0x48)
- 0x80294DA4 getMonth (0x38)             - 0x802954C4 getUTCMonth (0x58)
- 0x80294E58 getSeconds (0x24)           - 0x80295578 getUTCSeconds (0x44)

**Status:** boxing body fully decoded & clean-verified EXCEPT a 2-register swap
(value<->head get r31<->r30 the wrong way round). The rest of the AptDate getter
family LANDED CLEAN this session using the same boxing recipe:
- 0x80296888 sMethod_UTC (SDA getter, 48cfe42f0)
- 0x80294A14 getDay + 0x80295134 getUTCDay (call-based, value=getDayOfWeek result)
- 0x80294F0C getTime (boxes constant 0)
- 0x8029562C getYear (boxes year-1900) + 0x80294FC0 getTimezoneOffset (abs(off)*60)

**The boxing recipe (CONFIRMED, reusable):** each getter returns a number AptValue made
by the inlined AptValueGC allocator. Two-variable form (separate `head` for the free-list
fast path and `obj` for the alloc path):
```
AptNum* head = g_aptGCFreeList;            // SDA -0x691c
if (head) { w0|=0x20000000; pop next@0xC; if(size>=cap) clear bit else gcVec[size++]=head;
            head->w12 = value; return head; }
obj = g_aptValuePool->Allocate(16);        // pool SDA -0x59ec, 2-arg (this,16)
obj->initType(7); obj->w12 = value; obj->w8 = (void*)g_aptNumberVTable; return obj;
```
Globals: AptNum{w0,w4,w8=vtable,w12=value/next}; AptGCVector* g_aptGCVector (SDA -0x6bd0,
{cap@0,size@4,data@8}); g_aptNumberVTable[] absolute (lis/addi); ctor `initType`=AptValue::
AptValue(7) @0x802B45FC; Allocate @0x802B5848. Inner test MUST be `if (size >= cap)` (DOL
emits `blt append; clear; b`). The static helper does NOT inline (too big) — write the box
in each getter body.

**Why these 14 wall:** their boxed value is a RAW field load (`lwz r31, off(r3)`) with NO
computation. DOL then UNIFIES the result pointer into r30 (callee-saved, used in both fast
& alloc paths) and puts the field value in r31. The SAME compiler (SN ProDG 3.9.3) from
natural C++ instead gives result(head)=r31 / value=r30 — the head pointer has ~11 refs vs
the value's 3, so by GCC-2.95 global-alloc priority (floor_log2(n_refs)*freq/live_length)
head always outranks value and grabs r31 first (reg_alloc_order tries r31 before r30). No
source lever flips it: tried value-first vs head-first decl, single-var vs two-var (two-var
pushes head to a *volatile* r8, not DOL's r30), `inline` helper (inlines but optimizes the
return + same swap), result-intermediate/common-tail (size mismatch), all 4 schedule-flag
combos. The COMPUTED-value siblings (getYear/getTimezoneOffset/getDay) win precisely because
the value computation lands in r31 via an arithmetic op + a volatile temp, freeing head to a
volatile reg + the two-var split — a structure the raw-field load can't reproduce without an
extra (byte-changing) instruction. This is the "register-numbering coloring" wall class.
Re-test under a different SN point-version, or if a value->r31 priority lever is later found.

**Logged by:** Matcher-Opus-1c, 2026-06-05.

## 0x802341B0 ERLevel::AddBounds(EBound3 &, EBound3 &, bool &) (176B)

**Tried:** Natural clean C++ for first-bound copy and component-wise min/max merge, plus manual integer-copy variants to reproduce the DOL's six-word copy order and `-fno-schedule-insns`.

**Asm shape that didn't reduce:** Semantics are decoded, but generated code keeps choosing a shorter/reshuffled float min/max loop and different copy/load scheduling. DOL uses explicit fmr temporaries before each compare/store:

```
DOL:   lfsx  f0,r9,r5
       lfsx  f13,r9,r4
       fmr   f12,f0
       fcmpu cr0,f13,f0
       bge   keep_src
       fmr   f12,f13
       stfsx f12,r9,r4
MINE:  lfsx/fcmpu pair without the distinct f12 output temp, then stores f0/f13 variant
```

Manual first-copy forms can reproduce the pointer setup (`addi r10,src+12`, `addi r8,dst+12`) but drift on word load/store ordering or loop layout.

**Notes / hypotheses:** Likely a small expression-selection/scheduler wall, not a semantic unknown. Next pass should try alternate float helper shapes that force a distinct output temp register without adding instructions, or TU context if alias/inlining context affects the copy loop.

**Logged by:** Matcher-Pi, 2026-06-05.

## 0x800B859C GoalUnlock::SetupObjectUnlockInfo(void) (316B)

**Tried:** Natural C++ around `EResourceManager::AddRef(0x0c33db41)`, `EResource::getTable(lbl_803E9C08)`, walking table rows (72-byte row stride), extracting first object entry with positive unlock id into `s_objectUnlocks`, then zero-filling remaining 8-byte entries through index 127. Tried method declarations vs absolute `_quickdataman` pointer, structured loops, goto-shaped inner loop, manual offset/index forms, and `-fno-schedule-insns`.

**Asm shape that didn't reduce:** Semantics are decoded, but clean C++ does not reproduce the DOL's tight register/loop coloring. DOL keeps the table pointer in r3, mirrors it into r11 for count reloads, uses r10 as the outer index and r11 as the inner index, while keeping the output count in r31:

```
DOL:   li r31,0; mr r30,r3; ... getTable
       mr r11,r3
       li r10,0
       lwz r0,0xc(r11)
       cmplw r10,r0
       ... mulli r9,r10,72 ... li r11,0 ...
```

Natural C++ variants either compare using r31/r11, alter branch spans, or shrink/reorder the clear loop. Absolute `_quickdataman` recovers the lis/addi call setup, but the nested loop still size-mismatches (compiled ~304B vs DOL 316B) with register/layout drift.

**Notes / hypotheses:** Likely a register-coloring/control-flow-shape wall in a nested table scan rather than unknown behavior. Next pass should try a TU/context version or build a small helper for the inner row scan if that matches original source factoring. The global is `s_objectUnlocks` at 0x80485E7C; table name label is `lbl_803E9C08`; resource manager object is `_quickdataman` at 0x804BAEA0.

**Logged by:** Matcher-Pi, 2026-06-06.

## 0x8023353C ERLevel::AddInstanceToLevelHead(EInstance *) (240B)

**Tried:** Natural variant of the already-landed `AddInstanceToLevel` recipe, using `ValidateInstanceInLevel`, `AddInstanceToRoom`, `ENodeList::AddHead` for 0x40000-flagged instances, array head insertion by shifting the `this+0x2A2B8` instance list up one slot, and optional red-black-tree insertion for flag 0x100. Tried pointer-arithmetic forms for the `this+0x30000` addis base and explicit goto/label for the shift loop.

**Asm shape that didn't reduce:** DOL's head-insert block keeps the addis base in r9, copies it to r10, branches over only the shift loop on `count <= 0`, then always performs insertion/count increment:

```
DOL: addis r9,r30,3
     lwz   r11,-15688(r9)
     mr    r10,r9
     cmpwi r11,0
     ble   insert
     ... shift loop ...
insert:
     lwz r9,-15688(r10)
     stw r31,-23880(r10)
     addi r9,r9,1
     stw r9,-15688(r10)
```

Clean C++ variants either place the insertion/count update behind the wrong long branch target, allocate an extra count pointer register, or alter the addis base register (`r10` vs DOL's r9→r10 copy), giving a 472B compiled listing vs the DOL's 480B masked listing.

**Notes / hypotheses:** Semantic twin of the landed `0x80233454 AddInstanceToLevel`, but the front-insert shift loop is a control-flow/layout wall. A later pass should try source factoring of just the shift+insert helper or TU context; no banned asm/ASMPROC path used.

**Logged by:** Matcher-Pi, 2026-06-06.

---

## 0x802D91C8 EA::Allocator::GeneralAllocator::FindChunkBin(Chunk*) const (392 B)

**Status:** NEAR-MATCH (97/98 insns, **block order matches DOL exactly**). Genuine
register-coloring wall — the "redundant-mr quirk." Parked clean source:
`src/wip/near_match/FindChunkBin_0x802D91C8_regalloc_redundant_mr.cpp`. Forced
ASMPROC stub left UNCHANGED.

**What it does:** Given a chunk, classify which bin it currently sits in. Returns
3 if it's the top chunk; walks the size-specific fast bin (-> 1 if found); computes
a bin index (sentinel-self addr calc if pChunk points into the bins array, else
`size>>3` for size<=511 or `GetLargeBinIndexFromChunkSize(size)`); searches that bin
(-> 2); then exhaustively scans all 10 fast bins (-> 1) and all 127 regular bins
(-> 2); else 0.

**The single gap:** DOL holds `size` in r11 and emits a redundant `mr r3,r11` before
`bl 0x802D9030`; the SAME SN ProDG 3.9.3 from clean source coalesces `size` straight
into r3 (the call-arg reg), eliding the `mr` and renaming every size-touching insn
(r11->r3). This is strictly BETTER codegen.

**Root cause (not source-fixable):** `size`'s live range (top -> GetLargeBin call)
strictly contains the size-specific fastbin head's live range (the do-while walk).
Both prefer r3 and CONFLICT (size live across the head walk). DOL picked head->r3
(size->r11 + redundant mr); clean source picks size->r3 (head->r9, no mr). The
algorithm forces the overlap (fastbin walk must precede the bin-index calc; size
feeds both), so no clean C++ lever flips the tiebreak. Unaffected by
-fno-schedule-insns (coloring, not scheduling). Re-test on a different SN point-ver.

**Recipes that DID land their pieces (banked):** (1) inverted range conditional
`if(in_range){sentinel}else{size_based}` reproduces DOL block layout
`blt size_based; bge size_based; sentinel fall-through; b search`; (2) explicit
`int adj=(int)pChunk-52;` temp stops `pChunk-52-this` folding into `pChunk-(this+52)`
(reuse of cached &mBins[0]) -> DOL's `addi r9,r31,-52; subf r9,r30,r9`; (3) add-canon
`(size>>1)+(unsigned)this+4` puts half as rA matching `add rD,half,this`.

**Struct facts confirmed:** GeneralAllocator mField4@0x04 (max-fast threshold),
mFastBins[10]@0x0C (stride 4; size-specific slot = *(this+(size>>1)+4)), mBins[256]@0x34
(flat Chunk* array; bin k fd=mBins[2k] bk=mBins[2k+1]; regular-bin scan strides 8
over bins 1..127; range end &mBins[256]=this+1076), mpTopChunk@0x444. Helper
GetLargeBinIndexFromChunkSize 0x802D9030 is effectively static (1 arg: size in r3).

**Logged by:** Matcher-Opus-2e, 2026-06-05.

---

## 0x80296750 AptDate::sMethod_toString(AptValue*, int) (312 B)

**Status:** NEAR-MATCH, structurally complete. Register allocation, instruction
selection, and block layout ALL match DOL. The only residual is GCC's stack-slot
*region* assignment (21-24 byte-immediate diffs in `addi rN,r1,K` displacements +
frame size). Forced ASMPROC_inject_before fake-wrapper left UNCHANGED in
src/matched/aptdate/. Best clean candidates parked in F:\tmp\ (v4=24 off, v6=21 off).

**What it does:** AptScript native handler. Boxes a formatted date string into a
20-byte string AptValue (AptString). Inlined AptValueGC *string* allocator (distinct
from the number box): free-list at SDA -0x690c, next-link at obj+16 (NOT +12), object
size 20, EAStringC member at +12. Free path recycles + clears recycled string via
IsEmpty/ReserveSize(0); alloc path = pool->Allocate(20) + AptString::AptString ctor.
Then: default-construct a scratch EAStringC `s` (inlined: m_ptr=EAStringC_sEmptyString,
bump u16 refcount@[0]); `self->toString(s)` (@0x80294688) fills it; copy into the box
via `box->m_str = EAStringC(s.c_str())` (char-ctor temp @0x8026C6DC -> operator=
@0x8026C790 -> ~EAStringC @0x8026C728); then inline-release `s` (refcount-- + pool
Deallocate(buf,cap+9) if 0). Returns the box.

**TWO sub-walls CRACKED (banked recipes, reusable for sibling toString 0x80294688):**

1. **Destructor asymmetry** (s dtor INLINED, temp2 dtor CALLED, same EAStringC type):
   With one EAStringC type, an `inline` dtor inlines BOTH; an `extern` dtor calls
   BOTH. SN ProDG applies dtor-inlineness uniformly. FIX: model the scratch `s` as a
   **raw `char*`** (hand-inline its default-ctor refcount-bump and its release;
   NO auto-destructor), and the copy as a real **EAStringC** temp whose **extern**
   `~EAStringC` emits the `bl`. This yields s=inline-release, temp2=bl-dtor.

2. **Address rematerialization** (temp2's frame address): an ANONYMOUS EAStringC temp
   gets its stack address CACHED in a callee-saved reg (4 saved regs); a NAMED local
   gets the address REMATERIALIZED (`addi r1,K` re-emitted at each of char-ctor/op=/
   dtor, 3 saved regs — matches DOL). DOL rematerializes -> needs a NAMED local.
   Also: hoist `&box->m_str` into a callee-saved reg before toString by computing
   `EAStringC* dst = &box->m_str;` BEFORE the toString call (matches DOL's
   `addi r30,r31,12` pre-call hoist + later `mr`).

**The IRRECONCILABLE residual (the wall):** DOL places the copy temp in the
8-aligned **compiler-temporary slot region** (offset 16, with a 4-byte gap at 12,
frame 40) while ALSO rematerializing its address. But: a NAMED local (needed for
rematerialization, sub-wall #2) is placed in the **named-local region** = the LOW
slot (8), giving frame 32 and swapping s/temp2 offsets. An ANONYMOUS temp lands in
the high region (correct slot 16) but CACHES its address (4 regs, sub-wall #2 fails).
The two required behaviors — high/compiler-temp slot AND rematerialized address — are
coupled to mutually-exclusive source constructs (anonymous vs named). ~12 variants
tried (named/anon, dst hoist, -fno-schedule-insns/insns2, 8-byte `s` struct to force
frame 40, 8-byte copy wrapper, aligned(8), implicit conversion, pointer-assign). Best
= 21 byte-diffs (v6: 8-byte `s` gives correct frame 40 + 3 regs but s@16/temp2@8
swapped vs DOL s@8/temp2@16). Cost model: caching temp2 in r28 is "free" (extends the
stmw range) vs +2 addi to rematerialize, so SN prefers caching from clean source;
DOL's compiler chose remat. Same-function/same-compiler => an unfound IR/source
difference. Frame-layout + register-coloring class; re-test on a different SN
point-version.

**Struct facts confirmed:** AptString {w0 flags(bit 0x20000000=GC-registered)@0,
w4@4, vtable@8, EAStringC m_str@12, free-list-next@16} = 20B. EAStringC {char* m_ptr}
= 4B; buffer header [u16 ref@0, u16 cap@4, chars@8]; dtor = refcount-- + (if 0)
pool->Deallocate(buf, cap+9). String GC globals: free-list SDA -0x690c, gcvector
SDA -0x6bd0 {cap@0,size@4,data@8}, pool SDA -0x59ec. Default-ctor inlined everywhere
(EAStringC_sEmptyString abs addr, bump u16 refcount). Helpers all external bl:
toString 0x80294688, char-ctor 0x8026C6DC, operator= 0x8026C790, ~EAStringC
0x8026C728, IsEmpty 0x8026C6A0, ReserveSize 0x802BC858, AptString ctor 0x802AC2E4,
pool Allocate 0x802B5848 / Deallocate 0x802B598C.

**Logged by:** Matcher-Opus-1d, 2026-06-05.

**REVISIT — Matcher-Opus-1e, 2026-06-06 (improved to 7/312, coupling proven exact):**
The RECIPE-STR sibling wall (defaultSortCompareFunc 0x80287410, toString_char
0x802860E4, toString_EAStringC 0x80286168) was CRACKED this session via the 8-byte
EAStringC handle (`{char* m_ptr; int m_pad;}`) → forces 8-aligned temp slots. Applying
that here drops this fn from 21 → **7 residual bytes — ALL pure s@8 ⇄ temp2@16 slot
swap; frame 40, 3 saved regs (r29/r30/r31), and rematerialized temp addresses ALL match
DOL.** Parked: `F:\tmp\m96750_best.cpp` (nested temp2 + placement-new alloc path; the
`mr r31,r3`-vs-`bl ctor` alloc-order diff is fixed by `result = new(pool->Allocate(20))
AptStrNode();` with placement `operator new`). The slot swap is the ONLY thing left and
it is genuinely irreducible in SN 3.9.3 — the remat/slot behaviors are COUPLED:
  • **nested** named temp2  → rematerialized address (3 regs ✓) BUT named-local LOW slot 8 (✗)
  • **function-scope / anonymous** temp2 (const-ref operator= lets the rvalue bind) →
    compiler-temp HIGH slot 16 (✓) BUT caches its address in r28 (4 regs ✗)
DOL = remat **and** slot 16. No SN 3.9.3 source construct yields that pair (verified:
nested/funcscope/anonymous × default/-fno-schedule-insns/insns2 × two-type
inline-vs-extern-dtor split). The dtor inline/call split itself is fully solved (s =
inline-dtor type, temp2 = extern-dtor type, reverse-construction order → bl then inline).
Confirmed compiler-version coloring/cost-model wall; the original 2005 SN build
rematerialized function-scope temp addresses, SN 3.9.3 caches them. Re-test on an older
SN point-version. **Struct correction:** EAStringC is **8B** (`char* m_ptr; int pad`),
not 4B — the AptString m_str@12 2nd word (@16) IS the free-list next (union overlap),
so AptString stays 20B.

**Logged by:** Matcher-Opus-1e, 2026-06-06.

## 0x802DA950 EA::Allocator::GeneralAllocator::ReportNext(void*, int) (480 B)

**Tried:** Full decode + clean goto-based control-flow reconstruction that mirrors
the DOL's basic-block layout exactly (per Opus-2e's head-start: gotos force the
f18/f1c memory reloads that a clean `for/break` form CSE's away). Dual-mode iterator:
guard (`pContext && magic=='SNAP'`) → snapshot-array path (mMode@0x14==0, walk
`info[]` stride 24, signed `m_type`@+0x10 & flags) vs live-heap path (mMode!=0, walk
core blocks from mpCurrentCore@0x18 to `&mHeadCoreBlock` sentinel @this+1100, scan
chunks to `pLimit=core+coreSize-16`, `ChunkMatchesBlockType` 0x802D93B0 +
`GetBlockInfoForChunk` 0x802D94C4). Snapshot tried both `for(;;)` (strength-reduces
to an `lbzu` walk) and goto skip-in do/while (rotates to one bound check). Default
scheduling. Parked clean source:
`src/wip/near_match/ReportNext_0x802DA950_regalloc_redundant_mr.cpp` (112/120 insns,
block order matches DOL). Forced ASMPROC stub left unchanged.

**Asm shape that didn't reduce:** every count gap is the redundant-mr / const-hoist
class — DOL inserts a temp+copy or hoists a constant that SN ProDG 3.9.3 coalesces:
```
; sentinel:  DOL  addi r9,r27,1100 ; mr r28,r9     clean: addi r28,r27,1100 (no mr)
; pCore:     DOL  lwz r0,24(r30)   ; mr r10,r0     clean: lwz r10,24(r30)   (no mr)
; cur:       DOL  lwz r0,28(r30)   ; mr r3,r0      clean: lwz r3,28(r30)    (no mr)
; const 0:   DOL  li r26,0 (preheader, stmw r26)   clean: li r0,0 at store (stmw r27)
```
The const-0 hoist changes the callee-saved count (6 vs 5) which swaps the whole
coloring (flags r29<->r28, sentinel r28<->r29). Plus a snapshot loop-rotation
(DOL keeps a redundant entry bound check + `mr r11,r9`; 3.9.3 uses one shared check).

**Notes / hypotheses:** Not source-fixable — this is the CEO-noted "our correct 3.9.3
beats the 2005 build's codegen" register-coloring class (same family as FindChunkBin
0x802D91C8, GetBlockInfoForChunk 0x802D94C4, DescribeChunk 0x802DA588). A more-optimal
compiler can't be coaxed into emitting the extra `mr` copies / const hoist. The full
algorithm + Snapshot struct map (magic@0, mBlockTypeFlags@8, mMode@0x14, mpCurrentCore@0x18,
mpCurrentChunk@0x1c, mCount@0x24, mIndex@0x28, info[]@0x2c) is captured in the parked
source for a future objdiff / genuinely-older-point-version retry. SN-VERSION forbidden
in this lane (3.9.3 IS the original); calibration shows 3.8.1/3.7/3.5 identical on this class.

**Logged by:** Matcher-Opus-2f, 2026-06-06.

## 0x802D8A6C EA::Allocator::GeneralAllocator::Init(...) (424 B)

**Tried:** Full decode + faithful clean C++ (named struct members, DOL store-order).
One-time allocator init: mField0 guard → SetOption(0,1) → RAII mutex guard (m_mutex@0x4FC,
spilled to 8(1)) wrapping 5 memsets + a 127-iter circular bin-sentinel loop (fd@+8/bk@+12,
stride 8) + ~25 field stores → unlock → conditional AddCore(a,b,c,d,e,f) → return true.
DEFAULT scheduling reaches 105/106 (matches DOL's 12-callee-saved-reg allocation + param
numbering r20-r25); the forced stub's `-fno-schedule-insns` is over-applied (104/106, loses
the param alloc). Tried shared `char* base`, typed walker — no change. Parked clean source:
`src/wip/near_match/Init_0x802D8A6C_regalloc_loopwalker_storesort.cpp`. Forced stub unchanged.

**Asm shape that didn't reduce:** the 1-insn count gap is the bin-loop walker copy —
```
; DOL: mr r29,r30 (capture this+52 before bins memset); ... mr r9,r29 ; walk r9 (fresh temp)
; 3.9.3: coalesces the destructive walker into the dead memset pointer r30 -> no mr (1 shorter)
```
Plus a store-sort: the 0x46C..0x4A4 field-store block schedules in a different (legal) order
than the DOL under default scheduling (moot while the walker walls the instruction count).

**Notes / hypotheses:** Same redundant-mr / register-coalescing-tiebreak class as ReportNext
0x802DA950 and FindChunkBin 0x802D91C8 — the 2005 SN ProDG allocator inserts a copy that the
verify 3.9.3 allocator coalesces away (strictly better codegen, no source lever). Second
confirmation this 392B+ allocator tier is "mostly walls" of this class. Retry via objdiff or a
genuinely-different-allocator point-version only. SN-VERSION forbidden in this lane.

**Logged by:** Matcher-Opus-2f, 2026-06-06.

## 0x802D886C EA::Allocator::GeneralAllocator::GeneralAllocator(...) (448 B)

**Tried:** Full decode + faithful clean straight-line constructor (named struct members,
exact DOL store-order, `-fno-schedule-insns`). 6 memsets + ~45 zero-stores + non-zero defaults
(m08=1,m47C=1,m484=9,m485=10,m4CC=256,m4EC=4096,m4F0=0x400000,m4F4=0x100000,m520..524=
{221,222,205,171,254}, two default-callback fn-ptrs @0x4D0/0x4D8 (absolute relocs, masked),
two self back-ptrs @0x4D4/0x4DC=this) → delegate Init(a,b,c,d,e,f) → return this.
**Instruction COUNT matches exactly (112 insns).** Parked clean source:
`src/wip/near_match/ctor_0x802D886C_regalloc_coloring.cpp`. Forced stub unchanged.

**Asm shape that didn't reduce:** ~55 byte diffs, all register-coloring / constant-scheduling:
```
; params live entry->Init: DOL colors a=r27,b=r24,c=r26,d=r25,e=r23,f=r22 (3.9.3 differs)
; consts 9/10 -> DOL r9/r0 (3.9.3 swaps); 256/4096/0x400000/0x100000 -> DOL materializes all
;   four UP FRONT, holds across the zero-block, stores at the end; 3.9.3 materializes inline
;   -> cascade of ~40 store-offset diffs
```

**Notes / hypotheses:** Same redundant-mr / register-coalescing + constant-scheduling class as
ReportNext 0x802DA950, Init 0x802D8A6C, FindChunkBin 0x802D91C8. THIRD confirmation the entire
392B+ GeneralAllocator tier is this single wall class — the 2005 SN ProDG allocator/scheduler
makes different (often less-optimal) register/ordering choices than the verify 3.9.3 with no
clean source lever. Retry only via objdiff or a genuinely-different point-version; SN-VERSION
forbidden in this lane. Recommend deprioritizing the remaining 392B+ tier (ClearFastBins,
SetOption, Check* family) — same class — pending a Lane-B objdiff/version-override unlock.

**Logged by:** Matcher-Opus-2f, 2026-06-06.
