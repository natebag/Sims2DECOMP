/* SimpleReconObject<ThumbnailLoader>::DoStream(ReconBuffer*, int) at 0x803A828C (36B) */
// 0x803A828C (36 bytes)
class ReconBuffer;
class ThumbnailLoader {
public:
    void DoStream(ReconBuffer* rb, int flags);
};
struct SimpleReconProxy_ThumbnailLoader {
    void* unused;  // offset 0
    ThumbnailLoader* m_obj;    // offset 4
    void DoStream(ReconBuffer* rb, int flags);
};
void SimpleReconProxy_ThumbnailLoader::DoStream(ReconBuffer* rb, int flags) {
    m_obj->DoStream(rb, flags);
}
