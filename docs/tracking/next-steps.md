# Next Steps — Sims 2 GC Decomp → PC Port

Current milestone: **Milestone 7: PC PORT** — IN PROGRESS

Last updated: 2026-03-27

---

## Where We Are

Decompilation is DONE. All 18,539 functions byte-matched, all 1,214 asm stubs
converted to portable C++. `sims2pc.exe` compiles, links, runs, opens a Win32 window.

**What works:** x86 build, platform stubs, Win32 window (1280x720)
**What's needed:** asset loading, rendering, game loop, input, audio

---

## PC Port Sprint Plan

### SESSION A: Asset Loading — THE CRITICAL PATH
**Can be parallelized across 2 CLI sessions + worktree agents**

Without assets, nothing renders. The game's 1.2GB of content is in `.arc` archives
on the GameCube disc at `extracted/files/DATA/`.

#### CLI Session 1: .arc Archive Reader
- [ ] Reverse engineer .arc format (may already be partially documented)
- [ ] Write `src/platform/pc/arc_reader.cpp` — open .arc, list entries, extract files
- [ ] Map DVD file paths to PC filesystem paths (`extracted/files/DATA/`)
- [ ] Implement `DVDOpen`/`DVDRead` stubs to read from extracted disc files
- [ ] Test: list all files in an .arc, extract one successfully

#### CLI Session 2: Texture + Model Parsers
- [ ] Parse TPL texture format → raw RGBA pixels
- [ ] Parse ERModel vertex/index data → renderable mesh
- [ ] Write test harness that dumps a texture to BMP/PNG
- [ ] Test: display a texture filename + dimensions from game data

### SESSION B: OpenGL Rendering Backend
**4 worktree agents in parallel**

Replace GX stubs with OpenGL. The game uses ~30 core GX functions.

#### Agent 1: OpenGL Context + Basic Setup
- [ ] Add OpenGL context to Win32 window (wglCreateContext)
- [ ] Implement `GXInit`, `GXSetViewport`, `GXSetScissor`
- [ ] Implement `GXSetCullMode`, `GXSetZMode`, `GXSetBlendMode`
- [ ] Clear screen to blue instead of black (proof of life)

#### Agent 2: Vertex Submission
- [ ] Implement `GXBegin`/`GXEnd` → `glBegin`/`glEnd`
- [ ] Implement `GXPosition3f32` → `glVertex3f`
- [ ] Implement `GXNormal3f32` → `glNormal3f`
- [ ] Implement `GXColor4u8` → `glColor4ub`
- [ ] Implement `GXTexCoord2f32` → `glTexCoord2f`

#### Agent 3: Texture Loading
- [ ] Implement `GXInitTexObj` → `glGenTextures` + `glTexImage2D`
- [ ] Implement `GXLoadTexObj` → `glBindTexture`
- [ ] Handle GC texture formats (CMPR/DXT1, C4, C8, RGB5A3, RGBA8)
- [ ] Implement `GXInvalidateTexAll`

#### Agent 4: Matrix + State
- [ ] Implement `GXLoadPosMtxImm` → `glLoadMatrixf`
- [ ] Implement `GXSetCurrentMtx`, projection setup
- [ ] Implement TEV stage mapping to fixed-function GL
- [ ] Implement fog, alpha test

### SESSION C: Wire Up Game Loop
**Sequential — needs Sessions A+B working first**

- [ ] Replace stub `main()` with call to decompiled `MainInit()`
- [ ] Get EAHeap allocator working (already partially implemented)
- [ ] Get EResourceManager loading .arc files via new arc_reader
- [ ] Get EFileSystem::Init() pointing to extracted disc files
- [ ] Debug crashes (this will be iterative)
- [ ] Goal: get past boot to loading screen

### SESSION D: Input + Audio
**2 worktree agents in parallel**

#### Agent 1: Input
- [ ] Map Win32 keyboard messages to PAD button flags
- [ ] Map Xbox/PS controller (XInput) to PAD
- [ ] Wire up analog sticks
- [ ] Test: navigate a menu with keyboard

#### Agent 2: Audio
- [ ] Implement basic WAV/PCM playback via Win32 waveOut
- [ ] Hook up AX/DSP stubs to play sound effects
- [ ] Hook up music playback (AmbientScorePlayer)
- [ ] Test: hear a sound effect

### SESSION E: First Playable
- [ ] Fix remaining crashes
- [ ] Get main menu rendering
- [ ] Get Create-A-Sim working
- [ ] Load into a house
- [ ] **THE MOMENT: play the game on PC**

---

## Multi-CLI Strategy

The user has 2 Claude CLI sessions available. Optimal split:

| CLI 1 | CLI 2 |
|-------|-------|
| Session A1: .arc reader | Session A2: texture/model parsers |
| Session B: OpenGL (4 worktree agents) | Session C: game loop wiring |
| Session D1: input | Session D2: audio |

Both CLIs can use worktree agents for parallel work within their tasks.

---

## Build Commands

```bash
# PC build (from project root)
cd build_pc2
export PATH="/f/coding/Decompiles/Tools/devkitPro/msys2/usr/bin:$PATH"
cmake .. && make -j4

# Run
./sims2pc.exe

# GC build (original matching DOL)
make inject
make diff
```

---

## Key Files

| File | What |
|------|------|
| `CMakeLists.txt` | PC build system |
| `src/platform/pc/main_pc.cpp` | PC entry point (Win32 window) |
| `src/platform/pc/gx_stubs.cpp` | GX→OpenGL stubs (to be implemented) |
| `src/platform/pc/os_stubs.cpp` | OS/DVD/PAD stubs |
| `include/platform/platform.h` | Platform abstraction types |
| `src/decomp_cpp/*.cpp` | All portable game code (47 files) |
| `extracted/files/DATA/*.arc` | Game assets |

---

## Completed Milestones

| # | Milestone | Completed |
|---|-----------|-----------|
| 1 | Foundation | 2026-03-24 |
| 2 | Portable C++ Conversion | 2026-03-27 |
| 3 | Core Systems | 2026-03-27 |
| 4 | Gameplay Systems | 2026-03-27 |
| 5 | Presentation & Polish | 2026-03-27 |
| 6 | Full Match | 2026-03-27 |
| 7 | **PC Port** | **IN PROGRESS** |
