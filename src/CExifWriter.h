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
#ifndef CEXIFWRITER_H
#define CEXIFWRITER_H

#include <string>

#include <exiv2/image.hpp>
#include <exiv2/exif.hpp>

#include "iptc_struct.h"

/**
 * @brief Klass för att lite primitivt skriva in en del exif/xmp/iptc data
 * @todo Lägg till stöd för Iptc.Application2 samt olika taggar för windows, PS, digikam
 */
class CExifWriter {
public:
    CExifWriter(){;}
    ~CExifWriter(){;}
    /**
     * @brief Skriver exif/xmp/iptc data till en bildfil.
     * @param jpgfile
     * @param data
     */
    void WriteData(std::string jpgfile, iptc_data data);
};

#endif // CEXIFWRITER_H
