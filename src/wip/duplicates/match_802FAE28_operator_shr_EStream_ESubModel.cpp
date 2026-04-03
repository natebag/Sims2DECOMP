class EStream {};
class ESubModel {};
EStream &operator>>(EStream &s, ESubModel &m) { return s; }
