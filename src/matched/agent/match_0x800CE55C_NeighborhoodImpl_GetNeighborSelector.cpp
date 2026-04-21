// 0x800CE55C (72B) NeighborhoodImpl::GetNeighborSelector(int)

struct Selector {
    char pad[12];
    int field_12;
};

struct NeighborhoodImpl_Base {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual Selector* GetCurrentSelector(int arg) = 0;
};

struct NeighborhoodImpl_Impl : public NeighborhoodImpl_Base {
    int GetNeighborSelector(int arg);
};

int NeighborhoodImpl_Impl::GetNeighborSelector(int arg) {
    Selector* s = GetCurrentSelector(arg);
    if (s) return s->field_12;
    return 0;
}
