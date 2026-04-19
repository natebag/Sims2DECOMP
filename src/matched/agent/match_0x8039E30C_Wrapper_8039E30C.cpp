/* SimpleReconObject<ObjectSaveTypeTable2>::DoStream(ReconBuffer*, int) at 0x8039E30C (36B) */
// 0x8039E30C (36 bytes)
class ReconBuffer;
class ObjectSaveTypeTable2 {
public:
    void DoStream(ReconBuffer* rb, int flags);
};
struct SimpleReconProxy_ObjectSaveTypeTable2 {
    void* unused;  // offset 0
    ObjectSaveTypeTable2* m_obj;    // offset 4
    void DoStream(ReconBuffer* rb, int flags);
};
void SimpleReconProxy_ObjectSaveTypeTable2::DoStream(ReconBuffer* rb, int flags) {
    m_obj->DoStream(rb, flags);
}
