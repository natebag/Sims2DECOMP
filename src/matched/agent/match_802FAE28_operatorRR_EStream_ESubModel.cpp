class EStream;
class ESubModel;
EStream & operator>>(EStream &, ESubModel &);
EStream & operator>>(EStream & s, ESubModel &) { return s; }
