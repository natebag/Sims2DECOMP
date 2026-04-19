/* SimpleReconObject<IFFResMap>::DoStream(ReconBuffer*, int) at 0x803A4BE0 (36B) */
// 0x803A4BE0 (36 bytes)
class ReconBuffer;
class IFFResMap {
public:
    void DoStream(ReconBuffer* rb, int flags);
};
struct SimpleReconProxy_IFFResMap {
    void* unused;  // offset 0
    IFFResMap* m_obj;    // offset 4
    void DoStream(ReconBuffer* rb, int flags);
};
void SimpleReconProxy_IFFResMap::DoStream(ReconBuffer* rb, int flags) {
    m_obj->DoStream(rb, flags);
}
