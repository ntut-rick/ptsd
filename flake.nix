{
  description = "PTSD development environment";
  nixConfig.bash-prompt-prefix = "(PTSD)";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-24.05";
  };

  outputs =
    { self, nixpkgs, ... }:
    let
      systems = [
        "x86_64-linux"
        "aarch64-darwin"
      ];
      pkgsFor = system: import nixpkgs { inherit system; };
      lib = nixpkgs.lib;
    in
    {
      formatter.aarch64-darwin = nixpkgs.legacyPackages.aarch64-darwin.nixfmt-rfc-style;
      packages = lib.genAttrs systems (
        system:
        let
          pkgs = pkgsFor system;
        in
        {
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
              # pkgs.SDL2
              # pkgs.SDL2_image
              # pkgs.SDL2_ttf
              # pkgs.SDL2_mixer
              # pkgs.spdlog
              # pkgs.glm
              # pkgs.gtest
            ];
            buildInputs =
              [
                pkgs.libGLU
                pkgs.mesa
                pkgs.xorg.libX11
                pkgs.xorg.libXext
                pkgs.llvmPackages.llvm
              ]
              ++ lib.optionals (system == "aarch64-darwin") [
                pkgs.darwin.apple_sdk.frameworks.Cocoa
                pkgs.darwin.apple_sdk.frameworks.IOKit
                pkgs.darwin.apple_sdk.frameworks.ForceFeedback
                pkgs.darwin.apple_sdk.frameworks.AVFoundation
              ];
          };
        }
      );
    };
}
