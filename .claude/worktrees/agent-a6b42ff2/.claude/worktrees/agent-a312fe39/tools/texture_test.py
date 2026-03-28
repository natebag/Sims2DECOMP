#!/usr/bin/env python3
"""
GameCube TPL texture decoder and BMP dumper.
Reads .tpl files from the Sims 2 GC disc and exports them as .bmp.

Usage:
    python tools/texture_test.py extracted/files/ngcbanner.tpl
    python tools/texture_test.py extracted/files/ngcicon.tpl
"""

import struct
import sys
import os

# GC texture format IDs
GC_TF_I4     = 0
GC_TF_I8     = 1
GC_TF_IA4    = 2
GC_TF_IA8    = 3
GC_TF_RGB565 = 4
GC_TF_RGB5A3 = 5
GC_TF_RGBA8  = 6
GC_TF_C4     = 8
GC_TF_C8     = 9
GC_TF_C14X2  = 10
GC_TF_CMPR   = 14

FORMAT_NAMES = {
    0: "I4", 1: "I8", 2: "IA4", 3: "IA8", 4: "RGB565",
    5: "RGB5A3", 6: "RGBA8", 8: "C4", 9: "C8", 10: "C14X2", 14: "CMPR",
}

# ============================================================================
# Pixel decoders
# ============================================================================

def decode_rgb5a3(pixel):
    if pixel & 0x8000:
        r = ((pixel >> 10) & 0x1F) * 255 // 31
        g = ((pixel >> 5) & 0x1F) * 255 // 31
        b = (pixel & 0x1F) * 255 // 31
        a = 255
    else:
        a = ((pixel >> 12) & 0x07) * 255 // 7
        r = ((pixel >> 8) & 0x0F) * 255 // 15
        g = ((pixel >> 4) & 0x0F) * 255 // 15
        b = (pixel & 0x0F) * 255 // 15
    return (r, g, b, a)

def decode_rgb565(pixel):
    r = ((pixel >> 11) & 0x1F) * 255 // 31
    g = ((pixel >> 5) & 0x3F) * 255 // 63
    b = (pixel & 0x1F) * 255 // 31
    return (r, g, b, 255)

# ============================================================================
# Tile-based texture decoders
# ============================================================================

def decode_i4(data, w, h):
    pixels = [(0,0,0,255)] * (w * h)
    tilesX = (w + 7) // 8
    tilesY = (h + 7) // 8
    off = 0
    for ty in range(tilesY):
        for tx in range(tilesX):
            for row in range(8):
                for col in range(0, 8, 2):
                    if off >= len(data): return pixels
                    byte = data[off]; off += 1
                    for bit, dx in [(byte >> 4, 0), (byte & 0xF, 1)]:
                        x, y = tx*8 + col + dx, ty*8 + row
                        if x < w and y < h:
                            i = bit * 17
                            pixels[y*w + x] = (i, i, i, 255)
    return pixels

def decode_i8(data, w, h):
    pixels = [(0,0,0,255)] * (w * h)
    tilesX = (w + 7) // 8
    tilesY = (h + 3) // 4
    off = 0
    for ty in range(tilesY):
        for tx in range(tilesX):
            for row in range(4):
                for col in range(8):
                    if off >= len(data): return pixels
                    i = data[off]; off += 1
                    x, y = tx*8 + col, ty*4 + row
                    if x < w and y < h:
                        pixels[y*w + x] = (i, i, i, 255)
    return pixels

def decode_ia4(data, w, h):
    pixels = [(0,0,0,255)] * (w * h)
    tilesX = (w + 7) // 8
    tilesY = (h + 3) // 4
    off = 0
    for ty in range(tilesY):
        for tx in range(tilesX):
            for row in range(4):
                for col in range(8):
                    if off >= len(data): return pixels
                    byte = data[off]; off += 1
                    i = (byte & 0xF) * 17
                    a = (byte >> 4) * 17
                    x, y = tx*8 + col, ty*4 + row
                    if x < w and y < h:
                        pixels[y*w + x] = (i, i, i, a)
    return pixels

