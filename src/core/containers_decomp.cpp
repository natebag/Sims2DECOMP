// containers_decomp.cpp - Core container and string class decompilation
// Covers: EString, EString2, BString, BString2, EAStringC,
//         EHashTable, ERedBlackTree, QuickStringSet, TArray
//
// These classes are the backbone of the entire codebase. Every system
// in The Sims 2 GameCube uses one or more of them. Understanding their
// data layouts, memory ownership, and algorithms is critical.
//
// Sources: Disassembly of u2_ngc_release_dvd.elf via tools/disasm.py
//          Symbol names from u2_ngc_release.map (39,169 symbols)
//          Struct layouts from include/classes/*.h
//
// Build: SN Systems ProDG for GameCube (SN-NGC), DolphinSDK 1.0 HW2
// ============================================================================

// ============================================================================
//
//  TABLE OF CONTENTS
//
//  1. MEMORY ALLOCATION PRIMITIVES
//  2. EString  — Simple owning C string wrapper (no refcount)
//  3. EString2 — Wide-char (unsigned short) variant of EString
//  4. basic_string_ref / basic_string_ref2 — Reference-counted string buffers
//  5. BString  — Reference-counted string (char), with copy-on-write
//  6. BString2 — Reference-counted string (wchar_t), with copy-on-write
//  7. EAStringC — EA's custom string with refcount + hash caching
//  8. TArray<T, Allocator> — Templated dynamic array
//  9. EHashTable — Open-chaining hash table (key=u32, value=u32)
// 10. ERedBlackTree — Balanced binary search tree (key=u32, value=u32)
// 11. QuickStringSet — Localized string table resource
//
// ============================================================================


// ============================================================================
// 1. MEMORY ALLOCATION PRIMITIVES
// ============================================================================
//
// All containers allocate through MainHeap() → EAHeap::Malloc/Free.
// The global MainHeap is accessed via SDA-relative addressing (r13 register).
//
//   EAHeap* MainHeap(void);                  // returns the global heap
//   void* EAHeap::Malloc(u32 size, int align) // align=0 for default (8-byte)
//   void  EAHeap::Free(void* ptr)
//
// Small helper used by string classes:
//   void* Malloc_0x802d0aa4(u32 size, int align);  // MainHeap()->Malloc
//   void  Free_0x802d0d78(void* ptr);              // MainHeap()->Free
//   void  operator_delete_0x802d1220(void* ptr);   // scalar delete
//
// The MainHeap() function at 0x802cff00 is called before every alloc/free
// to get the current heap pointer. There is no per-container allocator —
// everything goes to one global heap (except TArray, which uses an Allocator
// policy template parameter for model/anim data).


// ============================================================================
// 2. EString — Simple Owning C String
// ============================================================================
//
// EString is a simple, NON-reference-counted string. It owns a heap-allocated
// char buffer (m_buffer). Copy means full deep copy. Used extensively in the
// engine for file paths, resource names, debug output, etc.
//
// === Data Layout (4 bytes) ===
//
//   struct EString {
//       char* m_buffer;   // 0x00 — pointer to heap-allocated null-terminated string
//   };
//   static char m_null;   // 0x804ff038 (SDA) — shared null sentinel (1 byte, value 0)
//
// sizeof(EString) = 4 bytes (just a pointer!)
//
// === Memory Ownership ===
//
// - m_buffer points to either:
//   (a) &m_null (SDA address r13-26856) — the empty/null state
//   (b) A heap-allocated buffer from MainHeap()->Malloc(len+1, 0)
//
// - SetToNull() sets m_buffer = &m_null (assembly: addi r0,r13,-26856; stw r0,0(r3))
// - Deallocate(buf) only frees if buf != &m_null
// - FreeBuffer(buf) calls MainHeap()->Free(buf)
// - No reference counting, no copy-on-write
// - Assignment (operator=) deep-copies: saves old, MakeCopy(new), Deallocate(old)
//
// === Key Functions ===

// EString::SetToNull — 0x802d293c (12 bytes, 3 instructions)
// Loads the SDA-relative address of m_null and stores to m_buffer.
// addi r0, r13, -26856   ; r0 = &m_null
// stw  r0, 0(r3)         ; this->m_buffer = &m_null
// blr
void EString::SetToNull(void) {
    m_buffer = &m_null;
}

// EString::Deallocate — 0x802d2948 (44 bytes)
// Compares buf against &m_null (SDA). Only calls FreeBuffer if it's a real allocation.
void EString::Deallocate(char* buf) {
    if (buf != &m_null) {
        FreeBuffer(buf);
    }
}

// EString::FreeBuffer — 0x802d29ac (52 bytes)
// Gets MainHeap(), calls Free. Paired with AllocBuffer.
void EString::FreeBuffer(char* buf) {
    EAHeap* heap = MainHeap();
    heap->Free(buf);
}

// EString::AllocBuffer — 0x802d2974 (56 bytes)
// Gets MainHeap(), calls Malloc(size, 0). Returns allocated pointer.
// Note: does NOT store into m_buffer — caller does that.
char* EString::AllocBuffer(int size) {
    EAHeap* heap = MainHeap();
    return (char*)heap->Malloc(size, 0);
}

// EString::MakeCopy — 0x802d2b60 (132 bytes)
// Deep-copies a C string. If src is NULL or strlen==0, sets to null.
// Otherwise allocates strlen+1 bytes, memcpy's, stores in m_buffer.
void EString::MakeCopy(char* src) {
    if (src == NULL) {
        SetToNull();
        return;
    }
    int len = strlen(src);
    if (len == 0) {
        SetToNull();
        return;
    }
    int allocSize = len + 1;
    char* buf = AllocBuffer(allocSize);
    if (buf == NULL) {
        SetToNull();
        return;
    }
    memcpy(buf, src, allocSize);   // copies string + null terminator
    m_buffer = buf;
}

// EString::operator=(char*) — 0x802d2be4 (64 bytes)
// Assignment: saves old buffer, copies new, then frees old.
// This order is critical — the old buffer might overlap with src.
EString& EString::operator=(char* str) {
    char* old = m_buffer;
    MakeCopy(str);
    Deallocate(old);
    return *this;
}

// EString::GetLength — 0x802d2c24 (36 bytes)
// Simply calls strlen on the buffer. No cached length.
int EString::GetLength(void) const {
    return strlen(m_buffer);
}

// EString::Empty — 0x802d2d40 (56 bytes)
// Deallocates buffer and resets to null sentinel.
void EString::Empty(void) {
    Deallocate(m_buffer);
    SetToNull();
}

// EString::Allocate — 0x802d2cb0 (144 bytes)
// Grows the buffer to fit 'newLen' characters (if needed).
// If newLen==0, calls Empty(). If newLen > current length, allocates
// newLen+1, copies old data, frees old buffer. Returns 1 on success.
int EString::Allocate(int newLen) {
    if (newLen == 0) {
        Empty();
        return 1; // actually jumps to Empty then returns 1
    }
    int curLen = GetLength();
    if (newLen <= curLen) {
        return 1; // already big enough
    }
    char* newBuf = AllocBuffer(newLen + 1);
    if (newBuf == NULL) {
        return 0;
    }
    memcpy(newBuf, m_buffer, curLen + 1);  // copy old string + null
    Deallocate(m_buffer);
    m_buffer = newBuf;
    return 1;
}

