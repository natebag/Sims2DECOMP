# cXObjectImpl Heavy Functions (200-300 bytes) - Analysis

## Task: 1d5fc964-a8d6-4f9b-8b45-43616223c078

### Functions Being Analyzed
1. **cXObjectImpl::TryPreloadObject** (200 bytes at 0x801abf5c / DVD 0x80100C84)
2. **cXObjectImpl::TryParticleEffect** (204 bytes at 0x801b435c / DVD 0x80108384)
3. **cXObjectImpl::TryHUDManage** (208 bytes at 0x801bb510 / DVD 0x8010EC30)
4. **cXObjectImpl::GosubObjectTree** (212 bytes at 0x801b6364 / DVD 0x80109DF0)
5. **cXObjectImpl::TryChangeWantFearTree** (224 bytes at 0x801b523c / DVD 0x80109264)
6. **cXObjectImpl::GetShortComboValue** (252 bytes at 0x801b6f98 / DVD 0x8010AA24)
7. **cXObjectImpl::Simulate** (280 bytes at 0x801b569c / DVD 0x801096C4)
8. **cXObjectImpl::TryTutorial** (284 bytes at 0x801aa180 / DVD 0x800FF1DC)
9. **cXObjectImpl::TryShowString** (284 bytes at 0x801b0e48 / DVD 0x80105420)
10. **cXObjectImpl::TryTestObjectType** (288 bytes at 0x801a4c38 / DVD 0x800FA1F4)

## Common Patterns Identified

### Try* Functions Pattern
```
1. Setup frame (stwu 1,-XX(1), mflr 0, stmw RR,YY(1))
2. Load parameters
3. Call InterpValue() to evaluate behavior tree condition
4. Check return (-1 = error)
5. If success, do virtual dispatch or direct function call
6. Store result in stack element
7. Return (0, 1) or (-1, -1) for errors
```

### Virtual Method Dispatch
- Load vtable: `lwz 9, 0(3)`
- Load offset from vtable: `lha 0, OFFSET(9)`
- Get function ptr: `lwz 9, OFFSET+4(9)`
- Call: `mtlr 9; blrl`

### InterpValue Call Pattern
```
lwz 3, 4(31)        // Load context
lha 5, 4(9)         // Load opcode from param
lbz 4, 6(9)         // Load type from param
li 6, 0; li 7, 0    // Setup registers
addi 8, 1, 8        // Stack addr for output
bl InterpValue      // Evaluate condition
cmpwi 3, -1         // Check for error
beq .error_label    // Branch if error
```

### Behavior Tree Return Pattern
- Success: return 0 (r3=0, r4=1) or 1 (r3=1, r4=0)
- Error: return -1 (r3=-1, r4=-1)
- Used for branching decisions in behavior tree interpreter

## Status
- NEEDS VERIFICATION via verify_match.sh with SN compiler
- All implementations in src/wip/ for refinement
- Ready for OpusWorker verification pass

## Notes for Implementer
- These functions are behavior tree primitives
- They interact heavily with the behavior tree interpreter (InterpValue)
- Virtual dispatch patterns are consistent across the class
- Stack frame sizes vary (24-48 bytes typically)
- Some functions use SDA (r13) for global state access
