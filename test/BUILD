

subinclude("//build_defs:qt")

subinclude("///cc//build_defs:cc")

# qt_moc(
#  name="QT_test_mocgen",
#  hdrs=glob("*.h")
# )

cc_qt_moc_library(
  name="QT_test_moc_library",
  mocHdrs=glob("*.h")
)

# cc_library(
#  name="QT_test_library",
#  srcs=glob("*.cpp"),
#  hdrs=glob("*.h"),
#  deps=[":QT_test_mocgen"]
# )

cc_binary(
 name="QT_test_binary",
 srcs=glob("*.cpp"),
 hdrs=glob("*.h"),
 deps=[":QT_test_moc_library"]
)

qt_translation_bin(
 name="QT_test_translations",
 srcs=glob("*.ts")
)