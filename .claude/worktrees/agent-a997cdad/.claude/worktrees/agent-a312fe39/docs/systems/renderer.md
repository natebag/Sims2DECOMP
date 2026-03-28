# Renderer

## Overview

The Sims 2 GC renderer is built on the GameCube's GX graphics library. `ENgcRenderer` is the platform-specific renderer that translates the engine's display list commands into GX hardware calls. It uses a command dispatch table, TEV stage configuration for shaders, and a render state cache for performance.

## Key Classes

- **ENgcRenderer** -- Main renderer. Processes display list (EDL) commands via a 75-entry opcode dispatch table. Manages frame timing, viewport state, and render passes.
- **ENgcRC** -- NGC Render Context. Extended vtable at offset 0x70 for platform-specific dispatch.
- **ERC** -- Base render context passed through the rendering pipeline.
- **EDL** / **EDLEntry** -- Display list and display list entries. The engine builds a display list each frame that the renderer processes.
- **ENgcShader** (0xF4 bytes) -- GX hardware shader. Directly configures TEV pipeline stages with color/alpha inputs.
- **ENgcRenderStateCache** -- Caches GX render state to minimize redundant hardware writes.
- **ENgcTexture** / **ENgcTextureBase** -- NGC-specific texture objects wrapping GXTexObj.
- **ESubModelShader** -- Per-sub-model shader binding for multi-material meshes.

## ENgcShader TEV Configuration

The GX TEV (Texture Environment) pipeline is configured per-shader:

```
Offset 0x00: m_numTEVStages (u8)   -- 1 or 2 stages
Offset 0x04: m_texGenCount
Offset 0x08: m_gxFlags
Offset 0x0C: m_blendSrc / 0x10: m_blendDst
Offset 0x14: m_alphaCompare
Offset 0x64: TEV stage 0 params (60 bytes)
Offset 0x80: TEV stage 0 color inputs (4 x u8)
Offset 0xA4: TEV stage 1 params (60 bytes)
Offset 0xC0: TEV stage 1 color inputs (4 x u8)
Offset 0xF0: m_pPlatformData
```

ENgcShader::Create (0x8034DE0C, 372 bytes) validates TEV configurations and can optimize 2-stage shaders down to 1 stage when the color input patterns match known configurations (packed values 0x4A, 0x5A, 0x6A for color; 0x44, 0x48, 0x64, 0x68 for alpha).

## Important Functions

| Function | Address | Size | Notes |
|----------|---------|------|-------|
| `ENgcShader::Create` | 0x8034DE0C | 372 | Validate TEV config, optimize 2-stage to 1-stage |
| `ENgcShader::Select` | 0x8034DC98 | 164 | Configure TEV stages via ERC extended vtable |
| `ERShader::Select` | 0x80320904 | 96 | Resolve EShader chain, dispatch to platform shader |
| `EResource::EResource` | 0x80311DC8 | 48 | Base resource init (refcount=1) |
| `ETexture::ETexture` | 0x807E9188 | 156 | Zero all texture fields |
| `ETexture::IsValid` | 0x807EAE8C | 64 | Check m_pPlatformTex != 0 |

## Global Renderer State

Key globals (r13-relative SDA access):
- `_pRend` -- Global renderer pointer
- `g_videoMode` -- 1 = progressive/480p
- `g_targetFrameRate` -- Target FPS
- `g_frameCounter` -- Frame count
- `g_polyCount` / `g_drawCallCount` / `g_batchCount` -- Per-frame stats
- `g_projectionMatrix[16]` -- Current projection matrix
- `g_compareTable[8]` -- GX compare function lookup (NEVER..ALWAYS)

## Render Pipeline Per Frame

1. `ENgcRenderer::BeginRenderPass(player)` -- Set up viewport for player
2. `DrawGame(rc)` -- Traverse scene, build display list, draw
3. `StateMachineManager::DrawTopmostMachines(rc)` -- Loading screens, overlays
4. `GameData::CopyrightDraw(rc)` -- Legal text overlay
5. `ENgcRenderer::EndRenderPass(rc)` -- Swap buffers

For split-screen, steps 1-4 repeat per player with different viewports.

## PC Port Notes

21 GX-to-OpenGL translation notes were documented during decompilation:
- GX TEV stages map to fragment shader texture combiners
- GX's fixed-function lighting maps to uniform-based lighting
- GX write-gather pipe (0xCC010000) has no direct equivalent -- replaced by command buffers
- Paired-single instructions (PS) for vertex transforms need SSE/NEON equivalents
- GX display lists map to OpenGL VAOs or Vulkan command buffers

## Quirks

- **TEV optimization**: ENgcShader::Create checks if a 2-stage shader can be reduced to 1 stage by examining packed color input patterns. This saves GPU bandwidth.
- **Render state cache**: ENgcRenderStateCache saves/restores GX state to avoid redundant hardware register writes. Critical for performance on GX.
- **Tiled screenshots**: ESimsApp::UpdateDraw supports tiled high-resolution screenshots by rendering the scene multiple times with different viewport offsets.
- **SDA for GX state**: The GX internal state struct is accessed via r13 - 17720 (SDA offset). Many GX functions cannot be compiled as pure C because they need this SDA-relative access.

## Relationships

- ENgcRenderer is initialized during ESimsApp::Init
- Shaders (ERShader -> EShader -> ENgcShader) configure the TEV pipeline
- Textures (ERTexture -> ETexture -> ENgcTexture) bind via GXTexObj
- Display lists (EDL) are built by the scene traversal and consumed by the renderer
- Frame effects (Bloom, MotionBlur, DepthOfField) post-process the framebuffer after the main render pass
