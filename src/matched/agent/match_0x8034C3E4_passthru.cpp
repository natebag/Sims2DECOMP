/* ENgcRenderSurface::GetOutputRect(TRect<float>&) at 0x8034C3E4 (32B) */
// 0x8034C3E4 (32 bytes)
template<class T> struct TRect { T x, y, w, h; };
class ERenderSurface {
public:
    void GetOutputRect(TRect<float>& r);
};
class ENgcRenderSurface : public ERenderSurface {
public:
    void GetOutputRect(TRect<float>& r);
};
void ENgcRenderSurface::GetOutputRect(TRect<float>& r) {
    ERenderSurface::GetOutputRect(r);
}
