/* ocaml-libsdl3 - An OCaml interface to the SDL3 library
 Copyright (C) 2025 Sébastien Serre

 This software is provided "AS-IS", without any express or implied warranty.
 In no event will the authors be held liable for any damages arising from
 the use of this software.

 Permission is granted to anyone to use this software for any purpose,
 including commercial applications, and to alter it and redistribute it freely.
*/
#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/fail.h>
#include <caml/bigarray.h>

#include <SDL3/SDL_surface.h>

#include "OcamlSDL3/surface_stub.h"
#include "OcamlSDL3/rect_stub.h"
#include "OcamlSDL3/blendmode_stub.h"
#include "OcamlSDL3/pixel_stub.h"

#include <string.h>

CAMLprim value
caml_SDL_CreateRGBSurface(
        value width,
        value height,
        value depth)
{
    CAMLparam3(width, height, depth);
    Uint32 flags = 0;
    Uint32 Rmask = 0;
    Uint32 Gmask = 0;
    Uint32 Bmask = 0;
    Uint32 Amask = 0;

    SDL_Surface *surf = SDL_CreateRGBSurface(
        flags,
        Int_val(width),
        Int_val(height),
        Int_val(depth),
        Rmask,
        Gmask,
        Bmask,
        Amask);
    CAMLreturn(Val_SDL_Surface(surf));
}

