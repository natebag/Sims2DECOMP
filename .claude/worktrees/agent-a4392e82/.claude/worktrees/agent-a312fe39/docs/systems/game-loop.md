# Game Loop

## Overview

The main game loop lives in `ESimsApp`, which inherits from `EApp` (the Maxis Engine application base). The loop follows a classic init-update-shutdown lifecycle with an 8-step per-frame update and a 24-step initialization sequence.

## Call Flow

```
EApp::Main()
  -> EApp::SystemInit()
    -> ESimsApp::Init()              -- one-time initialization (24 steps)
    -> ESimsApp::ShowInitialDisplay() -- heap compaction
  -> EApp::SystemUpdate()            -- called every frame
    -> ESimsApp::Update()            -- 8-step per-frame update
  -> ESimsApp::Shutdown()            -- cleanup on exit
```

## Key Class: ESimsApp

Size: ~0xD24 bytes. Extends EApp (0x338 bytes base).

Notable fields:
- `0x348`: m_argc / m_argv -- command line data
- `0x450`: m_audioMuted -- audio mute flag
- `0x468`: m_gameState -- current OVERALL_GAME_STATE
- `0x478`: m_gameStateMan -- EGameStateMan pointer
- `0x47C`: m_currentRC -- active render context (ERC)
- `0x480`: m_window -- render window (EWindow)
- `0x48C`: m_player1RemapPending / m_player2RemapPending -- controller auto-mapping
- `0x49C`: m_screenshotActive/Cols/Rows -- tiled screenshot state
- `0xD20`: m_languageId

## Per-Frame Update (ESimsApp::Update, 0x80005BA4, 264 bytes)

Executed every frame in this exact order:

1. **Controller auto-mapping** -- Remap player 1/2 controllers if pending
2. **ProfileHook()** -- Performance measurement
3. **UpdateCheats()** (0x80005448) -- Check for cheat button combos via PlayerCheats
4. **UpdateApt()** (0x800054BC) -- Tick APT/ActionScript UI system
5. **UpdateGame()** (0x80005514) -- Tick state machines and GameData (skipped if paused)
6. **UpdateAudio()** (0x800056F0) -- Update cSoundPlayer and UIAUDIO
7. **UpdateShaders(0.0f)** (0x80005554) -- Update shader animations with time scaling
8. **UpdateDraw()** (0x80005808) -- Render the frame
9. **UpdateReset()** (0x80005ACC) -- Check for soft reset combo (~2s hold)

## Shutdown Sequence (0x800043C8, 236 bytes)

Tears down subsystems in reverse init order:

1. Auto-save (EGlobal::BeginSaveGame)
2. Shutdown global sim data (Globs::Shutdown)
3. Free ResourceManager2
4. Shutdown StateMachineManager
5. Delete all game states + state manager
6. Reset EGlobal
7. Shutdown EyeToyClient
8. Destroy render window
9. Shutdown ResourceManager
10. Shutdown CTGDump

## Important Functions

| Function | Address | Size | Notes |
|----------|---------|------|-------|
| `ESimsApp::ESimsApp` | 0x80004340 | 88 | Constructor |
| `ESimsApp::Init` | varies | large | 24-step init sequence |
| `ESimsApp::Update` | 0x80005BA4 | 264 | Main per-frame update |
| `ESimsApp::Shutdown` | 0x800043C8 | 236 | Full teardown |
| `ESimsApp::ShowInitialDisplay` | 0x80004B8C | 244 | Two rounds of 13-heap compaction |
| `ESimsApp::parseCommandLine` | 0x80004074 | 716 | Parse -lot, -ngh, -test flags |
| `ESimsApp::SetGameState` | 0x80005410 | 8 | Set OVERALL_GAME_STATE |
| `ESimsApp::GetBuildVersion` | 0x800044B4 | 12 | Returns "GameCube The Sims 2 Console Build F.09.12.0" |
| `ESimsApp::TakeBigScreenshot` | 0x80005D2C | 20 | Initiate tiled screenshot |

## Global State

Key globals (originally SDA-relative via r13):
- `g_deltaTime` -- frame delta time (float)
- `g_pauseGame` -- pause flag
- `g_pStateMachineManager` -- manages game flow state machines
- `g_pEGlobal` -- central game state (EGlobal, 211 fields)
- `g_pGameData` -- game data singleton
- `g_pSoundPlayer` -- audio system
- `g_pEControllerManager` -- input system
- `g_resetTimer` -- accumulates hold time for soft reset combo

## Quirks

- **Shader time scaling**: `UpdateShaders()` supports a `TimeScaleObject` that slows/pauses shader animations during cutscenes. If dt is 0.0, it uses `g_deltaTime` instead.
- **Reset combo**: Holding the reset button combo for >2.0 seconds triggers a soft console reset via `UpdateReset()`.
- **UIAUDIO lazy init**: The UIAUDIO singleton is lazily constructed on first `UpdateAudio()` call, not during Init.
- **Command line**: Despite being a console game, `parseCommandLine()` supports `-lot <N>` (lot 1-16), `-ngh <file>`, and `-test` flags, likely used during development.

## Relationships

- ESimsApp owns `EGameStateMan` which manages the game flow state machine
- `StateMachineManager` drives all state machines (title, neighborhood, lot, live mode)
- `EGlobal` holds the 211-field global game state
- Audio, rendering, and UI are updated as sub-steps of the main loop
