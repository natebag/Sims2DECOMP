# Decomp Progress — Sims 2 GameCube

## Overview

| Metric | Value |
|--------|-------|
| DOL byte match | **100.000%** (4,644,364 / 4,644,364) |
| Total symbols (map) | 36,913 |
| Functions injected (matching) | 18,539 |
| Portable C++ files | 5,031 |
| Remaining asm stubs | 1,214 (~1,019 now have portable C++ equivalents) |
| Portable C++ lines | ~1,440,844 |
| Asm stub lines | ~1,178,431 |

## DOL Section Match (2026-03-24)

| Section | Size | Match |
|---------|------|-------|
| .init | 960 | **100%** |
| .text | 3,961,920 | **100%** |
| .ctors | 1,056 | **100%** |
| .rodata | 362,688 | **100%** |
| .data | 306,176 | **100%** |
| .sdata | 7,584 | **100%** |
| .sdata2 | 3,980 | **100%** |
| **TOTAL** | **4,644,364** | **100%** |

## Portable C++ Conversion Progress

The DOL match is achieved via byte injection from the original binary.
The real decomp work is converting asm stubs to portable C++ for the PC port.

| Metric | Value |
|--------|-------|
| By file count | 80.8% (5,023 / 6,237) |
| By line count | ~54.6% (1.42M / 2.60M) |
| Remaining asm stubs | 1,214 files (~720 now have portable C++ equivalents) |
| Stubs with portable equiv | ~1,019 (across 2 sessions) |

## By System

| System | Matched | Total | % |
|--------|---------|-------|---|
| Animation | 438 | 471 | 93.0% |
| Audio | 473 | 536 | 88.2% |
| Boot / SDK | 17 | 17 | 100.0% |
| Build Mode | 730 | 837 | 87.2% |
| Camera | 119 | 127 | 93.7% |
| Effects | 112 | 112 | 100.0% |
| Goals | 32 | 34 | 94.1% |
| Inventory | 62 | 65 | 95.4% |
| Memory | 5883 | 5922 | 99.3% |
| Misc | 16669 | 18723 | 89.0% |
| Objects | 553 | 584 | 94.7% |
| Rendering | 986 | 1061 | 92.9% |
| Save | 369 | 397 | 92.9% |
| Sim AI | 1187 | 1389 | 85.5% |
| Skin | 21 | 23 | 91.3% |
| UI / APT | 1216 | 1478 | 82.3% |

## Session Log

### 2026-03-26: Small batch + Effects sweep + Templates + Medium batch
- Converted 51 small asm stubs (39-49 lines) → `small_classes_batch2.cpp` (1,565 lines)
- Converted 27 Effects system stubs → `effects_system_sweep.cpp` (2,344 lines)
- Converted 147 CBMemberTranslator templates → `cb_member_translators.cpp` (1,142 lines)
- Converted 21 STL containers → `stl_containers.cpp` (669 lines)
- Converted 84 medium stubs (50-100 lines) → `medium_classes_batch.cpp` (3,058 lines)
- **Effects system now at 100%** portable C++ coverage
- Total: 330 asm stubs converted, 8,778 lines of portable C++ added

### 2026-03-27: Worktree parallel blitz on 101-500 line stubs
- 4 parallel worktree agents converting medium stubs simultaneously
- Agent 1: ~87 UI/APT stubs → `medium_ui_apt.cpp` (2,157 lines)
- Agent 2: ~102 STL container stubs → `medium_stl_containers.cpp` (1,436 lines)
- Agent 3: ~104 game system stubs → `medium_game_systems.cpp` (2,243 lines)
- Agent 4: ~92 engine/core stubs → `medium_engine_core.cpp` (2,547 lines)
- Total: ~385 asm stubs converted, 8,383 lines of portable C++ added

### 2026-03-27: Worktree blitz on 501-1000 line stubs
- 4 parallel worktree agents converting large stubs
- Batch 1: 28 files (ENodeList, ETweak, AptError, cGZMusic, EPathUtil, etc.) → `large_batch_1.cpp` (1,773 lines)
- Batch 2: 28 files (EAHeap, GoalUnlock, WantFearManager, UI3D, etc.) → `large_batch_2.cpp` (1,763 lines)
- Batch 3: 28 files (StateMachine, EHashTable, FamilyImpl, WorldMap, etc.) → `large_batch_3.cpp` (1,580 lines)
- Batch 4: 30 files (EQuat, EConfig, SimsMemCardWrap, Interaction, etc.) → `large_batch_4.cpp` (3,171 lines)
- Total: 114 asm stubs converted, 8,287 lines of portable C++ added

### 2026-03-27: Worktree blitz on 1001-5000 line stubs
- 4 parallel worktree agents converting extra-large stubs
- Batch 1: 46 files (EFloatTree, RParticle, ERedBlackTree, TreeSimImpl, etc.) → `xl_batch_1.cpp` (3,475 lines)
- Batch 2: 46 files (WantFear, SkinCompositor, ESpriteRender, Room, etc.) → `xl_batch_2.cpp` (3,048 lines)
- Batch 3: 46 files (PlumbBob, EResourceManager, AptValue, EMat4, etc.) → `xl_batch_3.cpp` (4,604 lines)
- Batch 4: 47 files (ESim, EGlobal, BString, ERModel, CameraDirector, etc.) → `xl_batch_4.cpp` (4,169 lines)
- Total: 185 asm stubs converted, 15,296 lines of portable C++ added
- **Running total: ~1,019 of 1,214 stubs now have portable C++ equivalents (83.9%)**
