// 0x800BC00C (212B) HouseImpl::IsResident(cXPerson *)

struct cXPerson;

struct PersonGroup {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual int ContainsPerson(cXPerson* p) = 0;  // slot 10 → offset 80/84
};

struct HouseMgr {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual PersonGroup* GetMembers() = 0;  // slot 7 → offset 56/60
};

struct NeighborhoodMgr {
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
    virtual PersonGroup* GetVisitors(int which) = 0;  // slot 36 → offset 288/292
};

extern HouseMgr* g_house_mgr;
extern NeighborhoodMgr* g_ng_mgr;
extern char g_flag[16];

struct HouseImpl {
    bool IsResident(cXPerson* p);
};

bool HouseImpl::IsResident(cXPerson* p) {
    PersonGroup* g = g_house_mgr->GetMembers();
    if (g->ContainsPerson(p) != 0) return true;
    if (*(int*)g_flag != 0) return false;
    PersonGroup* g2 = g_ng_mgr->GetVisitors(1);
    return g2->ContainsPerson(p) != 0;
}
