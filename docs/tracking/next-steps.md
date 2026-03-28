# Next Steps — Sims 2 GC Decompilation

**Current focus: ACTUALLY DECOMPILING FUNCTIONS**

Last updated: 2026-03-27

---

## THE REAL WORK: Function-by-Function Matching

Every function needs hand-written C++ that compiles to byte-identical PPC output.
Currently: ~5 matched out of 18,539. This is the core decomp work.

### Phase 1: Trivial Functions (target: 500+)

8-byte getter/setter functions. Pattern: load a field, return it.

Example (already matched):
```cpp
// 0x801A23BC (8 bytes)
int ACTTarget::IsActionQueueActive() {
    return *(int*)((char*)this + 0xD0);
}
```

**Functions to match:**
- [ ] ESimsApp::GetStartLot (8B) — `lwz r3, -32752(r13); blr`
- [ ] ESimsApp::GetDefaultLanguage (8B) — `li r3, 0; blr`
- [ ] ESimsApp::SetGameState (8B) — `stw r4, 0x468(r3); blr`
- [ ] ESimsApp::GetEventTableSize (8B) — `li r3, 0; blr`
- [ ] AptViewer::UIOn (8B)
- [ ] AptViewer::IsReadControllerActive (8B)
- [ ] AwarenessManager::SetIsRaining (8B)
- [ ] AwarenessManager::GetAwarenessAction (8B)
- [ ] AwarenessManager::GetStateFlags (8B)
- [ ] ~490 more 8-byte functions from the map file
- [ ] ~1000+ 12-20 byte functions (constant returns, simple stores)

### Phase 2: Small Functions with Pseudocode (target: 2000+)

Functions 20-100 bytes where we have pseudocode from esimsapp_decomp.cpp
and other analysis files. Write the C++, compile, compare.

### Phase 3: Medium Functions (target: 5000+)

Functions 100-500 bytes. Need Ghidra analysis of the disassembly.

### Phase 4: Large Functions (target: remaining ~10,000)

Functions 500+ bytes. Complex control flow, vtable dispatch, etc.

---

## Workflow for Matching a Function

```bash
# 1. Find the function in the map file
grep "FunctionName" extracted/files/u2_ngc_release.map

# 2. Look at the disassembly in the asm_decomp file or Ghidra
cat src/asm_decomp/ClassName.cpp | grep -A 50 "FunctionName"

# 3. Write C++ in src/matched/ClassName_matched.cpp

# 4. Compile with devkitPPC
make compile

# 5. Compare bytes against DOL
python tools/check_func.py src/matched/ClassName_matched.cpp FunctionName

# 6. If match: inject into skeleton
python tools/inject_matches.py --rebuild --verify

# 7. Verify full DOL still matches
make diff
```

---

## Agent Army Strategy

For parallelizing decomp work across multiple AI agents:

1. Each agent gets: function name, address, size, disassembly bytes, class header, struct layout
2. Agent writes C++ that should produce the same output
3. Agent compiles with devkitPPC and compares bytes
4. If match → commit. If not → iterate or flag for human review.

See docs/specs/agent-decomp-strategy.md for the full plan.

---

## GCC vs SN Systems Problem

The original game was compiled with SN Systems ProDG (proprietary, discontinued).
We use devkitPPC (GCC). Flag sweep shows 47% byte-exact match rate.

The other 53% of functions need:
- Inline assembly hints for register allocation
- Compiler-specific workarounds
- Or acceptance that some functions can't match with GCC

This is the hardest part of the project.

---

## PC Port (ON HOLD)

The PC port prototype (`src/platform/pc/`) exists but is parked until real decomp
progress is made. The game code can't run because all function bodies are empty.
The port will become viable once substantial decomp work is done.
