{ pkgs ? import <nixpkgs> {}, }:

rec {
  myProject = pkgs.stdenv.mkDerivation {
    name = "test";
    version = "test-0.1";
    buildInputs = with pkgs; [
      (callPackage ./googlebench.nix { stdenv = stdenv; })
    ];
  };
}
