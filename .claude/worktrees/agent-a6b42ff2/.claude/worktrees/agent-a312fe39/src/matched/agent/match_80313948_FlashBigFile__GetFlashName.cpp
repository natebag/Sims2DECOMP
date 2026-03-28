// 0x80313948 (12 bytes)
// lwz r3, 0(r3); addi r3, r3, 24; blr
class FlashBigFile {
    char* m_data; // 0x00
public:
    char* GetFlashName();
};
char* FlashBigFile::GetFlashName() {
    return m_data + 24;
}
