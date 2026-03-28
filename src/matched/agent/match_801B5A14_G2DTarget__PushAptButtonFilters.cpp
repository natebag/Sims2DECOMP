class G2DTarget {
public:
    void PushAptButtonFiltersForPlayer(int player);
    void PushAptButtonFilters();
};

void G2DTarget::PushAptButtonFilters() {
    PushAptButtonFiltersForPlayer(0);
    PushAptButtonFiltersForPlayer(1);
}
