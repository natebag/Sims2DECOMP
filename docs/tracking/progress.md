# Decomp Progress — Sims 2 GameCube

## HONEST STATUS

**Functions actually decompiled (hand-written C++ that compiles to matching bytes): 8,447 / 20,508 (41.2%)**

Real progress = functions with hand-written C++ that the SN Systems compiler
produces byte-identical output for. Verified by verify_match.sh.

Last audit: **Full exhaustive audit (2026-04-10)** — every file in src/matched/
verified via 4-way parallel compile-and-compare. 8,447 of 9,321 files PASS.
848 failures relocated to src/wip/version_diff/. 20 garbage temp files deleted.

## Overview

| Metric | Value |
|--------|-------|
| Total code functions | 20,508 |
| **Functions ACTUALLY decompiled** | **8,447 (41.2%)** |
| Functions remaining | 12,061 |
| Original compiler | SN Systems ProDG GCC 2.95.3 (found & working) |
| Total symbols (map) | 39,169 |
| Translation units (original .cpp files) | 519 |
| Class struct layouts documented | 643 |
| Anti-cheat guard | verify_match.sh rejects inline asm fakes |

## Milestone Status

| # | Milestone | Status | Notes |
|---|-----------|--------|-------|
| 1 | Infrastructure | **DONE** | Build system, dtk, symbols, CI, SN compiler |
| 2 | Scaffolding | **DONE** | Empty C++ shells, struct layouts |
| 3 | Actual Decomp | **IN PROGRESS** | 8,447/20,508 (41.2%) |
| 4 | PC Port | **BLOCKED** | Needs actual decomp first |

## Progress by Function Size

| Tier | Matched | Total | % |
|------|---------|-------|---|
| 0-8B | 2,017 | 2,166 | 93.1% |
| 9-16B | 577 | 1,035 | 55.7% |
| 17-32B | 381 | 1,373 | 27.7% |
| 33-64B | 624 | 3,583 | 17.4% |
| 65-128B | 310 | 4,725 | 6.6% |
| 129-256B | 42 | 3,105 | 1.4% |
| 257-512B | 18 | 2,273 | 0.8% |
| 513B+ | 65 | 2,243 | 2.9% |

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

## Portable C++ Conversion — COMPLETE

All 1,214 asm stub files now have portable C++ equivalents. The DOL match is
achieved via byte injection; the portable C++ enables the PC port.

| Metric | Value |
|--------|-------|
| Asm stubs converted | **1,214 / 1,214 (100%)** |
| By file count | 80.8% (5,023 / 6,237 total source files) |
| By line count | ~55.3% (1.47M / 2.64M lines) |

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

### 2026-04-10: FULL EXHAUSTIVE AUDIT — definitive verified count established
- **Audit-only session** — no matching work, pure verification
- **Method:** 4-way parallel compile-and-compare via batch_audit.py + verify_match.sh
- **All 9,321 files in src/matched/ audited exhaustively** (not sampled)
- **Primary audit:** 7,938 PASS, 631 MISMATCH, 149 SIZE_MISMATCH, 63 OTHER, 540 SKIP
- **Secondary audit (SKIP recovery):** 509 additional PASS from trivial functions with inferred sizes
- **Total verified PASS: 8,447** → 41.2% of 20,508
- **Previous reported: 9,192 (44.8%)** → 745 files inflated (8.1%)
- **Cleanup:** 848 failures relocated to src/wip/version_diff/, 20 garbage _clean.cpp files deleted
- **Directory breakdown:** agent/ 84.8%, cbmt_blast/ 100%, global_getters/ 65.3%
- **Tooling review:** verify_match.sh PASS count is trustworthy; set -e bug only affects failure categorization
- **Key insight:** Inflation came from pre-hook era when files could be committed without verification
- **Workflow gap closed:** pre-commit hook (80f3ec9d) prevents future orphans

### 2026-04-05: AgentOrch v3.93 pattern grinder + goldmine discovery
- **Before session:** 6,161 verified matches (30.0%)
- **After session:** 6,255 verified matches (30.5%)
- **Net new:** +94 matches
- **Goldmine discovery:** 3,074 "dark" functions found not in asm_decomp
- **~80 trivial 4B/8B matches** from goldmine (SonnetWorker auto-generator)
- **15 InteractorModule 65-128B matches** (SonnetWorker2)
- **8 cXObjectImpl 65-128B at 53% rate** (OpusWorker with `lwz r11` filter)
- **5 EBitArray constructors** (KimiGuy)
- **3 AptActionInterpreter + ObjectFolderImpl** (SonnetWorker)
- **6 pre-commit hook blocked** (fake/mismatched files rejected)
- **12 duplicates cleaned up** during session
- **500+ functions triaged as VERSION_DIFF** (need v1.76 compiler)
- **Key finding:** <=64B in asm_decomp now 100% cleared
- **65-128B match rate:** ~5% (Kimi) to 53% (Opus with r11 filter)
- **Bottleneck identified:** v1.76 compiler needed for remaining ~14,253 functions
- **Pre-commit hook installed:** Catches bad files automatically before commit
- **Tools built:** classify_functions.py, count_matched.py, find_missing_functions.py, scan_v393_pattern.py, count_new_matches.py

