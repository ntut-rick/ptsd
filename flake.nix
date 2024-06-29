{
  description = "PTSD development enviroment";
  nixConfig.bash-prompt-prefix = "(PTSD)";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-24.05";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs =
    {
      self,
      nixpkgs,
      flake-utils,
    }:
    let
      systems = [
        "x86_64-linux"
        "aarch64-darwin"
      ];
      lib = nixpkgs.lib;
    in
    flake-utils.lib.eachSystem systems (
      system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in
      {
        formatter = pkgs.nixfmt-rfc-style;
        packages = {
          default = pkgs.stdenv.mkDerivation {
            name = "ptsd";
            nativeBuildInputs = [
              pkgs.cmake
              pkgs.ninja
              pkgs.clang
            ];
            buildInputs =
              [
                pkgs.libGLU
                pkgs.mesa
                pkgs.xorg.libX11
                pkgs.xorg.libXext
              ]
              ++ lib.optionals (system == "aarch64-darwin") [
                pkgs.darwin.apple_sdk.frameworks.Cocoa
                pkgs.darwin.apple_sdk.frameworks.IOKit
                pkgs.darwin.apple_sdk.frameworks.ForceFeedback
                pkgs.darwin.apple_sdk.frameworks.AVFoundation
              ];
          };
        };
      }
    );
}
