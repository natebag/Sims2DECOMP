# APT Opcode Middle-Pool Template (100-200B) — Full Decision Guide

**Session 12 — OpusWorker Track C middle-pool full template pass.**
**OpusReview advisory A/B/C applied.** Signed off: pending.

Expands `apt-middle-template.md` with sub-family dispatch decision tree
so KimiGuy can blast middle-pool handlers without pattern drift.

## Sub-family taxonomy (from DOL inspection)

Middle-pool handlers divide into 4 sub-families. Identify by inspecting
the target function's DOL disassembly:

### A. Push-simple (AptValue-singleton)
**Signature:** reads SDA singleton token (g_aptActionGlobal = r13-22936),
pushes onto stack at `stack[sp*4]`, MI-vcalls token's vtable with
opcode 138.

**Example:** PushNULL (0x8027F2DC), PushUndefined (0x8027F340),
PushGlobalVariable (0x8027F62C).

**Dispatch offsets:** vt+8 (thisOff, lha), vt+12 (fn, lwz).

**Pc reads:** **NONE** — token comes from SDA, not bytecode.

**Template match:** 100% — direct copy of PushNULL pioneer with opcode-arg
adjustment. MATCH first-try.

### B. Stack-manipulation
**Signature:** reads existing stack value (e.g., stack[sp-1]), pushes
result (possibly the same value, or derived). Same MI-vcall as Push-simple.

**Example:** PushDuplicate (0x8027AAD4, 104B).

**Dispatch offsets:** vt+8 / vt+12 (same as Push-simple).

**Pc reads:** **NONE**.

