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

#include <SDL3/SDL_joystick.h>

/** FUNC CHANGE */
CAMLprim value
caml_SDL_NumJoysticks(value unit)
{
    CAMLparam1(unit);
    int num = 0;
    SDL_JoystickID * jss = SDL_GetJoysticks(&num);
    if (jss) SDL_free(jss);
    CAMLreturn(Val_int(num));
}

/* FUNC CHANGE */
CAMLprim value
caml_SDL_JoystickNameForIndex(value device_index)
{
    CAMLparam1(device_index);
    const char *name =
      SDL_GetJoystickNameForID(Int_val(device_index));
    CAMLreturn(caml_copy_string(name));
}

static value Val_SDL_Joystick(SDL_Joystick * p)
{
    return caml_copy_nativeint((intnat) p);
}

static SDL_Joystick * SDL_Joystick_val(value v)
{
    return (SDL_Joystick *) Nativeint_val(v);
}

CAMLprim value
caml_SDL_JoystickOpen(value device_index)
{
    CAMLparam1(device_index);
    SDL_Joystick *joy = SDL_OpenJoystick(Int_val(device_index));
    CAMLreturn(Val_SDL_Joystick(joy));
}

CAMLprim value
caml_SDL_JoystickClose(value joystick)
{
    CAMLparam1(joystick);
    SDL_CloseJoystick(SDL_Joystick_val(joystick));
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_JoystickNumAxes(value joystick)
{
    CAMLparam1(joystick);
    int num = SDL_GetNumJoystickAxes(
            SDL_Joystick_val(joystick));
    CAMLreturn(Val_int(num));
}

CAMLprim value
caml_SDL_JoystickNumHats(value joystick)
{
    CAMLparam1(joystick);
    int num = SDL_GetNumJoystickHats(SDL_Joystick_val(joystick));
    CAMLreturn(Val_int(num));
}

CAMLprim value
caml_SDL_JoystickGetAxis(value joystick, value axis)
{
    CAMLparam2(joystick, axis);
    Sint16 state = SDL_GetJoystickAxis(
            SDL_Joystick_val(joystick),
            Int_val(axis));
    CAMLreturn(Val_int(state));
}

CAMLprim value
caml_SDL_JoystickGetButton(value joystick, value button)
{
    CAMLparam2(joystick, button);
    Uint8 state = SDL_GetJoystickButton(
            SDL_Joystick_val(joystick),
            Int_val(button));
    CAMLreturn(Val_int(state));
}

/* vim: set ts=4 sw=4 et: */
