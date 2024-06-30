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
      glew-src = builtins.fetchTarball "https://github.com/nigels-com/glew/releases/download/glew-2.2.0/glew-2.2.0.zip";
      sdl2-src = builtins.fetchTarball "https://github.com/libsdl-org/SDL/releases/download/release-2.26.5/SDL2-2.26.5.zip";
      sdl2_image-src = builtins.fetchTarball "https://github.com/libsdl-org/SDL_image/releases/download/release-2.6.3/SDL2_image-2.6.3.zip";
      sdl2_ttf-src = builtins.fetchTarball "https://github.com/libsdl-org/SDL_ttf/releases/download/release-2.20.2/SDL2_ttf-2.20.2.zip";
      sdl2_mixer-src = builtins.fetchTarball "https://github.com/libsdl-org/SDL_mixer/releases/download/release-2.6.3/SDL2_mixer-2.6.3.zip";
      spdlog-src = builtins.fetchTarball "https://github.com/gabime/spdlog/archive/refs/tags/v1.10.0.zip";
      glm-src = builtins.fetchTarball "https://github.com/g-truc/glm/releases/download/0.9.9.8/glm-0.9.9.8.zip";
      googletest-src = builtins.fetchTarball "https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip";
      imgui-src = builtins.fetchTarball "https://github.com/ocornut/imgui/archive/refs/tags/v1.90.4-docking.zip";
      nlohmann_json-src = builtins.fetchTarball "https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz";
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
          default = pkgs.stdenv.mkDerivation rec {
            name = "ptsd";
            src = ./.;
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
            unpackPhase = ''
                          ln -s ${glew-src} ${src}/lib/glew
              ln -s ${sdl2-src} ${src}/lib/sdl2
              ln -s ${sdl2_image-src} ${src}/lib/sdl2_image
              ln -s ${sdl2_ttf-src} ${src}/lib/sdl2_ttf
              ln -s ${sdl2_mixer-src} ${src}/lib/sdl2_mixer
              ln -s ${spdlog-src} ${src}/lib/spdlog
              ln -s ${glm-src} ${src}/lib/glm
              ln -s ${googletest-src} ${src}/lib/googletest
              ln -s ${imgui-src} ${src}/lib/imgui
              ln -s ${nlohmann_json-src} ${src}/lib/nlohmann_json
            '';
          };
        };
      }
    );
}