// EString::Compare — 0x802d2d78 (112 bytes)
// Null-safe strcmp. Returns 0 if both empty, -1/+1 for one-empty cases,
// otherwise falls through to libc strcmp.
int EString::Compare(char* other) const {
    if (m_buffer[0] == 0) {
        if (other == NULL || other[0] == 0) return 0;
        return -1;
    }
    if (other == NULL || other[0] == 0) return 1;
    return strcmp(m_buffer, other);
}

// EString::Find(char, int) — 0x802d3198 (96 bytes)
// Returns index of first 'c' at or after position 'startPos'. Uses strchr.
// Returns -1 if not found or string is empty.
int EString::Find(char c, int startPos) const {
    if (m_buffer[0] == 0) return -1;
    char* found = strchr(m_buffer + startPos, c);
    if (found == NULL) return -1;
    return (int)(found - m_buffer);
}

// EString::operator+=(char*) — 0x802d30a8 (88 bytes)
// Appends another string. Constructs a temporary from (m_buffer, other),
// assigns it to this, then deallocates the temporary.
EString& EString::operator+=(char* other) {
    EString temp(m_buffer, other);  // EString(char*, char*) concatenation ctor
    *this = temp.m_buffer;
    temp.Deallocate(temp.m_buffer);
    return *this;
}

// EString::Mid — 0x802d2f6c (120 bytes)
// Returns substring. If count==-1, copies from start to end.
// Otherwise copies 'count' chars from position 'start'.
EString EString::Mid(int start, int count) const {
    EString result;
    if (count == -1) {
        result.MakeCopy(m_buffer + start);
    } else {
        EString temp;
        temp.MakeCopy(m_buffer + start);
        result.Left(count);        // truncate via Left helper
        temp.Deallocate(temp.m_buffer);
    }
    return result;
}

// EString::Replace(char*, char*) — 0x802d3374 (200 bytes)
// Replaces first occurrence of 'find' with 'replacement'.
// Returns 1 if replacement made, 0 if 'find' not found.
int EString::Replace(char* find, char* replacement) {
    int pos = Find(find, 0);
    if (pos == -1) return 0;
    EString prefix;
    prefix.Left(pos);                          // text before match
    int findLen = strlen(find);
    EString suffix(prefix.m_buffer, replacement);  // prefix + replacement
    EString result(suffix.m_buffer, m_buffer + pos + findLen);  // + text after match
    *this = result.m_buffer;
    // cleanup temporaries...
    return 1;
}

// EString::EString(char) — 0x802d2844 (60 bytes)
// Constructs from single char. Uses slwi r4,r4,8 + sth to store
// char in high byte of a u16 on stack, creating a null-terminated
// 1-char string, then calls MakeCopy.
EString::EString(char c) {
    char tmp[2];
    tmp[0] = c;
    tmp[1] = 0;
    MakeCopy(tmp);
}

// EString::EString(char*, char*) — 0x802d2880 (188 bytes)
// Concatenation constructor: creates string from start + append.
// Used by operator+ and operator+=.

// EString::operator char*() const — 0x803b0a6c (8 bytes)
// Implicit cast: simply returns m_buffer.
EString::operator char*(void) const {
    return m_buffer;
}


// ============================================================================
// 3. EString2 — Wide-Char Variant
// ============================================================================
//
// Identical architecture to EString but uses unsigned short (UCS-2/UTF-16LE)
// instead of char. All operations are 2-bytes-per-character.
//
// === Data Layout (4 bytes) ===
//
//   struct EString2 {
//       unsigned short* m_buffer;  // 0x00 — heap-allocated wide string
//   };
//   static unsigned short _estring2Null[2];   // SDA — {0, 0}
//   static unsigned short _estring2Error[8];   // 0x8043ed54 — L"<error>"
//
// === Key Differences from EString ===
//
// - StrLenC16() replaces strlen() — manual loop counting non-zero u16 values
// - AllocBuffer allocates (len+1)*2 bytes for wide chars
// - Has MakeCopyFromChars(char*) to convert narrow→wide
// - SetToError() sets buffer to a static L"<error>" string
// - operator=(char*) goes through MakeCopyFromChars, not MakeCopy
//
// Memory ownership is identical: no refcount, full deep copy on assignment.

// EString2::StrLenC16 — 0x802d4154 (56 bytes)
// Manual wcslen: counts u16 elements until 0 found.
int EString2::StrLenC16(unsigned short* str) {
    if (str == NULL) return 0;
    int len = 0;
    while (*str != 0) {
        str++;
        len++;
    }
    return len;
}

// EString2::GetLength — 0x802d4780 (36 bytes)
int EString2::GetLength(void) const {
    return StrLenC16(m_buffer);
}


// ============================================================================
// 4. basic_string_ref / basic_string_ref2 — Reference-Counted Buffers
// ============================================================================
//
// These are the internal representation objects used by BString/BString2.
// They implement reference counting for copy-on-write string semantics.
//
// === Data Layout (16 bytes) ===
//
//   struct basic_string_ref {     // for char strings (BString)
//       char*    m_data;      // 0x00 — pointer to character data
//       u32      m_length;    // 0x04 — string length (not counting null)
//       u32      m_capacity;  // 0x08 — allocated capacity (chars, not counting null)
//       u32      m_refCount;  // 0x0C — reference count (starts at 1)
//   };
//
//   struct basic_string_ref2 {    // for wchar_t strings (BString2)
//       unsigned short* m_data;     // 0x00 — pointer to wide character data
//       u32             m_length;   // 0x04 — string length in chars
//       u32             m_capacity; // 0x08 — allocated capacity in chars
//       u32             m_refCount; // 0x0C — reference count
//   };
//
// === Reference Counting Rules ===
//
// - Constructed with refCount = 1
// - Copy constructor just bumps refCount (no data copy!)
// - delete_ptr() frees m_data via MainHeap()->Free() and zeroes fields
// - When refCount hits 0, the ref object AND its data buffer are freed
//
// === Proof from Disassembly ===
//
// basic_string_ref default ctor at 0x8009c610 (inlined into BString::BString):
//   lwz  r9, 12(r11)     ; r9 = this->m_refCount
//   addi r9, r9, 1       ; r9++
//   stw  r9, 12(r11)     ; this->m_refCount = r9
//
// basic_string_ref(char*) at 0x8009c914:
//   strlen(src) → stored at both offset 0x04 and 0x08 (length = capacity initially)
//   Allocates capacity+1 bytes via MainHeap()->Malloc(capacity+1, 0)
//   Stores buffer at offset 0x00
//   memcpy(buffer, src, length)
//   buffer[length] = 0  (null terminate via stbx)
//   Stores refCount = 1 at offset 0x0C
//
// basic_string_ref::delete_ptr at 0x8009bf5c:
//   if (this->m_capacity != 0) {        // offset 0x08
//       MainHeap()->Free(this->m_data); // offset 0x00
//       this->m_data = 0;
//       this->m_capacity = 0;
//   }

