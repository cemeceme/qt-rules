

subinclude("//build_defs:qt")

subinclude("///cc//build_defs:cc")

qt_moc(
 name="QT_test_mocgen",
 hdrs=glob("*.h")
)

cc_library(
 name="QT_test_library",
 srcs=glob("*.cpp") + [":QT_test_mocgen"],
 hdrs=glob("*.h"),
 deps=[":QT_test_mocgen"],
 linker_flags=["/usr/lib/x86_64-linux-gnu/libQt6Gui.so", "/usr/lib/x86_64-linux-gnu/libQt6Widgets.so", "/usr/lib/x86_64-linux-gnu/libQt6Core.so"]
)

cc_binary(
 name="QT_test_binary",
 srcs=glob("*.cpp"),
 hdrs=glob("*.h"),
 deps=[":QT_test_library"]
)