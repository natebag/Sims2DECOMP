# Memory Management

## Overview

The Sims 2 GC uses EA's PPMalloc (GeneralAllocator) wrapped in a custom `EAHeap` class with a three-tier allocation strategy. A pool allocator handles small blocks, the GeneralAllocator handles medium/large blocks, and a heap hierarchy provides overflow fallback.

## Key Classes

- **EAHeap** (0x538 bytes) -- Top-level allocator. Inherits from `EA::Allocator::GeneralAllocator` (0x528 bytes base). Adds name, parent heap, aux heap, and checkpoint ID fields.
- **FastAllocPool** -- Fixed-size block pool using a free list. Uses `DESU` (0x44455355) and `EERF` (0x45455246) magic values to tag allocated and freed blocks.
- **ProtectedAllocPool** -- Thread-safe wrapper around FastAllocPool with mutex locking.
- **AllocPoolManager\<T\>** -- Manages 8 size classes for pool allocation (blocks <= 64 bytes).

## Three-Tier Allocation (EAHeap::Malloc, 0x802D0AA4)

1. **Tier 1 -- Pool Allocator**: For allocations <= 64 bytes (8 size classes). Skipped for DebugHeap. Pops from free list, tags with `DESU` magic.
2. **Tier 2 -- GeneralAllocator**: PPMalloc for sizes > 64 bytes or when pool is exhausted.
3. **Tier 3 -- Heap Hierarchy**: If this heap fails, try `m_parentHeap`, then `m_auxHeap` recursively.

## Heap Hierarchy (13 Named Heaps)

```
RootHeap        -- Top of hierarchy, fallback for all others
  MainHeap      -- General game allocations
  ResourceHeap  -- Asset/resource data
  AudioHeap     -- Sound buffers and mixing
  VMHeap        -- Virtual machine / scripting
  ShaderHeap    -- Shader data
  TextureHeap   -- Texture memory
  AnimationHeap -- Animation data
  ModelHeap     -- 3D model data
  FlashesHeap   -- APT/Flash UI data
  AptHeap       -- APT engine allocations
  DebugHeap     -- Debug allocations (skips pool tier)
  CUIHeap       -- Console UI allocations
```

Each heap has a global singleton accessor (e.g., `RootHeap()`, `MainHeap()`).

## Important Functions

| Function | Address | Size | Notes |
|----------|---------|------|-------|
| `EAHeap::EAHeap` | 0x802D09DC | 128 | Constructor: init GA, store name/parent/aux |
| `EAHeap::Init` | 0x802D0A5C | 72 | Initialize with memory region |
| `EAHeap::Malloc` | 0x802D0AA4 | 204 | Three-tier allocation |
| `EAHeap::MallocAligned` | 0x802D0B70 | 276 | Aligned allocation, falls to Malloc if align <= 8 |
| `EAHeap::Calloc` | 0x802D0C84 | 244 | Allocate + zero (pool allocs zeroed with memset) |
| `EAHeap::Free` | 0x802D0D78 | 176 | Check pool first, then find owning heap |
| `EAHeap::Compact` | 0x802D0E28 | 96 | Coalesce free chunks in GeneralAllocator |
| `EAHeap::Clear` | 0x802D0E88 | 76 | Reset checkpoint, disable high alloc + debug checks |
| `FastAllocPool::Alloc` | 0x802D7374 | 40 | Pop from free list, tag DESU |
| `FastAllocPool::Free` | 0x802D739C | 36 | Push to free list, tag EERF |
| `FastAllocPool::BlockIsInPool` | 0x802D7340 | 52 | Range check against pool bounds |

## Quirks

- **DebugHeap bypass**: DebugHeap skips Tier 1 (pool allocation) entirely. This prevents debug allocations from consuming pool blocks needed by the game.
- **Two-round compaction**: `ShowInitialDisplay()` compacts all 13 heaps twice after init to maximize contiguous free memory.
- **Malloc failure callbacks**: Each heap has a registered failure callback (e.g., `MallocFailureCallback_Root`) that fires when the GeneralAllocator runs out of memory, triggering fallback behavior.
- **GA options**: `Clear()` disables `kOptionEnableHighAllocation` (option 2) and `kOptionEnableDebugChecks` (option 10) on every heap reset.

## Relationships

- EAHeap is initialized during `ESimsApp::Init()` as one of the first subsystems
- All other systems allocate through the heap hierarchy
- `EResourceManager` uses dedicated heaps (ResourceHeap, TextureHeap, etc.) for asset data
- `FastAllocPool` is used by `ProtectedAllocPool` which is managed by `AllocPoolManager`