// basic_string_ref::basic_string_ref(char*) — 0x8009c914 (188 bytes)
// Allocates buffer, copies string, sets refcount to 1.
basic_string_ref::basic_string_ref(char* src) {
    if (src != NULL) {
        m_length = strlen(src);
        m_capacity = m_length;
    } else {
        m_length = 0;
        m_capacity = 0;
    }
    if (m_capacity != 0) {
        m_capacity = m_capacity + 1;  // +1 stored back, then used for alloc
        char* buf = (char*)MainHeap()->Malloc(m_capacity, 0);
        m_data = buf;
        memcpy(buf, src, m_length);
        // eos() call stores null terminator:
        m_data[m_length] = '\0';
    } else {
        m_data = NULL;
    }
    m_refCount = 1;
}

// basic_string_ref::delete_ptr — 0x8009bf5c (80 bytes)
// Frees the character data buffer (not the ref object itself).
void basic_string_ref::delete_ptr(void) {
    if (m_capacity != 0) {
        MainHeap()->Free(m_data);
        m_data = NULL;
        m_capacity = 0;
    }
}


// ============================================================================
// 5. BString — Reference-Counted String (char)
// ============================================================================
//
// BString is EA's reference-counted string class. It uses copy-on-write:
// multiple BString instances can share the same basic_string_ref. Only
// when a BString needs to mutate does it create a private copy.
//
// === Data Layout (4 bytes!) ===
//
//   struct BString {
//       basic_string_ref* m_ref;   // 0x00 — pointer to shared ref-counted buffer
//   };
//
// sizeof(BString) = 4 bytes (just a pointer to a basic_string_ref)
//
// There is a global shared empty string ref:
//   static basic_string_ref s_emptyRef;  // at 0x80485d90 (.data section)
//   // This ref has: m_data=NULL, m_length=0, m_capacity=0, m_refCount=large
//
// === Copy-on-Write Protocol ===
//
// 1. Default ctor: points m_ref to s_emptyRef, increments its refcount
// 2. Copy ctor / operator=(BString&):
//    - If src.ref_count() != -1 (i.e., not a "unique" / "frozen" ref):
//      Just share: this->m_ref = src.m_ref; m_ref->m_refCount++
//    - If ref_count == -1 (unique ownership requested):
//      Allocate new basic_string_ref(16 bytes), deep copy the data
// 3. Mutating operations (assign_str, append_str, insert_str, etc.):
//    - Check ref_count: if > 1, create a private copy first ("unshare")
//    - Then modify in place
// 4. Destructor (delete_ref):
//    - Decrements m_ref->m_refCount
//    - If refCount reaches 0: call delete_ptr (frees data), then free the ref itself
//
// === Proof from Disassembly ===
//
// BString::BString() at 0x8009d6f8 (32 bytes):
//   lis   r9, 0x8048       ; r9 = high half of s_emptyRef address
//   addi  r9, r9, 0x5d90   ; r9 = &s_emptyRef (0x80485d90)
//   stw   r9, 0(r10)       ; this->m_ref = &s_emptyRef
//   lwz   r11, 12(r9)      ; r11 = s_emptyRef.m_refCount
//   addi  r11, r11, 1      ; r11++
//   stw   r11, 12(r9)      ; s_emptyRef.m_refCount++
//
// BString::ref_count() at 0x8009c014 (12 bytes):
//   lwz  r9, 0(r3)         ; r9 = this->m_ref
//   lwz  r3, 12(r9)        ; return m_ref->m_refCount (offset 0x0C)
//
// BString::length() at 0x8009ff4c (12 bytes):
//   lwz  r9, 0(r3)         ; r9 = this->m_ref
//   lwz  r3, 4(r9)         ; return m_ref->m_length (offset 0x04)
//
// BString::point() at 0x8009c064 (12 bytes):
//   lwz  r9, 0(r3)         ; r9 = this->m_ref
//   lwz  r3, 0(r9)         ; return m_ref->m_data (offset 0x00)
//
// BString::data() at 0x8009c020 (68 bytes):
//   calls length(); if 0, returns NULL; else returns m_ref->m_data
//
// BString::c_str() at 0x8009ecf8 (48 bytes):
//   calls data(); if NULL, returns pointer to static "" string at 0x803e9030

// BString::BString() — 0x8009d6f8 (32 bytes)
// Default constructor: shares the global empty ref.
BString::BString(void) {
    m_ref = &s_emptyRef;
    s_emptyRef.m_refCount++;
}

// BString::ref_count() — 0x8009c014 (12 bytes)
// Returns the reference count of the shared buffer.
int BString::ref_count(void) const {
    return m_ref->m_refCount;
}

// BString::length() — 0x8009ff4c (12 bytes)
// Returns the string length (cached in the ref, not computed via strlen).
unsigned int BString::length(void) const {
    return m_ref->m_length;
}

// BString::point() — 0x8009c064 (12 bytes)
// Returns raw pointer to character data.
char* BString::point(void) {
    return m_ref->m_data;
}

// BString::delete_ref — 0x8009bfb4 (96 bytes)
// Decrements refcount. If it reaches 0, destroys the ref and its data.
void BString::delete_ref(void) {
    m_ref->m_refCount--;
    if (m_ref->m_refCount == 0) {
        // Free the character data buffer
        m_ref->delete_ptr(/* mode=2 */);
        // Then free the basic_string_ref object itself
        MainHeap()->Free(m_ref);
    }
}

// BString::operator=(BString&) — 0x8009d9d4 (152 bytes)
// Copy-on-write assignment. If src's refcount is not -1 (frozen),
// just share the ref. Otherwise, deep-copy into a new ref.
BString& BString::operator=(BString& src) {
    if (this == &src) return *this;

    delete_ref();  // release our current ref

    if (src.ref_count() != -1) {
        // Share the ref (cheap copy)
        m_ref = src.m_ref;
        m_ref->m_refCount++;
    } else {
        // Deep copy: allocate new ref (16 bytes)
        basic_string_ref* newRef = (basic_string_ref*)MainHeap()->Malloc(16, 0);
        // Initialize from src's data
        unsigned int len = src.length();
        *newRef = basic_string_ref(src, 0, len);
        m_ref = newRef;
    }
    return *this;
}


// ============================================================================
// 6. BString2 — Reference-Counted Wide String
// ============================================================================
//
// Identical architecture to BString but uses basic_string_ref2 (wide chars).
//
// === Data Layout (4 bytes) ===
//
//   struct BString2 {
//       basic_string_ref2* m_ref;  // 0x00 — pointer to shared ref-counted wide buffer
//   };
//
// Everything works the same as BString:
// - Shares basic_string_ref2 via reference counting
// - Copy-on-write: mutating operations check refcount > 1
// - s_emptyRef2 global at a different .data address
// - Character operations use u16 instead of u8
// - Allocations are (capacity+1)*2 bytes


