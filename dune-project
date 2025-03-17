(lang dune 3.15)

(name libsdl3)
(version 1.0)

(generate_opam_files true)

(source
  (github ssbx/ocaml-libsdl3))

(authors "Seb")

(maintainers "Seb")

(license "GPL-3.0-or-later")

(documentation https://github.com/ssbx/ocaml-libsdl3)

(use_standard_c_and_cxx_flags true)

(formatting (enabled_for ocaml))

(package
  (name libsdl3)
  (synopsis "Bindings to the SDL3 library")
  (description "Bindings to the SDL3 library")
  (depends conf-sdl3)
  (tags
    (topics autio bindings graphics media opengl input)))

