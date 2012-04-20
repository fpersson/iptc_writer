/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2012  Fredrik Persson <email>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "CExifWriter.h"

void CExifWriter::WriteData(std::string jpgfile, iptc_data data){
  Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(jpgfile);
  image->readMetadata();
  Exiv2::ExifData exifData = image->exifData();
  Exiv2::XmpData xmpData = image->xmpData();
  
  exifData["Exif.Image.Artist"] = data.Artist;
  exifData["Exif.Image.Copyright"] = data.Copyright;
  
  xmpData["Xmp.iptc.CiAdrCity"] = data.CiAdrCity;
  xmpData["Xmp.iptc.CiAdrCtry"] = data.CiAdrCtry;
  xmpData["Xmp.iptc.CiAdrEmailWork"] = data.CiAdrEmailWork;
  xmpData["Xmp.iptc.CiAdrExtadr"] = data.CiAdrExtadr;
  xmpData["Xmp.iptc.CiAdrPcode"] = data.CiAdrPcode;
  xmpData["Xmp.iptc.CiUrlWork"] = data.CiUrlWork;
  xmpData["Xmp.xmp.Label"] = data.Label;
  
  image->setExifData(exifData);
  image->setXmpData(xmpData);
  image->writeMetadata();
}

