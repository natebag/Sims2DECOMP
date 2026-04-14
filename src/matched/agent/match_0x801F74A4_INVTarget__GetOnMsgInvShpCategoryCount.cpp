// 0x801F74A4 INVTarget::GetOnMsgInvShpCategoryCount(char*) (68B)
// Pattern: TArray-style pointer subtraction gives count, feeds Sprintf
struct Element { char pad[8]; };
extern char gFmt_ShpCount[];
int Sprintf(char* dst, char* fmt, ...);

struct INVTarget {
    char pad[376];
    Element* m_start;
    Element* m_end;
    void GetOnMsgInvShpCategoryCount(char* msg);
};

void INVTarget::GetOnMsgInvShpCategoryCount(char* msg) {
    int count = m_end - m_start;
    Sprintf(msg, gFmt_ShpCount, count);
}
