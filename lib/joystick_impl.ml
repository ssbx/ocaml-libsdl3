module Joystick = struct
  type t
end

external num_joysticks : unit -> int = "caml_SDL_NumJoysticks"

external joystick_name_for_index
  :  device_index:int
  -> string
  = "caml_SDL_JoystickNameForIndex"

external joystick_open : device_index:int -> Joystick.t = "caml_SDL_JoystickOpen"
external joystick_close : Joystick.t -> unit = "caml_SDL_JoystickClose"
external joystick_num_axes : Joystick.t -> int = "caml_SDL_JoystickNumAxes"
external joystick_num_hats : Joystick.t -> int = "caml_SDL_JoystickNumHats"
external joystick_get_axis : Joystick.t -> axis:int -> int = "caml_SDL_JoystickGetAxis"

external joystick_get_button
  :  Joystick.t
  -> button:int
  -> int
  = "caml_SDL_JoystickGetButton"