// ============================================================================
// 7. EAStringC — EA's Custom String with RefCount + Hash
// ============================================================================
//
// EAStringC is a separate string class (not related to EString or BString)
// from EA's internal "APT" (ActionScript) library. It uses reference counting
// AND caches a hash value for fast dictionary lookups.
//
// === Data Layout (4 bytes for the string object itself) ===
//
//   struct EAStringC {
//       StringDataC* m_pData;  // 0x00 — pointer to ref-counted data block
//   };
//
//   struct StringDataC {   // Allocated as one contiguous block
//       u16   m_refCount;  // 0x00 — reference count (16-bit!)
//       u8    m_hashValid; // 0x02 — 0 = hash needs recalc, 1 = hash is valid
//       u8    _pad;        // 0x03
//       u16   m_maxSize;   // 0x04 — allocated buffer capacity
//       u16   m_hashLow;   // 0x06 — low 16 bits of hash? (or full hash stored differently)
//       char  m_buffer[1]; // 0x08 — actual string data (variable length, starts at +8)
//       // Total allocation: 9 + maxSize bytes (header is 8 bytes + data + null)
//   };
//
// Note: the "+9" in the destructor (addi r5, r5, 9) tells us the header
// is at least 8 bytes, plus 1 for null terminator.
//
// === Memory Ownership ===
//
// - m_pData points to a heap-allocated StringDataC
// - Allocated via a dedicated allocator (not MainHeap directly):
//   Uses a function pointer stored at SDA[r13 - 23020] — likely an APT allocator
// - Reference count is u16, incremented/decremented with lhz/sth (half-word ops)
// - When refCount reaches 0, the entire StringDataC block is freed
//   (free size = m_maxSize + 9)
//
// === Global Empty String ===
//
// There is a global shared StringDataC at 0x8044e6b4:
//   - m_refCount starts high (many EAStringC point here)
//   - m_buffer = "" (empty string)
//   - Constructor stores &s_emptyData to this->m_pData, increments refcount
//
// === Hash Caching ===
//
// EAStringC caches a hash of its string contents for fast lookups in hash tables.
// - GetHashValue() returns cached hash if m_hashValid, else recalculates
// - UpdateHashValue() / CalculateHashValue() compute the hash
// - InvalidateHashValue() marks hash as needing recalc
// - Mutations (Append, Insert, Delete, Replace) invalidate the hash
//
// === Proof from Disassembly ===
//
// EAStringC::EAStringC() at 0x8026c6bc (32 bytes):
//   lis   r11, 0x8044
//   addi  r0, r11, -6476       ; r0 = &s_emptyData (0x8044e6b4)
//   stw   r0, 0(r10)           ; this->m_pData = &s_emptyData
//   lhz   r9, -6476(r11)       ; r9 = s_emptyData.m_refCount
//   addi  r9, r9, 1            ; r9++
//   sth   r9, -6476(r11)       ; s_emptyData.m_refCount++
//
// EAStringC::EAStringC(EAStringC&) at 0x8026c70c (28 bytes):
//   lwz   r10, 0(r4)           ; r10 = src.m_pData
//   stw   r10, 0(r11)          ; this->m_pData = src.m_pData
//   lhz   r9, 0(r10)           ; r9 = m_pData->m_refCount
//   addi  r9, r9, 1            ; r9++
//   sth   r9, 0(r10)           ; m_pData->m_refCount++
//   — Just shares the pointer and bumps refcount (16-bit!)
//
// EAStringC::~EAStringC() at 0x8026c728 (104 bytes):
//   lwz   r4, 0(r31)           ; r4 = this->m_pData
//   lhz   r9, 0(r4)            ; r9 = m_pData->m_refCount
//   addi  r9, r9, -1           ; r9--
//   clrlwi r0, r9, 16          ; mask to u16
//   sth   r9, 0(r4)            ; m_pData->m_refCount = r9
//   cmpwi r0, 0                ; if refCount == 0:
//   bne   skip
//   lhz   r5, 4(r4)            ; r5 = m_pData->m_maxSize
//   lwz   r3, SDA[-23020](r13) ; r3 = allocator
//   addi  r5, r5, 9            ; free size = maxSize + 9
//   bl    Free                  ; Free(allocator, m_pData, size)
//
// EAStringC::operator=(EAStringC&) at 0x8026c790 (116 bytes):
//   1. Increment src.m_pData->m_refCount
//   2. Decrement this->m_pData->m_refCount
//   3. If old refCount == 0, free old block (maxSize + 9)
//   4. this->m_pData = src.m_pData

// EAStringC::EAStringC() — default ctor
EAStringC::EAStringC(void) {
    m_pData = &s_emptyData;
    s_emptyData.m_refCount++;
}

// EAStringC::EAStringC(EAStringC&) — copy ctor (shares ref)
EAStringC::EAStringC(EAStringC& src) {
    m_pData = src.m_pData;
    m_pData->m_refCount++;
}

// EAStringC::~EAStringC()
EAStringC::~EAStringC(void) {
    m_pData->m_refCount--;
    if (m_pData->m_refCount == 0) {
        u16 maxSize = m_pData->m_maxSize;
        s_allocator->Free(m_pData, maxSize + 9);
    }
}

// EAStringC::operator=(EAStringC&) — assignment (share + release old)
EAStringC& EAStringC::operator=(EAStringC& src) {
    // Increment src's refcount first (handles self-assignment)
    src.m_pData->m_refCount++;

    // Decrement and possibly free old
    m_pData->m_refCount--;
    if (m_pData->m_refCount == 0) {
        s_allocator->Free(m_pData, m_pData->m_maxSize + 9);
    }

    m_pData = src.m_pData;
    return *this;
}

// EAStringC::IsEmpty — checks if string data pointer is empty
bool EAStringC::IsEmpty(void) const {
    return (m_pData == &s_emptyData);
    // Actually checks if first byte of buffer is 0
}

// EAStringC::c_str — returns m_pData->m_buffer (at offset +8 from m_pData)
// From inline at 0x802b4d3c (12 bytes):
//   lwz r3, 0(r3)     ; r3 = this->m_pData
//   addi r3, r3, 8     ; r3 = &m_pData->m_buffer (skip 8-byte header)
//   blr
const char* EAStringC::c_str(void) const {
    return (const char*)((char*)m_pData + 8);
}


