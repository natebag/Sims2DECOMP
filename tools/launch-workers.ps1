# Sims 2 GC Decomp — Parallel Worker Launcher
# Creates git worktrees and launches Claude Code agents in parallel,
# each with full project context and a specific task assignment.
#
# Usage: .\tools\launch-workers.ps1
#        .\tools\launch-workers.ps1 -Workers 2    (limit to N workers)
#        .\tools\launch-workers.ps1 -Cleanup       (remove all worktrees)

param(
    [int]$Workers = 0,       # 0 = launch all defined tasks
    [switch]$Cleanup,
    [switch]$DryRun
)

$RepoRoot = (git -C $PSScriptRoot\.. rev-parse --show-toplevel 2>$null) -replace '/', '\'
if (-not $RepoRoot) {
    Write-Error "Not in a git repository"
    exit 1
}

$WorktreeBase = "$RepoRoot\.worktrees"
$MainBranch = "main"

# ============================================================================
# PROJECT CONTEXT — shared across all workers
# ============================================================================
$ProjectContext = @"
You are working on the Sims 2 GameCube matching decompilation project.

## Current State (Milestone 1: FOUNDATION — IN PROGRESS)
- devkitPPC (GCC 15.2.0) is at F:\coding\Decompiles\Tools\devkitPro\devkitPPC
- decomp-toolkit (dtk 1.8.3) is at F:\coding\Decompiles\Tools\dtk-windows-x86_64.exe
- Ghidra 12.0.4 is at F:\coding\Decompiles\Tools\ghidra_12.0.4_PUBLIC
- Python 3.14.3 is available
- The DOL is at extracted/sys/main.dol (SHA1: d15b7be1396544a15728f25f732db63a7cfcc877)
- The ELF with debug info is at extracted/files/u2_ngc_release_dvd.elf
- The CORRECT map file is extracted/files/u2_ngc_release_dvd.map (DVD build, matches DOL)
  (NOT u2_ngc_release.map which is a different larger build)
- 23,068 symbols extracted into config/symbols.txt (18,547 functions)
- config/symbol_names.txt maps sanitized dtk names back to demangled C++ names
- Makefile is set up with devkitPPC compile flags
- tools/check_func.py can compile and compare individual functions
- Original compiler was SN Systems ProDG (NOT CodeWarrior/Metrowerks)
- Game built on cm3-build22-NGC, September 12, 2005

## Key Rules
- Read CLAUDE.md for full project conventions
- Use EXACT symbol names from the map file
- Every decompiled function must byte-match the original DOL
- SN Systems compiled — GCC may not produce identical output for all functions
- Document your work as you go

## Working In a Worktree
- You are in an isolated git worktree branch
- Make commits to your branch as you complete work
- The main session will merge your branch when you're done
- Go full speed — you have full permissions
"@

