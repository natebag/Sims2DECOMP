# DolphinSDK Wrappers

## Overview

The Sims 2 GC statically links DolphinSDK 1.0 HW2 into the executable. These are the standard Nintendo-provided library functions for GameCube hardware access: graphics (GX), OS services, DVD, controllers (PAD), memory card (CARD), audio (AX/DSP), and math (VEC/MTX). The decomp contains ~500 SDK functions.

## SDK Subsystems

### GX -- Graphics Library (~281 functions)

The GX library provides low-level access to the Flipper GPU's TEV pipeline, vertex processing, and display output.

Key function groups:
- **FIFO management**: `GXInitFifoLimits`, `GXGetFifoBase`, `GXGetFifoSize`, `GXGetCPUFifo`, `GXGetGPFifo`
- **Vertex format**: `GXClearVtxDesc`, `GXInvalidateVtxCache`
- **TEV stages**: `GXSetNumTevStages`, `GXSetNumTexGens`, `GXSetNumChans`
- **Render state**: `GXSetCullMode`, `GXSetZMode`, `GXSetZCompLoc`, `GXSetLineWidth`, `GXSetPointSize`
- **Display copy**: `GXSetDispCopyGamma`, `GXClearBoundingBox`, `GXReadBoundingBox`
- **Fog**: `GXSetFogColor`
- **Display lists**: `GXBeginDisplayList`
- **Matrix**: `GXSetCurrentMtx`

Many GX functions write directly to the write-gather pipe at 0xCC010000 and access internal state via SDA (r13 - 17720). These must remain as inline PPC asm because they depend on hardware-specific access patterns.

### Light Object Accessors

Pure C functions that read/write GXLightObj fields:

| Function | Address | Size | Notes |
|----------|---------|------|-------|
| `GXInitLightAttn` | 0x80567574 | 28 | Set attenuation (a0,a1,a2,k0,k1,k2) |
| `GXInitLightPos` | 0x80567848 | 16 | Set position (x,y,z) |
| `GXInitLightDir` | 0x80567874 | 28 | Set direction (negated internally) |
| `GXInitLightColor` | 0x805679C8 | 16 | Set RGBA color |
| `GXInitSpecularDirHA` | 0x8056799C | 44 | Set specular half-angle (scales by -1048576.0f) |

### Texture Object Accessors

| Function | Address | Size | Notes |
|----------|---------|------|-------|
| `GXGetTexObjData` | 0x805685C0 | 16 | Get texture data pointer |
| `GXGetTexObjWidth` | 0x805685D0 | 8 | Get width |
| `GXGetTexObjHeight` | 0x805685D8 | 8 | Get height |
| `GXGetTexObjFmt` | 0x805685E0 | 8 | Get format |
| `GXGetTexObjWrapS/T` | 0x805685E8 | 8 | Get wrap modes |
| `GXGetTexObjMipMap` | 0x805685F8 | 8 | Get mipmap flag |

### VEC -- Vector Math

C fallback implementations (no paired-single instructions):

| Function | Address | Size | Notes |
|----------|---------|------|-------|
| `C_VECAdd` | in sdk_decomp.c | -- | Vector addition |
| `C_VECSubtract` | in sdk_decomp.c | -- | Vector subtraction |
| `C_VECScale` | in sdk_decomp.c | -- | Scalar multiply |
| `C_VECDotProduct` | in sdk_decomp.c | -- | Dot product |
| `C_VECCrossProduct` | in sdk_decomp.c | -- | Cross product |
| `C_VECNormalize` | 0x8025AB9C | 228 | Uses frsqrte Newton-Raphson (must stay asm) |
| `C_VECMag` | 0x8025ABD8 | 148 | Uses frsqrte Newton-Raphson (must stay asm) |
| `C_VECHalfAngle` | 0x8025AD88 | 216 | Calls C_VECNormalize (must stay asm) |
| `C_VECDistance` | 0x8025AF98 | 132 | Uses frsqrte Newton-Raphson (must stay asm) |

### MTX -- Matrix Math

| Function | Address | Size | Notes |
|----------|---------|------|-------|
| `C_MTXConcat` | 0x80372040 | 400 | 3x4 matrix multiply, handles in-place |
| `C_MTXTranspose` | 0x803721D0 | 96 | 3x4 transpose, zero translation |
| `C_MTXMultVecArray` | 0x80373EA0 | 76 | Transform array of vectors |
| `C_MTXMultVecArraySR` | 0x80373F3C | 76 | Transform array (scale/rotate only) |
| `C_MTX44Concat` | 0x80374488 | 584 | 4x4 matrix multiply, handles in-place |

Already in sdk_decomp.c: `C_MTXCopy`, `C_MTXScale`, `C_MTXIdentity`, `C_MTXTrans`, `C_MTXTransApply`, `C_MTXScaleApply`, `C_MTXMultVec`, `C_MTXMultVecSR`, `C_MTX44Identity`, `C_MTX44Copy`, `C_MTX44Trans`, `C_MTX44Scale`.

### OS, DVD, PAD, CARD, AX, DSP

These subsystems are covered in `src/decomp_cpp/global_chunk_2.cpp` and `global_chunk_3.cpp`:
- **OS**: Thread management, interrupts, timers, memory protection, arena
- **DVD**: Disc access, async file reads, directory traversal
- **PAD**: Controller polling, sampling callbacks, rumble
- **CARD**: Memory card read/write, directory operations, checksumming
- **AX/DSP**: Audio mixing, DSP task scheduling, ARAM DMA
- **VI**: Video interface configuration, retrace callbacks
- **EXI**: Expansion interface (memory card, broadband adapter)
- **SI**: Serial interface (controller communication)

## Why Functions Stay as ASM

Several categories of SDK functions cannot be compiled as pure C with GCC:

1. **SDA access**: Functions that load the GX state struct via `r13 - 17720` (Small Data Area). GCC cannot guarantee r13-relative addressing for arbitrary globals.
2. **Write-gather pipe**: Direct stores to 0xCC010000 must use specific instruction sequences. GCC may reorder or optimize these away.
3. **Paired-single instructions**: PPC paired-single (PS) math uses special FPU instructions (`ps_add`, `ps_mul`, etc.) not available in standard C.
4. **frsqrte Newton-Raphson**: The fast reciprocal square root estimate instruction sequence requires exact instruction ordering for precision.
5. **Cache control**: `dcbi`, `dcbst`, `icbi` cache instructions have no C equivalent.

## Relationships

- GX functions are called by ENgcRenderer and ENgcShader for all rendering
- VEC/MTX functions are used throughout the engine for transforms
- OS functions underpin threading (EThread), synchronization (ESemaphore, EThreadMutex)
- DVD functions are wrapped by EFile and EResourceLoaderImpl for asset loading
- CARD functions are wrapped by SimsMemCardWrap / ENgcMemoryCard for save/load
- PAD functions are wrapped by ENgcController and EControllerManager for input
