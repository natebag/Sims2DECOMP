Read the Build Roadmap section of CLAUDE.md. Identify the current milestone (marked `IN PROGRESS`) and the next unchecked `[ ]` gate criteria.

Then:
1. Print a brief status summary: what milestones are done, what's current, what's next
2. Read `docs/tracking/next-steps.md` for detailed task breakdown of the current lane
3. Read `docs/tracking/progress.md` for current decomp metrics
4. Check `extracted/files/u2_ngc_release.map` if you need symbol references for the next task
5. Propose a plan for the next task(s) and ask for confirmation before starting

If all gate criteria in the current milestone are checked, mark it `DONE`, find the next milestone, mark it `IN PROGRESS`, and proceed with that milestone instead.

Use the decomp-planner or ghidra-analyst agent approach when tackling new functions. Spawn cpp-reviewer agents in parallel for code review after writing C++.

For any function you decompile:
1. Find the symbol in the map file
2. Analyze the disassembly (either via Ghidra project or by examining the ELF)
3. Write matching C++ code
4. Verify with decomp-toolkit that it byte-matches
5. Update progress tracking
