# cleanup_root.ps1 — Remove junk from repo root + relocate reports
# Run from repo root: powershell -ExecutionPolicy Bypass -File tools/cleanup_root.ps1
#
# What this does:
#   1. git rm 70+ test/scratch/temp files
#   2. git mv report files to build/reports/
#   3. Commits both as separate commits
#
# Does NOT touch tool scripts — those path updates are done separately.

Set-StrictMode -Version Latest
$ErrorActionPreference = "Continue"
Push-Location "F:\coding\Decompiles\Sims 2"

# ── Preflight ────────────────────────────────────────────────────────
if (Test-Path ".git\index.lock") {
    Remove-Item ".git\index.lock" -Force
    Write-Host "Removed stale .git/index.lock" -ForegroundColor Yellow
}

# ── Step 1: Remove junk files ────────────────────────────────────────
Write-Host "`n=== Step 1: Removing junk files ===" -ForegroundColor Cyan

$junk = @(
    # Test .cpp files
    "test_asm.cpp", "test_audio_eff.cpp", "test_blr.cpp",
    "test_bool.cpp", "test_bool2.cpp", "test_bool3.cpp", "test_bool4.cpp", "test_bool5.cpp",
    "test_branch.cpp", "test_build_ui.cpp", "test_checkcancel.cpp",
    "test_cunlock.cpp", "test_cunlock2.cpp", "test_cunlock3.cpp", "test_cunlock4.cpp",
    "test_flags.cpp",
    "test_float_abs.cpp", "test_float_abs2.cpp",
    "test_getfb.cpp",
    "test_getselectionradius.cpp", "test_getselectionradius2.cpp",
    "test_getselectionradius3.cpp", "test_getselectionradius4.cpp",
    "test_getwallheight.cpp", "test_getwallheight2.cpp",
    "test_getwallheight3.cpp", "test_getwallheight4.cpp",
    "test_instancedata.cpp", "test_instancedata2.cpp",
    "test_instancedata3.cpp", "test_instancedata4.cpp",
    "test_iscameradirector.cpp", "test_iscameradirector2.cpp",
    "test_isvalidplayerid.cpp", "test_isvalidplayerid2.cpp",
    "test_isvalidplayerid3.cpp", "test_isvalidplayerid4.cpp",
    "test_naked.cpp",
    "test_placementobject.cpp", "test_placementobject2.cpp",
    "test_placementobject3.cpp", "test_placementobject4.cpp",
    "test_resetinputstate.cpp", "test_resetinputstate2.cpp", "test_resetinputstate3.cpp",
    "test_ret.cpp",
    "test_sda.cpp", "test_sda_ptr.cpp", "test_sda_ptr2.cpp",
    "test_session6.cpp",
    "test_sn.cpp", "test_sn2.cpp", "test_sn3.cpp", "test_sn4.cpp", "test_sn5.cpp", "test_sn6.cpp",
    "test_sound_ptr.cpp", "test_start.cpp", "test_stop.cpp", "test_tag.cpp", "test_virt.cpp",
    # Test .o files
    "test.o", "test_asm.o", "test_blr.o", "test_branch.o",
    "test_float_abs.o", "test_float_abs2.o", "test_naked.o",
    "test_ret.o", "test_sound_ptr.o", "test_virt.o",
    # Test .s files
    "test.s", "test_O2.s", "test_asm.s", "test_sda.s",
    # Binary artifacts
    "start_raw.bin", "stop_raw.bin", "tmp_csl.elf", "tmp_csr.elf", "tmp_disasm.o",
    # Logs and temp
    "output.txt", "dup_verify.log", "dup_verify_seq.log", "qa_monitor.log",
    # Old candidate lists
    "candidates.txt", "candidates_dvd.txt", "candidates_temp.txt",
    # Temp snapshots
    "matched_addrs_temp.txt", "matched_stats_pre_s0.json",
    # Scratch
    "dummy_match.cpp"
)

$removed = 0
foreach ($f in $junk) {
    # Check if file is tracked by git (exists in index)
    $tracked = git ls-files --error-unmatch $f 2>&1
    if ($LASTEXITCODE -eq 0) {
        git rm -f $f 2>&1 | Out-Null
        $removed++
        Write-Host "  rm $f" -ForegroundColor DarkGray
    } elseif (Test-Path $f) {
        # File exists but not tracked — just delete it
        Remove-Item $f -Force
        Write-Host "  del (untracked) $f" -ForegroundColor DarkGray
        $removed++
    }
}
Write-Host "Staged $removed files for removal"

if ($removed -gt 0) {
    git commit -m "cleanup: remove $removed scratch/test/temp files from repo root

These files were one-off compiler experiments, binary test artifacts,
old logs, and temp snapshots with zero references in the build system
or any tool script. See tools/cleanup_root.ps1 for the full list."
    Write-Host "Committed junk removal ($removed files)" -ForegroundColor Green
} else {
    Write-Host "No junk files found to remove (already clean?)" -ForegroundColor Yellow
}

# ── Step 2: Move report files to build/reports/ ─────────────────────
Write-Host "`n=== Step 2: Moving report files to build/reports/ ===" -ForegroundColor Cyan

$reportDir = "build/reports"
if (-not (Test-Path $reportDir)) {
    New-Item -ItemType Directory -Path $reportDir -Force | Out-Null
}

$reports = @(
    "sda_family_report.json", "sda_family_report2.json", "sda_family_report3.json",
    "sda_family_report4.json", "sda_family_report5.json", "sda_family_report6.json",
    "tu_ranking_full.json", "wall_classification.json",
    "missing_functions_report.txt", "missing_functions_report_new.txt",
    "targetable_functions.txt", "matched_stats.json",
    "tus.txt", "vtable_report.md", "version_diff_functions.txt"
)

$moved = 0
foreach ($f in $reports) {
    if (Test-Path $f) {
        $tracked = git ls-files --error-unmatch $f 2>&1
        if ($LASTEXITCODE -eq 0) {
            git mv $f "$reportDir/$f" 2>&1 | Out-Null
            Write-Host "  mv $f -> $reportDir/$f" -ForegroundColor DarkGray
        } else {
            Move-Item $f "$reportDir/$f" -Force
            git add "$reportDir/$f" 2>&1 | Out-Null
            Write-Host "  mv (untracked) $f -> $reportDir/$f" -ForegroundColor DarkGray
        }
        $moved++
    }
}
Write-Host "Staged $moved files for relocation"

if ($moved -gt 0) {
    git commit -m "cleanup: move $moved report/analysis files to build/reports/

Relocate generated reports, analysis JSONs, and reference files out of
the repo root into build/reports/. Tool scripts that reference these
files will be updated in the next commit."
    Write-Host "Committed report relocation ($moved files)" -ForegroundColor Green
} else {
    Write-Host "No report files found to move" -ForegroundColor Yellow
}

# ── Summary ──────────────────────────────────────────────────────────
Write-Host "`n=== Done ===" -ForegroundColor Cyan
Write-Host "Removed: $removed junk files"
Write-Host "Moved:   $moved report files to build/reports/"
Write-Host ""
Write-Host "NEXT STEP: Run the tool path updates (Claude will handle this after you confirm the commits landed)."

Pop-Location
