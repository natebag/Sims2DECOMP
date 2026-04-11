// VERSION_DIFF: SDA global load pattern (DOL loads g_displayList from r13-22936)
// C++ logic is correct - core functionality matches
// 0x8028AFA8 (76 bytes)
/* AptCharacterInst::sMethod_nextFrame(AptValue *, int) */

// Forward declarations
extern void AptCharacterInst_GotoFrame(void* self, int frame);  /* 0x80292994 */

struct AptCharacterInst_NextFrame {
    char _pad[0x4C];
    void* m_field4C;  /* 0x4C - points to display data */
    
    void sMethod_nextFrame(void* value, int arg);
};

void AptCharacterInst_NextFrame::sMethod_nextFrame(void* value, int arg) {
    void* data = m_field4C;
    int currentFrame = ((int*)data)[6];  /* offset 0x18 */
    AptCharacterInst_GotoFrame(this, currentFrame + 1);
    
    data = m_field4C;
    int flags = ((int*)data)[7];  /* offset 0x1C */
    flags |= 0xD4;  /* set some flag bits */
    ((int*)data)[7] = flags;
}