### 2026-04-03: AgentOrch grinder session — batch matching + quality cleanup
- AgentOrch multi-agent session: 1 opus, 2 sonnet, 3 haiku, 3 kimi workers
- OpusWorker: ~400 verified unique matches (destructors, constructors, COM patterns, trivials)
- Proven portable patterns: Release (92B, 36 classes), QueryInterface (112B, 19 classes), AddRef (20-28B, 29 classes)
- Discovered SN ProDG member init order quirk (reverses field order relative to vtable)
- **Massive duplicate cleanup**: 2,934 duplicate files removed across agent/trivial/trivial_batch2/global_getters directories
- Previous count of 7,701 was inflated — real deduplicated count: **6,118 (29.8%)**
- Verification audit: 20/20 random files passed verify_match.sh (100% pass rate)
- Batch matching hitting diminishing returns — remaining functions need per-function analysis
- Progress: ~5,700 → ~6,118 (+418 real new unique matches)

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

### 2026-03-27: Big Fish conversion (5K-40K line stubs)
- 4 parallel worktree agents tackling the largest remaining files
- Batch 1: 8 files (XRoute, ESimsCam, Effects, AptDate, etc.) → `bigfish_batch_1.cpp` (1,755 lines)
- Batch 2: 8 files (EA, StringPool, ISimsObjectModel, ObjectFolderImpl, etc.) → `bigfish_batch_2.cpp` (2,067 lines)
- Batch 3: 8 files (ERLevel, INVTarget, EAnimController, static_init, etc.) → `bigfish_batch_3.cpp` (2,159 lines)
- Batch 4: 6 files (ENgcRenderer, SAnimator2, cXPersonImpl, AptActionInterpreter, cXObjectImpl, InteractorModule) → `bigfish_batch_4.cpp` (5,703 lines)
- Total: 30 Big Fish stubs converted, 11,684 lines, 942+ functions cataloged
- **Running total: ~1,182 of 1,214 stubs (97.4%) — only global.cpp (230K) remains as the sole unconverted mega-file**

### 2026-03-27: FINAL BOSS — global.cpp (230K lines, 1,970 functions)
- 4 parallel worktree agents each handling ~495 functions
- Chunk 1: Functions 1-494 (APT callbacks, frame effects, wall utils, BString ops, math, XML, C runtime) → `global_chunk_1.cpp` (4,409 lines)
- Chunk 2: Functions 495-988 (DolphinSDK: OS, EXI, SI, DVD, VI, PAD, AI, APT engine, VEC math) → `global_chunk_2.cpp` (3,011 lines)
- Chunk 3: Functions 989-1482 (heap singletons, stream ops, printf, particles, image processing, main(), THP, matrix, ARAM, AX audio, CARD) → `global_chunk_3.cpp` (3,616 lines)
- Chunk 4: Functions 1483-1970 (CARD, GX graphics, VM, THP decoder, STL templates, serialization) → `global_chunk_4.cpp` (1,934 lines)
- Total: 1,970 functions cataloged, 12,970 lines of portable C++
- **100% OF ALL ASM STUBS NOW HAVE PORTABLE C++ EQUIVALENTS**

### 2026-03-27: PC Port — Game State Machine + Texture Pipeline
- PC game state machine: BOOT → LOGO → MAIN_MENU → LOADING → GAMEPLAY
- Real game textures rendering via OpenGL:
  - maxis_logo_black_clean (256x256 C8_32)
  - team_picture (512x512 CMPR/S3TC)
  - ui_start_screen (256x256 CMPR)
  - ui_logo256_english_light (256x256 C8_32)
- Arc reader fully fixed: textures.arc 207→11,443 entries, models.arc 931→3,631
- EA texture auto-detect: variable-length prefix detection (1-8 bytes)
- GC texture decode: C8_32 (indexed) and CMPR (S3TC) formats working
- Interactive menus with input handling (keyboard→PAD mapping)
- operator_new_wrapper/delete_wrapper fixed (enables decomp code on PC)
- Vector font system for on-screen text rendering
