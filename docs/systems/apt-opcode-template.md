# AptActionInterpreter Opcode Handler Template

**Session 12 — OpusWorker Track C pioneer pass.**

The `AptActionInterpreter::_FunctionAptAction*` family (131 opcode handlers,
0x80272...-0x80281...) share a common shape. This doc captures the
proven matching recipe from the three pioneers so a Kimi blaster can pick up
the remaining 47 unmatched handlers.

## Pioneer results

| # | Address    | Name              | Size  | Class       |
|---|------------|-------------------|-------|-------------|
| 1 | 0x8027DAAC | DefineDictionary  | 40B   | Simple leaf |
| 2 | 0x8027DA60 | StoreRegister     | 76B   | 1-call      |
| 3 | 0x8027EC04 | BranchAlways      | 96B   | Branch+call |

All three verify_match.sh MATCH with SN Systems ProDG.

## Common interface

```cpp
struct AptActionInterpreter {
    int m_stackIdx;        // 0x00  operand-stack index
    char pad_04[4];
    AptValue** m_stack;    // 0x08  operand-stack base (AptValue* pointers)
    char pad_0C[0x28];
    int m_dictPtr;         // 0x34  string-dictionary pointer
    int m_dictLen;         // 0x38  string-dictionary length
    // ... more fields
};

struct LocalContextT {
    int* m_pc;             // 0x00  bytecode program counter
};

// All handlers have this signature:
void _FunctionAptAction<Op>(AptActionInterpreter* interp, LocalContextT* ctx);
```

## Recipe — step by step

### 1. Compiler flags (put as first line)

```cpp
// FLAGS: -fno-schedule-insns -fno-schedule-insns2
```

Both scheduler passes OFF. Leaving either on causes SN-vs-GCC instruction
reordering that breaks the match.

**SCOPE GATE (per OpusReview advisory):** ONLY apply dual-scheduler-off for
handlers **<100B**. For handlers >100B, start with **default flags** (no
FLAGS comment) and only add `-fno-schedule-insns` / `-fno-schedule-insns2`
if verify fails. Default GCC scheduling reproduces SN ordering for many
>100B handlers (per prior-session insight, 2026-04-12). Mass-applying
dual-off to the 688B Add/Subtract/Multiply family will regress matches
that default scheduling would hit cleanly.

### 2. Pin `pc` to r11 (for 1-arg-read handlers) or r9 (for branch handlers)

```cpp
register int* pc asm("r11") = ctx->m_pc;
pc = (int*)(((unsigned int)pc + 3) & ~3u);   // align-up to 4
ctx->m_pc = (int*)((char*)pc + N);           // advance PC by N bytes
```

`N` = total size of bytecode args consumed.

### 3. Read args with pinned registers

SN tends to load args into specific registers. Pin local vars accordingly:

```cpp
register int w0 asm("r9") = pc[0];
register int w1 asm("r10") = pc[1];
```

### 4. Load-before-store via locals

If the handler writes to interp fields after reading from pc, bind the pc
loads to locals first, THEN store. Mixing `pc[i]` expressions directly into
store LHS triggers load-store interleaving:

```cpp
// WRONG (interleaves):
interp->field_A = pc[0];
interp->field_B = pc[1];

// RIGHT (load-load, store-store):
register int w0 asm("r9") = pc[0];
register int w1 asm("r10") = pc[1];
interp->field_A = w0;
interp->field_B = w1;
```

### 5. Pin call-argument locals to their call-ABI register

For a handler that ends with `SomeCall(int, ptr)`, pin the int to r3 BEFORE
the point of call, and the ptr load separately to r4. This forces SN's
load-then-call-through-epilogue shape:

```cpp
register int arg1 asm("r3") = pc[0];
SomeCall(arg1, ptr);
```

Without this, GCC schedules the arg load adjacent to the `bl` instead of
earlier alongside other setup — produces a mismatch of 1-2 swapped
instructions.

### 6. Pinning conventions observed

| Role                           | Register |
|--------------------------------|----------|
| Program counter `pc`           | r11 (leaf) or r9 (branching) |
| SDA global (e.g. value vector) | r10      |
| Operand-stack index            | r9       |
| Operand-stack base             | r0       |
| Call arg 1                     | r3       |
| Call arg 2                     | r4       |
| Post-stack-compute temp        | r9 (reuse) |
| Pre-computed `pc + 4`          | r0       |
| Signed branch delta            | r11      |

### 7. r0-reuse for branch handlers

DOL reuses a pre-computed `pc + 4` in r0 to avoid recomputing. To match
this pattern:

```cpp
register int pcPlus4 asm("r0") = (int)pc + 4;
ctx->m_pc = (int*)pcPlus4;
register int delta asm("r11") = pc[0];
ctx->m_pc = (int*)(pcPlus4 + delta);
```

Do NOT write `(int*)((char*)pc + 4 + delta)` — compiler folds to
`pc + (4+delta)` which emits an extra `addi r11,r11,4` then `add`.

### 8. SDA globals

```cpp
typedef unsigned char u8;
extern u8* g_aptValueVector;  // linker places at SDA slot
```

Compiler emits `R_PPC_EMB_SDA21` reloc. verify_match.sh masks this as
match-compatible.

### 9. Size & comment header

