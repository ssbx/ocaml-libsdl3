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

#include <SDL3/SDL.h>

CAMLprim value
caml_SDL_GetTicks(value unit)
{
    CAMLparam0();
    Uint32 ticks = SDL_GetTicks();
    CAMLreturn(Val_long(ticks));
}

/*
CAMLprim value
caml_SDL_GetTicks_d(value unit)
{
    CAMLparam1(unit);
    CAMLlocal1(ret);
    static const Uint32 th = 1000;
    Uint32 ticks = SDL_GetTicks();
    Uint32 sec = ticks / th;
    Uint32 msec = ticks - sec * th;
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(sec));
    Store_field(ret, 1, Val_int(msec));
    CAMLreturn(ret);
}
*/

CAMLprim value
caml_SDL_Delay(value ms)
{
    CAMLparam1(ms);
    SDL_Delay(Long_val(ms));
    CAMLreturn(Val_unit);
}

/* vim: set ts=4 sw=4 et: */
