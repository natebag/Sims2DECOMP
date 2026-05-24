// FLAGS: -fno-schedule-insns
// 0x80313948 FlashBigFile::GetFlashName(void) (12B)
// lwz r3,0x0(r3); addi r3,r3,24; blr
struct FlashBigFile {
    char* m_buf;  // offset 0
    const char* GetFlashName() const;
};
const char* FlashBigFile::GetFlashName() const {
    return m_buf + 24;
}
