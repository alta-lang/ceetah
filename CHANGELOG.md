# Changelog
All the changes for Ceetah, the C AST builder interface, will be kept in this file.

This project follows [semantic versioning](https://semver.org).

## [Unreleased]
Nothing yet.

## [0.0.0] - 2018-11-08
### Added
  * Basic preprocessor directives
    * `if` directive
    * `define` directive
    * `include` directive
  * Integer literals
  * Variable declaration and definition
  * Function declaration and definition
  * Type creation
  * `return` support
  * __BUILDERS!__ (honestly, they're great)
    * Simple expression creation using the various `create*` methods
    * Automatic insertion point management (builders must still be notified when you want to exit the current block, though)
    * Insertion point hopping (basically, you can insert nodes wherever the heck you want)
    * Easy code stringification
    * (for more on why builders are great, check out the comment on the `Builder` class in [`builder.hpp`](../include/ceetah/builder.hpp))