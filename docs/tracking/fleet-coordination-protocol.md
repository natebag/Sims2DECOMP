# Fleet Coordination Protocol

> **Tag:** `git-concurrency-discipline`  
> **Last updated:** 2026-05-21  
> **Applies to:** All fleet workers performing git writes (stage, commit, reset, checkout)

---

## 1. Incident Summary (2026-05-21)

**Root cause:** Concurrent agent git operations produced lock-file contention.
- `.git/index.lock` kept reappearing as a 0-byte stale lock.
- Reviewer encountered `index file smaller than expected`.
- SonnetWorker resolved by running `git reset HEAD` (rebuilt index from HEAD).

**Impact:** Fleet-wide hold declared. All commits and stages blocked until repo state confirmed clean.

---

## 2. Git Concurrency Discipline (Mandatory)

Any worker that performs a git write **must** follow this sequence:

### 2.1 Pre-flight Lock Check

Before running **any** git command that modifies the index or working tree (`git add`, `git commit`, `git reset`, `git checkout`, `git rm`, `git mv`):

1. Check whether `.git/index.lock` exists.
2. If the lock exists:
   - Wait **5–10 seconds**.
   - Re-check.
   - If still present, repeat up to a reasonable timeout (max ~120 s).
3. If the lock is **stale** (age > 30 s, no `git.exe` processes running), remove it and proceed.
4. If the lock is **stuck** (mtime unchanged for ≥ 30 s while git processes are alive), treat as an error and escalate to MainGuy.

### 2.2 Serialized Commit Path

**All commits must use the centralized helper:**

```bash
tools/git_safe_stage_and_commit.sh -m "<message>" <path1> [path2] ...
```

**Why this script:**
- It implements the pre-flight lock check internally (`wait_for_index_clear`).
- It detects stale locks (no git procs + age > 30 s) and removes them safely.
- It detects steady-state stuck locks (mtime unchanged for ≥ 30 s) and removes them.
- It uses `git commit --only` so that concurrent workers' staged files are **not scooped** into each other's commits.

**Do NOT:**
- Run bare `git add` + `git commit -m` directly.
- Run `git commit` without `--only` or explicit path arguments.
- Assume the index is in a clean state because you just checked.

### 2.3 Post-write Verification

After any commit:
- Verify `git status` shows a clean (or expected) working tree.
- If `git status` reports `index file smaller than expected`, run:
  ```bash
  git reset HEAD
  ```
  This rebuilds the index from HEAD without touching the working tree.

---

## 3. Lock-State Heuristics

| Condition | Action |
|---|---|
| No `.git/index.lock` | Proceed immediately. |
| Lock present, age < 30 s, git procs running | Wait 2 s, re-check. |
| Lock present, age ≥ 30 s, **no** git procs | Remove stale lock, proceed. |
| Lock present, age ≥ 30 s, git procs running, mtime **changing** | Wait 5 s, re-check (active operation). |
| Lock present, age ≥ 30 s, git procs running, mtime **steady** ≥ 30 s | Remove stuck lock, proceed **and report to MainGuy**. |

---

## 4. Fleet-Wide Tagging

When creating issues, checklists, or incident notes related to this protocol, use:

```
git-concurrency-discipline
```

This tag covers:
- Lock contention incidents
- Index corruption recoveries
- Script/tooling improvements to `git_safe_stage_and_commit.sh`
- Worker onboarding notes about git safety

---

## 5. Script Reference

- **`tools/git_safe_stage_and_commit.sh`** — wrapper: lock-wait → stage → delegate commit
- **`tools/git_safe_commit.sh`** — core commit helper with `--only` and lock-wait logic

Both scripts are MSYS2/Windows-aware and include Python fallbacks for `stat` portability.

---

## 6. Checklist for New Workers

- [ ] I have read this protocol.
- [ ] I will use `tools/git_safe_stage_and_commit.sh` for all commits.
- [ ] I will check `.git/index.lock` before any manual `git add` / `git reset` / `git checkout`.
- [ ] I know to run `git reset HEAD` if I see `index file smaller than expected`.
- [ ] I will report any stuck lock (steady mtime + active git procs > 30 s) to MainGuy.