# ============================================================================
# TASK DEFINITIONS — each worker gets one
# ============================================================================
$Tasks = @(
    @{
        Name   = "boot-decomp"
        Branch = "worker/boot-decomp"
        Prompt = @"
$ProjectContext

## YOUR TASK: Decompile the Boot Sequence

You are decompiling the GameCube boot sequence. These are small assembly/C functions in .init section.

### Functions to decompile (in order):
1. __start (0x80003100, SN Systems crt0) — sets up stack, r2, r13, calls init functions
2. __init_hardware (0x80003468, size 0x24) — hardware init from DolphinSDK
3. __flush_cache (0x8000348C, size 0x34) — cache flush from DolphinSDK
4. __init_vm and __premain are at 0x80003464 (size 0, likely labels/aliases)

### How to work:
1. Disassemble from the original ELF to see the actual instructions:
   F:\coding\Decompiles\Tools\devkitPro\devkitPPC\bin\powerpc-eabi-objdump.exe -d -M gekko --start-address=0x80003100 --stop-address=0x800034C0 extracted/files/u2_ngc_release_dvd.elf
2. Write matching assembly in src/boot/crt0.s (for __start) and src/boot/ppc_eabi_init.s (for SDK functions)
3. Compile with: F:\coding\Decompiles\Tools\devkitPro\devkitPPC\bin\powerpc-eabi-as.exe -mcpu=750 -meabi
4. Compare disassembly of your .o against the original
5. Document the boot flow in docs/systems/boot-sequence.md

Write assembly (.s files), not C — these are handwritten startup routines.
Commit your work when each function matches.
"@
    },
    @{
        Name   = "linker-and-diff"
        Branch = "worker/linker-and-diff"
        Prompt = @"
$ProjectContext

## YOUR TASK: Create Linker Script and Verify Matching Pipeline

Set up the end-to-end pipeline: compile -> link -> DOL -> diff against original.

### Steps:
1. Create config/ldscript.lcf — a PowerPC linker script that places sections at the correct addresses:
   - .init at 0x80003100
   - .text at 0x800034C0
   - .ctors at 0x803CA900
   - .dtors at 0x803CABA0
   - .rodata at 0x803CAD20
   - .data at 0x804235E0
   - .bss at 0x8046E1E0
   - .sdata at 0x804FD920
   - .sbss at 0x804FF6C0
   - .sdata2 at 0x80500600
   Entry point: 0x80003100

2. Test linking with a minimal stub:
   - Write a tiny .s file with just a blr instruction
   - Link it with the script
   - Verify the output ELF has correct section addresses

3. Test dtk dol diff:
   - Link your stub into an ELF
   - Run: F:\coding\Decompiles\Tools\dtk-windows-x86_64.exe dol diff config/sims2_gc.yml <your_elf>
   - Verify dtk can compare functions

4. Update the Makefile to use the linker script and add a 'diff' target that works

5. Document the build process in docs/systems/build-system.md

Commit your work as you complete each step.
"@
    },
    @{
        Name   = "ghidra-symbols"
        Branch = "worker/ghidra-symbols"
        Prompt = @"
$ProjectContext

## YOUR TASK: Write Ghidra Symbol Import Script

Create a Ghidra script that imports all 23,068 symbols from the DVD map file into a Ghidra project.

### Steps:
1. Write tools/symbol_importer.py — a Ghidra Python script (Jython) that:
   - Parses extracted/files/u2_ngc_release_dvd.map (SN Systems format)
   - For each symbol: creates a function or label at the correct address
   - Sets the symbol name to the demangled name from the map
   - Handles namespaces (e.g., ESimsApp::Init creates namespace ESimsApp)
   - Marks .text symbols as functions, .data/.rodata as data labels
   - Prints progress as it runs

2. The SN Systems map format has 4 indentation levels:
   - Level 0 (1 space after align): Section header
   - Level 1 (9 spaces): Input section
   - Level 2 (17 spaces): Object file path
   - Level 3 (25 spaces): Symbol name
   Pattern: ^([0-9a-fA-F]{8}) ([0-9a-fA-F]{8})\s+(\d+)(\s+)(\S.*)
   Level = (len(group4) - 1) // 8
   Align values are HEX not decimal

3. Write a README section or doc explaining how to use the script:
   - Open Ghidra, import main.dol or the ELF
   - Run the script via Script Manager
   - What to expect (takes a few minutes for 23K symbols)

4. Also write tools/ghidra_structs.py — a starter script that defines key structs:
   - Basic struct templates for ESim, ESimsApp, cXObject (just name + size placeholder)
   - These can be refined later as we decompile

Commit your work when the import script is complete and documented.
"@
    }
)

