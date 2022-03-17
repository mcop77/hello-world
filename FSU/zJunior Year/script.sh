#!/usr/bin/bash

cd /media/sf_Germany

echo "Loading Images..."

for filename in *; do
	exiftool $filename >> /home/mcop/Desktop/python/ImageMap/exifOutput.txt
done

echo "Processing Images..."

cd /home/mcop/Desktop/python/ImageMap
python3 map.py
google-chrome map.html
rm exifOutput.txt
rm map.html