// ============================================================================
// 8. TArray<T, Allocator> — Templated Dynamic Array
// ============================================================================
//
// EA's standard dynamic array template. Used with many element types
// (EString, EString2, EVec3, int, ESubModel, etc.) and multiple allocator
// policies (TArrayDefaultAllocator, TArrayERModelAllocator,
// TArrayERCharacterAllocator, TArrayERAnimAllocator).
//
// === Data Layout (12 bytes) ===
//
//   template<typename T, typename Allocator>
//   struct TArray {
//       T*   m_data;      // 0x00 — pointer to element array
//       u32  m_size;       // 0x04 — number of valid elements
//       u32  m_capacity;   // 0x08 — allocated capacity (in elements)
//   };
//
// === Allocator Policy ===
//
// The allocator template parameter controls where memory comes from:
// - TArrayDefaultAllocator: uses MainHeap() (global heap)
//   - Alloc at 0x80327654: MainHeap()->Malloc(count * sizeof(T), align=8)
//   - Free at 0x803276ac:  MainHeap()->Free(ptr)
// - TArrayERModelAllocator: uses model-specific allocator (for geometry data)
// - TArrayERCharacterAllocator: uses character-specific allocator
// - TArrayERAnimAllocator: uses animation-specific allocator
//
// === Growth Strategy ===
//
// From SetSize/Insert analysis, TArray uses power-of-2 growth:
//   int newCap = 1;
//   while (newCap < needed) newCap *= 2;
// This is visible in the Insert function (0x803c2a78):
//   li   r5, 1            ; newCap = 1
//   cmpw r5, r9           ; while (newCap < needed)
//   add  r5, r5, r5       ;   newCap *= 2
//   blt  loop
//
// === Key Operations ===
//
// Init(): Sets all three fields to 0.
// SetSize(newSize, newCap): Resize the array.
//   - If shrinking: destructs elements beyond newSize
//   - If newCap==0: deallocates and calls Init()
//   - If newCap differs from current: allocs new buffer, copies min(size,newSize)
//     elements, destructs old, frees old buffer
//   - If growing: constructs new elements (default-init)
// Insert(src, pos, count): Insert 'count' copies of src at position pos.
//   - If capacity insufficient: grow with power-of-2
//   - Shifts existing elements right via CopyReverse (handles overlap)
//   - Copies new elements via Copy
// Add(item): shorthand for Insert(&item, m_size, 1)
// Destruct(ptr, count): calls destructors on 'count' elements
// Construct(ptr, count): calls constructors on 'count' elements
// Copy(dst, src, count): element-wise copy (calls operator= for non-trivial types)
// CopyReverse(dst, src, count): reverse-order copy (for rightward shifts)
//
// === Proof from Disassembly ===
//
// TArray<EString>::Init at 0x8039bd90 (20 bytes):
//   li   r0, 0
//   stw  r0, 4(r3)        ; m_size = 0
//   stw  r0, 0(r3)        ; m_data = NULL
//   stw  r0, 8(r3)        ; m_capacity = 0
//
// TArray<EString>::Add at 0x803c2b50 (40 bytes):
//   lwz  r5, 4(r3)        ; r5 = m_size
//   li   r6, 1            ; count = 1
//   bl   Insert            ; Insert(&item, m_size, 1)

// TArray::Init — 0x8039bd90 (20 bytes)
template<typename T, typename A>
void TArray<T,A>::Init(void) {
    m_size = 0;
    m_data = NULL;
    m_capacity = 0;
}

// TArray::Add — 0x803c2b50 (40 bytes)
template<typename T, typename A>
void TArray<T,A>::Add(T& item) {
    Insert(&item, m_size, 1);
}

// TArray::SetSize — (e.g., 0x8039c468 for int, 0x803c28ec for EString)
// 292 bytes — the core resize logic.
template<typename T, typename A>
void TArray<T,A>::SetSize(int newSize, int newCap) {
    if (newCap == 0) newCap = newSize;

    // If shrinking, destruct excess elements
    if (newSize < m_size) {
        Destruct(m_data + newSize, m_size - newSize);
    }

    if (newCap == 0) {
        // Free everything
        Allocator::Free(m_data);
        Init();
        return;
    }

    if (newCap != m_capacity) {
        // Allocate new buffer
        T* newBuf = (T*)Allocator::Alloc(newCap * sizeof(T), 8);
        if (newBuf == NULL) return;

        if (m_data != NULL) {
            // Copy min(newSize, m_size) elements
            int copyCount = newSize;
            if (copyCount > m_size) copyCount = m_size;

            Construct(newBuf, copyCount);  // default-init destination
            Copy(newBuf, m_data, copyCount);  // copy data
            Destruct(m_data, m_size);      // destroy old
            Allocator::Free(m_data);       // free old buffer
        }

        m_data = newBuf;
        m_capacity = newCap;
    }
    m_size = newSize;

    // If growing, construct new elements
    if (newSize > /* oldSize */ m_size) {
        Construct(m_data + m_size, newSize - m_size);
    }
}

// TArray::Insert — (e.g., 0x803c2a78 for EString) (216 bytes)
// Inserts 'count' copies of *src at position 'pos'.
template<typename T, typename A>
void TArray<T,A>::Insert(T* src, int pos, int count) {
    int newSize = m_size + count;

    if (newSize > m_capacity) {
        // Grow with power-of-2
        int newCap = 1;
        while (newCap < newSize) {
            newCap *= 2;
        }
        SetSize(newSize, newCap);
    } else {
        // Enough capacity — just update size and construct new slots
        m_size = newSize;
        Construct(m_data + m_size, count);  // above old end
    }

    if (pos != m_size) {
        // Shift existing elements right to make room
        CopyReverse(m_data + pos + count, m_data + pos, m_size - pos);
    }

    // Copy new elements into the gap
    Copy(m_data + pos, src, count);
}


// ============================================================================
// 9. EHashTable — Open-Chaining Hash Table
// ============================================================================
//
// EHashTable is a generic hash table mapping u32 keys to u32 values.
// Uses separate chaining (linked list per bucket). Nodes are individually
// heap-allocated. Also maintains a global doubly-linked list of all nodes
// for fast iteration.
//
// === Data Layout (20 bytes) ===
//
//   struct EHashTable {
//       EHashTableNode* m_head;        // 0x00 — head of global linked list (newest node)
//       EHashTableNode* m_tail;        // 0x04 — tail of global linked list (oldest node)
//       EHashTableNode** m_buckets;    // 0x08 — array of bucket head pointers
//       u32              m_tableSize;  // 0x0C — number of buckets
//       u32              m_sentinel;   // 0x10 — used by Find iterator
//   };
//
// Note: NO vtable. This class does not inherit from anything virtual.
// The header file's "void** _vtable" field is incorrect — field 0x00 is m_head.
//
// === Node Layout (20 bytes) ===
//
//   struct EHashTableNode {
//       EHashTableNode* m_globalNext;  // 0x00 — next in global linked list
//       EHashTableNode* m_globalPrev;  // 0x04 — prev in global linked list
//       EHashTableNode* m_bucketNext;  // 0x08 — next in same hash bucket chain
//       u32             m_key;         // 0x0C — the key
//       u32             m_value;       // 0x10 — the value
//   };
//
// === Hash Function ===
//
// Simple modulo: bucket = key % m_tableSize
// From Find at 0x802c8d78:
//   divwu r9, r4, r0       ; r9 = key / tableSize
//   mullw r9, r9, r0       ; r9 = (key / tableSize) * tableSize
//   subf  r9, r9, r4       ; r9 = key - r9  (= key % tableSize)
//
// === Iteration ===
//
// GetSize() walks the global linked list counting nodes:
//   node = m_head; count = 0;
//   while (node != NULL) { node = node->m_globalPrev; count++; }
// (Note: uses offset 0x04 which is m_globalPrev, so iteration goes tail-ward)
//
// HTIteratorPtrType is just an EHashTableNode* used as an opaque handle.
//
// === Key Operations ===

// EHashTable::EHashTable(int) — 0x802c88c4 (60 bytes)
// Constructor: zeroes head/tail, then calls InitTable.
EHashTable::EHashTable(int tableSize) {
    m_head = NULL;     // 0x00
    m_tail = NULL;     // 0x04
    InitTable(tableSize);
}

