// 0x800D18E0 (72B) NeighborhoodImpl::GetPlayerVisitingAnotherHouse(void) const

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
    virtual int FindPlayer(int what) const = 0;
};

struct NeighborhoodImpl_Impl : public NeighborhoodImpl_Base {
    bool GetPlayerVisitingAnotherHouse() const;
};

bool NeighborhoodImpl_Impl::GetPlayerVisitingAnotherHouse() const {
    return FindPlayer(35) != 0;
}
