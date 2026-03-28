# Failed Matches — Functions to Revisit

Functions that agents attempted but couldn't match. Organized by failure reason.
These are our "come back later" list.

## Compiler Version Mismatch (SN v3.93 vs EA's build version)

Functions where the SN compiler produces correct logic but different
branch scheduling or instruction ordering. May need the exact compiler
version EA used, or NON_MATCHING annotation.

(Agents: add entries here as you find them)

## Relocation Issues (bl/b targets differ in .o vs DOL)

Functions that call other functions — the branch offsets in standalone .o
files differ from the linked DOL. The relocation masking in verify_match.sh
handles some of these, but complex call patterns still fail.

## Multiple Return Paths

Functions with complex control flow (multiple if/else chains, early returns)
where the compiler schedules branches differently.

## Unknown Failures

Functions that failed for unclear reasons — need manual investigation.

- `0x80014028` `AwarenessManager::GetPlayerObject(int)`
  Best C++ attempt came very close but did not match the original branch ordering. Current mismatch points:
  original wants `slwi` before the `addi 0x5DCC`, an explicit `li r3,0`, and `beqlr cr1`; generated code kept the same logic but scheduled those pieces differently.
  Restored the file to its raw-byte body instead of landing a wrong C++ version.

---

Last updated: 2026-03-28
Total matched: 5,544 / 20,508 (27.0%)
Total remaining: ~14,964