# ============================================================================
# CLEANUP MODE
# ============================================================================
if ($Cleanup) {
    Write-Host "`n=== Cleaning up worktrees ===" -ForegroundColor Yellow
    $existing = git -C $RepoRoot worktree list --porcelain 2>$null |
        Select-String "^worktree " | ForEach-Object { $_ -replace "^worktree ", "" }

    foreach ($wt in $existing) {
        if ($wt -like "*\.worktrees\*") {
            $branch = git -C $wt branch --show-current 2>$null
            Write-Host "  Removing worktree: $wt (branch: $branch)" -ForegroundColor Cyan
            git -C $RepoRoot worktree remove --force $wt 2>$null
            if ($branch -and $branch -ne $MainBranch) {
                Write-Host "  Branch $branch preserved — merge manually with: git merge $branch" -ForegroundColor DarkGray
            }
        }
    }
    if (Test-Path $WorktreeBase) { Remove-Item -Recurse -Force $WorktreeBase 2>$null }
    Write-Host "Done.`n" -ForegroundColor Green
    exit 0
}

# ============================================================================
# LAUNCH MODE
# ============================================================================
$tasksToLaunch = if ($Workers -gt 0) { $Tasks | Select-Object -First $Workers } else { $Tasks }

Write-Host "`n============================================================" -ForegroundColor Cyan
Write-Host "  Sims 2 GC Decomp — Launching $($tasksToLaunch.Count) parallel workers" -ForegroundColor Cyan
Write-Host "============================================================`n" -ForegroundColor Cyan

# Create worktree base dir
if (-not (Test-Path $WorktreeBase)) { New-Item -ItemType Directory -Path $WorktreeBase -Force | Out-Null }

foreach ($task in $tasksToLaunch) {
    $worktreePath = "$WorktreeBase\$($task.Name)"
    $branch = $task.Branch

    Write-Host "[$($task.Name)] Creating worktree..." -ForegroundColor Yellow

    # Create branch if it doesn't exist
    $branchExists = git -C $RepoRoot branch --list $branch 2>$null
    if (-not $branchExists) {
        git -C $RepoRoot branch $branch $MainBranch 2>$null
    }

    # Remove existing worktree if present
    if (Test-Path $worktreePath) {
        git -C $RepoRoot worktree remove --force $worktreePath 2>$null
        Start-Sleep -Milliseconds 500
    }

    # Create worktree
    git -C $RepoRoot worktree add $worktreePath $branch 2>$null
    if (-not (Test-Path $worktreePath)) {
        Write-Error "Failed to create worktree at $worktreePath"
        continue
    }

    Write-Host "[$($task.Name)] Worktree at $worktreePath" -ForegroundColor Green

    # Write the prompt to a temp file (avoids quoting hell)
    $promptFile = "$worktreePath\.claude-worker-prompt.txt"
    $task.Prompt | Out-File -FilePath $promptFile -Encoding utf8

    # Build the claude command
    $claudeCmd = "cd `"$worktreePath`"; Write-Host '=== Worker: $($task.Name) ===' -ForegroundColor Cyan; claude --dangerously-skip-permissions -p (Get-Content `"$promptFile`" -Raw)"

    if ($DryRun) {
        Write-Host "[$($task.Name)] DRY RUN — would launch:" -ForegroundColor DarkGray
        Write-Host "  $claudeCmd`n" -ForegroundColor DarkGray
    } else {
        Write-Host "[$($task.Name)] Launching Claude Code agent..." -ForegroundColor Green
        Start-Process powershell -ArgumentList "-NoExit", "-Command", $claudeCmd
        Start-Sleep -Milliseconds 1000  # Stagger launches slightly
    }
}

Write-Host "`n============================================================" -ForegroundColor Cyan
Write-Host "  All workers launched!" -ForegroundColor Green
Write-Host "  Each is running in its own PowerShell window." -ForegroundColor DarkGray
Write-Host "" -ForegroundColor DarkGray
Write-Host "  To check status:  git worktree list" -ForegroundColor DarkGray
Write-Host "  To see branches:  git branch" -ForegroundColor DarkGray
Write-Host "  To merge work:    git merge worker/boot-decomp" -ForegroundColor DarkGray
Write-Host "  To cleanup:       .\tools\launch-workers.ps1 -Cleanup" -ForegroundColor DarkGray
Write-Host "============================================================`n" -ForegroundColor Cyan
