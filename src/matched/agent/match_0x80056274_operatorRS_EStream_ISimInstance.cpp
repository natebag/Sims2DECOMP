struct EStorable;
struct EStream;
struct ISimInstance;

EStream& operator>>(EStream&, EStorable*&);

EStream& operator>>(EStream& stream, ISimInstance*& obj) {
    EStorable* storable;
    operator>>(stream, storable);
    obj = (ISimInstance*)storable;
    return stream;
}
