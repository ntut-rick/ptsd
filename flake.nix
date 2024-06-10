{
  description = "PTSD development enviroment";
  nixConfig.bash-prompt-prefix = "(PTSD)";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-24.05";
  };

  outputs = { self, nixpkgs}:
  let
    system = "x86_64-linux";
    pkgs = import nixpkgs { inherit system; };
  in
  {
    packages = {
      x86_64-linux = {
        default = pkgs.stdenv.mkDerivation {
          name = "ptsd";
          # `nix build` fails because of a problem with cmake fetchcontent.
          # To avoid successful execution followed by failure,
          # I've commented out `src`.
          # src = ./.;
          nativeBuildInputs = [
            pkgs.cmake
            pkgs.ninja
            pkgs.clang
#            pkgs.SDL2
#            pkgs.SDL2_image
#            pkgs.SDL2_ttf
#            pkgs.SDL2_mixer
#            pkgs.spdlog
#            pkgs.glm
#            pkgs.gtest
          ];
          buildInputs = [
            pkgs.libGLU
            pkgs.mesa
            pkgs.xorg.libX11
            pkgs.xorg.libXext
          ];
        };
      };
    };
  };
}
