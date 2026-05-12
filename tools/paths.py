"""Canonical project paths.

Provides a single source of truth for game-asset and config paths so that new
dtk-aware tools (configure.py, ninja build, CI) can use the standard
dtk-template layout (orig/G4ZE69/, config/G4ZE69/) while existing tools keep
working with their hardcoded paths to extracted/ and config/sims2_gc.yml.

Both layouts coexist:
- Existing tooling: extracted/, config/{sims2_gc.yml,symbols.txt,splits.txt,...}
- dtk-aware tooling: orig/G4ZE69/, config/G4ZE69/{config.yml,symbols.txt,splits.txt,...}

On Windows, orig/G4ZE69/sys and orig/G4ZE69/files are NTFS junctions back to
extracted/sys and extracted/files. The config/G4ZE69/ files are copies of the
config/ files (small text files, easy to keep in sync — see CLAUDE.md if/when
adding new config entries).
"""

from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent

GAME_ID = "G4ZE69"

# --- dtk-aware paths (preferred for new code) ---
ORIG_DIR = REPO_ROOT / "orig" / GAME_ID
DOL_PATH = ORIG_DIR / "sys" / "main.dol"
ELF_PATH = ORIG_DIR / "files" / "u2_ngc_release_dvd.elf"
MAP_PATH = ORIG_DIR / "files" / "u2_ngc_release_dvd.map"
DEBUG_MAP_PATH = ORIG_DIR / "files" / "u2_ngc_debug.map"
RELEASE_MAP_PATH = ORIG_DIR / "files" / "u2_ngc_release.map"

CONFIG_DIR = REPO_ROOT / "config" / GAME_ID
CONFIG_YML = CONFIG_DIR / "config.yml"
SYMBOLS_TXT = CONFIG_DIR / "symbols.txt"
SPLITS_TXT = CONFIG_DIR / "splits.txt"
LDSCRIPT_LCF = CONFIG_DIR / "ldscript.lcf"

# --- legacy paths (kept for existing tools, do not use in new code) ---
LEGACY_EXTRACTED = REPO_ROOT / "extracted"
LEGACY_DOL = LEGACY_EXTRACTED / "sys" / "main.dol"
LEGACY_MAP = LEGACY_EXTRACTED / "files" / "u2_ngc_release_dvd.map"
LEGACY_CONFIG_YML = REPO_ROOT / "config" / "sims2_gc.yml"