**Template match:** 100% after operand-order adjustment (Technique #57).

### C. Conditional-target (Drag/Movie)
**Signature:** reads SDA manager singleton (different SDA offset from
A/B — e.g., g_aptDragTarget = r13-23008), checks field at manager+60,
conditional MI-vcall with DIFFERENT opcode (e.g., 4686), then clears
field to NULL token.

**Example:** StopDragMovie (0x80275CB8).

**Dispatch offsets:** **vt+16 (thisOff)** / **vt+20 (fn)** — DIFFERENT
from Push-simple.

**Pc reads:** **NONE**.

**Template match:** 100% after applying vt+16/+20 offsets and explicit
double-read of SDA manager (once for test, once for clear).

### D. Pc-reading dict-lookup (String)
**Signature:** reads 1-2 bytes from `ctx->m_pc` (I-stream), looks up
via `interp->m_dict[byte]` (offset 0x38 in interp), pushes dict value,
MI-vcalls.

**Example:** PushStringDictByte (0x8027F924, 128B).

**Dispatch offsets:** vt+8 / vt+12 (same as Push-simple).

**Pc reads:** **YES** — reads `ctx->m_pc[0]` as byte or `ctx->m_pc[0..1]`
as word, advances pc by 1 or 2 bytes.

**Template match:** ~75-90% — GCC scheduler reorders 2-3 instruction
pairs relative to SN ProDG's order. Parked as permuter candidate.

## Decision tree — pick the right sub-family for a new handler

Given the handler's DOL disasm, run this checklist:

1. **Does the function read `ctx->m_pc`?** (`lwz rX, 0(r4)` early, or
   `lbz rX, 0(rY)` after mr-alias of r4)
   - YES → **Sub-family D (String/pc-reading)**
   - NO → continue

2. **Does the function test a manager-field for non-null and
   conditionally MI-vcall?** (`beq` after `cmpwi ... 0` immediately
   after a SDA `lwz rX, -N(r13)`)
   - YES → **Sub-family C (Conditional-target/Drag)**
   - NO → continue

3. **Does the function read an existing stack slot (`lwz rX, -4(rY)`
   or similar relative addressing of interp->m_stack[sp-N])?**
   - YES → **Sub-family B (Stack-manipulation)**
   - NO → continue

4. **Does the function push an SDA-loaded singleton (`lwz rX, -22936(r13)`
   or similar) onto the stack?**
   - YES → **Sub-family A (Push-simple)**
   - NO → OUT OF SCOPE — may be a larger handler (>200B), a specialized
     variant not covered here, or arithmetic family (park for S13).

## Dispatch-offset decision table

Inspect the DOL `lha rX, N(r9)` (thisOff) and `lwz rY, (N+4)(r9)` (fn)
immediately before the `blrl`:

| N (thisOff offset) | Sub-family                  | Opcode typical |
|--------------------|------------------------------|----------------|
| 8  → vt+8/+12      | A (Push-simple), B, D         | 138             |
| 16 → vt+16/+20     | C (Conditional-target/Drag)   | 4686 etc.       |
| (other)            | UNKNOWN — STOP, escalate to  | N/A             |
|                    | MainGuy before proceeding     |                 |

If the offsets don't match the table, the handler likely belongs to a
sub-family not yet pioneered. Do NOT guess — park and ask.

## Read-source classification (Kimi decision rule)

For every `lwz/lbz rX, IMM(rY)` in the function body, classify the read:

| Pattern                         | Source type    | C construct                                   |
|---------------------------------|----------------|-----------------------------------------------|
| `lwz rX, 0(r4)` early in fn     | `ctx->m_pc`    | `register u8* pc asm("r9") = ctx->m_pc;`      |
| `lbz rX, 0(rY)` where rY=pc     | bytecode byte  | `unsigned int byte = *pc;`                     |
| `lwz rX, 0(r3)` (r3=interp)     | sp             | `int sp = interp->m_stackIdx;`                 |
| `lwz rX, 8(r3)`                  | stack base     | `(int)interp->m_stack`                         |
| `lwz rX, 56(r3)` / `lwz rX, 60(r3)` | struct field | `*(int*)((char*)interp + N)` — inspect map    |
| `lwz rX, -N(r13)`                | SDA global     | `extern u8* g_<name>;` (SDA eabi placement)    |
| `lis rX,H; addi rX,rX,L`        | abs string     | `extern char g_<name>[16];` (sized, non-SDA)   |
| `lwzx rX, rA, rB`                | indexed load   | Use `(u8**)(rA + rB)` explicit int+int arith   |

## Debug-string naming convention

DOL middle-pool handlers pass 2 abs-addr string pointers as args 2+3.
Each is a `file:line` debug token specific to the opcode.

**Convention:** `g_aptDbgStr_<OpName>_<LoSuffix>`

Where `<LoSuffix>` is the lower 4 hex digits of the absolute address
from the DOL `addi rX, rX, IMM` (sign-extended).

**Examples:**
- `g_aptDbgStr_PushNULL_1680` for 0x80401680 used by PushNULL
- `g_aptDbgStr_StopDragMovie_1CF0` for 0x80401CF0 used by StopDragMovie

**Note:** my pioneer-3 files used short names `g_aptDbgStr1680` etc.
The shared `g_aptDbgStr1680`/`g_aptDbgStr16B4` are used ONLY by the
Push-simple family (NULL, Undefined, GlobalVariable). Drag-family,
String-family, and others need UNIQUE names per opcode to prevent
symbol collisions at link-time.

## Pc-handling sub-class (Sub-family D specifics)

Sub-family D reads pc and advances it. Register pin convention:

- `r10 = ctx` (start of function, `mr r10, r4`)
- `r9 = pc = ctx->m_pc`
- `r11 = byte = *pc` (then `byte << 2` for dict index)
- Store `ctx->m_pc = pc + N` before doing work

**Critical:** pc must be pinned to r9 (not r11 like Push-simple family).
The r9-pin is required because subsequent work reuses r10 for `dict`
and r11 for `byte*4`.

## Template commit naming

Filename: `match_0xADDR_AptActionInterpreter__FunctionAptAction<Op>.cpp`
(double underscore separates class from method, per OpusReview advisory A)

Class declaration (static member per advisory A):
```cpp
struct AptActionInterpreter {
    // field layout...
    struct LocalContextT { ... };
    static void _FunctionAptAction<Op>(AptActionInterpreter* interp, LocalContextT* ctx);
};
void AptActionInterpreter::_FunctionAptAction<Op>(
    AptActionInterpreter* interp, LocalContextT* ctx)
{
    ...
}
```

## Kimi handoff scope (per sub-family signoff)

| Sub-family | Status       | Unmatched count (100-200B) | Handoff scope     |
|------------|--------------|----------------------------|-------------------|
| A — Push-simple | ✅ GREEN (multi-sample) | ~5              | CLEARED (3 pioneers committed: PushNULL, PushUndefined, PushGlobalVariable) |
| B — Stack-mani. | ✅ GREEN (single-sample, spot-audit cleared) | ~3 | CLEARED after expansion |
| C — Conditional | ✅ GREEN (multi-sample) | ~5-10         | CLEARED (2 pioneers committed: StopDragMovie, Pop) |
| D — Pc-reading  | ⚠️ PARTIAL  | ~8-10                     | 75-90% match — permuter needed before full blast |
| E — Accessor-call+push | ⚠️ YELLOW (single-sample) | TBD    | Per-handler OpusReview until 2nd sample found |
| F — Stack-pop-push-no-vcall | ⚠️ PARTIAL | ~3-5         | Permuter candidate (3-insn-pair swap)           |

**Total addressable after full-template signoff:** ~17-20 new middle-pool
blast candidates beyond the 2 Push-simple already handed off.

## Scheduler flag — IMPORTANT

**Sub-families A/B/C:** default scheduling (no FLAGS line). Verified
clean with PushNULL/PushDuplicate/StopDragMovie pioneers.

**Sub-family D:** default scheduling produces 75-90% match with 2-3
instruction pair swaps. Adding `-fno-schedule-insns -fno-schedule-insns2`
causes SIZE_MISMATCH (grows). Recommend: commit partial match + flag for
asm-processor permuter when that tooling lands.

## Escalation rules

- Unknown dispatch offset → STOP, ask MainGuy.
- Handler >200B → OUT OF SCOPE for this template.
- Pc read with non-byte/non-word size → escalate (may be new sub-family).
- Any function with more than 2 abs-addr string args → sub-family TBD.
- `verify_match.sh` reports MISMATCH after applying template → post disasm
  diff to info board, tag `middle-pool-wall`.

## Technique cross-reference

- #53/#54/#55 — <100B dual-scheduler-off template (separate doc)
- #56 — MI-vcall via p+4 secondary vtable (InteractorModule, separate doc)
- #57 — stwx/add operand-order control via int+int arithmetic
- #58 — Middle-pool MI-vcall dispatch (vt+8/+12 vs vt+16/+20)
- #59 — Non-SDA abs-addr string args via `extern char g[16]`
