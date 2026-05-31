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
