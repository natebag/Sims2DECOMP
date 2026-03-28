/* HierarchySite::HierarchySite(cXObjectImpl *) - 56 bytes */

struct HierarchySite;

struct cXObjectImpl {
    void HierGetSite(HierarchySite *site);
};

struct HierarchySite {
    HierarchySite(cXObjectImpl *obj);
};

HierarchySite::HierarchySite(cXObjectImpl *obj) {
    obj->HierGetSite(this);
}
