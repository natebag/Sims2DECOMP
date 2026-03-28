class ESMSStrip;
class TArrayERModelAllocator;
template <class T, class A> class TArray {};
class ESubModelShader {
public:
    void MorphBreakUpStrip(TArray<ESMSStrip, TArrayERModelAllocator> &, TArray<ESMSStrip, TArrayERModelAllocator> &);
};
void ESubModelShader::MorphBreakUpStrip(TArray<ESMSStrip, TArrayERModelAllocator> &, TArray<ESMSStrip, TArrayERModelAllocator> &) {}
