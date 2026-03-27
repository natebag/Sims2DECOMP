# Next Steps — Sims 2 PC Port

Current milestone: **Milestone 7: PC PORT** — IN PROGRESS

Last updated: 2026-03-27

---

## What Works RIGHT NOW

- `sims2pc.exe` builds, links, runs (1.2MB x86_64 Windows)
- OpenGL window (1280x720) with rendered plumbob + textures
- All 22 .arc archives load (2,378+ game resources in memory)
- GX→OpenGL bridge (state, vertex, matrix, texture)
- Input bridge (keyboard → PAD mapping)
- Audio bridge (stubs ready)
- Game loop fully traced (ESimsApp::Update)

---

## SESSION C: Game Boot — THE NEXT BIG PUSH

This is an iterative debugging session. Call `ESimsApp::Init()`, fix each crash,
implement missing systems one at a time until the game boots.

### Step 1: Minimal Engine Init
- [ ] Implement `ENgcEngine::InitMemoryManager()` — wire EAHeap to malloc
- [ ] Implement `EGlobalManager::Startup()` — init global state singleton
- [ ] Implement `EApp::SetArgs()` — store argc/argv
- [ ] Call `MainInit()` from our main_pc.cpp
- [ ] **Test:** does it crash? Fix the first crash.

### Step 2: Resource System
- [ ] Wire `EResourceManager::Init()` to use our arc_reader
- [ ] Implement `EResourceLoaderImpl::Init()` — resource loading thread
- [ ] Map resource type IDs to .arc file categories
- [ ] **Test:** does `ESimsApp::Init()` get past resource loading?

### Step 3: Renderer Bootstrap
- [ ] Implement `ENgcRenderer::Init()` — route to our OpenGL context
- [ ] Implement `ENgcGraphics::Init()` — framebuffer setup
- [ ] Wire `ERC` (render context) to our gl_renderer
- [ ] **Test:** does the game try to render something?

### Step 4: UI System (APT)
- [ ] Implement `AptViewer::Init()` — the Flash/ActionScript UI engine
- [ ] Load flash UI files from flashes.arc (s2c_pause_mainmenu, etc.)
- [ ] Implement basic APT rendering (text, buttons, backgrounds)
- [ ] **Test:** does the main menu appear?

### Step 5: State Machine
- [ ] Wire `TheSimsStateMachine` — the top-level game state machine
- [ ] Implement `TheSimsMaxisLogoState` → `TheSimsMainMenuState` flow
- [ ] **Test:** can you see the Maxis logo → main menu transition?

### Debugging Strategy
For each crash:
1. Check sims2pc.log for last successful step
2. Add more logging around the crash point
3. Identify which function/system is missing
4. Implement minimal stub or real implementation
5. Rebuild and try again

Most crashes will be NULL pointer dereferences from uninitialized globals.
Fix: add `if (!ptr) return;` guards or initialize the globals properly.

---

## SESSION D: Texture Decoding (can run in parallel)

The EA/GC texture pipeline:
```
.arc file → EA TXFL header → GC pixel data (CMPR/C4/C8/RGBA8) → RGBA → OpenGL
```

- [ ] Parse EA TXFL header (the 16-byte prefix before pixel data)
- [ ] Feed pixel data to gc_texture_decode.cpp (CMPR decoder already exists)
- [ ] Test with fonts.arc "systemfont" (simplest texture)
- [ ] Test with textures.arc "title bg c" (title screen background)
- [ ] Wire into GXInitTexObj so game textures auto-decode

---

## SESSION E: First Playable (after C+D)

- [ ] Get past loading screen
- [ ] Main menu renders with real textures
- [ ] Navigate menu with keyboard
- [ ] Load into a house
- [ ] **THE MOMENT**

---

## Build Commands

```bash
# From project root:
cd build_pc2
export PATH="/f/coding/Decompiles/Tools/devkitPro/msys2/usr/bin:$PATH"
cmake .. && make -j4

# Run:
./sims2pc.exe

# Check log:
cat sims2pc.log
```

---

## Key Architecture

```
main_pc.cpp (PC entry point)
    ↓
Win32 Window + OpenGL context
    ↓
arc_reader.cpp → loads all .arc files
    ↓
Game loop: gl_begin_frame → [game update] → gl_end_frame
    ↓
GX stubs → gx_gl_impl.cpp → OpenGL calls
    ↓
Texture bridge → gc_texture_decode → gl_create_texture
```

When `ESimsApp::Init()` + `Update()` are wired in, the game will:
1. Init memory, resources, renderer, UI, audio
2. Start the state machine (logo → menu → gameplay)
3. Each frame: UpdateCheats → UpdateApt → UpdateGame → UpdateAudio → UpdateDraw
