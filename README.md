# Qt-rules
A set of please rules, that can moc-generate and build c++ Qt projects.

## How to use

First, make sure to include the plugin within your please project by adding the following to your projects `plugins/BUILD` file:
```
plugin_repo(
  name = "qt",
  revision = "master",
  plugin = "cc-rules",
  owner = "cemeceme"
)
```

If you're not using them already, also include the please `cc-rules` repo for the c/c++ rules.

Make sure to either `preloadsubincludes` or `subinclude` the rules in the BUILD files where you need them.

## Plugin configuration
To configure the plugin, add the following fields to the `[Plugin "qt"]` section of your `.pleaseconfig` file.

### qtVersion
The version of Qt to use.

Defaults to `6`.
Note that if the version number is changed, any version numbers in other config paths also need to be modified.

### qtMocTool
The tool to use for moc generation.

Defaults to `/usr/lib64/qt6/libexec/moc`.

### qtLRelease
The tool to use for translation binary generation.

Defaults to `/usr/bin/lrelease-qt6`.

### qtIncludePath
The include path to use for Qt.

Defaults to `/usr/include/qt6`.

### qtSORootPath
The root directory that contains the different Qt .so files.

Defaults to `/usr/lib64/`

### qtComponents
A list of Qt components that should be loaded.

Defaults to
```
Core
Widgets
```

## Provided rules

### qt_moc
Generates moc output for the given c++ files.

Takes the following arguments:
```
name       (str):  Name of this rule.
hdrs       (list): A list of headers to generate moc code for.
test_only  (bool): True if this rule should only be used for tests. Defaults to False.
visibility (list): list of rules that should have visibility to this rule. Defaults to None.
```

### cc_qt_moc_library
Generates a Qt c++ library `.a`, that can be used for further linking.

Takes the following arguments:
```
name       (str) : Name of this rule.
mocHdrs    (list): A list of headers to generate moc code for.
hdrs       (list): A list of optional headers to use when compiling the generated moc code. These do not get moc generation.
deps       (list): Dependent rules.
test_only  (bool): True if this rule should only be used for tests. Defaults to False.
visibility (list): list of rules that should have visibility to this rule. Defaults to None.
```

### qt_translation_bin
Compiles qt `.ts` files into `.qm` files for translations.

Takes the following arguments:
```
name              (str): Name of this rule.
srcs              (list): A list of sources to generate binaries for.
id_based          (bool): Use IDs instead of source strings for message keying. Defaults to False.
compress          (bool): Compress the QM files. Defaults to True.
no_unfinished     (bool):  Do not include unfinished translations. Defaults to False.
remove_identical  (bool): If the translated text is the same as the source text, do not include the message. Defaults to False.
mark_untranslated (str|None): If a message has no real translation, use the source text prefixed with the given string instead. Defaults to None.
test_only         (bool): True if this rule should only be used for tests. Defaults to False.
visibility        (list): list of rules that should have visibility to this rule. Defaults to None.
```

#### TODO
Currently, the default paths used by this plugin are set to those found on fedora with Qt6 installed through dnf. Eventually, the default paths should be set to empty strings, as to be overridable by the user. However, if not overriden, the plugin should use a tool like `pkg-config` to figure out the proper paths.