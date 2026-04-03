struct EStorable;
struct EStream;
struct ISimsCounterTopObject;

EStream& operator>>(EStream&, EStorable*&);

EStream& operator>>(EStream& stream, ISimsCounterTopObject*& obj) {
    EStorable* storable;
    operator>>(stream, storable);
    obj = (ISimsCounterTopObject*)storable;
    return stream;
}