def decode_ia8(data, w, h):
    pixels = [(0,0,0,255)] * (w * h)
    tilesX = (w + 3) // 4
    tilesY = (h + 3) // 4
    off = 0
    for ty in range(tilesY):
        for tx in range(tilesX):
            for row in range(4):
                for col in range(4):
                    if off + 1 >= len(data): return pixels
                    a = data[off]; i = data[off+1]; off += 2
                    x, y = tx*4 + col, ty*4 + row
                    if x < w and y < h:
                        pixels[y*w + x] = (i, i, i, a)
    return pixels

def decode_rgb565_tex(data, w, h):
    pixels = [(0,0,0,255)] * (w * h)
    tilesX = (w + 3) // 4
    tilesY = (h + 3) // 4
    off = 0
    for ty in range(tilesY):
        for tx in range(tilesX):
            for row in range(4):
                for col in range(4):
                    if off + 1 >= len(data): return pixels
                    pixel = struct.unpack_from(">H", data, off)[0]; off += 2
                    x, y = tx*4 + col, ty*4 + row
                    if x < w and y < h:
                        pixels[y*w + x] = decode_rgb565(pixel)
    return pixels

def decode_rgb5a3_tex(data, w, h):
    pixels = [(0,0,0,255)] * (w * h)
    tilesX = (w + 3) // 4
    tilesY = (h + 3) // 4
    off = 0
    for ty in range(tilesY):
        for tx in range(tilesX):
            for row in range(4):
                for col in range(4):
                    if off + 1 >= len(data): return pixels
                    pixel = struct.unpack_from(">H", data, off)[0]; off += 2
                    x, y = tx*4 + col, ty*4 + row
                    if x < w and y < h:
                        pixels[y*w + x] = decode_rgb5a3(pixel)
    return pixels

def decode_rgba8(data, w, h):
    pixels = [(0,0,0,255)] * (w * h)
    tilesX = (w + 3) // 4
    tilesY = (h + 3) // 4
    off = 0
    for ty in range(tilesY):
        for tx in range(tilesX):
            ar = []
            for i in range(16):
                if off + 1 >= len(data): return pixels
                ar.append((data[off], data[off+1])); off += 2
            for i in range(16):
                if off + 1 >= len(data): return pixels
                g = data[off]; b = data[off+1]; off += 2
                col_i, row_i = i % 4, i // 4
                x, y = tx*4 + col_i, ty*4 + row_i
                if x < w and y < h:
                    pixels[y*w + x] = (ar[i][1], g, b, ar[i][0])
    return pixels

