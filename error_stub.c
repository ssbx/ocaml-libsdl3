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

#include <SDL3/SDL_error.h>

CAMLprim value
caml_SDL_GetError(value unit)
{
    CAMLparam1(unit);
    const char *err = SDL_GetError();
    CAMLreturn(caml_copy_string(err));
}

CAMLprim value
caml_SDL_ClearError(value unit)
{
    CAMLparam1(unit);
    SDL_ClearError();
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_SetError(value str)
{
    CAMLparam1(str);
    SDL_SetError((const char*) String_val(str));
    CAMLreturn(Val_unit);
}


/* vim: set ts=4 sw=4 et: */
