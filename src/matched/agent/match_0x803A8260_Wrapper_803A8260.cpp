/* SimpleReconObject<ObjectSaveTypeTable>::DoStream(ReconBuffer*, int) at 0x803A8260 (36B) */
// 0x803A8260 (36 bytes)
class ReconBuffer;
class ObjectSaveTypeTable {
public:
    void DoStream(ReconBuffer* rb, int flags);
};
struct SimpleReconProxy_ObjectSaveTypeTable {
    void* unused;  // offset 0
    ObjectSaveTypeTable* m_obj;    // offset 4
    void DoStream(ReconBuffer* rb, int flags);
};
void SimpleReconProxy_ObjectSaveTypeTable::DoStream(ReconBuffer* rb, int flags) {
    m_obj->DoStream(rb, flags);
}
