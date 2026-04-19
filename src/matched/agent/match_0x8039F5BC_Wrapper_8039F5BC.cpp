/* SimpleReconObject<ObjectSaveIDTable>::DoStream(ReconBuffer*, int) at 0x8039F5BC (36B) */
// 0x8039F5BC (36 bytes)
class ReconBuffer;
class ObjectSaveIDTable {
public:
    void DoStream(ReconBuffer* rb, int flags);
};
struct SimpleReconProxy_ObjectSaveIDTable {
    void* unused;  // offset 0
    ObjectSaveIDTable* m_obj;    // offset 4
    void DoStream(ReconBuffer* rb, int flags);
};
void SimpleReconProxy_ObjectSaveIDTable::DoStream(ReconBuffer* rb, int flags) {
    m_obj->DoStream(rb, flags);
}
