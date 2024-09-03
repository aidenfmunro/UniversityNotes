#!/bin/sh

# convert DjVu -> PDF
# usage:  djvu2pdf.sh  <file.djvu>

echo "------------ converting $1 to PDF ----------------";

ddjvu -format=pdf -quality=85 -verbose "$1" "$(basename "$1" .djvu).pdf"
