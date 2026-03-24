# Decomp Progress — Sims 2 GameCube

## Overview

| Metric | Value |
|--------|-------|
| DOL byte match | **100.000%** (4,644,364 / 4,644,364) |
| Total symbols (map) | 36,913 |
| Functions injected (matching) | 18,539 |
| Portable C++ files | 5,012 |
| Remaining asm stubs | 1,214 |
| Portable C++ lines | ~1,396,190 |
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
| By file count | 80.5% (5,012 / 6,226) |
| By line count | ~54% (1.4M / 2.57M) |
| Remaining asm stubs | 1,214 files |

## By System

| System | Matched | Total | % |
|--------|---------|-------|---|
| Animation | 438 | 471 | 93.0% |
| Audio | 473 | 536 | 88.2% |
| Boot / SDK | 17 | 17 | 100.0% |
| Build Mode | 730 | 837 | 87.2% |
| Camera | 119 | 127 | 93.7% |
| Effects | 96 | 112 | 85.7% |
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
