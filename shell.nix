let
  sources = import ./npins;
  pkgs = import sources.nixpkgs {};
  flake-compat = import sources.flake-compat;
  hyprland = (flake-compat {src = sources.hyprland;}).defaultNix.packages.${pkgs.stdenv.hostPlatform.system}.hyprland;
in
  pkgs.mkShell {
    inputsFrom = [hyprland];
    nativeBuildInputs = [
      pkgs.cmake
      pkgs.pkg-config
      hyprland.dev
    ];

    buildInputs = [
      hyprland
    ];

    PKG_CONFIG_PATH = "${hyprland.dev}/lib/pkgconfig";

    # Ensure the plugin can find Hyprland's symbols at runtime
    shellHook = ''
      export NIX_CFLAGS_LINK="-L${hyprland}/lib $NIX_CFLAGS_LINK"
    '';
  }
