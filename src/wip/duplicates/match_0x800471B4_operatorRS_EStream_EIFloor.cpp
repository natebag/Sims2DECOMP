struct EStorable;
struct EStream;
struct EIFloor;

EStream& operator>>(EStream&, EStorable*&);

EStream& operator>>(EStream& stream, EIFloor*& obj) {
    EStorable* storable;
    operator>>(stream, storable);
    obj = (EIFloor*)storable;
    return stream;
}
