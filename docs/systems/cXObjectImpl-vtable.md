# cXObjectImpl Vtable Layout

## Class Structure Overview

cXObjectImpl has a complex inheritance hierarchy with **at least two vtable pointers** accessed through different indirection paths:

### Vtable Access Patterns

**Primary vtable (via r9, loaded from sub-object at field 0x04):**
- Access: `lwz r9, 4(this); lwz r11, 0(r9); lha adj, OFF(r11); lwz func, OFF+4(r11)`
- Or: `lwz r9, 0(this); ... similar pattern`
- This is the MAIN vtable used by 90%+ of virtual calls
- Vtable entries span from offset 0x008 to 0x520+

**Secondary vtable (via r11, loaded from different sub-object):**
- Fewer calls, different vtable entries
- Entries at 0x018-0x4CC range
- Used for a secondary interface/base class

### Vtable Pointer Location in cXObjectImpl

From the destructor analysis:
```
stw r9, 236(r31)   # this[0xEC] = vtable pointer (direct vtable in class)
```

From constructor/destructor patterns accessing sub-objects:
```
lwz r10, 4(r31)    # field_04 = sub-object pointer
lwz r9, 0(r10)     # sub_object->vtable
stw r0, 24(r9)     # vtable[24] = data
```

**Key findings:**
- **Offset 0xEC (236)**: Direct vtable pointer stored in the class
- **Offset 0x00**: Pointer to sub-object 1 (TreeSim-related)
- **Offset 0x04**: Pointer to sub-object 2 (main vtable dispatch target)
- Sub-objects at field_00 and field_04 have their OWN vtable pointers at their offset 0

### SN Systems Vtable Entry Format

Each vtable entry is 8 bytes:
```
struct VTEntry {
    short thisAdjustment;  // +0: signed 16-bit this-pointer delta (lha instruction)
    short _padding;        // +2: unused
    void* funcPtr;         // +4: function pointer (lwz instruction)
};
```

## Primary Vtable Slots (r9 dispatch, from sub-object at field_04)

Most-called slots listed by frequency:

| Slot Offset | Calls | Likely Function |
|-------------|-------|-----------------|
| 0x488/0x48C | 58 | (most frequent — core behavior dispatch) |
| 0x110/0x114 | 54 | |
| 0x520/0x524 | 51 | |
| 0x018/0x01C | 46 | |
| 0x318/0x31C | 39 | |
| 0x048/0x04C | 28 | |
| 0x010/0x014 | 27 | |
| 0x260/0x264 | 26 | |
| 0x058/0x05C | 22 | |
| 0x328/0x32C | 18 | |
| 0x368/0x36C | 18 | |
| 0x390/0x394 | 19 | |
| 0x020/0x024 | 14 | |
| 0x130/0x134 | 14 | |
| 0x0B8/0x0BC | 13 | |
| 0x100/0x104 | 12 | |
| 0x2B8/0x2BC | 12 | |
| 0x030/0x034 | 11 | |
| 0x138/0x13C | 11 | |

### Full Primary Vtable Map

Each entry is 8 bytes (delta + funcptr). Total slots = max_offset / 8.

Highest observed offset: 0x520 → (0x520/8) + 1 = **165 virtual functions minimum**.

