# S12→S13 Carryover Drafts (SonnetWorker)

These drafts didn't fully match before the S12 wind-down. Preserved for S13 retry with permuter or asm-processor.

## draft_0x80352364_Effects__EffectsManager__GetSingleton.cpp
Lazy singleton at SDA-relative `s_inst` (-25880(r13)).
Pattern: `if (!s_inst) s_inst = new EffectsManager(); return s_inst;`
Uses `__builtin_new(28)` for sizeof allocation.

**Status:** MISMATCH — likely register choice / instruction order. Not iterated due to wind-down.

**Retry plan:** Try register pin on `r3` for the loaded singleton, or rewrite as ternary.
