# Sims 2 GameCube -- Ghidra Struct Definitions (Starter)
# @author Sims 2 GC Decomp Project
# @category Sims2
# @description Define placeholder structs for key game classes. Refine as decomp progresses.
#
# Run this AFTER symbol_importer.py to lay down struct skeletons.
# Sizes are derived from BSS globals and vtable sizes in the symbol map.
# Fields are placeholders -- fill them in as functions are decompiled.

from ghidra.program.model.data import (
    StructureDataType,
    PointerDataType,
    IntegerDataType,
    FloatDataType,
    ByteDataType,
    ShortDataType,
    UnsignedIntegerDataType,
    BooleanDataType,
    ArrayDataType,
    CategoryPath,
    Undefined4DataType,
)


def get_or_create_category(dtm, path):
    """Get or create a data type category (folder) in the Data Type Manager."""
    cat = dtm.getCategory(CategoryPath(path))
    if cat is None:
        cat = dtm.createCategory(CategoryPath(path))
    return cat


def create_struct(dtm, category_path, name, size, description, fields=None):
    """Create a struct with given size and optional named fields.

    fields: list of (offset, name, data_type, comment) tuples
    """
    cat_path = CategoryPath(category_path)
    struct = StructureDataType(cat_path, name, size)
    struct.setDescription(description)

    if fields:
        for offset, field_name, data_type, comment in fields:
            try:
                struct.replaceAtOffset(offset, data_type, data_type.getLength(),
                                       field_name, comment)
            except Exception as e:
                println("  Warning: could not set field %s at offset 0x%X: %s" % (
                    field_name, offset, str(e)))

    # Add to data type manager
    existing = dtm.getDataType(cat_path, name)
    if existing is not None:
        dtm.replaceDataType(existing, struct, False)
        println("  Updated: %s::%s (%d bytes)" % (category_path, name, size))
    else:
        dtm.addDataType(struct, None)
        println("  Created: %s::%s (%d bytes)" % (category_path, name, size))

    return struct


