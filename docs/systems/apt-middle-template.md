# APT Middle-Pool Opcode Handler Template (100-200B)

**Session 12 — OpusWorker Track C middle-pool pioneer pass.**

For APT opcode handlers in the 100-200B range. Covers push-family
(PushNULL/PushUndefined/PushGlobalVariable), stack-manipulation
(PushDuplicate/StackSwap), and conditional-vcall shapes
(StopDragMovie/StartDragMovie).

## Pioneer results

| # | Address    | Name            | Size | Technique |
|---|------------|-----------------|------|-----------|
| 1 | 0x8027F2DC | PushNULL        | 100B | Push-MI-vcall |
| 2 | 0x8027AAD4 | PushDuplicate   | 104B | Read-top + push |
| 3 | 0x80275CB8 | StopDragMovie   | 100B | Conditional-MI-vcall |

All three MATCH with **default scheduling** (no FLAGS comment needed).
This is the CRITICAL difference from the <100B template which requires
`-fno-schedule-insns -fno-schedule-insns2`.

## Recipe — step by step

### 1. Default scheduling — NO FLAGS line

```cpp
// 0xADDRESS AptActionInterpreter::_FunctionAptAction<Op> (SIZEb)
```

Do NOT add `// FLAGS: -fno-schedule-insns -fno-schedule-insns2` for these.
The SN scheduler for 100-200B functions matches GCC's default scheduling.
Adding dual-off causes mismatches.

### 2. Register pin conventions for middle pool

| Role                       | Register |
|----------------------------|----------|
| Stack index `sp`           | r9 (Push) or r10 (Duplicate) |
| Stack base (as int)        | r8 (Push) or r7 (Duplicate) |
| `sp * 4`                   | r11 (Push) or r8 (Duplicate) |
| Pushed value / token       | r10 (Push) or r11 (Duplicate) |
| Manager/singleton          | r9 (conditional-vcall) |

### 3. Technique #57 — stwx/add operand-order control

PPC's `stwx rS, rA, rB` uses EA = rA + rB. Both orderings are
semantically equivalent but encode differently. DOL uses `rA=sp4, rB=stack`;
GCC canonicalizes `ptr + int` to `rA=ptr, rB=int` (opposite order).

**Fix:** convert the stack-base pointer to an int BEFORE the addition:

```cpp
register int stackInt asm("r8") = (int)interp->m_stack;
register int sp4 asm("r11") = sp << 2;
*(u8**)(sp4 + stackInt) = val;      // now int + int, GCC picks (r11, r8)
```

Same trick works for `add rD, rA, rB` in vals like `stack[sp-1]`:

```cpp
register u8* val = *(u8**)(sp4 + stackInt - 4);  // computes base first
```

### 4. Technique #58 — Middle-pool MI-vcall dispatch

```cpp
char* vt = *(char**)((char*)val + 8);   // val->field_at_8 is vtable ptr
short thisOff = *(short*)(vt + N);       // adjustor offset  (N varies)
fn_t fn = *(fn_t*)(vt + N + 4);          // fn slot  (usually +4 from adjustor)
fn((char*)val + thisOff, ...);
```

Vtable offsets vary per class:

| Class                      | Offset |
|----------------------------|--------|
| AptValue (Push*)           | 8/12   |
| DragTarget (StopDragMovie) | 16/20  |

Inspect the DOL's `lha rX, N(r9)` addend to pick the right N.

### 5. Technique #59 — Non-SDA abs-addr string args

APT handlers pass file:line debug string pointers as arguments. These
live at absolute addresses (0x80401680, 0x80401CF0, etc.) outside SDA.

```cpp
extern char g_dbgStr1680[16];   // abs 0x80401680
```

Compiler emits `R_PPC_ADDR16_HA + R_PPC_ADDR16_LO` reloc pair
(`lis r4,hi; addi r4,r4,lo`) — exactly DOL's shape. Sized char array
(>8B) forces non-SDA placement.

### 6. Worked example: minimal push handler (PushNULL, 100B)