CAMLprim value
caml_SDL_FreeSurface(value surf)
{
    CAMLparam1(surf);
    SDL_DestroySurface(SDL_Surface_val(surf));
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_LoadBMP(value filename)
{
    CAMLparam1(filename);
    SDL_Surface *surf = SDL_LoadBMP(String_val(filename));
    if (surf == NULL)
        caml_failwith("Sdlsurface.load_bmp");
    CAMLreturn(Val_SDL_Surface(surf));
}

CAMLprim value
caml_SDL_SaveBMP(value surf, value filename)
{
    CAMLparam2(surf, filename);
    int r = SDL_SaveBMP(SDL_Surface_val(surf), String_val(filename));
    if (r) caml_failwith("Sdlsurface.save_bmp");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_FillRect(
        value dst,
        value rect,
        value color)
{
    CAMLparam3(dst, rect, color);
    SDL_Rect _rect;
    SDL_Rect_val(&_rect, rect);
    int r = SDL_FillSurfaceRect(
        SDL_Surface_val(dst), &_rect,
        Int32_val(color));
    if (r) caml_failwith("Sdlsurface.fill_rect");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_BlitSurface(
        value src, value _srcrect,
        value dst, value _dstrect)
{
    CAMLparam4(src, _srcrect, dst, _dstrect);
    CAMLlocal1(ret);
    SDL_Rect dstrect;
    SDL_Rect srcrect;
    SDL_Rect_val(&dstrect, _dstrect);
    SDL_Rect_val(&srcrect, _srcrect);
    int r = SDL_BlitSurface(
        SDL_Surface_val(src), &srcrect,
        SDL_Surface_val(dst), &dstrect);
    if (r) caml_failwith("Sdlsurface.blit_surface");
    Val_SDL_Rect(ret, &dstrect);
    CAMLreturn(ret);
}

CAMLprim value
caml_SDL_BlitSurf(
        value src, value dst, value _dstrect)
{
    CAMLparam3(src, dst, _dstrect);
    CAMLlocal1(ret);
    SDL_Rect dstrect;
    SDL_Rect_val(&dstrect, _dstrect);
    int r = SDL_BlitSurface(
        SDL_Surface_val(src), NULL,
        SDL_Surface_val(dst), &dstrect);
    if (r) caml_failwith("Sdlsurface.blit_surf");
    Val_SDL_Rect(ret, &dstrect);
    CAMLreturn(ret);
}

CAMLprim value
caml_SDL_BlitSurfs(
        value src, value dst, value _dstrect)
{
    CAMLparam3(src, dst, _dstrect);
    SDL_Rect dstrect;
    SDL_Rect_val(&dstrect, _dstrect);
    int r = SDL_BlitSurface(
        SDL_Surface_val(src), NULL,
        SDL_Surface_val(dst), &dstrect);
    if (r) caml_failwith("Sdlsurface.blit_surfs");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_Surface_Blit_Pixels(
        value surf, value pixels_buffer)
{
    CAMLparam2(surf, pixels_buffer);
    SDL_Surface *surface = SDL_Surface_val(surf);
    memcpy(surface->pixels,
        String_val(pixels_buffer),
        caml_string_length(pixels_buffer));
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_SetColorKey(value surf, value flag, value key)
{
    CAMLparam3(surf, flag, key);
    /* TODO:
     *  You can pass SDL_RLEACCEL to enable RLE accelerated blits.
     */
    int r = SDL_SetSurfaceColorKey(
        SDL_Surface_val(surf), Bool_val(flag), Int32_val(key));
    if (r) caml_failwith("Sdlsurface.set_color_key");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_SetColorKey_MapRGB(value surf, value flag, value rgb)
{
    CAMLparam3(surf, flag, rgb);
    int r = SDL_SetSurfaceColorKey(
        SDL_Surface_val(surf),
        Bool_val(flag),
        SDL_MapRGB(
            SDL_Surface_val(surf)->format,
            Int_val(Field(rgb,0)),
            Int_val(Field(rgb,1)),
            Int_val(Field(rgb,2)) ) );

    if (r) caml_failwith("Sdlsurface.set_color_key_map_rgb");

    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_SurfaceGetWidth(value surf)
{
    CAMLparam1(surf);
    CAMLreturn(Val_int(SDL_Surface_val(surf)->w));
}

CAMLprim value
caml_SDL_SurfaceGetHeight(value surf)
{
    CAMLparam1(surf);
    CAMLreturn(Val_int(SDL_Surface_val(surf)->h));
}

CAMLprim value
caml_SDL_SurfaceGetPitch(value surf)
{
    CAMLparam1(surf);
    CAMLreturn(Val_int(SDL_Surface_val(surf)->pitch));
}

CAMLprim value
caml_SDL_SurfaceGetDims(value surface)
{
    CAMLparam1(surface);
    CAMLlocal1(dims);
    dims = caml_alloc(2, 0);
    Store_field(dims, 0, Val_int(SDL_Surface_val(surface)->w));
    Store_field(dims, 1, Val_int(SDL_Surface_val(surface)->h));
    CAMLreturn(dims);
}

CAMLprim value
caml_SDL_SurfaceGetPixel32(value surf, value x, value y)
{
    CAMLparam3(surf, x, y);
    Uint32 *pixels = (Uint32 *) SDL_Surface_val(surf)->pixels;
    int width = SDL_Surface_val(surf)->w;
    int ofs = (Long_val(y) * width) + Long_val(x);
    CAMLreturn(caml_copy_int32(pixels[ofs]));
}

CAMLprim value
caml_SDL_SurfaceGetPixel16(value surf, value x, value y)
{
    CAMLparam3(surf, x, y);
    Uint16 *pixels = (Uint16 *) SDL_Surface_val(surf)->pixels;
    int width = SDL_Surface_val(surf)->w;
    int ofs = (Long_val(y) * width) + Long_val(x);
    CAMLreturn(caml_copy_int32(pixels[ofs]));
}

CAMLprim value
caml_SDL_SurfaceGetPixel8(value surf, value x, value y)
{
    CAMLparam3(surf, x, y);
    Uint8 *pixels = (Uint8 *) SDL_Surface_val(surf)->pixels;
    int width = SDL_Surface_val(surf)->w;
    int ofs = (Long_val(y) * width) + Long_val(x);
    CAMLreturn(caml_copy_int32(pixels[ofs]));
}

CAMLprim value
caml_SDL_SurfaceGetBitsPerPixel(value surf)
{
    CAMLparam1(surf);
    CAMLreturn(Val_int(SDL_Surface_val(surf)->format->BitsPerPixel));
}

static inline bool
SDL_SurfaceHasPalette(SDL_Surface * surface)
{
    return ((surface->format->palette) != 0);
}

static inline int
SDL_SurfacePaletteColors(SDL_Surface * surface)
{
    if ((surface->format->palette) != 0)
    {
        return (surface->format->palette->ncolors);
    }
    else return (-1);
}

CAMLprim value
caml_SDL_SurfaceHasPalette(value surf)
{
    CAMLparam1(surf);
    bool b = SDL_SurfaceHasPalette(SDL_Surface_val(surf));
    CAMLreturn(Val_bool(b));
}

CAMLprim value
caml_SDL_SurfacePaletteColors(value surf)
{
    CAMLparam1(surf);
    CAMLreturn(Val_int(SDL_SurfacePaletteColors(SDL_Surface_val(surf))));
}

CAMLprim value
caml_SDL_SetSurfaceBlendMode(
        value surf,
        value blendMode)
{
    CAMLparam2(surf, blendMode);
    int r =
        SDL_SetSurfaceBlendMode(
            SDL_Surface_val(surf),
            SDL_BlendMode_val(blendMode));
    if (r) caml_failwith("Sdlsurface.set_blend_mode");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_Surface_get_pixelformat_t(value surf)
{
    CAMLparam1(surf);
    SDL_PixelFormat *pixel_format =
        SDL_Surface_val(surf)->format;

    Uint32 format = pixel_format->format;

    CAMLreturn(Val_Sdl_pixelformat_t(format));
}

CAMLprim value
caml_SDL_Surface_get_pixels(value surface)
{
    CAMLparam1(surface);
    CAMLlocal1(ml_pixels);

    SDL_Surface *surf = SDL_Surface_val(surface);

    unsigned int len =
        surf->w * surf->h *
        surf->format->BytesPerPixel;

    ml_pixels = caml_alloc_initialized_string(len, surf->pixels);

    CAMLreturn(ml_pixels);
}

/*
 * Big array
 */
CAMLprim value
caml_SDL_Surface_ba_get_pixels(value surface)
{
    CAMLparam1(surface);
    SDL_Surface *surf = SDL_Surface_val(surface);

    int b_flag = 0;
    long dim = surf->h;

    dim *= surf->pitch;
    b_flag |= CAML_BA_UINT8;

    b_flag |= CAML_BA_C_LAYOUT | CAML_BA_EXTERNAL ;

    CAMLreturn(caml_ba_alloc(b_flag, 1, surf->pixels, &dim));
}

#define Uint32_val(d) (Int32_val(d))

CAMLprim value
caml_SDL_CreateRGBSurfaceFrom(
        value pixels, value width, value height, value depth, value pitch,
        value Rmask, value Gmask, value Bmask, value Amask)
{
    CAMLparam5(pixels, width, height, depth, pitch);
    CAMLxparam4(Rmask, Gmask, Bmask, Amask);
    SDL_Surface *surf =
        SDL_CreateRGBSurfaceFrom(
            (void *) Caml_ba_data_val(pixels),
            Int_val(width),
            Int_val(height),
            Int_val(depth),
            Int_val(pitch),
            Uint32_val(Rmask),
            Uint32_val(Gmask),
            Uint32_val(Bmask),
            Uint32_val(Amask));

    CAMLreturn(Val_SDL_Surface(surf));
}

CAMLprim value
caml_SDL_CreateRGBSurfaceFrom_bytecode(value * argv, int argn)
{
    return caml_SDL_CreateRGBSurfaceFrom(
            argv[0], argv[1], argv[2],
            argv[3], argv[4], argv[5],
            argv[6], argv[7], argv[8] );
}

/* vim: set ts=4 sw=4 et: */