def run():
    println("=" * 60)
    println("  Sims 2 GC -- Ghidra Struct Definitions")
    println("=" * 60)

    dtm = currentProgram.getDataTypeManager()
    ptr = PointerDataType()
    u32 = UnsignedIntegerDataType()
    s32 = IntegerDataType()
    f32 = FloatDataType()
    u16 = ShortDataType()
    u8 = ByteDataType()
    bool_t = BooleanDataType()

    # ========================================================
    # ESimsApp -- Main application class
    # Global instance: _app at 0x8046E208, size 0x4A8
    # ========================================================
    create_struct(dtm, "/Sims2/Core", "ESimsApp", 0x4A8,
        "Main application singleton. Global instance: _app (0x8046E208).",
        [
            (0x00, "vtable", ptr, "Virtual function table pointer"),
        ]
    )

    # ========================================================
    # ESim -- Base sim class
    # vtable IBaseSimInstance: 0x38 bytes (14 entries)
    # m_typeInfo: 0x28 bytes
    # Actual ESim size unknown yet -- placeholder 0x200
    # ========================================================
    create_struct(dtm, "/Sims2/Sim", "ESim", 0x200,
        "Base sim entity. Size is a placeholder -- refine from constructor.",
        [
            (0x00, "vtable", ptr, "Virtual function table pointer"),
        ]
    )

    # IBaseSimInstance vtable layout
    create_struct(dtm, "/Sims2/Sim", "ESim_IBaseSimInstance_vtable", 0x38,
        "ESim::IBaseSimInstance virtual table (14 entries at 0x8045B2D0).",
        []
    )

    # ========================================================
    # cXObject -- Base game object class
    # vtable TreeSim: 0xB0 bytes (44 entries)
    # ========================================================
    create_struct(dtm, "/Sims2/Objects", "cXObject", 0x200,
        "Base game object. Size is a placeholder -- refine from constructor.",
        [
            (0x00, "vtable", ptr, "Virtual function table pointer"),
        ]
    )

    create_struct(dtm, "/Sims2/Objects", "cXObject_TreeSim_vtable", 0xB0,
        "cXObject::TreeSim virtual table (44 entries at 0x804614E0).",
        []
    )

    # ========================================================
    # ESimsCam -- Camera system
    # s_params: 0x390 bytes, s_newControlParms: 0xC4 bytes
    # ========================================================
    create_struct(dtm, "/Sims2/Camera", "ESimsCam", 0x200,
        "Camera system. Size is a placeholder -- refine from constructor.",
        [
            (0x00, "vtable", ptr, "Virtual function table pointer"),
        ]
    )

    create_struct(dtm, "/Sims2/Camera", "ESimsCam_CameraParameters", 0xC4,
        "Camera parameters struct (s_newControlParms at 0x80473514).",
        []
    )

    # ========================================================
    # ENgcRenderer -- NGC rendering system
    # m_jumpTable: 0x258 bytes
    # ========================================================
    create_struct(dtm, "/Sims2/Render", "ENgcRenderer", 0x400,
        "NGC renderer. Size is a placeholder -- refine from constructor.",
        [
            (0x00, "vtable", ptr, "Virtual function table pointer"),
        ]
    )

    # ========================================================
    # EAHeap -- EA memory allocator
    # s_poolBlocks: 0x20 bytes
    # ========================================================
    create_struct(dtm, "/Sims2/Core", "EAHeap", 0x40,
        "EA heap allocator. Size is a placeholder.",
        [
            (0x00, "vtable", ptr, "Virtual function table pointer"),
        ]
    )

    # ========================================================
    # FastAllocPool -- Fast fixed-size allocator
    # ========================================================
    create_struct(dtm, "/Sims2/Core", "FastAllocPool", 0x20,
        "Fixed-size pool allocator. Size is a placeholder.",
        [
            (0x00, "vtable", ptr, "Virtual function table pointer"),
        ]
    )

    # ========================================================
    # FrameEffects structs
    # ========================================================
    create_struct(dtm, "/Sims2/Effects", "FrameEffectsBloomDataElement", 0x20,
        "Bloom effect parameters. Size is a placeholder.",
        []
    )

    create_struct(dtm, "/Sims2/Effects", "FrameEffectsMotionBlurDataElement", 0x20,
        "Motion blur effect parameters. Size is a placeholder.",
        []
    )

    create_struct(dtm, "/Sims2/Effects", "FrameEffectsDepthOfFieldDataElement", 0x20,
        "Depth of field effect parameters. Size is a placeholder.",
        []
    )

    # ========================================================
    # PlayerCheats
    # g_playerCheats: 0x28 bytes
    # ========================================================
    create_struct(dtm, "/Sims2/Core", "PlayerCheats", 0x28,
        "Cheat code input handler. Global: g_playerCheats (0x8046E1E0).",
        []
    )

    # ========================================================
    # Common types used across the codebase
    # ========================================================
    create_struct(dtm, "/Sims2/Common", "EVec3", 0x0C,
        "3D vector (x, y, z floats).",
        [
            (0x00, "x", f32, None),
            (0x04, "y", f32, None),
            (0x08, "z", f32, None),
        ]
    )

    create_struct(dtm, "/Sims2/Common", "EVec4", 0x10,
        "4D vector (x, y, z, w floats).",
        [
            (0x00, "x", f32, None),
            (0x04, "y", f32, None),
            (0x08, "z", f32, None),
            (0x0C, "w", f32, None),
        ]
    )

    create_struct(dtm, "/Sims2/Common", "EMatrix", 0x30,
        "3x4 matrix (3 rows of EVec4). Used for transforms.",
        []
    )

    println("")
    println("=" * 60)
    println("  Struct definitions complete.")
    println("  These are placeholders -- refine sizes and fields")
    println("  as you decompile each class's constructor.")
    println("=" * 60)


# Entry point
run()
