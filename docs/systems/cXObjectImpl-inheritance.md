# cXObjectImpl Inheritance Chain

## Inheritance Hierarchy

Based on map file analysis and vtable symbols:

```
TreeSim (base class)
    │   Size: ~176 bytes (0xB0)
    │   VTable: 0x805FAF48
    │
    ├── cXObject (inherits from TreeSim)
    │       Size: ~240 bytes + TreeSim base
    │       VTable: 0x805E33B0 ("cXObject::TreeSim virtual table")
    │       Constructor: 0x80189E88 (cXObject::cXObject(int))
    │       Destructor: 0x80175D24 (cXObject::~cXObject(void))
    │
    └── cXObjectImpl (has TreeSim vtable but separate hierarchy)
            Size: ~240 bytes (includes TreeSim at offset 0xF0/240)
            VTable: 0x805E2DD0 ("cXObjectImpl::TreeSim virtual table")
            Constructor: 0x800D962C (cXObjectImpl::cXObjectImpl(int, ObjSelector*, ObjectModule*))
            Destructor: 0x800DBC54 (cXObjectImpl::~cXObjectImpl(void))
```

## Evidence

### 1. TreeSim Base Class

**Map file entries:**
- `805faf48` - TreeSim virtual table
- `805fae98` - TreeSimImpl::TreeSim virtual table
- `8020c6b4` - TreeSim::TreeSim(void) constructor

### 2. cXObject Inheritance

**Map file entries:**
- `805e33b0` - cXObject::TreeSim virtual table (indicates cXObject has TreeSim)
- `80189e88` - cXObject::cXObject(int) constructor
- `80175d24` - cXObject::~cXObject(void) destructor

### 3. cXObjectImpl Inheritance

**Map file entries:**
- `805e2dd0` - cXObjectImpl::TreeSim virtual table (indicates cXObjectImpl has TreeSim)
- `80175ecc` - cXObjectImpl::cXObjectImpl(int, ObjSelector*, ObjectModule*) constructor
- `800dbc54` - cXObjectImpl::~cXObjectImpl(void) destructor

### 4. Constructor Analysis

From `src/asm_decomp/cXObjectImpl.cpp` constructor at 0x800D962C:
```asm
// Line 230: Calls TreeSim::TreeSim(void) at 0x8020C6B4
.long 0x4806e041  /* bl TreeSim::TreeSim(void) */
```

This confirms cXObjectImpl directly contains or inherits from TreeSim.

## Related Classes

Other classes with TreeSim in their inheritance chain:

| Class | TreeSim VTable Address |
|-------|------------------------|
| cXMTObject | 0x805DB640 |
| cXMTObjectImpl | 0x805DAFF8 |
| cXObject | 0x805E33B0 |
| cXObjectImpl | 0x805E2DD0 |
| cXPerson | 0x805F2DE8 |
| cXPersonImpl | 0x805F2950 |
| cXPortal | 0x805F4C60 |
| cXPortalImpl | 0x805F45E8 |
| TreeSim | 0x805FAF48 |
| TreeSimImpl | 0x805FAE98 |

## Key Findings

1. **cXObjectImpl contains TreeSim as a base class**, not cXObject directly
2. **TreeSim vtable is at offset 0xF0 (240)** in cXObjectImpl based on constructor analysis
3. **Multiple inheritance pattern**: cXObjectImpl has its own TreeSim vtable separate from cXObject's
4. The constructor calls `TreeSim::TreeSim(void)` explicitly

## Next Steps

1. Determine exact TreeSim size by analyzing TreeSim constructor
2. Map cXObjectImpl fields relative to TreeSim base
3. Identify vtable pointer location within cXObjectImpl
4. Build complete struct layout with all field offsets
