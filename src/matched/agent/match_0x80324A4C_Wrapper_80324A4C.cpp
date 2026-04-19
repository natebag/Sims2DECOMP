/* EEdithTreeSetMan::GetHeap(void) at 0x80324A4C (32B) */
// 0x80324A4C (32 bytes)
class EAHeap;
extern EAHeap* VMHeap();
class EEdithTreeSetMan {
public:
    EAHeap* GetHeap();
};
EAHeap* EEdithTreeSetMan::GetHeap() {
    return VMHeap();
}
