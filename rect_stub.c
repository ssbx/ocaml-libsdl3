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

#include <SDL3/SDL_rect.h>
#include "OcamlSDL3/rect_stub.h"

CAMLprim value
caml_SDL_HasIntersection(value a, value b)
{
    CAMLparam2(a,b);
    SDL_Rect _a;
    SDL_Rect _b;
    SDL_Rect_val(&_a, a);
    SDL_Rect_val(&_b, b);

    bool r =
        SDL_HasRectIntersection(&_a, &_b);

    CAMLreturn(Val_bool(r));
}

CAMLprim value
caml_SDL_PointInRect(value pt, value rct)
{
    CAMLparam2(pt, rct);
    SDL_Point _pt;
    SDL_Rect _rct;
    SDL_Rect_val(&_rct, rct);
    SDL_Point_val(&_pt, pt);

    bool r =
        SDL_PointInRect(&_pt, &_rct);

    CAMLreturn(Val_bool(r));
}

CAMLprim value
caml_SDL_IntersectRectAndLine(value rect, value x1, value y1, value x2, value y2)
{
    CAMLparam5(rect, x1, y1, x2, y2);
    CAMLlocal2(ret, r);

    SDL_Rect _rect;
    SDL_Rect_val(&_rect, rect);

    int X1 = Int_val(x1);
    int Y1 = Int_val(y1);
    int X2 = Int_val(x2);
    int Y2 = Int_val(y2);

    bool res =
        SDL_GetRectAndLineIntersection(&_rect, &X1, &Y1, &X2, &Y2);

    if (res == true) {
        r = caml_alloc(4, 0);

        Store_field(r, 0, Val_int(X1));
        Store_field(r, 1, Val_int(Y1));
        Store_field(r, 2, Val_int(X2));
        Store_field(r, 3, Val_int(Y2));

        ret = caml_alloc_some(r);
    } else {
        ret = Val_none;
    }

    CAMLreturn(ret);
}

/* vim: set ts=4 sw=4 et: */