```
Offset  Slot#  Calls  Notes
0x008   1      6      
0x010   2      27     
0x018   3      46     HIGH FREQUENCY
0x020   4      14     
0x028   5      3      
0x030   6      11     
0x038   7      10     
0x040   8      10     
0x048   9      28     HIGH FREQUENCY
0x050   10     9      
0x058   11     22     
0x060   12     9      
0x068   13     5      
0x070   14     9      
0x078   15     7      
0x080   16     6      
0x088   17     3      
0x090   18     10     
0x098   19     7      
0x0A0   20     7      
0x0A8   21     7      
0x0B0   22     1      
0x0B8   23     13     
0x0C8   25     1      
0x0D0   26     2      
0x0D8   27     6      
0x0E0   28     2      
0x0E8   29     7      
0x0F0   30     5      
0x0F8   31     1      
0x100   32     12     
0x108   33     3      
0x110   34     54     HIGHEST FREQUENCY (except 0x488)
0x118   35     1      
0x120   36     7      
0x128   37     10     
0x130   38     14     
0x138   39     11     
0x140   40     1      
0x148   41     4      
0x150   42     4      
0x158   43     5      
0x160   44     5      
0x168   45     1      
0x188   49     4      (gap: slots 46-48 unused)
0x190   50     4      
0x198   51     8      
0x1A0   52     3      
0x1A8   53     8      
0x1B0   54     9      
0x1B8   55     4      
0x1C0   56     3      
0x1D0   58     10     (gap: slot 57)
0x1D8   59     3      
0x1E0   60     2      
0x1E8   61     6      
0x1F0   62     4      
0x200   64     1      (gap: slot 63)
0x210   66     3      (gap: slot 65)
0x218   67     5      
0x240   72     2      (gap: slots 68-71)
0x248   73     3      
0x250   74     7      
0x258   75     1      
0x260   76     26     HIGH FREQUENCY
0x270   78     9      (gap: slot 77)
0x288   81     1      (gap: slots 79-80)
0x2A0   84     2      (gap: slots 82-83)
0x2B0   86     10     (gap: slot 85)
0x2B8   87     12     
0x2C0   88     10     
0x2D0   90     3      (gap: slot 89)
0x2E8   93     1      (gap: slots 91-92)
0x2F0   94     1      
0x2F8   95     3      
0x300   96     4      
0x308   97     10     
0x310   98     2      
0x318   99     39     HIGH FREQUENCY
0x328   101    18     (gap: slot 100)
0x330   102    4      
0x338   103    2      
0x348   105    1      (gap: slot 104)
0x350   106    3      
0x358   107    4      
0x360   108    2      
0x368   109    18     
0x378   111    4      (gap: slot 110)
0x380   112    1      
0x388   113    2      
0x390   114    19     
0x398   115    2      
0x3A0   116    2      
0x3F8   127    2      (gap: slots 117-126)
0x400   128    2      
0x418   131    1      (gap: slots 129-130)
0x448   137    1      (gap: slots 132-136)
0x450   138    2      
0x458   139    1      
0x470   142    3      (gap: slots 140-141)
0x478   143    3      
0x480   144    5      
0x488   145    58     HIGHEST FREQUENCY — core dispatch
0x490   146    9      
0x498   147    2      
0x4A8   149    5      (gap: slot 148)
0x4B8   151    2      (gap: slot 150)
0x4C8   153    6      (gap: slot 152)
0x4E0   156    2      (gap: slots 154-155)
0x4F8   159    1      (gap: slots 157-158)
0x500   160    1      
0x510   162    1      (gap: slot 161)
0x518   163    2      
0x520   164    51     HIGH FREQUENCY — second most called
```

## Secondary Vtable Slots (r11 dispatch)

| Slot Offset | Calls |
|-------------|-------|
| 0x018/0x01C | 1 |
| 0x020/0x024 | 1 |
| 0x030/0x034 | 1 |
| 0x048/0x04C | 1 |
| 0x068/0x06C | 1 |
| 0x080/0x084 | 1 |
| 0x088/0x08C | 1 |
| 0x098/0x09C | 2 |
| 0x1F0/0x1F4 | 3 |
| 0x2D0/0x2D4 | 2 |
| 0x318/0x31C | 1 |
| 0x328/0x32C | 2 |
| 0x350/0x354 | 1 |
| 0x378/0x37C | 1 |
| 0x488/0x48C | 2 |
| 0x4C8/0x4CC | 1 |

## Key Class Fields (from field access analysis)

| Offset | Size | Type | Access Count | Description |
|--------|------|------|-------------|-------------|
| 0x000 | 4 | ptr | 658 | Sub-object pointer 1 (TreeSim-related) |
| 0x004 | 4 | ptr | 784 | Sub-object pointer 2 (main vtable dispatch) |
| 0x008 | 4 | int/ptr | 30 | |
| 0x00C | 4 | int/ptr | 29 | |
| 0x010 | 4 | int/ptr | 31 | |
| 0x016 | 2 | short | 53 | Frequently accessed short field |
| 0x018 | 2+4 | mixed | 36 | Short + float/int overlapping |
| 0x058 | 4 | ptr | 42 | Frequently read pointer |
| 0x064 | 2 | short | 19 | |
| 0x068 | 4 | ptr | 18 | |
| 0x06C | 4 | ptr | 16 | |
| 0x080 | 4 | ptr | 22 | |
| 0x0B6 | 2 | u16 | 10 | (lhz only — unsigned short) |
| 0x0DC | 4 | int | 14 | Read+write (flag field?) |
| 0x0E0 | 4 | float | 15 | Frequently written float |
| 0x0E4 | 4 | int | 10 | Write-only (store count?) |
| 0x0EC | 4 | vtptr | 6 | **VTABLE POINTER** |
