// 0x8021df90 InteractorModule::SimInteractor::GetBeamScale(void) (100B)
// SGI STL std::max(low, std::min(high, val)) clamp via stack-store + pointer-mux.
// 3 const float refs (0.01, 1.0, 0.5) materialized to stack slots for `const T&`.
// Two NaN-loose `bge` skip-mr branches form the min/max selectors.

namespace InteractorModule {

template <class T>
inline const T& sgi_min(const T& a, const T& b) {
    return b < a ? b : a;
}

template <class T>
inline const T& sgi_max(const T& a, const T& b) {
    return a < b ? b : a;
}

class SimInteractor {
public:
    char pad[0x180];
    float m_field180;
    float GetBeamScale();
};

float SimInteractor::GetBeamScale() {
    return sgi_max(0.01f, sgi_min(1.0f, m_field180 - 0.5f));
}

}
