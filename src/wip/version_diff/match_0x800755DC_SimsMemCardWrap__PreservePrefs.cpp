// FLAGS: -fno-elide-constructors
// SimsMemCardWrap::PreservePrefs(void)
// Address: 0x800755DC | Size: 40 bytes
// Pattern: Load global + call (SDA-based)

// Global at 0x80475F14 (r13-relative small data area)
extern void* gSimsMemCardWrap;

void DoPreservePrefs(void* ptr);

void SimsMemCardWrap__PreservePrefs(void) {
    DoPreservePrefs(gSimsMemCardWrap);
}
