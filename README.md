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

### qtMocTool
The tool to use for moc generation.
Defaults to `/usr/lib/qt6/libexec/moc`.

### qtIncludePath
The include path to use for Qt.
Defaults to `/usr/include/x86_64-linux-gnu/qt6`.

### qtLinkerPaths
A set of paths to use for linking to Qt.
Multiple paths may be defined.

Defaults to
```
/usr/lib/x86_64-linux-gnu/libQt6Gui.so
/usr/lib/x86_64-linux-gnu/libQt6Widgets.so
/usr/lib/x86_64-linux-gnu/libQt6Core.so
```

## Provided rules

### qt_moc
Generates moc output for the given c++ files.

Takes the following arguments:
```
name       (str):  Name of this rule.
hdrs       (list): A list of headers to generate moc code for.
test_only  (bool): True if this rule should only be used for tests. Defaults to False.
visibility (bool): list of rules that should have visibility to this rule. Defaults to None.
```

### cc_qt_moc_library
Generates a Qt c++ library `.a`, that can be used for further linking.

Takes the following arguments:
```
name       (str) : Name of this rule.
mocHdrs    (list): A list of headers to generate moc code for.
hdrs       (list): A list of optional headers to use when compiling the generated moc code. These do not get moc generation.
deps       (list): Dependant rules.
test_only  (bool): True if this rule should only be used for tests. Defaults to False.
visibility (bool): list of rules that should have visibility to this rule. Defaults to None.
```