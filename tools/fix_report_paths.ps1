# fix_report_paths.ps1 — Update tool scripts to reference build/reports/ paths
# Run from repo root AFTER cleanup_root.ps1 has moved the files.
# powershell -ExecutionPolicy Bypass -File tools/fix_report_paths.ps1

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"
Push-Location "F:\coding\Decompiles\Sims 2"

if (Test-Path ".git\index.lock") {
    Remove-Item ".git\index.lock" -Force
    Write-Host "Removed stale .git/index.lock" -ForegroundColor Yellow
}

# Each entry: [file, old_string, new_string]
$replacements = @(
    # spot_sda_families*.py — output paths
    @("tools/spot_sda_families.py",  "'sda_family_report.json'",  "'build/reports/sda_family_report.json'"),
    @("tools/spot_sda_families2.py", "'sda_family_report2.json'", "'build/reports/sda_family_report2.json'"),
    @("tools/spot_sda_families3.py", "'sda_family_report3.json'", "'build/reports/sda_family_report3.json'"),
    @("tools/spot_sda_families4.py", "'sda_family_report4.json'", "'build/reports/sda_family_report4.json'"),
    @("tools/spot_sda_families5.py", "'sda_family_report5.json'", "'build/reports/sda_family_report5.json'"),
    @("tools/spot_sda_families6.py", "'sda_family_report6.json'", "'build/reports/sda_family_report6.json'"),

    # tu_completion_ranking.py — output path
    @("tools/tu_completion_ranking.py", "'tu_ranking_full.json'", "'build/reports/tu_ranking_full.json'"),
    # legacy TU scout
    @("tools/legacy_analysis/tu_scout_enum.py", "'tu_ranking_full.json'", "'build/reports/tu_ranking_full.json'"),

    # wall_classification.json — read and write
    @("tools/classify_version_diff.py", '"wall_classification.json"', '"build/reports/wall_classification.json"'),
    @("tools/deep_classify.py",        "'wall_classification.json'", "'build/reports/wall_classification.json'"),
    @("tools/deep_classify2.py",       "'wall_classification.json'", "'build/reports/wall_classification.json'"),
    @("tools/inspect_walls.py",        "'wall_classification.json'", "'build/reports/wall_classification.json'"),

    # missing_functions_report.txt
    @("tools/find_missing_functions.py", "'missing_functions_report.txt'",    "'build/reports/missing_functions_report.txt'"),
    @("tools/goldmine_matcher.py",       '"missing_functions_report.txt"',    '"build/reports/missing_functions_report.txt"'),
    @("tools/scout_tu.py",              "'missing_functions_report.txt'",     "'build/reports/missing_functions_report.txt'"),

    # targetable_functions.txt + version_diff_functions.txt
    @("tools/classify_functions.py", "'targetable_functions.txt'",     "'build/reports/targetable_functions.txt'"),
    @("tools/classify_functions.py", "'version_diff_functions.txt'",   "'build/reports/version_diff_functions.txt'"),

    # matched_stats.json
    @("tools/count_matched.py",  "'matched_stats.json'", "'build/reports/matched_stats.json'"),
    @("tools/dedup_matched.py",  "'matched_stats.json'", "'build/reports/matched_stats.json'"),
    @("tools/experimental/dedup_inspect.py",     "'matched_stats.json'", "'build/reports/matched_stats.json'"),
    @("tools/experimental/dedup_verify.py",      "'matched_stats.json'", "'build/reports/matched_stats.json'"),
    @("tools/experimental/dedup_verify_seq.py",  "'matched_stats.json'", "'build/reports/matched_stats.json'"),

    # vtable_report.md
    @("tools/build_vtable_report.py", "'vtable_report.md'", "'build/reports/vtable_report.md'")
)

$updated = @{}
foreach ($r in $replacements) {
    $file = $r[0]
    $old  = $r[1]
    $new  = $r[2]

    if (-not (Test-Path $file)) {
        Write-Host "  SKIP (not found): $file" -ForegroundColor Yellow
        continue
    }

    $content = Get-Content $file -Raw
    if ($content.Contains($old)) {
        $content = $content.Replace($old, $new)
        Set-Content $file -Value $content -NoNewline
        $updated[$file] = $true
        Write-Host "  Updated: $file" -ForegroundColor Green
    } else {
        Write-Host "  SKIP (pattern not found): $file - looking for $old" -ForegroundColor Yellow
    }
}

# Also fix the goldmine_matcher.py docstring reference
$gm = "tools/goldmine_matcher.py"
if (Test-Path $gm) {
    $content = Get-Content $gm -Raw
    $content = $content.Replace(
        "from missing_functions_report.txt",
        "from build/reports/missing_functions_report.txt"
    )
    Set-Content $gm -Value $content -NoNewline
    $updated[$gm] = $true
}

# Also fix the print message in build_vtable_report.py
$vt = "tools/build_vtable_report.py"
if (Test-Path $vt) {
    $content = Get-Content $vt -Raw
    $content = $content.Replace(
        "Report written to vtable_report.md",
        "Report written to build/reports/vtable_report.md"
    )
    Set-Content $vt -Value $content -NoNewline
}

# Also fix print messages in count_matched.py and dedup_matched.py
foreach ($f in @("tools/count_matched.py", "tools/dedup_matched.py")) {
    if (Test-Path $f) {
        $content = Get-Content $f -Raw
        $content = $content.Replace("saved to matched_stats.json", "saved to build/reports/matched_stats.json")
        Set-Content $f -Value $content -NoNewline
    }
}

$count = $updated.Count
Write-Host "`nUpdated $count tool scripts" -ForegroundColor Cyan

if ($count -gt 0) {
    git add tools/
    $msg = "cleanup: update $count tool scripts to use build/reports/ paths"
    git commit -m $msg
    Write-Host "Committed path updates" -ForegroundColor Green
}

Pop-Location