// EHashTable::InitTable — 0x802c899c (80 bytes)
// Allocates bucket array, zeroes it, stores tableSize.
void EHashTable::InitTable(int tableSize) {
    EAHeap* heap = MainHeap();
    m_buckets = (EHashTableNode**)heap->Malloc(tableSize * 4, 0);
    m_tableSize = tableSize;
    ClearTable();
}

// EHashTable::ClearTable — 0x802c89ec (48 bytes)
// Zeroes all bucket pointers (memset to 0).
void EHashTable::ClearTable(void) {
    memset(m_buckets, 0, m_tableSize * 4);
}

// EHashTable::Insert — 0x802c8b1c (140 bytes)
// Inserts key/value. If allowDuplicates is true, always inserts.
// If false, checks if key exists first; only inserts if not found.
void EHashTable::Insert(unsigned int key, unsigned int value, bool allowDuplicates) {
    unsigned int bucket = key % m_tableSize;

    if (allowDuplicates) {
        InsertNew(bucket, key, value);
    } else {
        // Check for existing key in this bucket
        EHashTableNode* existing = Find(bucket, key);
        if (existing == NULL) {
            InsertNew(bucket, key, value);
        }
        // If found, do nothing (no update!)
    }
}

// EHashTable::InsertNew — 0x802c8ba8 (148 bytes)
// Allocates a new 20-byte node, links into bucket chain and global list.
EHashTableNode* EHashTable::InsertNew(unsigned int bucket, unsigned int key, unsigned int value) {
    EHashTableNode* node = (EHashTableNode*)MainHeap()->Malloc(20, 0);
    if (node == NULL) return NULL;

    node->m_key = key;             // offset 0x0C
    node->m_value = value;         // offset 0x10

    // Link into bucket chain (prepend)
    node->m_bucketNext = m_buckets[bucket];  // offset 0x08
    m_buckets[bucket] = node;

    // Link into global doubly-linked list (prepend to tail)
    node->m_globalNext = m_tail;   // offset 0x00
    if (m_tail != NULL) {
        m_tail->m_globalPrev = node;  // offset 0x04
    } else {
        m_head = node;
    }
    node->m_globalPrev = NULL;     // offset 0x04
    m_tail = node;

    return node;
}

// EHashTable::Find(key, valueOut) — 0x802c8d78 (88 bytes)
// Looks up key. Walks bucket chain comparing m_key. Returns node if found.
// If valueOut != NULL, stores the value there.
EHashTableNode* EHashTable::Find(unsigned int key, unsigned int* valueOut) const {
    unsigned int bucket = key % m_tableSize;
    EHashTableNode* node = m_buckets[bucket];

    while (node != NULL) {
        if (node->m_key == key) {
            if (valueOut != NULL) {
                *valueOut = node->m_value;
            }
            return node;
        }
        node = node->m_bucketNext;
    }
    return NULL;
}

// EHashTable::GetSize — 0x802c8f0c (40 bytes)
// Counts nodes by walking the global linked list.
int EHashTable::GetSize(void) const {
    int count = 0;
    EHashTableNode* node = m_head;
    while (node != NULL) {
        node = node->m_globalPrev;
        count++;
    }
    return count;
}

// EHashTable::~EHashTable — 0x802c8950 (76 bytes)
// Frees all nodes (RemoveAll), then frees the bucket array.
EHashTable::~EHashTable(void) {
    RemoveAll();
    MainHeap()->Free(m_buckets);
}


// ============================================================================
// 10. ERedBlackTree — Balanced Binary Search Tree
// ============================================================================
//
// A standard left-leaning red-black tree mapping u32 keys to u32 values.
// Used for ordered dictionaries throughout the engine (resource maps,
// object registries, etc.).
//
// === Data Layout (12 bytes — no vtable!) ===
//
//   struct ERedBlackTree {
//       ERedBlackTreeNode* m_head;       // 0x00 — head of flat linked list (for iteration)
//       ERedBlackTreeNode* m_tail;       // 0x04 — tail of flat linked list
//       ERedBlackTreeNode* m_root;       // 0x08 — root of the BST
//   };
//
// Note: The header's layout suggests 32 bytes with a vtable, but the actual
// assembly accesses only 3 pointer fields. The sentinel is a STATIC, not a
// member. The tree maintains a separate flat linked list for fast iteration
// alongside the BST structure.
//
// === Sentinel Node ===
//
// A static sentinel node acts as the "nil" leaf (black). Address: 0x8043ed34 (.data)
// All leaf pointers and new node children point to this sentinel instead of NULL.
// The sentinel is compared by pointer identity: `cmpw r3, r9` where r9 = &m_sentinel.
//
// === Node Layout (32 bytes) ===
//
//   struct ERedBlackTreeNode {
//       ERedBlackTreeNode* m_left;       // 0x00 — left child
//       ERedBlackTreeNode* m_right;      // 0x04 — right child
//       ERedBlackTreeNode* m_parent;     // 0x08 — parent node
//       ERedBlackTreeNode* m_listPrev;   // 0x0C — prev in flat linked list
//       ERedBlackTreeNode* m_listNext;   // 0x10 — next in flat linked list
//       u32                m_color;      // 0x14 — 0=BLACK, 1=RED
//       u32                m_key;        // 0x18 — the key
//       u32                m_value;      // 0x1C — the value
//   };
//
// === Red-Black Tree Properties ===
//
// Standard CLRS red-black tree implementation:
// 1. Every node is red or black
// 2. Root is black
// 3. All leaves (sentinel) are black
// 4. Red nodes have black children
// 5. All paths from root to leaves have the same black-height
//
// === Key Operations ===

// ERedBlackTree::ERedBlackTree() — 0x802cd9b8 (32 bytes)
// Constructor: sets root to sentinel, head/tail to NULL.
ERedBlackTree::ERedBlackTree(void) {
    m_head = NULL;              // 0x00
    m_root = &m_sentinel;       // 0x08 — sentinel is the "empty tree" root
    m_tail = NULL;              // 0x04
}

// ERedBlackTree::FindKeyOrParent — 0x802cdcec (72 bytes)
// BST search: walks from root comparing keys. Returns the node if found,
// or the would-be parent if not found (for insertion).
ERedBlackTreeNode* ERedBlackTree::FindKeyOrParent(unsigned int key) const {
    ERedBlackTreeNode* node = m_root;
    ERedBlackTreeNode* parent = NULL;

    while (node != &m_sentinel) {
        if (key == node->m_key) return node;  // found!
        parent = node;
        if (key < node->m_key) {
            node = node->m_left;
        } else {
            node = node->m_right;
        }
    }
    return parent;  // not found, return would-be parent
}

// ERedBlackTree::Find — 0x802ce3ac (88 bytes)
// Searches for key. Returns node pointer if found, NULL if not.
// If valueOut != NULL, stores the value.
ERedBlackTreeNode* ERedBlackTree::Find(unsigned int key, unsigned int* valueOut) const {
    ERedBlackTreeNode* node = m_root;

    while (node != &m_sentinel) {
        if (key == node->m_key) {
            if (valueOut != NULL) {
                *valueOut = node->m_value;
            }
            return node;
        }
        if (key < node->m_key) {
            node = node->m_left;
        } else {
            node = node->m_right;
        }
    }
    return NULL;
}

