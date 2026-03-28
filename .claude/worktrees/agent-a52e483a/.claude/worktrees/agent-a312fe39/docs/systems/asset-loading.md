# Asset Loading

## Overview

The Sims 2 GC uses a reference-counted resource system built on `EResource` and `EResourceManager`. Assets are loaded from `.arc` archives (RefPack compressed), `.NGH` neighborhood files, and IFF containers. An async loader (`EResourceLoaderImpl`) handles DVD streaming.

## Key Classes

- **EResource** (0x14 bytes) -- Base reference-counted resource. Fields: vtable, m_pManager, m_resId, m_refCount, m_flags, m_resSize. Default refcount is 1, default size is 128.
- **EResourceManager** -- Central registry for all loaded resources. Manages refcounting, lookup by ID, and heap allocation.
- **EResourceLoaderImpl** -- Async resource loading coordinator. Queues load commands, manages DVD read threads.
- **ERShader** (0x17BC bytes) -- Shader resource wrapping EShader(s). Manages day/night blending, multi-shader states, and texture swapping.
- **ERTexture** (~0x28 bytes) -- Texture resource wrapper around ETexture. Released via ETextureManager.
- **ERFont** -- Bitmap font resource.
- **ETexture** (0x28 bytes) -- Platform-agnostic texture description: format, dimensions, palette info, platform texture pointer.
- **NghResFile** -- Neighborhood save/load handler for .NGH format.
- **ChainResFile** -- Multi-file resource chaining.
- **IFFResFile2** -- IFF container parser (shared format with PC Sims).
- **ArcFileInfo** / **ArcCopier** -- .arc archive extraction and decompression.

## Resource Lifecycle

```
EResource_Ctor()     -- refcount = 1, size = 128
  -> EResource_AddRef()  -- increment refcount (managed: delegate to manager)
  -> EResource_DelRef()  -- decrement refcount (managed: delegate to manager)
                          -- if unmanaged and refcount hits 0: virtual SafeDelete
  -> EResource_Dtor()    -- notify manager, cleanup, conditional scalar-delete
```

## Important Functions

| Function | Address | Size | Notes |
|----------|---------|------|-------|
| `EResource::EResource` | 0x80311DC8 | 48 | Init vtable, refcount=1, size=128 |
| `EResource::~EResource` | 0x80311DF8 | 108 | Notify manager, restore parent vtable |
| `EResource::AddRef` | 0x80312000 | 64 | Managed: delegate; unmanaged: local increment |
| `EResource::DelRef` | 0x80311F70 | 104 | Managed: delegate; unmanaged: decrement, SafeDelete at 0 |
| `EResource::SafeDelete` | 0x80312158 | 64 | Virtual dispatch through vtable offset 0x30 |
| `EResource::Write` | 0x80311E64 | 84 | Write type name "EResource" to stream |
| `EResource::Read` | 0x80311EB8 | 92 | Read from stream (skips if binary load) |
| `ERShader::ERShader` | 0x8031C6DC | 196 | Init 20+ shader fields, timeOfDay = -1.0f |
| `ERShader::Select` | 0x80320904 | 96 | Resolve EShader, dispatch to platform shader |
| `ERShader::IsDayNightShader` | 0x80320750 | 12 | Check bit 5 of m_flags |
| `ERShader::IsMultiShader` | 0x80320860 | 12 | Check bit 1 of m_flags |
| `ERTexture::ERTexture` | 0x80320B28 | 68 | Init base + null texture pointer |
| `ERTexture::Deallocate` | 0x80320C00 | 80 | Release via ETextureManager |
| `ERTexture::Load` | 0x80320D00 | 240 | Open TXFL signature, version 9 |

## Archive Formats

- **.arc** -- EA archive format with RefPack compression. Contains game assets (textures, models, sounds).
- **.NGH** -- Neighborhood save file. Custom tagged binary format with section headers for families, lots, and sim data.
- **IFF** -- Interchange File Format containers inherited from the PC Sims codebase. Used for behavior trees, object definitions, and slot descriptions.

## Binary Load Path

A global flag `g_useBinaryLoad` (at 0x804FCD4E) controls whether resources use a binary fast path (skipping text stream parsing) or the slower stream-based path. Release builds use binary load.

## Quirks

- **SN Systems ABI**: Destructors use a hidden parameter where bit 0 controls scalar-delete (memory freeing). This is the SN Systems calling convention, not the Itanium ABI used by GCC.
- **ERShader timeOfDay**: Initialized to -1.0f (no time selected). The day/night system updates this to control shader blending between day and night variants.
- **ERShader flags** (offset 0x058): Bit 1 = multi-shader, bit 4 = state change pending, bit 5 = day/night shader.
- **Texture invalidation cycle**: ERTexture::Refresh invalidates the GX texture cache, reloads from file, then revalidates -- ensures no stale GPU state.

## Relationships

- All resources allocate from dedicated heaps (ResourceHeap, TextureHeap, ShaderHeap, etc.)
- EResourceManager is initialized during ESimsApp::Init
- ERShader references ETexture via ETextureManager for GPU texture binding
- NghResFile is loaded when entering a neighborhood (via ESimsApp::SetNghName)
- Async loading uses EThread and ESemaphore for DVD read coordination