def decode_cmpr(data, w, h):
    pixels = [(0,0,0,255)] * (w * h)
    tilesX = (w + 7) // 8
    tilesY = (h + 7) // 8
    off = 0
    for ty in range(tilesY):
        for tx in range(tilesX):
            for sb in range(4):
                if off + 7 >= len(data): return pixels
                c0 = struct.unpack_from(">H", data, off)[0]
                c1 = struct.unpack_from(">H", data, off+2)[0]
                indices = struct.unpack_from(">I", data, off+4)[0]
                off += 8

                color = [decode_rgb565(c0), decode_rgb565(c1), None, None]
                if c0 > c1:
                    color[2] = tuple((2*color[0][i] + color[1][i] + 1)//3 for i in range(3)) + (255,)
                    color[3] = tuple((color[0][i] + 2*color[1][i] + 1)//3 for i in range(3)) + (255,)
                else:
                    color[2] = tuple((color[0][i] + color[1][i])//2 for i in range(3)) + (255,)
                    color[3] = (0, 0, 0, 0)

                baseX = tx*8 + (sb & 1)*4
                baseY = ty*8 + (sb >> 1)*4
                for row in range(4):
                    for col in range(4):
                        shift = 30 - ((row*4 + col)*2)
                        idx = (indices >> shift) & 3
                        x, y = baseX + col, baseY + row
                        if x < w and y < h:
                            pixels[y*w + x] = color[idx]
    return pixels

# ============================================================================
# Main decoder dispatch
# ============================================================================

def decode_gc_texture(data, w, h, fmt):
    decoders = {
        GC_TF_I4: decode_i4,
        GC_TF_I8: decode_i8,
        GC_TF_IA4: decode_ia4,
        GC_TF_IA8: decode_ia8,
        GC_TF_RGB565: decode_rgb565_tex,
        GC_TF_RGB5A3: decode_rgb5a3_tex,
        GC_TF_RGBA8: decode_rgba8,
        GC_TF_CMPR: decode_cmpr,
    }
    decoder = decoders.get(fmt)
    if decoder is None:
        print(f"  Unsupported format: {fmt} ({FORMAT_NAMES.get(fmt, '?')})")
        return None
    return decoder(data, w, h)

# ============================================================================
# TPL parser
# ============================================================================

def parse_tpl(data):
    if len(data) < 12:
        return []
    magic, num_images, table_off = struct.unpack_from(">III", data, 0)
    if magic != 0x0020AF30:
        print(f"ERROR: Not a TPL file (magic=0x{magic:08X})")
        return []

    images = []
    for i in range(num_images):
        entry_off = table_off + i * 8
        img_off, pal_off = struct.unpack_from(">II", data, entry_off)

        if img_off == 0: continue
        h, w, fmt, data_off = struct.unpack_from(">HHI I", data, img_off)

        pal_data = None
        pal_fmt = 0
        pal_entries = 0
        if pal_off != 0:
            pal_entries, _, _, pal_fmt, pal_data_off = struct.unpack_from(">HBB II", data, pal_off)
            pal_data = data[pal_data_off:pal_data_off + pal_entries * 2]

        images.append({
            "width": w, "height": h, "format": fmt,
            "data_offset": data_off,
            "palette": pal_data, "pal_fmt": pal_fmt,
        })
    return images

# ============================================================================
# BMP writer
# ============================================================================

def write_bmp(filename, pixels, w, h):
    row_bytes = w * 3
    pad = (4 - row_bytes % 4) % 4
    stride = row_bytes + pad
    img_size = stride * h
    file_size = 54 + img_size

    with open(filename, "wb") as f:
        # BMP header
        f.write(b"BM")
        f.write(struct.pack("<I", file_size))
        f.write(b"\x00\x00\x00\x00")
        f.write(struct.pack("<I", 54))
        # DIB header
        f.write(struct.pack("<I", 40))
        f.write(struct.pack("<i", w))
        f.write(struct.pack("<i", h))
        f.write(struct.pack("<HH", 1, 24))
        f.write(struct.pack("<I", 0))  # compression
        f.write(struct.pack("<I", img_size))
        f.write(b"\x00" * 16)  # resolution + colors

        # Pixel data (bottom-to-top, BGR)
        padding = b"\x00" * pad
        for y in range(h - 1, -1, -1):
            for x in range(w):
                r, g, b, a = pixels[y * w + x]
                f.write(bytes([b, g, r]))
            f.write(padding)

# ============================================================================
# Main
# ============================================================================

def main():
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <file.tpl> [output.bmp]")
        return

    path = sys.argv[1]
    with open(path, "rb") as f:
        data = f.read()

    print(f"Loaded {path} ({len(data)} bytes)")

    images = parse_tpl(data)
    if not images:
        print("ERROR: No images found")
        return

    print(f"TPL contains {len(images)} image(s)\n")

    for i, img in enumerate(images):
        w, h, fmt = img["width"], img["height"], img["format"]
        fmt_name = FORMAT_NAMES.get(fmt, f"?({fmt})")
        print(f"  Image {i}: {w}x{h}, format={fmt_name}")

        tex_data = data[img["data_offset"]:]
        pixels = decode_gc_texture(tex_data, w, h, fmt)
        if pixels is None:
            continue

        # Output path
        if len(sys.argv) > 2 and len(images) == 1:
            out_path = sys.argv[2]
        else:
            base = os.path.splitext(path)[0]
            out_path = f"{base}_{i}.bmp"

        write_bmp(out_path, pixels, w, h)
        print(f"  Wrote: {out_path}")

    print("\nDone!")

if __name__ == "__main__":
    main()
