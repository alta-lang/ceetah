# Changelog
All the changes for Ceetah, the C AST builder interface, will be kept in this file.

This project follows [semantic versioning](https://semver.org).

## [Unreleased]
Nothing yet.

## [0.4.0] - 2018-11-27
  * String literals

## [0.3.0] - 2018-11-18
### Added
  * Function calls
  * Type definitions
  * Function pointer type support 👍

## [0.2.0] - 2018-11-13
### Added
  * Binary operations (`+`, `-`, `*`, `/`)
  * Multi expressions (a.k.a. commma-sequenced expressions; e.g. `someExpression, someOtherExpression`)
  * Preprocessor undefinitions (e.g. `#undef FOOBAR`)

## [0.1.0] - 2018-11-11
### Added
  * Smart pointers here, smart pointers there, smart pointers everywhere
    * We've switched to smart pointers for, well, everything, because Ceetah needs to create many nodes and it usually can't keep track of them all
    * Plus, laziness
  * Expression indirection/pointer creation
  * Expression dereference/lookup creation
  * Assignment expressions

## [0.0.1] - 2018-11-09
### Fixed
  * Variable declarations should be using `extern`---otherwise, they're just definitions without initiailzers. Whoops!
  * Builders should now properly enter and exit insertion points

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
