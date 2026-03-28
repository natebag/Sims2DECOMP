struct EStorable;
struct EStream;
struct IShrubObject;

EStream& operator>>(EStream&, EStorable*&);

EStream& operator>>(EStream& stream, IShrubObject*& obj) {
    EStorable* storable;
    operator>>(stream, storable);
    obj = (IShrubObject*)storable;
    return stream;
}
