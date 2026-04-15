// 0x800CEC04 (80B) NeighborhoodImpl::MakeNewFreePlayFamily(int)

struct Family;

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
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual Family* GetFamily(int id) = 0;
};

struct NeighborhoodImpl_Impl : public NeighborhoodImpl_Base {
    int BaseMakeNewFamily(bool free_play, int id);
    int MakeNewFreePlayFamily(int id);
};

int NeighborhoodImpl_Impl::MakeNewFreePlayFamily(int id) {
    if (GetFamily(id)) return 0;
    return BaseMakeNewFamily(true, id);
}
