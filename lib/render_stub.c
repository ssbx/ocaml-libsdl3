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

#include <SDL3/SDL_render.h>

#include "OcamlSDL3/render_stub.h"
#include "OcamlSDL3/video_stub.h"
#include "OcamlSDL3/surface_stub.h"
#include "OcamlSDL3/rect_stub.h"
#include "OcamlSDL3/blendmode_stub.h"
#include "OcamlSDL3/pixel_stub.h"

const int caml_sdl_textureaccess_table[] = {
    SDL_TEXTUREACCESS_STATIC,
    SDL_TEXTUREACCESS_STREAMING,
    SDL_TEXTUREACCESS_TARGET
};

value
Val_Sdl_textureaccess_t(int texture_access)
{
    switch (texture_access) {
    case SDL_TEXTUREACCESS_STATIC:    return Val_int(0);
    case SDL_TEXTUREACCESS_STREAMING: return Val_int(1);
    case SDL_TEXTUREACCESS_TARGET:    return Val_int(2);
    }
    caml_failwith("SdlTextureAccess.t");
}

static const SDL_RendererFlags SDL_RendererFlags_table[] = {
    SDL_RENDERER_SOFTWARE,
    SDL_RENDERER_ACCELERATED,
    SDL_RENDERER_PRESENTVSYNC,
    SDL_RENDERER_TARGETTEXTURE,
};

static inline Uint32
SDL_RendererFlags_val(value flag_list)
{
    CAMLparam1(flag_list);
    int c_mask = 0;
    while (flag_list != Val_emptylist)
    {
        value head = Field(flag_list, 0);
        c_mask |= SDL_RendererFlags_table[Long_val(head)];
        flag_list = Field(flag_list, 1);
    }
    CAMLreturn(c_mask);
}

static const SDL_FlipMode sdl_rendererflip_table[] = {
    SDL_FLIP_NONE,
    SDL_FLIP_HORIZONTAL,
    SDL_FLIP_VERTICAL,
};

#define SDL_RendererFlip_val(v) \
    sdl_rendererflip_table[Long_val(v)]


CAMLprim value
caml_SDL_CreateWindowAndRenderer(
        value width, value height, value _window_flags)
{
    CAMLparam3(width, height, _window_flags);
    CAMLlocal1(ret);

    SDL_Window *window;
    SDL_Renderer *renderer;
    Uint32 window_flags =
        Val_SDL_WindowFlags(_window_flags);

    int r = SDL_CreateWindowAndRenderer(
        Int_val(width), Int_val(height), window_flags, &window, &renderer);

    if (r)
        caml_failwith("Sdlrender.create_window_and_renderer");

    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_SDL_Window(window));
    Store_field(ret, 1, Val_SDL_Renderer(renderer));
    CAMLreturn(ret);
}

CAMLprim value
caml_SDL_CreateRenderer(value window, value index, value _flags)
{
    CAMLparam3(window,index,_flags);
    Uint32 flags = SDL_RendererFlags_val(_flags);

    SDL_Renderer * rend =
        SDL_CreateRenderer(
            SDL_Window_val(window),
            Int_val(index),
            flags);

    if (rend == NULL)
        caml_failwith("Sdlrender.create_renderer");

    CAMLreturn(Val_SDL_Renderer(rend));
}