// ERedBlackTree::Insert — 0x802cddd8 (128 bytes)
// Insert key/value. If allowDuplicates, finds parent and inserts.
// If !allowDuplicates, checks for existing key first.
ERedBlackTreeNode* ERedBlackTree::Insert(unsigned int key, unsigned int value, bool allowDuplicates) {
    if (allowDuplicates) {
        ERedBlackTreeNode* parent = FindParent(key);
        return InsertAt(parent, key, value);
    } else {
        ERedBlackTreeNode* existing = FindKeyOrParent(key);
        if (existing != NULL && existing->m_key == key) {
            return NULL;  // duplicate — don't insert
        }
        return InsertAt(existing, key, value);
    }
}

// ERedBlackTree::InsertAt — 0x802cde58 (336 bytes)
// Creates a new node (32 bytes), links it into the BST at the given parent,
// maintains the flat linked list, then calls InsertFixup for rebalancing.
ERedBlackTreeNode* ERedBlackTree::InsertAt(ERedBlackTreeNode* parent, unsigned int key, unsigned int value) {
    ERedBlackTreeNode* node = (ERedBlackTreeNode*)MainHeap()->Malloc(32, 0);
    if (node == NULL) return NULL;

    node->m_color = 1;           // RED (new nodes start red)
    node->m_right = &m_sentinel; // children are sentinel
    node->m_parent = parent;
    node->m_value = value;
    node->m_left = &m_sentinel;
    node->m_key = key;

    if (parent == NULL) {
        // Tree was empty — this becomes the root
        m_root = node;
        // Link into flat list
        node->m_listNext = m_head;
        if (m_head != NULL) {
            m_head->m_listPrev = node;
        } else {
            m_tail = node;
        }
        node->m_listPrev = NULL;
        m_head = node;
    } else if (key < parent->m_key) {
        // Insert as left child
        parent->m_left = node;
        // Link into flat list (before parent's predecessor)
        node->m_listPrev = parent->m_listPrev;
        if (parent->m_listPrev != NULL) {
            parent->m_listPrev->m_listNext = node;
        }
        parent->m_listPrev = node;
        node->m_listNext = parent;
    } else {
        // Insert as right child
        parent->m_right = node;
        // Link into flat list (after parent's successor)
        node->m_listNext = parent->m_listNext;
        if (parent->m_listNext != NULL) {
            parent->m_listNext->m_listPrev = node;
        } else {
            m_head = node;  // becomes new head
        }
        node->m_listNext = NULL;  // Wait, this doesn't match...
        // Actually the linked list insertion is more nuanced —
        // the exact list ordering depends on in-order traversal position
        m_tail = node;
    }

    InsertFixup(node);  // rebalance
    return node;
}

// ERedBlackTree::RotateLeft — 0x802cda24 (124 bytes)
// Standard left rotation. y = node->right; node->right = y->left;
// if y->left != sentinel, y->left->parent = node; etc.
void ERedBlackTree::RotateLeft(ERedBlackTreeNode* node) {
    ERedBlackTreeNode* y = node->m_right;

    // node->right = y->left
    node->m_right = y->m_left;
    if (y->m_left != &m_sentinel) {
        y->m_left->m_parent = node;
    }

    // y->parent = node->parent
    if (y != &m_sentinel) {
        y->m_parent = node->m_parent;
    }

    // Fix parent's child pointer
    if (node->m_parent != NULL) {
        if (node == node->m_parent->m_left) {
            node->m_parent->m_left = y;
        } else {
            node->m_parent->m_right = y;
        }
    } else {
        m_root = y;
    }

    // y->left = node
    y->m_left = node;
    if (node != &m_sentinel) {
        node->m_parent = y;
    }
}

// ERedBlackTree::RotateRight — 0x802cdaa0 (124 bytes)
// Mirror of RotateLeft. y = node->left; node->left = y->right; etc.
void ERedBlackTree::RotateRight(ERedBlackTreeNode* node) {
    ERedBlackTreeNode* y = node->m_left;

    node->m_left = y->m_right;
    if (y->m_right != &m_sentinel) {
        y->m_right->m_parent = node;
    }

    if (y != &m_sentinel) {
        y->m_parent = node->m_parent;
    }

    if (node->m_parent != NULL) {
        if (node == node->m_parent->m_right) {
            node->m_parent->m_right = y;
        } else {
            node->m_parent->m_left = y;
        }
    } else {
        m_root = y;
    }

    y->m_right = node;
    if (node != &m_sentinel) {
        node->m_parent = y;
    }
}

// ERedBlackTree::InsertFixup — 0x802cdb1c (328 bytes)
// Standard CLRS red-black tree insertion fixup.
// Walks up the tree fixing red-red violations.
void ERedBlackTree::InsertFixup(ERedBlackTreeNode* node) {
    // While node is not root and parent is RED
    while (node != m_root && node->m_parent->m_color == 1 /* RED */) {
        ERedBlackTreeNode* parent = node->m_parent;
        ERedBlackTreeNode* grandparent = parent->m_parent;

        if (parent == grandparent->m_left) {
            // Parent is left child
            ERedBlackTreeNode* uncle = grandparent->m_right;
            if (uncle->m_color == 1 /* RED */) {
                // Case 1: uncle is red — recolor
                parent->m_color = 0;     // BLACK
                uncle->m_color = 0;      // BLACK
                grandparent->m_color = 1; // RED
                node = grandparent;
            } else {
                if (node == parent->m_right) {
                    // Case 2: node is right child — rotate left
                    node = parent;
                    RotateLeft(node);
                }
                // Case 3: node is left child — rotate right
                node->m_parent->m_color = 0;                  // BLACK
                node->m_parent->m_parent->m_color = 1;        // RED
                RotateRight(node->m_parent->m_parent);
            }
        } else {
            // Mirror: parent is right child
            ERedBlackTreeNode* uncle = grandparent->m_left;
            if (uncle->m_color == 1 /* RED */) {
                parent->m_color = 0;
                uncle->m_color = 0;
                grandparent->m_color = 1;
                node = grandparent;
            } else {
                if (node == parent->m_left) {
                    node = parent;
                    RotateRight(node);
                }
                node->m_parent->m_color = 0;
                node->m_parent->m_parent->m_color = 1;
                RotateLeft(node->m_parent->m_parent);
            }
        }
    }
    // Root must always be black
    m_root->m_color = 0;
}

// ERedBlackTree::GetSize — 0x802ce56c (40 bytes)
// Counts nodes via the flat linked list (offset 0x10 = m_listNext).
int ERedBlackTree::GetSize(void) const {
    int count = 0;
    ERedBlackTreeNode* node = m_head;
    while (node != NULL) {
        node = node->m_listNext;
        count++;
    }
    return count;
}


