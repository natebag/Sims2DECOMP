/* PlacementSpec::PlacementSpec(cXObjectImpl *) - 56 bytes */

struct PlacementSpec;

struct cXObjectImpl {
    void GetPlacementSpec(PlacementSpec *spec);
};

struct PlacementSpec {
    PlacementSpec(cXObjectImpl *obj);
};

PlacementSpec::PlacementSpec(cXObjectImpl *obj) {
    obj->GetPlacementSpec(this);
}