```cpp
// 0x8027F2DC AptActionInterpreter::_FunctionAptActionPushNULL (100B)

typedef unsigned char u8;
extern u8* g_aptActionGlobal;       // SDA
extern char g_aptDbgStr1680[16];    // abs
extern char g_aptDbgStr16B4[16];    // abs

struct AptActionInterpreter {
    int m_stackIdx;
    char pad_04[4];
    u8** m_stack;

    struct LocalContextT { int* m_pc; };

    static void _FunctionAptActionPushNULL(AptActionInterpreter* interp, LocalContextT* ctx);
};

void AptActionInterpreter::_FunctionAptActionPushNULL(
    AptActionInterpreter* interp, LocalContextT* ctx)
{
    register int sp asm("r9") = interp->m_stackIdx;
    register u8* val asm("r10") = g_aptActionGlobal;
    register u8** stack asm("r8") = interp->m_stack;
    register int sp4 asm("r11") = sp << 2;
    sp = sp + 1;
    register int stackInt asm("r8") = (int)stack;
    *(u8**)(sp4 + stackInt) = val;
    interp->m_stackIdx = sp;
    char* vt = *(char**)((char*)val + 8);
    short thisOff = *(short*)(vt + 8);
    void (*fn)(void*, char*, char*, int) =
        *(void(**)(void*, char*, char*, int))(vt + 12);
    fn((char*)val + thisOff, g_aptDbgStr1680, g_aptDbgStr16B4, 138);
}
```

## Worked example: conditional-vcall handler (StopDragMovie, 100B)

```cpp
void AptActionInterpreter::_FunctionAptActionStopDragMovie(
    AptActionInterpreter* interp, LocalContextT* ctx)
{
    register u8* mgr asm("r9") = g_aptDragTarget;
    register u8* drag asm("r11") = *(u8**)((char*)mgr + 60);
    if (drag != 0) {
        char* vt = *(char**)((char*)drag + 8);
        short thisOff = *(short*)(vt + 16);      // note: 16/20 not 8/12
        void (*fn)(void*, char*, char*, int) =
            *(void(**)(void*, char*, char*, int))(vt + 20);
        fn((char*)drag + thisOff, g_dragDbgStr1CF0, g_dragDbgStr1844, 4686);
    }
    u8* mgr2 = g_aptDragTarget;
    u8* nullTok = g_aptActionGlobal;
    *(u8**)((char*)mgr2 + 60) = nullTok;
}
```

Key: reload the SDA manager AFTER the conditional branch (the second
`g_aptDragTarget` read). Compiler may CSE/hoist if you use one local
variable — use two separate expressions for the two reads.

## Verify workflow

```bash
bash tools/verify_match.sh \
    --outdir build/verify/apt_mid_<opcode> \
    src/matched/aptactioninterpreter/match_0xADDR_AptActionInterpreter__FunctionAptAction<Op>.cpp \
    0xADDR <size_decimal>
```

Must print `MATCH!` before commit. Pre-commit hook also enforces.

## Scope — 100-200B middle pool

Candidate pool from DVD map `_FunctionAptAction*` symbols in 100-200B size:

- 0x8027F2DC PushNULL ✅ matched
- 0x8027F340 PushUndefined (100B) — same body as PushNULL
- 0x8027F62C PushGlobalVariable (100B)
- 0x80275CB8 StopDragMovie ✅ matched
- 0x8027AAD4 PushDuplicate ✅ matched
- 0x8027AB3C StackSwap (112B)
- ~10 more handlers in 100-130B range

Kimi blast rate estimate: 10-15 min per handler (template slot-fill, register
pin re-tune based on DOL disasm).

## Technique cross-reference

- #53/#54/#55 — <100B dual-scheduler-off template (separate doc)
- **#57** — stwx/add operand-order control (int+int arithmetic)
- **#58** — middle-pool MI-vcall dispatch (vt at val+8, per-class offsets)
- **#59** — non-SDA abs-addr string args via `extern char g[16]`
- **#56** — MI-vcall via p+4 secondary vtable (InteractorModule family, separate doc)
