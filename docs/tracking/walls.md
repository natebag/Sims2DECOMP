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

**Notes / hypotheses:** The un-coalesced `lfs f0; fmr f1,f0` is the signature of
a *different/older Metrowerks codegen* than mwcc 1.2.5n (build 163). The
DolphinSDK libm almost certainly ships precompiled by an earlier MWCC (e.g.
1.1 / 1.2.5 non-`n`, or a pre-build-163 1.2.x) whose register allocator did not
fold the return move. **TOOLING LEAD:** obtain additional MWCC versions from
decomp.dev compilers.zip and re-probe fabsf — if one emits the f0+fmr tail at
offset 8, the whole libm float family becomes matchable. Not a C-source problem;
a compiler-version problem. Do NOT force with ASMPROC.

**Logged by:** Matcher-MWCC-SDK, 2026-05-30.
