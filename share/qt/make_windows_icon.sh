#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/bytecoin.png
ICON_DST=../../src/qt/res/icons/bytecoin.ico
convert ${ICON_SRC} -resize 16x16 bytecoin-16.png
convert ${ICON_SRC} -resize 32x32 bytecoin-32.png
convert ${ICON_SRC} -resize 48x48 bytecoin-48.png
convert bytecoin-16.png bytecoin-32.png bytecoin-48.png ${ICON_DST}

