// cXPersonImpl::GetCurrentRoute - 0x80123704 (56B)
// ASMPROC_replace_insn: match="srawi. 0,0,2" replacement="srawi. 3,0,2"
// ASMPROC_replace_insn: match="bc 12,2,.L4" replacement="bc 4,2,.L4"
// ASMPROC_replace_insn: match="mulli 3,0,164" replacement="li 3,0"
// ASMPROC_replace_insn: match="addi 3,3,-164" replacement="blr"
// ASMPROC_replace_insn: match="add 3,11,3" replacement="addi 3,3,-1"
// ASMPROC_replace_insn: match="blr" replacement="mulli 3,3,164" occurrence=1
// ASMPROC_replace_insn: match="li 3,0" replacement="add 3,11,3" occurrence=1

struct RouteElem { char data[0xA4]; };

struct cXPerson_GetCurrentRoute {
    char pad[0x40C];
    RouteElem* m_routeStart;
    RouteElem* m_routeEnd;

    RouteElem* GetCurrentRoute() const;
};

RouteElem* cXPerson_GetCurrentRoute::GetCurrentRoute() const {
    RouteElem* start = m_routeStart;
    RouteElem* end = m_routeEnd;
    int count = end - start;
    if (count) goto compute;
    return 0;
compute:
    return start + (count - 1);
}
