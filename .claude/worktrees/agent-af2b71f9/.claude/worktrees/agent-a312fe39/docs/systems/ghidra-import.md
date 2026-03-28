# Ghidra Symbol Import Guide

How to import the 23,068 symbols from the Sims 2 GC DVD map into Ghidra.

## Prerequisites

- **Ghidra 11.0+** (tested with 12.0.4)
- The project repo cloned locally
- Either `extracted/sys/main.dol` (DOL) or `extracted/files/u2_ngc_release_dvd.elf` (ELF with debug info)

## Step 1: Create Ghidra Project

1. Launch Ghidra
2. **File > New Project** — create a project (e.g., `Sims2GC`)
3. **File > Import File** — import `extracted/files/u2_ngc_release_dvd.elf`
   - Ghidra should auto-detect **PowerPC:BE:32:Gekko_Broadway**
   - If importing `main.dol` instead, select the same processor manually
   - Accept default import options
4. Double-click the imported file to open it in the CodeBrowser

## Step 2: Import Symbols

1. **Window > Script Manager** (or press the Script Manager icon)
2. Click the **Manage Script Directories** button (folder icon)
3. Add the `tools/` directory from this project
4. Find **symbol_importer.py** in the script list (under category "Sims2")
5. Double-click to run it

### What Happens

The script reads two files from `config/`:

| File | Contents |
|------|----------|
| `config/symbols.txt` | All 23,068 symbols in dtk format (address, type, size) |
| `config/symbol_names.txt` | Mapping from sanitized names back to original demangled C++ |

For each symbol it:
- **Code symbols** (`.init`, `.text`): Creates a function at the address with the correct name
- **Data symbols** (`.data`, `.rodata`, `.bss`, etc.): Creates a labeled data reference
- **Namespaces**: Parses `Class::Method` names and creates Ghidra namespaces (e.g., `ESimsApp`, `PlayerCheats`, `BBI::InventoryItems`)
- **Comments**: Adds the full demangled signature as a plate comment (e.g., `ESimsApp::Init(void)`)

### Expected Output

```
============================================================
  Sims 2 GC -- Ghidra Symbol Import
============================================================
Parsing symbols.txt...
  Found 23068 symbols
Parsing symbol_names.txt...
  Found 18443 name mappings

Importing 23068 symbols...
  [5%]  1153 / 23068 symbols processed (2.3s elapsed)
  ...
  [95%] 21914 / 23068 symbols processed (38.1s elapsed)

============================================================
  Import Complete  (40.2 seconds)
============================================================
  Functions created:   ~15000
  Functions renamed:   ~3500
  Data labels created: ~4000
  ...
```

The import takes **30-60 seconds** depending on your machine.

## Step 3: Import Struct Definitions (Optional)

After importing symbols, run **ghidra_structs.py** from the same Script Manager.

This creates placeholder struct definitions for key classes:

| Struct | Category | Size | Notes |
|--------|----------|------|-------|
| `ESimsApp` | /Sims2/Core | 0x4A8 | Main app singleton, size from `_app` global |
| `ESim` | /Sims2/Sim | 0x200* | Base sim entity |
| `cXObject` | /Sims2/Objects | 0x200* | Base game object |
| `ESimsCam` | /Sims2/Camera | 0x200* | Camera system |
| `ENgcRenderer` | /Sims2/Render | 0x400* | NGC renderer |
| `EAHeap` | /Sims2/Core | 0x40* | EA memory allocator |
| `FastAllocPool` | /Sims2/Core | 0x20* | Fixed-size pool allocator |
| `PlayerCheats` | /Sims2/Core | 0x28 | Cheat handler, size from `g_playerCheats` |
| `EVec3` | /Sims2/Common | 0x0C | 3D vector (x, y, z) |
| `EVec4` | /Sims2/Common | 0x10 | 4D vector (x, y, z, w) |

*\* Placeholder sizes — refine from constructors as you decompile.*

Structs are organized in the Data Type Manager under `/Sims2/`.

## Step 4: Analyze

After importing symbols, run Ghidra's auto-analysis:

1. **Analysis > Auto Analyze** (or it may prompt automatically)
2. Enable all default analyzers
3. Wait for analysis to complete (~5-10 minutes for 4.4MB DOL)

The imported symbol names dramatically improve Ghidra's decompiler output since it now knows function boundaries and names.

## Tips

- **ELF vs DOL**: The ELF (`u2_ngc_release_dvd.elf`) already has DWARF debug info. Importing it gives you type information that the DOL lacks. The symbol importer adds the remaining symbols from the map file.
- **Re-running**: The script is safe to re-run. It will rename existing functions rather than creating duplicates.
- **Namespace view**: Use **Window > Symbol Tree** to browse by namespace (ESimsApp, ESim, cXObject, etc.).
- **Search**: Use **Search > For Strings** or **Search > Label** to find symbols by name.
- **Decompiler**: With symbols imported, the decompiler (Window > Decompile) shows meaningful function and variable names.

## Troubleshooting

| Problem | Solution |
|---------|----------|
| Script not found | Add `tools/` to Script Manager directories |
| "Cannot find config/symbols.txt" | Script must be in the `tools/` subdirectory of the project root |
| Few functions created | Make sure you imported the DOL/ELF first so Ghidra has the memory mapped |
| Wrong addresses | Verify you're using the DVD build files (SHA1 of main.dol: `d15b7be1`) |
