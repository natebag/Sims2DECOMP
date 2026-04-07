# Inline ASM Stub Workflow

**Purpose:** Convert inline ASM stubs in `src/asm_decomp/*.cpp` to real C++ decompilation.

## Workflow Steps

### 1. Identify Target Function
- Find function in `src/asm_decomp/*.cpp` with inline ASM stub
- Note the address, size, and class structure from the stub

### 2. Extract DOL Bytes
```python
import struct

data = open('extracted/sys/main.dol', 'rb').read()
base_addr = 0x800034C0
base_off = 0x0004C0

addr = 0x800A76AC  # Target address
size = 0x50        # Target size

file_off = base_off + (addr - base_addr)
func_data = data[file_off:file_off+size]
for j in range(0, size, 4):
    word = struct.unpack('>I', func_data[j:j+4])[0]
    print(f'  {addr+j:08X}: {word:08X}')
```

### 3. Analyze ASM Pattern
From the inline ASM stub, identify:
- Input parameters (r3 = this, r4-r10 = args)
- Return register (usually r3)
- Memory access patterns (offsets from pointers)
- Branch conditions

### 4. Decode Logic
Key instruction patterns:
- `lwz rX, offset(rY)` - Load word from memory
- `cmpwi rX, value` - Compare with immediate
- `beq/bne/ble/bgt` - Branch conditions
- `slwi rX, rY, n` - Shift left (multiply by 2^n)
- `lwzx rX, rY, rZ` - Indexed load

### 5. Reconstruct C++
- Declare matching class structure
- Implement logic following DOL control flow
- Use variable declaration order to influence register allocation
- First declared → r31, second → r30, etc. for callee-saved regs

### 6. Verify
```bash
bash tools/verify_match.sh <source.cpp> <addr> <size>
```

### 7. Iterate
- If MISMATCH: analyze diff, adjust struct layout or variable order
- Common issues: wrong offsets, extra indirection, register allocation

## Example: QuickStringSet::GetString

**Target:** 0x800A76AC, 80B

**ASM Analysis:**
```asm
lwz   r9, 8(r3)       # Load from this+8
cmpwi r9, 0           # Check if null
beq   return_0
cmpwi r4, 0           # Check if index <= 0
ble   return_0
lwz   r11, 0(r9)      # Load from ptr+0 (double indirection)
li    r0, 0
cmpwi r11, 0
beq   skip_count
lwz   r0, -4(r11)     # Load count from array-4
skip_count:
cmpw  r4, r0          # Check index <= count
ble   compute_result
return_0:
li    r3, 0
blr
compute_result:
addi  r9, r4, -1      # index - 1
slwi  r9, r9, 2       # (index - 1) * 4
lwzx  r3, r11, r9     # Load string pointer
blr
```

**Key Findings:**
- Double indirection: this+8 → ptr → array
- Count stored at array-4
- 1-based indexing (index-1 for array access)

**Blocker:** Register allocation differs between DOL and compiler.
- DOL uses: r9, r11, r0
- Compiler uses: r11, r9, r4

This suggests the original source had specific local variable declarations that forced this allocation.

## Common Patterns

### Array Access with Count
```cpp
// Count stored at offset -4 from array
int count = ((int*)array)[-1];
```

### 1-based Indexing
```cpp
// Convert 1-based to 0-based
return array[index - 1];
```

### Double Indirection
```cpp
// Pointer to pointer
char** stringArray = *ptrToArray;
```

## Status

**Workflow piloted:** 2026-04-07
**Function tested:** QuickStringSet::GetString (0x800A76AC)
**Result:** MISMATCH - register allocation differs
**Next steps:** Try variable declaration order technique or check if struct layout has hidden fields