CAMLprim value
caml_SDL_DestroyRenderer(value renderer)
{
    CAMLparam1(renderer);
    SDL_DestroyRenderer(SDL_Renderer_val(renderer));
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_RenderSetLogicalSize(value renderer, value w, value h)
{
    CAMLparam3(renderer, w, h);
    int r = SDL_SetRenderLogicalPresentation(
                SDL_Renderer_val(renderer),
                Int_val(w), Int_val(h));
    if (r) caml_failwith("Sdlrender.set_logical_size2");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_RenderSetViewport(value renderer, value _rect)
{
    CAMLparam2(renderer, _rect);

    SDL_Rect rect;
    SDL_Rect_val(&rect, _rect);
    int r = SDL_SetRenderViewport(
                SDL_Renderer_val(renderer),
                &rect);
    if (r) caml_failwith("Sdlrender.set_viewport");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_RenderSetClipRect(value renderer, value _rect)
{
    CAMLparam2(renderer,_rect);
    SDL_Rect rect;
    SDL_Rect_val(&rect, _rect);
    int r = SDL_SetRenderClipRect(
                SDL_Renderer_val(renderer),
                &rect);
    if (r) caml_failwith("Sdlrender.set_clip_rect");
    CAMLreturn(Val_unit);
}

#define Uint8_val Int_val
CAMLprim value
caml_SDL_SetRenderDrawColor(
        value renderer, value r, value g, value b, value a)
{
    CAMLparam5(renderer, r, g, b ,a);
    int s = SDL_SetRenderDrawColor(
        SDL_Renderer_val(renderer),
        Uint8_val(r), Uint8_val(g), Uint8_val(b), Uint8_val(a));
    if (s) caml_failwith("Sdlrender.draw_color");
    CAMLreturn(Val_unit);
}
#undef Uint8_val

CAMLprim value
caml_SDL_SetRenderDrawBlendMode(value renderer, value blendMode)
{
    CAMLparam2(renderer, blendMode);
    int r = SDL_SetRenderDrawBlendMode(
                SDL_Renderer_val(renderer),
                SDL_BlendMode_val(blendMode));
    if (r)
        caml_failwith("Sdlrender.set_draw_blend_mode");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_RenderDrawPoint(value renderer, value p)
{
    CAMLparam2(renderer, p);
    int r = SDL_RenderPoint(
                SDL_Renderer_val(renderer),
                Int_val(Field(p, 0)),
                Int_val(Field(p, 1)));
    if (r) caml_failwith("Sdlrender.draw_point");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_RenderDrawPoint2(value renderer, value x, value y)
{
    CAMLparam3(renderer, x, y);
    int r = SDL_RenderPoint(
                SDL_Renderer_val(renderer),
                Int_val(x), Int_val(y));
    if (r) caml_failwith("Sdlrender.draw_point2");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_RenderDrawPoints(value renderer, value ml_points)
{
    CAMLparam2(renderer, ml_points);
    unsigned int i;
    unsigned int count = Wosize_val(ml_points);
    SDL_Point * points = malloc(count * sizeof(SDL_Point));
    for (i = 0; i < count; i++) {
        value p = Field(ml_points, i);
        points[i].x = Int_val(Field(p, 0));
        points[i].y = Int_val(Field(p, 1));
    }
    int r = SDL_RenderPoints(
                SDL_Renderer_val(renderer),
                points, count);
    free(points);
    if (r) caml_failwith("Sdlrender.draw_points");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_RenderDrawLine(value renderer, value line)
{
    CAMLparam2(renderer, line);
    value p1 = Field(line, 0);
    value p2 = Field(line, 1);
    int r = SDL_RenderLine(
                SDL_Renderer_val(renderer),
                Int_val(Field(p1, 0)),
                Int_val(Field(p1, 1)),
                Int_val(Field(p2, 0)),
                Int_val(Field(p2, 1)));
    if (r) caml_failwith("Sdlrender.draw_line");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_RenderDrawLine2(value renderer, value p1, value p2)
{
    CAMLparam3(renderer, p1, p2);
    int r = SDL_RenderLine(
                SDL_Renderer_val(renderer),
                Int_val(Field(p1, 0)),
                Int_val(Field(p1, 1)),
                Int_val(Field(p2, 0)),
                Int_val(Field(p2, 1)));
    if (r) caml_failwith("Sdlrender.draw_line2");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_RenderDrawLines(value renderer, value ml_points)
{
    CAMLparam2(renderer, ml_points);
    unsigned int i;
    unsigned int count = Wosize_val(ml_points);
    SDL_Point * points = malloc(count * sizeof(SDL_Point));
    for (i = 0; i < count; i++) {
        value p = Field(ml_points, i);
        points[i].x = Int_val(Field(p, 0));
        points[i].y = Int_val(Field(p, 1));
    }
    int r = SDL_RenderLines(
                SDL_Renderer_val(renderer),
                points, count);
    free(points);
    if (r) caml_failwith("Sdlrender.draw_lines");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_RenderDrawRect(value renderer, value _rect)
{
    CAMLparam2(renderer, _rect);
    SDL_Rect rect;
    SDL_Rect_val(&rect, _rect);
    int r = SDL_RenderRect(
                SDL_Renderer_val(renderer),
                &rect);
    if (r) caml_failwith("Sdlrender.draw_rect");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_RenderDrawRects(value renderer, value ml_rects)
{
    /* TODO a rectangle list type so no malloc occurs here */
    CAMLparam2(renderer, ml_rects);
    unsigned int i;
    unsigned int count = Wosize_val(ml_rects);
    SDL_Rect * rects = malloc(count * sizeof(SDL_Rect));
    for (i = 0; i < count; i++) {
        value _rect = Field(ml_rects, i);
        SDL_Rect_val(&(rects[i]), _rect);
    }
    int r = SDL_RenderRects(
                SDL_Renderer_val(renderer),
                rects, count);
    free(rects);
    if (r) caml_failwith("Sdlrender.draw_rects");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_RenderFillRect(value renderer, value _rect)
{
    CAMLparam2(renderer, _rect);
    SDL_Rect rect;
    SDL_Rect_val(&rect, _rect);
    int r = SDL_RenderFillRect(
                SDL_Renderer_val(renderer),
                &rect);
    if (r) caml_failwith("Sdlrender.fill_rect");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_RenderFillRects(value renderer, value ml_rects)
{

    /* TODO a rectangle list type so no malloc occurs here */
    CAMLparam2(renderer, ml_rects);
    unsigned int i;
    unsigned int count = Wosize_val(ml_rects);
    SDL_Rect * rects = malloc(count * sizeof(SDL_Rect));
    for (i = 0; i < count; i++) {
        value _rect = Field(ml_rects, i);
        SDL_Rect_val(&(rects[i]), _rect);
    }
    int r = SDL_RenderFillRects(
                SDL_Renderer_val(renderer),
                rects, count);
    free(rects);
    if (r) caml_failwith("Sdlrender.fill_rects");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_RenderCopy(
        value renderer,
        value texture,
        value srcrect_opt,
        value dstrect_opt)
{
    CAMLparam4(renderer, texture, srcrect_opt, dstrect_opt);

    SDL_Rect srcrect;
    SDL_Rect dstrect;

    SDL_Rect *srcrect_ = NULL;
    SDL_Rect *dstrect_ = NULL;

    if (Is_some(srcrect_opt)) {
        SDL_Rect_val(&srcrect, Some_val(srcrect_opt));
        srcrect_ = &srcrect;
    }

    if (Is_some(dstrect_opt)) {
        SDL_Rect_val(&dstrect, Some_val(dstrect_opt));
        dstrect_ = &dstrect;
    }

    int r = SDL_RenderTexture(
                SDL_Renderer_val(renderer),
                SDL_Texture_val(texture),
                srcrect_,
                dstrect_);

    if (r)
        caml_failwith("Sdlrender.copy");

    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_RenderCopyEx(
        value renderer,
        value texture,
        value srcrect_opt,
        value dstrect_opt,
        value angle,
        value center_opt,
        value flip)
{
    CAMLparam5(renderer, texture, srcrect_opt, dstrect_opt, angle);
    CAMLxparam2(center_opt, flip);

    SDL_Rect srcrect;
    SDL_Rect dstrect;
    SDL_Point center;

    SDL_Rect *srcrect_ = NULL;
    SDL_Rect *dstrect_ = NULL;
    SDL_Point *center_ = NULL;

    if (Is_some(srcrect_opt)) {
        SDL_Rect_val(&srcrect, Some_val(srcrect_opt));
        srcrect_ = &srcrect;
    }

    if (Is_some(dstrect_opt)) {
        SDL_Rect_val(&dstrect, Some_val(dstrect_opt));
        dstrect_ = &dstrect;
    }

    if (Is_some(center_opt)) {
        SDL_Point_val(&center, Some_val(center_opt));
        center_ = &center;
    }

    int r =
        SDL_RenderTextureRotated(
                SDL_Renderer_val(renderer),
                SDL_Texture_val(texture),
                srcrect_,
                dstrect_,
                Double_val(angle),
                center_,
                SDL_RendererFlip_val(flip));

    if (r)
        caml_failwith("Sdlrender.copyEx");

    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_RenderCopyEx_bc(value * argv, int argn)
{
    return caml_SDL_RenderCopyEx(
        argv[0], argv[1], argv[2], argv[3],
        argv[4], argv[5], argv[6]);
}

CAMLprim value
caml_SDL_RenderSetScale(value renderer, value scaleX, value scaleY)
{
    CAMLparam3(renderer, scaleX, scaleY);
    int r = SDL_SetRenderScale(
                SDL_Renderer_val(renderer),
                Double_val(scaleX),
                Double_val(scaleY));
    if (r)
        caml_failwith("Sdlrender.set_scale");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_RenderPresent(value renderer)
{
    CAMLparam1(renderer);
    SDL_RenderPresent(SDL_Renderer_val(renderer));
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_RenderClear(value renderer)
{
    CAMLparam1(renderer);
    int r = SDL_RenderClear(SDL_Renderer_val(renderer));
    if (r) caml_failwith("Sdlrender.clear");
    CAMLreturn(Val_unit);
}

static value
Val_SDL_RendererInfo(SDL_RendererInfo * info)
{
}

CAMLprim value
caml_SDL_GetRenderDriverInfo(value index)
{
    CAMLparam1(index);
    CAMLlocal1(ret);
    SDL_RendererInfo info;
    int r = SDL_GetRenderDriverInfo(Int_val(index), &info);
    if (r) caml_failwith("Sdlrender.get_render_drivers");

#if 0
    Uint32 flags;               /**< Supported ::SDL_RendererFlags */
    Uint32 num_texture_formats; /**< The number of available texture formats */
    Uint32 texture_formats[16]; /**< The available texture formats */
#endif

    ret = caml_alloc(3, 0);
    Store_field(ret, 0, caml_copy_string(info.name));
    Store_field(ret, 1, Val_int(info.max_texture_width));
    Store_field(ret, 2, Val_int(info.max_texture_height));
    CAMLreturn(ret);
}

CAMLprim value
caml_SDL_GetNumRenderDrivers(value unit)
{
    CAMLparam0();
    CAMLreturn(Val_int(SDL_GetNumRenderDrivers()));
}

CAMLprim value
caml_SDL_RenderReadPixels(value renderer, value _rect, value surf)
{
    CAMLparam3(renderer, _rect, surf);
    SDL_Rect rect;
    SDL_Rect *rect_;
    SDL_Surface *surface = SDL_Surface_val(surf);

    if (_rect == Val_none) {
        rect_ = NULL;
    } else {
        SDL_Rect_val(&rect, Some_val(_rect));
        rect_ = &rect;
    }

    int r = SDL_RenderReadPixels(
                SDL_Renderer_val(renderer),
                rect_,
                surface->format->format,
                surface->pixels,
                surface->pitch);

    if (r != 0) caml_failwith("Sdlrender.read_pixels");

    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_CreateTexture(
        value renderer,
        value format,
        value access,
        value w,
        value h)
{
    CAMLparam5(renderer, format, access, w, h);
    SDL_Texture *texture =
        SDL_CreateTexture(
                SDL_Renderer_val(renderer),
                Sdl_pixelformat_t(format),
                Sdl_textureaccess_t(access),
                Int_val(w),
                Int_val(h));

    if (!texture) caml_failwith("Sdlrender.create_texture");

    CAMLreturn(Val_SDL_Texture(texture));
}

CAMLprim value
caml_SDL_QueryTexture(value texture)
{
    CAMLparam1(texture);
    CAMLlocal1(ret);
    Uint32 format;
    int access, w, h, r;
    r = SDL_QueryTexture(SDL_Texture_val(texture), &format, &access, &w, &h);
    if (r != 0)
        caml_failwith("Sdlrender.create_texture");
    ret = caml_alloc(4, 0);
    Store_field(ret, 0, Val_Sdl_pixelformat_t(format));
    Store_field(ret, 1, Val_Sdl_textureaccess_t(access));
    Store_field(ret, 2, Val_int(w));
    Store_field(ret, 3, Val_int(h));
    CAMLreturn(ret);
}

CAMLprim value
caml_SDL_SetRenderTarget(
        value renderer,
        value texture_option)
{
    CAMLparam2(renderer, texture_option);

    SDL_Texture *texture;
    if (Is_none(texture_option)) {
        texture = NULL;
    } else {
        texture = SDL_Texture_val(Some_val(texture_option));
    }
    int r = SDL_SetRenderTarget(
                SDL_Renderer_val(renderer),
                texture);

    if (r) caml_failwith("Sdlrender.render_target");

    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_GetRendererOutputSize(value renderer)
{
    CAMLparam1(renderer);
    CAMLlocal1(ret);

    int w, h;
    int r = SDL_GetCurrentRenderOutputSize(SDL_Renderer_val(renderer), &w, &h);
    if (r) caml_failwith("Sdlrender.get_output_size");

    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(w));
    Store_field(ret, 1, Val_int(h));
    CAMLreturn(ret);
}

// static value
// Val_SDL_RendererInfo(SDL_RendererInfo * info)
// {
// #if 0
//     Uint32 flags;               /**< Supported ::SDL_RendererFlags */
//     Uint32 num_texture_formats; /**< The number of available texture formats */
//     Uint32 texture_formats[16]; /**< The available texture formats */
// #endif
//     CAMLparam0();
//     CAMLlocal1(ret);
//     ret = caml_alloc(3, 0);
//     Store_field(ret, 0, caml_copy_string(info->name));
//     Store_field(ret, 1, Val_int(info->max_texture_width));
//     Store_field(ret, 2, Val_int(info->max_texture_height));
//     CAMLreturn(ret);
// }
//
//
// CAMLprim value
// caml_SDL_GetRenderDrivers(value unit)
// {
//     CAMLparam0();
//     CAMLlocal2(ret, dinf);
//     unsigned int i, n;
//     SDL_RendererInfo info;
//     n = SDL_GetNumRenderDrivers();
//     ret = caml_alloc(n, 0);
//     for (i = 0; i < n; i++) {
//         int r = SDL_GetRenderDriverInfo(i, &info);
//         if (r) caml_failwith("Sdlrender.get_render_drivers");
//         Store_field(ret, i, Val_SDL_RendererInfo(&info));
//     }
//     CAMLreturn(ret);
// }
//



CAMLprim value
caml_SDL_CreateTextureFromSurface(value renderer, value surface)
{
    CAMLparam2(renderer, surface);
    SDL_Texture *tex =
        SDL_CreateTextureFromSurface(
                SDL_Renderer_val(renderer),
                SDL_Surface_val(surface));
    if (!tex)
        caml_failwith("Sdltexture.create_from_surface");
    CAMLreturn(Val_SDL_Texture(tex));
}

CAMLprim value
caml_SDL_DestroyTexture(value texture)
{
    CAMLparam1(texture);
    SDL_DestroyTexture(SDL_Texture_val(texture));
    CAMLreturn(Val_unit);
}

#define Uint8_val Int_val
#define Val_uint8(uc) Val_int((int)uc)

CAMLprim value
caml_SDL_SetTextureAlphaMod(value texture, value alpha)
{
    CAMLparam2(texture, alpha);
    int r =
        SDL_SetTextureAlphaMod(
            SDL_Texture_val(texture),
            Uint8_val(alpha));
    if (r)
        caml_failwith("Sdltexture.set_alpha_mod");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_GetTextureAlphaMod(value texture)
{
    CAMLparam1(texture);
    Uint8 alpha;
    int r =
        SDL_GetTextureAlphaMod(
            SDL_Texture_val(texture),
            &alpha);
    if (r)
        caml_failwith("Sdltexture.get_alpha_mod");
    CAMLreturn(Val_uint8(alpha));
}

CAMLprim value
caml_SDL_SetTextureColorMod(value texture, value rgb)
{
    CAMLparam2(texture, rgb);
    value r = Field(rgb,0);
    value g = Field(rgb,1);
    value b = Field(rgb,2);
    int s =
        SDL_SetTextureColorMod(
            SDL_Texture_val(texture),
            Uint8_val(r), Uint8_val(g), Uint8_val(b));
    if (s)
        caml_failwith("Sdltexture.set_color_mod");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_SetTextureColorMod3(
        value texture, value r, value g, value b)
{
    CAMLparam4(texture, r, g, b);
    int s =
        SDL_SetTextureColorMod(
            SDL_Texture_val(texture),
            Uint8_val(r), Uint8_val(g), Uint8_val(b));
    if (s)
        caml_failwith("Sdltexture.set_color_mod3");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_SetTextureBlendMode(value texture, value blendMode)
{
    CAMLparam2(texture, blendMode);
    int r =
        SDL_SetTextureBlendMode(
            SDL_Texture_val(texture),
            SDL_BlendMode_val(blendMode));
    if (r)
        caml_failwith("Sdltexture.set_blend_mode");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_GetTextureBlendMode(value texture)
{
    CAMLparam1(texture);
    SDL_BlendMode blendMode;
    int r =
        SDL_GetTextureBlendMode(
            SDL_Texture_val(texture),
            &blendMode);
    if (r)
        caml_failwith("Sdltexture.get_blend_mode");
    CAMLreturn(Val_SDL_BlendMode(blendMode));
}

CAMLprim value
caml_SDL_GetTextureColorMod(value texture)
{
    CAMLparam1(texture);
    CAMLlocal1(rgb);

    Uint8 r, g, b;
    int s =
        SDL_GetTextureColorMod(
            SDL_Texture_val(texture),
            &r, &g, &b);
    if (s)
        caml_failwith("Sdltexture.get_color_mod");

    rgb = caml_alloc(3, 0);
    Store_field(rgb, 0, Val_uint8(r));
    Store_field(rgb, 1, Val_uint8(g));
    Store_field(rgb, 2, Val_uint8(b));
    CAMLreturn(rgb);
}

#undef Val_uint8
#undef Uint8_val

/* vim: set ts=4 sw=4 et: */