```cpp
// FLAGS: -fno-schedule-insns -fno-schedule-insns2
// 0xADDRESS AptActionInterpreter::_FunctionAptAction<Op> (SIZEb)
```

The size MUST match the DOL function size byte-for-byte (pre-commit hook
enforces this).

### 10. Naming — flat free-function vs proper C++ member form

Per OpusReview advisory + CLAUDE.md, proper C++ member form is canonical.
The drafts show flat `AptActionInterpreter_FunctionAptAction<Op>` because
SN's name mangling collapses both forms to the identical mangled symbol.
Both verify MATCH; prefer member form on commit.

**Filename:** `match_0xADDR_AptActionInterpreter__FunctionAptAction<Op>.cpp`
(double underscore separates class from method).

**Function body — prefer member form:**

```cpp
class AptActionInterpreter {
public:
    void _FunctionAptActionDefineDictionary(AptActionInterpreter* ignored, LocalContextT* ctx);
    int m_dictPtr;
    int m_dictLen;
    // etc.
};

void AptActionInterpreter::_FunctionAptActionDefineDictionary(
    AptActionInterpreter*, LocalContextT* ctx)
{
    // body same as flat form
}
```

Both forms produce the same mangled symbol `_FunctionAptActionDefineDictionary__20AptActionInterpreterP20AptActionInterpreterP13LocalContextT` — so the object file links correctly either way.

### 11. REL14 epilogue pattern (worked example)

BranchAlways emits two `.text+0x00000054` REL14 relocations from two
conditional branches that both jump to the shared epilogue. The pattern
that produces this shape:

```cpp
if (dirty != 0) {
    if (interp->m_stackIdx == 0) {
        AptValueVector_ReleaseValues(vec);
    }
}
// (shared epilogue falls through here)
```

**Critical:** nested-if with the inner call-then-fallthrough is what emits
the `beq skip; bne skip; bl ...; skip:` shape with two REL14 relocs
pointing to the same label.

An `if ... else if ...` or flat `if (a && b)` form will emit different
branches:
- `a && b`: one branch (short-circuit compiles to single `beq skip`)
- `if/else`: separate targets, no shared epilogue reuse

If verify output shows offset differences in the branch-offset region
(~0x30-0x50), check that you used the nested-if form.

## Example: minimal simple handler (DefineDictionary, 40B)

```cpp
// FLAGS: -fno-schedule-insns -fno-schedule-insns2
// 0x8027DAAC AptActionInterpreter::_FunctionAptActionDefineDictionary (40B)

struct AptActionInterpreter {
    char pad_00[0x34];
    int m_dictPtr;   // 0x34
    int m_dictLen;   // 0x38
};

struct LocalContextT {
    int* m_pc;
};

void AptActionInterpreter_FunctionAptActionDefineDictionary(
    AptActionInterpreter* interp, LocalContextT* ctx)
{
    register int* pc asm("r11") = ctx->m_pc;
    pc = (int*)(((unsigned int)pc + 3) & ~3u);
    ctx->m_pc = (int*)((char*)pc + 8);
    register int w0 asm("r9") = pc[0];
    register int w1 asm("r10") = pc[1];
    interp->m_dictPtr = w0;
    interp->m_dictLen = w1;
}
```

## Verify workflow (MANDATORY)

```bash
bash tools/verify_match.sh \
    --outdir build/verify/apt_<opcode> \
    src/matched/aptactioninterpreter/match_0xADDR_<Name>.cpp \
    0xADDR <size_decimal>
```

Must print `MATCH!` before commit. If it doesn't, iterate on register pins
and statement ordering — do NOT commit partial matches.

## Scope for handoff

There are **112 unmatched** handlers as of 2026-04-20 (of 131 total;
19 already matched as stubs or via other means). The 50 handlers
`_FunctionAptActionAdd/Subtract/Multiply/...` at 0x272bc4+ are 688B
arithmetic templates — these may need different treatment than the
~80B common shape.

**Recommended Kimi pool (small & structured, highest yield):**

- 0x8027DAAC DefineDictionary (40B)      — MATCHED (pioneer 1)
- 0x8027DA60 StoreRegister (76B)         — MATCHED (pioneer 2)
- 0x8027EC04 BranchAlways (96B)          — MATCHED (pioneer 3)
- 0x8027F2DC PushNULL (100B)             — identical body to PushUndefined
- 0x8027F340 PushUndefined (100B)        — same as PushNULL
- 0x8027F62C PushGlobalVariable (100B)   — similar pattern
- 0x80275CB8 StopDragMovie (100B)
- 0x8027AAD4 PushDuplicate (104B)
- 0x8027AB3C StackSwap (112B)
- 0x8027EC04..0x8027ECXX remaining branches (BranchIfTrue etc.)

Scan the DVD map for full address list:
```bash
grep "_FunctionAptAction" extracted/files/u2_ngc_release_dvd.map
```

## Technique library additions

From this track, techniques to codify in `memory/project_sn_compiler.md`:

- **#53** Opcode-handler pin pattern (r11-pc, r9/r10-temps, r3-arg)
- **#54** r0-reuse across branch: pin pcPlus4 to r0 to avoid `addi` duplicate
- **#55** Dual-scheduler-off (`-fno-schedule-insns -fno-schedule-insns2`)
  required for small (<100B) handlers; default OK for >100B per prior session notes
