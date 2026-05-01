/* SimpleReconObject<ObjectSaveTypeTable3>::DoStream(ReconBuffer*, int) at 0x8039F5E8 (36B) */
// 0x8039F5E8 (36 bytes)
class ReconBuffer;
class ObjectSaveTypeTable3 {
public:
    void DoStream(ReconBuffer* rb, int flags);
};
struct SimpleReconProxy_ObjectSaveTypeTable3 {
    void* unused;  // offset 0
    ObjectSaveTypeTable3* m_obj;    // offset 4
    void DoStream(ReconBuffer* rb, int flags);
};
void SimpleReconProxy_ObjectSaveTypeTable3::DoStream(ReconBuffer* rb, int flags) {
    m_obj->DoStream(rb, flags);
}
