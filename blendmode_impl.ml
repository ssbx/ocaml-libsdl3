
module Blendmode = struct
  type t =
    | NONE
    | BLEND
    | ADD
    | MOD
    | MUL

  let to_string = function
    | NONE -> "SDL_BLENDMODE_NONE"
    | BLEND -> "SDL_BLENDMODE_BLEND"
    | ADD -> "SDL_BLENDMODE_ADD"
    | MOD -> "SDL_BLENDMODE_MOD"
    | MUL -> "SDL_BLENDMODE_MUL"

  let of_string = function
    | "SDL_BLENDMODE_NONE" -> NONE
    | "SDL_BLENDMODE_BLEND" -> BLEND
    | "SDL_BLENDMODE_ADD" -> ADD
    | "SDL_BLENDMODE_MOD" -> MOD
    | "SDL_BLENDMODE_MUL" -> MUL
    | invalid -> invalid_arg (Printf.sprintf "BlendMode.t %s" invalid)
end