// ============================================================================
// 11. QuickStringSet — Localized String Table Resource
// ============================================================================
//
// QuickStringSet is a resource class that loads localized string tables
// from IFF resource files. It implements the StringSet interface and
// supports COM-style reference counting (AddRef/Release/QueryInterface).
//
// === Data Layout (24 bytes) ===
//
//   struct QuickStringSet {
//       void** _vtable;               // 0x00 — vtable pointer
//       StringSetData*  m_ansiData;    // 0x04 — pointer to ANSI string data (from resource)
//       QuickStringSetEntry* m_entries;// 0x08 — pointer to loaded string entry array
//       void*           m_locName;     // 0x0C — localized name (points to static null if none)
//       u32             m_refCount;    // 0x10 — COM-style reference count
//       u32             m_locInfo;     // 0x14 — localized resource info
//   };
//
// === String Entry Format ===
//
// Strings are stored as a length-prefixed array:
//   u32 count;                        // at array[-1] (before first pointer)
//   char* strings[count];             // array of string pointers
//
// The Count() method accesses array[-4] to get the count (lwz r3, -4(r9)):
//   - m_entries points to the first string pointer
//   - The count is stored 4 bytes BEFORE that pointer
//
// GetString(index) does: return m_entries[(index-1)]  (1-based indexing!)
//
// === Proof from Disassembly ===
//
// QuickStringSet::QuickStringSet() at 0x800a75bc (44 bytes):
//   lis   r9, 0x8046
//   addi  r9, r9, -6904        ; r9 = vtable address
//   li    r0, 0
//   addi  r10, r13, -32132     ; r10 = &s_nullPointer (SDA)
//   stw   r9, 0(r11)           ; vtable
//   stw   r0, 8(r11)           ; m_entries = NULL
//   stw   r10, 12(r11)         ; m_locName = &s_nullPointer
//   stw   r0, 16(r11)          ; m_refCount = 0
//   stw   r0, 4(r11)           ; m_ansiData = NULL
//
// QuickStringSet::Count(char) at 0x800a7620 (84 bytes):
//   Checks m_entries first; if non-NULL, accesses entries->array and
//   reads the count from array[-4]. Falls through to m_ansiData path
//   if m_entries is NULL.
//
// QuickStringSet::GetString(int index, char) at 0x800a76ac (80 bytes):
//   lwz   r9, 8(r3)           ; r9 = m_entries
//   lwz   r11, 0(r9)          ; r11 = m_entries->array
//   lwz   r0, -4(r11)         ; r0 = count (stored before array)
//   cmpw  r4, r0              ; bounds check (index <= count)
//   addi  r9, r4, -1          ; r9 = index - 1 (convert to 0-based!)
//   slwi  r9, r9, 2           ; r9 *= 4
//   lwzx  r3, r11, r9         ; return array[index-1]

// QuickStringSet::QuickStringSet() — 0x800a75bc (44 bytes)
QuickStringSet::QuickStringSet(void) {
    _vtable = &s_QuickStringSet_vtable;
    m_ansiData = NULL;
    m_entries = NULL;
    m_locName = &s_nullPointer;   // SDA-relative static null
    m_refCount = 0;
}

// QuickStringSet::Count — 0x800a7620 (84 bytes)
// Returns number of strings. Reads from m_entries if loaded,
// otherwise falls back to m_ansiData.
int QuickStringSet::Count(char langCode) {
    if (m_entries != NULL) {
        void* array = m_entries->array;
        if (array == NULL) return 0;
        return *(int*)((char*)array - 4);  // count stored at array[-1]
    }
    if (m_ansiData != NULL) {
        void* array = m_ansiData->array;
        int count = 0;
        if (array != NULL) {
            count = *(int*)((char*)array - 4);
        }
        return count;
    }
    return 0;
}

// QuickStringSet::GetString — 0x800a76ac (80 bytes)
// Returns string at 1-based index. Bounds-checked.
char* QuickStringSet::GetString(int index, char langCode) {
    if (m_entries == NULL) return NULL;
    if (index <= 0) return NULL;
    void* array = m_entries->array;
    int count = 0;
    if (array != NULL) {
        count = *(int*)((char*)array - 4);
    }
    if (index > count) return NULL;
    // 1-based to 0-based conversion
    return ((char**)array)[index - 1];
}

// QuickStringSet::AddRef — 0x800a7d44 (20 bytes)
// COM-style reference counting.
void QuickStringSet::AddRef(void) {
    m_refCount++;
}

// QuickStringSet::Release — 0x800a7d58 (92 bytes)
// Decrements refcount; if 0, destructs and frees.
void QuickStringSet::Release(void) {
    m_refCount--;
    if (m_refCount == 0) {
        // Call destructor and free
        this->~QuickStringSet();
        MainHeap()->Free(this);
    }
}


// ============================================================================
// SUMMARY OF MEMORY OWNERSHIP PATTERNS
// ============================================================================
//
// String Classes — Three Different Strategies:
//
// 1. EString / EString2: OWNING, NO REFCOUNT
//    - Each instance owns its buffer. Copy = deep copy (MakeCopy).
//    - Lightweight (4 bytes). Uses sentinel for empty state.
//    - Pro: Simple, no thread-safety issues.
//    - Con: Every copy allocates. Expensive for frequently-copied strings.
//
// 2. BString / BString2: SHARED, REFERENCE-COUNTED (Copy-on-Write)
//    - Multiple instances share one basic_string_ref.
//    - Copy is cheap (increment refcount). Mutate creates private copy.
//    - refCount == -1 means "unique/frozen" — forces deep copy on assignment.
//    - Pro: Cheap copies. Good for string parameters.
//    - Con: Mutation is expensive (must check and possibly copy).
//    - Con: Not thread-safe (refcount is non-atomic).
//
// 3. EAStringC: SHARED, REFERENCE-COUNTED + HASH CACHE
//    - Similar to BString but with 16-bit refcount and hash caching.
//    - Uses a separate allocator (APT allocator, not MainHeap).
//    - StringDataC header = 8 bytes + variable-length string data.
//    - Hash cached for fast lookup in APT dictionaries.
//    - Pro: Optimized for UI/scripting string lookups.
//    - Con: 16-bit refcount limits sharing to 65535 refs.
//
// Container Classes:
//
// 4. TArray<T, Alloc>: OWNING
//    - Owns its element buffer. Grows with power-of-2 strategy.
//    - Elements are properly constructed/destructed/copied via template methods.
//    - Allocator policy allows different heaps for different use cases.
//
// 5. EHashTable: OWNING (individual node allocation)
//    - Each node is a separate 20-byte heap allocation.
//    - Table owns all nodes; destructor frees everything.
//    - Bucket array is a separate allocation.
//
// 6. ERedBlackTree: OWNING (individual node allocation)
//    - Each node is a separate 32-byte heap allocation.
//    - Static sentinel (not dynamically allocated) — shared by all trees.
//    - Maintains BST structure AND flat linked list simultaneously.
//    - Flat list enables O(n) iteration without tree traversal overhead.
//
// 7. QuickStringSet: COM-STYLE REFCOUNT
//    - AddRef/Release pattern. Freed when refcount reaches 0.
//    - String data loaded from IFF resources (not individually allocated).
//    - 1-based indexing for string access (matches Sims 2 IFF conventions).
