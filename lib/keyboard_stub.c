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

#include <SDL3/SDL_keyboard.h>
#include "OcamlSDL3/rect_stub.h"

CAMLprim value
caml_SDL_StartTextInput(value unit)
{
    CAMLparam0();
    SDL_StartTextInput();
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_StopTextInput(value unit)
{
    CAMLparam0();
    SDL_StopTextInput();
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_IsTextInputActive(value unit)
{
    CAMLparam0();
    bool b = SDL_TextInputActive();
    CAMLreturn(Val_bool(b));
}

CAMLprim value
caml_SDL_SetTextInputRect(value _rect)
{
    CAMLparam1(_rect);
    SDL_Rect rect;
    SDL_Rect_val(&rect, _rect);
    SDL_SetTextInputRect(&rect);
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_HasScreenKeyboardSupport(value unit)
{
    CAMLparam0();
    bool b = SDL_HasScreenKeyboardSupport();
    CAMLreturn(Val_bool(b));
}

/* vim: set ts=4 sw=4 et: */
