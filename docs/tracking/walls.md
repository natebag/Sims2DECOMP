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
